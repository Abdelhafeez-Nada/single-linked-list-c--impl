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

    void print_addresses()
    {
        if (head == nullptr)
        {
            cout << "Length: 0" << endl;
        }
        cout << "Length: " << length << " | Head: " << head << " | Tail: " << tail << endl;
        Node *current = head;
        while (current != nullptr)
        {
            cout << current << " ";
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

    void delete_tail()
    {
        if (head == nullptr)
            return;
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node *current = head;
        while (current->next != tail)
            current = current->next;
        delete tail;
        tail = current;
        tail->next = nullptr;
    }

    void delete_with_key(int val)
    {
        if (head == nullptr)
            return;

        if (head->data == val)
        {
            Node *oldHead = head;
            head = head->next;
            if (head == nullptr)
                tail = nullptr;
            delete oldHead;
            length--;
            return;
        }
        Node *prev = head;
        Node *current = head->next;
        while (current != nullptr)
        {
            if (current->data == val)
            {
                prev->next = current->next;
                if (current == tail)
                    tail = prev;
                delete current;
                length--;
                return;
            }
            prev = current;
            current = current->next;
        }
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

    // void swap_pairs_values()
    // {
    //     if (head == nullptr || head->next == nullptr)
    //         return;

    //     Node *before = head;
    //     Node *after = head->next;
    //     while (before && after)
    //     {
    //         swap_values(before, after);
    //         before = after->next;
    //         if (before)
    //             after = before->next;
    //     }
    // }

    void swap_pairs_values()
    {
        if (head == nullptr || head->next == nullptr)
            return;

        Node *current = head;
        while (current && current->next)
        {
            swap_values(current, current->next);
            current = current->next->next;
        }
    }

    void swap_values(Node *n1, Node *n2)
    {
        int temp = n1->data;
        n1->data = n2->data;
        n2->data = temp;
    }

    void reverse()
    {
        if (head == nullptr || head->next == nullptr)
            return;

        Node *n1 = head;
        Node *n2 = head->next;
        // Node *n3 = n2->next;
        Node *n3 = nullptr;

        while (n2)
        {
            n3 = n2->next;
            n2->next = n1;
            n1 = n2;
            n2 = n3;
            // if (n3)
            //     n3 = n3->next;
        }
        head->next = nullptr;
        Node *temp = head;
        head = tail;
        tail = temp;
    }

    // position is 1-based
    void delete_even_position()
    {
        if (head == nullptr || head->next == nullptr)
            return;
        Node *prev = head;
        Node *current = nullptr;
        while (prev && prev->next)
        {
            current = prev->next;
            prev->next = current->next;
            delete current;
            length--;

            if (prev->next == nullptr)
                tail = prev;

            prev = prev->next;
        }
    }

    // sort ASC
    void insert_sorted(int val)
    {
        Node *to_insert = new Node(val);
        // empty list
        if (!head)
            head = tail = to_insert;
        // insert at head
        else if (head->data > val)
        {
            to_insert->next = head;
            head = to_insert;
        }
        // insert in middle pr tail
        else
        {
            Node *current = head;
            // loop until find correct position to insert at
            while (current->next && current->next->data < val)
                current = current->next;
            to_insert->next = current->next;
            current->next = to_insert;
            if (!to_insert->next)
                tail = to_insert;
        }
        length++;
    }

    // //sort ASC
    //     void insert_sorted(int val)
    //     {
    //         Node *node = new Node(val);
    //         // first node
    //         if (head == nullptr)
    //         {
    //             head = tail = node;
    //         }
    //         else if (val < head->data)
    //         {
    //             node->next = head;
    //             head = node;
    //         }
    //         else
    //         {
    //             Node *prev = head;
    //             Node *current = nullptr;
    //             while (prev)
    //             {
    //                 current = prev->next;
    //                 // last node
    //                 if (current == nullptr)
    //                 {
    //                     prev->next = node;
    //                     node->next = nullptr;
    //                     tail = node;
    //                     break;
    //                 }
    //                 // in middle
    //                 else if (current->data > val)
    //                 {
    //                     prev->next = node;
    //                     node->next = current;
    //                     break;
    //                 }
    //                 else
    //                     prev = prev->next;
    //             }
    //         }
    //         length++;
    //     }

    void swap_head_and_tail()
    {
        if (!head || !head->next)
            return;
        Node *after_head = head->next;
        Node *before_tail = head;
        while (before_tail->next->next != nullptr)
            before_tail = before_tail->next;
        tail->next = after_head;
        before_tail->next = head;
        head->next = nullptr;
        Node *temp = head;
        head = tail;
        tail = temp;
    }

    void left_rotate_once()
    {
        if (head == nullptr || head->next == nullptr)
            return;
        Node *newHead = head->next;
        tail->next = head;
        head->next = nullptr;
        head = newHead;
        tail = tail->next;
    }

    void left_rotate_n_times(int n)
    {
        n = n % length;
        if (head == nullptr || head->next == nullptr || n == 0)
            return;
        Node *new_tail = head;

        for (int i = 1; i < n; i++)
            new_tail = new_tail->next;
        Node *new_head = new_tail->next;
        tail->next = head;
        tail = new_tail;
        new_tail->next = nullptr;
        head = new_head;
    }

    void remove_duplicates()
    {
        if (head == nullptr || head->next == nullptr)
            return;

        Node *unique = head;
        Node *prev = nullptr;
        while (unique != nullptr)
        {
            prev = unique;
            while (prev != nullptr && prev->next != nullptr)
            {
                // check and remove duplicates
                if (prev->next->data == unique->data)
                {
                    Node *temp = prev->next;
                    prev->next = temp->next;
                    delete temp;
                    length--;
                    // maintain tail
                    if (prev->next == nullptr)
                        tail = prev;
                }
                else
                    prev = prev->next;
            }
            unique = unique->next;
        }
    }
};