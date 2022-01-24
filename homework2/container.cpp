//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------

// Конструктор контейнера
Container::Container(): length(0) { }

//------------------------------------------------------------------------------

// Деструктор контейнера
Container::~Container() {
    Clear();
}

//------------------------------------------------------------------------------

// Очистка контейнера от элементов (освобождение памяти)
void Container::Clear() {
    for(int i = 0; i < length; i++) {        
        delete storage[i];
    }
    length = 0;
}

//------------------------------------------------------------------------------

// Ввод содержимого контейнера из указанного потока
void Container::In(ifstream &ifst) {
    while(!ifst.eof()) {
        if((storage[length] = Shape::StaticIn(ifst)) != 0) {
            length++;
        }
    }
}

//------------------------------------------------------------------------------

// Случайный ввод содержимого контейнера
void Container::InRnd(int size) {
    while(length < size) {
        if((storage[length] = Shape::StaticInRnd()) != nullptr) {
            length++;
        }
    }
}
//------------------------------------------------------------------------------

// Вывод содержимого контейнера в указанный поток
void Container::Out(ofstream &ofst) {
    ofst << "Container contains " << length << " elements." << endl;
    for(int i = 0; i < length; i++) {
        ofst << i << ": ";
        storage[i]->Out(ofst);
    }
}

// Вывод содержимого контейнера в тестовый файл.
void Container::OutShort(ofstream &ofst) {    
    for(int i = 0; i < length; i++) {        
        storage[i]->OutShort(ofst);
        if(i<length-1){
            ofst << "\n";
        }
    }
}
//------------------------------------------------------------------------------

// Вычисление средней площади поверхности всех фигур в контейнере
double Container::SurfaceAreaAverage() {
    double sum = 0.0;
    for(int i = 0; i < length; i++) {
        sum += storage[i]->SurfaceArea();
    }
    return sum/length;
}

//------------------------------------------------------------------------------

// Функция, оставляющая фигуры, у которых площадь поверхности выше средней всех фигур
    void Container::FilterBySurfaceArea() {
        int deleted = 0;
        int new_index = 0;
        double avg = SurfaceAreaAverage();
        for(int i = 0; i < length; ++i){
            if(storage[i]->SurfaceArea() <= avg){
                delete storage[i];
                deleted++;                
            } else {                
                storage[new_index++] = storage[i];
            }
        }          
        length -= deleted;
    }