#ifndef __parallelepiped__
#define __parallelepiped__

//------------------------------------------------------------------------------
// parallelepiped.h - содержит описание параллелепипеда  и его интерфейса.
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
#include "shape.h"

//------------------------------------------------------------------------------
// параллелепипед
class Parallelepiped : public Shape {
public:
    virtual ~Parallelepiped() { }
    // Ввод параметров параллелепипеда из файла
    virtual void In(ifstream &ifst);
    // Случайный ввод параметров параллелепипеда
    virtual void InRnd();
    // Вывод параметров параллелепипеда в форматируемый поток
    virtual void Out(ofstream &ofst);
    // Вывод параметров параллелепипеда в тестовый файл.
    virtual void OutShort(ofstream &ofst);
    // Вычисление площади поверхности параллелепипеда
    double SurfaceArea();
private:
    int a, b, c; //длина, ширина, высота
};

#endif //__parallelepiped__
