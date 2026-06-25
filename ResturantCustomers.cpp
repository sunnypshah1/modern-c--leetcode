#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
  int n{};
  std::cin >> n;
  std::vector<std::pair<int, int>> custs{};
  custs.reserve(n);

  for (int i{}; i < n * 2; ++i) {
    std::pair<int, int> temp{};
    std::cin >> temp.first;
    if (i % 2 == 0) {
      temp.second = 1;
    } else {
      temp.second = -1;
    }
    custs.push_back(temp);
  }

  std::sort(custs.begin(), custs.end(),
            [](const auto &a, const auto &b) { return a.first < b.first; });

  int total{};
  int best{};
  for (int i{}; i < n * 2; i++) {
    total += custs[i].second;
    best = std::max(total, best);
  }

  std::cout << best << "\n";
  return 0;
}
