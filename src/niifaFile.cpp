//
// Created by nz on 27.06.2020.
//


#include <fstream>
#include "niifaFile.h"


NiifaFile::NiifaFile(const char *filename) : filename(filename){
    std::string line;
    std::ifstream inputFile(filename, std::ios::binary | std::ios::ate);
    if(!inputFile){
        return;
    }
    std::streamsize size = inputFile.tellg();
    inputFile.seekg(0, std::ios::beg);

    char* buffer = static_cast<char *>(malloc(sizeof(char) * size));
    inputFile.read(buffer, size);
    inputFile.close();

    std::string data(buffer, size);
    delete[] buffer;

    size_t start = data.find(FIRST_NAME);
    start = data.find_first_of(' ', start) + 1;
    size_t stop = data.find_first_of('\n', start);
    size_t middle;
    while(true){
        middle = data.find_first_of(' ', start);
        if(middle > stop){
            signals.emplace_back(data.substr(start, stop - start));
            break;
        }
        signals.emplace_back(data.substr(start, middle - start));
        start = middle + 1;
    }
    start = stop + 1;

    size_t length = ((size - start)/4/(signals.size() + 1));
    char* currentPtr = data.data() + start;
    while (length > 0) {
        timeline.push_back(*((float *)(currentPtr)));
        currentPtr += 4;
        for (auto & signal : signals) {
            signal.values.push_back(*((float *)(currentPtr)));
            currentPtr += 4;
        }
        length --;
    }
    ok = true;
}

std::vector<float> NiifaFile::getTimeline() {
    return timeline;
}

Signal NiifaFile::getSignal(size_t number) {
    return signals.at(number);
}

Signal NiifaFile::getSignal(std::string name) {
    for(auto signal : signals){
        if(signal.name == name){
            return signal;
        }
    }
    return getSignal(999999);
}
