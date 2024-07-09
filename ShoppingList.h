
#ifndef UNTITLED40_SHOPPINGLIST_H
#define UNTITLED40_SHOPPINGLIST_H


#include "Observer.h"
#include "Subject.h"
#include "Item.h"
#include <map>
#include <list>
#include <string>
#include <utility>
#include <exception>
#include <stdexcept>
#include <memory>

#include <iostream>

using namespace std;


class ShoppingList : public Subject {
public:

    ShoppingList(const string &SL_N) : SL_name(SL_N) {}

    virtual ~ShoppingList() = default;

    virtual void subscribe(Observer *o) override;

    virtual void unsubscribe(Observer *o) override;

    virtual void notify() override;

    void addItem(const Item &item);

    void removeItem(const string &name);

    const string &getShoppingListName() const;

    void setItemBought(const string &name);

    void setShoppingListName(const string &shoppingListName);

    const map<string, shared_ptr<Item>> &getShoppingList() const;

    const list<Observer *> &getObservers() const;

    const map<string, int> &getCategories() const;


private:
    string SL_name;
    list<Observer *> observers;
    map<string, shared_ptr<Item>> SL;
    map<string, int> category;

};


#endif //UNTITLED40_SHOPPINGLIST_H
