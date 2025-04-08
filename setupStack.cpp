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
    string data;
    Node *next;
};

typedef struct Node *node;

bool empty(node top)
{
    return top == NULL;
}

int getSize(node top)
{
    int cnt;
    while (top != NULL)
    {
        top = top->next;
        cnt++;
    }
    return cnt;
}

node makeNode(string x)
{
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

void push(node &top, string x)
{
    node tmp = makeNode(x);
    if (empty(top))
    {
        top = tmp;
        return;
    }
    tmp->next = top;
    top = tmp;
}

void pop(node &top)
{
    if (top == NULL)
        return;
    top = top->next;
}

string getTop(node top)
{
    if (top == NULL)
        cout << "danh sach rong\n";
    return top->data;
}

int main()
{
    node top = NULL;
    string str;
    getline(cin, str);
    stringstream ss(str);
    string token;
    while (ss >> token)
    {
        push(top, token);
    }
    while (!empty(top))
    {
        cout << getTop(top) << " ";
        pop(top);
    }

    return 0;
}