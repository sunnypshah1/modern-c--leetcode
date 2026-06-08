#include <array>
#include <iostream>
#include <string>

int main() {
  std::string val{};
  std::cin >> val;
  if (val.size() % 2 != 0) {
    std::cout << "No";
    return 0;
  }

  std::array<int, 26> map{};

  for (char c : val) {
    map[c - 'a']++;
  }

  for (int a : map) {
    if (a != 0 && a != 2) {
      std::cout << "No";
      return 0;
    }
  }

  for (size_t i{}; i < val.size(); i += 2) {
    if (val[i] != val[i + 1]) {
      std::cout << "No";
      return 0;
    }
  }

  std::cout << "Yes";
  return 0;
}
