


#include "gtest/gtest.h"
#include "../Observer.h"
#include "../ShoppingList.h"


class ObserverTest : public testing::Test, public Observer {
public:
    void update(const string &listName) override {
        updated = true;
    }

    bool isUpdated() const {
        return updated;
    }

    int getCountUpdate()const{
        return countUpdate;
    };
protected:

    void SetUp() override {
        s.subscribe(this);

    }

    void TearDown() override {
        s.unsubscribe(this);
    }


    bool updated = false;
    int countUpdate=0;
    ShoppingList s{"sport"};
    Item palla{"palla", "calcio", 3};

};


TEST_F(ObserverTest, Update) {
    ASSERT_FALSE(isUpdated());
    ASSERT_EQ(getCountUpdate(), 0);

    s.addItem(palla);
    ASSERT_TRUE(isUpdated());
    ASSERT_EQ(getCountUpdate(), 1);

    s.addItem(palla);
    ASSERT_EQ(getCountUpdate(), 2);
}


