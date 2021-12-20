namespace Reaper
{

Track::Track ()
:
ValueTreeWrapper (ID)
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

};
