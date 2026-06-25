#include <iostream>

int main() {
  int n{};
  std::cin >> n;
  while (n--) {
    int a{};
    int b{};
    std::cin >> a >> b;
    std::cout << b + ((b - 1) / (a - 1)) << "\n";
  }
  return 0;
}
