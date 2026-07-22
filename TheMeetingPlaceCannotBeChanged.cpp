#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <span>
#include <vector>

double calcTime(std::span<const int> pos, std::span<const int> speed,
                int meetPos) {
  double maxTime{};

  for (std::size_t i{}; i < pos.size(); ++i) {
    const int distance{std::abs(pos[i] - meetPos)};
    const double time{static_cast<double>(distance) / speed[i]};

    maxTime = std::max(maxTime, time);
  }

  return maxTime;
}

int main() {
  int n{};
  std::cin >> n;

  std::vector<int> pos(n);
  std::vector<int> speed(n);

  for (int &x : pos) {
    std::cin >> x;
  }

  for (int &x : speed) {
    std::cin >> x;
  }

  int left{*std::min_element(pos.begin(), pos.end())};
  int right{*std::max_element(pos.begin(), pos.end())};

  while (left < right) {
    const int mid{std::midpoint(left, right)};

    if (calcTime(pos, speed, mid) <= calcTime(pos, speed, mid + 1)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  std::cout << std::fixed << std::setprecision(10) << calcTime(pos, speed, left)
            << '\n';
}
