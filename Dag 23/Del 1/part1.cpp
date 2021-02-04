#include <bits/stdc++.h>
using namespace std;

// std::string Path = "..//input.txt";
std::string Path = "..//example.txt"; // andra fil vägen
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

void print_c(vector<int> list, int current_cup)
{
    for (auto &&q : list)
    {
        (q == list[current_cup]) ? printf("(%d) ", q) : printf("%d ", q);
    }
    cout << endl;
}
void print_c(vector<int> list, string prefix = "")
{
    if (!prefix.empty())
    {
        printf("%s\n", prefix);
    }
    for (auto &&q : list)
    {
        printf("%d ", q);
    }
    cout << endl;
}
int find_dest(int in)
{
    int b = 0;
    if (in == circle.size()) {
        cout << "bigger\n"; 
        in--;
    }
    for (int i = 0; i < circle.size(); i++)
    {
        if (i == in)
        {
            b = circle.at(mod(in,circle.size()));
            break;
        }
    }

    cout << b << endl;

    for (int i = 0; i < circle.size(); i++)
    {
        if (b - 1 == circle[i])
        {
            cout << "fast dest: " << circle[i] << endl;
            return i;
        }
    }

    for (int c = 1; c < circle.size(); c++)
    {
        /* code */

        for (int i = 0; i < circle.size(); i++)
        {
            /* code */

            /* code */
            int cup = mod(b - c, 10);
            printf("%d | mod %d - %d , 10  | %d \t %d \n", i, b, c, cup, circle.at(i));
            if (circle.at(i) == cup)
            {
                cout << "dest: " << circle.at(i) << endl;

                return i;
            }
            else
            {
            }
        }
    }
}

void erase(int current_cup)
{
    
    holding.push_back(circle.at(mod(current_cup + 1, circle.size())));
    holding.push_back(circle.at(mod(current_cup + 2, circle.size())));
    holding.push_back(circle.at(mod(current_cup + 3, circle.size())));

    circle.erase(circle.begin() + (mod(current_cup + 1, circle.size())));
    circle.erase(circle.begin() + (mod(current_cup + 1, circle.size())));
    circle.erase(circle.begin() + (mod(current_cup + 1, circle.size())));
    cout << "holding: " << endl;
    print_c(holding);
    cout << "new hand: " << endl;
    print_c(circle, current_cup);
    cout << endl;
}

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
    int c;
    cout << "starting" << endl;
    for (auto &&i : l)
    {
        cout << i << " ";
        circle.push_back(to_int(i));
    }
    cout << endl;
    int current_cup = -1;
    /** 
     * *MAIN loop
    */
    for (int i = 0; i < 4; i++)
    {
        if (circle.size() > 9)
        {
            printf("failiure size > 9");
            return 1;
        }
        current_cup = mod(current_cup + 1, circle.size());
        printf("------------------------\nIndex: %d \nCurrent Cup: %d\n", i, current_cup);
        int a = current_cup-1;
        
        cout << "current hand: ";
        print_c(circle, current_cup);
        erase(current_cup);
        int destination; 
        
            destination = find_dest(current_cup);
        printf("[%d] to i: %d\n",current_cup,destination);
        
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
        print_c(circle,current_cup);

        cout << endl;
    }
}