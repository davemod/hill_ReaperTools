/*
  ==============================================================================

    ReaperProjectTest.cpp
    Created: 17 Dec 2021 17:30 pm
    Author:  David Hill

  ==============================================================================
*/

#pragma once

#include "ReaperProjectTest.h"

namespace ReaperTest
{

using namespace Reaper;

ProjectTest::ProjectTest ()
:
UnitTest ("Reaper::ProjectTest")
{
    testFile = getReaperTestFile ();
}

void ProjectTest::runTest ()
{
    if (! testFile.existsAsFile())
    {
        // could not find the reaper test file
        jassertfalse;
        return;
    }
    
    initTest ();
    
    if (reaperProject.isValid())
    {
        setCursorPositionTest ();
        setRecordPathATest ();
        setTempoTest ();
        setTimeSignatureTest ();
        setSelectionTest ();
        setSelection2Test ();
        setVolumeTest ();
        setPanTest ();
    }
    
    // it seems that the static instance of this test will be deleted AFTER the leak detector of juce does its work. so clear the project here to avoid the leaking detector detecting any leaks ...
    reaperProject.clear();
}

void ProjectTest::initTest ()
{
    
    ValueTree vt = createValueTreeFromReaperFile (testFile, true);
    
    // file was not parsed correctly, but ... this has been tested earlier! Did you mess around with the test reaper file?
    jassert (vt.isValid());
    if (! vt.isValid())
        return;
    
    reaperProject.wrap (vt);
}

void ProjectTest::setCursorPositionTest ()
{
    beginTest ("setCursorPositionTest");
    reaperProject.setCursorPosition (1234);
    expectEquals (reaperProject.getCursorPosition (), 1234);
}

void ProjectTest::setRecordPathATest ()
{
    beginTest ("setRecordPathATest");
    File testLocation = File::getSpecialLocation (File::userDesktopDirectory).getChildFile ("Records");
    
    reaperProject.setRecordPathA (testLocation);
    expectEquals (reaperProject.getRecordPathA ().getFullPathName(), testLocation.getFullPathName());
}

void ProjectTest::setTempoTest ()
{
    beginTest ("setTempoTest");
    reaperProject.setTempo (123.4f);
    expectEquals (reaperProject.getTempo (), 123.4f);
}

void ProjectTest::setTimeSignatureTest ()
{
    beginTest ("setTimeSignatureTest");
    reaperProject.setTimeSignature ({1,3});
    expectEquals (reaperProject.getTimeSignature (), {1,3});
}

void ProjectTest::setSelectionTest ()
{
    beginTest ("setSelectionTest");
    reaperProject.setSelection ({5,10});
    expectEquals (reaperProject.getSelection (), {5,10});
}

void ProjectTest::setSelection2Test ()
{
    beginTest ("setSelection2Test");
    reaperProject.setSelection2 ({10,20});
    expectEquals (reaperProject.getSelection2 (), {10,20});
}

void ProjectTest::setVolumeTest ()
{
    beginTest ("setVolumeTest");
    reaperProject.setVolume (0.5f);
    expectEquals (reaperProject.getVolume (), 0.5f);
}

void ProjectTest::setPanTest ()
{
    beginTest ("setPanTest");
    reaperProject.setPan (-0.1f);
    expectEquals (reaperProject.getPan (), -0.1f);
}


};
