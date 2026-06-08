#include <iostream>

int main() {
  int val{};
  std::cin >> val;
  // 0
  // val * 2 spaces 0 val * 2 spaces\
  // next digit up to val
  // val * 2 - 2 spaces 0 1 0 val * 2 - 2 spaces
  int space_count{val * 2};
  for (int i{}; i <= val; ++i) {
    for (int j{}; j < space_count; j++) {
      std::cout << " ";
    }
    for (int k{}; k <= i; k++) {
      std::cout << k << ' ';
    }
    for (int m{i - 1}; m >= 0; m--) {
      std::cout << m << ' ';
    }
    for (int l{}; l < space_count - 1; l++) {
      std::cout << " ";
    }
    std::cout << "\n";
    space_count -= 2;
  }

  int space_count2{2};
  for (int i{val - 1}; i >= 0; --i) {
    for (int j{}; j < space_count2; j++) {
      std::cout << " ";
    }
    for (int k{}; k <= i; k++) {
      std::cout << k << ' ';
    }
    for (int m{i - 1}; m >= 0; m--) {
      std::cout << m << ' ';
    }
    for (int l{}; l < space_count2 - 1; l++) {
      std::cout << " ";
    }
    std::cout << "\n";
    space_count2 += 2;
  }

  return 0;
}
