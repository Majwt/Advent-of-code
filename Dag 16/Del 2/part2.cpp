#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <sstream>
using namespace std;

std::string l;
std::string PathC = "..//condition.txt";
std::string Path = "..//input.txt";
         std::string PathF = "..//Fullinput.txt";
         //std::string PathF = "..//example.txt"; // andra fil vägen
/*
    your ticket:
    157,59,163,149,83,131,107,89,109,113,151,53,127,97,79,103,101,173,167,61

*/
struct con
{
    string name;
    int high1;
    int low1;
    int high2;
    int low2;
};
struct tick
{
    string name;
    vector<string> hit;
    vector<string> hitname;
    vector<int> content;
} ticket;

vector<con> conds;

vector<tick> tickets;
int yes, no;

void condis(string l4)
{
    con condition;
    string line = l4.substr(l4.find_first_of(':') + 2);
    string n = l4.substr(0,l4.find_first_of(':'));
    string str2 = line.substr(line.find_last_of('r') + 2);
    string str1 = line.substr(0, line.find_first_of(' '));
    //cout << str1 << endl;
    //cout << str2 << endl;
    condition.name = n;
    condition.high1 = stoi(str1.substr(str1.find_first_of('-') + 1), nullptr, 10);
    condition.low1 = stoi(str1.substr(0, str1.find_first_of('-') + 1), nullptr, 10);
    condition.high2 = stoi(str2.substr(str2.find_first_of('-') + 1), nullptr, 10);
    condition.low2 = stoi(str2.substr(0, str2.find_first_of('-') + 1), nullptr, 10);
    conds.push_back(condition);
}

void ticketgrab(string l2)
{
    string l3;
    stringstream ss(l2);
    while (getline(ss, l3, ','))
    {

        

        ticket.content.push_back(stoi(l3, nullptr, 10));
    }
    //cout << endl;
    tickets.push_back(ticket);
    ticket.content.clear();
    
}

int fullGetInput()
{

    std::ifstream input;
    string l2;
    input.open(PathF);
    int mode = 1;
    if (!input.is_open())
    {
        std::cout << "not found or could not open\n";
        return 1;
    }
    while (getline(input, l2))
    {
        if (l2.empty())
        {
            mode++;
        }
        else
        {
            if (mode == 1)
            {
                condis(l2);
            }
            else if (mode == 3)
            {
                ticketgrab(l2);
            }
        }
    }
    return 0;
}
int sum = 0;
    // int t = 9;
vector<vector<string>> hit;
void checkTicket(tick y)
{
    
    vector<string> temp2;
    for (size_t t = 0; t < conds.size() ; t++)
    {
    for (size_t n = 0; n < y.content.size(); n++)
    {
    
    
    int temp = y.content[n];

    int counter = 0;
        if ((temp - (conds[t].low1) >= 0) && ((conds[t].high1) - temp >= 0))
        {
            temp2.push_back(".");
            // cout << "yes | ";
            // cout << conds[t].low1 << " < " << temp << " < " << conds[t].high1 << "  ";
            // cout << conds[t].low2 << " < " << temp << " < " << conds[t].high2;
            // cout << "\t|name: " << conds[t].name << endl;
        //    cout << "pbno| " << conds[t].low2 << "  <  " << temp << "  <  " << conds[t].high2 << endl;
        }
        else if ((temp - (conds[t].low2) >= 0) && ((conds[t].high2) - temp >= 0))
        {
            temp2.push_back(".");
            // cout << "yes | ";
            // cout << conds[t].low1 << " < " << temp << " < " << conds[t].high1 << "  ";
            // cout << conds[t].low2 << " < " << temp << " < " << conds[t].high2;
            // cout << "\t|name: " << conds[t].name << endl;

        }
        else
        {
            temp2.push_back("N");
            //  cout << "no  | " << conds[t].low1 << "  <  " << temp << "  <  " << conds[t].high1 << endl;
            //  cout << "no  | " << conds[t].low2 << "  <  " << temp << "  <  " << conds[t].high2 << endl;
        }

     }
             
        hit.push_back(temp2);
        
        temp2.clear();
    

    
    
    }

    
    
    
    
     
}
int main()
{

    // cout << "------------------------- \t Index: " << ind << endl;
    fullGetInput();
    for (auto &&i : tickets)
    {
       checkTicket(i);
       
    }
    for (size_t i = 0; i < hit.size(); i++)
    {
        if (i % 20 == 0) {
            cout << endl;
        }
        for (auto &&v : hit[i])
        {
            cout << v << " ";
        }
        cout << i % 20;
        cout << "\tname: " << conds[i%20].name << endl;
    }
        
}