

#include "User.h"

void User::addShoppingList(ShoppingList &shoppingList) {
    auto sListPtr = make_shared<ShoppingList>(shoppingList);
    myLists.insert(make_pair(shoppingList.getShoppingListName(), sListPtr));
    shoppingList.subscribe(this);
}


void User::removeShoppingList(const string &name) {
    auto itr = myLists.find(name);
    if (itr == myLists.end()) {
        throw std::invalid_argument("Nome lista non valido");
    } else {
        itr->second->unsubscribe(this);
        myLists.erase(name);
    }
}


void User::update(const string &listName) {

    auto itr = myLists.find(listName);
    cout << "Lista ' " << listName << " ' aggiornata: " << endl;
    cout << endl;
}

const map<string, shared_ptr<ShoppingList>> &User::getLists() const {
    return myLists;
}

