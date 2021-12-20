#pragma once

#include "ParserTest.h"

#if IMPLEMENT_REAPER_DATA_STRUCTURES
#include "DataStructures/DataStructuresTest.h"
#endif

namespace Reaper
{
  class ReaperToolsTestRunner : public UnitTestRunner
  {
  public:
      ReaperToolsTestRunner ()
      {
          runAllTests();
      }
  };
  
  const static inline ReaperToolsTestRunner testRunner;

};
