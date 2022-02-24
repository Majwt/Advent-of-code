#include <bits/stdc++.h>
using std::cout; using std::endl;
std::string l;
typedef std::pair<float, float> HexPos;
// std::string Path = "..//input.txt";
std::string Path = "..//example.txt"; // andra fil vägen
std::vector<std::string> locators;
HexPos getPos(std::string location) {
    float x, y = 0;
    std::string::iterator it;

    for (it = location.begin(); it != location.end(); it++)
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
    return HexPos(x, y);

}

void flip(std::string location, std::map<HexPos, bool>* Hexes) {
    HexPos pos = getPos(location);

    Hexes->operator[](pos) = (Hexes->operator[](pos) == true) ? false : true;

}
void flip(HexPos pos, std::map<HexPos, bool>* Hexes) {
    Hexes->operator[](pos) = (Hexes->operator[](pos) == true) ? false : true;
}
HexPos addPos(HexPos pos, std::string direction) {

    if (direction[0] == 'n')
    {
        pos.second += 0.5f;
        if (direction[1] == 'e')
        {
            pos.first += 0.5f;
        }
        else if (direction[1] == 'w')
        {
            pos.first -= 0.5f;
        }
        return pos;
    }
    else if (direction[0] == 's')
    {
        pos.second += 0.5f;
        if (direction[1] == 'e')
        {
            pos.first += 0.5f;
        }
        else if (direction[1] == 'w')
        {
            pos.first -= 0.5f;
        }
        return pos;
    }
    else if (direction[0] == 'e') {
        pos.first += 1.f;
        return pos;
    }
    else if (direction[0] == 'w') {
        pos.first -= 1.f;
        return pos;
    }
    return HexPos(0.2f, 0.2f);
}


size_t checksuronding(HexPos pos, std::map<HexPos, bool>* Hexes, std::map<HexPos, bool>* temp) {
    size_t counter = 0;
    std::string dir[6] = { "n", "ne", "se", "s", "sw", "nw" };
    for (int i = 0; i < 6; i++)
    {
        HexPos newpos = addPos(pos, dir[i]);
        if (newpos != HexPos(0.2f, 0.2f))
        {

            if (Hexes->find(newpos) != Hexes->end())
            {
                if (Hexes->at(newpos) == true)
                {
                    counter++;
                }
            }
            else {
                temp->operator[] (newpos) = false;
            }
        }
    }
    return counter;
}
int main()
{
    std::map<HexPos, bool> Hexes;
    std::ifstream input{ Path };
    std::string line;
    std::vector<std::string> linesNegh;
    std::string dir[6] = { "n", "ne", "se", "s", "sw", "nw" };
    int i = 0;
    while (std::getline(input, line)) {
        cout << line << endl;


        flip(line, &Hexes);

    }

    size_t counter = 0;
    std::map<HexPos, bool> Hexes2;
    Hexes2 = Hexes;
    for (auto&& i : Hexes)
    {
        counter += i.second;
    }
    cout << counter << endl;
    for (int n = 0; n < 6; n++) {
        counter = 0;
        int flips = 0;
        for (auto&& i : Hexes)
        {
            int neghbours = checksuronding(i.first, &Hexes, &Hexes2);
            if (i.second == false && neghbours == 2)
            {
                // flip(i.first, &Hexes2);
                Hexes2[i.first] = true;
                cout << "flipped to black\n";
                printf("(%f, %f)\n", i.first.first, i.first.second);
                flips++;
                // continue;
            }
            else if (i.second == true)
            {
                if (neghbours == 0) {

                    // flip(i.first, &Hexes2);
                    Hexes2[i.first] = false;
                    cout << "flipped to white\n";
                    printf("(%f, %f)\n", i.first.first, i.first.second);
                    flips++;
                }
                else if (neghbours > 2)
                {
                    // flip(i.first, &Hexes2);
                    Hexes2[i.first] = false;
                    cout << "flipped to white\n";
                    printf("(%f, %f)\n", i.first.first, i.first.second);
                    flips++;
                }
            }
        }
        cout << "flips == " << flips << endl;

        Hexes = Hexes2;
        for (auto&& i : Hexes)
        {
            counter += i.second;
        }
        cout << counter << endl;
    }

    return 0;
}