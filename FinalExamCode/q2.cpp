#include <iostream>

class Node {
    public:
        std::string value;
        Node* next;

        Node (std::string value, Node* node = nullptr) : value(value), next(node) {}
};

class LinkedList {
    private:
        Node* head;
    public:
        LinkedList() : head(nullptr) {}
        void push_front(std::string value);

        //todo
        void filterClothing(std::string f);
};

void LinkedList::push_front(std::string value) {
    Node* newNode = new Node(value, head);
    head = newNode;
}



void LinkedList::filterClothing(std::string f) {
    Node* curr = this->head;
    Node* prev = nullptr;

    if (curr->value != f) {
        this->head = curr->next;
    }
    else {
        prev = curr;
    }

    curr = curr->next;


    while (curr != nullptr) {
        if (curr->value == f) {
            if (prev != nullptr) {
                prev->next = curr->next;
            }
        }
        if (prev = nullptr) {
            prev = curr;
        }
        curr = curr->next;
    }
}