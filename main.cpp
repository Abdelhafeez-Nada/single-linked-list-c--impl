#include <iostream>
#include "LinkedList.cpp"
using namespace std;

int main()
{
    LinkedList list;

    list.insert_end(1);

    list.insert_end(2);

    list.insert_end(3);

    list.insert_end(4);

    list.insert_end(5);

    list.insert_end(6);

    list.print();

    cout << "---------------------------------\n";

    for (int i = 6; i >= 1; i--)
    {
        Node *found = list.get_nth_back(i);
        cout << found->data << " ";
    }

    cout << endl;

    for (int i = 1; i <= 6; i++)
    {
        Node *found = list.get_nth_back(i);
        cout << found->data << " ";
    }
}
