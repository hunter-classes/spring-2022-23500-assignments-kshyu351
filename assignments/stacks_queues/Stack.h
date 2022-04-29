#pragma once 
#define STACK_ERR_EMPTY 1
#define STACK_ERR_FULL 2
#define STACK_ERR_OTHER 4
#include "List.h"

class Stack { 
    private: 
        List *s;
        int size;

    public:
        Stack(); 
        ~Stack(); 
        void push(int); 
        int pop(); //remove and return the top item
        int top(); // return but do not remove the top item
        bool is_empty(); // return true if empty, false otherwise
};

