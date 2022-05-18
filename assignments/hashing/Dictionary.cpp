  #include "Dictionary.h"
  #include <iostream> 

  

Dictionary::Dictionary() { 
    for (int i = 0; i < 10; i++) { 
        hashTable[i] = new OList(); 
    }
}

Dictionary::~Dictionary(){ 
     for (int i = 0; i < 10; i++) { 
        delete hashTable[i];
    }
}



void Dictionary::insert(Person *p) {  // A method to insert a new Person.
    int index = getHash(p->get_name()); 
    hashTable[index]->insert(p);
}

Person* Dictionary::retrievePerson(std::string name) { 
    int index = getHash(name); 
    // get param??
    int location = 0;
 //   std::cout<<index<<std::endl; 
    OList *list = hashTable[index];
    std::cout<<list->toString()<<std::endl; 
    ONode *n = list->getHead(); 

    while (n != nullptr) { 
        if(n->getPerson()->get_name() == name) { 
            return n->getPerson();
        }
        n = n->getNext();

    }
    return nullptr; 

   // return hashTable[index]->get(0);
} 

int Dictionary::getHash(std::string key) { 
    int sum = 0; 
    int hash = 0; 

    for (int i = 0; i < key.length(); i++) { 
        sum += (int)key[i]; 
    }

    hash = sum % 10;

    return hash; 
}

std::string Dictionary::getAllKeys() { 

    std::string keys = ""; 
    for (int i = 0; i < 10; i++) { 
        if(hashTable[i]->toString() != "nullptr"){
            keys += hashTable[i]->toString(); 
            keys += ", ";  
        }
    }
    return keys;
}
