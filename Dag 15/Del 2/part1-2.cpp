#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <map>
using namespace std;

map<int, int> i1;
map<int, int>::iterator it1;
static std::string Path = "..//input.txt";
// std::string Path = "..//example.txt"; // andra fil vägen
int main()
{
    int looking;
    string l;
    std::ifstream input;
    input.open(Path);
    int count = 0;
    if (!input.is_open())
    {
        std::cout << "not found or could not open\n";
        return 1;
    }
    while (getline(input, l))
    {
        i1.insert(pair<int, int>(stoi(l, nullptr), count));
        count++;
        looking = stoi(l,nullptr);
    }
    for (int i = count-2; i < 29999999; i++)
    {
        const int temp = i + 1;
        it1 = i1.find(looking);
        if (it1 != i1.end())
        {
            int seperation = temp - it1->second;
            i1[looking] = temp;
            if (temp >= 29999999) {
                cout << looking << endl;
            }
            looking = seperation;
            continue;
        }
        else
        {
            i1[looking] = temp;
            looking = 0;
            continue;
        }
    }
    for (auto &&i : i1)
    {
        if (i.second >= 29999999)
        {
            cout << "number:" << i.first << "\t" << i.second+1 << "th" << endl;
            break;
        }
    }
}


