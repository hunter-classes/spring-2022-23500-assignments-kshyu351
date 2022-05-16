#include <iostream>
#include "Node.h"
//#include "Node.cpp"
#include "BSTree.h"
//#include "BSTree.cpp"



int main() { 
    //setting the values of the nodes 
    Node *root = new Node(2); 
    std::cout << root->getData() << std::endl; 
    Node *p1 = new Node(4); 
    Node *p2 = new Node(6); 
    Node *c1 = new Node(8); 
    Node *c2 = new Node(12); 
    Node *c3 = new Node(12); 
    Node *c4 = new Node(18); 


    //setting the values of the nodes and their children and then printing them on separate lines 
    root->setLeft(p1);
    std::cout << root->getLeft()->getData() << std::endl; 
    root->setRight(p2);
    std::cout << root->getRight()->getData() << std::endl; 
    p1->setLeft(c1);
    std::cout << root->getLeft()->getLeft()->getData() << std::endl; 
    p1->setRight(c2);
    std::cout << root->getLeft()->getRight()->getData() << std::endl; 
    p2->setLeft(c3);
    std::cout << root->getRight()->getLeft()->getData() << std::endl; 
    p2->setRight(c4);
    std::cout << root->getRight()->getRight()->getData() << std::endl; 

    // BSTree *t = new BSTree();
    // t->setup();

    //teting get_debug_string() to see if it prints the value of the root 
   // std::cout << t->get_debug_string() << std::endl;


  BSTree *t = new BSTree();
  t->setup();

    std::cout << std::endl; 
    std::cout << "Printing out all the nodes in order from root, left subtree, then right subtree: " << std::endl;
  std::cout <<  t->get_debug_string() << "\n";

  

  try {
    int x  = t->rsearch(5);
    std::cout << std::to_string(x) << " is in the tree" "\n";
  } 

  catch (int e) {
    std::cout << "5 is not in the tree\n";

 }

  try {
    int x  = t->rsearch(10);
    std::cout << "10 is in the tree\n";
  
  } 

  catch (int e) {
    std::cout << "10 is not in the tree\n";

  }

  try {
    int x  = t->rsearch(-10);
    std::cout << "-10 is in the tree\n";
  
  } 

  catch (int e) {
    std::cout << "-10 is not in the tree\n";

  }

  try {
    int x  = t->rsearch(7);
    std::cout << "7 is in the tree\n";
  
  } 

  catch (int e) {
    std::cout << "7 is not in the tree\n";

  }


  // std::cout <<  t->get_debug_string() << "\n";
//   BSTree *t2 = new BSTree();
//    t2->setup();
//   // std::cout << t2->get_debug_string() << std::endl;
//    t2->deleteNode(5);
//    std::cout << t2->get_debug_string() << std::endl;
  

//  t2->deleteNode(3);


//    std::cout << t2->get_debug_string() << std::endl;

  
//   t2->deleteNode(9);
//    std::cout << t2->get_debug_string() << std::endl;
   



  


   
    




  







}