#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>

std::string l;
std::vector<long long> arr;
//std::string Path = "..//input.txt";
std::string Path = "..//example.txt"; // andra fil vägen

int preamable = 5;
bool myFunction(size_t i) {
    bool yes;
    
    std::cout << i << '\n';
    
    
        for (size_t n = i-1; n > i-(preamable+1); n--)
        {
        
        for (size_t v = i-(preamable+1); v < i-1; v++)
        {
        
        if (arr[i] == arr[n]+arr[v] && arr[n] != arr[v]) {
            yes = true;            
            break;
        }
            std::cout << "no v\n";
        }
            std::cout << "no n \n";

        }
    
    
    if (yes) {
            return true;
        }
        else 
        {

        return false;
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
        long long number = std::stoll(l,nullptr,10);
        std::cout << number << '\n';
         arr.push_back(number);
    }

    for (size_t i = preamable+1; i < arr.size(); i++)
    {
       if(myFunction(i) == false) {
           std::cout << "\nindex: " << i << '\n';
           break;
       } else {
           continue;
       }
    }
    
}