#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

std::string l;
std::string Path = "..//input.txt";
// std::string Path = "..//example.txt"; // andra fil vägen

vector<int> player1;
vector<int> player2;

vector<int> subplayer1;
vector<int> subplayer2;

map<vector<int>,int> mem1;
map<vector<int>,int> mem2;

int gameC = 1;
int svaret(vector<int> v);
int subgame(vector<int> *sp1, vector<int> *sp2);
void check(vector<int> *p1, vector<int> *p2, int result);
int parse();

void printDeck(string name, vector<int> deck)
{
    printf("\n%s: ", name.c_str());
    for (auto &&i : deck)
    {
        cout << i << " ";
    }
}

void addsub(vector<int> p, vector<int> *sp)
{
    sp->clear();
    for (size_t i = 0; i != p.at(0); i++)
    {
        sp->push_back(p.at(i + 1));
    }
}

int main()
{

    parse();
    size_t i = 1;
    while(player1.size() != 0 && player2.size() != 0)
    {
        printf("\nRound %d (game %d)", i, 1);
        printDeck("player 1", player1);
        printDeck("player 2", player2);
        if ((player1.at(0) <= player1.size() - 1) && (player2.at(0) <= player2.size() - 1))
        {
            addsub(player1, &subplayer1);
            printDeck("sub player 1",subplayer1);
            addsub(player2, &subplayer2);
            printDeck("sub player 2",subplayer2);

            int subRes = subgame(&subplayer1, &subplayer2);
            if (subRes == 0 || subRes == 4) {
                break;
            }
            check(&player1, &player2, subRes);
            
        }
        else if (player1.at(0) > player2.at(0))
        {
            printf("\nplayer1 wins round %d", i);
            check(&player1, &player2, 1);
        }
        else if (player1.at(0) < player2.at(0))
        {
            printf("\nplayer2 wins round %d", i);
            check(&player1, &player2, 2);
        }
        i++;
    }
        cout << "\n";
    svaret(player1);
    svaret(player2);
}

int svaret(vector<int> v)
{
    int sum = 0;
    int temp = v.size();
    cout << endl;
    for (auto &&i : v)
    {
        cout << i << "\t *\t" << temp << "\t= " << i*temp << endl;
        sum += i * temp;
        temp--;
    }
    cout << "total sum:\t" << sum << endl;
}

int subgame(vector<int> *sp1, vector<int> *sp2)
{
    int counter = 1;
    gameC++;
    while (sp1->size() != 0 && sp2->size() != 0)
    {
        auto a = mem1.find(*sp1);auto b = mem2.find(*sp2);
        if (a != mem1.end() && b != mem2.end())
        {
            for (auto &&c : a->first)
            {
                cout << c << " ";
            }
            cout << endl;
            for (auto &&c : b->first)
            {
                cout << c << " ";
            }
            
            return 1;
        }
        else 
        {
            mem1[subplayer1] = 1;
            mem2[subplayer2] = 1;
        }
        printf("\n\n\tRound %d (game %d)", counter, gameC);
        printDeck("\t(sub) player 1", subplayer1);
        printDeck("\t(sub) player 2", subplayer2);
        if (sp1->at(0) > sp2->at(0))
        {
            check(sp1, sp2, 1);
            printf("\n\tplayer 2 wins Round %d of game %d", counter, gameC);
        }
        else if (sp1->at(0) < sp2->at(0))
        {
            check(sp1, sp2, 2);
            printf("\n\tplayer 2 wins Round %d of game %d\n", counter, gameC);
        }
        counter++;
    }
    mem1.clear();
    mem2.clear();

    if (sp1->size() == 0)
    {
        cout << "player 2 wins subgame " << gameC << endl;
        return 2;
    }
    else if (sp2->size() == 0)
    {
        cout << "player 1 wins subgame " << gameC << endl;
        return 1;
    }
        cout << "game nr: " << gameC << endl;
        return 0;
}

int parse()
{
    std::ifstream input;
    input.open(Path);
    if (!input.is_open())
    {
        std::cout << "not found or could not open\n";
        return 1;
    }
    int ecount = 0;
    while (getline(input, l))
    {
        if (l.empty())
        {
            ecount = 1;
            cout << endl;
        }
        else
        {
            cout << endl
                 << l;
            int num = stoi(l, nullptr, 10);
            if (ecount == 0)
            {
                player1.push_back(num);
            }
            else
            {
                player2.push_back(num);
            }
        }
    }
}
void check(vector<int> *p1, vector<int> *p2, int result)
{
    switch (result)
    {
    case 1:
        p1->push_back(p1->at(0));
        p1->push_back(p2->at(0));
        p1->erase(p1->begin());
        p2->erase(p2->begin());
        break;
    case 2:
        p2->push_back(p2->at(0));
        p2->push_back(p1->at(0));
        p1->erase(p1->begin());
        p2->erase(p2->begin());
        break;
    default:
        cout << "\nError\n\n";
        break;
    }
    
}
