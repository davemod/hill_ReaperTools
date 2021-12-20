/*
  ==============================================================================

    ReaperProject.h
    Created: 17 Dec 2021 18:30 pm
    Author:  David Hill

  ==============================================================================
*/

#pragma once

using namespace juce;

namespace Reaper
{

class Project : public ValueTreeWrapper
{
public:

    const static inline Identifier ID {"REAPER_PROJECT"};
    
    Project ();
    
//    RIPPLE 0
//    GROUPOVERRIDE 0 0 0
//    AUTOXFADE 1
//    ENVATTACH 1
//    POOLEDENVATTACH 0
//    MIXERUIFLAGS 11 48
//    PEAKGAIN 1
//    FEEDBACK 0
//    PANLAW 1
//    PROJOFFS 0 0 0
//    MAXPROJLEN 0 600
//    GRID 3199 8 1 8 1 0 0 0
//    TIMEMODE 1 5 -1 30 0 0 -1
//    VIDEO_CONFIG 0 0 256
//    PANMODE 3
    
    //    CURSOR 244
    void setCursorPosition (int position, bool selfCallback = false) { setValue (position, CURSORID, selfCallback); }
    int getCursorPosition () const { return getValue <int> (CURSORID); }
    
//    ZOOM 2.13030110273488 0 0
//    VZOOMEX 6 0
//    USE_REC_CFG 0
//    RECMODE 1
//    SMPTESYNC 0 30 100 40 1000 300 0 0 1 0 0
//    LOOP 0
//    LOOPGRAN 0 4
//    RECORD_PATH "" ""
    void setRecordPathA (const File& pathA) { setValueInVarArray (RECORD_PATHID, 0, pathA.getFullPathName()); }
    File getRecordPathA () const { return {getValueInVarArray<String> (RECORD_PATHID, 0)}; }
    
//    RENDER_FILE ""
//    RENDER_PATTERN ""
//    RENDER_FMT 0 2 0
//    RENDER_1X 0
//    RENDER_RANGE 1 0 0 18 1000
//    RENDER_RESAMPLE 3 0 1
//    RENDER_ADDTOPROJ 0
//    RENDER_STEMS 0
//    RENDER_DITHER 0
//    TIMELOCKMODE 1
//    TEMPOENVLOCKMODE 1
//    ITEMMIX 0
//    DEFPITCHMODE 589824 0
//    TAKELANE 1
//    SAMPLERATE 44100 0 0
//    LOCK 1
//    GLOBAL_AUTO -1
//    TEMPO 120 4 4

    void setTempo (float tempo) { setValueInVarArray (TEMPOID, 0, tempo); }
    float getTempo () const { return getValueInVarArray<float> (TEMPOID, 0); }

    struct TimeSignature
    {
        TimeSignature (int nominator_, int denominator_)
        :
        nominator (nominator_),
        denominator (denominator_)
        {}
        
        int nominator = 4;
        int denominator = 4;
        
        bool operator== (const TimeSignature& other) { return other.nominator == nominator && other.denominator == denominator; }
        bool operator!= (const TimeSignature& other) { return ! (*this == other); }
        
        operator String () { return (String)nominator + "/" + (String)denominator; }
    };
    
    void setTimeSignature (TimeSignature ts);
    TimeSignature getTimeSignature () const;
    
//    PLAYRATE 1 0 0.25 4
//    SELECTION 0 0
    struct Selection
    {
        double start = 0.0;
        double end = 0.0;
        
        bool operator== (const Selection& other) { return other.start == start && other.end == end; }
        bool operator!= (const Selection& other) { return ! (*this == other); }
        
        operator String () { return "start: " + (String)start + ", end: " + (String)end; }
    };
    
    void setSelection (Selection selection, bool selfCallback = false);
    Selection getSelection () const;

//    SELECTION2 0 0
    void setSelection2 (Selection selection, bool selfCallback = false);
    Selection getSelection2 () const;
    
//    MASTERAUTOMODE 0
//    MASTERTRACKHEIGHT 0 0
//    MASTERPEAKCOL 16576
//    MASTERMUTESOLO 0
//    MASTERTRACKVIEW 0 0.6667 0.5 0.5 -1 -1 -1 0 0 0 -1 -1 0
//    MASTERHWOUT 0 0 1 0 0 0 0 -1
//    MASTER_NCH 2 2
    
//    MASTER_VOLUME 1 0 -1 -1 1 // Volume, Pan, ?, ?, ?
    void setVolume (float volume) { setValueInVarArray (MASTER_VOLUMEID, 0, volume); }
    float getVolume () const { return getValueInVarArray<float> (MASTER_VOLUMEID, 0); }
    
    void setPan (float pan) { setValueInVarArray (MASTER_VOLUMEID, 1, pan); }
    float getPan () const { return getValueInVarArray<float> (MASTER_VOLUMEID, 1); }
    
//    MASTER_FX 1
//    MASTER_SEL 0


