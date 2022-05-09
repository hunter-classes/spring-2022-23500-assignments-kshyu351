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

// we will always insert new nodes as leaves
void BSTree::insert(int value) {
     Node *newnode = new Node(value);

  Node *p = root;
  Node *trailer;

  

//   if (trailer == nullptr) { 
//       break; 
//   }

//   trailer = p;

//   else if (p->getData() < value) { 
//         insert(p->getLeft())); 

//   }
//     else if (p->getData() > value) { 
//         insert(p->getRight()); 

//   }
//  if (root==nullptr){
//     root=newnode;
//   } 
//   else {
//     // trailer points to the node ABOVE where the new node
//     // will go.
//     // we have to figure out if newnode goes on the
//     // left of trailer or on the right of trailer
//     if (trailer->getData() < value){
//       trailer->setRight(newnode);
//     } else {
//       trailer->setLeft(newnode);
//     }

//   }

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
      w = w->getLeft();
      tail = w;
    
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
            //tail->getRight()->setData(w->getData());

            
  
            // w->setRight(nullptr);
            // delete w->getRight();
           

          }
          else if (w->getData() < tail->getData()) {
            tail->setLeft(w->getLeft());
          }
       
        }
        else if (w->getLeft() == nullptr) {
          if (w->getData() > tail->getData()) { 
            tail->setRight(w->getRight());

          }
          else if (w->getData() < tail->getData()) {
            tail->setLeft(w->getRight());
          }
         
        }
      }


      //if it has 2 children 
      //largest member of left subtree
      else if (((w->getRight() != nullptr) && (w->getLeft()) != nullptr)) { 
      
         Node *max = w->getLeft(); 
          while (max != nullptr) { 
            max = max->getRight(); 
          } 
      
        //if node to be deleted is left subtree
        if (w->getData() < tail->getData()) { 
          std::cout << "test\n";

         
           tail->getLeft()->setData(max->getData());
           max = nullptr;;
           delete max; 

           std::cout << "test\n";
   
        
        }
        else if (w->getData() > tail->getData()) { 
         
          tail->getRight()->setData(max->getData());
           max = nullptr;;
           delete max;

      

          std::cout << "test\n";
        
        }
      }

       tail= nullptr;
          delete tail;
          return;

          
}










        

  


  