

#include "gtest/gtest.h"
#include "../ShoppingList.h"
#include "../User.h"

class UserSuite : public ::testing::Test {

protected:

    virtual void SetUp() {
        u.addShoppingList(s1);
        u.addShoppingList(s2);
    }



    ShoppingList s1{"ufficio"};
    ShoppingList s2{"giardino"};
    ShoppingList s3{"sport"};
   User u;

};


TEST_F(UserSuite, TestAddShoppingList) {
    u.addShoppingList(s3);

    ASSERT_EQ(3,u.getLists().size());
}



TEST_F(UserSuite, TestRemoveShoppingList) {
    u.removeShoppingList("Casa");

    ASSERT_EQ(1,u.getLists().size());
}
