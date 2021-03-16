#include "Unity/src/unity.h"
#include "list.h"

void testf(){
  node test = createNode();
  TEST_ASSERT_EQUAL_INT(0, HowMuchNode(test));
  addNode(test, "hello world");
  addNode(test, "hello world");
  TEST_ASSERT_EQUAL_INT(2, HowMuchNode(test));
}

void setUp(/* arguments */) {
  /* code */
}

void tearDown(/* arguments */) {
  /* code */
}

void main() {
  UNITY_BEGIN();
  RUN_TEST(testf);
  return UNITY_END();
}
