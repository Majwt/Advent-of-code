#include <bits/stdc++.h>
using namespace std;

// std::string Path = "..//input.txt";
std::string Path = "..//example.txt"; // andra fil vägen
// std::string Path = "..//example copy.txt"; // andra fil vägen

vector<vector<vector<char>>> plane;
vector<vector<vector<char>>> Pcopy;
vector<char> temp;
vector<vector<char>> temp2d;

int neighbors3d(int z, int y, int x)
{
    int counter = 0;
    size_t test = 0;
    for (int i = -1; i < 2; i++)
    {

        bool zi_size = (Pcopy.size() <= z + i);
        bool zi_0 = (z + i < 0);
        for (int j = -1; j < 2; j++)
        {
            bool yj_size = (Pcopy.at(z).size() <= y + j);
            bool yj_0 = (y + j < 0);

            for (int k = -1; k < 2; k++)
            {

                bool xk_size = (Pcopy.at(z).at(y).size() <= x + k);
                bool xk_0 = (x + k < 0);
                if ((yj_size) || (xk_size) || (zi_size) || (yj_0) || (xk_0) || (zi_0))
                {
                    // printf("bounds error\n");
                    // printf("z = %d i = %d\tx = %d j = %z\tz = %d k = %d\tsize = %i\n", z, i, y, j,x,k, Pcopy.size());
                }
                else if (Pcopy.at(i + z).at(j + y).at(x + k) == '#')
                {
                    if (!(i == 0 && j == 0 && k == 0)) {
                        
                    printf("z=%d y=%d x=%d active neighbor at z=%d y=%d x=%d\n",z,y,x,z+i,y+j,x+k);
                    
                        // printf("  z: %d(%d,%d)\n",z+i,x+k,y+j);
                        counter++;
                    }
                }
                test++;
            }
        }
    }
    if (counter > 0)
    {
        // printf("%d z: %d (%d,%d)\n",counter,z,x,y);
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
        temp2d.push_back(temp);
    }
    for (size_t i = 0; i < (overflow * 2) + linesize; i++)
    {
        plane.push_back(temp2d);
    }

    return overflow;
}

void change()
{
    for (int i = 0; i < Pcopy.size(); i++)
    {
        for (int j = 0; j < Pcopy.at(i).size(); j++)
        {
            for (int k = 0; k < Pcopy.at(i).at(j).size(); k++)
            {

                int counter = neighbors3d(i, j, k);
                if (Pcopy.at(i).at(j).at(k) == '.')
                {
                    if (counter == 3)
                    {
                        cout << "change to #\n";
                        plane.at(i).at(j).at(k) = '#';
                        cout << endl;
                    }
                }
                else if (counter != 2 && counter != 3)
                {
                    cout << "change to .\n";
                    plane.at(i).at(j).at(k) = '.';
                    cout << endl;
                }
                if (counter > 0)
                    cout << endl;
            }
        }
    }
}
void print_layer(vector<vector<char>> p, int y)
{
    cout << "z = " << y << "\n\t";
    for (size_t i = 0; i < p.size(); i++)
    {
        cout << i << "\t";
    }
    cout << endl;
    for (size_t i = 0; i < p.size(); i++)
    {
        cout << i << "\t";
        for (size_t j = 0; j < p[i].size(); j++)
        {
            cout << p[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    
}
void printPlane(vector<vector<vector<char>>> plane)
{
    for (size_t i = 0; i < plane.size(); i++)
    {
    first:
        for (size_t j = 0; j < plane.at(i).size(); j++)
        {
            for (size_t k = 0; k < plane.at(i).at(j).size(); k++)
            {
                if (plane[i][j][k] == '#')
                {
                    // print_layer(plane[i - 1]);
                    print_layer(plane[i], i);
                    // print_layer(plane[i + 1]);
                    i++;
                    goto first;
                }
            }
        }
    }
}
int countActive(vector<vector<vector<char>>> plane)
{
    int counter = 0;
    // int layer = 0;
    for (auto &&i : plane)
    {
        // cout << "\nz = " << layer << endl;
        for (auto &&j : i)
        {
            for (auto &&q : j)
            {
                if (q == '#')
                    counter++;
                // cout << q << " ";
            }
            // cout << endl;
        }
        // layer++;
    }
    // cout << end;
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
    // int overflow = initPlane(8, 7);
    int overflow = initPlane(3, 7);

    int h = 0;
    while (getline(input, l))
    {
        std::cout << l << endl;
        for (size_t i = 0; i < l.size(); i++)
        {
            plane[overflow][overflow + h][overflow + i] = l[i];
        }

        h++;
    }
    Pcopy = plane;

    // Loop
    // printPlane(plane, ' ', "\n\n");
    // cout << plane[7][9][8] << endl;
    // print_layer(plane[7]);
    for (size_t i = 0; i < 6; i++)
    {
        // Print
        printPlane(plane);
        change();
        Pcopy = plane;
        printPlane(plane);
        cout << endl;
    }
    cout << countActive(plane);
}