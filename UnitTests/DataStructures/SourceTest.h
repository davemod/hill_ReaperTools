/*
 ==============================================================================
 
 SourceTest.h
 Created: 7 Jan 2022 19:27 pm
 Author:  David Hill
 
 ==============================================================================
 */

#pragma once

using namespace juce;

namespace ReaperTest
{

using namespace Reaper;

class SourceTest : public UnitTest
{
public:
    SourceTest ();
    
    void initTest ();
    void runTest () override;
    
    void setTypeTest ();
    void setFileTest ();
    
private:
    
    Reaper::Project testProject;
    Source source;
};

static inline SourceTest sourceTest;
};
