#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
    int data;
    Node* next;
    explicit Node(int value, Node* nextNode = nullptr) : data(value), next(nextNode) {}
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}
    void prepend(int value);
    bool search(int value);
private:
    Node* head;
};

#endif
