#pragma once

class ONode{
    private:
    //This could be any data type
    int data;
    //This will be a pointer for the next Node
    ONode *next;
    public:
    //Basic constructors
    ONode();
    ONode(int data);
    ONode(int data, ONode* next);

    //Basic accessor method
    int getData();
    ONode *getNext();
    
    //Basic setter method
    void setData(int data);
    void setNext(ONode *next);
};