#pragma once

#include <stdexcept>

template <typename T, int MaxSize = 100>
class Stack {
 public:
  auto size() const { return size_; }

  auto push(double value) {
    if (size_ == MaxSize) throw std::out_of_range("Stack is full");
    values[size_++] = value;
  }

  auto pop() {
    if (!size_) throw std::out_of_range("Cannot pop empty stack");
    return values[--size_];
  }

 private:
  int size_{0};
  T values[MaxSize];
};
