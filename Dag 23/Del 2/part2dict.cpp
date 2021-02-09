#include <bits/stdc++.h>
using namespace std;

// std::string Path = "..//input.txt";
std::string Path = "..//example.txt"; // andra fil vägen
vector<char> temp;
unordered_map<int,int> circle;
vector<int> holding;
int to_int(char i)
{
    string s;
    s += i;
    return stoi(s, nullptr);
}
int mod(int a, int b)
{
    int c = a % b;
    return (c < 0) ? c + b : c;
}

void print_c(vector<int> list, int current_cup = 100)
{
    if (current_cup < circle.size())
    {
        for (auto &&q : list)
        {
            (q == list[current_cup]) ? printf("(%d) ", q) : printf("%d ", q);
        }
    }
    else
    {
        for (auto &&q : list)
        {
            printf("%d ", q);
        }
    }
    cout << endl;
}

int find_dest(int in)
{
    int b = 0;
    if (in == circle.size())
    {
        cout << "bigger\n";
        in--;
    }

    b = circle[mod(in, circle.size())];

    // cout << b << endl;

    for (int c = 1; c < circle.size(); c++)
    {

        for (int i = in + 1; mod(i, circle.size()) != in; i++)
        {
            // cout << i << " " <<  mod(i,circle.size()) << " " << in << endl;
            if (circle.at(mod(i, circle.size())) == mod(b - c, 10))
            {
                // printf("\nDestination: %d\n", circle.at(mod(i, circle.size())));
                return mod(i, circle.size());
            }
        }
    }
    return 1;
}

int erase(int current_cup)
{
    int offset = 0;
    if (mod(current_cup + 1, circle.size()) < current_cup)
    {
        offset++;
    }
    if (mod(current_cup + 2, circle.size()) < current_cup)
    {
        offset++;
    }
    if (mod(current_cup + 3, circle.size()) < current_cup)
    {
        offset++;
    }
    holding.push_back(circle.at(mod(current_cup + 1, circle.size())));
    holding.push_back(circle.at(mod(current_cup + 2, circle.size())));
    holding.push_back(circle.at(mod(current_cup + 3, circle.size())));
    
    int a = 0;
    for (auto &&i : holding)
    {
        circle.erase(find(circle.begin(), circle.end(), i));
    }
    current_cup -= offset;
    // cout << "picked up: ";
    // print_c(holding);
    return offset;
}
int mainLoop(int runs);

void get_results();

int main()
{
    int mill = 1000000;
    int runs = mill * 10;
    std::string l;
    std::ifstream input{Path};
    if (!input)
    {
        std::cout << "not found or could not open\n";
        return 1;
    }

    getline(input, l);
    int c;
    cout << "starting" << endl;
    for (auto &&i : l)
    {
        cout << i << " ";
        circle[to_int(i)] = 0;
    }
    for (size_t i = 10; i < mill; i++)
    {
        circle[i] = 0;
    }

    cout << endl;
    /** 
     * *MAIN loop
    */
    mainLoop(runs);

    get_results();
}

int mainLoop(int runs)
{
    int current_cup = -1;
    for (int i = 0; i < runs; i++)
    {

        current_cup = mod(current_cup + 1, circle.size());
        int a = i;
        // printf("--- Move: %d --- \nCurrent Cup: %d\n", i + 1, current_cup);

        // cout << "current hand: ";
        // print_c(circle, current_cup);
        current_cup -= erase(current_cup);
        int destination;
        // print_c(circle,current_cup);
        destination = find_dest(current_cup);
        // printf("[%d] to i: %d\n", current_cup, destination);

        int nextcup = mod(current_cup, circle.size());
        // cout << nextcup << endl;
        circle.insert(circle.begin() + destination + 1, holding.begin(), holding.end());
        holding.clear();

        if (nextcup > destination)
        {
            current_cup += 3;
        }

        // cout << endl;
    }
    return 0;
}

void get_results()
{
    cout << "---Final---" << endl;
    // print_c(circle);
    int ones;
    for (size_t i = 0; i < circle.size(); i++)
    {
        if (circle.at(i) == 1)
        {
            ones = i;
            cout << i << endl;
        }
    }
    print_c(circle);

    int first = circle[ones + 1];
    int second = circle[ones + 2];
    long long resu = (long long)first * (long long)second;
    printf("---Output---\n%d * %d = %lld", first, second, resu);
}