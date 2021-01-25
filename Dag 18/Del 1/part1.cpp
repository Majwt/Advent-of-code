
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
    long long sum = 0;
    int mode = 0;
    string test = "";
    stringstream ss{str};
    string ln;
    while (getline(ss, ln, ' '))
    {
        spaced.push_back(ln);
    }

    for (int i = 0; i < spaced.size(); i++)
    {
        string v = spaced[i];

        if (v == "+")
        {

            mode = 1;
            continue;
        }
        else if (v == "*")
        {

            mode = 2;
            continue;
        }
        else
        {
            test.append(v);

            switch (mode)
            {
            case 1:

                sum += stoi(test, nullptr);
                cout << sum << endl;
                test.clear();
                break;
            case 2:
                sum *= stoi(test, nullptr);
                test.clear();
                cout << sum << endl;
                break;
            case 0:
                sum += stoi(test, nullptr);
                test.clear();
                break;
            default:
                break;
            }
        }
    }
    cout << "insum: " << sum << endl;
    return sum;
}