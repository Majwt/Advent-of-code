#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>

std::string l;
//std::string Path = "..//input.txt";
std::string Path = "..//example.txt"; // andra fil vägen
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
        std::cout << l << '\n';

    }
}