#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>
using namespace std;

std::string l;
std::string Path = "..//input.txt";
vector<int> starting;
vector<int> spoken;
vector<int> duplicates;
// std::string Path = "..//example.txt"; // andra fil vägen
void myFucntion()
{
    for (size_t turn = 1; turn < 2020; turn++)
    {
        for (size_t i = 0; i < duplicates.size()-1; i++)
        {
            if (spoken[turn] == duplicates[i])
            {
              

            } else {

            }
            
        }

    }
    
}
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
        starting.push_back(stoi(l, nullptr, 10));
        spoken.push_back(stoi(l, nullptr, 10));
        duplicates.push_back(stoi(l, nullptr, 10));
    }
    myFucntion();
}