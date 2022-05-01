#include <iostream>
#include "BSTree.h"
#include "Node.h"


BSTree::BSTree() { 
    root = nullptr; 
}

std::string BSTree::get_debug_string_helper(Node *n) { 

  
    std::string r = std::to_string(n->getData()); 
    std::string left = "";
    std::string right = "";

    if (!(n->getLeft() == nullptr)) { 
         left += get_debug_string_helper(n->getLeft());
    }
    if (!(n->getRight() == nullptr)) { 
          right += get_debug_string_helper(n->getRight());
    }
         
    return  r+"\n"+left+right; 


}

std::string BSTree::get_debug_string() { 
    if (root == nullptr) { 
        return "";
    }
    else { 
        return get_debug_string_helper(root);
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


int BSTree::rsearch(int value, Node *n) {

    int nval = n->getData(); 

    if(n == nullptr) { 
        throw "error"; 
    }
    else if(n->getData() == value) { 
        return value;
    }

    else if (value < nval) { 
        n = n->getLeft(); 
        rsearch(value, n); 
    }
    else { 
        n = n->getRight(); 
        rsearch(value, n);  
    }
    throw "error";
    
}

int BSTree::rsearch(int value) {
  
   return rsearch(value,root);

}

