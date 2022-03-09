#include <iostream> 
#include "List.h" 

List::List() { 
    head = nullptr; 
}

List::~List() { 
    delete[] head;
}

void List::insert(std::string data) { 

    //create a new node 
    Node *new_node = new Node(data); 

    //insert the new node 
    new_node->setNext(head); 
    head=new_node; 
}

std::string List::toString() { 
  
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

void List::locate(int index, Node *n) { //same as insert 

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

   
void List::remove(int index) { 

    //locates the node referred to by the index 
    Node *walker = head; 

    if(index == 0) { 
    Node *head2 = head; 
    delete head2; 
    head = head->getNext();
    }
    for (int i = 0; i < index-1; i++) { 
    walker = walker->getNext(); 
    }

    //creates new node to store the earlier heads that were inserted first 
    Node *head2 = walker->getNext()->getNext();

    //deletes nodes from the index 
    delete walker->getNext(); 

    //sets walker node to earlier heads 
    walker->setNext(head2);
} 
























 

