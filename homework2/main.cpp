//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, 
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <cstring>

#include "container.h"

void errMessage1() {
    cout << "incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile.txt outfile01.txt outfile02.txt // to run program from data from infile.txt\n"
            "  Or:\n"
            "     command -n number outfile01.txt outfile02.txt     // to run program with random number of elements \n"
            "  Or:\n"
            "     command -g number outfile.txt                            // to generate test with 'number' elements in outfile.txt\n";
}

void errMessage2() {
    cout << "incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile.txt outfile01.txt outfile02.txt // to run program from data from infile.txt\n"
            "  Or:\n"
            "     command -n number outfile01.txt outfile02.txt     // to run program with random number of elements \n"
            "  Or:\n"
            "     command -g number outfile.txt                            // to generate test with 'number' elements in outfile.txt\n";
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    clock_t begin;
    clock_t end;
    if(argc == 4) {
        if(!strcmp(argv[1], "-g")) {             
            Container c;        
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
            c.InRnd(size);                
            ofstream ofst(argv[3]);
            c.OutShort(ofst);
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
    Container c;
    
    if(!strcmp(argv[1], "-f")) {
        begin = clock();
        ifstream ifst(argv[2]);
        c.In(ifst);
    }
    else if(!strcmp(argv[1], "-n")) {
        begin = clock();
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
        c.InRnd(size);
    }
    else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    ofstream ofst1(argv[3]);
    ofst1 << "Filled container:\n";
    c.Out(ofst1);

    // Вторая часть задания
    ofstream ofst2(argv[4]);
    ofst2 << "Surface area AVG = " << c.SurfaceAreaAverage() << "\n" << "Figures with surface area greater than AVG: \n";    
    cout << "Stop"<< endl;    
    c.FilterBySurfaceArea();
    c.Out(ofst2);
    end = clock();
    ofst2 << "Time: " << (double)(end-begin)/CLOCKS_PER_SEC << " s.";
    return 0;
}
