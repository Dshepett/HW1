#ifndef __tetrahedron__
#define __tetrahedron__

//------------------------------------------------------------------------------
// tetrahedron.h - содержит описание тетраэдра  и его интерфейса.
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
#include "shape.h"

// тетраэдр
struct tetrahedron: shape {
    int a; // сторона
};

// Ввод параметров тетраэдра из файла
void In(tetrahedron &r, ifstream &ifst);

// Случайный ввод параметров тетраэдра
void InRnd(tetrahedron &r);

// Вывод параметров тетраэдра в форматируемый поток
void Out(tetrahedron &r, ofstream &ofst);

// Вывод параметров тетраэдра в тестовый файл.
void OutShort(tetrahedron &t, ofstream &ofst);

// Вычисление площади поверхности тетраэдра
double SurfaceArea(tetrahedron &r);

#endif //__tetrahedron__
