#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data) : data(data) {}
};

class LinkedList_head_only
{
private:
    Node *head{};

public:
    ~LinkedList_head_only()
    {
        cout << "\n LinkedList_head_only Destructor Started !";
        while (head != nullptr)
        {
            Node *oldHead = head;
            head = head->next;
            delete oldHead;
        }
    }

    void add_element(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void print()
    {
        if (head == nullptr)
            cout << "EMPTY!";
        for (Node *cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
    }

    Node *get_tail()
    {
        Node *current = head;
        while (current->next != nullptr)
            current = current->next;
        return current;
    }

    void delete_last()
    {
        if (head == nullptr)
            return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *current = head;
        while (current->next->next != nullptr)
            current = current->next;
        delete current->next;
        current->next = nullptr;
    }
};
