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
    // if (inString == "cid")
        //  return cid;
}
int count = 0;
void checkpassport(passport &data2)
{

    bool dateValid;
    bool hightValid;
    bool hairColourValid;
    bool eyeColourValid;
    bool idValid;
    std::cout << std::boolalpha;
    if (!data2.byr.empty() &&
        !data2.iyr.empty() &&
        !data2.eyr.empty() &&
        !data2.hgt.empty() &&
        !data2.hcl.empty() &&
        !data2.ecl.empty() &&
        !data2.pid.empty() /*&&
        !data.cid.empty()*/
    )
    {

        int bir = std::stoi(data2.byr, nullptr, 10);
        int exp = std::stoi(data2.eyr, nullptr, 10);
        int isu = std::stoi(data2.iyr, nullptr, 10);
        if ((bir > 1919) && (2003 > bir))
        {
            // std::cout << "birth = correct\n";
            if ((isu > 2009) && (2021 > isu))
            {

            // std::cout << "issue = correct\n";
                if ((exp > 2019) && (2031 > exp))
                {
                // std::cout << "expire = correct\n";
                    dateValid = true;
                }
                else
                {
                // std::cout << "expire = false\n";
                    dateValid = false;
                }
            }
            else
            {
            // std::cout << "issue = false\n";
                dateValid = false;
            }
        }
        else
        {
            // std::cout << "birth = false\n";
            dateValid = false;
        }

        std::string sh(data2.hcl);
        std::smatch mh;
        std::regex eh("^#([a-f\\d]{6})$");
        while (std::regex_search(sh, mh, eh))
        {
            hairColourValid = mh.ready();
            break;
        }

        std::string se(data2.ecl);
        std::smatch me;
        std::regex ee("(amb|blu|brn|gry|grn|hzl|oth)$");
        while (std::regex_search(se, me, ee))
        {
            eyeColourValid = me.ready();
            break;
        }

        std::string si(data2.pid);
        std::smatch mi;
        std::regex ei("^(\\d{9})$");
        while (std::regex_search(si, mi, ei))
        {
            if (si.size() == 9 && mi.ready())
            {
            idValid = true;
            break;
                
            } else {
                idValid = false;
                break;
            }
            
        }

        std::string st(data2.hgt);
        std::smatch mt;
        std::regex et("((1[5-8]\\d|19[0-3])cm)|((59|6\\d|7[0-6])in)$");
        while (std::regex_search(st, mt, et))
        {
            hightValid = mt.ready();
            break;
        }
    }
    //valid++;

    if (hairColourValid &&
        eyeColourValid &&
        dateValid &&
        idValid &&
        hightValid)
    {
        valid++;
        // count++;
        std::cout <<"Passport nr:\t" << count+1 << "\tis Accepted" << "\tNew total:\t" << valid << std::endl; 
    } else {
        std::cout <<"Passport nr:\t" << count+1 << "\tisn't Valid" << std::endl; 
        // std::cout << "\nDateVal: " << dateValid << " = " << data2.byr << ", " << data2.iyr << ", " << data2.eyr << "\n";

        // count++;
    }
        count++;
    
        // std::cout << "\n\n hColour: " << hairColourValid << " = " << data2.hcl << "\n";
        // std::cout << "\n eColour: " << eyeColourValid << " = " << data2.ecl << "\n";
        // std::cout << "\n DateVal: " << dateValid << " = " << data2.byr << ", " << data2.iyr << ", " << data2.eyr << "\n";
        // std::cout << "\tIDvalid: " << idValid << " = " << data2.pid << '\t' << data2.pid.size() << std::endl;
        // std::cout << "\n HightVa: " << hightValid << " = " << data2.hgt << "\n\n";
        // std::cout << "nr: " << count << "\n\n";
        data.push_back(data2);
}

std::vector<std::string> line;
int main()
{

    // std::ifstream input{"d:\\Kod\\Advent of Code\\Dag 4\\example.txt"};
    // std::ifstream input{"d:\\Kod\\Advent of Code\\Dag 4\\example2.txt"};
    std::ifstream input{"..\\input.txt"};
    if (!input.is_open())
    {
        return 1;
    }

    std::string s;

    int pos = 4;
    int checkC[] = {0,0,0,0,0,0,0};
    int temp = 0;
    passport structure;
    while (std::getline(input, s))
    {

        line.push_back(s);
        // std::cout << s << std::endl;
        std::string str = s.substr(0, 3);
        if (s.empty())
        {
            //std::cout << "empty\n";
            checkpassport(structure);
            for (auto &&i : checkC)
            {
                temp += i;
            }

            if (temp == 7) {
                std::cout << temp << std::endl;
                
            } else if(temp > 7) {
                temp = 0;
            }
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
                checkC[0]++;
                structure.byr = s.substr(pos);
                break;
            case iyr:
                checkC[1]++;
                structure.iyr = s.substr(pos);
                break;
            case eyr:
                checkC[2]++;
                structure.eyr = s.substr(pos);
                break;
            case hgt:
                checkC[3]++;
                structure.hgt = s.substr(pos);
                break;
            case hcl:
                checkC[4]++;
                structure.hcl = s.substr(pos);
                break;
            case ecl:
                checkC[5]++;
                structure.ecl = s.substr(pos);
                break;
            case pid:
                checkC[6]++;
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
    // for (size_t b = 0; b < data.size(); b++)
    // {

    //     std::cout << "\n" << data.size() << "\n";
    //     std::cout << "byr,"<< data[b].byr <<"\n";
    //     std::cout << "iyr,"<< data[b].iyr <<"\n";
    //     std::cout << "eyr,"<< data[b].eyr <<"\n";
    //     std::cout << "hgt,"<< data[b].hgt <<"\n";
    //     std::cout << "hcl,"<< data[b].hcl <<"\n";
    //     std::cout << "ecl,"<< data[b].ecl <<"\n";
    //     std::cout << "pid,"<< data[b].pid <<"\n";
    //     std::cout << "cid,"<< data[b].cid <<"\n";
    // }
    std::cout << "\n"
              << valid << " valid passports";
    std::cout << "\n"
              << data.size() << "total passports";
}