#include <bits/stdc++.h>
using namespace std;

// std::string Path = "..//input.txt";
std::string Path = "..//example.txt"; // andra fil vägen
// std::string Path = "..//example copy.txt"; // andra fil vägen

vector<char> temp;
vector<vector<char>> temp2d;
vector<vector<vector<char>>> temp3d;
vector<vector<vector<vector<char>>>> plane;
vector<vector<vector<vector<char>>>> Pcopy;
vector<vector<vector<vector<char>>>> plane3d;
vector<vector<vector<vector<char>>>> Pcopy3d;

int size;

template <typename T>
bool hashtag(vector<T> *vec, int level, vector<int> pos)
{
    return hashtag(&vec->at(pos.at(level)), level + 1, pos);
}

template <>
bool hashtag(vector<char> *vec, int level, vector<int> pos)
{
    return (vec->at(pos.at(level)) == '#') ? true : false;
}

template <typename T>
void changeitem(vector<T> *vec,vector<T> *vec2, int level, vector<int> pos, int counter)
{
    changeitem(&vec->at(pos[level]),&vec2->at(pos[level]), level + 1, pos,counter);
}

template <>
void changeitem(vector<char> *vec,vector<char> *vec2, int level, vector<int> pos,int counter)
{
    if (vec->at(pos.at(level)) == '#') {
        if (counter-1 != 3 && counter-1 != 2){
            vec2->at(pos.at(level)) = '.';
            // cout << vec2->at(pos.at(level)) << endl;
        }
    } else {
        if (counter == 3) {
            vec2->at(pos.at(level)) = '#';
            // cout << vec2->at(pos.at(level)) << endl;
        }
    }
}

template <typename T>
int recNeigh(vector<T> vec, int level, vector<int> dim)
{
    int o = 0;
    if (dim[level] + 1 < vec.size() && dim[level] - 1 > 0)
    {
        for (int i = -1; i < 2; i++)
        {
            o += recNeigh(vec.at(dim[level] + i), level + 1, dim);
        }
    }
    return o;
}
template <>
int recNeigh(vector<char> vec, int level, vector<int> dim)
{
    int o = 0;
    if (dim[level] + 1 < vec.size() && dim[level] - 1 > 0)
    {
        for (int i = -1; i < 2; i++)
        {
            if (vec.at(dim[level] + i) == '#')
            {
                o += 1;
            }
            // test++;
        }
    }
    return o;
}

template <typename T>
void change(vector<T> *layers,vector<T> *layers2, vector<int> pos)
{
    // auto temp2 = &layers2;
    for (int i = 0; i < layers2->size(); i++)
    {
        // cout << "c";
        pos.push_back(i);
        change(&layers->at(i),&layers2->at(i), pos);
        pos.pop_back();
    }
}
template <>
void change(vector<char> *layers,vector<char> *layers2, vector<int> pos)
{
    // cout << "c";
    for (int i = 0; i < layers->size(); i++)
    {
        pos.push_back(i);
        int counter = recNeigh(Pcopy, 0, pos);
        changeitem(layers,layers2,0,pos,counter);
        // cout << endl;
        
        
        
        pos.pop_back();
    }
    // cout << "|";
}
template <typename T>
int countHash(vector<T> *layers, vector<int> pos)
{
    int active = 0;
    for (size_t i = 0; i < layers->size(); i++)
    {
        pos.push_back(i);
        active += countHash(&layers->at(i), pos);
        pos.pop_back();
    }
    return active;
}
template <>
int countHash(vector<char> *layers, vector<int> pos)
{
    int active = 0;
    for (size_t i = 0; i < layers->size(); i++)
    {
        pos.push_back(i);
        if (hashtag(&Pcopy, 0, pos))
        {
            active += 1;
        }
        pos.pop_back();
    }
    return active;
}

