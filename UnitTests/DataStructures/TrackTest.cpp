namespace ReaperTest
{


TrackTest::TrackTest ()
:
UnitTest ("Reaper::TrackTest")
{
    
}

void TrackTest::runTest ()
{

    initTest ();
    
    if (! track.isValid())
    {
        return;
    }
    
    setNameTest ();
    setPeakColTest ();
    setAutoModeTest ();
    setVolumeTest ();
    setPanTest ();
    setMuteTest ();
    setSoloTest ();
    setFXTest ();
    
    getItemTest ();
    
    reaperProject.clear ();
    track.clear ();

}

void TrackTest::initTest ()
{
    reaperProject = getReaperTestProject ();
    track = reaperProject.getTrack (0);
    
    // if you hit one of these, trackteste could not be initialized successfully
    jassert (reaperProject.isValid());
    jassert (track.isValid());

}

void TrackTest::setNameTest ()
{
    beginTest ("setNameTest");
    track.setName ("First Track Ever");
    expectEquals (track.getName (), (String)"First Track Ever");
}

void TrackTest::setPeakColTest ()
{

}

// ...

void TrackTest::setAutoModeTest ()
{
    beginTest ("setAutoModeTest");
    track.setAutoMode (Track::AutoMode::Write);
    expectEquals (track.getAutoMode (), Track::AutoMode::Write);
}

void TrackTest::setVolumeTest ()
{

}

void TrackTest::setPanTest ()
{
    beginTest ("setPanTest");
    track.setPan (0.2f);
    expectEquals (track.getPan (), 0.2f);
}

void TrackTest::setMuteTest ()
{
    beginTest ("setMuteTest");
    track.setMute (true);
    expectEquals ((int)track.getMute (), (int)true);
    
    track.setMute (false);
    expectEquals ((int)track.getMute (), (int)false);
}

void TrackTest::setSoloTest ()
{
    beginTest ("setSoloTest");
    track.setSolo (true);
    expectEquals ((int)track.getSolo (), (int)true);
    
    track.setSolo (false);
    expectEquals ((int)track.getSolo (), (int)false);
}

// ...

void TrackTest::setFXTest ()
{
    beginTest ("setFXTest");
    track.setFX (true);
    expectEquals ((int)track.getFX (), (int)true);
    
    track.setFX (false);
    expectEquals ((int)track.getFX (), (int)false);
}

void TrackTest::getItemTest ()
{
    auto item = track.getItem (0);
    expect (item.isValid());
    
    auto trackB = reaperProject.getTrack (1);
    item = trackB.getItem (0);
    expect (item.isValid());
}

};
