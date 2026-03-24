#ifndef INVENTORY_H
#define INVENTORY_H

#include "Book.h"
#include <string>

using namespace std;

class Inventory {
private:
    // node structure for the linked list
    struct Node {
        Book* data;
        Node* next;
    };

    Node* head;

public:
    Inventory();
    ~Inventory();
    
    void addBook(Book* bookPtr);
    void displayAll();
};

#endif
