#include <iostream>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <vector>

using namespace std;

class SinhVien
{
private:
    string ten, lop, ns;
    float gpa;
    int ma;

public:
    static int cnt;
    SinhVien();
    friend ostream &operator<<(ostream &, SinhVien);
    friend istream &operator>>(istream &, SinhVien &);
    string chuanHoaNs(SinhVien &);
    string chuanHoaTen(string);
    float getGpa()
    {
        return this->gpa;
    }
    string getName(SinhVien);
};

int SinhVien::cnt = 0;

SinhVien::SinhVien()
{
    ns = ten = lop = "";
    gpa = 0.0;
    ma = 0;
}

istream &operator>>(istream &in, SinhVien &a)
{
    ++SinhVien::cnt;
    a.ma = SinhVien::cnt;
    getline(in, a.ten);
    in >> a.lop;
    in >> a.ns;
    in >> a.gpa;
    in.ignore();

    return in;
}

ostream &operator<<(ostream &out, SinhVien a)
{
    out << "B20DCCN" << setfill('0') << setw(3) << right << a.ma << " ";
    out << a.chuanHoaTen(a.ten) << " " << a.lop << " " << a.chuanHoaNs(a) << " " << fixed << setprecision(2) << a.gpa << endl;
    return out;
}

string SinhVien::chuanHoaNs(SinhVien &a)
{
    if (a.ns[2] != '/')
        a.ns = '0' + a.ns;
    if (a.ns[5] != '/')
        a.ns.insert(3, "0");
    return a.ns;
}

string SinhVien::chuanHoaTen(string a)
{
    string res = "";
    stringstream ss(a);
    string word;
    while (ss >> word)
    {
        res += toupper(word[0]);
        for (int i = 1; i < word.size(); i++)
        {
            res += tolower(word[i]);
        }
        res += " ";
    }
    res.erase(res.length() - 1);
    return res;
}

string SinhVien::getName(SinhVien a)
{
    string res = "";
    stringstream ss(a.ten);
    string token;
    while (ss >> token)
    {
        res = token;
    }
    return res;
}

bool compare(SinhVien a, SinhVien b)
{
    return a.getGpa() > b.getGpa();
}

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    SinhVien ds[50];
    for (int i = 0; i < N; i++)
        cin >> ds[i];
    sort(ds, ds + N, compare);
    for (int i = 0; i < N; i++)
        cout << ds[i];
    return 0;
}
