#pragma once

using namespace juce;

namespace Reaper
{

class EnvelopePoint : public ValueTreeWrapper
{
public:
    
    EnvelopePoint ();
    EnvelopePoint (const ValueTree& ptTree);
    EnvelopePoint (const EnvelopePoint& other);
    
    const static inline Identifier ID {"PT"};
    const static inline Identifier ValuesId {"PT"};
    
    void setPosition (double Position);
    double getPosition ();
    
    void setLevel (double level);
    double getLevel ();
    
    void setShape (double Shape);
    double getShape ();
    
    void setSelected (double Selected);
    double getSelected ();
    
    void setUnknownAttribute (double UnknownAttribute);
    double getUnknownAttribute ();
    
    void setTension (double Tension);
    double getTension ();
    
    
    
    
//    PT 0 0.99 5 1 0 0 -0.18211639 // Position, Value, Shape, ?, Selected, Tension
//    THE ARRAY DOES ONLY CONTAIN VALUES UNTIL THE LAST NON ZERO VALUE
    const static inline Identifier PositionId {"PositionId"};
    const static inline Identifier ValueId {"ValueId"};
    const static inline Identifier ShapeId {"ShapeId"};
    const static inline Identifier SelectedId {"SelectedId"};
    const static inline Identifier UnknownAttributeId {"UnknownAttributeId"};
    const static inline Identifier TensionId {"TensionId"};
    
private:
    
    void initValueTree () override {}
    
};

class Envelope : public ValueTreeWrapper
{

public:
    
    Envelope (const Identifier& type);
    Envelope (const Identifier& type, const ValueTree& envTree);
    Envelope (const Envelope& other);

    void setEguid (const GUID& eguid, bool selfCallback = false) { setValue ((String)eguid, EGUIDID, selfCallback); }
    GUID getEguid () const { return getValue<String> (EGUIDID); }
    
    void setActive (bool active, bool selfCallback = false) { setValueInVarArray (ACTID, 0, active); }
    bool getActive () const { return getValueInVarArray<bool> (ACTID, 0); }
    
    void setVisible (bool isVisible, bool selfCallback = false) { setValueInVarArray (VISID, 0, isVisible); }
    bool getVisible () { getValueInVarArray<bool> (VISID, 0); }
    
    void setVisibleInExtraLane (bool hasItsOwnLane, bool selfCallback = false) { setValueInVarArray (VISID, 1, hasItsOwnLane); }
    bool getVisibleInExtraLane () { getValueInVarArray<bool> (VISID, 1); }
    
    void setArm (int armed, bool selfCallback = false) { setValue (armed, ARMID, selfCallback); }
    int getArm () const { return getValue<int> (ARMID); }
    
//    void setDefShape (bool selfCallback = false) {}
//    int getDefShape () const { return getValue<int> (DEFSHAPEID); }
    
    enum VolType { AmplitudeScaling = 0, FaderScaling };
    void setVolType (VolType volType, bool selfCallback = false) { setValue ((int)volType, VOLTYPEID, selfCallback); }
    VolType getVolType () const { return (VolType)getValue<int> (VOLTYPEID); }
    
    EnvelopePoint getPoint (int index)
    {
        return { getChild(index) };
    }
    
    EnvelopePoint operator[] (int index)
    {
        return getPoint (index);
    }
    
private:

    const static inline Identifier EGUIDID {"EGUID"}; // {843D34E4-5132-BC45-8906-C25E10041DF9}
    const static inline Identifier ACTID {"ACT"}; // 1 -1
    const static inline Identifier VISID {"VIS"}; // 0 1 1
    const static inline Identifier LANEHEIGHTID {"LANEHEIGHT"}; // 0 0
    const static inline Identifier ARMID {"ARM"}; // 1
    const static inline Identifier DEFSHAPEID {"DEFSHAPE"}; // 0 -1 -1
    const static inline Identifier VOLTYPEID {"VOLTYPE"}; // 1

    void initValueTree () override {}
    
};

class VolumeEnvelope2 : public Envelope
{
public:
    VolumeEnvelope2 () : Envelope (ID) {}
    VolumeEnvelope2 (const ValueTree& vt) : Envelope (ID, vt) {}
    
    const static inline Identifier ID {"VOLENV2"};
    
private:
    
};

}
