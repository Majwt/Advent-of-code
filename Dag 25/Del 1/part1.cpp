#include <bits/stdc++.h>
using namespace std;

std::string Path = "..//input.txt";
// std::string Path = "..//example.txt"; // andra fil vägen

int findLoop(int seq);

long long findenc(long long sub, int loopSize);

int main()
{
    map<int,int> key;
    vector<int> vec;
    std::string l;
    std::ifstream input;
    input.open(Path);
    if (!input.is_open())
    {
        std::cout << "not found or could not open\n";
        return 1;
    }
    while (getline(input, l))
    {
        std::cout << l << endl;
        int b = stoll(l,nullptr);
        int c = findLoop(b);
        vec.push_back(b);
        key[b] = c;
        cout << "loopSize: " << c << endl << endl;
    }

    long long o1 = findenc(vec[0],key[vec[1]]);
    cout << endl;
    long long o2 = findenc(vec[1],key[vec[0]]);
    if(o1-o2 == 0) {

    cout << "\nEncryption key: " << o1 << endl;
    } else {
        cout << "no" << endl;
    cout << "1: " << o1 << endl;
    cout << "2: " << o2 << endl;
    }

}

int findLoop(int start) 
{
    
    int a = 1;
    int sub = 7;
    int loopSize = 0;
    while (a != start)
    {

        a *= sub;
        a = a % 20201227;
        loopSize++;
    }
    
    return loopSize;
}
long long findenc(long long sub,int loopSize) 
{
    cout << "subject number: " << sub << endl;
    int loop = 100;
    if (loopSize) {
        loop = loopSize;
    }
    long long a = 1;
    for(int i = 0; i != loop; i++)
    {
        a *= sub;
        a %= 20201227;
        // cout << i <<"\t|\t" << a << endl;
    }
    
    return a;
}
