#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>

std::string l;
std::vector<long long> arr;
std::vector<long long> fake;
std::string Path = "..//input.txt";
//std::string Path = "..//example.txt"; // andra fil vägen


bool myFunction()
{
    bool yes = false;

    for (size_t n = 0; n < arr.size(); n++)
    {

        long long testing = arr[n];

        std::cout << "\n\n";
        std::cout << arr[n] << std::endl;

        for (size_t v = 1; v < arr.size(); v++)
        {
            std::cout << arr[n + v] << std::endl;
            testing += arr[n + v];

            if (testing == 1492208709)
            {
                std::cout << "\n"<< testing << std::endl;
                yes = true;
                goto skip;
            }
        }
    }
    if (yes) {skip:return true;} else {return false;}
}

int main()
{
    std::ifstream input;
    input.open(Path);
    if (!input.is_open())
    {
        std::cout << "not found or could not open" << std::endl;
        return 1;
    }
    while (getline(input, l))
    {
        long long number = std::stoll(l, nullptr, 10);
        arr.push_back(number);
    }
    std::boolalpha;
    if (myFunction())
    {
        std::cout << "\ndone\n"<< std::endl;
    }
    else
    {
        std::cout << "didnt find" << std::endl;
    }
}