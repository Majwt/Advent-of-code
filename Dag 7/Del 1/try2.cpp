#include <bits/stdc++.h>
using namespace std;

// std::string Path = "..//input.txt";
std::string Path = "..//example.txt"; // andra fil vägen

int main()
{

    std::string l;
    std::ifstream input;
    input.open(Path);
    if (!input.is_open())
    {
        std::cout << "not found or could not open\n";
        return 1;
    }
    while (getline(input, l))
    {
        std::cout << l << endl;

    }
}