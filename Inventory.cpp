// Name: Wadan
// Date: 3/23/26
// Purpose: Refactoring Inventory to use a custom linked list
#include "Inventory.h"
#include <iostream>

Inventory::Inventory() {
    head = nullptr;
}

// clean up all the memory
Inventory::~Inventory() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current->data; 
        delete current;       
        current = nextNode;
    }
    head = nullptr;
}

void Inventory::addBook(Book* bookPtr) {
    Node* newNode = new Node;
    newNode->data = bookPtr;
    newNode->next = nullptr;

    // if the list is empty or it belongs at the very front
    if (head == nullptr || bookPtr->getTitle() < head->data->getTitle()) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // find the right alphabetical spot
    Node* curr = head;
    while (curr->next != nullptr && curr->next->data->getTitle() < bookPtr->getTitle()) {
        curr = curr->next;
    }

    // put the new node in
    newNode->next = curr->next;
    curr->next = newNode;
}

// print out the whole list
void Inventory::displayAll() {
    if (head == nullptr) {
        cout << "Inventory is empty." << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        temp->data->displayInfo(); 
        temp = temp->next;
    }
}
