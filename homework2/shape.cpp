//------------------------------------------------------------------------------
// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры
//------------------------------------------------------------------------------

#include "parallelepiped.h"
#include "sphere.h"
#include "tetrahedron.h"

//------------------------------------------------------------------------------\

Random Shape::rnd30(1, 30);
Random Shape::rnd3(1,3);

//------------------------------------------------------------------------------

// Ввод параметров обобщенной фигуры из файла
Shape* Shape::StaticIn(ifstream &ifst) {
    int k;
    ifst >> k;
    Shape* s = nullptr;
    switch (k) {
        case 1:
            s = new Sphere;
            break;
        case 2:
            s = new Parallelepiped;
            break;
        case 3:
            s = new Tetrahedron;
            break;
    }    
    s->In(ifst);
    return s;
}

// Случайный ввод обобщенной фигуры
Shape* Shape::StaticInRnd() {
    int k = Shape::rnd3.Get();    
    Shape* s = nullptr;
    switch (k) {
        case 1:
            s = new Sphere;
            break;
        case 2:
            s = new Parallelepiped;
            break;
        case 3:
            s = new Tetrahedron;
            break;
    }    
    s->InRnd();
    return s;
}
