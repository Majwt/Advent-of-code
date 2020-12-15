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
    for (size_t turn = starting.size(); turn < 2021; turn++)
    {
        cout << spoken[turn-1] << endl;
        for (size_t i = 0; i < duplicates.size()-1; i++)
        {
            
        
            
        
        if(spoken[turn-1] == duplicates[i]) {
            spoken.push_back(0);
            //cout << spoken[turn] << endl;
            duplicates.push_back(0);
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
        starting.push_back(stoi(l,nullptr,10));
        spoken.push_back(stoi(l,nullptr,10));
        duplicates.push_back(stoi(l,nullptr,10));
    }
    myFucntion();
}