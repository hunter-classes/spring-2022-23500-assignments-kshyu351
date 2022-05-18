#pragma once 
#include "Person.h"
#include "OList.h"

#include <iostream>

class Dictionary {
 private:
    
    OList* hashTable[10];

 public:
    Dictionary(); 
    ~Dictionary(); 
    void insert(Person *p);  // A method to insert a new Person.
    Person* retrievePerson(std::string name); 
    std::string getAllKeys(); 
    int getHash(std::string key); 


  
 
  

//   One or more constructors
// A destructor that frees all the linked lists

// A method to retrieve a Person (return nullptr if they’re not in the Dictionary).
// A Method to get all the keys - that is, all the first+last names.
  
};


