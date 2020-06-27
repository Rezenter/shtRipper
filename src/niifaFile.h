//
// Created by nz on 27.06.2020.
//

#ifndef SHTRIPPER_NIIFAFILE_H
#define SHTRIPPER_NIIFAFILE_H


#include <vector>
#include <iostream>

#define FIRST_NAME "t_ms"

class Signal{
public:
    explicit Signal(std::string name) : name(name){};
    std::vector<float> values;
    std::string name;
};


class NiifaFile {
private:
    const char* filename;
    std::vector<Signal> signals;
    std::vector<float> timeline;

public:
    explicit NiifaFile(const char* filename);
    std::vector<float> getTimeline();
    Signal getSignal(size_t number);
    Signal getSignal(std::string name);
    bool ok = false;
};

#endif //SHTRIPPER_NIIFAFILE_H
