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

    list.print();
    cout << endl;
    // Node *found = list.get_nth_for(4);

    int idx = list.search_transposition(5);
    cout << "found: " << idx << endl;

    list.print();
}
