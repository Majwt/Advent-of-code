#include <bits/stdc++.h>
using namespace std;

// std::string Path = "..//input.txt";
std::string Path = "..//example.txt"; // andra fil vägen
vector<int> temp{3,8,9,1,2,5,4,6,7};
map<int,int> circle;

struct node
{
    int data;
    struct node* next;
};

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
    void get_time(steady_clock::time_point start, steady_clock::time_point stop, int suff = 1)
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

};



struct node* add_end(struct node* tail,int data) {

    node* temp = new node;
    temp->data = data;
    temp->next = NULL;

    temp->next = tail->next;
    tail->next = temp;
    tail = tail->next;
    return tail;
}

void print(node* tail) {
    node* p = tail->next;
    do
    {
        printf("%d ",p->data);
        p = p->next;
    } while (p!=tail->next);

}

int main()
{
    cout << "h";
    node* tail = new node;
    cout << "o\n";

    tail->data = 3;
    tail->next = tail;
    tail = add_end(tail,8);
    tail = add_end(tail,9);
    tail = add_end(tail,1);
    tail = add_end(tail,2);
    tail = add_end(tail,5);
    tail = add_end(tail,4);
    tail = add_end(tail,6);
    tail = add_end(tail,7);
    print(tail);    
    
    
}


