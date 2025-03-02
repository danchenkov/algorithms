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

    void print() const;
    bool includes(int value) const;
    Node* findByValue(int value) const;
    int countNodes() const;
    int firstNodeData() const;
    int lastNodeData() const;
    Node* getAtIndex(int index) const;
    int valueAtIndex(int index) const;


    void prepend(int value);
    void append(int value);
    void insertAfterNode(int data, Node* head);
    void deleteFirstNode();
    void deleteLastNode();
    void deleteNode(Node* nodeToDelete);
    void deleteByValue(int value);
    void reversal();

private:
    Node* head;
};

#endif
