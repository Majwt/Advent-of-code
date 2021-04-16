#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>
using namespace std;
std::string l;
vector<int> inputData;
vector<int> diffArr;
vector<int> endArr;
int diff1;
int diff2;
int diff3;
// std::string Path = "..//input.txt";
std::string Path = "..//example.txt"; // andra fil vägen
// std::string Path = "..//lillaExample.txt"; // tredje fil vägen

#include "C:\Users\theodor.wase\Documents\Visual Studio 2019\projekt\hfiler\myfunctions.hpp"

bool mySort(int i, int j) { return (i < j); }
int counter;
size_t myFunction(vector<int> arr)
{
    vector<vector<int>> possible;
    vector<int> passpos;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i+1]-arr[i] == 3) {
            // cout << arr[i+1] << "\t"<< arr[i] <<endl;
            passpos.push_back(arr[i]);
            possible.push_back(passpos);
            passpos.clear();
        } else {
            // cout << arr[i] << " ";
            passpos.push_back(arr[i]);
            cout << passpos.at(0);
        }
    }
        cout << "\n[";
    for (auto &&i : possible)
    {
        cout << "[";
        for (auto &&j : i)
        {
            cout << j << ",";
        }
        cout << "],";
    }
        cout << "]"<< endl;
    size_t sum =1;
    for (auto &&n : possible)
    {
        switch (n.size())
        {
        case 3:
            sum *= 2;
            break;
        case 4:
            sum *= 4;
            break;
        case 5:
            sum *= 7;
            break;
        default:
            break;
        }
    }
    return sum;
    
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
        int line = stoi(l, nullptr, 10);
        inputData.push_back(line);
         //std::cout << line << ' ';
    }
    inputData.push_back(0);
    // cout << endl << "  ";
    sort(inputData.begin(), inputData.end(), mySort);
    inputData.push_back(inputData.at(inputData.size()-1)+3);
    for (auto &&n : inputData)
    {
        
       std::cout << n << ' ';
    }

    cout << myFunction(inputData) << endl;
    
    
    
}