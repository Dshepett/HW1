//------------------------------------------------------------------------------
// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры
//------------------------------------------------------------------------------

#include "parallelepiped.h"
#include "sphere.h"
#include "tetrahedron.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
shape* In(ifstream &ifst) {
    int k;
    ifst >> k;
    switch(k) {
        parallelepiped *p;
        sphere *s;
        tetrahedron *t;
        case 1:
            s = new sphere;
            s->k = shape::sphere;
            In(*s, ifst);
            return s;
        case 2:
            p = new parallelepiped;
            p->k = shape::parallelepiped;
            In(*p, ifst);
            return p;
        case 3:
            t = new tetrahedron;
            t->k = shape::tetrahedron;
            In(*t, ifst);
            return t;
        default:
            return 0;
    }
}

// Случайный ввод обобщенной фигуры
shape *InRnd() {
    auto k = rand() % 3 + 1;
    switch(k) {
        sphere *s;
        parallelepiped *p;
        tetrahedron *t;
        case 1:
            s = new sphere;
            s->k = shape::sphere;
            InRnd(*s);
            return s;
        case 2:
            p = new parallelepiped;
            p->k = shape::parallelepiped;
            InRnd(*p);
            return p;
        case 3:
            t = new tetrahedron;
            t->k = shape::tetrahedron;
            InRnd(*t);
            return t;
        default:
            return 0;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
void Out(shape &s, ofstream &ofst) {
    switch(s.k) {
        case shape::sphere:
            Out(*((sphere*)&s), ofst);
            break;
        case shape::parallelepiped:
            Out(*((parallelepiped*)&s), ofst);
            break;
        case shape::tetrahedron:
            Out(*((tetrahedron*)&s), ofst);
            break;
        default:
            ofst << "Incorrect figure!" << endl;
    }
}

// Вывод параметров текущей фигуры в тестовый файл.
void OutShort(shape &s, ofstream &ofst) {
    switch(s.k) {
        case shape::sphere:
            OutShort(*((sphere*)&s), ofst);
            break;
        case shape::parallelepiped:
            OutShort(*((parallelepiped*)&s), ofst);
            break;
        case shape::tetrahedron:
            OutShort(*((tetrahedron*)&s), ofst);
            break;
        default:
            ofst << "" << endl;
    }
}

//------------------------------------------------------------------------------
// Вычисление площади поверхности фигуры
double SurfaceArea(shape &s) {
    switch(s.k) {
        case shape::sphere:
            return SurfaceArea(*reinterpret_cast<sphere*>(&s));
            break;
        case shape::parallelepiped:
            return SurfaceArea(*reinterpret_cast<parallelepiped*>(&s));
            break;
        case shape::tetrahedron:
            return SurfaceArea(*reinterpret_cast<tetrahedron*>(&s));
            break;
        default:
            return 0.0;
    }
}

//------------------------------------------------------------------------------
// Удаление обобщенной фигуры
void DeleteShape(shape *s) {
   switch(s->k) {
       case shape::sphere:
            delete (sphere*)s;
            break;
       case shape::parallelepiped:
            delete (parallelepiped*)s;
            break;
        case shape::tetrahedron:
            delete (tetrahedron*)s;
            break;
       default:
            break;
    }
}
