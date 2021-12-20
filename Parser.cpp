/*
  ==============================================================================

    Parser.cpp
    Created: 16 Dec 2021 3:09:39pm
    Author:  David Hill

  ==============================================================================
*/

#include "Parser.h"

static var parseValue (const String& valueAsString)
{
    if (valueAsString.isQuotedString() || valueAsString.startsWith ("{") || ! valueAsString.containsOnly("1234567890."))
    {
        return { valueAsString };
    }
    
    return { valueAsString.getDoubleValue () };
    
}

juce::ValueTree Reaper::createValueTreeFromReaperFile(const juce::File &file, const bool& loadValuesAsVarArrays)
{
    if (! file.getFileExtension().equalsIgnoreCase (".rpp"))
    {
        /** pass only reaper files */
        jassertfalse;
        return {};
    }
    
    juce::ValueTree projectFile {file.getFileNameWithoutExtension()};
    juce::ValueTree child = projectFile;
 
    juce::StringArray lines;
    file.readLines(lines);
    
    for (auto line : lines)
    {
        juce::String l = line.trim();
        
        if (l.startsWith("<"))
        {
            l = l.trimCharactersAtStart("<");
            juce::StringArray elementAndAttributes;
            elementAndAttributes.addTokens(l, " ", "\"");
            
            juce::String elementName = elementAndAttributes.size() > 0 ? elementAndAttributes.getReference(0) : "ELEMENT_WITHOUT_NAME";
            
            juce::ValueTree newChild {elementName};
            
            if (elementAndAttributes.size() > 1)
            {
                for (int i = 1; i < elementAndAttributes.size(); i++)
                {
                    newChild.setProperty({"Attribute_" + (juce::String)i}, elementAndAttributes.getReference(i), nullptr);
                }
            }
            
            child.appendChild(newChild, nullptr);
            child = newChild;
        }
        else if (l.endsWith(">"))
        {
            jassert (child.isValid());
            jassert (child.getParent().isValid());
            
            child = child.getParent();
        }
        else
        {
            juce::StringArray property;
            property.addTokens (l, " ", "\"");
            
            if (property.size() > 0)
            {
                jassert (child.isValid());

                juce::String name = property.getReference(0);

                property.remove (0);

                if (loadValuesAsVarArrays)
                {

                    if (property.size () == 1)
                    {
                        child.setProperty (name, property[0], nullptr);
                    }
                    else
                    {
                        child.setProperty (name, property, nullptr);
                    }
                }
                else
                {
                    auto values = property.joinIntoString(" ");
                    child.setProperty(name, values, nullptr);
                }
            }
        }
    }
    
    return projectFile.getChild(0);
}

std::unique_ptr<juce::XmlElement> Reaper::createXmlFromReaperFile (const juce::File& file)
{
    juce::ValueTree vt = createValueTreeFromReaperFile(file);
    return vt.createXml();
}
