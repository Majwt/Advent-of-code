#include <bits/stdc++.h>
using namespace std;
vector<vector<vector<char>>> v3d;
void expand() {
    vector<vector<char>> addition3d;
    vector<char> addition2d;
    for (size_t i = 0; i < v3d.size()+2; i++)
    {
        addition2d.push_back('#');

    }
    for (size_t i = 0; i < v3d.size()+2; i++)
    {
        addition3d.push_back(addition2d);
    }
    for (auto &&i : v3d)
    {
        for (auto &&j : i)
        {
            j.push_back('.');
            j.insert(j.begin(), '.');
        }
        i.push_back(addition2d);
        i.insert(i.begin(), addition2d);
    }

    v3d.push_back(addition3d);
    v3d.insert(v3d.begin(), addition3d);

}
int main(int argc, char const *argv[])
{
    vector<vector<char>> temp2d;
    vector<char> temp1d;
    for (size_t i = 0; i < 5; i++)
    {
        temp1d.push_back('.');
    }
    for (size_t i = 0; i < 5; i++)
    {
        temp2d.push_back(temp1d);
    }
    for (size_t i = 0; i < 5; i++)
    {
        v3d.push_back(temp2d);
    }

    for (auto &&q : v3d)
    {
        for (auto &&i : q)
        {
            cout << "  ";
            for (auto &&j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }
    cout << "after" << endl;
    expand();
    
    // addition2d.push_back('#');
    // addition2d.insert(addition2d.begin(), '#');
    // for (auto &&i : addition3d)
    // {
    //     i.push_back('#');
    //     i.insert(i.begin(), '#');
    // }
    

    for (auto &&q : v3d)
    {
        for (auto &&i : q)
        {
            for (auto &&j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }

    return 0;
}
