#include "linked_list.h"
#include <gtest/gtest.h>

TEST(LinkedListTest, Prepend) {
    LinkedList list;
    list.prepend(30);
    list.prepend(20);
    list.prepend(10);

    EXPECT_TRUE(list.search(20));
    EXPECT_FALSE(list.search(40));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
