#pragma once
#include <vector>

#define QUEUE_FULL 1
#define QUEUE_EMPTY 2

class Queue {

  private:

    int* q;
    int head;
    int tail;
    int size;
    int capacity; 

  public:
    Queue();
    ~Queue();
    void enqueue(int x); // remove and return the item from the front of the queue
    int sequeue(); // return but do not remove the item from the front of the queue
    int front(); //return true if empty, false otherwise
    bool is_empty();   // return true if queue is full (head == tail)
    bool is_full();
};