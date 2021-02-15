#include <bits/stdc++.h>
#include <chrono>
using namespace std;

// std::string Path = "..//input.txt";
std::string Path = "..//example.txt"; // andra fil vägen
vector<int> circle{3, 8, 9, 1, 2, 5, 4, 6, 7};
// vector<int> circle {3,1,5,6,7,9,8,2,4};
vector<int> holding;
unordered_map<int, int> cache;
int to_int(char i)
{
    string s;
    s += i;
    return stoi(s, nullptr);
}
int mod(int a, int b)
{
    int c = a % b;
    return (c < 0) ? c + b : c;
}
namespace std::chrono
{
    /**
     * @brief Get the time object
     * 
     * @param start start time
     * @param stop stop time
     * @param suff 1 = minuets, 2 = seconds, 3 = milliseconds, 4 = microseconds, 5 = nanoseconds
     */
    void get_time(steady_clock::time_point start, steady_clock::time_point stop,int suff = 1) 
    {
        int64_t t;
        switch (suff)
        {
        case 1:
            
        t = duration_cast<minutes>(stop - start).count();
        cout << t << " min" << endl;
            break;
        case 2:
            
        t = duration_cast<seconds>(stop - start).count();
        cout << t << " s" << endl;
            break;
        case 3:
            
        t = duration_cast<milliseconds>(stop - start).count();
        cout << t << " ms" << endl;
            break;
        case 4:
            
        t = duration_cast<microseconds>(stop - start).count();
        cout << t << " µs" << endl;
            break;
        case 5:
            
        t = duration_cast<nanoseconds>(stop - start).count();
        cout << t << " ns" << endl;
            break;
        
        default:
            break;
        }
        
        
    }

}; // namespace std::chrono

// int mill = 100001
//ger skumt resultat
int mill = 10;
int runs = 10;
void print_c(vector<int> list, int current_cup = 100)
{
    if (current_cup < circle.size())
    {
        for (auto &&q : list)
        {
            (q == list[current_cup]) ? printf("(%d) ", q) : printf("%d ", q);
        }
    }
    else
    {
        for (auto &&q : list)
        {
            printf("%d ", q);
        }
    }
    cout << endl;
}

int find_dest(int in)
{
    int maxs = mill - 1;
    vector<int> temp2;

    if (in == circle.size())
    {
        in--;
    }
    int b = circle.at(mod(in, circle.size()));
    int c = 1;
    temp2 = holding;
    sort(temp2.rbegin(), temp2.rend());
    for (auto &&i : temp2)
    {
        if (i == maxs)
        {
            maxs--;
        }
        if (i == b - c)
        {
            c++;
        }
    }

    int o;
    // b = b - c ? b - c : maxs;

    auto f = cache.find(b - c);
    if (f != cache.end())
    {
        o = cache[f->second - 3] - 2 > 0 ? cache[f->second - 3] - 2 : cache[f->second - 3];
        // cout << cache[f->second-3]-2 << " " << cache[f->second-3] << " " << o << "\n";
    }
    else
    {
        f = cache.find(maxs);
        if (f != cache.end())
        {
            cout << "hello\n";
            cout << f->second-3 << "\n";
            int off = f->second-3;
            o = mod(cache[off], circle.size());
        }
    }

    

    // if (circle.at(i) == b)
    // {
    //     o = i;
    //     break;
    // }

    return o;
}

int erase(int current_cup);

int mainLoop(int runs);

void get_results();
int main()
{

    for (size_t i = 0; i < circle.size(); i++)
    {
        cache[circle[i]] = i;
        // printf("cache[%d] = %d\n", circle[i], i);
    }

    for (size_t i = 10; i != mill; i++)
    {
        circle.push_back(i);
        cache[i] = i;
    }

    cout << endl;
    /** 
     * *MAIN loop
    */
    mainLoop(runs);

    get_results();
}

int mainLoop(int runs)
{
    int current_cup = -1;
    auto s1 = chrono::steady_clock::now();
    chrono::steady_clock::time_point s2;
    for (int i = 0; i <= runs; i++)
    {
        auto o1 = chrono::steady_clock::now();

        printf("ind: %d\t|", i);
        current_cup = mod(current_cup + 1, circle.size());

        /**/cout << "current hand: \n";
        /**/print_c(circle, current_cup);

        current_cup -= erase(current_cup);

        /**/print_c(circle, current_cup);
        /**/print_c(holding);

        int destination = find_dest(current_cup);
        cout << endl;
        for (auto &&j : cache)
        {
            cout << j.first << "\t" << j.second << endl;
        }
        
        /**/printf("\n%d to i: %d\n", circle[current_cup], destination);

        int nextcup = mod(current_cup, circle.size());

        /**/cout << nextcup << endl;

        circle.insert(circle.begin() + destination + 1, holding.begin(), holding.end());
        holding.clear();

        if (destination < current_cup) {
            for (auto &&j : cache)
            {
                j.second += 3;
            }
            
        }

        if (nextcup > destination)
        {
            current_cup += 3;
        }
        /**/print_c(circle, current_cup);

        auto o2 = chrono::steady_clock::now();
        s2 = chrono::steady_clock::now();

        s1 = chrono::steady_clock::now();
        /**/cout << endl;
        get_time(o1,o2,4);
    }
    return 0;
}

int erase(int current_cup)
{

    int offset = 0;
    for (size_t i = 1; i != 4; i++)
    {

        if (mod(current_cup + i, circle.size()) < current_cup)
        {
            offset++;
        }
        holding.push_back(circle.at(mod(current_cup + i, circle.size())));
    }

    for (size_t i = 0; i < holding.size(); i++)
    {
        /* code */
        auto j = cache.find(holding[i]);
        cout << j->second << endl;
        // --(++j->second);
    }
        circle.erase(circle.begin()+mod(current_cup+1,circle.size()));
        circle.erase(circle.begin()+mod(current_cup+1,circle.size()));
        circle.erase(circle.begin()+mod(current_cup+1,circle.size()));
    // for (auto &&i : cache)
    // {
    //     i.second -= offset;
    // }

    return offset;
}

void get_results()
{
    cout << "---Final---" << endl;
    cout << circle.size() << endl;
    int ones;
    for (size_t i = 0; i < circle.size(); i++)
    {
        if (circle[i] == 1)
        {
            ones = i;
        }
        if (i % 15 == 0)
        {
            cout << endl;
        }
        cout << circle[i] << " ";
    }

    int first = circle[mod(ones + 1, circle.size())];
    int second = circle[mod(ones + 2, circle.size())];
    long long resu = (long long)first * (long long)second;
    printf("\n---Output---\n%d * %d = %lld", first, second, resu);
}