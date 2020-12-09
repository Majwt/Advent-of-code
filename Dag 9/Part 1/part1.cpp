#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>

std::string l;
std::string Path = "..//input.txt";
std::vector<int> arr;
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
        int number = std::stoi(l,nullptr,10);
        std::cout << 1ll*number << '\n';
        arr.push_back(1ll*number);

    }
}