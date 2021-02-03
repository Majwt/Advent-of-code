#include <bits/stdc++.h>
using namespace std;

std::string Path = "..//input.txt";
// std::string Path = "..//example.txt"; // andra fil vägen

vector<string> lines;
struct bag
{
    string name;
    vector<pair<string, int>> inside;
};
vector<bag> bag_array;

vector<string> myfunc2(vector<bag> other, vector<string> holders)
{
    map<string, int> counter;
    for (auto &&i : holders)
    {
        for (size_t n = 0; n < other.size(); n++)
        {
            for (auto &&q : other.at(n).inside)
            {
                if (i == q.first)
                {
                    if (counter.find(other.at(n).name) != counter.end())
                    {
                        counter[other.at(n).name]++;
                    }
                    else
                    {
                        counter[other.at(n).name] = 1;
                    }
                }
            }
        }
    }
    vector<string> out;
    for (auto &&i : counter)
    {
        out.push_back(i.first);
    }

    return out;
}

int myfunc(string sname)
{
    int ind = 0;
    vector<bag> other = bag_array;

    vector<string> temp2 = {sname};
    vector<string> holders = myfunc2(other, temp2);

    int out = 1;
    vector<string> temp = myfunc2(other, holders);
    while (!temp.empty())
    {

        holders.insert(holders.end(), temp.begin(), temp.end());
        temp = myfunc2(other, temp);
    }
    sort(holders.begin(), holders.end());
    holders.erase(unique(holders.begin(), holders.end()), holders.end());
    int inc = holders.size();
    for (auto &&i : holders)
    {
        cout << i << endl;
    }

    return inc;
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
    while (input)
    {
        getline(input, l);
        cout << l << endl;
        stringstream parser{};
        parser << l;

        string colour, pattern;
        parser >> pattern;
        parser >> colour;
        bag current;
        string bag_name = pattern + " " + colour;

        cout << bag_name << endl;
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
                cout << "cleared" << endl;
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
            bag_array.push_back(current);
        }
    }

    for (auto &&i : bag_array)
    {
        cout << i.name << " {";
        for (auto &&n : i.inside)
        {
            cout << n.first << "(" << n.second << ")" << ",";
        }
        cout << "}\n";
    }

    cout << "\nresultat:\n"
         << myfunc("shiny gold") << endl;
}