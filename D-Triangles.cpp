#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  int n{};
  std::cin >> n;
  std::vector<int> nums{};
  for (int i{}; i < n; ++i) {
    int temp{};
    std::cin >> temp;
    nums.push_back(temp);
  }

  std::sort(nums.begin(), nums.end());

  long long total{};
  for (int i{}; i < n; ++i) {
    for (int j{i + 1}; j < n; ++j) {
      int sum{nums[i] + nums[j]};
      // need vals that are less than this
      auto it{std::lower_bound(nums.begin() + j + 1, nums.end(), sum)};
      total += std::distance(nums.begin() + j + 1, it);
    }
  }

  std::cout << total << "\n";

  return 0;
}
