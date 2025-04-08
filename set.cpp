#include <iostream>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, int> mp;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        mp[s]++;
        int x = mp[s];
        if (mp[s] > 1)
        {
            v.push_back(s + to_string(x - 1));
        }
        else
            v.push_back(s);
    }
    for (string x : v)
        cout << x << endl;

    return 0;
}