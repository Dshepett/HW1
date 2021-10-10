#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// shape.h - содержит описание обобщающей геометрической фигуры,
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся фигуры
struct shape {
    // значения ключей для каждой из фигур
    enum key {sphere,
        parallelepiped,
        tetrahedron};
    key k; // ключ
};

// Ввод обобщенной фигуры
shape *In(ifstream &ifdt);

// Случайный ввод обобщенной фигуры
shape *InRnd();

// Вывод обобщенной фигуры
void Out(shape &s, ofstream &ofst);

// Вывод параметров текущей фигуры в тестовый файл.
void OutShort(shape &s, ofstream &ofst);

// Вычисление площади поверхности обобщенной фигуры
double SurfaceArea(shape &s);

// Удаление обобщенной фигуры
void DeleteShape(shape *s);

#endif
