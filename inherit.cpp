#include <iostream>

using namespace std;

class A
{
public:
    A()
    {
        cout << "constructor cua lop A\n";
    }
    ~A()
    {
        cout << "Destructor cua lop A\n";
    }
    void in()
    {
        cout << "Xin chao A\n";
    }
};

class B
{
public:
    B()
    {
        cout << "constructor cua lop B\n";
    }
    ~B()
    {
        cout << "Destructor cua lop B\n";
    }
    void in()
    {
        cout << "Xin chao B\n";
    }
};

class C : public A, public B
{
public:
    C()
    {
        cout << "constructor cua lop C\n";
    }
    ~C()
    {
        cout << "Destructor cua lop C\n";
    }
    void in()
    {
        cout << "Xin chao C\n";
    }
};

int main()
{
    C obj;
    obj.in();
}