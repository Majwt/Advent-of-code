#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>

using namespace std;

string l;
vector<string> lines;
//std::string Path = "..//input.txt";
string Path = "..//example.txt"; // andra fil vägen

void myFunction()
{

    char empty = 'L';
    char occupied = '#';
    char floor = '.';
    vector<string> previous;
    for (auto &&i : lines)
    {
        previous.push_back(i);
        cout << i << endl;
    }
    cout << endl;
int counter;
    for (size_t i = 0; i < 1; i++)
    {
        int index = i;
        int n;
        while (n < 9) {
            

            if (index == 0) {
                    counter++;
                if (n = 0)
                {
                    if (previous[i][n + 1] != occupied &&
                        previous[i + 1][n] != occupied &&
                        previous[i + 1][n + 1] != occupied)
                    {
                        lines[i][n] = occupied;
                    }
                        n++;
                }
                else
                {
                    if (previous[i][n + 1] != occupied &&
                        previous[i][n - 1] != occupied &&
                        previous[i + 1][n] != occupied &&
                        previous[i + 1][n + 1] != occupied &&
                        previous[i + 1][n - 1] != occupied)
                    {
                        lines[i][n] = occupied;
                    }
                    n++;
                    
                }
            }
            else if (index == 9) 
            {
                cout << "i=9" << endl;
                if (n = 0)
                {
                    if (previous[i][n + 1] != occupied &&
                        previous[i - 1][n] != occupied &&
                        previous[i - 1][n + 1] != occupied)
                    {
                        lines[i][n] = occupied;
                    }
                    n++;
                    
                }
                else
                {
                    if (previous[i][n + 1] != occupied &&
                        previous[i][n - 1] != occupied &&
                        previous[i - 1][n] != occupied &&
                        previous[i - 1][n + 1] != occupied &&
                        previous[i - 1][n - 1] != occupied)
                    {
                        lines[i][n] = occupied;
                    }
                    n++;
                    
                }
                
            } 
            else 
            {
            
            cout << "i!=0 || 9" << endl;
                if (previous[i - 1][n - 1] != occupied &&
                    previous[i - 1][n] != occupied &&
                    previous[i - 1][n + 1] != occupied &&
                    previous[i][n - 1] != occupied &&
                    previous[i][n + 1] != occupied &&
                    previous[i + 1][n - 1] != occupied &&
                    previous[i + 1][n] != occupied &&
                    previous[i + 1][n + 1] != occupied)
                {
                    lines[i][n] = occupied;
                }
                
                n++;
                    
            }
            
            
        }
            
        
    }
    slut:
    for (auto &&o : lines)
    {
        cout << o << endl;
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
        std::cout << l << '\n';
        lines.push_back(l);
    }
    cout << endl;
    
    myFunction();
}