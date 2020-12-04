#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <sstream>

struct passport
{
    std::string byr;
    std::string iyr;
    std::string eyr;
    std::string hgt;
    std::string hcl;
    std::string ecl;
    std::string pid;
    std::string cid;
};

std::vector<std::string> clines;
std::vector<passport> data;

enum string_code
{
    byr,
    iyr,
    eyr,
    hgt,
    hcl,
    ecl,
    pid,
    cid
};

string_code hashit(std::string const &inString)
{
    if (inString == "byr")
        return byr;
    if (inString == "iyr")
        return iyr;
    if (inString == "eyr")
        return eyr;
    if (inString == "hgt")
        return hgt;
    if (inString == "hcl")
        return hcl;
    if (inString == "ecl")
        return ecl;
    if (inString == "pid")
        return pid;
    if (inString == "cid")
        return cid;
}

void addpassport(std::string full)
{
}

int main()
{

    std::ifstream input{"d:\\Kod\\Advent of Code\\Dag 4\\input.txt"};
    if (!input.is_open())
    {
        return 1;
    }

    std::string l;
    std::string line2;

    while (std::getline(input, l))
    {
        // std::cout << l << "\n";
        line2.append(l + "\n");
    }
    std::string s;
    std::istringstream is(line2);
    int pos = 4;

    passport structure;
    while (std::getline(is, s))
    {
        if (s.empty())
        {
            std::cout << "\n"
                      << "pushed";
            data.push_back(structure);
        }
        else
        {
            std::cout << "\n"
                      << s;
            switch (hashit(s))
            {
            case byr:
                structure.byr = s.substr(pos);
                break;
            case iyr:

                structure.iyr = s.substr(pos);
                break;
            case eyr:

                structure.eyr = s.substr(pos);
                break;
            case hgt:

                structure.hgt = s.substr(pos);
                break;
            case hcl:

                structure.hcl = s.substr(pos);
                break;
            case ecl:

                structure.ecl = s.substr(pos);
                break;
            case pid:

                structure.pid = s.substr(pos);
                break;
            case cid:

                structure.cid = s.substr(pos);
                break;
            }
        }
    }
}