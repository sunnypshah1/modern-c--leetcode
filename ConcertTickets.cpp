#include <algorithm>
#include <iostream>
#include <set>

int main() {
  int n{};
  int m{};
  std::cin >> n >> m;
  std::multiset<int> bag{};
  for (int i{}; i < n; ++i) {
    int temp{};
    std::cin >> temp;
    bag.insert(temp);
  }
  for (int i{}; i < m; ++i) {
    int temp{};
    std::cin >> temp;
    auto it{std::upper_bound(bag.begin(), bag.end(), temp)};
    if (it != bag.begin()) {
      --it;
      std::cout << *it << '\n';
      bag.erase(it);
    } else {
      std::cout << -1 << '\n';
    }
  }
  return 0;
}
