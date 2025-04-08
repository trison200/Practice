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
    Node *prev;
    Node *next;
};

Node *makeNode(int x)
{
    Node *newNode = new Node();
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = x;
    return newNode;
}

void duyet(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int getSize(Node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

void themdau(Node *&head, int x)
{
    Node *newNode = makeNode(x);
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

void themcuoi(Node **head, int x)
{
    Node *newNode = makeNode(x);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *tmp = *head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    newNode->prev = tmp;
}

void themgiua(Node *&head, int x, int pos)
{
    int n = getSize(head);
    if (pos < 1 || pos > n + 1)
        return;
    if (pos == 1)
    {
        themdau(head, x);
        return;
    }
    Node *tmp = head;
    for (int i = 1; i < pos; i++)
    {
        tmp = tmp->next;
    }
    Node *newNode = makeNode(x);
    newNode->next = tmp;
    tmp->prev->next = newNode;
    newNode->prev = tmp->prev;
    tmp->prev = newNode;
}

int main()
{
    Node *head = NULL;
    while (1)
    {
        cout << "-------------DSLK--------\n ";
        cout << "1. Them node vao dau\n";
        cout << "2. Them node vao cuoi\n";
        cout << "3. Them node vao giua\n";
        cout << "4. Duyet\n";
        cout << "5. Thoat !\n";
        cout << "--------------------------\n ";
        cout << "Nhap lua chon :";
        int lc;
        cin >> lc;
        if (lc == 1)
        {
            int x;
            cout << "Nhap x : ";
            cin >> x;
            themdau(head, x);
        }
        else if (lc == 2)
        {
            int x;
            cout << "Nhap x : ";
            cin >> x;
            themcuoi(&head, x);
        }
        else if (lc == 3)
        {
            int x;
            cout << "Nhap x : ";
            cin >> x;
            int k;
            cout << "Nhap vi tri chen:";
            cin >> k;
            themgiua(head, x, k);
        }
        else if (lc == 4)
        {
            duyet(head);
        }
        else
        {
            break;
        }
    }
    return 0;
}