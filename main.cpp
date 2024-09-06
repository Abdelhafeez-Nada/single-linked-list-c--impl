#include <iostream>
// #include "LinkedList.cpp"
#include "LinkedList_head_only.cpp"
using namespace std;

int main()
{

    LinkedList_head_only list;

    list.add_element(1);
    list.add_element(2);
    list.add_element(3);
    list.add_element(4);
    list.add_element(5);
    list.add_element(6);

    list.print();
    cout << endl;

    list.delete_last();
    list.print();
    cout << endl;

    list.delete_last();
    list.print();
    cout << endl;

    list.delete_last();
    list.print();
    cout << endl;

    list.delete_last();
    list.print();
    cout << endl;

    list.delete_last();
    list.print();
    cout << endl;

    list.delete_last();
    list.print();
    cout << endl;

    // LinkedList list;

    // list.insert_end(11);

    // list.insert_end(2);

    // list.insert_end(3);

    // list.insert_end(41);

    // list.insert_end(5);

    // list.insert_end(6);

    // LinkedList list2;

    // list2.insert_end(11);

    // list2.insert_end(2);

    // list2.insert_end(3);

    // list2.insert_end(41);

    // list2.insert_end(5);

    // // list2.insert_end(6);

    // cout << list.is_same_use_length(list2) << endl;
}
