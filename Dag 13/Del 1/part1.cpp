#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>
using namespace std;
int departtime = 1000052;
std::string l;
std::string Path = "..//input.txt";
std::vector<int> lines;
// std::string Path = "..//example.txt"; // andra fil vägen

void myFunction(int i) {
    int current = lines[i];
    int n = 1;
    int testing = 0;
    while (testing < departtime)
    {
        n++;
        testing = current * n;

    }
    cout << "next Depart: " << testing << "\t = \t"
    << lines[i] << " * " << n << endl;
    cout << testing - departtime << endl;
    cout << (testing - departtime) * current << endl;
    cout << endl;
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
        //std::cout << l << '\n';
        lines.push_back(stoi(l,nullptr,10));
    }

    for (size_t i = 0; i < lines.size(); i++)
    {
    myFunction(i);
        
    }
    
}