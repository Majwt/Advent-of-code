#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <regex>
#include <sstream>

using namespace std;

string Path = "..//input.txt";
// std::string Path = "..//example.txt"; // andra fil vägen

struct pass
{
    int birthYear;
    int issueYear;
    int expireYear;

    string hight;
    string eyeColour;
    string hairColour;
    string passId;
    bool hightcheck = false;
    bool eyecheck = false;
    bool haircheck = false;
    bool passIdcheck = false;
    bool birthcheck = false;
    bool issuecheck = false;
    bool expirecheck = false;

    void addBirth(string str)
    {
        int birth = std::stoi(str, nullptr, 10);
        if (birth > 1919 && 2003 > birth)
        {
            birthYear = birth;
            birthcheck = true;
        }
    }
    void addIssue(string str)
    {

        int issue = std::stoi(str, nullptr, 10);
        if (issue > 2009 && 2021 > issue)
        {
            issueYear = issue;
            issuecheck = true;
        }
    }
    void addExpire(string str)
    {
        int expire = std::stoi(str, nullptr, 10);
        if (expire > 2019 && 2031 > expire)
        {
            expireYear = expire;
            expirecheck = true;
        }
    }
    void addHight(string hgt)
    {
        regex reg("(((1[5-8][0-9]|19[0-3])cm)|((59|6[0-9]|7[0-6])in))(\\s|$)");
        smatch match;
        while (regex_search(hgt, match, reg))
        {
            hightcheck = true;
            hight = hgt;
        }
    }
    void addHair(string hair)
    {
        regex reg("#[0-9a-f]{6}(\\s|$)");
        smatch match;
        while (regex_search(hair, match, reg))
        {
            haircheck = true;
            hairColour = hair;
        }
    }
    void addeye(string str)
    {
        regex reg("(amb|blu|brn|gry|grn|hzl|oth)(\\s|$)");
        smatch match;
        while (regex_search(str, match, reg))
        {
            eyecheck = true;
            eyeColour = str;
        }
    }
    void addId(string str)
    {
        regex reg("([0-9]{9})(\\s|$)");
        smatch match;
        while (regex_search(str, match, reg))
        {
            passIdcheck = true;
            passId = str;
            cout << "id \n";
        }
    }
    bool checkall()
    {
        if (hightcheck &&
            eyecheck &&
            haircheck &&
            passIdcheck &&
            birthcheck &&
            issuecheck &&
            expirecheck)
        {
            return true;
        }
    }
};
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
    //     return cid;
}
std::vector<pass> data;
vector<string> line;
int valid = 0;
int main()
{

    std::ifstream input;
    input.open(Path);
    if (!input.is_open())
    {
        std::cout << "not found or could not open\n";
        return 1;
    }

    string s;

    int pos = 4;

    
    while (getline(input, s))
    {
pass structure;
        //std::cout << s << "\n";
        string str = s.substr(0, 3);
        if (s.empty())
        {
            if (structure.checkall())
            {
                valid++;
            }
            data.push_back(structure);
        }
        else
        {

            switch (hashit(str))
            {
            case byr:
                // checkC[0]++;
                structure.addBirth(s.substr(pos));
                break;
            case iyr:
                // checkC[1]++;
                structure.addIssue(s.substr(pos));
                break;
            case eyr:
                // checkC[2]++;
                structure.addExpire(s.substr(pos));
                break;
            case hgt:
                // checkC[3]++;
                structure.addHight(s.substr(pos));
                break;
            case hcl:
                // checkC[4]++;
                structure.addHair(s.substr(pos));
                break;
            case ecl:
                // checkC[5]++;
                structure.addeye(s.substr(pos));
                break;
            case pid:
                // checkC[6]++;
                structure.addId(s.substr(pos));
                break;

            default:
                break;
            }
        }
    }
    for (size_t i = 0; i < 10; i++)
    {
        cout << "\n"
             << line[i] << "\n";
    }
}