#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>

using namespace std;

string l;
vector<string> original;
vector<string> lines;
std::string Path = "..//input.txt";
//string Path = "..//example.txt"; // andra fil vägen
char empty = 'L';
char occupied = '#';
char flor = '.';

int doLine()
{
    int changes = 0;
    int near = 0;
    vector<string> previous;
    for (auto &&i : lines)
    {
        previous.push_back(i);
        cout << i << endl;
    }
    cout << endl;
    for (int v = 0; v < previous.size(); v++)
    {
      
        
        for (int h = 0; h < previous[v].size(); h++)
        {
        /**
        * *Horizontel
        */
            char seat = previous[v][h];
            if (seat == flor)
            {
                continue;
            }

            if (h != 0)
            {

                if (previous[v][h - 1] == occupied)
                {
                    near++;
                }
            }
            if (h != previous[v].size()-1)
            {

                if (previous[v][h + 1] == occupied)
                {
                    near++;
                }
            }

            if (v != previous.size()-1)
            {
                if (previous[v + 1][h - 1] == occupied)
                {
                    near++;
                }
                if (previous[v + 1][h] == occupied)
                {
                    near++;
                }
                if (previous[v + 1][h + 1] == occupied)
                {
                    near++;
                }
            }
            if (v != 0)
            {

                if (h != 0)
                {

                    if (previous[v - 1][h - 1] == occupied)
                    {
                        near++;
                    }
                }

                if (previous[v - 1][h] == occupied)
                {
                    near++;
                }
                if (h != previous[v].size()-1)
                {

                    if (previous[v - 1][h + 1] == occupied)
                    {
                        near++;
                    }
                }
            }
            //cout << "near: " << near << endl;
            if (seat == empty && near == 0)
            {
                lines[v][h] = occupied;
                changes++;
            }
            if (seat == occupied && near >= 4)
            {
                lines[v][h] = empty;
                changes++;
            }
            near = 0;
        }
    }
    return changes;

}
int totOccupied()
{
    int total = 0;
    for (auto &&i : lines)
    {
        for (auto &&v : i)
        {
            if (v == occupied) {
                total++;
            }
        }
        
    }
    return total;
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
        original.push_back(l);
    }
    
    while(doLine() != 0) {
        
    
    cout << endl;
}
if (doLine() == 0)
    cout << "Total Occupied Seats: " << totOccupied() << endl;
    
}