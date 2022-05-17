#pragma once 
#include "ONode.h"

//same as List but should store items in increasing order.

class OList{ 
    private:
        ONode *head; 


    public: 
        OList();
        ~OList();
        void insert(Person *p); //insert a new node with value into the list in its proper location.
        std::string toString(); //return a string representation of the full list.
        bool contains(int n); // returns true if value is in the list, false otherwise.
        Person get(int loc); //returns the value at loc
        void remove(int loc);  //returns the value at loc
        void reverse(); //This should “reverse” the list - that is reverse the pointers.         
}; 