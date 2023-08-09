#define BOOST_TEST_MAIN

#ifdef BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#else
#include <boost/test/included/unit_test.hpp>
#endif

#include <algorithm>
#include <iterator>
#include <stdexcept>

#include "stack.h"

struct StackFixture {
  constexpr static int maxSize{100};
  Stack<double, maxSize> stack{};
  double testValues[3]{1., 2., 3.};
};

BOOST_FIXTURE_TEST_CASE(testEmptyStack, StackFixture) {

  BOOST_CHECK(stack.size() == 0);
  BOOST_CHECK_THROW(stack.pop(), std::out_of_range);
}

BOOST_FIXTURE_TEST_CASE(testPushPop, StackFixture) {

  auto stackSize = 0;
  const auto pushFunctor = [&](auto value) {
    stack.push(value);
    BOOST_CHECK(stack.size() == ++stackSize);
  };
  std::for_each(std::cbegin(testValues), std::cend(testValues), pushFunctor);

  const auto popFunctor = [&](auto value) {
    BOOST_CHECK(stack.pop() == value);
    BOOST_CHECK(stack.size() == --stackSize);
  };
  std::for_each(std::crbegin(testValues), std::crend(testValues), popFunctor);
}

BOOST_FIXTURE_TEST_CASE(testOverflow, StackFixture) {

  for (auto i = 0; i < maxSize; ++i) {
    stack.push(0.);
  }
  BOOST_CHECK_THROW(stack.push(0.), std::out_of_range);
}
