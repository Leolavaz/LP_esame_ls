

#include "gtest/gtest.h"
#include "../ShoppingList.h"
#include "../User.h"
#include<algorithm>

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

/*
TEST_F(UserSuite, TestAddShoppingList) {
    u.addShoppingList(s3);

    ASSERT_EQ(3, u.getLists().size());
}


TEST_F(UserSuite, TestRemoveShoppingList) {
    u.removeShoppingList("Casa");

    ASSERT_EQ(1, u.getLists().size());
}*/

TEST_F(UserSuite, TestAddShoppingList) {
    u.addShoppingList(s3);

    auto listNames = u.getListName();
    ASSERT_EQ(3, listNames.size());
    ASSERT_NE(std::find(listNames.begin(), listNames.end(), "sport"), listNames.end()); // Verifica che "sport" sia presente
}

TEST_F(UserSuite, TestRemoveShoppingList) {
    u.removeShoppingList("giardino");

    auto listNames = u.getListName();
    ASSERT_EQ(1, listNames.size());
    ASSERT_EQ(std::find(listNames.begin(), listNames.end(), "giardino"), listNames.end()); // Verifica che "giardino" non sia presente
}



