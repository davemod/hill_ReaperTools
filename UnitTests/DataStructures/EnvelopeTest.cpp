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
    
    getVolumeEnvelope2Test();
    iterateOverPointsTest();
}

void EnvelopeTest::getVolumeEnvelope2Test()
{
    beginTest ("getVolumeEnvelope2Test");
    expect (envelope.isValid());
}

void EnvelopeTest::iterateOverPointsTest()
{
    beginTest ("iterateOverPointsTest");
    int numPoints = 0;
    for (auto pt : envelope)
    {
        numPoints++;
    }
    
    expect (numPoints > 0);
}


EnvelopePointTest::EnvelopePointTest ()
:
UnitTest ("Reaper::EnvelopePointTest")
{
    initTest ();
}

void EnvelopePointTest::initTest ()
{
    reaperProject = getReaperTestProject();
    track = reaperProject.getTrack (0);
    envelope = track.getVolumeEnvelope2();
    point = envelope.getPoint (0);
}

void EnvelopePointTest::runTest ()
{
    jassert (point.isValid());
    if (! point.isValid())
        return;
    
    setPositionTest ();
    setLevelTest ();
    setShapeTest ();
    setSelectedTest ();
    setUnknownAttributeTest ();
    setTensionTest ();
    
    arraySizeTest ();
}

void EnvelopePointTest::arraySizeTest ()
{
    beginTest ("arraySizeTest");
    
    if (auto values = point.getValues())
    {
        point.setPosition (0.0);
        point.setLevel (0.0);
        point.setShape (EnvelopePoint::Shape::Linear);
        point.setSelected (false);
        point.setUnknownAttribute (0.0);
        point.setTension(0.0);
        
        expectEquals (values->size(), 0);
        
        point.setSelected (true);
        expectEquals (values->size(), 4);
        
        point.setTension (0.001);
        expectEquals (values->size(), 6);
        
        point.setTension (0.0);
        expectEquals (values->size(), 4);
    }

    
}

void EnvelopePointTest::setPositionTest ()
{
    auto val = 123.4;
    point.setPosition (val);
    expectEquals (point.getPosition (), val);
}

void EnvelopePointTest::setLevelTest ()
{
    auto val = 0.5;
    point.setLevel (val);
    expectEquals (point.getLevel (), val);
}

void EnvelopePointTest::setShapeTest ()
{
    auto val = point.Bezier;
    point.setShape (val);
    expectEquals ((int)point.getShape (), (int)val);
}

void EnvelopePointTest::setSelectedTest ()
{
    auto val = true;
    point.setSelected (val);
    expectEquals ((int)point.getSelected (), (int)val);
}

void EnvelopePointTest::setUnknownAttributeTest ()
{
    auto val = 1.0;
    point.setUnknownAttribute (val);
    expectEquals (point.getUnknownAttribute (), val);
}

void EnvelopePointTest::setTensionTest ()
{
    auto val = 12.0;
    point.setTension (val);
    expectEquals (point.getTension (), val);
}

