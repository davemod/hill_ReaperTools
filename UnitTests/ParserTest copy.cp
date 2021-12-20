/*
  ==============================================================================

    Parser.cpp
    Created: 16 Dec 2021 3:09:39pm
    Author:  David Hill

  ==============================================================================
*/

#include "ParserTest.h"

namespace Reaper
{

ParserTest::ParserTest ()
:
UnitTest ("Reaper::ParserTest")
{
    reaperTestFile = getReaperTestFile();
}

void ParserTest::runTest ()
{
    if (! reaperTestFile.existsAsFile())
    {
        DBG ("ParserTest: Could not start tests because no reaper file was found.");
        jassertfalse;
        
        return;
    }
    
    createValueTreeFromReaperFileTest ();
    
}

void ParserTest::createValueTreeFromReaperFileTest ()
{
    beginTest ("createValueTreeFromReaperFileTest");

    // check storing properties as string properties
    ValueTree vt = createValueTreeFromReaperFile(reaperTestFile, false);
    
    expect (vt.isValid());
    
    if (vt.isValid())
    {
        expect (vt.getType () == Project::ID);
        
        // check for a few properties
        expect (vt.hasProperty ("RIPPLE"));
        expect (vt.hasProperty ("GROUPOVERRIDE"));
        expect (vt.hasProperty ("AUTOXFADE"));
        expect (vt.hasProperty ("ENVATTACH"));
        expect (vt.hasProperty ("POOLEDENVATTACH"));
        expect (vt.hasProperty ("MIXERUIFLAGS"));
        
        String groupOverride = vt.getProperty ("GROUPOVERRIDE");
        expect (StringArray::fromTokens (groupOverride, " ", "\"").size() == 3);
    }
    
    
    // check storing properties as var arrays if necessary
    vt = createValueTreeFromReaperFile(reaperTestFile, true);

    if (vt.isValid())
    {
        expect (vt.getType () == Project::ID);
        
        // check for a few properties
        expect (vt.hasProperty ("RIPPLE"));
        expect (vt.hasProperty ("GROUPOVERRIDE"));
        expect (vt.hasProperty ("AUTOXFADE"));
        expect (vt.hasProperty ("ENVATTACH"));
        expect (vt.hasProperty ("POOLEDENVATTACH"));
        expect (vt.hasProperty ("MIXERUIFLAGS"));
        
        Array<var> zoom = *vt.getProperty ("ZOOM").getArray();
        
        expect (zoom.size() == 3);
        expect ((double)zoom [0] == 2.13030110273488);
        expect ((int)zoom [1] == 50);
        expect ((float)zoom [2] == 0.0f);
        
    }

}

File ParserTest::getReaperTestFile ()
{
    auto modulesFolder = File (PATH_TO_CUSTOM_MODULES);
    return modulesFolder.getChildFile ("hill_ReaperTools").getChildFile ("UnitTests").getChildFile ("ReaperTestProject.rpp");
}

}
