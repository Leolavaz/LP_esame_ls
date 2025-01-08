

#include "ShoppingList.h"


void ShoppingList::subscribe(Observer *o) {
    observers.push_back(o);
}


void ShoppingList::unsubscribe(Observer *o) {
    observers.remove(o);
}


void ShoppingList::notify() {
    for (auto &itr: observers)
        itr->update(SL_name);
}


void ShoppingList::setItemBought(const std::string &name) {
    auto itr = SL.find(name);
    if (itr != SL.end()) {
        itr->second->setBought(true);
        notify();
    } else
        throw std::invalid_argument("Nome oggetto non valido");
}

void ShoppingList::addItem(const Item &item) {

    auto itr = SL.find(item.getIname());
    if (itr != SL.end() && itr->second->getCat() == item.getCat()) //l'oggetto è già presente
    {
        int result = itr->second->getQuantity() + item.getQuantity();
        itr->second->setQuantity(result);
    } else {
        auto itemPtr = make_shared<Item>(item);
        SL.insert(make_pair(item.getIname(), itemPtr));
    }

    string itemCat = item.getCat();   //serve in seguito per andare a stampare gli oggetti in base alla categoria
    bool k = false;
    for (auto &it: category) {
        if (it.first == itemCat) {
            k = true;  //categoria già  presente, aggiorno numero oggetti nella categoria
            it.second++;
            break;
        }
    }
    if (!k) {
        category.insert(make_pair(itemCat, 1));
    }

    notify();

}

void ShoppingList::removeItem(const std::string &name) {
    auto itr = SL.find(name);
    if (itr == SL.end()) {
        throw std::invalid_argument("Oggetto non presente");
    } else {
        auto itc = category.find(itr->second->getCat());      //tratto la mappa di categorie
        itc->second--;
        if (itc->second == 0)//e' presente solo l'elemento in questione
        {
            category.erase(itc);
        }

        itr->second->setQuantity(0);
        SL.erase(itr);        //tratto la mappa di oggetti

        notify();
    }

}

const string &ShoppingList::getShoppingListName() const {
    return SL_name;
}



vector<shared_ptr<Item>> ShoppingList::getShoppingList() const {
    vector<shared_ptr<Item>> itemList;
    for (const auto &pair : SL) {
        itemList.push_back(pair.second);
    }
    return itemList;
}


const list<Observer *> &ShoppingList::getObservers() const {
    return observers;
}

const map<string, int> &ShoppingList::getCategories() const {
    return category;
}

map<string, vector<shared_ptr<Item>>> ShoppingList::getItemsByCategory() const {
    map<string, vector<shared_ptr<Item>>> itemsByCategory;
    for (const auto &pair : SL) {
        itemsByCategory[pair.second->getCat()].push_back(pair.second);
    }
    return itemsByCategory;
}

vector<shared_ptr<Item>> ShoppingList::getUnboughtItems() const {
    vector<shared_ptr<Item>> unboughtItems;
    for (const auto &pair : SL) {
        if (!pair.second->getBought()) {
            unboughtItems.push_back(pair.second);
        }
    }
    return unboughtItems;
}

