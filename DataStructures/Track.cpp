namespace Reaper
{

Track::Track ()
:
ValueTreeWrapper (ID)
{
    
}

Track::Track (const ValueTree& trackTree)
:
ValueTreeWrapper (ID, trackTree)
{
}

Track::Track (const Track& other)
:
ValueTreeWrapper (other)
{
}

void Track::setVolume (float volume)
{
    setValueInVarArray (VOLPANID, 0, volume);
}

float Track::getVolume () const
{
    return (float)getValueInVarArray<double> (VOLPANID, 0);
}

void Track::setPan (float pan)
{
    setValueInVarArray (VOLPANID, 1, pan);
}

float Track::getPan () const
{
    return (float)getValueInVarArray<double> (VOLPANID, 1);
}

void Track::setMute (bool mute)
{
    setValueInVarArray (MUTESOLOID, 0, mute);
}

bool Track::getMute () const
{
    return getValueInVarArray <bool> (MUTESOLOID, 0);
}

void Track::setSolo (bool solo)
{
    setValueInVarArray (MUTESOLOID, 1, solo ? 2 : 0);
}

bool Track::getSolo () const
{
    return getValueInVarArray<int> (MUTESOLOID,1) > 0;
}

};
