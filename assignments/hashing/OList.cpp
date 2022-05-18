#include <iostream> 
#include "OList.h" 


OList::OList() { 
    head = nullptr;
    size = 0; 
}

OList::~OList() { 
     ONode *walker = head;
     head = nullptr; 
     ONode *trailer;
    
 
  while(walker != nullptr){
    trailer = head;
    walker = walker->getNext();
    delete trailer;
  }
  
}

ONode* OList::getHead() { 
    return this->head; 
}

void OList::insert(Person *p) { //insert a new node with value into the list in its proper location.

    ONode *temp = new ONode(p);
    temp->setNext(head);
    this->head = temp;

        // ONode *newN = new ONode(p); 
        // ONode *walker = head; 

        // if (head == nullptr) { 
        //     head = newN;
        //     return;
        // }
        // else if (n < head->getData()) { 
        //     walker = head;
        //     head = newN;
        //     head->setNext(walker);
        //     return;
        // }

        // while (walker->getNext() != nullptr) { 

        //      if(walker->getData() < n && walker->getNext()->getData() > n) { 

        //          newN->setData(n);
        //          newN->setNext(walker->getNext()); 
        //          walker->setNext(newN);

        //      }
             
        //     walker = walker->getNext(); 

        // } 

        // if(walker->getData() < n) { 
        //     walker->setNext(new ONode(n));
        // }
        
}


std::string OList::toString() { //return a string representation of the full list.

    ONode *walker = head; 
    std::string s = ""; 

    while (walker != nullptr) { 
      
        s = s+ walker->getPerson()->get_name() + "-->"; 
        walker = walker->getNext(); 
    }

    s = s+"nullptr"; 
    return s;  

} 

// bool OList::contains(int n) {  // returns true if value is in the list, false otherwise.

//     // ONode* temp = head;
//     // while(temp != nullptr) {
//     //     if (temp->getData() == n) { 
//     //         return true;
//     //     }
//     //     else { 
//     //         temp = temp->getNext();
//     //     }
//     // }
//     return false; 
// } 


void OList::get(int loc, Person *p) {  //returns the value at loc

   ONode *walker = head;
   ONode *Node = new ONode(p);

   if(loc == 0){
       Node->setNext(head);
       head = Node;
   }
   while (walker != nullptr && loc > 1)
   {
       walker = walker->getNext();
       loc-=1;
   }

   Node->setNext(walker->getNext());
   walker->setNext(Node);
   

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

// void OList::reverse() {  //This should “reverse” the list - that is reverse the pointers. 

//     if(head == nullptr || head->getNext() == nullptr){
//         return;
//     }

//     ONode *walker = head;
//     ONode *reverseWalker = nullptr; 
//     ONode *temp = nullptr;

//     while (walker != nullptr) { 

//         temp = walker->getNext();
//         walker->setNext(reverseWalker);
//         reverseWalker = walker;
//         walker = temp;

//     }
//     head = reverseWalker; 
// }