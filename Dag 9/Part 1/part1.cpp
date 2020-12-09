#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>

std::string l;
std::vector<long long> arr;
std::string Path = "..//input.txt";
//std::string Path = "..//example.txt"; // andra fil vägen

int inputnum = 25;

bool myFunction(size_t i)
{
    bool yes = false;

    for (size_t n = i - inputnum; n < i - 0 ; n++)
    {

        for (size_t v = i - inputnum; v < i ; v++)
        {
            if(v == n) {
                continue;
            }
            if (arr[n] + arr[v] == arr[i])
            {
                // std::cout << "O | "<< n <<"\t"<< v <<"\t| "
                //           << arr[n] << "\t+\t" << arr[v] << "\t =\t" << arr[n] + arr[v] << "\t| " << arr[i] << "\n";
                 yes = true;
                 //break;
                 goto skip;
                // return yes;
            }
            else
            {
                
                // std::cout << "x | "<< n << "\t" << v <<"\t| "
                //           << arr[n] << "\t+\t" << arr[v] << "\t =\t" << arr[n] + arr[v] << "\t| " << arr[i] << "\n";
                
            }
        }
        
    }
    std::cout << "\nLine: " << i+1 << std::endl;
    if(yes) {
    skip:
        return true;
    } else {
        return false;
    }


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
        //std::cout << number << '\n';
        arr.push_back(number);
    }
    std::vector<int> fake;
    for (size_t i = inputnum; i < arr.size(); i++)
    {
        std::boolalpha;
        
        if (!myFunction(i))
        {
            
            //std::cout << "\nFalse\n--------------------\n\n\n";
            fake.push_back(i+1);
            goto slut;
            
            continue;
        }
      
    }
    slut:
    std::cout << "done" << std::endl;
    std::cout << "first false: " << arr[fake[0]-1];
}