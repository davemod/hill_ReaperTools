#include "SourceTest.h"

using namespace ReaperTest;

SourceTest::SourceTest ()
:
UnitTest ("Reaper::SourceTest")
{
    initTest ();
}

void SourceTest::initTest ()
{
    testProject = getReaperTestProject ();
    
    auto track = testProject.getTrack (0);
    auto item = track.getItem (0);
    
    source = item.getSource ();
}

void SourceTest::runTest ()
{
    jassert (source.isValid());
    
    if (! source.isValid())
        return;
    
    setTypeTest ();
    setFileTest ();
}

void SourceTest::setTypeTest ()
{
    beginTest ("setTypeTest");
    
    auto type = Source::Type::WAVE;
    source.setType (type);
    expectEquals (type, source.getType());
    
    type = Source::Type::NONE;
    source.setType (type);
    expectEquals (type, source.getType());
}

void SourceTest::setFileTest ()
{
    beginTest ("setFileTest");

    File file = File::getSpecialLocation(File::userMusicDirectory).getChildFile("Wavefile.wav");
    
    source.setFile (file);
    expectEquals (source.getFile().getFullPathName(), file.getFullPathName());
}

