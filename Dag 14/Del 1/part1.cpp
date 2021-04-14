#include <bits/stdc++.h>
// #include "header/myfunctions.h"
// #include <header/addons.h>
#include "C:/Users/theodor.wase/Documents/Visual Studio 2019/projekt/Advent-of-code-1/header/myfunctions.h"
using namespace std;

std::string Path = "..//input.txt";
// std::string Path = "..//example.txt"; // andra fil vägen

map<int,size_t> mem;

size_t masking(long long x,int maxsize = 5,string mask = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX")
{
    string b;
    // b[0] = '\0';
    long long m = pow(2,maxsize-1);
    long long z;
    int i = 0;
    for (z = m; z > 0; z >>= 1, i++) {
        // cout << i << " ";
        if (mask[i] == 'X') {
            b+= ((x&z) == z) ? "1" : "0";
            continue;
        } else {
            // cout << i << " ";
            b += mask[i];
        }
    }
    return stoll(b,nullptr,2);
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
        string check,mask;
    while (input)
    {
        
        getline(input, l);
        stringstream parser{};
        parser << l;
        parser.ignore(3);
        parser >> check;
        int mempos;
        cout << check << endl;
        if (check == "k") {
            parser.ignore(2);

            parser >> mask;
            cout << "mask: " << mask << "\t size:" << mask.size() << endl;
            continue;
        } else {
            mempos = stoi(check.substr(1,closing(check,0,'[',']')-1),nullptr,10);
            cout << "mempos:\t" << mempos << endl;
            parser.ignore(3);
            long long v;
            parser >> v;
            cout << "value:\t";
            print_binary(v,36);
            cout << " " << v << endl << "mask:\t" << mask << endl << "result:\t";
            auto r = masking(v,36,mask);

            print_binary(r,36);
            mem[mempos] = r;
            printf("\nmem[%d] = %lld\n\n",mempos,mem[mempos]);
        }
        if (input.fail())
        {
            break;
        }
        if (parser.fail()) {
            break;
        }
    }

    int a = 511;
    int b = 31;
    size_t sum = 0;
    for (auto &&i : mem)
    {
        sum+=i.second;
    }
    cout << sum;
    // string mask = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX0X0X0X";
    // static char o[9] = byte_to_binary(5);
    // string biRes = byte_to_binary(a,36,mask);
    // long long r = stoi(biRes,nullptr,2);
    // cout << "value:  " << byte_to_binary(a,36) << endl;
    // cout << "mask:   " << mask << endl;
    // cout << "result: " << biRes << endl;
    // cout << "result int: " << r << endl;
    
    
}