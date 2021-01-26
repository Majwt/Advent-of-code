#include <bits/stdc++.h>
using namespace std;

using bag_pair = pair<string, int>;
// std::string Path = "..//input.txt";
std::string Path = "..//example.txt"; // andra fil vägen

struct Bag
{
    static unordered_map<string, Bag*> bag_index;
    string name;
    Bag(string new_name) : name{new_name} {}

    vector<bag_pair> bag_contains;
    vector<string> bag_inside;

    void contains_bags(string name,int amount) {
        bag_pair bags(name,amount);
        bag_contains.push_back(bags);
    }
    void add_inside(string name) {
        bag_inside.push_back(name);
    }
};
unordered_map<string, Bag*> Bag::bag_index = {};
int counter = 0;
int counter2 = 0;
string myFunction(string name);

vector<string> lines;
vector<string> temp;

void other(string l) {
    
    vector<string> found;
    for (auto &&i : lines)
    {
        int t = i.find(l,15);
        if (t != string::npos) {
            int t2 = i.find("bags");
            if(t2 != string::npos) {

            found.push_back(i.substr(0,t2-1));
            }
        }
    }
    
    for (auto &&i : found)
    {
        cout << i << endl;
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
    int i = 0;
    while (getline(input, l))
    {

        // std::cout << l << endl;
        lines.push_back(l);
        if (l.find("shiny gold") != string::npos)
        {
            // temp.push_back(i);
        }
        i++;
    }

    other("shiny gold");
    // string c = myFunction("shiny gold");
    // string a;
   
    // cout << counter2 << endl;
}
int t;
// void myFunction() {
//     int pos = bags[0].find("bags");
//     if(pos != string::npos) {
//         cout << pos << endl;
//         string a = bags[0].substr(0,pos-1);
//         cout << a << endl;
//         string inside = bags[0].substr(pos+13);
//         int pos2 = inside.find(',');
//         if (pos2 != string::npos) {
//             inside.substr(0,pos2);
//         }
//         cout << inside << endl;
//     }
// }
string myFunction(string name)
{
    
    cout << lines.size() << endl;
    int no = 0;
    for (size_t n = 0; n < 1000000; n++)
    {
    string b;
    
    for (int i = 0; i < lines.size(); i++)
    {
        if (name == "shiny gold" && n != 0) {
            return "";
        }
        if (lines[i].find(name,15) != string::npos)
        {
            t = i;
            counter++;
            // counter2++;
            int a = lines[i].find("bags");
            if (a != string::npos)
            {
                b = lines[i].substr(0, a - 1);
                cout << b << endl;
                temp.push_back(b);
            }
        }
    }
    if (counter > 0) {
        counter2 += counter;
                name = b;
         
    }
    counter = 0;
    }
    return "";
}

void seperate(string l) {
    int n = l.find("bags");
    if (n != string::npos) {
        string s = l.substr(0,n-2);
        Bag *current_bag;
        if(Bag::bag_index.find(s) == Bag::bag_index.end()) {
            current_bag = new Bag(s);
            Bag::bag_index[s] = current_bag;
        } else {
            current_bag = Bag::bag_index[s];
        }

        
        
    }
}