  protected:
  
    const static inline Identifier RIPPLEID {"RIPPLE"};
    const static inline Identifier GROUPOVERRIDEID {"GROUPOVERRIDE"};
    const static inline Identifier AUTOXFADEID {"AUTOXFADE"};
    const static inline Identifier ENVATTACHID {"ENVATTACH"};
    const static inline Identifier POOLEDENVATTACHID {"POOLEDENVATTACH"};
    const static inline Identifier MIXERUIFLAGSID {"MIXERUIFLAGS"};
    const static inline Identifier PEAKGAINID {"PEAKGAIN"};
    const static inline Identifier FEEDBACKID {"FEEDBACK"};
    const static inline Identifier PANLAWID {"PANLAW"};
    const static inline Identifier PROJOFFSID {"PROJOFFS"};
    const static inline Identifier MAXPROJLENID {"MAXPROJLEN"};
    const static inline Identifier GRIDID {"GRID"};
    const static inline Identifier TIMEMODEID {"TIMEMODE"};
    const static inline Identifier VIDEO_CONFIGID {"VIDEO_CONFIG"};
    const static inline Identifier PANMODEID {"PANMODE"};
    const static inline Identifier CURSORID {"CURSOR"};
    const static inline Identifier ZOOMID {"ZOOM"};
    const static inline Identifier VZOOMEXID {"VZOOMEX"};
    const static inline Identifier USE_REC_CFGID {"USE_REC_CFG"};
    const static inline Identifier RECMODEID {"RECMODE"};
    const static inline Identifier SMPTESYNCID {"SMPTESYNC"};
    const static inline Identifier LOOPID {"LOOP"};
    const static inline Identifier LOOPGRANID {"LOOPGRAN"};
    const static inline Identifier RECORD_PATHID {"RECORD_PATH"};
    const static inline Identifier RENDER_FILEID {"RENDER_FILE"};
    const static inline Identifier RENDER_PATTERNID {"RENDER_PATTERN"};
    const static inline Identifier RENDER_FMTID {"RENDER_FMT"};
    const static inline Identifier RENDER_1XID {"RENDER_1X"};
    const static inline Identifier RENDER_RANGEID {"RENDER_RANGE"};
    const static inline Identifier RENDER_RESAMPLEID {"RENDER_RESAMPLE"};
    const static inline Identifier RENDER_ADDTOPROJID {"RENDER_ADDTOPROJ"};
    const static inline Identifier RENDER_STEMSID {"RENDER_STEMS"};
    const static inline Identifier RENDER_DITHERID {"RENDER_DITHER"};
    const static inline Identifier TIMELOCKMODEID {"TIMELOCKMODE"};
    const static inline Identifier TEMPOENVLOCKMODEID {"TEMPOENVLOCKMODE"};
    const static inline Identifier ITEMMIXID {"ITEMMIX"};
    const static inline Identifier DEFPITCHMODEID {"DEFPITCHMODE"};
    const static inline Identifier TAKELANEID {"TAKELANE"};
    const static inline Identifier SAMPLERATEID {"SAMPLERATE"};
    const static inline Identifier LOCKID {"LOCK"};
    const static inline Identifier VOLID {"VOL"};
    const static inline Identifier FREQID {"FREQ"};
    const static inline Identifier BEATLENID {"BEATLEN"};
    const static inline Identifier SAMPLESID {"SAMPLES"};
    const static inline Identifier PATTERNID {"PATTERN"};
    const static inline Identifier GLOBAL_AUTOID {"GLOBAL_AUTO"};
    const static inline Identifier TEMPOID {"TEMPO"};
    const static inline Identifier PLAYRATEID {"PLAYRATE"};
    const static inline Identifier SELECTIONID {"SELECTION"};
    const static inline Identifier SELECTION2ID {"SELECTION2"};
    const static inline Identifier MASTERAUTOMODEID {"MASTERAUTOMODE"};
    const static inline Identifier MASTERTRACKHEIGHTID {"MASTERTRACKHEIGHT"};
    const static inline Identifier MASTERPEAKCOLID {"MASTERPEAKCOL"};
    const static inline Identifier MASTERMUTESOLOID {"MASTERMUTESOLO"};
    const static inline Identifier MASTERTRACKVIEWID {"MASTERTRACKVIEW"};
    const static inline Identifier MASTERHWOUTID {"MASTERHWOUT"};
    const static inline Identifier MASTER_NCHID {"MASTER_NCH"};
    const static inline Identifier MASTER_VOLUMEID {"MASTER_VOLUME"};
    const static inline Identifier MASTER_FXID {"MASTER_FX"};
    const static inline Identifier MASTER_SELID {"MASTER_SEL"};
    
  private:

    void initValueTree () override {}

};


};
