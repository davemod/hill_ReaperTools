#include "Item.h"


namespace Reaper
{


Item::Item ()
:
ValueTreeWrapper (ID)
{

}

Item::Item (const ValueTree& itemTree)
:
ValueTreeWrapper (ID, itemTree)
{
}


};
