using namespace juce;

namespace Reaper
{

class TrackTest : public UnitTest
{

public:
    
    TrackTest ();
    
    void runTest () override;
    
private:

    void setNameTest ();
    void setPeakColTest ();

//    void setBeat (bool selfCallback = false);

    void setAutoModeTest ();
    void setVolPanTest ();
    void setVolumeTes ();
    void setPanTest ();
    void setMuteSoloTest ();
    void setMuteTest ();
    void setSoloTest ();
    
    // void setIPHASE (bool selfCallback = false);
    
    // void setPLAYOFFS (bool selfCallback = false);
    
    // void setISBUS (bool selfCallback = false);
    
    // void setBUSCOMP (bool selfCallback = false);
    
    // void setSHOWINMIX (bool selfCallback = false);
    
    // void setFREEMODE (bool selfCallback = false);
    
    // void setSEL (bool selfCallback = false);
    
    // void setREC (bool selfCallback = false);
    
    // void setVU (bool selfCallback = false);
    
    // void setTRACKHEIGHT (bool selfCallback = false);
    
    // void setINQ (bool selfCallback = false);
    
    // void setNCHAN (bool selfCallback = false);

    void setFXTest ();
    
    // void setTRACKID (bool selfCallback = false);
    
    // void setPERF (bool selfCallback = false);
    
    // void setMIDIOUT (bool selfCallback = false);
    
    // void setMAINSEND (bool selfCallback = false);
    
    
    
};

}
