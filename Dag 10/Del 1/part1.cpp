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
//std::string Path = "..//input.txt";
//std::string Path = "..//example.txt"; // andra fil vägen
std::string Path = "..//lillaExample.txt"; // tredje fil vägen

bool mySort(int i, int j) { return (i < j); }
int counter;
void myFunction(int index)
{
    int ind2;
    
int last;
    for (size_t i = 0; i < inputData.size(); i++)
    {
        
            
        
        
        // if (inputData[i + 1] % inputData[i] == 1 &&
        //      inputData[i + 2] % inputData[i + 1] == 1 &&
        //      inputData[i] % inputData[i-1] == 1 && i < index ) {
        //      cout << "2st 1 - 2" << endl;
            
        //      endArr.push_back(inputData[i+1]);
        //      i+=1;
        //      diff2 += 1;
             
        //  }
        if (inputData[i + 1] % inputData[i] == 1 &&
             inputData[i + 2] % inputData[i + 1] == 1 && 
             inputData[i + 3] % inputData[i+2] == 1 &&
             inputData[i] % inputData[i-1] == 1 && i < index) {
             cout << "3st 1 - 3" << endl;
      
             endArr.push_back(inputData[i+2]);
             i+=2;
             diff3 += 1;
            continue;  
         }
         if (inputData[i + 1] % inputData[i] == 3)
        {
            
            cout << "hoppade 3" << endl;
            endArr.push_back(inputData[i]);
            diff3 += 1;
            
        }
         if (inputData[i + 1] % inputData[i] == 1)
        {
            cout << "hoppade 1" << endl;
            
            endArr.push_back(inputData[i]);
            diff1 += 1;
            
        }
        else {
            
            cout << "else" << endl;
            endArr.push_back(inputData[i]);
        }
        
        
    }
     endArr.push_back(22);
    //diff1++;
    counter++;
    cout  << endl;
    for (auto &&i : endArr)
    {
        cout << i<< ' ';
    }
    cout << '\t' << inputData.size() << '\t';
    endArr.clear();
    
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
    // cout << endl << "  ";
    sort(inputData.begin(), inputData.end(), mySort);
    for (auto &&n : inputData)
    {
        
       std::cout << n << ' ';
    }
    
    //for (auto &&i : inputData)
    //{
            
        
        myFunction(3);
       // cout<< i << '\t';
        cout<<counter<<endl;
        
    //}
    
    
}