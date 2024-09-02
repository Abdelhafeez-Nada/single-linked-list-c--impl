#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data) : data(data) {}
};

void print_while(Node *ptr)
{
    cout << "---------------print_while-------------------\n";
    while (ptr != nullptr)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
    cout << "---------------print_while-------------------\n";
}

void print_for(Node *ptr)
{
    cout << "---------------print_for-------------------\n";
    for (; ptr != nullptr; ptr = ptr->next)
        cout << ptr->data << endl;
    cout << "---------------print_for-------------------\n";
}

void print_rec(Node *ptr)
{
    static bool isFirstCall = true;

    if (isFirstCall)
    {
        cout << "---------------print_rec-------------------\n";
        isFirstCall = false;
    }
    if (ptr == nullptr)
    {
        cout << "---------------print_rec-------------------\n";
        return;
    }

    cout << ptr->data << endl;
    print_rec(ptr->next);
}

int main()
{
    Node *head = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = nullptr;
    Node *ptr = head;
    print_while(ptr);
    ptr = nullptr;
    ptr = head;
    print_for(head);
    ptr = nullptr;
    ptr = head;
    print_rec(ptr);
}
