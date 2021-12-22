/*
  ==============================================================================

    ReaperProjectTest.h
    Created: 17 Dec 2021 18:30 pm
    Author:  David Hill

  ==============================================================================
*/

#pragma once

using namespace juce;

namespace ReaperTest
{

using namespace Reaper;

class ProjectTest : public UnitTest
{
public:

    ProjectTest ();
    
    void runTest () override;
    
private:
    
    void initTest ();
    
    void setCursorPositionTest ();
    void setRecordPathATest ();
    void setTempoTest ();
    void setTimeSignatureTest ();
    void setSelectionTest ();
    void setSelection2Test ();
    void setVolumeTest ();
    void setPanTest ();
    
    void getTrackTest ();
    
    File testFile;
    Project reaperProject;
};

static inline ProjectTest projectTest;

};
