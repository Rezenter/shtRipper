//
// Created by nz on 27.06.2020.
//

#include <iostream>
#include "version.h"

#include "niifaFile.h"

char* filename = "d:/code/shtRipper/in/00038654.dat";


int main(int argc, char* argv[]){


    std::cout << "cpp shtRipper, Version:" << VERSION << '\n' << std::endl;

    NiifaFile testFile(filename);

    std::cout << testFile.getTimeline().size() << std::endl;

    Signal test = testFile.getSignal("001");
    std::cout << test.name << ", " << test.values.size() << std::endl;

    std::cout << "tested " <<std::endl << std::flush;
    return 0;
}

