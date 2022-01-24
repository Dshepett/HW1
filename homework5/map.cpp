#include "map.h"
#include <iostream>

//------------------------------------------------------------------------------
// map.h - содержит функции обработки карты.
//------------------------------------------------------------------------------

// Конструтор карты из файла..
Map::Map(std::ifstream &ifst) {
    ifst >> height >> width;
    map = new int *[height];
    for (size_t i = 0; i < height; ++i) {
        map[i] = new int[width];
        for (size_t j = 0; j < width; ++j) {
            ifst >> map[i][j];
        }
    }

}

//------------------------------------------------------------------------------

// Деструктор карты.
Map::~Map() {
    for (size_t i = 0; i < height; ++i) {
        delete[] map[i];
    }
    delete[] map;
}

//------------------------------------------------------------------------------

// Вывод карты в консоль.
void Map::PrintMap() const {
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; ++j) {
            std::cout << map[i][j] << " ";
        }
        std::cout << "\n";
    }
}

//------------------------------------------------------------------------------

// Вывод карты в файл.
void Map::PrintMap(std::ofstream &ofst) const {
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; ++j) {
            ofst << map[i][j] << " ";
        }
        ofst << "\n";
    }
}

//------------------------------------------------------------------------------

// Получение площади карты.
int Map::Area() const {
    return height * width;
}

//------------------------------------------------------------------------------

// Генерация карты по заданным харатктеристикам.
Map *Map::generateMap(int height, int width) {
    int **map = new int *[height];
    for (size_t i = 0; i < height; ++i) {
        map[i] = new int[width];
        for (size_t j = 0; j < width; ++j) {
            map[i][j] = rand() % 15000;
        }
    }
    return new Map(height, width, map);
}

//------------------------------------------------------------------------------

// Приватный конструктор, необходимый при рандомной генерации.
Map::Map(int height, int width, int **map) : height(height), width(width), map(map) {
}

