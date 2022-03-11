#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include "OList.h"
#include "ONode.h"

OList *l = new OList();

TEST_CASE("testing insert & toString") { 
  l->insert(1);
  l->insert(3);
  l->insert(5);
  l->insert(4);
  l->insert(0);
  l->insert(10);

  CHECK(l->toString() == "head-->0-->1-->3-->4-->5-->10-->nullptr");   
} 

TEST_CASE("testing contains"){
  CHECK(l->contains(4));
  CHECK(!l->contains(2));
}

TEST_CASE("testing get"){
  CHECK(l->get(0) == 0);
  CHECK(l->get(1) == 1);
  CHECK(l->get(2) == 3);
  CHECK(l->get(5) == 10);
}

TEST_CASE("testing remove"){
  l->remove(0);
  l->remove(3);
  l->remove(1);
  CHECK(l->toString() == "head-->1-->3-->5-->nullptr");   
}

TEST_CASE("testing reverse"){
  l->reverse();
  CHECK(l->toString() == "head-->5-->3-->1-->nullptr"); 
  l->reverse();
  CHECK(l->toString() == "head-->1-->3-->5-->nullptr"); 
}