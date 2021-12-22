/*
  ==============================================================================

    Parser.h
    Created: 16 Dec 2021 3:09:39pm
    Author:  David Hill

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <unistd.h>
#include <filesystem>
#include <iostream>

#include "../Parser.h"

#define PATH_TO_CUSTOM_MODULES "~/Documents/Juce/modules/"


namespace ReaperTest
{
    static File getReaperTestFile ();
    static Reaper::Project getReaperTestProject ();

    class ParserTest : public UnitTest
    {
    public:
      ParserTest ();

      void runTest () override;

    private:

        void invariantTest ();
        
      void createValueTreeFromReaperFileTest ();
      
      File reaperTestFile;

    };

    const static inline ParserTest parserTest;
    
};
