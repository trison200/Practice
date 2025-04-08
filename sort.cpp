#include <iostream>
#include <vector>
#include <cstdlib> // rand(), srand()
#include <ctime>   // time()

using namespace std;

void insertionSort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = a[i], pos = i - 1;
        while (pos >= 0 && a[pos] > x)
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
    }
}

void shellSort(int *a, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int tmp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > tmp; j -= gap)
            {
                a[j] = a[j - gap];
            }
            a[j] = tmp;
        }
    }
}

int merge(int *a, int l, int m, int r)
{
    vector<int> x(a + l, a + m + 1);
    vector<int> y(a + m + 1, a + r + 1);
    int i = 0, j = 0;
    int cnt = 0;
    while (i < x.size() && j < y.size())
    {
        if (x[i] <= y[j])
        {
            a[l] = x[i];
            i++;
            l++;
        }
        else
        {
            cnt += x.size() - i;
            a[l] = y[j];
            j++;
            l++;
        }
    }
    while (i < x.size())
    {
        a[l] = x[i];
        i++;
        l++;
    }
    while (j < y.size())
    {
        a[l] = y[j];
        j++;
        l++;
    }
    return cnt;
}

int mergeSort(int *a, int l, int r)
{
    int dem = 0;
    if (l < r)
    {
        int m = (l + r) / 2;
        dem += mergeSort(a, l, m);
        dem += mergeSort(a, m + 1, r);
        dem += merge(a, l, m, r);
    }
    return dem;
}

// left-index = 2i + 1
// right-index = 2i + 2

void heapify(int *a, int n, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l < n && a[l] > a[largest])
    {
        largest = l;
    }
    if (r < n && a[r] > a[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(a[largest], a[i]);
        heapify(a, n, largest);
    }
}

void heapSort(int *a, int n)
{
    // build max-heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    // push back root node to a[]
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int partition(int *a, int l, int r)
{
    int x = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (a[j] < x)
        {
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

int partition2(int *a, int l, int r)
{
    int pivot = a[l];
    int i = l - 1;
    int j = r + 1;
    while (true)
    {
        do
        {
            ++i;
        } while (a[i] < pivot);
        do
        {
            --j;
        } while (a[j] > pivot);
        if (i < j)
        {
            swap(a[i], a[j]);
        }
        else
        {
            return j;
        }
    }
}

void quickSort(int *a, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int q = partition2(a, l, r);
    quickSort(a, l, q);
    quickSort(a, q + 1, r);
}

int main()
{
    int n = 100;
    int a[100];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = 1 + rand() % 1000;
    }
    quickSort(a, 0, n - 1);
    for (int x : a)
    {
        cout << x << " ";
    }
    return 0;
}