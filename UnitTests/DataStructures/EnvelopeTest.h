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
    
private:
    
    Project reaperProject;
    Track track;
    
    VolumeEnvelope2 envelope;
};

static inline EnvelopeTest envelopeTest;

};
