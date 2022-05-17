  #include "Dictionary.h"
  #include <iostream> 

  

Dictionary::Dictionary() { 
    for (int i = 0; i < 100; i++) { 
        hashTable[i] = new List(); 
    }
}

Dictionary::~Dictionary(){ 
    delete[] hashTable; 
}



void Dictionary::insert(Person *p) {  // A method to insert a new Person.
    int index = getHash(p->get_name()); 
    if (hashTable[index] == nullptr) { 
        hashTable[index]->insert(p);
    }
    //linear probing???
    else { 
      
        while(index != 100) { 
            if (hashTable[index] == nullptr) { 
                hashTable[index]->insert(p);
            }
            if (index == 99) { 
                index = 0; 
            }
            index++;
        }
    }
}

Person Dictionary::getPerson(std::string name) { 
    int index = getHash(name); 
    // get param??

    return hashTable[index]->get(0);
} 

int Dictionary::getHash(std::string key) { 
    int sum = 0; 
    int hash = 0; 

    for (int i = 0; i < key.length(); i++) { 
        sum += (int)key[i]; 
    }

    hash = sum % 100;

    return hash; 
}

std::string Dictionary::getAllKeys() { 

    std::string keys = ""; 
    for (int i = 0; i < 100; i++) { 
        keys = keys + std::to_string(hashTable[i]) + "\n";  
    }
    return keys;
}
