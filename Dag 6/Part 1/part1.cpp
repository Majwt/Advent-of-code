#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>

std::string l;
std::string line;
std::vector<std::string> list;
std::string Path = "..//input.txt";
// std::string Path = "..//example.txt"; // andra fil vägen
int main()
{

    std::ifstream input;
    input.open(Path);
    if (!input.is_open())
    {
        std::cout << "not found or could not open\n";
        return 1;
    }

    while (getline(input, l))
    {
        std::cout << line << "\n";
        if (l.empty())
        {
            list.push_back(line);
            line = "";
        } else {
            line += l;
        }
    }

    ;
}