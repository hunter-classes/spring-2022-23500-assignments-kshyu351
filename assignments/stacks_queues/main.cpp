#include <iostream> 
#include "Node.h"
#include "Stack.h"
#include "List.h"
#include "Queue.h"

int main() { 

    

    Stack *s = new Stack(); 
     std::cout << s->is_empty() << std::endl; 

    s->push(5); 
    s->push(4); 
    s->push(2); 
    s->push(9); 

    std::cout << s->is_empty() << std::endl; 

    int t = s->top(); 
    std::cout << t << std::endl; 
    int j = s->pop(); 
    int z = s->top(); 
    std::cout << z << std::endl; 

    Queue *q = new Queue();
    std::cout << q->is_empty() << std::endl;

    std::cout << q->is_full() << std::endl;
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);

    std::cout << q->is_empty() << std::endl;
    int n = q->sequeue();
    std::cout << n << std::endl; 
    int m = q->front(); 
    std::cout << m << std::endl; 
    int a = q->sequeue();
    int b = q->sequeue();
    int c = q->sequeue();
    std::cout << q->is_empty() << std::endl;
    std::cout << q->is_full() << std::endl;








   
  
    





    // Node *walker = n1; 
    // while (walker != nullptr) { 
    //     std::cout << walker->getData() << std::endl; 
    //     walker = walker->getNext(); 
    // }


}

