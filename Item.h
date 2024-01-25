
#ifndef UNTITLED40_ITEM_H
#define UNTITLED40_ITEM_H

#include <string>
#include <exception>
#include <stdexcept>


using namespace std;

class Item {
public:
    Item(string s, string c, int q = 1) : IName(std::move(s)), category(std::move(c)) {
        if (q >= 0)
            quantity = q;
        else
            throw out_of_range("La quantità deve essere positiva");
    }

    const string &getIname() const {
        return IName;
    };

    const string &getCat() const {
        return category;
    }

    void setQuantity(int q) {
        if (q >= 0) {
            quantity = q;
        } else throw out_of_range(" La quantità deve essere positiva");
    }

    int getQuantity() const {
        return quantity;
    }

    bool getBought() const {
        return bought;
    }

    void setBought(bool b) {
        bought = b;
    }


private:
    string IName;
    int quantity;
    string category;
    bool bought;
};


#endif //UNTITLED40_ITEM_H
