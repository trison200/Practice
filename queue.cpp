#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <utility>

using namespace std;

// int convert(int s, int t)
// {
//     queue<pair<int, int>> q;
//     set<int> se;
//     q.push({s, 0});
//     se.insert(s);
//     while (!q.empty())
//     {
//         pair<int, int> tmp = q.front();
//         q.pop();
//         if (tmp.first * 2 == t || tmp.first - 1 == t)
//         {
//             return tmp.second + 1;
//         }
//         if (tmp.first > 0 && se.find(tmp.first - 1) == se.end())
//         {
//             q.push({tmp.first - 1, tmp.second + 1});
//             se.insert(tmp.first - 1);
//         }
//         if (tmp.first < t && se.find(tmp.first * 2) == se.end() && tmp.first > 0)
//         {
//             q.push({tmp.first * 2, tmp.second + 1});
//             se.insert(tmp.first * 2);
//         }
//     }
// }

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.pop();
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}