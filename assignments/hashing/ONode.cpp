#include <iostream>
#include "ONode.h"
#include "Person.h"

ONode::ONode() : next(nullptr){
}

ONode::ONode(Person *p){
    this->p = p;
    this->next = nullptr;
}

ONode::ONode(Person *p, ONode *next){
    this->p = p;
    this->next = next;
}

void ONode::setPerson(Person *p){
    this->p = p;
}

void ONode::setNext (ONode *next){
    this->next = next;
}

Person* ONode::getPerson(){
    return this->p;
}

ONode *ONode::getNext()
{
    return this->next;
}
