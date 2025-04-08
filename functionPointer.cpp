#include <iostream>

using namespace std;

bool isEven(int a) { return (a & 1) == 0; }

void print(bool (*notOdd)(int), int y)
{
    if (notOdd(y))
    {
        cout << "Even";
    }
    else
    {
        cout << "Odd";
    }
}

int main()
{
    bool (*hai)(int) = isEven;
    print(hai, 92);
}