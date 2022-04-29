#pragma once

class Node {
 private:
  int data;
  Node *n;
 
 public:
  Node();
  Node(int data);
  Node(int d, Node *n);
  int getData();
  Node *getNext();
 

  void setData(int d);
  void setNext(Node *n);


};