#include <bits/stdc++.h>
using namespace std;

// std::string Path = "..//input.txt";
std::string Path = "..//example.txt"; // andra fil vägen

vector<vector<vector<char>>> cubes;
vector<vector<char>> inuts;
vector<char> temp;

void change() {

}

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
        for (auto &&i : l)
        {
            temp.push_back(i);
        }
        inuts.push_back(temp);
        temp.clear();

    }
    for (auto &&i : inuts)
    {
        for (auto &&q : i)
        {
            cout << q << " ";
        }
        cout << endl;
    }
    
}