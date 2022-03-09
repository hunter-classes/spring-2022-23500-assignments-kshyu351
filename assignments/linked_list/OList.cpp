#include <iostream> 
#include "OList.h" 

OList::OList() { 
    head = nullptr; 
}

OList::~OList() { 
    delete[] head;
}

OList::void insert(std::string s) { //insert a new node with value into the list in its proper location.

    //how come locate(0,n) gives error ? 

    if (index == 0) { 
        //what zman wrote in class 
        //throw std::out_of_range("out of range"); 

        std::cout << head << ":" << n << "\n";
        n->setNext(head); 
        head = n; 
    }
    else { 
        //locates the node referred to by the index 
        Node *walker = head; 
        for (int i = 0; i < index; i++) { 
            walker = walker->getNext(); 
        }

        //creates new node to store the earlier heads that were inserted first 
        Node *head2 = walker->getNext();

        //inserts the new node 
        walker->setNext(n);

        //puts in old heads in new node 
        n->setNext(head2);
    }
}



std::string OList::toString() { //return a string representation of the full list.

  Node *walker = head; 
    std::string s = ""; 
    std::cout << walker << "\n";

    while (walker != nullptr) { 
        s = s+ walker->getData() + "-->"; 
        walker = walker->getNext(); 
    }

    s = s+"nullptr"; 
    return s;  

} 

bool OList::contains(std::string value) {  // returns true if value is in the list, false otherwise.

    Node* temp = head;
    if(temp != NULL) {
    while(temp != NULL) {
        if (temp == value) { 
            return true;
        }
        else { 
            temp = temp->next;
        }
    }
    return false; 
  } 


std::string OList::get(loc) {  //returns the value at loc

    Node *walker = head; 

    for (int i = 0; i < loc-1; i++) { 
        walker = walker->getNext(); 
        return walker->getData(); 
    } 
}

void OList::remove(loc) {   
 //locates the node referred to by the index 
    Node *walker = head; 

    if(loc == 0) { 
    Node *head2 = head; 
    delete head2; 
    head = head->getNext();
    }
    for (int i = 0; i < loc-1; i++) { 
    walker = walker->getNext(); 
    }

    //creates new node to store the earlier heads that were inserted first 
    Node *head2 = walker->getNext()->getNext();

    //deletes nodes from the index 
    delete walker->getNext(); 

    //sets walker node to earlier heads 
    walker->setNext(head2);
} 

void OList::reverse() {  //This should “reverse” the list - that is reverse the pointers.   
    
} 