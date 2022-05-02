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
    Node *n = new Node(7);
    root = n;
    n = new Node(5);
    root->setLeft(n);
    n = new Node(9);
    root->setRight(n);
    n = new Node(3);
    root->getLeft()->setLeft(n);
     n = new Node(6);
    root->getLeft()->setRight(n);
     n = new Node(8);
    root->getRight()->setLeft(n);
     n = new Node(10);
    root->getRight()->setRight(n);


 
}


int BSTree::rsearch(int value, Node *n) {

    if(n == nullptr) { 
        throw 1; 
    }
    int nval = n->getData(); 

    if(nval == value) { 
        return value;
    }
    
    else if (value < nval) { 
       n = n->getLeft(); 
       return rsearch(value, n); 
    }

    else if (value > nval) { 
        n = n->getRight(); 
        return rsearch(value, n);   
    }
    throw 1; 
   
}

int BSTree::rsearch(int value) {
  
   return rsearch(value,root);

}

int BSTree::search(int value){
  Node *t = root;

  while (t != nullptr){
    int tval = t->getData();
    if (tval==value){
      // here we'd really return a full object
      // with all the stuff associated with value
      // not just an int
      return value;
    }

    if (tval < value){
      t = t->getRight();
    } else {
      t = t->getLeft();
    }
    
  }

  // if we get here then the value isn't
  // in the tree

  // normally, if we had a tree of objects
  // we could return null but since we only have
  // an int, we can't return an int to represent
  // not found so we'll throw an exception

  throw 1; // we should define our exceptions.

    
  
}


