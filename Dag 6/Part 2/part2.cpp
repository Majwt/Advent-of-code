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
char alphabet[26] {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int group(std::string searchline,char ch) {
        if(searchline.find_first_of(ch) != std::string::npos) {
            return 1;
        } else
        {
            return 0;
        }
        
}
int myFunction() {
    int groupTotal = 0;
    for (size_t n = 0; n < list.size(); n++)
    {
        for (size_t p = 0; p < 27; p++)
        {
        groupTotal += group(list[n],alphabet[p]);
            
        }
        
    }
    return groupTotal;
    
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
        std::cout << line << "\n";
        if (l.empty())
        {
            list.push_back(line);
            line = "";
        } else {
            line += l;
        }
    }

    total += myFunction();

    for (size_t i = 0; i < list.size() + 1; i++)
    {
        std::cout << list[i] << "\n";
    }
    std::cout <<"\n" << total << " total\n";
    
}