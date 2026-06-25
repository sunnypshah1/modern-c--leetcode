#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

int main() {
  long long n{};
  std::cin >> n;

  std::vector<std::pair<long long, long long>> custs{};
  custs.reserve(n);

  for (long long i{}; i < n; ++i) {
    std::pair<long long, long long> temp{};
    std::cin >> temp.first >> temp.second;
    custs.push_back(temp);
  }

  std::sort(custs.begin(), custs.end(),
            [](const auto &a, const auto &b) { return a.first < b.first; });

  long long opt_enter{custs[n / 2].first};

  std::sort(custs.begin(), custs.end(),
            [](const auto &a, const auto &b) { return a.second < b.second; });

  long long opt_exit{custs[n / 2].second};

  long long total_time{};
  for (long long i{}; i < n; ++i) {
    total_time += (std::abs(opt_enter - custs[i].first));
    total_time += (std::abs(custs[i].first - custs[i].second));
    total_time += (std::abs(opt_exit - custs[i].second));
  }

  std::cout << total_time << "\n";

  return 0;
}
