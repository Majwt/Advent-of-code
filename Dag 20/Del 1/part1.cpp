#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <sstream>
using namespace std;

std::string l;
std::string Path = "..//input.txt";
// std::string Path = "..//example.txt"; // andra fil vägen

vector<string> line;
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
        if (l.empty()) 
        {

        line.push_back(l);
        }
        //lines.push_back();
    }
}