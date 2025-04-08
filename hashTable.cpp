#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int hashFunction(int key, int capacity)
{
    return key % capacity;
}

template <class K, class V>
class XHashMap
{
public:
    class Entry
    {
    public:
        K key;
        V value;
        Entry *next;

        Entry(K key, V value, Entry *next = 0)
        {
            this->key = key;
            this->value = value;
            this->next = next;
        }
    };

private:
    Entry **table; // hash table
    int capacity;  // size for the hash table
    int count;

public:
    // Constructor
    XHashMap()
    {
        this->capacity = 10;
        this->count = 0;
        table = new Entry *[capacity];
        // reset table to 0
        for (int i = 0; i < capacity; i++)
        {
            table[i] = 0;
        }
    }

    ~XHashMap()
    { // Destructor
        // Remove all entries in the current map
        for (int idx = 0; idx < this->capacity; idx++)
        {
            Entry *entry = this->table[idx];
            while (entry != 0)
            {
                Entry *next = entry->next;
                delete entry;
                entry = next;
            }
        }
        // Remove table
        delete[] table;
    }

    // YOUR ANSWER

    // print table method (for testing)
    void printTable() const
    {

        cout << "------------The hash table is shown below------------\n";
        for (int i = 0; i < capacity; i++)
        {
            Entry *entry = table[i];
            cout << "Index " << i << ": ";
            while (entry != 0)
            {
                cout << "(" << entry->key << ", " << entry->value << ") ";
                entry = entry->next;
            }
            cout << endl;
        }
        cout << "-----------------------------------------------------\n";
    }
    void put(int, int);
    void ensureLoadFactor(int current_size);
    void rehash(int newCapacity);
    V &get(int key);
    V remove(int key);
};

template <class K, class V>
void XHashMap<K, V>::put(int key, int value)
{
    int index = hashFunction(key, capacity);
    Entry *current = table[index];
    while (current != NULL)
    {
        if (current->key == key)
        {
            current->value = value;
            return;
        }
        current = current->next;
    }
    Entry *newEntry = new Entry(key, value, table[index]);
    table[index] = newEntry;
    this->count++;
    ensureLoadFactor(count);
}

template <class K, class V>
void XHashMap<K, V>::ensureLoadFactor(int current_size)
{
    float loadFactor = 0.75;
    int maxAllowed = loadFactor * capacity;
    if (current_size >= maxAllowed)
    {
        int newCapacity = capacity * 1.5;
        rehash(newCapacity);
    }
}

template <class K, class V>
void XHashMap<K, V>::rehash(int newCapacity)
{
    int oldCapacity = capacity;
    Entry **oldTable = table;

    table = new Entry *[newCapacity];
    capacity = newCapacity;
    count = 0;
    for (int i = 0; i < capacity; i++)
    {
        table[i] = NULL;
    }
    for (int i = 0; i < oldCapacity; i++)
    {
        Entry *current = oldTable[i];
        while (current != NULL)
        {
            int newIndex = hashFunction(current->key, newCapacity);
            Entry *nextNode = current->next;
            current->next = table[newIndex];
            table[newIndex] = current;
            current = nextNode;
        }
    }
    delete[] oldTable;
}

template <class K, class V>
V &XHashMap<K, V>::get(int key)
{
    int index = hashFunction(key, capacity);
    Entry *current = table[index];
    while (current != NULL)
    {
        if (current->key == key)
        {
            return current->value;
        }
        current = current->next;
    }
    throw std::out_of_range("key not found!");
}

template <class K, class V>
V XHashMap<K, V>::remove(int key)
{
    int index = hashFunction(key, capacity);
    Entry *current = table[index];
    Entry *prev = NULL;
    while (current != NULL)
    {
        if (current->key == key)
        {
            V removed = current->value;
            if (prev == NULL)
            {
                table[index] = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            delete current;
            count--;
            return removed;
        }
        prev = current;
        current = current->next;
    }
    throw std::out_of_range("Key not found");
}

int foldShift(long long key, int addressSize)
{
    string str = to_string(key);
    int sum = 0;
    int strSize = str.length();
    for (int i = 0; i < strSize; i += addressSize)
    {
        string s = str.substr(i, min(addressSize, strSize - i));
        sum += stoi(s);
    }
    string res = "";
    string sumStr = to_string(sum);
    int resSize = sumStr.length();
    if (resSize >= addressSize)
    {
        res = sumStr.substr(resSize - addressSize, addressSize);
    }
    else
    {
        res = sumStr;
    }
    return stoi(res);
}

int rotation(long long key, int addressSize)
{
    int lastDigit = key % 10;
    key /= 10;
    long long res = lastDigit * pow(10, (int)log10(key) + 1) + key;
    return foldShift(res, addressSize);
}

long long midSquare(long int seed)
{
    long long square = seed * seed;
    square /= 100;
    return square % 10000;
}

int moduleDivision(long int seed, int mod)
{
    return seed % mod;
}

int digitExtraction(long int seed, int *extractDigits, int size)
{
    string strSeed = to_string(seed);
    string res = "";
    for (int i = 0; i < size; i++)
    {
        res += strSeed[extractDigits[i]];
    }
    return stoi(res);
}

int pairMatching(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    int cnt = 0;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        int current = it->first;
        int couple = target - current;
        if (current == couple)
        {
            cnt += mp[current] / 2;
        }
        else if (current < couple)
        {
            if (mp.find(couple) != mp.end())
            {
                cnt += min(mp[current], mp[couple]);
            }
        }
    }
    return cnt;
}

int main()
{
    vector<int> nums1 = {1, 3, 5, 3, 7};
    cout << "Test 1: " << pairMatching(nums1, 6) << " (Expected: 2)" << endl;

    vector<int> nums2 = {2, 2, 2, 2}; // All same number
    cout << "Test 2: " << pairMatching(nums2, 4) << " (Expected: 2)" << endl;

    vector<int> nums3 = {1, 2, 3, 4}; // Unique elements
    cout << "Test 3: " << pairMatching(nums3, 5) << " (Expected: 2)" << endl;

    vector<int> nums4 = {1, 1, 1, 2, 2, 3, 3};
    cout << "Test 4: " << pairMatching(nums4, 4) << " (Expected: 2)" << endl; // (1,3), (2,2)

    vector<int> nums5 = {5, 5, 5, 5, 5};
    cout << "Test 5: " << pairMatching(nums5, 10) << " (Expected: 2)" << endl; // two pairs of (5,5)

    vector<int> nums6 = {};
    cout << "Test 6: " << pairMatching(nums6, 10) << " (Expected: 0)" << endl;

    vector<int> nums7 = {1, 2, 3, 4, 5, 6};
    cout << "Test 7: " << pairMatching(nums7, 100) << " (Expected: 0)" << endl; // No valid pairs

    return 0;
}