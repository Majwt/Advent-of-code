#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <regex>

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
int valid = 0;
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

void checkpassport(passport &data2)
{
    bool dateValid;
    bool hightValid;
    bool hairColourValid;
    bool idValid;
    if (!data2.byr.empty() &&
        !data2.iyr.empty() &&
        !data2.eyr.empty() &&
        !data2.hgt.empty() &&
        !data2.hcl.empty() &&
        !data2.ecl.empty() &&
        !data2.pid.empty() /*&&
        !data.cid.empty()*/)
    {
    int bir = std::stoi(data2.byr, nullptr, 10);
    int exp = std::stoi(data2.eyr, nullptr, 10);
    int isu = std::stoi(data2.iyr, nullptr, 10);
        if ((bir >= 1920 && bir <=2002) && (isu >= 2010 && isu <= 2020) && (exp >= 2020 && exp <= 2030)) 
        {dateValid = true;} else {dateValid = false;}

        std::string s (data2.hcl);
        std::smatch m;
        std::regex e ("(#)([a-f0-9])+\n");
        
        if(std::regex_match(data2.hcl, std::regex("(#)([a-f0-9])+\n") )) {hairColourValid = true; valid += 200;} else {hairColourValid = false;}
        
    }
    if (hairColourValid && dateValid) {
std::cout <<"\n\n" <<"true" << "\n\n";
valid++;
    data.push_back(data2);
    }
}


 std::vector<std::string> line;
int main()
{

    // std::ifstream input{"d:\\Kod\\Advent of Code\\Dag 4\\example.txt"};
    std::ifstream input{"d:\\Kod\\Advent of Code\\Dag 4\\input.txt"};
    if (!input.is_open())
    {
        return 1;
    }

    std::string l;
    std::string line2;

    while (std::getline(input, l))
    {
         std::cout << l << "\n";
        line2.append(l + "\n");

    }
    std::string s;
    std::istringstream is(line2);
    int pos = 4;

    passport structure;
    while (std::getline(is, s))
    {
       
        line.push_back(s);
        //std::cout << s << "\n";
        std::string str = s.substr(0,3);
        if (s.empty())
        {
            checkpassport(structure);
            
            structure.byr = "";
            structure.iyr = "";
            structure.eyr = "";
            structure.hgt = "";
            structure.hcl = "";
            structure.ecl = "";
            structure.pid = "";
            structure.cid = "";

        }
        else
        {
            
            
            switch (hashit(str))
            {
            case byr:
                // checkC[0]++;
                structure.byr = s.substr(pos);
                break;
            case iyr:
                // checkC[1]++;
                structure.iyr = s.substr(pos);
                break;
            case eyr:
                // checkC[2]++;
                structure.eyr = s.substr(pos);
                break;
            case hgt:
                // checkC[3]++;
                structure.hgt = s.substr(pos);
                break;
            case hcl:
                // checkC[4]++;
                structure.hcl = s.substr(pos);
                break;
            case ecl:
                // checkC[5]++;
                structure.ecl = s.substr(pos);
                break;
            case pid:
                // checkC[6]++;
                structure.pid = s.substr(pos);
                break;
            case cid:
                // checkC[7]++;
                structure.cid = s.substr(pos);
                break;
            default:
                break;
            }
        }
    }
    for (size_t b = 0; b < data.size(); b++)
    {
        
        std::cout << "\n" << data.size() << "\n";
        std::cout << "byr,"<< data[b].byr <<"\n";
        std::cout << "iyr,"<< data[b].iyr <<"\n";
        std::cout << "eyr,"<< data[b].eyr <<"\n";
        std::cout << "hgt,"<< data[b].hgt <<"\n";
        std::cout << "hcl,"<< data[b].hcl <<"\n";
        std::cout << "ecl,"<< data[b].ecl <<"\n";
        std::cout << "pid,"<< data[b].pid <<"\n";
        std::cout << "cid,"<< data[b].cid <<"\n";
    }
    std::cout << "\n"
              << valid << " valid passports";
std::cout << "\n"
              << data.size() << " valid passports";
}