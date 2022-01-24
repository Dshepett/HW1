//------------------------------------------------------------------------------
// output.c - единица компиляции, вбирающая в себя все функции вывода данных
//------------------------------------------------------------------------------

#include <stdio.h>

#include "extdata.h"

// Вычисление периметра прямоугольника
double SurfaceAreaSphere(void *r);

// Вывод параметров прямоугольника в файл
void OutSphere(void *r, FILE *ofst) {
    fprintf(ofst, "It is a Sphere: x = %d, density = %d. Surface Area = %g\n",
            *((int*)r), *((int*)(r+intSize)), SurfaceAreaSphere(r));
}

// Вычисление периметра прямоугольника
double SurfaceAreaTetrahedron(void *r);

// Вывод параметров прямоугольника в файл
void OutTetrahedron(void *r, FILE *ofst) {
    fprintf(ofst, "It is a Tetarhedron: x = %d, density = %d. Surface Area = %g\n",
            *((int*)r), *((int*)(r+intSize)), SurfaceAreaTetrahedron(r));
}

// Вычисление периметра треугольника
double SurfaceAreaParallelepiped(void *t);

// Вывод параметров треугольника в файл
void OutParallelepiped(void *t, FILE *ofst) {
    fprintf(ofst, "It is a Parallelepiped: a = %d, b = %d, c = %d, density = %d. Surface area = %g\n",
           *((int*)t), *((int*)(t+intSize)), *((int*)(t+2*intSize)),
            *((int*)(t+3*intSize)), SurfaceAreaParallelepiped(t));
}

// Вывод параметров текущей фигуры в файл
void OutShape(void *s, FILE *ofst) {
    int k = *((int*)s);
    if(k==SPHERE){
        OutSphere(s + intSize, ofst);
    } else{
        if(k == TETRAHEDRON){
            OutTetrahedron(s + intSize, ofst);
        } else{
            if(k== PARALLELEPIPED){
                OutParallelepiped(s + intSize, ofst);
            } else{
                fprintf(ofst, "Incorrect figure!\n");
            }
        }
    }    
}

// Вывод содержимого контейнера в файл
void OutContainer(void *c, int len, FILE *ofst) {
    void *tmp = c;
    fprintf(ofst, "Container contains %d elements.\n", len);
    for(int i = 0; i < len; i++) {
        fprintf(ofst, "%d: ", i+1);
        OutShape(tmp, ofst);
        tmp = tmp + shapeSize;
    }
}