void initPlane(int linesize, int overflow = 7)
{
    for (size_t i = 0; i < (overflow * 2) + linesize; i++)
    {
        temp.push_back('.');
    }
    for (size_t i = 0; i < (overflow * 2) + linesize; i++)
    {
        temp2d.push_back(temp);
    }
    for (size_t i = 0; i < (overflow * 2) + linesize; i++)
    {
        temp3d.push_back(temp2d);
    }
    for (size_t i = 0; i < (overflow * 2) + linesize; i++)
    {
        plane.push_back(temp3d);
    }
}

void print_layer(vector<vector<char>> p, int y)
{
    cout << "z = " << y << "\n\t";
    for (size_t i = 0; i < p.size(); i++)
    {
        cout << i << "\t";
    }
    cout << endl;
    for (size_t i = 0; i < p.size(); i++)
    {
        cout << i << "\t";
        for (size_t j = 0; j < p[i].size(); j++)
        {
            cout << p[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
template <typename T>
void printPlane(vector<T> plane,int a)
{
        cout << a << endl;
    for (auto &&i : plane)
    {
        printPlane(i,a+1);
    }

    cout << endl;
}
template <>
void printPlane(vector<char> plane,int a)
{
    for (auto &&i : plane)
    {
        cout << i << " ";
    }
    cout << endl;
}
int countActive(vector<vector<vector<vector<char>>>> plane)
{
    int counter = 0;
    // int layer = 0;
    for (auto &&i : plane)
    {
        // cout << "\nz = " << layer << endl;
        for (auto &&j : i)
        {
            for (auto &&q : j)
            {
                for (auto &&k : q)
                {
                if (k == '#')
                    counter++;
                    
                }
                
                // cout << q << " ";
            }
            // cout << endl;
        }
        // layer++;
    }
    // cout << end;
    return counter;
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
    // int overflow = initPlane(8, 7);
    int overflow = 3;
    initPlane(3, overflow);

    int h = 0;
    while (getline(input, l))
    {
        std::cout << l << endl;
        for (size_t i = 0; i < l.size(); i++)
        {
            // plane3d[overflow + 1][overflow + h][overflow + i] = l[i];
            plane[overflow + 1][overflow + 1][overflow + h][overflow + i] = l[i];
        }

        h++;
    }
    // Pcopy3d = plane3d;
    Pcopy = plane;

    // Loop
    // printPlane(plane, ' ', "\n\n");
    // cout << plane[7][9][8] << endl;
    // print_layer(plane[7]);
    // changeitem(&plane,0,{0,0,0,1},3);
    //     cout << countActive(plane) << endl;
    auto t1 = chrono::high_resolution_clock::now();
    auto t2 = chrono::high_resolution_clock::now();
    auto time = chrono::duration_cast<chrono::seconds>(t2-t1);
    vector<int> pos;
    
    
        
    for (size_t a = 0; a < 1; a++)
    {
        
            for (size_t j = 0; j < plane.size(); j++)
            {
                for (size_t q = 0; q < plane.at(j).size(); q++)
                {
                    plane.at(j).at(q).insert(plane.at(j).at(q).begin(),temp);
                    plane.at(j).at(q).push_back(temp);
                    
                }
                plane.at(j).insert(plane.at(j).begin(),temp2d);
                plane.at(j).push_back(temp2d);
                
            }
            
            plane.insert(plane.begin(),temp3d);
            plane.push_back(temp3d);
            
        
    
        cout << countActive(plane) << endl << endl;
        t1 = chrono::high_resolution_clock::now();
        change(&Pcopy,&plane, pos);
        Pcopy = plane;
        plane.insert(plane.begin(),temp3d);
        plane.push_back(temp3d);
        t2 = chrono::high_resolution_clock::now();
        time = chrono::duration_cast<chrono::seconds>(t2-t1);
        cout << time.count() << "s\t";
        // printPlane(plane,0);
        cout << countActive(plane) << endl << endl;
    }
}