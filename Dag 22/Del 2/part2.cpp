#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <cstring>
using namespace std;

std::string l;
std::string Path = "..//input.txt";
// std::string Path = "..//example.txt"; // andra fil vägen

vector<int> player1;
vector<int> player2;
int compare();
int svaret(vector<int> v);
int main()
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
            cout << endl << "empty";
        }
        else
        {
            cout << endl << l;
            int num = stoi(l,nullptr,10);
        if (ecount == 0)
        {
            player1.push_back(num);
        } else if(ecount == 1) {
            player2.push_back(num);

        }
        
        }
    }

    cout << endl << "player 1 V" << endl;

    for (auto &&n : player1)
    {
        cout << n << endl;
    }
    cout << "player 2 V" << endl;
    for (auto &&i : player2)
    {
        cout << i << endl;
        
    }
    int counter = 1;
    while((player1.size() != 0) && (player2.size() != 0)) {
        cout << endl << "Game " << counter << endl;
        counter++;
        compare();
        cout << player1.size() << endl << player2.size() << endl;
    }

    if (player1.size() > player2.size())
    {
        cout << "player1 wins the game with the ";
        svaret(player1);
    }
    else if (player2.size() > player1.size())
    {
        cout << "player2 wins the game with the ";
        svaret(player2);
    }
    
    
}

int svaret(vector<int> v) {
    int sum = 0;
    int temp = v.size();
    // cout << endl;
    for (auto &&i : v)
    {
        // cout << i << "\t *\t" << temp << "\t= " << i*temp << endl;
        sum += i*temp;
        temp--;
    }
    cout << "total sum:\t" << sum; 
    
}

int compare() {
    cout << "player 1: ";

    for (auto &&n : player1)
    {
        cout << n << " ";
    }
    cout <<endl << "player 2: ";
    for (auto &&i : player2)
    {
        cout << i << " ";
        
    }
    int p1s = player1[0];
    cout << endl << endl << "player 1:\t" << p1s << endl;
    int p2s = player2[0];
    cout << "player 2:\t" << p2s << endl;
    cout << "comparing..." << endl;
    if (p1s > p2s)
    {
        cout << "player 1 Wins with:\t" << p1s << endl;
        player1.erase(player1.begin());
        player2.erase(player2.begin());
        player1.push_back(p1s);
        player1.push_back(p2s);
    } else if (p2s > p1s)
    {
        cout << "player 2 Wins with:\t" << p2s << endl;
        player1.erase(player1.begin());
        player2.erase(player2.begin());
        player2.push_back(p2s);
        player2.push_back(p1s);
    } else
    {
        cout << "error" << endl;
        return 1;
    }
    
    cout << endl;
    
}