#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[10];
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    stack<int> st;
    int i = 0;
    while (i < n)
    {
        if (st.empty() || a[st.top()] <= a[i])
        {
            st.push(i);
            i++;
        }
        else
        {
            int tmp = st.top();
            st.pop();
            if (!st.empty())
                res = max(res, a[tmp] * (i - st.top() - 1));
            else
                res = max(res, a[tmp] * i);
        }
    }
    while (!st.empty())
    {
        int tmp = st.top();
        st.pop();
        if (!st.empty())
            res = max(res, a[tmp] * (i - st.top() - 1));
        else
            res = max(res, a[tmp] * i);
    }
    cout << res;
    return 0;
}