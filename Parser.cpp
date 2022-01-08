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

enum LineType { TNewChild, TCloseChild, TChildProperty, TEnvelopePoint };
static LineType getLineType (const String& line)
{
    auto l = line.trim();
    
    if (l.startsWith("<"))
        return TNewChild;
    
    if (l.startsWith("PT "))
        return TEnvelopePoint;
    
    if (l.endsWith(">"))
        return TCloseChild;
    
    return TChildProperty;
}

static void writeProperty (ValueTree& vtToWriteTo, const String& line, const bool& loadValuesAsVarArrays)
{
    juce::StringArray property;
    property.addTokens (line.trim(), " ", "\"");
    
    if (property.size() > 0)
    {
        jassert (vtToWriteTo.isValid());
        
        juce::String name = property.getReference(0);
        
        property.remove (0);
        
        if (loadValuesAsVarArrays)
        {
            
            if (property.size () == 1)
            {
                vtToWriteTo.setProperty (name, property[0], nullptr);
            }
            else
            {
                vtToWriteTo.setProperty (name, property, nullptr);
            }
        }
        else
        {
            auto values = property.joinIntoString(" ");
            vtToWriteTo.setProperty(name, values, nullptr);
        }
    }
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
    
    jassert (lines.size() > 0);
    
    for (auto line : lines)
    {
        auto l = line.trim();
        auto lineType = getLineType (l);
        
        if (lineType == TNewChild)
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
        else if (lineType == TCloseChild)
        {
            jassert (child.isValid());
            jassert (child.getParent().isValid());
            
            child = child.getParent();
        }
        else if (lineType == TEnvelopePoint)
        {
            jassert (child.isValid());
            if (child.isValid())
            {
                jassert (child.getType ().toString().contains("ENV"));
                ValueTree point {"PT"};
                
                writeProperty (point, l, loadValuesAsVarArrays);

                child.appendChild (point, nullptr);
            }
        }
        else if (lineType == TChildProperty)
        {
            writeProperty(child, l, loadValuesAsVarArrays);
        }
    }
    
    return projectFile.getChild(0);
}

std::unique_ptr<juce::XmlElement> Reaper::createXmlFromReaperFile (const juce::File& file)
{
    juce::ValueTree vt = createValueTreeFromReaperFile(file);
    return vt.createXml();
}
