#include <iostream>
#include "Queue.h"

Queue::Queue() {

    head = 0;
    tail = 0;
    size = 0;
    capacity = 10; 
    
    q= new int[10];
}
  
Queue::~Queue() {

    delete[] q;
  

}

void Queue::enqueue(int n) {
 
  if (is_full()) { 

      throw std::out_of_range("Queue is full");
  }
  else { 

    if (tail > 10) { 
        tail %= 10; 
    }

    size++; 
    q[tail] = n;
    tail++;
    
  }

}

int Queue::sequeue() {

    if (is_empty()) { 

        throw std::out_of_range("Queue is empty");

    }
    else { 

        int p = q[head];
        head++;
        size--;

        return p;
    }
}

int Queue::front() {

  if (is_empty()) { 

    throw std::out_of_range("Queue is empty");
  }

  return q[head];
}


bool Queue::is_empty() { 
    if (size == 0) { 
        return true;
    }
    else { 
        return false; 
    }
}

bool Queue::is_full() {
	if (size == capacity) { 
        return true; 
    }
    else { 
        return false; 
    }
}

