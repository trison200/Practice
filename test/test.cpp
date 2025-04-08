// todo selection sort

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    cout << "Moi nhap day so ban muon \n";
    for (int &x : arr)
    {
        cin >> x;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] <= arr[min])
            {
                min = j;
            }
        }
        int tmp = arr[min];
        arr[min] = arr[i];
        arr[i] = tmp;
    }
    for (int x : arr)
    {
        cout << x << " ";
    }
}