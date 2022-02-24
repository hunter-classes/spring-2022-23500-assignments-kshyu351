#include <iostream>
#include "Node.h"
#include "List.h"

// int main (int argc, char *argy[]) { 
    
// }

int main() { 

    List *l1 = new List(); 
    std::cout << l1->toString() << "\n"; 

    l1->insert("a");
    l1->insert("b");
    l1->insert("c");
    l1->insert("d");
    l1->insert("e");

      std::cout << l1->toString() << "\n"; 
      std::cout << std::endl; 
      Node *n = new Node("new_node");

    l1->locate(2,n); 
    std::cout << "Inserting a new node in specified location: " << std::endl; 
    std::cout << l1->toString() << "\n"; 
    std::cout << std::endl; 

    Node *n2 = new Node("new_node2");
    l1->locate(4,n2); 
    std::cout << "Inserting a new node in specified location: " << std::endl; 
    std::cout << l1->toString() << "\n"; 
    std::cout << std::endl; 

    l1->remove(2); 
    std::cout << "Removing node at specified location: " << std::endl; 
    std::cout << l1->toString() << "\n"; 
    std::cout << std::endl; 

    l1->remove(1); 
    std::cout << "Removing node at specified location: " << std::endl; 
    std::cout << l1->toString() << "\n"; 
    std::cout << std::endl; 

    l1->remove(4); 
    std::cout << "Removing node at specified location: " << std::endl; 
    std::cout << l1->toString() << "\n"; 
    std::cout << std::endl; 

      l1->remove(0); 
    std::cout << "Removing node at specified location: " << std::endl; 
    std::cout << l1->toString() << "\n"; 
    std::cout << std::endl; 

   



}