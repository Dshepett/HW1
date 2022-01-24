#ifndef __tetrahedron__
#define __tetrahedron__

//------------------------------------------------------------------------------
// tetrahedron.h - содержит описание тетраэдра  и его интерфейса.
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
#include "shape.h"

//------------------------------------------------------------------------------
// тетраэдр
class Tetrahedron: public Shape {
public:
    virtual ~Tetrahedron() { }
    // Ввод параметров тетраэдра из файла
    virtual void In(ifstream &ifst);
    // Случайный ввод параметров тетраэдра
    virtual void InRnd();
    // Вывод параметров тетраэдра в форматируемый поток
    virtual void Out(ofstream &ofst);
    // Вывод параметров тетраэдра в тестовый файл.
    virtual void OutShort(ofstream &ofst);
    // Вычисление площади поверхности тетраэдра
    double SurfaceArea();
private:
    int a; // ребро
};


#endif //__tetrahedron__
