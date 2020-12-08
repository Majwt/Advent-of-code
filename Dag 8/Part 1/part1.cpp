#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>

//using namespace std;

std::string Path = "..//input.txt";
//std::string Path = "..//example.txt"; // andra fil vägen
int acc;
struct action
{
    std::string name;
    int value;
    bool first;
};
std::vector<action> actions;
std::vector<int> values;
std::vector<int> indexHit;

void myFunction()
{
    std::cout << std::boolalpha; 
    for (size_t n = 0; n < actions.size(); n++)
    {
        if(n != 612) {
        
        indexHit.push_back(n);
        if (actions[n].name == "acc" && actions[n].first == true)
        {
            actions[n].first = false;
            acc += actions[n].value;
            std::cout << "\nindex: " << n;
            std::cout << "\nförsta? " << actions[n].first << "\n";
            std::cout << "namn: " << actions[n].name << "\n";
            std::cout << "värde: " << actions[n].value << "\n";
            std::cout << "nya Acc: " << acc << '\n';
            continue;
        }
        else if (actions[n].name == "jmp" && actions[n].first == true)
        {
            
            actions[n].first = false;
            if (actions[n].value + n > 604) {
                values.push_back(actions[n].value);
                values.push_back(n);
            }
            n += actions[n].value - 1;
            std::cout << "\nindex: " << n;
            std::cout << "\nförsta? " << actions[n].first << "\n";
            std::cout << "namn: " << actions[n].name << "\n";
            std::cout << "värde: " << actions[n].value << "\n";
            continue;
        }
        else if (actions[n].name == "nop" && actions[n].first == true)
        {
            actions[n].first = false;
            if (actions[n].value + n > 604) {
                values.push_back(actions[n].value);
                values.push_back(n);
            }
            std::cout << "\nindex: " << n;
            std::cout << "\nförsta? " << actions[n].first << "\n";
            std::cout << "namn: " << actions[n].name << "\n";
            std::cout << "värde: " << actions[n].value << "\n";
            continue;
        }
        } else
        {
            
     break;   
    }
        std::cout << "\nindex: " << n;
            std::cout << "\nförsta? " << actions[n].first << "\n";
            std::cout << "namn: " << actions[n].name << "\n";
            std::cout << "värde: " << actions[n].value << "\n";
        break;
    }


    std::cout << '\n' << "a "
              << acc
              << "\n";
        for (int u = 0; u < values.size(); u++)
        {
            std::cout << "\nvalues: " << values[u];
        }
        for (int q = 0; q < indexHit.size(); q++)
        {
            std::cout << "\nindeces: " << indexHit[q];
        }
        

}

int main()
{
    std::string l;

    std::ifstream input;
    input.open(Path);
    if (!input.is_open())
    {
        std::cout << "not found or could not open\n";
        return 1;
    }
    std::cout << "\nindexing";
    while (std::getline(input, l))
    {
        action var;
        size_t found;
        std::string str;
        std::cout << '.';
        //std::cout << l << '\n';
        found = l.find("nop");
        if (found != std::string::npos)
        {
            str = l.substr(found + 3);
            //std::cout << str << "\n";
            int v = std::stoi(str, nullptr, 10);
            var.value = v;
            var.name = "nop";
            var.first = true;
            actions.push_back(var);
            var.name = "";
            var.value = 0;
            var.first = false;
        }
        found = l.find("acc");
        if (found != std::string::npos)
        {
            str = l.substr(found + 3);

            int v = std::stoi(str, nullptr, 10);
            var.value = v;
            var.name = "acc";
            var.first = true;
            actions.push_back(var);
            var.name = "";
            var.value = 0;
            var.first = false;
        }
        found = l.find("jmp");
        if (found != std::string::npos)
        {
            str = l.substr(found + 3);
            int v = std::stoi(str, nullptr, 10);
            var.value = v;
            var.name = "jmp";
            var.first = true;
            actions.push_back(var);
            var.name = "";
            var.value = 0;
            var.first = false;
        }
    }


    // for (size_t i = 0; i < actions.size(); i++)
    // {
    //     std::cout << "\n"
    //               << actions[i].name << "\n"
    //               << actions[i].value << "\n";
    // }
    myFunction();
}