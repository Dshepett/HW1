#include "captainSilver.h"
#include "groupOfPirates.h"

//------------------------------------------------------------------------------
// map.h - содержит функции,
// для выполнения дествий капитана Сильвера.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

// Конструктор капитана.
CaptainSilver::CaptainSilver(Map *map, int amount_of_groups) {
    this->map = map;
    number_of_groups = amount_of_groups;
}

//------------------------------------------------------------------------------

// Поиск сокровища с использованием групп пиратов, которые представляются в виде потоков.
int *CaptainSilver::findTreasure() {
    std::thread *groups_of_pirates[number_of_groups];
    int area = map->Area();
    int **results = new int *[number_of_groups];
    // Создание потоков и распределение их по своим непересекающимся секциям
    for (int i = 0; i < number_of_groups; ++i) {
        groups_of_pirates[i] = new std::thread{tryToFindTreasure, i * area / number_of_groups,
                                               (i + 1) * area / number_of_groups - i * area / number_of_groups, map,
                                               results, i};
    }

    // Ожидание авершения поиска сокровища каждой группой пиратов
    for (int i = 0; i < number_of_groups; ++i) {
        groups_of_pirates[i]->join();
        delete groups_of_pirates[i];
    }

    int *result = new int[3];
    result[0] = INT32_MIN;

    // Итоговый поиск сокровища.
    for (int i = 0; i < number_of_groups; ++i) {
        if (results[i][0] > result[0]) {
            result[0] = results[i][0];
            result[1] = results[i][1];
            result[2] = results[i][2];
        }
        delete[] results[i];
    }

    delete[] results;

    return result;
}

//------------------------------------------------------------------------------

CaptainSilver::~CaptainSilver() {
    delete map;
}
