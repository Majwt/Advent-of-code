#include <bits/stdc++.h>
using namespace std;

// std::string Path = "..//input.txt";
std::string Path = "..//example.txt"; // andra fil vägen
vector<int> temp{3, 8, 9, 1, 2, 5, 4, 6, 7};
map<int, int> circle;

struct node
{
    int data;
    struct node *next;
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
    return (c <= 0) ? c + b : c;
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
    void get_timeDiff(steady_clock::time_point start, steady_clock::time_point stop, int suff = 1)
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

struct node *add_end(struct node *tail, int data)
{

    node *temp = new node;
    temp->data = data;
    temp->next = NULL;

    temp->next = tail->next;
    tail->next = temp;
    tail = tail->next;
    return tail;
}

void print(node *tail, int current = 0)
{
    node *p = tail->next;
    do
    {
        if (p == tail->next)
        {
            (p->data == current) ? printf("(%d)", p->data) : printf("%d ", p->data);
        }
        else
        {
            (p->data == current) ? printf("(%d)", p->data) : printf(" %d ", p->data);
        }
        p = p->next;
    } while (p != tail->next);
    cout << endl;
}

struct node *insertAfter(node *last, int new_data, int after_item)
{
    //return null if list is empty
    if (last == NULL)
        return NULL;
    after_item = mod(after_item, 10);
    node *temp, *p;
    p = last->next;

    do
    {
        if (p->data == after_item)
        {
            temp = new node;
            temp->data = new_data;
            temp->next = p->next;
            p->next = temp;

            if (p == last)
                last = temp;
            // printf("destination: %d\n", after_item);
            return last;
        }
        p = p->next;
    } while (p != last->next);
    // cout << "The node with data " << after_item << " is not present in the list." << endl;

    return insertAfter(last, new_data, after_item - 1);
}

vector<int> arr;
int deleteNode(node *head, int key)
{

    // If linked list is empty
    if (head == NULL)
        return -1;

    // If the list contains only a single node
    if (head->data == key && head->next == head)
    {
        free(head);
        head = NULL;
        return -1;
    }

    node *last = head, *d;

    // If head is to be deleted
    if (head->data == key)
    {
        cout << "head == key\t" << head->data << endl;
        // Find the last node of the list
        // while (last->next != head)
        //     last = last->next;

        // Point last node to the next of head i.e.
        // the second node of the list
        last->next = head->next;
        int o = head->data;
        free(head);
        head = last->next;
        return o;
    }

    // Either the node to be deleted is not found
    // or the end of list is not reached
    // while (last->next != head && last->next->data != key)
    // {
    //     last = last->next;
    // }

    // If node to be deleted was found
    if (last->next->data == key)
    {

        d = last->next;
        last->next = d->next;
        int o = d->data;
        free(d);

        return o;
    }
    else
    {

        cout << "no such keyfound";
        return -1;
    }
}

int main()
{
    // vector<int> input = {3,1,5,6,7,9,8,2,4};
    vector<int> input = {3,8,9,1,2,5,4,6,7};
    cout << "h";
    node *tail = new node;
    cout << "o\n";
    tail->data = input[0];
    tail->next = tail;
    node *curr = tail;
    for (size_t i = 1; i < input.size(); i++)
    {
    tail = add_end(tail, input[i]);

    }

    for (size_t i = input.size(); i < 1000000; i++)
    {
        tail = add_end(tail, i);
    }
    
    

    for (size_t i = 0; i < 10; i++)
    {
        /* code */

        printf("circle | %d | curr = %d\n", i, curr->data);
        // print(curr, curr->data);
        // cout << curr->data << endl;
        auto o1 = chrono::steady_clock::now();
        int dataTemp = curr->data;
        vector<int> deled;
        deled = {};
        cout << "cups: ";
        // print(curr, curr->data);
        for (size_t k = 0; k < 3; k++)
        {
            int de = deleteNode(curr, curr->next->data);
            deled.push_back(de);
        }
        // printf("holding: ");
        // for (auto &&j : deled)
        // {
        //     printf("%d ", j);
        // }
        // printf("\ndest pre: %d\n", dataTemp - 1);
        node *t = curr->next;
        insertAfter(curr, deled[0], dataTemp - 1);
        insertAfter(curr, deled[1], deled[0]);
        insertAfter(curr, deled[2], deled[1]);
        // print(curr, dataTemp);
        curr = t;
        auto o2 = chrono::steady_clock::now();
        get_timeDiff(o1,o2,3);
        // cout << endl;
    }

    print(curr, 1);

    long long s1;
    long long s2;
    node *p = curr->next;
    do
    {
        if (p->data == 1) {

        printf(" ");
        s1 = p->next->data;
        s2 = p->next->next->data;
        } else {
        printf("%d", p->data);

        }
        p = p->next;
    } while (p != curr->next);
        printf("\n\t%d\n*\t%d\n=\n%d\n",s1,s2,(s1*s2));
    cout << endl;
}
