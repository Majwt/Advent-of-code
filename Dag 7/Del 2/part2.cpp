#include <bits/stdc++.h>
using namespace std;

std::string Path = "..//input.txt";
// std::string Path = "..//example.txt"; // andra fil vägen

struct bag
{
    string name;
    vector<pair<string, int>> inside;
};
unordered_map<string, bag> bag_array;



void parsing(string l);
int count_inner(string name);

int main()
{

    std::string l;
    std::ifstream input{Path};
    if (!input)
    {
        std::cout << "not found or could not open\n";
        return 1;
    }
    while (input)
    {
        getline(input, l);
        parsing(l);
    }

    cout << "\nresultat:\n";
    int sum = count_inner("shiny gold");
    cout << sum << endl;
}

void parsing(string l)
{
    stringstream parser{};
    parser << l;

    bag current;
    string colour, pattern, bag_name;
    parser >> pattern;
    parser >> colour;
    bag_name = pattern + " " + colour;

    parser.ignore(13);
    if (!parser.fail())
    {
        current.name = bag_name;
    }
    else
    {
        parser.clear();
    }

    while (parser)
    {
        int amount;
        parser >> amount;
        string c_pattern, c_colour;
        parser >> c_pattern;
        parser >> c_colour;
        string nbag_name = c_pattern + " " + c_colour;
        parser.ignore(6);
        if (!parser.fail())
        {
            current.inside.push_back(pair<string, int>(nbag_name, amount));
        }
        else
        {
            parser.clear();
            break;
        }
    }
    if (parser.fail())
    {
        parser.clear();
        current = {};
    }
    else
    {
        bag_array[current.name] = current;
    }
}

int count_inner(string name)
{
    auto b = bag_array[name].inside;
    if (b.empty())
    {
        cout << "\treturned\n}\n";
        return 0;
    }
    for (auto &&i : b)
    {
        cout << "[" << i.first << " (" << i.second << ")] {" << endl;
    }

    int sum = 0;
    for (auto &&i : b)
    {
        cout << "\tAdding bag " << i.first << "(" << i.second << ")" << endl;
        sum += i.second;
        cout << "\tGoing to " << i.first << "(" << i.second << ")" << endl;
        sum += i.second * count_inner(i.first);
    }
    return sum;
}

