//todo cach doc,ghi file
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fs;
    fs.open("test.txt");
    if (!fs.is_open())
    {
        return 1;
    }
    
    string name;
    int a;
    getline(fs,name);
    fs>>a;
    cout<<"Name: "<<name<<endl;
    cout<<"so: "<<a;
    fs.close();



    return 0;
}
