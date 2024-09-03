#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data) : data(data) {}
};

class LinkedList
{
private:
    Node *head{};
    Node *tail{};

public:
    void print()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void insert_end(int val)
    {
        Node *newNode = new Node(val);
        Node *current = head;
        if (head == nullptr)
        {
            tail = newNode;
            head = newNode;
        }
        while (current->next != nullptr)
            current = current->next;
        current->next = newNode;
        tail = newNode;
    }
};