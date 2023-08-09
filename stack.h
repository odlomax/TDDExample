#pragma once

#include <stdexcept>

template <typename T, int MaxSize = 100>
class Stack{
 public:
  auto size() const {return size_;}

  auto push (double val) {
    values[size_++] = val;
  }

  auto pop() {
    if (!size_) throw std::out_of_range("empty stack");
    return values[--size_];
  }

 private:

  int size_{0};
  T values[MaxSize];

};
