#include <iostream>
#include "LinkedList.cpp"
// #include "LinkedList_head_only.cpp"
using namespace std;

int main()
{

    LinkedList list;
    list.insert_end(1);
    list.insert_end(2);

    list.insert_end(3);
    list.insert_end(4);
    // list.insert_end(5);
    // list.insert_end(6);

    list.print();
    cout << "\n---------------------------------------\n";

    list.delete_even_position();

    list.print();

    // LinkedList list;
    // list.insert_end(1);
    // list.insert_end(1);

    // list.insert_end(2);
    // list.insert_end(2);
    // list.insert_end(3);
    // list.insert_end(3);

    // list.insert_end(4);
    // list.insert_end(4);

    // list.insert_end(5);
    // list.insert_end(5);

    // list.insert_end(7);

    // list.insert_end(6);

    // list.print();
    // cout << "\n---------------------------------------\n";

    // list.delete_with_key(1);
    // list.print();
    // cout << "\n---------------------------------------\n";

    // list.delete_with_key(2);
    // list.print();
    // cout << "\n---------------------------------------\n";

    // list.delete_with_key(3);
    // list.print();
    // cout << "\n---------------------------------------\n";

    // list.delete_with_key(4);
    // list.print();
    // cout << "\n---------------------------------------\n";

    // list.delete_with_key(5);
    // list.print();
    // cout << "\n---------------------------------------\n";

    // list.delete_with_key(6);
    // list.print();
    // cout << "\n---------------------------------------\n";

    // LinkedList_head_only list;

    // list.add_element(1);
    // list.add_element(2);
    // list.add_element(3);
    // list.add_element(4);
    // list.add_element(5);
    // list.add_element(6);

    // list.print();
    // cout << endl;

    // list.delete_nth(1);
    // list.print();
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
