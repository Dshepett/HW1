//------------------------------------------------------------------------------
// sphere.cpp - содержит функции обработки шара
//------------------------------------------------------------------------------

#include "sphere.h"
#define M_PI 3.14159265358979323846

//------------------------------------------------------------------------------
// Ввод параметров шара из потока
void In(sphere &s, ifstream &ifst) {
    ifst >> s.r;
}

// Случайный ввод параметров шара
void InRnd(sphere &s) {
    s.r = Random();
}

//------------------------------------------------------------------------------
// Вывод параметров шара в поток
void Out(sphere &s, ofstream &ofst) {
    ofst << "It is a sphere: r = " << s.r
         << ". Surface area = " << SurfaceArea(s) << "\n";
}

//------------------------------------------------------------------------------
// Вывод параметров шара в тестовый файл.
void OutShort(sphere &s, ofstream &ofst) {
    ofst << 1<<"\n" << s.r<<"\n";
}

//------------------------------------------------------------------------------
// Вычисление периметра шара
double SurfaceArea(sphere &s) {
    return 4 * M_PI * s.r * s.r;
}