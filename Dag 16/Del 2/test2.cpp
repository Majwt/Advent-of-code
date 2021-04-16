#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <sstream>
using namespace std;

// std::string PathC = "..//condition.txt";
// std::string Path = "..//input.txt";
std::string PathF = "..//Fullinput.txt";
// std::string PathF = "..//example.txt"; // andra fil vägen
/*
    your ticket:
    157,59,163,149,83,131,107,89,109,113,151,53,127,97,79,103,101,173,167,61

*/
/**
 * 1    !=
 * 2    !=
 * 3    != 
 * 4    !=
 * 5    !=
 * 6    != train zone
 * 7    !=
 * 8    !=
 * 9    !=
 * 10   != arrival-track
 * 11   != class && 
 * 12   != class && departure-track
 * 13   !=
 * 14   !=
 * 15   !=
 * 16   !=
 * 17   !=
 * 18   !=
 * 19   != route
 * 20   !=
 * 
 * */

struct con
{

    string name;

    pair<int, int> low;
    pair<int, int> high;
    bool check(int number)
    {
        if (low.first <= number && number <= low.second)
        {
            return true;
        }
        else if (high.first <= number && number <= high.second)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
struct tick
{
    string name;
    vector<string> hit;
    vector<string> hitname;
    vector<int> content;
} ticket, myTicket;

vector<con> conditions;

vector<tick> tickets;
int yes, no;
void check_row();
void get_conditions(string l4)
{
    con condition;
    string cname, range1, range2;
    stringstream parser{};
    parser << l4;
    parser >> cname;
    parser >> range1;
    parser.ignore(4);
    parser >> range2;
    auto f1 = range1.find('-');
    auto f2 = range2.find('-');
    auto nme = cname.find(':');
    int c1r1 = stoi(range1.substr(0, f1), nullptr, 10);
    int c1r2 = stoi(range1.substr(f1 + 1), nullptr, 10);
    int c2r1 = stoi(range2.substr(0, f2), nullptr, 10);
    int c2r2 = stoi(range2.substr(f2 + 1), nullptr, 10);
    condition.low = make_pair(c1r1, c1r2);
    condition.high = make_pair(c2r1, c2r2);

    condition.name = cname.substr(0, nme);
    conditions.push_back(condition);
}
tick get_myticket(string l2)
{
    string l3;
    stringstream ss(l2);
    while (getline(ss, l3, ','))
    {
        ticket.content.push_back(stoi(l3, nullptr, 10));
    }

    return ticket;
}

void get_ticket(string l2)
{
    ticket.content.clear();
    string l3;
    stringstream ss(l2);
    while (getline(ss, l3, ','))
    {
        ticket.content.push_back(stoi(l3, nullptr, 10));
    }
    tickets.push_back(ticket);
    ticket.content.clear();
}

int fullGetInput()
{

    std::ifstream input;
    string l;
    input.open(PathF);
    int mode = 1;
    if (!input.is_open())
    {
        std::cout << "not found or could not open\n";
        return 1;
    }
    while (input)
    {

        getline(input, l);
        if (l.empty())
        {
            mode++;
            cout << "mode++" << endl;
        }
        else if (mode == 3)
        {
            cout << "grabed tickets\n";
            get_ticket(l);
        }
        else if (mode == 2)
        {
            cout << "test";
            myTicket = get_myticket(l);
            for (auto &&i : myTicket.content)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else if (mode == 1)
        {
            cout << "get_conditions\n";
            get_conditions(l);
        }
        else
        {
            break;
        }
    }
    return 0;
}

int main()
{

    fullGetInput();
    for (auto &&i : tickets)
    {
        cout << "adad: ";
        for (auto &&j : i.content)
        {
            cout << j << ",";
        }

        cout << endl;
    }
    check_row();
}

void check_row()
{
    int max = 20;
    int start = 0;
    for (size_t i = 0; i < tickets.size(); i++)
    {
        for (size_t p = 0; p < conditions.size(); p++)
        {
            cout << p+1 << "\t";
        }
        cout << endl;
        for (size_t n = start; n < max; n++)
        {

            for (size_t j = 0; j < tickets[i].content.size(); j++)
            {
                cout << ((conditions[n].check(tickets[i].content.at(j))) ? "#" : ".") << "\t";
            }
            cout << conditions[n].name << endl;
        }
    }
}