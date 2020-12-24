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
vector<vector<string>> hit;
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
int ind = 1;
void checkTicket(tick y)
{
    vector<string> temp2;
    for (size_t n = 0; n < y.content.size(); n++)
    {
        /* code */
    
    int x = y.content[n];
    int temp = x;

    int compatible = 0;
    int counter = 0;
    for (auto &&i : conds)
    {
        
        if ((temp - (i.low1)) >= 0 && ((i.high1) - temp) >= 0)
        {
            temp2.push_back("Y");
            // cout << "yes | ";
            // cout << i.low1 << " < " << temp << " < " << i.high1 << "  ";
            // cout << i.low2 << " < " << temp << " < " << i.high2;
            // cout << "\t|name: " << i.name << endl;
           // cout << "pbno| " << i.low2 << "  <  " << temp << "  <  " << i.high2 << endl;
        }
        else if ((temp - (i.low2)) >= 0 && ((i.high2) - temp) >= 0)
        {
            temp2.push_back("Y");
            // cout << "yes | ";
            // cout << i.low1 << " < " << temp << " < " << i.high1 << "  ";
            // cout << i.low2 << " < " << temp << " < " << i.high2;
            // cout << "\t|name: " << i.name << endl;

        }
        else
        {
            temp2.push_back("N");

            // cout << "no  | " << i.low1 << "  <  " << temp << "  <  " << i.high1 << endl;
            // cout << "no  | " << i.low2 << "  <  " << temp << "  <  " << i.high2 << endl;
            compatible++;
        }

    }
    hit.push_back(temp2);
    temp2.clear();
    cout << "value: " << x << " ";
    if (compatible == conds.size())
    {
        sum += x;
        no++;
        cout << "returned False" << "  no nr: ";
        cout << no << "\tcurrent sum: " << sum << endl;
        
    }
    else
    {
        yes++;
        cout << "returned True" << endl;
    }
    counter++;
    // cout << "------------------------- \t Index: " << ind << endl;
    ind++;
    }
}
int main()
{

    // cout << "------------------------- \t Index: " << ind << endl;
    ind++;
    fullGetInput();
    //for (auto &&i : tickets)
    //{
    //    checkTicket(i);
    //    
    //}
    for_each(tickets.begin(),tickets.end(),checkTicket);

   

    cout << "    p1,  p2,  p3,  p4,  p5,  p6,  p7,  p8,  p9,  p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20" << endl;

   for (size_t i = 0; i < 231; i++)
   {
       //cout << conds[i].name << ": ";
       cout << "  : ";
        
        for (size_t n = 0; n < hit[i].size(); n++)
        {
            cout << hit[i][n] << "    ";
        }
        
        cout << endl;

   }
    
    
}