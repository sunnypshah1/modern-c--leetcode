#include <algorithm>
#include <iostream>
#include <numeric>
#include <span>
#include <vector>

bool isFeasible(std::span<const int> nums, int subarrays, int k) {
  int curr{1};
  int sum{};
  for (int n : nums) {
    if (n + sum > k) {
      curr++;
      sum = n;
    } else {
      sum += n;
    }
  }
  return curr <= subarrays;
}

int main() {
  int n{};
  int subarrays{};
  std::cin >> n >> subarrays;
  std::vector<int> nums{};
  for (int i{}; i < n; ++i) {
    int temp{};
    std::cin >> temp;
    nums.push_back(temp);
  }

  int left{*std::max_element(nums.begin(), nums.end())};
  int right{std::accumulate(nums.begin(), nums.end(), 0)};

  while (left < right) {
    int mid{std::midpoint(left, right)};

    if (isFeasible(nums, subarrays, mid)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  std::cout << left << '\n';

  return 0;
}
