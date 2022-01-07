#pragma once

namespace Reaper
{

typedef Array<var> Playrate;
typedef Array<var> Fade;

class Item : public ValueTreeWrapper
{
public:

	const static inline Identifier ID {"ITEM"};

	Item ();
    Item (const ValueTree& itemTree);

	void setPosition (double position, bool selfCallback = false) { setValue (position, POSITIONID, selfCallback); }
	double getPosition () const { return getValue<double> (POSITIONID); }

//	void setSnapOffs (bool selfCallback = false);
//	void getSnapOffs () const;

	void setLength (double length, bool selfCallback = false) { setValue (length, LENGTHID, selfCallback); }
	double getLength () const { return getValue<double> (LENGTHID); }

	void setLoop (bool loop, bool selfCallback = false) { setValue (loop, LOOPID, selfCallback); }
	bool getLoop () const { return getValue<bool> (LOOPID); }

	void setAllTakes (bool allTakes, bool selfCallback = false) { setValue (allTakes, ALLTAKESID, selfCallback); }
	bool getAllTakes () const { return getValue<bool> (ALLTAKESID); }

	void setFadeIn (Fade fade, bool selfCallback = false) { setValue (fade, FADEINID, selfCallback); }
	Fade getFadeIn () const { return getArray (FADEINID); }

	void setFadeOut (Fade fade, bool selfCallback = false) { setValue (fade, FADEOUTID, selfCallback); }
	Fade getFadeOut () const { return getArray (FADEOUTID); }

	void setMute (bool mute, bool selfCallback = false) { setValueInVarArray (MUTEID, 0, mute); }
	bool getMute () const { return getValueInVarArray<bool> (MUTEID, 0); }

	void setSel (bool sel, bool selfCallback = false) { setValue (sel, SELID, selfCallback); }
	bool getSel () const { return getValue<bool> (SELID); }

	void setIGuid (const GUID iguid, bool selfCallback = false) { setValue((String)iguid, IGUIDID, selfCallback); }
    GUID getIGuid () const { return { getValue<String> (IGUIDID) }; }

	void setIId (const int& iid, bool selfCallback = false) { setValue(iid, IIDID, selfCallback); }
	int getIId () const { return getValue<int> (IIDID); }

	void setName (const String& name, bool selfCallback = false) { setValue (name, NAMEID, selfCallback); }
	String getName () const { return getValue<String> (NAMEID); }

	void setVolPan (Array<var> volPan, bool selfCallback = false) { setValue (volPan, VOLPANID, selfCallback); }
	Array<var> getVolPan () const { return getValue<Array<var>> (VOLPANID); }

    void setVolume (float volume, bool slefCallback = false) { setValueInVarArray (VOLPANID, 0, volume); }
    float getVolume () { return getValueInVarArray<float>(VOLPANID, 0); }
    
    void setPan (float pan, bool slefCallback = false) { setValueInVarArray (VOLPANID, 1, pan); }
    float getPan () { return getValueInVarArray<float>(VOLPANID, 1); }

	void setPlayrate (Playrate playRate, bool selfCallback = false) { setValue (playRate, PLAYRATEID, selfCallback); }
	Playrate getPlayrate () const { return getArray (PLAYRATEID); }

	void setChanMode (int chanMode, bool selfCallback = false) { setValue (chanMode, CHANMODEID, selfCallback); }
	int getChanMode () const { return getValue<int> (CHANMODEID); }

	void setGuid (const GUID& guid, bool selfCallback = false) { setValue ((String)guid, GUIDID, selfCallback); }
    GUID getGuid () const { return { getValue<String> (GUIDID) }; }

    Source getSource () { return getFirstChildOfType <Source> (); }
    
private:

	const static inline Identifier POSITIONID {"POSITION"};	// POSITION 2.5
	const static inline Identifier SNAPOFFSID {"SNAPOFFS"};    // SNAPOFFS 0
	const static inline Identifier LENGTHID {"LENGTH"};    // LENGTH 25.5
	const static inline Identifier LOOPID {"LOOP"};    // LOOP 1
	const static inline Identifier ALLTAKESID {"ALLTAKES"};    // ALLTAKES 0
	const static inline Identifier FADEINID {"FADEIN"};    // FADEIN 1 1.55 0 1 0 0 0
	const static inline Identifier FADEOUTID {"FADEOUT"};    // FADEOUT 1 0.01 0 1 0 0 0
	const static inline Identifier MUTEID {"MUTE"};    // MUTE 0 0
	const static inline Identifier SELID {"SEL"};    // SEL 0
	const static inline Identifier IGUIDID {"IGUID"};    // IGUID {8DFC0BC9-E3D7-A642-ABD8-1BADE5301DA4}
	const static inline Identifier IIDID {"IID"};    // IID 2
	const static inline Identifier NAMEID {"NAME"};    // NAME "01_Fat Man.wav"
	const static inline Identifier VOLPANID {"VOLPAN"};    // VOLPAN 1 0 1 -1
	const static inline Identifier SOFFSID {"SOFFS"};    // SOFFS 0
	const static inline Identifier PLAYRATEID {"PLAYRATE"};    // PLAYRATE 1 1 0 -1 0 0.0025
	const static inline Identifier CHANMODEID {"CHANMODE"};    // CHANMODE 0
	const static inline Identifier GUIDID {"GUID"};    // GUID {7521C72B-2744-6642-B645-FEAE80A35D60}
    
	void initValueTree () override {}

};

};
