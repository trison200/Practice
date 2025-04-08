#include <iostream>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <vector>

using namespace std;

struct Student
{
    string name, id;
    float gpa;
};

struct SV
{
    Student s;
    SV *next;
};

SV *makeSV(Student x)
{
    cout << "Nhap thong tin sinh vien:\n";
    cout << "Nhap ten:";
    getline(cin, x.name);
    cout << "Nhap id:";
    std::cin >> x.id;
    std::cin.ignore();
    cout << "Nhap gpa:";
    std::cin >> x.gpa;
    cin.ignore();
    SV *tmp = new SV();
    tmp->next = NULL;
    tmp->s = x;
    return tmp;
}

bool empty(SV *head)
{
    return head == NULL;
}

int size(SV *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

void insertFirst(SV *&head, Student x)
{
    SV *tmp = makeSV(x);
    if (head == NULL)
    {
        head = tmp;
        return;
    }
    tmp->next = head;
    head = tmp;
}

void insertLast(SV *&head, Student x)
{
    SV *tmp = makeSV(x);
    if (head == NULL)
    {
        head = tmp;
        return;
    }
    SV *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = tmp;
}

void insertMiddle(SV *&head, Student x, int pos)
{
    int n = size(head);
    if (pos == 0)
    {
        insertFirst(head, x);
        return;
    }
    else if (pos == n + 1)
    {
        insertLast(head, x);
        return;
    }
    else if (pos < 0 || pos > n)
    {
        cout << "Vi tri khong hop le!\n";
        return;
    }
    SV *tmp = makeSV(x);
    SV *p = head;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
    }
    tmp->next = p->next;
    p->next = tmp;
}

void deleteFirst(SV *&head)
{
    if (head == NULL)
        return;
    head = head->next;
}

void deleteLast(SV *&head)
{
    if (head == NULL)
        return;
    if (size(head) == 1)
    {
        head = NULL;
    }
    SV *p = head;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    p->next = NULL;
}

void deleteMiddle(SV *&head, int pos)
{
    if (pos <= 0 || pos > size(head))
        return;
    SV *before = NULL;
    SV *after = head;
    for (int i = 0; i < pos - 1; i++)
    {
        before = after;
        after = after->next;
    }
    if (before == NULL)
        head = head->next;
    before->next = after->next;
}

void in(SV *head)
{
    cout << "--------------------------------------\n";
    while (head != NULL)
    {
        cout << head->s.name << " " << head->s.id << " " << head->s.gpa << endl;
        head = head->next;
    }
    cout << endl;
    cout << "--------------------------------------\n";
}

void sapxep(SV *&head)
{
    for (SV *p = head; p->next != NULL; p = p->next)
    {
        SV *min = p;
        for (SV *q = p->next; q != NULL; q = q->next)
        {
            if (q->s.gpa < min->s.gpa)
            {
                min = q;
            }
        }
        Student tmp = min->s;
        min->s = p->s;
        p->s = tmp;
    }
}

int main()
{
    SV *head = NULL;
    while (1)
    {
        cout << "------------------MENU-----------------\n";
        cout << "1. Chen 1 phan tu vao dau danh sach\n";
        cout << "2. Chen 1 phan tu vao cuoi danh sach\n";
        cout << "3. Chen 1 phan tu vao giua danh sach\n";
        cout << "4. Xoa 1 phan tu o dau danh sach\n";
        cout << "5. Xoa 1 phan tu o cuoi danh sach\n";
        cout << "6. Xoa 1 phan tu o giua danh sach\n";
        cout << "7. In danh sach\n";
        cout << "8.Thoat \n";
        cout << "9.Sap xep cac phan tu trong danh sach\n";
        cout << "--------------------------------------\n";
        cout << "Nhap lua chon :\n";
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 1)
        {
            Student s;
            insertFirst(head, s);
        }
        else if (choice == 2)
        {
            Student s;
            insertLast(head, s);
        }
        else if (choice == 3)
        {
            Student s;
            cout << "Nhap vi tri can chen\n";
            int x;
            cin >> x;
            cin.ignore();
            insertMiddle(head, s, x);
        }
        else if (choice == 4)
            deleteFirst(head);
        else if (choice == 5)
            deleteLast(head);
        else if (choice == 6)
        {
            cout << "Nhap vi tri can xoa\n";
            int pos;
            cin >> pos;
            cin.ignore();
            deleteMiddle(head, pos);
        }
        else if (choice == 7)
            in(head);
        else if (choice == 8)
            break;
        else if (choice == 9)
            sapxep(head);
    }
    return 0;
}
