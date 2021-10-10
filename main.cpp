//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, 
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <ctime>   
#include <cstring>

#include "container.h"

void errMessage1() {
    cout << "incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile.txt outfile01.txt outfile02.txt // to run program from data from infile.txt\n"
            "  Or:\n"
            "     command -n number outfile01.txt outfile02.txt     // to run program with random number of elements \n"
            "  Or:\n"
            "     command -g outfile.txt                            // to generate test in outfile.txt\n";
}

void errMessage2() {
    cout << "incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if(argc == 3) {
        if(!strcmp(argv[1], "-g")) {
             container c;
            Init(c);            
            srand(static_cast<unsigned int>(time(0)));        
            auto size = rand() % 1000 + 1;            
            InRnd(c, size);
            ofstream ofst(argv[2]);
            OutShort(c, ofst);
            cout<<"Generated\n";
            return 0;
        }   
        errMessage2();
        return 1;
    }

    if(argc != 5) {
        errMessage1();
        return 1;
    }

    cout << "Start"<< endl;
    container c;
    Init(c);
    
    if(!strcmp(argv[1], "-f")) {
        ifstream ifst(argv[2]);
        In(c, ifst);
    }
    else if(!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) { 
            cout << "incorrect numer of figures = "
                 << size
                 << ". Set 0 < number <= 10000\n";
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        InRnd(c, size);
    }
    else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    ofstream ofst1(argv[3]);
    ofst1 << "Filled container:\n";
    Out(c, ofst1);

    // The 2nd part of task
    ofstream ofst2(argv[4]);
    ofst2 << "Surface area sum = " << SurfaceAreaSum(c) << "\n";

    Clear(c);
    cout << "Stop"<< endl;
    return 0;
}
