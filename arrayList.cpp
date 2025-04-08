template <class T>
class ArrayList
{
protected:
    T *data;      // dynamic array to store the list's items
    int capacity; // size of the dynamic array
    int count;    // number of items stored in the array

public:
    ArrayList()
    {
        capacity = 5;
        count = 0;
        data = new T[5];
    }
    ~ArrayList() { delete[] data; }
    void add(T e);
    void add(int index, T e);
    int size();
    bool empty();
    void clear();
    T get(int index);
    void set(int index, T e);
    int indexOf(T item);
    bool contains(T item);
    T removeAt(int index);
    bool removeItem(T item);
    void ensureCapacity(int index);
};

template <class T>
T ArrayList<T>::removeAt(int index)
{
    if (index < 0 || index > count)
    {
        throw std::out_of_range("index is invalid!");
    }
    T removed = data[index];
    for (int i = index; i < count - 1; i++)
    {
        data[i] = data[i + 1];
    }
    this->count--;
    data[count] = T();
    return removed;
}

template <class T>
bool ArrayList<T>::removeItem(T item)
{
    for (int i = 0; i < count; i++)
    {
        if (data[i] == item)
        {
            removeAt(i);
            return true;
        }
        else
        {
            return false;
        }
    }
}

template <class T>
void ArrayList<T>::clear()
{
    if (data != NULL)
    {
        delete[] data;
    }
    capacity = 5;
    count = 0;
    data = new T[capacity];
}

template <class T>
void ArrayList<T>::ensureCapacity(int cap)
{
    if (cap == capacity)
    {
        int new_capacity = static_cast<int>(capacity * 1.5);
        T *new_data = new T[new_capacity];
        for (int i = 0; i < cap; i++)
        {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
    else
    {
        return;
    }
}

template <class T>
void ArrayList<T>::add(T e)
{
    ensureCapacity(count + 1);
    data[count] = e;
    count++;
}

template <class T>
void ArrayList<T>::add(int index, T e)
{
    if (index < 0 || index > count + 1)
    {
        throw std::out_of_range("the index is invalid!");
    }
    ensureCapacity(count + 1);
    for (int i = count; i > index; i--)
    {
        data[i] = data[i - 1];
    }
    data[index] = e;
    count++;
}

template <class T>
int ArrayList<T>::size()
{
    return this->count;
}
