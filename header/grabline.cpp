#include "grabline.h"
#include <iostream>

std::vector<std::string> grabline(std::string Path, char delim = '\n') {
    std::ifstream input {Path};

    input.open(Path);
    
    std::vector<std::string> lines;
    if (!input.is_open()) {
        return lines;
    }
    std::string l;
    while (std::getline(input, l, delim))
    {
        lines.push_back(l);
    }
    return lines;
}