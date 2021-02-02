#include <bits/stdc++.h>
using namespace std;

// std::string Path = "..//input.txt";
std::string Path = "..//example.txt"; // andra fil vägen

int main()
{

    std::string l;
    std::ifstream input{Path};
    if (!input)
    {
        std::cout << "not found or could not open\n";
        return 1;
    }
    while (input)
    {
        getline(input, l);
        stringstream parser{};
        parser << l;

        if (input.fail())
        {
            break;
        }

    }
}