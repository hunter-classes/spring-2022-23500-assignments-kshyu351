#include <iostream>
#include "ONode.h"
#include "OList.h"


int main() { 

    OList *l = new OList(); 

    l->insert(1);
    l->insert(10);
    l->insert(4);
    l->insert(-2);
    l->insert(2);

    int x = l->get(3); 
    std::cout << x << std::endl;
    std::string s = l->toString(); 
    std::cout << s << std::endl; 
    bool test = l->contains(-100); 
    l->remove(2); 
    std::cout << l->toString() << std::endl;
    std::cout << l->contains(1)<< std::endl;// true
    std::cout << l->contains(11)<< std::endl;// false

    l->reverse();
    std::cout << l->toString() << std::endl;




    // List *l1 = new List(); 
    // std::cout << l1->toString() << "\n"; 

    // l1->insert("a");
    // l1->insert("b");
    // l1->insert("c");
    // l1->insert("d");
    // l1->insert("e");

    //   std::cout << l1->toString() << "\n"; 
    //   std::cout << std::endl; 
    //   Node *n = new Node("new_node");

    // l1->locate(2,n); 
    // std::cout << "Inserting a new node in specified location: " << std::endl; 
    // std::cout << l1->toString() << "\n"; 
    // std::cout << std::endl; 

    // Node *n2 = new Node("new_node2");
    // l1->locate(4,n2); 
    // std::cout << "Inserting a new node in specified location: " << std::endl; 
    // std::cout << l1->toString() << "\n"; 
    // std::cout << std::endl; 

    // l1->remove(2); 
    // std::cout << "Removing node at specified location: " << std::endl; 
    // std::cout << l1->toString() << "\n"; 
    // std::cout << std::endl; 

    // l1->remove(1); 
    // std::cout << "Removing node at specified location: " << std::endl; 
    // std::cout << l1->toString() << "\n"; 
    // std::cout << std::endl; 

    // l1->remove(4); 
    // std::cout << "Removing node at specified location: " << std::endl; 
    // std::cout << l1->toString() << "\n"; 
    // std::cout << std::endl; 

    //   l1->remove(0); 
    // std::cout << "Removing node at specified location: " << std::endl; 
    // std::cout << l1->toString() << "\n"; 
    // std::cout << std::endl; 

    // Node *n3 = new Node("new_node3"); 
    // l1->locate(0,n3);
    //   std::cout << "Inserting a new node in specified location: " << std::endl; 
    // std::cout << l1->toString() << "\n"; 
    // std::cout << "ZZZ\n";
    // std::cout << std::endl; 


}