#include "Envelope.h"

namespace Reaper
{

EnvelopePoint::EnvelopePoint ()
:
ValueTreeWrapper (ID)
{}

EnvelopePoint::EnvelopePoint (const ValueTree& ptTree)
:
ValueTreeWrapper (ID, ptTree)
{}

EnvelopePoint::EnvelopePoint (const EnvelopePoint& other)
:
ValueTreeWrapper (other)
{}

void EnvelopePoint::setPosition (double Position)
{
    
}

double EnvelopePoint::getPosition ()
{
    
}

void EnvelopePoint::setLevel (double level)
{
    
}

double EnvelopePoint::getLevel ()
{
    
}

void EnvelopePoint::setShape (double Shape)
{}
double EnvelopePoint::getShape ()
{}

void EnvelopePoint::setSelected (double Selected)
{}
double EnvelopePoint::getSelected ()
{}

void EnvelopePoint::setUnknownAttribute (double UnknownAttribute)
{}
double EnvelopePoint::getUnknownAttribute ()
{}

void EnvelopePoint::setTension (double Tension)
{}
double EnvelopePoint::getTension ()
{}

// ==================================================
// ==================================================
Envelope::Envelope (const Identifier& type)
:
ValueTreeWrapper (type)
{
}

Envelope::Envelope (const Identifier& type, const ValueTree& trackTree)
:
ValueTreeWrapper (type, trackTree)
{
}

Envelope::Envelope (const Envelope& other)
:
ValueTreeWrapper (other)
{
}








};
