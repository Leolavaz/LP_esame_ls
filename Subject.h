

#ifndef UNTITLED40_SUBJECT_H
#define UNTITLED40_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual ~Subject() = default;

    virtual void subscribe(Observer *o) = 0;

    virtual void unsubscribe(Observer *o) = 0;

    virtual void notify() = 0;
};


#endif //UNTITLED40_SUBJECT_H
