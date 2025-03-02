#include "linked_list.h"

void LinkedList::prepend(int data) {
    head = new Node(data, head);
}

bool LinkedList::search(int data) {
    Node* current = head;
    while (current) {
        if (current->data == data) return true;
        current = current->next;
    }
    return false;
}

// void LinkedList::append(int data) {
//     if (!head) {
//         head = new Node(data);
//         return;
//     }
//     Node* temp = head;
//     while (temp->next) {
//         temp = temp->next;
//     }
//     temp->next = new Node(data);
// }

// #include <iostream>
// #include <limits>
// #include <cassert> // For tests

// struct node {
//     node* next;
//     int data;

//     explicit node(int data) :  next(nullptr), data(data) {}
//     node(node* head, int data) : next(head), data(data) {}
// };

// node* push(node* head, int data) {
//     return new node {head, data};
// }

// void insertAfter(node* head, int data) {
//     if (!head) return;

//     node* newNode = new node(data);
//     newNode->next = head->next;
//     head->next = newNode;
// }

// node* append(node* head, int data) {
//     node* newNode = new node(data);
//     if (!head) { return newNode; }

//     node* current = head;
//     while (current->next) { current = current->next; }
//     current->next = newNode;

//     return head;
// }

// node* deleteFirst(node* head) {
//     if (!head) { return nullptr; }
//     node* newHead = head->next;
//     delete head;
//     return newHead;
// }

// node* deleteNode(node* head, node* nodeToDelete) {
//     if (!head || !nodeToDelete) { return head; }

//     if (head == nodeToDelete) {
//         node* newHead = head->next;
//         delete nodeToDelete;
//         return newHead;
//     }

//     node* current = head;
//     while (current->next && current-> next != nodeToDelete) {
//         current = current->next;
//     }

//     if (!current->next) return head;

//     current->next = nodeToDelete->next;
//     delete nodeToDelete;
//     return head;
// }

// node* deleteLast(node* head) {
//     if (!head) { return nullptr; }

//     if (!head->next) {
//         delete head;
//         return nullptr;
//     }

//     node* current = head;
//     while (current->next->next) {
//         current = current->next;
//     }
//     delete current->next;
//     current->next = nullptr;

//     return head;
// }

// node* deleteByValue(node* head, int value) {
//     if (!head) { return nullptr; }

//     if (head->next == nullptr && head->data == value) {
//         delete head;
//         return nullptr;
//     }

//     if (head->data == value) {
//         node* current = head->next;
//         delete head;
//         return current;
//     }

//     node* current = head;
//     while (current->next && current->next->data != value) {
//         current = current->next;
//     }

//     if (!current->next) { return head; }

//     node* nodeToDelete = current->next;
//     current->next = nodeToDelete->next;
//     delete nodeToDelete;
//     return head;
// }

// void printList(const node* head) {
//     while (head != nullptr) {
//         std::cout << head->data << " -> ";
//         head = head->next;
//     }
//     std::cout << "nullptr\n";
// }

// int countNodes(const node* head) {
//     int count = 0;
//     const node* current = head;
//     while (current) {
//         count++;
//         current = current->next;
//     }
//     return count;
// }

// int firstNodeData(const node* head) {
//     if (!head) return std::numeric_limits<int>::min();
//     return head->data;
// }

// int lastNodeData(const node* head) {
//     if (!head) return std::numeric_limits<int>::min();
//     while (head->next) {
//         head = head->next;
//     }
//     return head->data;
// }

// const node* findNodeByValue(const node* head, int value) {
//     if (!head) { return nullptr; }
//     while (head->data != value) {
//         head = head->next;
//         if (!head) { return nullptr; }
//     }
//     return head;
// }

// node* reversal(const node* head) {
//     if (!head) { return nullptr; }
//     node* reversedList = nullptr;
//     while (head) {
//         reversedList = push(reversedList, head->data);
//         head = head->next;
//     }
//     return reversedList;
// }

// int main() {
//     node* head = nullptr;
//     head = push(head, 30);

//     printList(head);

//      // Tests for correctness
//     assert(countNodes(head) == 1);
//     assert(lastNodeData(head) == 30);

//     head = append(head, 40);
//     head = push(head, 20);
//     auto save = head;
//     head = push(head, 10);

//     printList(head);
//     assert(countNodes(head) == 4);
//     assert(lastNodeData(head) == 40);

