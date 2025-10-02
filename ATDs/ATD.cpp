#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <iomanip>

int main() {
    LinkedList list;

    const int size = 10;

    for (int i = 0; i < size; i++) {
        list.Add(rand() % (size + 1));
    }

    list.Print();
}