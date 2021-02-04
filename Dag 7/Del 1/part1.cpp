#include <bits/stdc++.h>
using namespace std;

std::string Path = "..//input.txt";
// std::string Path = "..//example.txt"; // andra fil vägen

struct Bag
{
    string name;
    vector<pair<string, int>> inside;
};
vector<Bag> Bag_array;

/**
 * @brief Parsar input filen och delar upp den rätt.
 * 
 * @param line Linjen som den går igenom
 */
void parsing(string line);

/**
 * @brief Hämtar alla väskor som håller väskor i 'holders'. Jag vet inte hur den här fungerade men den gör det.
 * 
 * @param holders Lista med väskors namn.
 * @return vector<string> Lista med hittade väskornas namn.
 */
vector<string> get_holders(vector<string> holders);

/**
 * @brief Loopar igenom alla väskor och kör 'get_holders' som innehåller 'bagName' och räknar dom.
 * 
 * @param bagName Namnet på den sökande väskan
 * @return antalet väskor som kan innehålla 'bagName'
 */
int get_result(string bagName);

int main()
{
    char inputname[] = "shiny gold";
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
    printf("Total amount of bags that could be\ncontaining a '%s bag', is %d.", inputname, get_result(inputname));
}

vector<string> get_holders(vector<string> holders)
{
    map<string, int> counter;
    vector<string> out;
    for (auto &&i : holders)
    {
        for (auto &&n : Bag_array)
        {
            for (auto &&q : n.inside)
            {
                if (i == q.first)
                {
                    counter[n.name] = 0;
                }
            }
        }
    }
    for (auto &&i : counter)
    {
        out.push_back(i.first);
    }

    return out;
}
int get_result(string bagName)
{
    /** 
     * Jag vet inte hur den functionen här fungerar men den gör det. 
    */

    vector<string> holders = get_holders({bagName});
    vector<string> inside = get_holders(holders);

    while (!inside.empty())
    {
        holders.insert(holders.end(), inside.begin(), inside.end());
        inside = get_holders(inside);
    }

    sort(holders.begin(), holders.end());
    holders.erase(unique(holders.begin(), holders.end()), holders.end());

    return holders.size();
}
void parsing(string line)
{
    /**
     * @brief skapar objektet 'Bag' och hämtar namnet på väskan
     */
    int amount;
    string colour, pattern, Bag_name;
    Bag current;
    stringstream parser{};
    parser << line;
    parser >> pattern;
    parser >> colour;
    current.name = Bag_name = pattern + " " + colour;
    parser.ignore(13);

    /**
     * @brief går igenom insidan av väskan och sedan om det finns, 
     *        pushar namnen & antalet till vectorn innom Bag objectet. 
     */
    while (parser)
    {

        parser >> amount;
        parser >> pattern;
        parser >> colour;
        Bag_name = pattern + " " + colour;
        parser.ignore(6);
        if (parser.fail())
        {
            parser.clear();
            Bag_array.push_back(current);
            return;
        }
        current.inside.push_back(pair<string, int>(Bag_name, amount));
    }
}