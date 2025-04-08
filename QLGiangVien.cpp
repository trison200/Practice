#include <iostream>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <vector>

using namespace std;

class GiangVien
{
private:
    int ma;
    string ten, mon;

public:
    static int cnt;
    GiangVien();
    friend ostream &operator<<(ostream &, GiangVien);
    friend istream &operator>>(istream &, GiangVien &);
    string getName(GiangVien);
    string chuanHoaMon(GiangVien);
    int getMa()
    {
        return this->ma;
    }
    bool checkMon(string str)
    {
        return this->mon == str;
    }
    string getTen()
    {
        return this->ten;
    }
};

int GiangVien::cnt = 0;

GiangVien::GiangVien()
{
    ten = mon = "";
    ma = 0;
}

string GiangVien::chuanHoaMon(GiangVien a)
{
    string res = "";
    stringstream ss(a.mon);
    string token;
    while (ss >> token)
    {
        res += toupper(token[0]);
    }
    return res;
}

istream &operator>>(istream &in, GiangVien &a)
{
    ++GiangVien::cnt;
    a.ma = GiangVien::cnt;
    getline(in, a.ten);
    getline(in, a.mon);
    return in;
}

ostream &operator<<(ostream &out, GiangVien a)
{
    out << "GV" << setfill('0') << setw(2) << right << a.ma << " " << a.ten << " " << a.chuanHoaMon(a) << endl;
    return out;
}

string GiangVien::getName(GiangVien a)
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

bool cmp(GiangVien a, GiangVien b)
{
    if (a.getName(a) == b.getName(b))
        return a.getMa() < b.getMa();
    return a.getName(a) < b.getName(b);
}

string chuan(string str)
{
    string res = "";
    stringstream ss(str);
    string token;
    while (ss >> token)
    {
        res += toupper(token[0]);
    }
    return res;
}

bool checkTen(string str, string str_finded)
{
    for (char &x : str)
        x = tolower(x);
    for (char &x : str_finded)
        x = tolower(x);
    return str.find(str_finded) != string::npos;
}

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    GiangVien ds[50];
    for (int i = 0; i < N; i++)
        cin >> ds[i];
    int Q;
    cin >> Q;
    cin.ignore();
    while (Q--)
    {
        string s;
        cin >> s;
        cin.ignore();
        cout << "DANH SACH GIANG VIEN BO MON THEO TU KHOA " << s << ":\n";
        for (int i = 0; i < N; i++)
        {
            if (checkTen(ds[i].getTen(), s))
            {
                cout << ds[i];
            }
        }
    }
    return 0;
}
