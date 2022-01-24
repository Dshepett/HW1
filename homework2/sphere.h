#ifndef __sphere__
#define __sphere__

//------------------------------------------------------------------------------
// sphere.h - содержит описание шара  и его интерфейса.
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
#include "shape.h"

//------------------------------------------------------------------------------
// шар
class Sphere: public Shape {
public:
    virtual ~Sphere() { }
    // Ввод параметров шара из файла
    virtual void In(ifstream &ifst);
    // Случайный ввод параметров шара
    virtual void InRnd();
    // Вывод параметров шара в форматируемый поток
    virtual void Out(ofstream &ofst);
    // Вывод параметров шара в тестовый файл.
    virtual void OutShort(ofstream &ofst);
    // Вычисление площади поверхности шара
    double SurfaceArea();
private:
    int r; // радиус
};


#endif //__sphere__
