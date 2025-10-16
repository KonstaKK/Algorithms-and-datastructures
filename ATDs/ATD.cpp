#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <iomanip>

/*int main() {
    LinkedList list;
    LinkedList listInsert;
    LinkedList listEndInsert;

    const int size = 100;

    std::cout << "Normal list:" << std::endl;
    for (int i = 0; i < 0; i++) {
        list.Add(i);
    }
    list.Print();
    std::cout << std::endl;

    std::cout << "Insert list:" << std::endl;
    for (int i = 0; i < size; i++) {
        listInsert.Insert(i);
    }
    listInsert.Print();
    std::cout << std::endl;

    std::cout << "Insert End list:" << std::endl;
    for (int i = 0; i < size; i++) {
        listEndInsert.InsertEnd(i);
    }
    listEndInsert.Print();
    std::cout << std::endl;


    LinkedList extraList;
    for (int i = 0; i < size; i++) {
        extraList.InsertEnd(i);
    }
    std::cout << "Finding 46: " << extraList.Find(46) << std::endl;
    std::cout << "Finding 66: " << extraList.Find(66) << std::endl;
    std::cout << "Finding 100: " << extraList.Find(100) << std::endl;

    std::cout << "Deleting 77: " << extraList.Delete(77) << std::endl;
    std::cout << "Deleting 21: " << extraList.Delete(21) << std::endl;
    std::cout << "Deleting -1: " << extraList.Delete(-1) << std::endl;

    std::cout << std::endl;
    for (int i = 0; i < size; i++) {
        extraList.Delete(i);
    }
    extraList.Print();
    std::cout << std::endl;

    std::cout << "Insert End list is used for the challenge" << std::endl;
    listEndInsert.Print();
    std::cout << std::endl << "Reversed:" << std::endl;
    listEndInsert.Reverse();
    listEndInsert.Print();
}*/