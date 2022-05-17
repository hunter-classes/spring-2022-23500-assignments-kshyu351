#pragma once
#include "Person.h"

class ONode {
      private:
        Person *p;
        ONode *next;

    public:
        ONode();
        ONode(Person *p);
        ONode(Person *p, ONode *next);

        void setPerson(Person *p);
        void setNext(ONode *next);

        Person* getPerson();
        ONode *getNext()
};