//     insertAfter(save, 25);
//     printList(head);
//     assert(countNodes(head) == 5);
//     assert(lastNodeData(head) == 40);

//     head = deleteLast(head);
//     printList(head);
//     assert(countNodes(head) == 4);
//     assert(lastNodeData(head) == 30);
//     assert(firstNodeData(head) == 10);

//     head = deleteFirst(head);
//     printList(head);
//     assert(countNodes(head) == 3);
//     assert(lastNodeData(head) == 30);
//     assert(firstNodeData(head) == 20);

//     head = append(head, 35);
//     head = append(head, 45);
//     printList(head);
//     assert(countNodes(head) == 5);
//     assert(lastNodeData(head) == 45);
//     assert(firstNodeData(head) == 20);

//     head = append(head, 55);
//     printList(head);
//     assert(countNodes(head) == 6);

//     head = deleteNode(head, head->next->next->next);
//     printList(head);
//     assert(countNodes(head) == 5);
//     assert(lastNodeData(head) == 55);
//     assert(firstNodeData(head) == 20);

//     while(countNodes(head) > 0) {
//         head = deleteLast(head);
//         printList(head);
//     }

//     head = append(head, 99);
//     printList(head);
//     assert(countNodes(head) == 1);
//     assert(lastNodeData(head) == 99);

//     head = append(head, 55);
//     printList(head);

//     head = append(head, 60);
//     printList(head);

//     while(countNodes(head) > 0) {
//         head = deleteNode(head, head);
//         printList(head);
//     }
//     assert(countNodes(head) == 0);

//     head = append(head, 110);
//     printList(head);
//     assert(countNodes(head) == 1);
//     assert(lastNodeData(head) == 110);

//     head = deleteByValue(head, 100);
//     printList(head);
//     assert(countNodes(head) == 1);
//     assert(lastNodeData(head) == 110);

//     head = deleteByValue(head, 110);
//     printList(head);
//     assert(head == nullptr);

//     head = deleteByValue(head, 110);
//     printList(head);
//     assert(head == nullptr);

//     head = append(head, 120);
//     head = append(head, 130);
//     head = append(head, 140);
//     head = append(head, 150);
//     printList(head);
//     assert(countNodes(head) == 4);
//     assert(firstNodeData(head) == 120);
//     assert(lastNodeData(head) == 150);
//     node* reversed = reversal(head);
//     std::cout << "REVERSED LIST: ";
//     printList(reversed);
//     assert(countNodes(reversed) == 4);
//     assert(firstNodeData(reversed) == 150);
//     assert(lastNodeData(reversed) == 120);

//     head = deleteByValue(head, 120);
//     printList(head);
//     assert(countNodes(head) == 3);
//     assert(firstNodeData(head) == 130);
//     assert(lastNodeData(head) == 150);

//     head = deleteByValue(head, 140);
//     printList(head);
//     assert(countNodes(head) == 2);
//     assert(firstNodeData(head) == 130);
//     assert(lastNodeData(head) == 150);

//     head = append(head, 160);
//     head = deleteByValue(head, 150);
//     printList(head);
//     assert(countNodes(head) == 2);
//     assert(firstNodeData(head) == 130);
//     assert(lastNodeData(head) == 160);

//     head = deleteByValue(head, 130);
//     printList(head);
//     assert(countNodes(head) == 1);
//     assert(firstNodeData(head) == 160);
//     assert(lastNodeData(head) == 160);

//     head = deleteByValue(head, 170);
//     printList(head);
//     assert(countNodes(head) == 1);
//     assert(firstNodeData(head) == 160);
//     assert(lastNodeData(head) == 160);

//     head = deleteByValue(head, 160);
//     printList(head);
//     assert(countNodes(head) == 0);
//     assert(firstNodeData(head) == std::numeric_limits<int>::min());
//     assert(lastNodeData(head) == std::numeric_limits<int>::min());

//     head = push(head, 230);
//     head = push(head, 220);
//     printList(head);
//     node* storedHead = head;
//     head = push(head, 210);
//     head = push(head, 200);
//     printList(head);
//     const node* foundNode = findNodeByValue(head, 220);
//     std::cout << storedHead << ": " << storedHead->data << " vs " << foundNode << ": " << foundNode->data << '\n';
//     assert (storedHead == foundNode);

//     while(countNodes(head) > 0) {
//         head = deleteNode(head, head);
//         printList(head);
//     }
//     assert(countNodes(head) == 0);

//     return 0;
// }
