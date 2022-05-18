#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Dictionary.h"

TEST_CASE("testing insert and getAllKeys") {
  Dictionary *d = new Dictionary();
   
    Person *kir = new Person("Kirsten", "Shyu", 0);
    Person *kass = new Person("Kassidy", "Shyu", 1);
    Person *p3 = new Person("Max", "Shyu", 2); 
    Person *p4 = new Person("Peter", "Shyu", 3); 
    Person *p5 = new Person("Lillian", "Shyu", 4); 
    d->insert(kir);
    d->insert(kass);
   

    CHECK(d->getAllKeys() == "Shyu, Kirsten-->nullptr, Shyu, Kassidy-->nullptr, ");
    d->insert(p3);
    d->insert(p4);
    CHECK(d->getAllKeys() == "Shyu, Peter-->nullptr, Shyu, Max-->nullptr, Shyu, Kirsten-->nullptr, Shyu, Kassidy-->nullptr, "); 
    d->insert(p5);
    CHECK(d->getAllKeys() == "Shyu, Lillian-->nullptr, Shyu, Peter-->nullptr, Shyu, Max-->nullptr, Shyu, Kirsten-->nullptr, Shyu, Kassidy-->nullptr, ");
  
} 

TEST_CASE("testing retrieval") {
    Dictionary *d = new Dictionary();
    Person *kir = new Person("Kirsten", "Shyu", 0);
    Person *kass = new Person("Kassidy", "Shyu", 1);
    Person *p3 = new Person("Max", "Shyu", 2); 
    Person *p4 = new Person("Peter", "Shyu", 3); 
    Person *p5 = new Person("Lillian", "Shyu", 4); 
     d->insert(kir);
    d->insert(kass);
    CHECK(d->retrievePerson(kir->get_name()) == kir);
    CHECK(d->retrievePerson(kass->get_name()) == kass);
    CHECK(d->retrievePerson(p3->get_name()) == nullptr);
    CHECK(d->retrievePerson(p4->get_name()) == nullptr);
    CHECK(d->retrievePerson(p5->get_name()) == nullptr);
       d->insert(p3);
    d->insert(p4);
      CHECK(d->retrievePerson(p3->get_name()) == p3);
    CHECK(d->retrievePerson(p4->get_name()) == p4);

}

TEST_CASE("testing getHash") {
     Dictionary *d = new Dictionary();
    Person *kir = new Person("Kirsten", "Shyu", 0);
    Person *kass = new Person("Kassidy", "Shyu", 1);
    Person *p3 = new Person("Max", "Shyu", 2); 
    Person *p4 = new Person("Peter", "Shyu", 3); 
    Person *p5 = new Person("Lillian", "Shyu", 4); 

    CHECK(d->getHash(kir->get_name()) == 7);
    CHECK(d->getHash(kass->get_name()) == 9);
    CHECK(d->getHash(p3->get_name()) == 5);
    CHECK(d->getHash(p4->get_name()) == 3);
    CHECK(d->getHash(p5->get_name()) == 0);



  }

//   SUBCASE("Hashing"){
//     Person *carl = new Person("Carl", "Jar", 3);
//     Person *jack = new Person("Jack", "Gil", 4);
//     Person *kadin = new Person("Kadin", "Gentry", 5);
//     Person *coco = new Person("Coco", "Bean", 6);
//     Person *tyler = new Person("Tyler", "Wong", 7);
//     CHECK(myDict->hash(carl, 20) == 9);
//     CHECK(myDict->hash(jack, 20) == 9);
//     CHECK(myDict->hash(kadin, 20) == 13);
//     CHECK(myDict->hash(coco, 20) == 10);
//     CHECK(myDict->hash(tyler, 20) == 11);
//   //}//




