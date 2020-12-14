#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>

using namespace std;

std::string l;
std::string Path = "..//input.txt";
//std::string Path = "..//example.txt"; // andra fil vägen

vector<char> dirl;
vector<int> vall;

int iNorth, iSouth, iWest, iEast;
char Forwart = 'F';
char North = 'N';
char East = 'E';
char West = 'W';
char South = 'S';
char Right = 'R';
char Left = 'L';

int dir = 90;
    int absUpDown,absRightLeft;

void myFunction()
{
    for (size_t i = 0; i < vall.size(); i++)
    {
        if (dirl[i] == Forwart)
        {
            switch (dir)
            {
            case 270:
                iWest += vall[i];
                break;
            case 90:
                iEast += vall[i];
                break;
            case 180:
                iSouth += vall[i];
                break;
            case 0:
                iNorth += vall[i];
                break;

            default:
                break;
            }
        }
        else if (dirl[i] == North)
        {
            iNorth += vall[i];
            continue;
        }
        else if (dirl[i] == South)
        {
            iSouth += vall[i];
            continue;
        }
        else if (dirl[i] == West)
        {
            iWest += vall[i];
            continue;
        }
        else if (dirl[i] == East)
        {
            iEast += vall[i];
            continue;
        }
        else if (dirl[i] == Left) 
        {
            cout << dir << endl;
            if (dir - vall[i] < -1) {
            cout << ((dir - vall[i]) % 360)+360 << endl;

            dir = ((dir - vall[i]) % 360) + 360;
            } 
            else 
            {
            cout << ((dir - vall[i]) % 360) << endl;
            dir = (dir - vall[i]) % 360;

            }
            cout << endl;
            continue;
        
        }
        else if (dirl[i] == Right) 
        {
            cout << dir << endl;
            cout << (vall[i]+dir) % 360 << endl;
            dir = (vall[i]+dir) % 360;
            cout << endl;
            continue;
        }
        
    }

    absUpDown = abs(iNorth - iSouth);
    absRightLeft = abs(iEast - iWest);

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
        string v = l.substr(1);
        int value = stoi(v, nullptr, 10);
        vall.push_back(value);
        dirl.push_back(l.at(0));
    }
    

    myFunction();
    cout << '\t' << iNorth << endl;
    cout << iWest << '\t' << '\t' << iEast << endl; 
    cout << '\t' << iSouth << endl;
    
    cout << absUpDown << " + "<< absRightLeft << " = " << absUpDown+absRightLeft << endl;
}