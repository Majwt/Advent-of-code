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
int diff1;
int diff3;
//std::string Path = "..//input.txt";
 std::string Path = "..//example.txt"; // andra fil vägen


bool mySort (int i,int j) { return (i<j); }


/*
int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    sort(arr, arr+n, greater<int>()); 
  
    cout << "Array after sorting : \n"; 
    for (int i = 0; i < n; ++i) 
        cout << arr[i] << " "; 
  
*/

void myFunction()
{
    
   
    for (size_t i = 0; i < inputData.size(); i++)
    {
        // if (i+1 <inputData.size()) {
            diffArr.push_back(inputData[i+1]%inputData[i]);
            if(inputData[i+1]%inputData[i] == 1 || i == 0) {

                diff1 += 1;

            } else if( inputData[i+1]%inputData[i] == 3) {
                diff3 += 1;
            }

        // }
    }
    cout << endl;
    
        cout<< diff1 << endl;
        cout<< diff3 << endl;
    cout << endl;
    for (auto &&i : diffArr)
    {
        cout << i << endl;
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
        int line = stoi(l,nullptr,10);
        inputData.push_back(line);
        std::cout << line << '\n';

    }
    cout << endl;
    sort(inputData.begin(),inputData.end(),mySort);
    for (auto &&i : inputData)
    {
        cout<< i << endl;
    }
    inputData.push_back(inputData[inputData.size()-1]+3);
    myFunction();
    
    
}