#include <bits/stdc++.h>
using namespace std;

// std::string Path = "..//input.txt";
std::string Path = "..//example.txt"; // andra fil vägen
// std::string Path = "..//example copy.txt"; // andra fil vägen

vector<vector<char>> plane;
vector<vector<char>> Pcopy;
vector<char> temp;

int neighbors2d(int y, int x)
{
    int counter = 0;
    for (int i = -1; i < 2; i++)
    {

        for (int j = -1; j < 2; j++)
        {
            if (j == 0 && i == 0)
            {
                continue;
            }
            else if ((Pcopy.size() <= y + i) ||
                     (Pcopy.at(y).size() <= x + j) ||
                     (y + i < 0) ||
                     (x + j < 0))
            {

                printf("y = %d i = %d\tx = %d j = %d\tsize = %i\n", y, i, x, j, Pcopy.size());
            }
            else if (Pcopy.at(i + y).at(j + x) == '#')
            {
                printf("counted\n");
                counter++;
            }
        }
    }
    return counter;
}

int initPlane(int linesize, int overflow = 7)
{
    for (size_t i = 0; i < (overflow * 2) + linesize; i++)
    {
        temp.push_back('.');
    }
    for (size_t i = 0; i < (overflow * 2) + linesize; i++)
    {
        plane.push_back(temp);
    }
    return overflow;
}

void change()
{
    for (size_t i = 0; i < Pcopy.size(); i++)
    {
        for (size_t j = 0; j < Pcopy.at(i).size(); j++)
        {

            int counter = neighbors2d(i, j);

            if (Pcopy.at(i).at(j) == '.')
            {
                if (counter == 3)
                {
                    cout << "change to #\n";
                    plane.at(i).at(j) = '#';
                }
            }
            else if (counter != 2 && counter != 3)
            {
                cout << "change to .\n";
                plane.at(i).at(j) = '.';
            }
        }
    }
}
int printPlane(vector<vector<char>> plane, string spacer = "\t", string end = "\n")
{
    int counter = 0;
    for (auto &&i : plane)
    {
        for (auto &&q : i)
        {
            if (q == '#')
                counter++;
            cout << q << spacer;
        }
        cout << endl;
    }
    cout << end;
    return counter;
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
    int overflow = initPlane(3, 7);

    int h = 0;
    while (getline(input, l))
    {
        std::cout << l << endl;
        for (size_t i = 0; i < l.size(); i++)
        {
            plane[overflow + h][overflow + i] = l[i];
        }

        h++;
    }
    Pcopy = plane;

    // Loop
    printPlane(plane, "\t", "\n\n");
    for (size_t i = 0; i < 1; i++)
    {
        // Print
        change();
        cout << printPlane(plane);
        Pcopy = plane;
        cout << endl;
    }
}