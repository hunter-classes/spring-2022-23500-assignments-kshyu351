#pragma once 
#include "Node.h"

class List{ 
    private:
        Node *head; 


    public: 
        List();
        ~List();
        void insert(int data);
        std::string toString();
        int locate(int index);
       void remove(int index); 


        
     
}; 