#define BOOST_TEST_MAIN

#ifdef BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#else
#include <boost/test/included/unit_test.hpp>
#endif

#include "stack.h"

BOOST_AUTO_TEST_CASE(emptyStack) {

  auto stack = Stack<double>{};
  BOOST_CHECK(stack.size() == 0);
  BOOST_CHECK_THROW(stack.pop(), std::out_of_range);

}

BOOST_AUTO_TEST_CASE(testPushPop) {

  auto stack = Stack<double>{};
  stack.push(2.);
  stack.push(3.);

  BOOST_CHECK(stack.size() == 2);


  BOOST_CHECK(stack.pop() == 3.);
  BOOST_CHECK(stack.size() == 1);

}
