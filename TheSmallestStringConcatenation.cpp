#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int num_strings{};
  std::cin >> num_strings;

  std::vector<std::string> strings(num_strings);

  for (int i{}; i < num_strings; ++i) {
    std::cin >> strings[i];
  }

  std::sort(
      strings.begin(), strings.end(),
      [](const std::string &a, const std::string &b) { return a + b < b + a; });

  std::string res{};
  for (const auto &s : strings) {
    res += s;
  }

  std::cout << res << '\n';
}
