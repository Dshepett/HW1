#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "shape.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
class Container {
public:
    Container();
    ~Container();

    // Ввод содержимого контейнера из указанного потока
    void In(ifstream &ifst);
    // Случайный ввод содержимого контейнера
    void InRnd(int size);
    // Вывод содержимого контейнера в указанный поток
    void Out(ofstream &ofst); 
    // Вывод содержимого контейнера в тестовый файл.
    void OutShort(ofstream &ofst);
    // Вычисление средней площади поверности всех фигур в контейнере
    double SurfaceAreaAverage();
    // Функция, оставляющая фигуры, у которых площадь поверхности выше средней всех фигур
    void FilterBySurfaceArea();
private:
    // Очистка контейнера от элементов (освобождение памяти)
    void Clear();
    int length; // текущая длина контейнера
    Shape* storage[10000];
};

#endif
