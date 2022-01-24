#ifndef __map__
#define __map__
//------------------------------------------------------------------------------
// map.h - содержит тип данных,
// представляющий карту с ее данными
//------------------------------------------------------------------------------
#include <fstream>

class Map {
private:
    Map(int height, int width, int **map);

public:
    explicit Map(std::ifstream &ifst);

    ~Map();

    // Колучение площади карты.
    int Area() const;

    // Вывод карты в консоль.
    void PrintMap() const;

    // Вывод карты в файл.
    void PrintMap(std::ofstream&) const;

    // Генерация карты по заданным параметрам.
    static Map *generateMap(int height, int width);

    // Ширина карты.
    int width;
    // Высота карты.
    int height;
    // Значение кажой точки карты.
    int **map;
};

#endif