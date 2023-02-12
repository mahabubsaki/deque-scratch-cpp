#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *previous;
};
class Deque
{
public:
    node *head;
    node *tail;
    int size;
    bool reverse;
    Deque()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
        reverse = false;
    }
    node *CreateNode(int value)
    {
        node *newNode = new node;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->previous = nullptr;
        return newNode;
    }
    void InsertAtLast(int value)
    {
        node *newNode = CreateNode(value);

        if (size == 0)
        {
            head = newNode;
            tail = newNode;
            size++;
            return;
        }
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
        size++;
    }
    void InsertAtFirst(int value)
    {
        node *newNode = CreateNode(value);

        if (size == 0)
        {
            head = newNode;
            tail = newNode;
            size++;
            return;
        }
        head->previous = newNode;
        newNode->next = head;
        head = newNode;
        size++;
    }
    void DeleteAtLast()
    {
        if (size == 0)
        {
            cout << "Deque is empty" << endl;
            return;
        }
        if (size == 1)
        {
            delete tail;
            head = nullptr;
            tail = nullptr;
            size = 0;
            return;
        }
        node *current = tail;
        tail->previous->next = nullptr;
        tail = tail->previous;
        delete current;
    }
    void DeleteAtFirst()
    {
        if (size == 0)
        {
            cout << "Deque is empty" << endl;
            return;
        }
        if (size == 1)
        {
            delete tail;
            head = nullptr;
            tail = nullptr;
            size = 0;
            return;
        }
        node *current = head;
        head->next->previous = nullptr;
        head = head->next;
        delete current;
    }
    int GetFirst()
    {
        if (size == 0)
        {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return head->data;
    }
    int GetLast()
    {
        if (size == 0)
        {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return tail->data;
    }
    void PushBack(int value)
    {
        if (reverse)
        {
            InsertAtFirst(value);
        }
        else
        {
            InsertAtLast(value);
        }
    }
    void PushFront(int value)
    {
        if (reverse)
        {
            InsertAtLast(value);
        }
        else
        {

            InsertAtFirst(value);
        }
    }
    void PopFront()
    {
        if (reverse)
        {
            DeleteAtLast();
        }
        else
        {

            DeleteAtFirst();
        }
    }
    void PopBack()
    {
        if (reverse)
        {
            DeleteAtFirst();
        }
        else
        {

            DeleteAtLast();
        }
    }
    int GetSize()
    {
        return size;
    }
    void PrintList()
    {
        if (reverse)
        {
            node *current = tail;
            while (current)
            {
                cout << current->data << endl;
                current = current->previous;
            }
            delete current;
        }
        else
        {
            node *current = head;
            while (current)
            {
                cout << current->data << endl;
                current = current->next;
            }
            delete current;
        }
    }
    void ReverseList()
    {
        node *first = head;
        node *last = tail;
        while (first != last)
        {
            swap(first->data, last->data);
            first = first->next;
            last = last->previous;
        }
    }
    int Front()
    {
        if (reverse)
        {
            return GetLast();
        }
        else
        {
            return GetFirst();
        }
    }
    int Back()
    {
        if (reverse)
        {
            return GetFirst();
        }
        else
        {

            return GetLast();
        }
    }
    void ReverseSt()
    {
        reverse = !reverse;
    }
};
int main()
{
    Deque mydq;
    mydq.PushBack(2);
    mydq.PushBack(4);
    mydq.PushBack(6);
    mydq.PushBack(8);
    mydq.PushBack(10);
    mydq.PrintList();
    mydq.ReverseSt();
    mydq.PrintList();
    cout << mydq.Back();
    return 0;
}