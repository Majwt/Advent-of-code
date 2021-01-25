
#include <bits/stdc++.h>
using namespace std;

std::string Path = "..//input.txt";
// std::string Path = "..//example.txt"; // andra fil vägen

long long totalsum = 0;
// Adderar och multiplicerar med de speciella reglerna
long long getTotal(string str);

// hittar parentes par och kör getTotal på ekvationen inom 
int closing(string expression, int index); // inte min https://www.geeksforgeeks.org/find-index-closing-bracket-given-opening-bracket-expression/

// räknar hur många -> c <- det finns i string
int charInString(string s, char c);

// raderar parenteser till charInString ger 0
long long removePar(string s);

int main()
{
    std::ifstream input;
    std::string l;
    input.open(Path);
    if (!input.is_open())
    {
        std::cout << "not found or could not open\n";
        return 1;
    }
    while (getline(input, l))
    {
        cout << l << endl;
        totalsum += removePar(l);
        cout << totalsum << endl;
        cout << endl;
    }
    cout << "TotalSum:\t" << totalsum << endl;
}

int closing(string expression, int index)
{
    int i;

    if (expression[index] != '(')
    {

        return -1;
    }

    stack<int> st;

    for (i = index; i < expression.length(); i++)
    {

        if (expression[i] == '(')
            st.push(expression[i]);

        else if (expression[i] == ')')
        {
            st.pop();
            if (st.empty())
            {

                return i;
            }
        }
    }
}
int charInString(string s, char c)
{

    int cInS = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == c)
        {
            cInS++;
        }
    }
    return cInS;
}
long long removePar(string s)
{

    while (charInString(s, '(') != 0)
    {

        int foundO = s.find_last_of('(');
        if (foundO != string::npos)
        {

            int foundC = closing(s, foundO);

            string sub = s.substr(foundO + 1, foundC - foundO - 1);
            s.erase(foundO, foundC - foundO + 2);
            string re = to_string(getTotal(sub)) + " ";
            s.insert(foundO, re);
        }
    }
    return (long long)getTotal(s);
}
long long getTotal(string str)
{
    vector<string> spaced;
    vector<string> spaced2;
    long long sum = 1;
    stringstream ss{str};
    string ln;
    cout << endl;
    while (getline(ss, ln, ' '))
    {
        spaced.push_back(ln);
        cout << ln << " ";
    }

    for (int i = 0; i < spaced.size(); i++)
    {
        string v = spaced[i];
        cout << endl << i << "\t|\t" << v << "\t|\t";
        
        if (v == "+")
        {
            int tempsum = stoi(spaced[i-1],nullptr) + stoi(spaced[i+1],nullptr);
            if(i+2 < spaced.size() && i+2 != spaced.size() && spaced[i+2] == "+") {
                cout << "next +";
                spaced[i+1] = to_string(tempsum);
                

            } else {
                cout << "next !+";
                spaced2.push_back(to_string(tempsum));
            }
        }
        else if (v == "*")
        {
            cout << "*";
            if(i == 1) {
                spaced2.push_back(spaced[0]);
            }
            spaced2.push_back(v);
            if(i+2 < spaced.size() && spaced[i+2] != "+") {
                spaced2.push_back(spaced[i+1]);
            }
        }
        else if(i == spaced.size()-1 && spaced[i-1] != "+")
        { 
            spaced2.push_back(v);
        }
    }
    cout << endl;
    for (auto &&i : spaced2)
    {
        cout << i << " ";
        if(i != "+" && i != "*"){

        sum *= stoi(i,nullptr);
        }
    }
    
    cout << "= insum: " << sum << endl;
    return sum;
}