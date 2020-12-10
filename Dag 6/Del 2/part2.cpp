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

char alphabet[26]{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

void myFunction()
{
    int groupTotal = 0;

    for (size_t n = 0; n < list.size(); n++)
    {
        int inGroup = std::count(list[n].begin(), list[n].end(), ',');
        std::cout << list[n] << " ";
        std::cout << groupTotal << "\n";
        for (size_t p = 0; p < 27; p++)
        {
            if (std::count(list[n].begin(), list[n].end(), alphabet[p]) == inGroup)
            {
                groupTotal += 1;
            }
        }
    }
    std::cout << "\n total :" << groupTotal << "\n";
}
int main()
{
    int total;
    std::ifstream input;
    input.open(Path);
    if (!input.is_open())
    {
        std::cout << "not found or could not open\n";
        return 1;
    }

    while (getline(input, l))
    {
        //std::cout << line << "\n";
        if (l.empty())
        {
            list.push_back(line);
            line = "";
        }
        else
        {
            line += l;
            line += ',';
        }
    }
    myFunction();
}
