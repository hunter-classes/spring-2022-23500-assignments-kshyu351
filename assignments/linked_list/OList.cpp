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

        ONode *newN = new ONode(n); 
        ONode *walker = head; 

        if (head == nullptr) { 
            head = newN;
            return;
        }
        else if (n < head->getData()) { 
            walker = head;
            head = newN;
            head->setNext(walker);
            return;
        }

        while (walker->getNext() != nullptr) { 

             if(walker->getData() < n && walker->getNext()->getData() > n) { 

                 newN->setData(n);
                 newN->setNext(walker->getNext()); 
                 walker->setNext(newN);

             }
             
            walker = walker->getNext(); 

        } 

        if(walker->getData() < n) { 
            walker->setNext(new ONode(n));
        }
        
}


std::string OList::toString() { //return a string representation of the full list.

    ONode *walker = head; 
    std::string s = "head-->"; 

    while (walker != nullptr) { 
      
        s = s+ std::to_string(walker->getData()) + "-->"; 
        walker = walker->getNext(); 
    }

    s = s+"nullptr"; 
    return s;  

} 

bool OList::contains(int n) {  // returns true if value is in the list, false otherwise.

    ONode* temp = head;
    while(temp != nullptr) {
        if (temp->getData() == n) { 
            return true;
        }
        else { 
            temp = temp->getNext();
        }
    }
    return false; 
} 


int OList::get(int loc) {  //returns the value at loc

    ONode *walker = head; 

    for (int i = 0; i < loc; i++) { 
        walker = walker->getNext();  
    } 
    return walker->getData(); 

}

void OList::remove(int loc) {   
 //locates the node referred to by the index 
    ONode *walker = head; 

    if(loc == 0) { 
        ONode *head2 = head; 
        head = head->getNext();
        delete head2; 
    }
    for (int i = 0; i < loc; i++) { 
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

    if(head == nullptr || head->getNext() == nullptr){
        return;
    }

    ONode *walker = head;
    ONode *reverseWalker = nullptr; 
    ONode *temp = nullptr;

    while (walker != nullptr) { 

        temp = walker->getNext();
        walker->setNext(reverseWalker);
        reverseWalker = walker;
        walker = temp;

    }
    head = reverseWalker; 
}