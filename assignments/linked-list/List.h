#pragma once 
#include "Node.h"

class List{ 
    private:
        Node *head; 


    public: 
        List();
        ~List();
        void insert(std::string data);
        std::string toString();
        void locate(int index, Node *n);
       void remove(int index); 


        
     
}; 