/***********************************************************************************
 BEGIN_JUCE_MODULE_DECLARATION

  ID:               hill_ReaperTools
  vendor:           David Hill
  version:          1.0.0
  name:             Hill Reaper Tools
  description:      Collection of tools to handle Reaper Files
  website:
  license:

  dependencies:     juce_core juce_data_structures juce_events hill_ValueTreeTools
  OSXFrameworks:
  iOSFrameworks:
  linuxLibs:
  mingwLibs:

 END_JUCE_MODULE_DECLARATION
***********************************************************************************/

#pragma once


#include <juce_core/juce_core.h>
#include <juce_data_structures/juce_data_structures.h> 
#include <juce_events/juce_events.h>
#include <stdio.h>

#include "Parser.h"

/** Config: IMPLEMENT_REAPER_DATA_STRUCTURES
 Implements data structures and interfaces to handle reaper files
 */
#ifndef IMPLEMENT_REAPER_DATA_STRUCTURES
#define IMPLEMENT_REAPER_DATA_STRUCTURES 1
#endif

#if IMPLEMENT_REAPER_DATA_STRUCTURES
#include "DataStructures/DataStructures.h"
#endif

/** Config: ENABLE_UNIT_TESTS
 Enable unit tests for this module
 */
#ifndef ENABLE_UNIT_TESTS
#define ENABLE_UNIT_TESTS 1
#endif

#if ENABLE_UNIT_TESTS
#include "UnitTests/ReaperToolsTestRunner.h"
#endif

