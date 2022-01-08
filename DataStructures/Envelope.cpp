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

void EnvelopePoint::setPosition (double position)
{
    setValueInArray (PositionId, position);
}

double EnvelopePoint::getPosition ()
{
    return getValueInArray<double> (PositionId);
}

void EnvelopePoint::setLevel (double level)
{
    setValueInArray (LevelId, level);
}

double EnvelopePoint::getLevel ()
{
    return getValueInArray<double> (LevelId);
}

void EnvelopePoint::setShape (Shape shape)
{
    setValueInArray (ShapeId, (int)shape);
}

EnvelopePoint::Shape EnvelopePoint::getShape ()
{
    return (Shape)getValueInArray<int> (ShapeId);
}

void EnvelopePoint::setSelected (bool Selected)
{
    setValueInArray (SelectedId, Selected);
}

bool EnvelopePoint::getSelected ()
{
    return getValueInArray<bool> (SelectedId);
}

void EnvelopePoint::setUnknownAttribute (double UnknownAttribute)
{
    setValueInArray (UnknownAttributeId, UnknownAttribute);
}

double EnvelopePoint::getUnknownAttribute ()
{
    return getValueInArray<double> (UnknownAttributeId);
}

void EnvelopePoint::setTension (double Tension)
{
    setValueInArray (TensionId, Tension);
}

double EnvelopePoint::getTension ()
{
    return getValueInArray<double> (TensionId);
}

bool EnvelopePoint::setValueInArray (int index, var newValue, bool resizeIfPossible)
{
    auto array = getArrayPointer (ValuesId);
    jassert (array);
    
    if (array)
    {
        auto size = array->size();
        bool isLastEntry = index == size - 1;
        bool isEmpty = (double)newValue == 0.0;
        
        if (resizeIfPossible)
        {
            if ((isEmpty && isLastEntry))
            {
                int lastNonZeroValue = index - 1;
                
                while (lastNonZeroValue >= 0)
                {
                    if ((double)array->getUnchecked (lastNonZeroValue) != 0.0)
                        break;
                    
                    lastNonZeroValue--;
                }
                array->resize (lastNonZeroValue + 1);
            }
            else if (!isEmpty && index >= size)
            {
                array->resize (index);
                array->set (index, newValue);
            }
            else if (index < size)
            {
                array->set (index, newValue);
            }
            
            return true;
        }
        else if (index < size)
        {
            array->set (index, newValue);
            
            return true;
        }
            
        return false;
    }
    
    // array was not found...
    jassertfalse;
    return false;
        
}

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
