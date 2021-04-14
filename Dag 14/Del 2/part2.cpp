#include <bits/stdc++.h>
// #include "header/myfunctions.h"
// #include <header/addons.h>
// #include "C:/Users/theodor.wase/Documents/Visual Studio 2019/projekt/Advent-of-code-1/header/myfunctions.h"

#include "d:/Kod/hfiler/myfunctions.hpp"

using namespace std;

// std::string Path = "..//input.txt";
std::string Path = "..//example.txt"; // andra fil vägen

map<int, size_t> mem;

string reverse(string a) {
    reverse(a.begin(),a.end());
    return a;
}


vector<long long> masking(long long x, string mask = "000000000000000000000000000000000000")
{
    vector<long long> out;
    string b;
    vector<string> temp = {b};
    string inString = byte_to_binary(x, mask.size());
    // reverse(inString.begin(), inString.end());
    // cout << "input:\t" << x << endl
    //      << "bin:\t" << inString << endl
    //      << "\t\t";
    // b[0] = '\0';

    string rmask = reverse(mask);
    long long m = pow(2, mask.size() - 1);
    long long z;
    int i = mask.size() - 1;

    for (z = 0; i != -1; z <<= 1, i--)
    {
        // cout << "before: " << endl;
        // for (auto &&n : temp)
        // {
        //     cout << '\t' << n << endl;
        // }
        // cout << "mask: " << mask[i] << endl << "after: \n";
        int siz = temp.size();
        for (size_t j = 0; j != siz; j++)
        {
            
            if (mask[i] == 'X')
            {
                if (temp.size() > 100) {
                    return vector<long long>(10);
                }
                temp.push_back(temp[j]);
                temp[j] += '0';
                temp[j + siz] += '1';
                // cout << endl << temp[j] << endl << temp[j+1] << endl;
                continue;
            }
            else if (mask[i] == '1')
            {
                temp[j] += '1';
            }
            else
            {
                // ((x&z) == z) ? "1" : "0";
                temp[j] += inString[i];
            }
        }
        // for (auto &&n : temp)
        // {
        //     cout << '\t' << n << endl;
        // }
        // cout << endl;
    }
    for (auto &&i : temp)
    {
        // cout << i << endl;
        out.push_back(stoll(reverse(i), nullptr, 2));
    }

    // cout << "\ndone:\t" << out[0] << endl;

    return out;
}

int main()
{

    std::string l;
    std::ifstream input{Path};
    if (!input)
    {
        std::cout << "not found or could not open\n";
        return 1;
    }
    string check, mask;
    while (input)
    {

        getline(input, l);
        stringstream parser{};
        parser << l;
        parser.ignore(3);
        parser >> check;
        int mempos;
        // cout << check << endl;
        if (check == "k") {
            parser.ignore(2);

            parser >> mask;
            // cout << "mask: " << mask << "\t size:" << mask.size() << endl;
            continue;
        } else {
            mempos = stoi(check.substr(1,closing(check,0,'[',']')-1),nullptr,10);
            // cout << "mempos:\t" << mempos << endl;
            parser.ignore(3);
            long long v;
            parser >> v;
            // cout << "value:\t";
            // print_binary(v,36);
            // cout << " " << v << endl << "mask:\t" << mask << endl << "result:\t";
            auto r = masking(mempos,mask);
            for (auto &&i : r)
            {
            mem[i] = v;
            }
            
            // print_binary(r,36);
            // printf("\nmem[%d] = %lld\n\n",mempos,mem[mempos]);
        }
        if (input.fail())
        {
            break;
        }
        if (parser.fail()) {
            break;
        }
    }

    // int a = 511;
    // int b = 42;
    // print_binary(b, 10);
    // vector<long long> test = masking(b, "000000000000000000000000000000X1001X");
    // for (auto &&i : test)
    // {
    //     print_binary(i, 7);
    //     cout << " " << i << endl;
    // }

    size_t sum = 0;
    for (auto &&i : mem)
    {
        sum+=i.second;
    }
    cout << "\nsum: " << sum;
    // string mask = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX0X0X0X";
    // static char o[9] = byte_to_binary(5);
    // string biRes = byte_to_binary(a,36,mask);
    // long long r = stoi(biRes,nullptr,2);
    // cout << "value:  " << byte_to_binary(a,36) << endl;
    // cout << "mask:   " << mask << endl;
    // cout << "result: " << biRes << endl;
    // cout << "result int: " << r << endl;
}