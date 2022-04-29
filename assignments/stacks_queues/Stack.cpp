#include <iostream>
#include "Node.h"
#include "Stack.h"
#include "List.h"


Stack::Stack() { 
    s = new List(); 
    size = 0; 
}

Stack::~Stack() { 
    delete[] s;
}

void Stack::push(int n) { 

    s->insert(n); 
    size++; 
}

int Stack::pop() { 
    if (size == 0) {
        throw STACK_ERR_EMPTY;
    }
    else { 
        int num = s->locate(0); 
        s->remove(0);
        size--;
        return num; 
    }
}

int Stack::top() { 
    if (size == 0) {
        throw STACK_ERR_EMPTY;
    }
    else { 
        int num = s->locate(0); 
        return num; 
    }
}

bool Stack::is_empty(){
    if (size == 0) { 
        return true;
    }
    else { 
        return false; 
    }
}



    // if (t == nullptr) {
    //     throw std::out_of_range("Cannot pop an empty list");
    // }
    // else { 
    //     Node *hold = t;

    //     while (hold->getNext() != nullptr) { 
    //         hold = hold->getNext();
    //     }

    //     Node *m = new Node(n);
    //     hold->setNext(m);
    // }


