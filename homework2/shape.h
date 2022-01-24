#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// shape.h - содержит описание обобщающей геометрической фигуры,
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "rnd.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся фигуры
class Shape {
protected:
    static Random rnd30;
    static Random rnd3;
    double density; // плотность материала
public:
    virtual ~Shape() {};
    // Ввод обобщенной фигуры
    static Shape *StaticIn(ifstream &ifdt);
    // Ввод обобщенной фигуры
    virtual void In(ifstream &ifdt)=0;
    // Случайный ввод обобщенной фигуры
    static Shape *StaticInRnd();
    // Виртуальный метод ввода случайной фигуры
    virtual void InRnd() = 0;
    // Вывод обобщенной фигуры
    virtual void Out(ofstream &ofst) = 0;
    // Вывод параметров текущей фигуры в тестовый файл.
    virtual void OutShort(ofstream &ofst) = 0;
    // Вычисление площади поверхности обобщенной фигуры
    virtual double SurfaceArea() = 0;
 private:    
};


#endif
