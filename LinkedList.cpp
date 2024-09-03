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
    int length = 0;

public:
    void print()
    {
        cout << "Length: " << length << endl;
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
        if (head != nullptr)
        {
            tail->next = newNode;
            tail = newNode;
        }
        else
            head = tail = newNode;
        length++;
    }

    Node *get_nth_while(int n)
    {
        Node *current = head;
        while (current != nullptr && n > 1)
        {
            current = current->next;
            n--;
        }
        if (current != nullptr && n == 1)
            return current;
        return nullptr;
    }
};