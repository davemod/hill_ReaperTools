/*
  ==============================================================================

    DataStructures.h
    Created: 17 Dec 2021 17:30 pm
    Author:  David Hill

  ==============================================================================
*/

#pragma once

#include "ReaperProject.h"

namespace Reaper
{

Project::Project ()
:
ValueTreeWrapper (ID)
{
    
}

Project::Project (const ValueTree& projectTree)
:
ValueTreeWrapper (ID, projectTree)
{
}

Project::Project (const Project& other)
:
ValueTreeWrapper (other)
{
    
}

void Project::setTimeSignature (TimeSignature ts)
{
    setValueInVarArray (TEMPOID, 1, ts.nominator);
    setValueInVarArray (TEMPOID, 2, ts.denominator);
}

Project::TimeSignature Project::getTimeSignature () const
{
    return {
        getValueInVarArray<int> (TEMPOID, 1),
        getValueInVarArray<int> (TEMPOID, 2)
    };
}

void Project::setSelection (Selection selection, bool selfCallback)
{
    setValueInVarArray (SELECTIONID, 0, selection.start);
    setValueInVarArray (SELECTIONID, 1, selection.end);
}

Project::Selection Project::getSelection () const
{
    return {
        getValueInVarArray<double> (SELECTIONID, 0),
        getValueInVarArray<double> (SELECTIONID, 1)
    };
}

void Project::setSelection2 (Selection selection, bool selfCallback)
{
    setValueInVarArray (SELECTION2ID, 0, selection.start);
    setValueInVarArray (SELECTION2ID, 1, selection.end);
}

Project::Selection Project::getSelection2 () const
{
    return {
        getValueInVarArray<double> (SELECTION2ID, 0),
        getValueInVarArray<double> (SELECTION2ID, 1)
    };
}

};
