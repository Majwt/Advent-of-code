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
// string Path = "..//miniTest.txt"; // andra fil vägen

/**
 * *instructioner
 * 
 * 
 * 
 */

char emptySeat = 'L';
char occupied = '#';
char flor = '.';

int searchDir(vector<string> pre, int sx, int sy, int dx, int dy)
{

    int x = dx;
    int y = dy;
    int hit = 0;
    
    while (pre[sy + y][sx + x] == flor)
    {
        

            if (sy + y == 0 && y != 0)
            {
                // cout << "\tsy + y == 0\t";
                break;
            }
    

            if (sy + y == pre.size() - 1 && sy != pre.size() - 1)
            {
                // cout << "\tsy + y == pre.size() - 1\t";
                break;
            }
        

       

            if (sx + x == 0 && x != 0)
            {
                // cout << "\tsx + x == 0\t";
                break;
            }
        
        

            if (sx + x == pre.size() - 1 && sx != pre.size() - 1)
            {
                // cout << "\tsx + x == pre.size() - 1\t";
                break;
            }
        
        y += dy;
        x += dx;
    }
    // y += dy;
    // x += dx;
    if (pre[sy + y][sx + x] == occupied)
    {
        hit = 1;
    }
    else if (pre[sy + y][sx + x] == emptySeat)
    {
        hit = 0;
    } 

    // cout << "\thit: " << hit << "\t|\t";
    // cout << sy << "+" << y << "  \t= " << sy + y << "  \t" << sx << "+" << x << "  \t= " << sx + x << "  \t" << pre[sy + y][sx + x] << endl;

    return hit;
}

int doLine()
{
    int changes = 0;
    int near = 0;
    vector<string> previous;
    for (auto &&i : lines)
    {
        previous.push_back(i);
        for (auto &&v : i)
        {
            // cout << v << " ";
        }
        // cout << endl;
    }
    
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
            // cout << endl << v << "/" << h << endl;
            if (h != 0)
            {
                // cout << "<-  \t" << near;
                near += searchDir(previous, h, v, -1, 0); // <-
            }

            if (h != previous[v].size() - 1)
            {
                // cout << "->  \t" << near;
                near += searchDir(previous, h, v, 1, 0); // ->
            }

            if (v != previous.size() - 1)
            {
                // cout << "v   \t" << near;
                near += searchDir(previous, h, v, 0, 1); // .|.
                if (h != 0)
                {
                    // cout << "v<  \t" << near;
                    near += searchDir(previous, h, v, -1, 1); // ./
                }
                if (h != previous[v].size() - 1)
                {
                    // cout << ">v  \t" << near;
                    near += searchDir(previous, h, v, 1, 1); // \.
                }
            }
            if (v != 0)
            {
                // cout << "^   \t" << near;
                near += searchDir(previous, h, v, 0, -1); //0,-1 ^

                if (h != 0)
                {
                    // cout << "^<  \t" << near;
                    near += searchDir(previous, h, v, -1, -1); // ^\.
                }

                if (h != previous[v].size() - 1)
                {
                    // cout << ">^  \t" << near;
                    near += searchDir(previous, h, v, 1, -1); // /^
                }
            }
            //cout << "near: " << near << endl;
            if (seat == emptySeat && near == 0)
            {
                lines[v][h] = occupied;
                changes++;
            }
            if (seat == occupied && near >= 5)
            {
                lines[v][h] = emptySeat;
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
    cout << endl;
    for (auto &&i : lines)
    {
        
        for (auto &&v : i)
        {
            if (v == occupied)
            {
                total++;
            }
        }

    }

    return total;
}
int main()
{
    int temp = 0;
    std::ifstream input;
    input.open(Path);
    if (!input.is_open())
    {
        std::cout << "not found or could not open\n";
        return 1;
    }

    while (getline(input, l))
    {
        // std::cout << l << '\n';
        lines.push_back(l);
        original.push_back(l);
    }


    while (doLine() != 0)
    {

         cout << temp << endl;
         temp++;
    }
    
    if (doLine() == 0)
        cout << endl << "Total Occupied Seats: "<< totOccupied() << endl;

cout << endl;
    // for (auto &&i : lines)
    // {
    //     cout << endl;
    //     for (auto &&v : i)
    //     {
    //     cout << v <<" ";
            
    //     }

    // }
}