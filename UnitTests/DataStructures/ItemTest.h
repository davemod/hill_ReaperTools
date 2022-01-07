/*
 ==============================================================================
 
 ItemTest.h
 Created: 7 Jan 2022 16:28 pm
 Author:  David Hill
 
 ==============================================================================
 */

#pragma once

using namespace juce;

namespace ReaperTest
{

using namespace Reaper;

class ItemTest : public UnitTest
{
public:
    
    ItemTest ();
    
    void runTest () override;
    
private:
    
    void initTest ();
    
    void getSourceTest ();

    void setPositionTest ();
    void setLengthTest ();
    void setLoopTest ();
    void setAllTakesTest ();
    void setFadeInTest ();
    void setFadeOutTest ();
    void setMuteTest ();
    void setSelTest ();
    void setIGuidTest ();
    void setIIdTest ();
    void setNameTest ();
    void setVolumeTest ();
    void setPanTest ();
    void setPlayrateTest ();

    Item item;
    File testFile;
    Project reaperProject;
    
};

static inline ItemTest itemTest;

};
