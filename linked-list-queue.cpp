#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class Queue
{
public:
    node *head;
    node *tail;
    int size;
    Queue()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    node *CreatNode(int value)
    {
        node *newNode = new node;
        newNode->data = value;
        newNode->next = nullptr;
        return newNode;
    }
    void Enqueue(int value)
    {
        node *newNode = CreatNode(value);
        size++;
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }
    void Dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        if (size == 1)
        {
            delete head;
            size = 0;
            head = nullptr;
            tail = nullptr;
            return;
        }
        node *current = head;
        head = head->next;
        delete current;
        size--;
    }
    int Front()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return head->data;
    }
    int Size()
    {
        return size;
    }
};

int main()
{
    Queue q;
    q.Enqueue(5);
    q.Enqueue(10);
    q.Enqueue(15);
    cout << "Q size :" << q.Size();
    q.Dequeue();
    cout << q.Front();
    return 0;
}