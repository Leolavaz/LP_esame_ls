
#include "gtest/gtest.h"
#include"../Item.h"


TEST(ItemSuite,TestConstructor)
{
    Item i("pane","cibo",6);
    ASSERT_EQ(i.getQuantity(),6);
    ASSERT_EQ(i.getCat(),"cibo");
    ASSERT_EQ(i.getIname(),"pane");

    ASSERT_THROW(Item i2("pane","cibo",-2) ,out_of_range);
}


TEST(ItemSuite, TestSetItemquantity) {
    Item i("pane","cibo",3);
    ASSERT_THROW(i.setQuantity(-2),out_of_range);
}
