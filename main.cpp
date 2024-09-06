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

    LinkedList list2;

    list2.insert_end(1);

    list2.insert_end(2);

    list2.insert_end(3);

    list2.insert_end(4);

    // list2.insert_end(5);

    list2.insert_end(6);

    cout << list.is_same_use_length(list2) << endl;
}
