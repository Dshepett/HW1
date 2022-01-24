//------------------------------------------------------------------------------
// tetrahedron.cpp - содержит функции обработки тетраэдра
//------------------------------------------------------------------------------

#include "tetrahedron.h"
#include "math.h"

//------------------------------------------------------------------------------
// Ввод параметров тетраэдра из потока
void Tetrahedron::In(ifstream &ifst) {
    ifst >> a >> density;
}

// Случайный ввод параметров тетраэдраconsole.log();
void Tetrahedron::InRnd() {
    a = Shape::rnd30.Get();   
    density =  Shape::rnd30.Get();
}

//------------------------------------------------------------------------------
// Вывод параметров тетраэдра в поток
void Tetrahedron::Out(ofstream &ofst)
{
    ofst << "It is a tetrahedron: a = " << a   
         << "; density = " << density      
         << ". Surface area = " << SurfaceArea() << "\n";
}

// Вывод параметров тетраэдра в тестовый файл.
void Tetrahedron::OutShort(ofstream &ofst){
    ofst << 3 << "\n" << a << " " << density;
}

//------------------------------------------------------------------------------
// Вычисление периметра тетраэдра
double Tetrahedron::SurfaceArea() {
    return sqrt(3) * a * a;
}