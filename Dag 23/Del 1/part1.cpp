#include <bits/stdc++.h>
using namespace std;

std::string Path = "..//input.txt";
// std::string Path = "..//example.txt"; // andra fil vägen
vector<char> temp;
vector<int> circle;
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

int find_fdest(int b, int ln)
{
    for (int i = 0; i < circle.size(); i++)
    {
        if (b - 1 == circle[i])
        {
            cout << "fast dest: " << circle[i] << endl;
            return i;
        }
    }
    return 0;
}
bool find_fdest(int b, int ln,int destinguisher)
{
    for (int i = 0; i < circle.size(); i++)
    {
        if (b - 1 == circle[i])
        {
            return true;
        }
    }
    return false;
}
int find_dest(int in)
{
    int b = 0;
    if (in == circle.size())
    {
        cout << "bigger\n";
        in--;
    }
    for (int i = 0; i < circle.size(); i++)
    {
        if (i == in)
        {
            b = circle.at(mod(in, circle.size()));
            break;
        }
    }

    cout << b << endl;
    if (find_fdest(b, in,0))
    {
        return find_fdest(b, in);
    }

    for (int c = 1; c < circle.size(); c++)
    {

        for (int i = 0; i < circle.size(); i++)
        {
            cout << ".";
            if (circle.at(i) == mod(b - c, 10))
            {
                printf("\nDestination: %d\n", circle.at(i));
                return i;
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

    for (auto &&i : holding)
    {
        for (int v = 0; v < circle.size(); v++)
        {
            if (i == circle[v])
            {
                circle.erase(circle.begin() + v);
                continue;
            }
        }
    }
    current_cup -= offset;
    cout << "picked up: ";
    print_c(holding);
    return offset;
}
int mainLoop(int runs);

void get_results();


int main()
{

    std::string l;
    std::ifstream input{Path};
    if (!input)
    {
        std::cout << "not found or could not open\n";
        return 1;
    }

    getline(input, l);
    int runs = stoi(l, nullptr);
    getline(input, l);
    int c;
    cout << "starting" << endl;
    for (auto &&i : l)
    {
        cout << i << " ";
        circle.push_back(to_int(i));
    }
    cout << endl;
    /** 
     * *MAIN loop
    */
    mainLoop(runs);
    
    get_results();
}

int mainLoop(int runs) {
    int current_cup = -1;
    for (int i = 0; i < runs; i++)
    {
        if (circle.size() > 9)
        {
            printf("failiure size > 9");
            return 1;
        }
        current_cup = mod(current_cup + 1, circle.size());
        printf("--- Move: %d --- \nCurrent Cup: %d\n", i + 1, current_cup);
        int a = current_cup - 1;

        cout << "current hand: ";
        print_c(circle, current_cup);
        current_cup -= erase(current_cup);
        int destination;

        destination = find_dest(current_cup);
        printf("[%d] to i: %d\n", current_cup, destination);

        int nextcup = circle[mod(current_cup, circle.size())];
        cout << nextcup << endl;
        circle.insert(circle.begin() + destination + 1, holding.begin(), holding.end());
        holding.clear();
        for (int n = 0; n < circle.size(); n++)
        {
            if (circle[n] == nextcup)
            {
                current_cup = n;
            }
        }
        print_c(circle, current_cup);

        cout << endl;
    }
    return 0;
}

void get_results()
{
    cout << "---Final---\n" << endl;
    print_c(circle);
    int ones;
    for (size_t i = 0; i < circle.size(); i++)
    {
        if (circle.at(i) == 1)
        {
            ones = i;
        }
    }
    cout << "---Output---\n";
    for (size_t i = 1; i != circle.size(); i++)
    {
        cout << circle[mod(i + ones, circle.size())];
    }
}