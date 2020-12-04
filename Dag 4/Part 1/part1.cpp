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
int valid = 0;
std::vector<std::string> clines;
std::vector<passport> data;
std::vector<passport> invalid;
int findSmallestElement(int arr[], int n)
{
    /* We are assigning the first array element to
    * the temp variable and then we are comparing
    * all the array elements with the temp inside
    * loop and if the element is smaller than temp
    * then the temp value is replaced by that. This
    * way we always have the smallest value in temp.
    * Finally we are returning temp.
    */
    int temp = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (temp > arr[i])
        {
            temp = arr[i];
        }
    }
    return temp;
}
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
int checkC[]{
    0, // 0 byr, 1 iyr, 2 eyr, 3 hgt, 4 hcl, 5 ecl, 6 pid, 7 cid
    0, // iyr
    0, // eyr
    0, // hgt
    0, // hcl
    0, // ecl
    0  // pid
       // cid
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

void checkpassport(passport &data)
{
    if (data.byr.empty())
            {
            }
            else if (data.iyr.empty())
            {
            }
            else if (data.eyr.empty())
            {
                
            }
            else if (data.hgt.empty())
            {
            }
            else if (data.hcl.empty())
            {
            }
            else if (data.ecl.empty())
            {
            }
            else if (data.pid.empty())
            {
            } else {
                valid++;
            }
}
        // int birth = std::stoi(data.byr, nullptr, 10);
        // int expire = std::stoi(data.eyr, nullptr, 10);
        // int issue = std::stoi(data.iyr, nullptr, 10);

int main()
{

    std::ifstream input{"d:\\Kod\\Advent of Code\\Dag 4\\example.txt"};
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
            data.push_back(structure);
        }
        else
        {
            std::cout << "\n"<< s;
            std::string str = s.substr(0, 3);
            if (str == "byr") {
                if (!s.substr(pos).empty())
                {
                structure.byr = s.substr(pos);
                }
            } else if (str == "iyr") {
                if (!s.substr(pos).empty())
                {
                structure.iyr = s.substr(pos);
                } else
                {
                    structure.iyr = "";
                }
            } else if (str == "eyr") {
                if (!s.substr(pos).empty()) 
                {
                structure.eyr = s.substr(pos);
                } else
                {
                    structure.eyr = "";
                }
            } else if (str == "hgt") {
                if (!s.substr(pos).empty()) 
                {
                structure.hgt = s.substr(pos);
                } else
                {
                    structure.hgt = "";
                }
            } else if (str == "hcl") {
                if (!s.substr(pos).empty()) 
                {
                structure.hcl = s.substr(pos);
                } else
                {
                    structure.hcl = "";
                }
            } else if (str == "ecl") {
                if (!s.substr(pos).empty()) 
                {
                structure.ecl = s.substr(pos);
                } else
                {
                    structure.ecl = "";
                }
            } else if (str == "pid") {
                if (!s.substr(pos).empty()) 
                {
                structure.pid = s.substr(pos);
                } else
                {
                    structure.pid = "";
                }
                
            }
            /*
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
        */}
        
    }
    for (size_t b = 0; b < data.size(); b++)
    {
        checkpassport(data[b]);
        std::cout << "\n"
                  << "\n";
        std::cout << data[b].byr << " byr data \n";
        std::cout << data[b].iyr << " iyr data \n";
        std::cout << data[b].eyr << " eyr data \n";
        std::cout << data[b].hgt << " hgt data \n";
        std::cout << data[b].hcl << " hcl data \n";
        std::cout << data[b].ecl << " ecl data \n";
        std::cout << data[b].pid << " pid data \n";
        std::cout << data[b].cid << " cid data \n";
    }
    std::cout << "\n"
              << valid << " valid passports";
}