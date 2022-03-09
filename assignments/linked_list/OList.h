#pragma once 
#include "Node.h"

//same as List but should store items in increasing order.

class OList{ 
    private:
        Node *head; 


    public: 
        OList();
        ~OList();
        void insert(std::string s); //insert a new node with value into the list in its proper location.
        std::string toString(); //return a string representation of the full list.
        bool contains(value); // returns true if value is in the list, false otherwise.
        std::string get(loc); //returns the value at loc
        void remove(loc);  //returns the value at loc
        void reverse(); //This should “reverse” the list - that is reverse the pointers.         
}; 