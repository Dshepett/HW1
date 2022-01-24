#ifndef __pirates__
#define __pirates__

//------------------------------------------------------------------------------
// groupOfPirates.h - содержит описание функции, представляющую из себя поиск скоровища на предложенной территории пиратам.
//------------------------------------------------------------------------------

#include "map.h"

void tryToFindTreasure(int start_position, int length, Map *map, int **results, int index);

#endif