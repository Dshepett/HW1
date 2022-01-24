#include "groupOfPirates.h"

//------------------------------------------------------------------------------
// groupOfPirates.cpp - содержит функцию, представляющую из себя поиск скоровища на предложенной территории пиратам.
//------------------------------------------------------------------------------

void tryToFindTreasure(int start_position, int length, Map *map, int **results, int index) {
    int **map_of_island = map->map;
    int width = map->width;
    int *max_point = new int[3];
    max_point[0] = INT32_MIN;
    for (int i = start_position; i < start_position + length; ++i) {
        int first = i / width;
        int second = i - first * width;
        if (max_point[0] <= map_of_island[first][second]) {
            max_point[0] = map_of_island[first][second];
            max_point[1] = first;
            max_point[2] = second;
        }
    }
    results[index] = max_point;
}
