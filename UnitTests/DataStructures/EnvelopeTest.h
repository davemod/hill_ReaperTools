#pragma once

namespace ReaperTest
{
using namespace Reaper;

class EnvelopeTest : public UnitTest
{
public:
    
    EnvelopeTest ();
    
    void initTest ();
    void runTest () override;
    
    void getVolumeEnvelope2Test ();
    void iterateOverPointsTest ();
    
private:
    
    Project reaperProject;
    Track track;
    
    VolumeEnvelope2 envelope;
};

static inline EnvelopeTest envelopeTest;

class EnvelopePointTest : public UnitTest
{
public:
    
    EnvelopePointTest ();
    
    void initTest ();
    void runTest () override;
    
    void getPointTest ();
    
    void setPositionTest ();
    void setLevelTest ();
    void setShapeTest ();
    void setSelectedTest ();
    void setUnknownAttributeTest ();
    void setTensionTest ();
    
    void arraySizeTest ();
private:
    
    Project reaperProject;
    Track track;
    
    VolumeEnvelope2 envelope;
    EnvelopePoint point;
};

static inline EnvelopePointTest envelopePointTest;

};
