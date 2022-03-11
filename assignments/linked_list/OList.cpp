#include <iostream> 
#include "OList.h" 


OList::OList() { 
    head = nullptr; 
}

OList::~OList() { 
     ONode *trailer;
    
 
  while(head != nullptr){
    trailer = head;
    head = head->getNext();
    delete trailer;
  }
  
}

void OList::insert(int n) { //insert a new node with value into the list in its proper location.


        ONode *walker = head->getNext(); 
        if (n < walker->getData()) { 
            ONode *new_ONode = new ONode(n);
            head->setNext(new_ONode);
            new_ONode->setNext(walker);
        }

     
       while (walker->getNext() != nullptr) { 

             if(walker->getData() < n && walker->getNext()->getData() > n) { 
                  ONode *new_ONode = new ONode();  

                 new_ONode->setData(n);
                 new_ONode->setNext(walker->getNext()); 
                 walker->setNext(new_ONode);

             }
             
            walker = walker->getNext(); 

        } 

        if(walker->getData() < n) { 
            walker->setNext(new ONode(n));
        }
}


std::string OList::toString() { //return a string representation of the full list.

  ONode *walker = head; 
    std::string s = ""; 
    std::cout << walker << "\n";

    while (walker != nullptr) { 
        s = s+ std::to_string(walker->getData()) + "-->"; 
        walker = walker->getNext(); 
    }

    s = s+"nullptr"; 
    return s;  

} 

bool OList::contains(int n) {  // returns true if value is in the list, false otherwise.

    ONode* temp = head;
    if(temp != nullptr) {
    while(temp != nullptr) {
        if (temp->getData() == n) { 
            return true;
        }
        else { 
            temp = temp->getNext();
        }
    }
  }
  return false; 
} 


int OList::get(int loc) {  //returns the value at loc

    ONode *walker = head; 

    for (int i = 0; i < loc-1; i++) { 
        walker = walker->getNext(); 
        
    } 
    return walker->getData(); 
}

void OList::remove(int loc) {   
 //locates the node referred to by the index 
    ONode *walker = head; 

    if(loc == 0) { 
    ONode *head2 = head; 
    delete head2; 
    head = head->getNext();
    }
    for (int i = 0; i < loc-1; i++) { 
    walker = walker->getNext(); 
    }

    //creates new node to store the earlier heads that were inserted first 
    ONode *head2 = walker->getNext()->getNext();

    //deletes nodes from the index 
    delete walker->getNext(); 

    //sets walker node to earlier heads 
    walker->setNext(head2);
} 

void OList::reverse() {  //This should “reverse” the list - that is reverse the pointers.   
    

}