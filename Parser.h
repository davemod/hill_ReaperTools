/*
  ==============================================================================

    Parser.h
    Created: 16 Dec 2021 3:09:39pm
    Author:  David Hill

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

namespace Reaper
{
juce::ValueTree createValueTreeFromReaperFile (const juce::File& reaperFile, const bool& loadValuesAsVarArrays = false);
std::unique_ptr<juce::XmlElement> createXmlFromReaperFile (const juce::File& reaperFile);
};
