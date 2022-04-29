#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Stack.h"
#include "Queue.h"

#include <iostream>

TEST_CASE("Stack") {

    Stack *s = new Stack();

    CHECK(s->is_empty() == 1);

    s->push(3);
    s->push(-2);
    s->push(4);
    s->push(8);
    
   
    CHECK(s->top() == 8);
    CHECK(s->pop() == 8);
    CHECK(s->top() == 4);
   


    CHECK(s->is_empty() == 0);

}

TEST_CASE("Queue") {

    Queue *q = new Queue();

    CHECK(q->is_empty() == 1);

    q->enqueue(3);
    q->enqueue(6);
    q->enqueue(9);
    q->enqueue(12);
    q->enqueue(3);
    q->enqueue(6);
    q->enqueue(9);
    q->enqueue(12);
    q->enqueue(9);
    q->enqueue(12);

    
    CHECK(q->is_full() == 1);
    CHECK(q->is_empty() == 0);

    int a = q->sequeue(); 
    CHECK(a == 3);
    a = q->sequeue();  
    CHECK(a == 6);
    a = q->front(); 
    CHECK(a == 9);
    a = q->sequeue();  
    a = q->sequeue();  
    a = q->sequeue();  
    a = q->sequeue();  
    a = q->sequeue();  
    a = q->sequeue();  
    a = q->sequeue();  
    a = q->sequeue();  
    CHECK(q->is_full() == 0);
    CHECK(q->is_empty() == 1);


   
}




