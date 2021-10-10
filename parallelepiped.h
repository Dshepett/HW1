#ifndef __parallelepiped__
#define __parallelepiped__

//------------------------------------------------------------------------------
// parallelepiped.h - содержит описание параллелепипеда  и его интерфейса.
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
#include "shape.h"

// параллелепипед
struct parallelepiped: shape {
    int a,b,c; // длина, ширина, высота
};

// Ввод параметров параллелепипеда из файла
void In(parallelepiped &r, ifstream &ifst);

// Случайный ввод параметров параллелепипеда
void InRnd(parallelepiped &r);

// Вывод параметров параллелепипеда в форматируемый поток
void Out(parallelepiped &r, ofstream &ofst);

// Вывод параметров параллелепипеда в поток
void OutShort(parallelepiped &p, ofstream &ofst);

// Вычисление площади поверхности параллелепипеда
double SurfaceArea(parallelepiped &r);

#endif //__parallelepiped__
