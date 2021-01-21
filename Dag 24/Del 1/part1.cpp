#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>
using namespace std;

 
struct Hex
{
    int x;
    int y;
    int z;
    bool white = true;
};

vector<Hex> Hexes;

std::string l;
// std::string Path = "..//input.txt";
std::string Path = "..//example.txt"; // andra fil vägen
vector<string> locators;
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
        locators.push_back(l);
    }
}