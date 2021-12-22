using namespace juce;

namespace Reaper
{

class Track : public ValueTreeWrapper
{

public:
    
    Track ();
    Track (const ValueTree& trackTree);
    Track (const Track& other);

    const static inline Identifier ID {"TRACK"};

    void setName (const String& name, bool selfCallback = false) { setValue (name, NAMEID, selfCallback); }
    String getName () const { return getValue<String> (NAMEID); }
    
    void setPeakCol (uint32 c, bool selfCallback = false) { setValue ((int64)c, PEAKCOLID, selfCallback); }
    uint32 getPeakCol () const { return (uint32)getValue<int64> (PEAKCOLID); }
    
    //    void setBeat (bool selfCallback = false);
    enum AutoMode {Trim = 0, Read, Touch, Latch, LatchPreview, Write};
    void setAutoMode (AutoMode autoMode, bool selfCallback = false) { setValue ((int)autoMode, AUTOMODEID, selfCallback); }
    AutoMode getAutoMode () { return (AutoMode) getValue<int> (AUTOMODEID); }
    
    void setVolPan (Array<var> volPan, bool selfCallback = false);
    Array<var> getVolPan () const;
    
    // VOLPAN
    void setVolume (float volume);
    float getVolume () const;
    
    void setPan (float pan);
    float getPan () const;
    
    // MUTESOLO
    void setMute (bool mute);
    bool getMute () const;
    
    void setSolo (bool solo);
    bool getSolo () const;
    
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
    
    void setFX (bool enableFX, bool selfCallback = false) { setValue (enableFX, FXID, selfCallback); }
    bool getFX () const { return getValue<bool> (FXID); }
    
    // void setTRACKID (bool selfCallback = false);
    // void setPERF (bool selfCallback = false);
    // void setMIDIOUT (bool selfCallback = false);
    // void setMAINSEND (bool selfCallback = false);
    
    Item getItem (int itemNo) const { return getNthChildOfType <Item> (itemNo); }
    
private:

    const static inline Identifier NAMEID {"NAME"}; // "Midi Track"
    const static inline Identifier PEAKCOLID {"PEAKCOL"}; // 16576
    const static inline Identifier BEATID {"BEAT"}; // -1
    const static inline Identifier AUTOMODEID {"AUTOMODE"}; // 0
    const static inline Identifier VOLPANID {"VOLPAN"}; // 1 0 -1 -1 1
    const static inline Identifier MUTESOLOID {"MUTESOLO"}; // 0 0 0
    const static inline Identifier IPHASEID {"IPHASE"}; // 0
    const static inline Identifier PLAYOFFSID {"PLAYOFFS"}; // 0 1
    const static inline Identifier ISBUSID {"ISBUS"}; // 0 0
    const static inline Identifier BUSCOMPID {"BUSCOMP"}; // 0 0 0 0 0
    const static inline Identifier SHOWINMIXID {"SHOWINMIX"}; // 1 0.6667 0.5 1 0.5 -1 -1 -1
    const static inline Identifier FREEMODEID {"FREEMODE"}; // 0
    const static inline Identifier SELID {"SEL"}; // 0
    const static inline Identifier RECID {"REC"}; // 0 0 1 0 0 0 0
    const static inline Identifier VUID {"VU"}; // 2
    const static inline Identifier TRACKHEIGHTID {"TRACKHEIGHT"}; // 0 0 0 0 0 0
    const static inline Identifier INQID {"INQ"}; // 0 0 0 0.5 100 0 0 100
    const static inline Identifier NCHANID {"NCHAN"}; // 2
    const static inline Identifier FXID {"FX"}; // 1
    const static inline Identifier TRACKIDID {"TRACKID"}; // {1E0F5019-66A9-A34D-96DD-14E6BFEFFD1C}
    const static inline Identifier PERFID {"PERF"}; // 0
    const static inline Identifier MIDIOUTID {"MIDIOUT"}; // -1
    const static inline Identifier MAINSENDID {"MAINSEND"}; // 1 0

    void initValueTree () override {}
    
};

}
