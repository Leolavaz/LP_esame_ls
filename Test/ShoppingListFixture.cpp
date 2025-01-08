
#include "gtest/gtest.h"
#include "../ShoppingList.h"
#include "../User.h"

class ShoppingListSuite : public ::testing::Test {

protected:

    void SetUp() override {
        s.addItem(mela);
        s.addItem(insalata);
        s.addItem(pane);
    }


    ShoppingList s{"casa"};
    Item mela{"mela", "frutta", 1};
    Item insalata{"insalata", "verdura", 1};
    Item pane{"pane", "cibo", 5};
    User user;
};


TEST_F(ShoppingListSuite, TestParametrizeConstructor) {
    ShoppingList sl("Animali");
    ASSERT_EQ(sl.getShoppingListName(), "Animali");
}

TEST_F(ShoppingListSuite, TestSubject) {
    s.subscribe(&user);
    ASSERT_EQ(1, s.getObservers().size());

    s.unsubscribe(&user);
    ASSERT_EQ(0, s.getObservers().size());
}
TEST_F(ShoppingListSuite, TestAddItem) {
    Item banana("banana", "frutta", 3);
    s.addItem(banana);

    auto items = s.getShoppingList();

    ASSERT_EQ(items.size(), 4);

    bool found = false;
    for (const auto& itemPtr : items) {
        if (itemPtr->getIname() == "banana") {
            found = true;
            ASSERT_EQ(itemPtr->getQuantity(), 3);
            break;
        }
    }
    ASSERT_TRUE(found);
}



TEST_F(ShoppingListSuite, TestRemoveItem) {
    s.removeItem("mela");
    auto items = s.getShoppingList();
    ASSERT_EQ(items.size(), 2);
    bool found = false;
    for (const auto& itemPtr : items) {
        if (itemPtr->getIname() == "mela") {
            found = true;
            break;
        }
    }}
TEST_F(ShoppingListSuite, ImpTestRemove) {
    ASSERT_THROW(s.removeItem("carota"), std::invalid_argument);
    auto items = s.getShoppingList();
    ASSERT_EQ(items.size(), 3);
    bool foundCarota = false;
    for (const auto& itemPtr : items) {
        if (itemPtr->getIname() == "carota") {
            foundCarota = true;
            break;
        }
    }
    ASSERT_FALSE(foundCarota);
}







