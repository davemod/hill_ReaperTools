#include "ItemTest.h"

using namespace ReaperTest;


ItemTest::ItemTest ()
:
UnitTest ("ItemTest")
{
    initTest ();
}
    
void ItemTest::runTest ()
{
    jassert (item.isValid());
    
    if (! item.isValid())
        return;
    
    getSourceTest ();
    
    setPositionTest ();
    setLengthTest ();
    setLoopTest ();
    setAllTakesTest ();
    setFadeInTest ();
    setFadeOutTest ();
    setMuteTest ();
    setSelTest ();
    setIGuidTest ();
    setIIdTest ();
    setNameTest ();
    setVolumeTest ();
    setPanTest ();
    setPlayrateTest ();
    
}

void ItemTest::initTest ()
{
    reaperProject = getReaperTestProject ();
    item = reaperProject.getTrack(0).getItem(0);
}

void ItemTest::getSourceTest ()
{
    beginTest ("getSourceTest");
    auto source = item.getSource ();
    expect (source.isValid());
}

void ItemTest::setPositionTest ()
{
    beginTest ("setPositionTest");
    double val = 12345.6789;
    
    item.setPosition (val);
    expectEquals (item.getPosition (), val);
}

void ItemTest::setLengthTest ()
{
    beginTest ("setLengthTest");
    double val = 0.123;
    
    item.setLength (val);
    expectEquals (item.getLength (), val);
}

void ItemTest::setLoopTest ()
{
    beginTest ("setLoopTest");
    bool val = true;
    
    item.setLoop (val);
    expectEquals ((int)item.getLoop (), (int)val);
}

void ItemTest::setAllTakesTest ()
{
    beginTest ("setAllTakesTest");
    bool val = true;
    
    item.setAllTakes (val);
    expectEquals ((int)item.getAllTakes (), (int)val);
}

void ItemTest::setFadeInTest ()
{
    beginTest ("setFadeInTest");
    Fade fade {1, 0.2, 0, 0, 1, 2, 3};
    
    item.setFadeIn (fade);
    expect (item.getFadeIn () == fade);
}

void ItemTest::setFadeOutTest ()
{
    beginTest ("setFadeOutTest");
    Fade fade {1, 0.2, 0, 0, 1, 2, 3};
    
    item.setFadeOut (fade);
    expect (item.getFadeOut () == fade);
}

void ItemTest::setMuteTest ()
{
    beginTest ("setMuteTest");
    bool val = false;
    
    item.setMute (val);
    expectEquals ((int)item.getMute (), (int)val);
}

void ItemTest::setSelTest ()
{
    beginTest ("setSelTest");
    bool val = true;
    
    item.setSel (val);
    expectEquals ((int)item.getSel (), (int)val);
}

void ItemTest::setIGuidTest ()
{
    beginTest ("setIGuidTest");
    GUID guid;
    
    item.setIGuid (guid);
    expectEquals (item.getIGuid (), guid);
}

void ItemTest::setIIdTest ()
{
    beginTest ("setIIdTest");
    int val = 123;
    
    item.setIId (val);
    expectEquals (item.getIId (), val);
}

void ItemTest::setVolumeTest ()
{
    beginTest ("setVolumeTest");
    float val = 0.12f;
    item.setVolume (val);
    expectEquals (item.getVolume(), val);
}

void ItemTest::setPanTest ()
{
    beginTest ("setPanTest");
    float val = 0.12f;
    item.setPan (val);
    expectEquals (item.getPan(), val);
}

void ItemTest::setNameTest ()
{
    beginTest ("setNameTest");
    String val = "New Item Name";
    
    item.setName (val);
    expectEquals (item.getName (), val);
}

void ItemTest::setPlayrateTest ()
{
    beginTest ("setPlayrateTest");
    Playrate playrate {1,2,3,4,5,6,7};
    
    item.setPlayrate (playrate);
    expect (item.getPlayrate () == playrate);
}


