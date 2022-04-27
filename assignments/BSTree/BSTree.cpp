#include <iostream>
#include "BSTree.h"
#include "Node.h"

BSTree::BSTree() { 
    root = nullptr; 
}


std::string BSTree::get_debug_string() { 
    if (root == nullptr) { 
        return "";
    }
    else { 
        return std::to_string(root->getData());
    }
   
}

void BSTree::setup() {
    Node *n = new Node(10);
    root = n;
    n = new Node(20);
    root->setLeft(n);
    n = new Node(30);
    root->setRight(n);
    n = new Node(40);
    root->getLeft()->setLeft(n);
 
}