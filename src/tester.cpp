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

    std::cout << "tested ok" <<std::endl;
    for(int i = 0; i < 1000000; i++){}
    return 0;
}

