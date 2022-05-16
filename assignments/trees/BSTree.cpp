#include <iostream>
#include "BSTree.h"
#include "Node.h"


BSTree::BSTree() { 
    root = nullptr; 
}

// we will always insert new nodes as leaves
void insertHelper(int value, Node* current){
  if(value > current->getData()){
    if(current->getRight() == nullptr){
      current->setRight(new Node(value));
    }
    else return insertHelper(value,current->getRight());
  }
  else if (value < current->getData()){
    if(current->getLeft() == nullptr){
      current->setLeft(new Node(value));
    }
    else return insertHelper(value,current->getLeft());
  }
}

void BSTree::insert(int value) {
  if(root == nullptr){
    root = new Node(value);
  }
  else return insertHelper(value,root);

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
    insert(15);
    insert(16);


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

Node* BSTree::search(int value){
  Node *t = root;

  while (t != nullptr){
    int tval = t->getData();
    if (tval==value){
      // here we'd really return a full object
      // with all the stuff associated with value
      // not just an int
      return t;
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

void BSTree::deleteNode(int value) { 

  //delete a leaf 
  Node *w = root;
  Node *tail = w;


  while (w != nullptr) {
  
    if (w->getData() == value) {
      break;
    }
    else if (w->getData() < value) {
      tail = w; 
      w = w->getRight(); 
     
    } 

    else if (w->getData() > value) {
      tail = w;
      w = w->getLeft();
      
    
    }
  }

      //if it is a leaf 
      if (w->getRight() == nullptr && w->getLeft() == nullptr) { 
      
        //if its value is less than the parent then its the left child 
        if(value < tail->getData()) {
         
            
         // w->setLeft(nullptr);
         tail->setLeft(nullptr);
        }
        else if (value > tail->getData()) { 
           
            
             
          tail->setRight(nullptr);
          // delete w->getRight(); 

          
            
        //   w= nullptr;
        // delete w;
        // return;
          
        }
        

      }
      //if it has 1 child 
      else if ((((w->getRight() == nullptr) && (w->getLeft()) != nullptr)) || (((w->getRight() != nullptr) && (w->getLeft() == nullptr)))) {
       // std::cout << "hi" << std::endl;
        //if it only has 1 left child 
        if (w->getRight() == nullptr) { 
          //std::cout << "hi" << std::endl;
          
          //if the node to be deleted is the left subtree 

          if (w->getData() == tail->getData()) { 
            //std::cout << "hi" << std::endl;
            tail->setRight(w->getRight());
            return; 
            //tail->getRight()->setData(w->getData());

            
  
            // w->setRight(nullptr);
            // delete w->getRight();
           

          }
          else if (w->getData() < tail->getData()) {
            tail->setLeft(w->getLeft());
          }
          else { 
            tail->setRight(w->getLeft());
          }

          
       
        }
        else if (w->getLeft() == nullptr) {
          if (w->getData() > tail->getData()) { 
            tail->setRight(w->getRight());
            return;

          }
          else if (w->getData() < tail->getData()) {
            tail->setLeft(w->getRight());
            return; 
          }
         
        }

      }


      //if it has 2 children 
      //largest member of left subtree
      else if (((w->getRight() != nullptr) && (w->getLeft()) != nullptr)) { 

       
      
         Node *max = w->getLeft(); 
          while (max->getRight() != nullptr) { 
            max = max->getRight(); 
          } 
      
        //if node to be deleted is left subtree

        if (tail == nullptr) {
          std::cout << "root\n";
          // max->setRight(w->getRight());
          // root->setData(max->getData());
          tail->setLeft(max);
        }
        


        //   max->setRight(w->getRight());

        // if (tail){
        //   tail->setLeft(max);
        // }
          //tail->setRight(max);
        
         if ((w->getData() < tail->getData())) { 
        
        
         max->setRight(w->getRight());
        
          
           tail->setLeft(max);
           

            delete max;
           max = nullptr;
          
         
        }
        else if (w->getData() > tail->getData()) { 
        //      if (tail == nullptr){
        //   std::cout << "root\n";
        //   // max->setRight(w->getRight());
        //   // root->setData(max->getData());
        //   tail->setLeft(max);
        // }
        
          // std::cout << "test2222\n";

          max->setRight(w->getRight());
    
          
           tail->setRight(max);
          

          //   delete max;
          //  max = nullptr;
           
        }
    
      }

}



int countLeavesHelper(Node* current)   {
    if (current == nullptr) { 
    return 0;
  }
  if ((current->getRight() == nullptr) && (current->getLeft() == nullptr)) { 
    return 1; 
  }
  else { 
    return countLeavesHelper(current->getRight()) + countLeavesHelper(current->getLeft());
  }
}
    

int BSTree::countLeaves() { 
  return countLeavesHelper(root);
  
}


int countHeightHelper(Node* current){
  if (current == nullptr) { 
    return -1;
  }
  int left = countHeightHelper(current->getLeft()); 
  int right = countHeightHelper(current->getRight()); 

  if (left < right) { 
    return right+1;
  } 
  else { 
    return left+1; 
  }
}

int BSTree::countHeight() { 
  return countHeightHelper(root);
}

int countSumHelper(int level,Node* current){
  if(level < 0) { 
    return -1;
  }
  if(level == 0) {
    if(current == nullptr) { 
      return 0;

    } 
    else { 
      return current->getData();
    }
  }
  else return countSumHelper(level-1,current->getLeft()) + countSumHelper(level-1,current->getRight());
}

int BSTree::countSum(int level) { 
  return countSumHelper(level, root);
}
int getLevelHelper(int target, Node *current) { 
  if (current == nullptr) { 
    throw 1;
  }
  
  if (current->getData() == target) { 
    return 0;
  }
  else { 
    if(current->getData() > target) {
      return 1 + getLevelHelper(target,current->getLeft());
    }
    else { 
      return 1 + getLevelHelper(target,current->getRight());
    }

  }
}

int BSTree::getLevel(int target) {
  return getLevelHelper(target, root);
}

bool BSTree::isCousins(int n, int m) { 
  return getLevel(search(n)->getData()) == getLevel(search(m)->getData());
}










        

  


  