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
struct Way
{
    int x;
    int y;
    int dir;
};
struct boat
{
    int x;
    int y;
};

char Fr = 'F';
char Nr = 'N';
char Ea = 'E';
char We = 'W';
char So = 'S';
char Right = 'R';
char Left = 'L';

int dir = 90;
int absUpDown, absRightLeft;

void myFunction()
{
    boat ship;
    Way Waypoint;
    ship.x = 0;
    ship.y = 0;
    Waypoint.x = 10;
    Waypoint.y = 1;
    Waypoint.dir = 90;
    for (size_t i = 0; i < vall.size(); i++)
    {
        
        if (dirl[i] == Fr)
        {
            ship.x += (Waypoint.x) * vall[i];
            ship.y += (Waypoint.y) * vall[i];

            
        }
        else if (dirl[i] == Nr)
        {
            Waypoint.y += vall[i];

            
        }
        else if (dirl[i] == So)
        {
            Waypoint.y -= vall[i];

            
        }
        else if (dirl[i] == We)
        {
            Waypoint.x -= vall[i];

            
        }
        else if (dirl[i] == Ea)
        {
            Waypoint.x += vall[i];

            
        }
        else if (dirl[i] == Left)
        {
            int lastx = Waypoint.x;
            int lasty = Waypoint.y;

            if (vall[i] == 90)
            {
                Waypoint.x = -1*lasty;
                Waypoint.y = lastx;

                
            }
            if (vall[i] == 180)
            {
                Waypoint.x = -1*lastx;
                Waypoint.y = -1*lasty;

                
            }
            if (vall[i] == 270)
            {
                Waypoint.x = lasty;
                Waypoint.y = -1*lastx;

                
            }
        }
        else if (dirl[i] == Right)
        {

            int lastx = Waypoint.x;
            int lasty = Waypoint.y;

            if (vall[i] == 90)
            {
                Waypoint.x = lasty;
                Waypoint.y = -1*lastx;

                
            }
            if (vall[i] == 180)
            {
                Waypoint.x = -1*lastx;
                Waypoint.y = -1*lasty;

                
            }
            if (vall[i] == 270)
            {
                Waypoint.x = -1*lasty;
                Waypoint.y = lastx;

                
            }
        }
        std::cout << endl;
        std::cout <<"instruction nr" << i+1 <<": " <<  dirl[i] << vall[i] << "\t||\t at: ";
        std::cout << ship.x << '\t' << ship.y;
        std::cout <<"\t Pointing: \t" << Waypoint.x << '\t' << Waypoint.y << endl;
    }

    absUpDown = abs(ship.x);
    absRightLeft = abs(ship.y);
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
    std::cout << absUpDown << " + " << absRightLeft << " = " << absUpDown + absRightLeft << endl;
}