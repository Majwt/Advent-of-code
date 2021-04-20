#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>

std::string line;
int output[851];
int biggest;

int myFunction(std::string l)
{
    int i = 0;
    long long num = 0;
    int arr[10] = {};

    while (i < 10)
    {

        if (l.at(i) == 'B')
        {
            arr[i] = 1;
        }
        else if (l.at(i) == 'F')
        {
            arr[i] = 0;
        }
        else if (l.at(i) == 'L')
        {
            arr[i] = 0;
        }
        else if (l.at(i) == 'R')
        {
            arr[i] = 1;
        }

        i++;
    }

    num += (arr[0] * 0b10000000);
    num += (arr[1] * 0b1000000);
    num += (arr[2] * 0b100000);
    num += (arr[3] * 0b10000);
    num += (arr[4] * 0b1000);
    num += (arr[5] * 0b100);
    num += (arr[6] * 0b10);
    int num2 = (arr[7] * 0b100) + (arr[8] * 0b10) + (arr[9] * 0b1);
    num /= 2;
    std::cout << " row: " << num << "  coloum: " << num2 << " id: " << (num * 8) + num2 << "\n";
    return (num * 8) + num2;
}
int main()
{

    std::ifstream input;
    input.open("input.txt");
    if (!input.is_open())
    {
        return 1;
    }
    int counter = 0;
    while (getline(input, line))
    {
        std::cout << line << '\n';
        output[counter] = myFunction(line);
        counter++;
    }

    int h = sizeof(output) / sizeof(output[0]);

    std::sort(output, output + 851);
    for (size_t k = 0; k < 852; k++)
    {
        if (output[k] - output[k - 1] == 1 && output[k] > 0)
        {

            std::cout << output[k] << "\n";
        }
        else
        {
            std::cout << " THIS ONE HERE" << output[k] - 1 << "\n";
            std::cout << output[k] << "\n";
        }
    }
}