#include "EnvelopeTest.h"

using namespace ReaperTest;

EnvelopeTest::EnvelopeTest ()
:
UnitTest ("Reaper::EnvelopeTest")
{
    initTest ();
}

void EnvelopeTest::initTest ()
{
    reaperProject = getReaperTestProject();
    track = reaperProject.getTrack (0);
    envelope = track.getVolumeEnvelope2();
}

void EnvelopeTest::runTest ()
{
    jassert (track.isValid());
    if (! track.isValid())
        return;
    
    getVolumeEnvelope2Test ();
}

void EnvelopeTest::getVolumeEnvelope2Test ()
{
    beginTest ("getVolumeEnvelope2Test");
    expect (envelope.isValid());
}



