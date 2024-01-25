


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

protected:

    void SetUp() override {
        s.subscribe(this);

    }

    void TearDown() override {
        s.unsubscribe(this);
    }

    bool updated = false;
    ShoppingList s{"sport"};
    Item palla{"palla", "calcio", 3};

};


TEST_F(ObserverTest, Update) {
    ASSERT_FALSE(isUpdated());

    s.addItem(palla);
    ASSERT_TRUE(isUpdated());
}


