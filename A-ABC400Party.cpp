#include <iostream>

int main() {
  int val{};
  std::cin >> val;
  if (400 % val != 0)
    std::cout << -1 << "\n";
  else
    std::cout << (400 / val) << "\n";
  return 0;
}
