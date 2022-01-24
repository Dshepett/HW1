#include <iostream>
#include <ctime>
#include "captainSilver.h"
#include <cstring>


void errorMessage() {
    std::cout << "incorrect command line or data!\n"
                 "  Waited:\n"
                 "     command -f infile.txt outfile.txt // to run program from data from infile.txt\n"
                 "  Or:\n"
                 "     command -n height width numberOfGroups outfile.txt     // to run program with random map with chosen height width and number of groups of elements \n"
                 "  Width and height should be between 1 and 30. Number of groups should be less than multiplication of width and height and greater than zero. \n";
}


int main(int argc, char *argv[]) {
    srand(static_cast<unsigned int>(time(0)));
    Map *map;
    int group_count;
    std::string output_file;
    if (argc == 4 && !std::strcmp(argv[1], "-f")) {
        std::ifstream ifst(argv[2]);
        ifst >> group_count;
        std::cout << "Creating map....\n";
        map = new Map(ifst);
        output_file = argv[3];
    } else {
        if (argc == 6 && !std::strcmp(argv[1], "-n")) {
            int height = std::stoi(argv[2]);
            int width = std::stoi(argv[3]);
            group_count = std::stoi(argv[4]);
            if (height < 0 || height > 30 || width < 0 || width > 30 || width * height < group_count ||
                group_count < 1) {
                errorMessage();
                return 1;
            }
            output_file = argv[5];
            std::cout << "Creating map....\n";
            map = Map::generateMap(height, width);
        } else {
            errorMessage();
            return 1;
        }
    }
    clock_t start_time = clock();
    std::cout << "Start finding the treasure....\n";
    CaptainSilver *captain_silver = new CaptainSilver(map, group_count);

    int *result = captain_silver->findTreasure();
    clock_t end_time = clock();
    std::cout << "Finish finding the treasure....\n";
    std::ofstream ofst(output_file);
    map->PrintMap();
    map->PrintMap(ofst);
    std::cout << "The treasure has value = " << result[0] << " and is located on this coordinates: " << result[1] << " "
              << result[2];
    ofst << "The treasure has value = " << result[0] << " and is located on this coordinates: " << result[1] << " "
         << result[2];
    std::cout << "\nTime " << end_time - start_time << " ms.\n";
    ofst << "\nTime " << end_time - start_time << " ms.\n";
    delete captain_silver;
    delete[] result;
    return 0;
}