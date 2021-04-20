#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>

std::string Path = "..//input.txt";
std::string PathN = "..//nopPos.txt";
std::string PathJ = "..//jmpPos.txt";
//std::string Path = "..//example.txt"; // andra fil vägen

struct action
{
    std::string name;
    int value;
    bool first;
};
std::vector<action> actions;
std::vector<int> nopPos;
std::vector<int> jmpPos;
int acc;
int highest = 0;

int grabLines()
{
    std::string l;
    std::ifstream doc;
    doc.open(PathJ);
    if (!doc.is_open())
    {
        std::cout << "not found or could not open\n";
        return 1;
    }
    while (std::getline(doc, l))
    {
        int v = std::stoi(l, nullptr, 10);
        jmpPos.push_back(v);
    }
    std::string l2;
    std::ifstream doc2;
    doc2.open(PathN);
    if (!doc2.is_open())
    {
        std::cout << "not found or could not open\n";
        return 1;
    }
    while (std::getline(doc2, l2))
    {
        int v = std::stoi(l2, nullptr, 10);
        nopPos.push_back(v);
    }
    return 0;
}
void myFunction()
{
    std::cout << std::boolalpha;
    for (size_t n = 0; n < actions.size(); n++)
    {
        if (n > highest)
        {
            highest = n;
        }
        if (actions[n].name == "acc" && actions[n].first == true)
        {
            actions[n].first = false;
            acc += actions[n].value;
            continue;
        }
        else if (actions[n].name == "jmp" && actions[n].first == true)
        {
            actions[n].first = false;
            n += actions[n].value - 1;
            continue;
        }
        else if (actions[n].name == "nop" && actions[n].first == true)
        {
            actions[n].first = false;
            continue;
        }
        else
        {
            break;
        }
    }
}
void pushToArray(std::string line, action a)
{
    std::string str = line.substr(4);
    int v = std::stoi(str, nullptr, 10);
    a.value = v;
    a.first = true;
    actions.push_back(a);
    a.name = "";
    a.value = 0;
    a.first = false;
}

int getlines(int indj = 1000, int indn = 1000)
{
    std::string l;
    std::ifstream input;
    input.open(Path);
    if (!input.is_open())
    {
        std::cout << "not found or could not open\n";
        return 1;
    }

    int counter = 1;
    while (std::getline(input, l))
    {
        action var;
        size_t found;

        found = l.find("nop");
        if (found != std::string::npos)
        {

            if (counter == indn)
            {
                var.name = "jmp";
            }
            else
            {
                var.name = "nop";
            }
            pushToArray(l, var);
        }
        found = l.find("acc");
        if (found != std::string::npos)
        {
            var.name = "acc";
            pushToArray(l, var);
        }
        found = l.find("jmp");
        if (found != std::string::npos)
        {
            if (counter == indj)
            {
                var.name = "nop";
            }
            else
            {
                var.name = "jmp";
            }
            pushToArray(l, var);
        }
        counter++;
    }
    return 0;
}
void resetVars()
{
    acc = 0;
    actions.clear();
    nopPos.clear();
    jmpPos.clear();
}

int main()
{
    grabLines();
    int finalIndex;
    for (size_t h = 0; h < 225; h++)
    {
        resetVars();
        getlines(jmpPos[h]);
        myFunction();
        if (highest == 611)
        {
            finalIndex = h;
            break;
        }
    }
    if (highest == 611)
    {
        std::cout << "\nLine nr: " << jmpPos[finalIndex] << "  |  jmp -> nop\n";
        std::cout << "Acc: " << acc << '\n';
    }
    else
    {
        for (size_t h = 0; h < 53; h++)
        {
            resetVars();
            getlines(-1, nopPos[h]);
            myFunction();
            if (highest == 611)
            {
                finalIndex = h;
                break;
            }
        }
        if (highest == 611)
        {
            std::cout << "\nLine nr: " << nopPos[finalIndex] << "  |  nop -> jmp\n";
            std::cout << "Acc: " << acc << '\n';
        }
        else
        {
            std::cout << "not found";
        }
    }
}