#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>
using namespace std;

std::string l;
std::string Path = "..//input.txt";
// std::string Path = "..//example.txt"; // andra fil vägen
vector<string> starting;
vector<int> spoken;
vector<string> duplicates;

void myFunction();

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
        // std::cout << l << '\n';

        spoken.push_back(stoi(l, nullptr, 10));
    }
    for (size_t i = 0; i <  2019; i++)
    {
        spoken.push_back(0);
    }
    cout << spoken.size() << endl;
    cout << spoken[0] << "\tturn: " << 0 << endl;
    cout << spoken[1] << "\tturn: " << 1 << endl;
    cout << spoken[2] << "\tturn: " << 2 << endl;
    cout << spoken[3] << "\tturn: " << 3 << endl;
    cout << spoken[4] << "\tturn: " << 4 << endl;
    cout << spoken[5] << "\tturn: " << 5 << endl;
    cout << spoken[6] << "\tturn: " << 6 << endl;
    myFunction();

    cout << endl
         << endl
         << spoken[2019] << endl;
}

void myFunction()
{
    for (int i = 7; i < 2019; i++)
    {

        int n = 0;
        cout << spoken[i] <<'\t' << i <<endl;
        for (int v = i - 1; v >= 0; v--)
        {

            if (spoken[v] == spoken[i])
            {
                spoken[i + 1] = i - v;

                break;
            }
        }
        
    }
}