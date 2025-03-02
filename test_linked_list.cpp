#include "linked_list.h"
#include <gtest/gtest.h>

TEST(LinkedListTest, Prepend) {
    LinkedList list;
    list.prepend(30);
    list.prepend(20);
    list.prepend(10);

    EXPECT_TRUE(list.includes(20));
    EXPECT_FALSE(list.includes(40));
}

TEST(LinkedListTest, Append) {
    LinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);

    EXPECT_TRUE(list.includes(10));
    EXPECT_FALSE(list.includes(50));
    EXPECT_TRUE(list.firstNodeData() == 10);
    EXPECT_TRUE(list.countNodes() == 3);
    EXPECT_TRUE(list.lastNodeData() == 30);
}

TEST(LinkedListTest, InsertAfterNode) {
    LinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);
    Node* node = list.findByValue(20);
    list.insertAfterNode(25, node);

    EXPECT_TRUE(list.firstNodeData() == 10);
    EXPECT_TRUE(list.getAtIndex(2)->data == 25);
    EXPECT_TRUE(list.countNodes() == 4);
    EXPECT_TRUE(list.lastNodeData() == 30);
}

TEST(LinkedListTest, DeleteFirstNode) {
    LinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.deleteFirstNode();

    EXPECT_TRUE(list.firstNodeData() == 20);
    EXPECT_TRUE(list.countNodes() == 2);
    EXPECT_TRUE(list.lastNodeData() == 30);
}

TEST(LinkedListTest, DeleteLastNode) {
    LinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);
    list.deleteLastNode();

    EXPECT_TRUE(list.firstNodeData() == 10);
    EXPECT_TRUE(list.countNodes() == 4);
    EXPECT_TRUE(list.lastNodeData() == 40);
}

TEST(LinkedListTest, NodeToDelete) {
    LinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);
    Node* node = list.getAtIndex(3);
    list.deleteNode(node);

    EXPECT_TRUE(list.firstNodeData() == 10);
    EXPECT_TRUE(list.countNodes() == 4);
    EXPECT_TRUE(list.valueAtIndex(3) == 50);
    EXPECT_TRUE(list.lastNodeData() == 50);
}

TEST(LinkedListTest, DeleteByValue) {
    LinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);
    list.deleteByValue(20);
    list.deleteByValue(50);

    EXPECT_TRUE(list.firstNodeData() == 10);
    EXPECT_TRUE(list.countNodes() == 3);
    EXPECT_TRUE(list.valueAtIndex(1) == 30);
    EXPECT_TRUE(list.valueAtIndex(2) == 40);
    EXPECT_TRUE(list.lastNodeData() == 40);
 }

TEST(LinkedListTest, ReversedList) {
    LinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);
    list.reversal();

    EXPECT_TRUE(list.firstNodeData() == 50);
    EXPECT_TRUE(list.countNodes() == 5);
    EXPECT_TRUE(list.valueAtIndex(1) == 40);
    EXPECT_TRUE(list.valueAtIndex(2) == 30);
    EXPECT_TRUE(list.lastNodeData() == 10);
 }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
