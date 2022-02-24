#include <bits/stdc++.h>
using std::cout; using std::endl;
std::string l;
std::map<std::pair<float, float>, bool> Hexes;
std::string Path = "..//input.txt";
// std::string Path = "..//example.txt"; // andra fil vägen
std::vector<std::string> locators;
void flip(std::string location) {
    float x, y = 0;
    std::string::iterator it;
    int i = 0;
    for (it = location.begin(); it != location.end(); it++, i++)
    {

        if (*it == 'n' || *it == 's')
        {
            if (*it == 'n')
            {
                y += 0.5f;
            }
            else
            {
                y -= 0.5f;
            }
            it++;
            switch (*it)
            {
            case 'e':
                x += 0.5f;

                break;

            case 'w':
                x -= 0.5f;
                break;
            default:
                cout << "default" << endl;
                break;
            }
        }
        else if (*it == 'e') {
            x += 1.f;
        }
        else if (*it == 'w') {
            x -= 1.f;
        }
    }

    Hexes[std::pair<float, float>(x, y)] = (Hexes[std::pair<float, float>(x, y)] == true) ? false : true;

}
int main()
{
    std::ifstream input{ Path };
    std::string line;
    while (std::getline(input, line)) {
        cout << line << endl;
        flip(line);
    }
    size_t counter = 0;
    for (auto&& i : Hexes)
    {
        counter += i.second;
    }
    cout << counter << endl;


}