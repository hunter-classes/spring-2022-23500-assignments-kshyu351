#include <iostream> 
#include "Dictionary.h"


int main() { 

    Dictionary *d = new Dictionary(); 
    Person *p = new Person("Kirsten", "Shyu", 0); 
    Person *p2 = new Person("Kassidy", "Shyu", 1); 
    Person *p3 = new Person("Max", "Shyu", 2); 
    Person *p4 = new Person("Peter", "Shyu", 3); 
    Person *p5 = new Person("Lillian", "Shyu", 4); 

    d->insert(p); 
    d->insert(p2); 
    d->insert(p3); 
    d->insert(p4); 
    d->insert(p5);

    //testing retrieve and insert 

    Person *kirsten = d->retrievePerson("Shyu, Kirsten");
    std::cout << "Name: " << kirsten->get_name() << std::endl; 
    std::cout << "ID: " << kirsten->get_id() << std::endl; 

    Person *kass = d->retrievePerson("Shyu, Kassidy");
    std::cout << "Name: " << kass->get_name() << std::endl; 
    std::cout << "ID: " << kass->get_id() << std::endl; 

    //testing getAllKeys 

    std::cout << d->getAllKeys() << std::endl; 

}