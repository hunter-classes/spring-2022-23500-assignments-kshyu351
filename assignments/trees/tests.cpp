
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.h"
#include "BSTree.h"
#include <iostream>

TEST_CASE("testing rsearch") {

  BSTree *t = new BSTree();
  t->setup();

   CHECK(t->rsearch(7) == t->search(7)->getData());
    CHECK(t->rsearch(10) == t->search(10)->getData());
    CHECK(t->rsearch(8) == t->search(8)->getData());
    CHECK(t->rsearch(3) == t->search(3)->getData());
    CHECK_THROWS(t->rsearch(0)); 
    CHECK_THROWS(t->rsearch(-10)); 
    CHECK_THROWS(t->rsearch(99)); 
}

TEST_CASE("testing delete") {

  BSTree *t = new BSTree();
  t->setup();
    t->deleteNode(6);
    CHECK(t->get_debug_string() == "7\n5\n3\n9\n8\n10\n15\n16\n");
    t->deleteNode(10);
    CHECK(t->get_debug_string() == "7\n5\n3\n9\n8\n15\n16\n");
    t->deleteNode(5);
    CHECK(t->get_debug_string() == "7\n3\n9\n8\n15\n16\n");
    t->deleteNode(9);
    CHECK(t->get_debug_string() == "7\n3\n8\n15\n16\n");
}

TEST_CASE("testing getLevel") {
  BSTree *t = new BSTree();
  t->setup();
  CHECK(t->getLevel(7) == 0); 
  CHECK(t->getLevel(5) == 1); 
  CHECK(t->getLevel(9) == 1); 
  CHECK(t->getLevel(8) == 2); 
  CHECK_THROWS(t->getLevel(11));

}

TEST_CASE("testing isCousins") {
  BSTree *t = new BSTree();
  t->setup();
  CHECK(t->isCousins(7,8) == 0); 
  CHECK(t->isCousins(10,8) == 1); 
  CHECK(t->isCousins(5,9) == 1); 
  CHECK(t->isCousins(16,9) == 0); 
  

}

TEST_CASE("testing countSum") {
  BSTree *t = new BSTree();
  t->setup();
  CHECK(t->countSum(2) == 27);
  CHECK(t->countSum(1) == 14);
  CHECK(t->countSum(0) == 7);
  CHECK(t->countSum(3) == 15);
  CHECK(t->countSum(-1) == -1);
}

TEST_CASE("testing countLeaves") {
  BSTree *t = new BSTree();
  t->setup();
  CHECK(t->countLeaves() == 4);
}




