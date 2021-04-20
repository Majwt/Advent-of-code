#include <iostream>
#include <vector>
#include <string>
#include <fstream>



char tree = '#';

int currentX = 0;
int currentY = 0;
int asum = 0;
int bsum = 0;
int csum = 0;
int dsum = 0;
int esum = 0;

int slope(std::vector<std::string>& printdata, int dx, int dy){

    int x = 0;
    int y = 0;
    int count = 0;

    while(y < printdata.size()) {
        if (printdata[y][x % 31] == tree) {
            count++;
        }

        x += dx;
        y += dy;
    }

    return count;
}

void myFunction(std::vector<std::string>& printdata)
{
    asum = slope(printdata, 1, 1);
    bsum = slope(printdata, 3, 1);
    csum = slope(printdata, 5, 1);
    dsum = slope(printdata, 7, 1);
    esum = slope(printdata, 1, 2);

#if 0

    for (int mode = 1; mode <= 5; mode++)
    {

        for (int i = 0; i < 323; i++)
        {

            switch (mode)
            {
            case 1:

                if (currentX == 30)
                {
                    currentX = 2;
                    //printdata[currentY].at(currentX) = 'A';
                    currentY += 1;
                }
                else if (currentX == 29)
                {
                    currentX = 1;
                    //printdata[currentY].at(currentX) = 'A';
                    currentY += 1;
                }
                else if (currentX == 28)
                {
                    currentX = 0;
                    //printdata[currentY].at(currentX) = 'A';
                    currentY += 1;
                }
                else
                {
                    currentX += 3;
                    //printdata[currentY].at(currentX) = 'A';
                    currentY += 1;
                }
                break;
            case 2:

                if (currentX == 30)
                {
                    currentX = 0;
                    //printdata[currentY].at(currentX) = 'B';
                    currentY += 1;
                }
                else
                {
                    currentX += 1;
                    //printdata[currentY].at(currentX) = 'B';
                    currentY += 1;
                }
                break;
            case 3:
                if (currentX == 30)
                {
                    currentX = 4;
                    //printdata[currentY].at(currentX) = 'C';
                    currentY += 1;
                }
                else if (currentX == 29)
                {
                    currentX = 3;
                    //printdata[currentY].at(currentX) = 'C';
                    currentY += 1;
                }
                else if (currentX == 28)
                {
                    currentX = 2;
                    //printdata[currentY].at(currentX) = 'C';
                    currentY += 1;
                }
                else if (currentX == 27)
                {
                    currentX = 1;
                    //printdata[currentY].at(currentX) = 'C';
                    currentY += 1;
                }
                else if (currentX == 26)
                {
                    currentX = 0;
                    //printdata[currentY].at(currentX) = 'C';
                    currentY += 1;
                }
                else
                {
                    currentX += 5;
                    //printdata[currentY].at(currentX) = 'C';
                    currentY += 1;
                }
                break;
            case 4:
                if (currentX == 30)
                {
                    currentX = 6;
                    //printdata[currentY].at(currentX) = 'D';
                    currentY += 1;
                }
                else if (currentX == 29)
                {
                    currentX = 5;
                    //printdata[currentY].at(currentX) = 'D';
                    currentY += 1;
                }
                else if (currentX == 28)
                {
                    currentX = 4;
                    //printdata[currentY].at(currentX) = 'D';
                    currentY += 1;
                }
                else if (currentX == 27)
                {
                    currentX = 3;
                    //printdata[currentY].at(currentX) = 'D';
                    currentY += 1;
                }
                else if (currentX == 26)
                {
                    currentX = 2;
                    //printdata[currentY].at(currentX) = 'D';
                    currentY += 1;
                }
                else if (currentX == 25)
                {
                    currentX = 1;
                    //printdata[currentY].at(currentX) = 'D';
                    currentY += 1;
                }
                else if (currentX == 24)
                {
                    currentX = 0;
                    //printdata[currentY].at(currentX) = 'D';
                    currentY += 1;
                }
                else
                {
                    currentX += 7;
                    //printdata[currentY].at(currentX) = 'D';
                    currentY += 1;
                }
                break;
            case 5:

                if (currentX == 30)
                {
                    currentX = 0;
                    //printdata[currentY].at(currentX) = 'E';
                    currentY += 2;
                }
                else
                {
                    currentX += 1;
                    //printdata[currentY].at(currentX) = 'E';
                    currentY += 2;
                }
                break;
            default:
                break;
            }

            if (currentX == 0 && currentY == 0)
            {
                printdata[currentY].at(currentX) = 'Y';
            }

            if (currentY > 322)
            {
                if (mode == 5) 
                {
                    break;
                }
                else
                {
                    currentY = 0;
                    currentX = 0;
                }
            }
            if (printdata[currentY].at(currentX) == tree)
            {
                //printdata[currentY].at(currentX) = 'X';
                if (mode == 1)
                {
                    asum++;
                }
                else if (mode == 2)
                {
                    bsum++;
                }
                else if (mode == 3)
                {
                    csum++;
                }
                else if (mode == 4)
                {
                    dsum++;
                }
                else if (mode == 5)
                {
                    esum++;
                }
            }
            else if (printdata[currentY].at(currentX) == '.')
            {
                //data[currentY].at(currentX) = 'O';
            }
        }
    }
    #endif
}

int main()
{
    std::ifstream input{"input.txt"};
    if (!input.is_open())
    {
        return 1;
    }

    std::vector<std::string> lines;

    std::string line;
    while(std::getline(input, line)) {
        lines.push_back(line);
    }
 
    myFunction(lines);


#if 0
    for(auto& line : lines) {
        std::cout << line << "\n";
    }
    #endif

    std::cout << asum;
    std::cout << "\n";
    std::cout << bsum;
    std::cout << "\n";
    std::cout << csum;
    std::cout << "\n";
    std::cout << dsum;
    std::cout << "\n";
    std::cout << esum << "\n";
    std::cout << (1ll * asum * bsum * csum * dsum * esum) << "\n";
}