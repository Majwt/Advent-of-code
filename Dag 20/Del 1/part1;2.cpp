#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <sstream>
using namespace std;

std::string l;
// std::string Path = "..//input.txt";
std::string Path = "..//example.txt"; // andra fil vägen

vector<string> lines;
vector<vector<string>> line;
vector<int> ids;
struct tile
{
    string right;
    string left;
    string up;
    string down;
    string rright;
    string rleft;
    string rup;
    string rdown;
    int id;
    void rotate90r()
    {
        auto temp = right;
        auto temp2 = left;
        auto temp3 = up;
        auto temp4 = down;
        right = temp3;
        left = temp4;
        down = temp;
        up = temp2;
        auto rtemp = rright;
        auto rtemp2 = rleft;
        auto rtemp3 = rup;
        auto rtemp4 = rdown;
        rright = rtemp3;
        rleft = rtemp4;
        rdown = rtemp;
        rup = rtemp2;
    }
    void rotate90l()
    {
        auto temp = right;
        auto temp2 = left;
        auto temp3 = up;
        auto temp4 = down;
        right = temp4;
        left = temp3;
        down = temp2;
        up = temp;
        auto rtemp = rright;
        auto rtemp2 = rleft;
        auto rtemp3 = rup;
        auto rtemp4 = rdown;
        rright = rtemp4;
        rleft = rtemp3;
        rdown = rtemp2;
        rup = rtemp;
    }
};
vector<tile> tiles;

int to_Bi(char c, size_t i)
{
    int val = 0;
    switch (c)
    {
    case '.':
        val += 0;
        break;
    case '#':
        val += pow(2, i);
        break;
    default:
        break;
    }
    return val;
}

void myfunc(int id, int index)
{

    tile t;
    t.id = id;
    string leftSum = "";
    string rightSum = "";
    string upSum = "";
    string downSum = "";
    string rleftSum = "";
    string rrightSum = "";
    string rupSum = "";
    string rdownSum = "";
    // for (auto &&i : line[index])
    // {
    //     cout << i << endl;
    // }
    // cout << endl;
    rrightSum.resize(10);
    rleftSum.resize(10);
    rdownSum.resize(10);
    rupSum.resize(10);
    for (size_t i = 0; i < line[index].size(); i++)
    {
        downSum     += line[index][9][i];
        upSum       += line[index][0][i];
        leftSum     += line[index][i][0];
        rightSum    += line[index][i][9];
    }
    
    t.down = downSum;
    t.up = upSum;
    t.right = rightSum;
    t.left = leftSum;
    
    reverse_copy(downSum.begin(), downSum.end(), rdownSum.begin());
    reverse_copy(upSum.begin(), upSum.end(), rupSum.begin());
    reverse_copy(rightSum.begin(), rightSum.end(), rrightSum.begin());
    reverse_copy(leftSum.begin(), leftSum.end(), rleftSum.begin());

    // cout << rightSum << endl
    //      << rrightSum << endl;
    t.rdown = rdownSum;
    t.rup = rupSum;
    t.rright = rrightSum;
    t.rleft = rleftSum;

    // int total = 0;
    // for (size_t i = 0; i < 9; i++)
    // {
    //     total+=to_Bi(line[index][9][i],i);
    //     total+=to_Bi(line[index][0][i],i);
    //     total+=to_Bi(line[index][i][0],i);
    //     total+=to_Bi(line[index][i][9],i);
        
    // }
    // 
    // cout << total << endl;
    // cout << line[index][0] << " line top    \t" << upSum << endl;
    // for (size_t i = 0; i < line[index].size(); i++)
    // {
    //     cout << line[index][i][0] << "\t\t ";
    //     cout << line[index][i][9] << endl;
    // }
    // cout << line[index][9] << " line bottom \t" << downSum << endl;
    // cout << "left column \t" << leftSum << endl;
    // cout << "right column\t" << rightSum << endl;

    tiles.push_back(t);
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
        if (l.empty())
        {
            line.push_back(lines);
            lines.clear();
        }
        else if (l.find("Tile") != string::npos)
        {
            lines.clear();
            ids.push_back(stoi(l.substr(l.find("Tile") + 5, 4), nullptr));
            // cout << endl;
        }
        else
        {

            lines.push_back(l);
            // cout << l << endl;
        }
    }
    for (size_t i = 0; i < line.size(); i++)
    {
        myfunc(ids[i], i);
    }

cout << line.size();
for (size_t i = 0; i < 10; i++)
{
    /* code */

    for (size_t n = 0; n < tiles.size(); n++)
    {
        if (tiles[i].left == tiles[n].rdown)
        {
            cout << "left rdown";
        cout << endl;
        }
        else if (tiles[i].left == tiles[n].up) {
            cout << "left upp";
        cout << endl;

            tiles[n].rotate90l();
            tiles[i].down   += " "+tiles[n].down;
            tiles[i].up     += " "+tiles[n].up;
            tiles[i].right  = tiles[n].right;
            tiles[i].rdown  += " "+tiles[n].rdown;
            tiles[i].rup    += " "+tiles[n].rup;
            tiles[i].rleft  += " "+tiles[n].rleft;
            tiles[i].rright = tiles[n].rright;
            tiles.erase(tiles.begin()+n);
        }
        else if (tiles[i].left == tiles[n].right) {
            
            cout << "left right";
        cout << endl;
        }
        else if (tiles[i].left == tiles[n].down) {
            
            cout << "left down";
            tiles[n].rotate90r();
            tiles[i].down   += " "+tiles[n].down;
            tiles[i].up     += " "+tiles[n].up;
            tiles[i].left   += " "+tiles[n].left;
            tiles[i].right  += " "+tiles[n].right;
            tiles[i].rdown  += " "+tiles[n].rdown;
            tiles[i].rup    += " "+tiles[n].rup;
            tiles[i].rleft  += " "+tiles[n].rleft;
            tiles[i].rright += " "+tiles[n].rright;
            tiles.erase(tiles.begin()+n);
        cout << endl;
        } else {
        }
    }
}
    for (auto &&i : line)
    {
        for (auto &&a : i)
        {
            cout << a << endl;
        }
        cout << endl;
    }
    

    for (auto &&i : tiles)
    {
        cout << i.up << "\t\t";
        // cout << i.rup << endl;
        cout << endl;
        for (size_t a = 0; a < 9; a++)
        {
            cout << i.left[a] << "\t\t "; 
            cout << i.right[a] << "\t\t ";
            // cout << i.rleft[a] << "\t\t ";
            // cout << i.rright[a] << endl;
            cout << endl;
        }
        cout << i.down << "\t\t ";;
        // cout << i.rdown << endl << endl;
        cout << endl << endl;
        
    }
    
}