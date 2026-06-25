#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n{};
  std::cin >> n;
  while (n--) {
    int len{};
    int k{};
    std::cin >> len >> k;
    std::string str{};
    std::cin >> str;
    std::sort(str.begin(), str.end());
    if (str[0] != str[k - 1]) {
      std::cout << str[k - 1] << '\n';
      continue;
    }

    std::cout << str[0];

    if (str[k] != str[len - 1]) {
      for (int i{k}; i < len; i++)
        std::cout << str[i];
    } else {
      for (int i{k}; i < ((len + 1 - k) / k); ++i)
        std::cout << str[i];
    }

    std::cout << '\n';
  }
  return 0;
}
