#include <iostream>
#include <limits>
#include "linked_list.h"

void LinkedList::print() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

bool LinkedList::includes(int data) const {
    Node* current = head;
    while (current) {
        if (current->data == data) return true;
        current = current->next;
    }
    return false;
}

Node* LinkedList::getAtIndex(int index) const {
    if (index < 0) return nullptr;

    Node* current = head;
    int count = 0;

    while (current) {
        if (count == index) return current;
        current = current->next;
        count++;
    }

    return nullptr;
}

int LinkedList::valueAtIndex(int index) const {
    if (index < 0) return std::numeric_limits<int>::min();

    Node* current = head;
    int count = 0;

    while (current) {
        if (count == index) return current->data;
        current = current->next;
        count++;
    }

    return std::numeric_limits<int>::min();
}

Node* LinkedList::findByValue(int value) const {
    Node* current = head;
    while (current) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

int LinkedList::countNodes() const {
    int count = 0;
    Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

int LinkedList::firstNodeData() const {
    if (!head) return std::numeric_limits<int>::min();
    return head->data;
}

int LinkedList::lastNodeData() const {
    if (!head) return std::numeric_limits<int>::min();
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    return current->data;
}

void LinkedList::prepend(int data) {
    head = new Node(data, head);
}

void LinkedList::append(int data) {
    if (!head) {
        head = new Node(data);
        return;
    }
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = new Node(data);
}

void LinkedList::insertAfterNode(int data, Node* head) {
    if (!head) return;

    Node* current = new Node(data);
    current->next = head->next;
    head->next = current;
}

void LinkedList::deleteFirstNode() {
    if (!head) return;

    Node* current = head->next;
    delete head;
    head = current;
}

void LinkedList::deleteLastNode() {
    if (!head) return;

    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;
    while (current->next->next) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
}

void LinkedList::deleteNode(Node* nodeToDelete) {
    if (!head || !nodeToDelete) return;

    if (head == nodeToDelete) {
        Node* newHead = head->next;
        delete nodeToDelete;
        head = newHead;
        return;
    }

    Node* current = head;
    while (current->next && current->next != nodeToDelete) {
        current = current->next;
    }

    if (!current->next) return;

    current->next = nodeToDelete->next;
    delete nodeToDelete;
}

void LinkedList::deleteByValue(int value) {
    if (!head) return;

    if (head->data == value) {
        Node* nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;
        return;
    }

    Node* current = head;
    while (current->next) {
        if (current->next->data == value) {
            Node* nodeToDelete = current->next;
            current->next = nodeToDelete->next;
            delete nodeToDelete;
            return;
        }
        current = current->next;
    }
}

void LinkedList::reversal() {
    if (!head || !head->next) return;

    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}
