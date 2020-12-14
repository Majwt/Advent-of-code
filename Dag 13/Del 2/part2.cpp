#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>
using namespace std;
int departtime = 1000052;
std::string l;
std::string Path = "..//input2.txt";
std::vector<int> lines;
std::vector<int> integers;
std::vector<string> all;
// std::string Path = "..//example.txt"; // andra fil vägen
int arr[] = {
    0,
    17,
    23,
    35,
    36,
    40,
    52,
    54,
    95};
int arr2[] = {
    17,
    6,
    13,
    1,
    4,
    11,
    1,
    41};
int t = 96;
int findMult(int a, int b, int aneg)
{
    for (size_t i = 10000000000000; i < 10000000000000000; i++)
    {

        if ((b * i) + aneg == a)
        {
            return i;

            //cout << "something: " << b << " * " << n <<" = (" << a<<" * " << i << ") + " << aneg<< endl;
        }
        else
        {
            continue;
        }
    }
}

void myFunction()
{
    long long neg = 32;
    int a = 863;
    int b = 571;
    int c = 19;

    for (size_t i = 120000000; i < 130000000; i++)
    {
        long long ai = a * i;
        for (size_t n = 180000000; n < 182000000; n += 1)
        {
            long long bn = b * n;
            if (bn < 1000000000)
            {
                continue;
            }
            else
            {
                if (ai == bn - neg)
                {
                    integers.push_back(n);
                    cout << "found: " << a << " * " << i << " = (" << b << " * " << n << ") - " << neg << " = " << bn << endl;
                    continue;
                }
            }
        }
    }
    cout << "nothing" << endl;
}

size_t loop(size_t t, size_t p, size_t m, size_t k)
{
    while ((t + p) % m != 0)
    {
        cout << t << endl;
        t += k;
    }
    return t;
}

void annat()
{
    int t = 0;
    int k = 7;
    t = loop(t, 1, 13, k);
    k *= 13;
    t = loop(t, 4, 59, k);
    k *= 59;
    t = loop(t, 6, 31, k);
    k *= 31;
    t = loop(t, 7, 19, k);

    cout << t << endl;
}

/*


t % 7 == 0
t % 13 == 11









152683
82214
18115
34477
56252

17,
5,
12,
3,
11,
1,
40



(i% lines[0] == 0) &&
((i+17)%lines[1] == 0) && 
((i+23)%lines[2] == 0) &&
((i+35)%lines[3] == 0) &&
((i+36)%lines[4] == 0) &&
((i+40)%lines[5] == 0) &&
((i+52)%lines[6] == 0) &&
((i+54)%lines[7] == 0) &&
((i+95)%lines[8] == 0)
*/
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
        all.push_back(l);
        if (l.at(0) == 'x')
        {
            lines.push_back(-1);
        }
        else
        {

            lines.push_back(stoi(l, nullptr, 10));
        }
    }
    cout << all.size() << endl;

        size_t t = 0;
        size_t k = lines[0];
    for (size_t i = 1; i < lines.size(); i++)
    {
        if (lines[i] < 0)
        {
            continue;
        }
        
        t = loop(t, i, lines[i], k);
        k *= lines[i];
       
        //std::cout << lines[i] << '\n';
    }
        cout << t << endl;
    cout << endl;
    //annat();
    // myFunction();
}