#include <iostream>

int main() {
  int val;
  std::cin >> val;
  while (val != 1) {
    if (val % 2 == 0)
      val /= 2;
    else
      val = val * 3 + 1;
    std::cout << val << " ";
  }
  return 0;
}
