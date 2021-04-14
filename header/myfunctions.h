#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Gets a closing -> rpar by the cord of the opening lpar
 * 
 * @param expression The string with the -> brackets
 * @param index index of -> lpar
 * @param lpar left (
 * @param rpar right )
 * @return index of closing
 */
int closing(string expression, int index, char lpar, char rpar)
{
    int i;

    if (expression[index] != lpar)
    {

        return -1;
    }

    stack<int> st;

    for (i = index; i < expression.length(); i++)
    {

        if (expression[i] == lpar)
            st.push(expression[i]);

        else if (expression[i] == rpar)
        {
            st.pop();
            if (st.empty())
            {

                return i;
            }
        }
    }
    return -1;
}

string byte_to_binary(long long x, int maxsize = 5)
{
    string b;
    long long i = 0;
    for (long long z = pow(2, maxsize - 1); z > 0; z >>= 1, i++)
    {
        b += ((x & z) == z) ? "1" : "0";

    }
    
    return b;
}

void print_binary(long long b, int maxchar)
{
    for (long long z = pow(2, maxchar - 1); z > 0; z >>= 1)
    {
        cout << (((b & z) == z) ? "1" : "0");
    }
}
