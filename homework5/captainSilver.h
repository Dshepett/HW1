#ifndef __captain__
#define __captain__

//------------------------------------------------------------------------------
// map.h - содержит тип данных,
// представляющий капитана Сильвера.
//------------------------------------------------------------------------------

#include <thread>
#include "map.h"

class CaptainSilver {
private:
    // количество группп пиратов.
    int number_of_groups;
    // Карта по которой ищут сокровище.
    Map *map;
public:
    CaptainSilver(Map *map, int amount_of_groups);

    ~CaptainSilver();

    // Поиск сокровища.
    int *findTreasure();
};
#endif