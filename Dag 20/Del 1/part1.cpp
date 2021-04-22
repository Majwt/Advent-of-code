#include <bits/stdc++.h>
using namespace std;

std::string l;
// std::string Path = "..//input.txt";
std::string Path = "..//example.txt"; // andra fil vägen

int to_Bi(string a);
vector<string> get_edges(vector<string> tile);

int main()
{

    std::ifstream input;
    input.open(Path);
    if (!input.is_open())
    {
        std::cout << "not found or could not open\n";
        return 1;
    }
    string l;
    vector<string> tTile, tId;
    vector<vector<string>> tTileHolder;
    while (input)
    {
        getline(input, l);
        stringstream parser{};
        parser << l;

        if (parser.fail() || input.fail())
        {
            break;
        }
        string tileId, line;
        parser >> line;

        if (line == "Tile")
        {
            parser >> tileId;
            tileId = tileId.substr(0, 4);
            cout << tileId << endl;

            tId.push_back(tileId);
        }
        else if (line.empty())
        {
            if (!tTile.empty())
            {
                tTileHolder.push_back(tTile);
                tTile.clear();
            }
        }
        else
        {
            cout << line << endl;
            tTile.push_back(line);
        }
    }
    int n = 8;
    cout << endl
         << tId[n] << endl;
    for (auto &&i : tTileHolder[n])
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << to_Bi(i) << endl;
    }
    vector<string> p = get_edges(tTileHolder[8]);
    for (auto &&i : p)
    {
        cout << to_Bi(i) << endl;
    }
    
}

vector<string> get_edges(vector<string> tile)
{
    vector<string> out;
    for (size_t i = 0; i < 10; i += 9)
    {
        string temp1;
        string temp2;
        for (size_t j = 0; j < tile[i].size(); j++)
        {
            temp1 += tile.at(j).at(i);
            temp2 += tile.at(i).at(j);

        }
        out.push_back(temp1);
        out.push_back(temp2);
        cout << temp1 << endl;
        cout << temp2 << endl;
        temp1.clear();
        temp2.clear();
    }
    return out;
}

int to_Bi(string a)
{
    int val = 0;
    int n = 0;
    for (int i = a.size() - 1; i >= 0; i--, n++)
    {
        if (a.at(n) == '#')
        {
            val += pow(2,i);
        }
    }
    return val;
}