

#ifndef UNTITLED40_USER_H
#define UNTITLED40_USER_H

#include "ShoppingList.h"
#include "Observer.h"
#include <iostream>
#include <algorithm>
#include <exception>
#include <stdexcept>
#include <memory>
#include <vector>

using namespace std;

class User : public Observer {
public:
    virtual ~User() {
        for (auto &itr: myLists)
            itr.second->unsubscribe(this);
    }

    virtual void update(const string &listName) override;

    void addShoppingList(ShoppingList &shoppingList);

    void removeShoppingList(const string &name);

    const map<string, shared_ptr<ShoppingList >> &getLists() const;
    vector<string> getListName() const;

private:
    string UserName;
    map<string, shared_ptr<ShoppingList>> myLists;

};


#endif //UNTITLED40_USER_H
