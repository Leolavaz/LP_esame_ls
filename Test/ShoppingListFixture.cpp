


#include "gtest/gtest.h"
#include "../ShoppingList.h"
#include "../User.h"

class ShoppingListSuite:  public::testing::Test{

protected:

    void SetUp() override {
        s.addItem(ciliegia);
        s.addItem(insalata);
        s.addItem(pane);
    }


    ShoppingList s{"casa"};
    Item ciliegia{"mela","frutta",1};
    Item insalata{"insalata","verdura",1};
    Item pane{"pane","cibo",5};
    User user;
};



TEST_F(ShoppingListSuite, TestParametrizeConstructor) {
    ShoppingList sl("Animali");
    ASSERT_EQ(sl.getShoppingListName(),"Animali");
}


TEST_F(ShoppingListSuite, TestAddItem) {
    Item carne("carne","cibo",4);
    s.addItem(carne);
    int size=s.getShoppingList().size();
    ASSERT_EQ(size,4);

    Item carne2("carne","cibo",2);
    s.addItem(carne2);
    size=s.getShoppingList().size();
    ASSERT_EQ(size,4);

    auto itr= s.getShoppingList().find("pane");
    itr->second->setQuantity(2);
    auto ris= itr->second->getQuantity();
    ASSERT_EQ(size,4);
    ASSERT_EQ(ris,2);
}



TEST_F(ShoppingListSuite, TestRemoveItem) {
    s.removeItem("mela");
    int size=s.getShoppingList().size();
    ASSERT_EQ(size,2);
}
//aggiungere test per rimozione impossibile

TEST_F(ShoppingListSuite, ImpTestRemove){
    s.removeItem("carota");
    int size=s.getShoppingList().size();
    ASSERT_EQ(size,2);
}



TEST_F(ShoppingListSuite,TestSubject)
{
    s.subscribe(&user);
    ASSERT_EQ(1,s.getObservers().size());

    s.unsubscribe(&user);
    ASSERT_EQ(0,s.getObservers().size());
}








