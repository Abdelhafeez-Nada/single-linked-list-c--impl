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
    ~LinkedList()
    {
        cout << "\n LINKEDLIST DESTRUCTOR STARTED\n";
        while (head != nullptr)
        {
            Node *current = head->next;
            delete head;
            head = current;
        }
    }

public:
    void print()
    {
        if (head == nullptr)
        {
            cout << "Length: 0" << endl;
        }
        cout << "Length: " << length << " | Head: " << head->data << " | Tail: " << tail->data << endl;
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

    void insert_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head = newNode;
        }
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

    Node *get_nth_for(int n)
    {
        int i = 0;
        for (Node *current = head; current; current = current->next)
            if (++i == n)
                return current;
        return nullptr;
    }

    Node *get_nth_back(int n)
    {
        if (n < 1 || n > length)
            return nullptr;
        int idx = length - n;
        if (idx == 0)
            return head;
        if (idx == length - 1)
            return tail;
        Node *current = head;
        while (idx > 0)
        {
            current = current->next;
            idx--;
        }
        return current;
    }

    int search(int value)
    {
        if (head->data == value)
            return 0;
        int idx = 1;
        Node *ptr = head->next;
        while (ptr != nullptr)
        {
            if (ptr->data == value)
                return idx;
            ptr = ptr->next;
            idx++;
        }
        return -1;
    }

    int search_transposition(int value)
    {
        if (head->data == value)
            return 0;
        Node *prev = head->next;
        if (prev->data == value)
        {
            head->next = prev->next;
            prev->next = head;
            head = prev;
            return 0;
        }
        Node *pre = head;
        Node *current = prev->next;
        int idx = 1;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                pre->next = current;
                prev->next = current->next;
                current->next = prev;
                if (current == tail)
                    tail = prev;
                return idx;
            }
            pre = prev;
            prev = current;
            current = current->next;
            idx++;
        }
        return -1;
    }

    void delete_front()
    {
        if (head == nullptr)
            return;
        if (head == tail)
            delete head;
        else
        {
            Node *newHead = head->next;
            delete head;
            head = newHead;
        }
        length--;
    }

    Node *get_head() const
    {
        return head;
    }

    int get_length() const
    {
        return length;
    }

    bool is_same_use_length(const LinkedList &another)
    {
        if (length != another.get_length())
            return false;
        Node *current = head;
        Node *another_current = another.get_head();
        while (current != nullptr && another_current != nullptr)
        {
            if (current->data != another_current->data)
                return false;
            current = current->next;
            another_current = another_current->next;
        }
        return true;
    }

    bool is_same_no_length(const LinkedList &another)
    {
        Node *current = head;
        Node *another_current = another.get_head();
        while (current != nullptr && another_current != nullptr)
        {
            if (current->data != another_current->data)
                return false;
            current = current->next;
            another_current = another_current->next;
        }
        return current == nullptr && another_current == nullptr;
    }
};