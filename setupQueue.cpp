#include <iostream>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

typedef struct Node *node;

bool empty(node back)
{
    return back == NULL;
}

int getSize(node back)
{
    int cnt = 0;
    while (back != NULL)
    {
        cnt++;
        back = back->next;
    }
    return cnt;
}

node makeNode(int x)
{
    node tmp = new Node();
    tmp->next = NULL;
    tmp->data = x;
    return tmp;
}

void push(node &back, int x)
{
    node tmp = makeNode(x);
    tmp->next = back;
    back = tmp;
}

void pop(node &back)
{
    if (back == NULL)
        return;
    if (getSize(back) == 1)
    {
        back = NULL;
        return;
    }
    node p = back;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    p->next = NULL;
}

int front(node back)
{
    while (back->next != NULL)
    {
        back = back->next;
    }
    return back->data;
}

int main()
{
    node back = NULL;
    push(back, 6);
    push(back, 8);
    vector<int> lp;
    while (1)
    {
        int top = front(back);
        pop(back);
        string s = to_string(top);
        if (s.size() == 8)
            break;
        lp.push_back(top);
        push(back, top * 10 + 6);
        push(back, top * 10 + 8);
    }
    for (int x : lp)
    {
        cout << x << " ";
    }
    return 0;
}