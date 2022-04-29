#include <iostream>
#include "Node.h"

Node::Node() {
  data = 0;
  n = nullptr;  

}


Node::Node(int data){
  this->data = data;
 
}


int Node::getData(){
  return data;
}


void Node::setData(int d){
  data = d;
}

Node* Node::getNext(){
  return n;
}

void Node::setNext(Node *l){
  n = l;
}






