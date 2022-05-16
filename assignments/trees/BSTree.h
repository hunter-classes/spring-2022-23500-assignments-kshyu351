#pragma once 

#include "Node.h"

class BSTree { 
    private: 
        Node *root; 

    public:
        BSTree();
        void insert(int d);
        std::string get_debug_string();
        std::string get_debug_string_helper(Node *n);

        void setup(); 

        int rsearch(int value, Node *n); 
        int rsearch(int value);
        Node* search(int value); 
        void deleteNode(int value);

        int countLeaves(); 
       
        int countHeight(); 
        int countSum(int level); 
        int getLevel(int target); 
        bool isCousins(int n, int m);


};