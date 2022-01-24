#ifndef __sphere__
#define __sphere__

//------------------------------------------------------------------------------
// sphere.h - содержит описание шара  и его интерфейса.
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
#include "shape.h"

// шар
struct sphere: shape {
    int r; // радиус
};

// Ввод параметров шара из файла
void In(sphere &r, ifstream &ifst);

// Случайный ввод параметров шара
void InRnd(sphere &r);

// Вывод параметров шара в форматируемый поток
void Out(sphere &r, ofstream &ofst);

// Вывод параметров шара в тестовый файл.
void OutShort(sphere &s, ofstream &ofst);

// Вычисление площади поверхности шара
double SurfaceArea(sphere &r);

#endif //__sphere__
