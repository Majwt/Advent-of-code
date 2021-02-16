#include <bits/stdc++.h>
using namespace std;

/**
 * https://github.com/frerich/aoc2020/blob/main/day23.py
 * https://www.reddit.com/r/adventofcode/comments/kimluc/2020_day_23_solutions/gh6rs11?utm_source=share&utm_medium=web2x&context=3
 */

const int Million = 1000000;

vector<int> successors (Million);
vector<int> puzzleInput = {3, 1, 5, 6, 7, 9, 8, 2, 4};
// vector<int> puzzleInput = {3, 8, 9, 1, 2, 5, 4, 6, 7};
int startCup;
int flytta(int current)
{
    int p0 = successors[current];
    int p1 = successors[p0];
    int p2 = successors[p1];
    int next = successors[p2];
    int destcup = current - 1;
    while (true)
    {
        if (destcup < 1)
        {
            vector<int>::iterator ms;
            ms = max_element(successors.begin(), successors.end());

            destcup = *ms;
        }
        if (destcup != p0 && destcup != p1 && destcup != p2)
        {
            break;
        }
        destcup -= 1;
    }
    successors[current] = next;
    successors[p2] = successors[destcup];
    successors[destcup] = p0;
    return next;
}

int myfunc() {
    startCup = puzzleInput[0];
    for (size_t i = 0; i < puzzleInput.size() - 1; i++)
    {
        successors[puzzleInput[i]] = puzzleInput[i + 1];
    }
    vector<int>::iterator ms = max_element(successors.begin(), successors.end());

    iota(successors.begin()+*ms+1, successors.end(), *ms+2);
    successors[puzzleInput[8]] = *ms + 1;
    successors[Million] = puzzleInput[0];
    return startCup;

}
int main()
{

    int current = myfunc();

    for (size_t i = 0; i != Million * 10; i++)
    {
        
        current = flytta(current);   
    }
    long long res = (long long)successors[1] * successors[successors[1]];
    printf("Resultat: %d * %d = %lld",successors[1],successors[successors[1]],res);
}