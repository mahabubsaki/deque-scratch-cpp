#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 500;

class Queue
{
public:
    int *array;
    int left, right;
    int capacity;
    int size;
    Queue()
    {
        array = new int[1];
        capacity = 1;
        left = 0;
        right = -1;
        size = 0;
    }
    void RemoveCircular()
    {
        int *temp = new int[capacity];
        int index = 0;
        for (int i = left; i < capacity; i++)
        {
            temp[index] = array[i];
            index++;
        };
        for (int i = 0; i <= right; i++)
        {
            temp[index] = array[i];
            index++;
        }
        swap(temp, array);
        left = 0;
        right = capacity - 1;
        delete[] temp;
    }
    void IncreaseSize()
    {
        if (left > right)
        {
            RemoveCircular();
        }
        int *temp = new int[capacity * 2];
        for (int i = 0; i < capacity; i++)
        {
            temp[i] = array[i];
        };
        swap(array, temp);
        capacity = capacity * 2;
        delete[] temp;
    }
    int Size()
    {
        return size;
    }
    void Enqueue(int value)
    {
        if (size == MAX_SIZE)
        {
            cout << "Queue is full" << endl;
            return;
        }
        right++;

        if (right == MAX_SIZE)
        {
            right = 0;
        }
        array[right] = value;
        size++;
    }
    void Dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        left++;
        if (left == MAX_SIZE)
        {
            left = 0;
        }
        size++;
    }
    int Front()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return array[left];
    }
};
int main()
{
    Queue q;
    q.Enqueue(5);
    q.Enqueue(6);
    q.Enqueue(7);
    cout << q.Size();
    return 0;
}