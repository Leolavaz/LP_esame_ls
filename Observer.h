
#ifndef UNTITLED40_OBSERVER_H
#define UNTITLED40_OBSERVER_H

#include <string>

using namespace std;

class Observer {
public:
    virtual ~Observer() = default;

    virtual void update(const string &listName) = 0;
};


#endif //UNTITLED40_OBSERVER_H
