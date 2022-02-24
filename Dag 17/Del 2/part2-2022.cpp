#include <bits/stdc++.h>





int main(int argc, char const *argv[])
{
    std::ifstream input{"../example.txt"};
    
    std::string l;
    std::vector<std::string> lines;
    while (std::getline(input, l))
    {
        std::cout << l << '\n';
    }

    return 0;
}
