
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.h"
#include "BSTree.h"
#include <iostream>

TEST_CASE("testing rsearch") {

  BSTree *t = new BSTree();
  t->setup();

   CHECK(t->rsearch(7) == t->search(7));
    CHECK(t->rsearch(10) == t->search(10));
    CHECK(t->rsearch(8) == t->search(8));
    CHECK(t->rsearch(3) == t->search(3));
    CHECK_THROWS(t->rsearch(0)); 
    CHECK_THROWS(t->rsearch(-10)); 
    CHECK_THROWS(t->rsearch(99)); 
}
