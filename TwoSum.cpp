#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
  int n{};
  int target{};
  std::cin >> n >> target;
  std::vector<int> nums(n);
  for (int &x : nums) {
    std::cin >> x;
  }
  std::unordered_map<int, int> mp{};
  for (int i{}; i < n; ++i) {
    int complement{target - nums[i]};
    auto it{mp.find(complement)};
    if (it != mp.end()) {
      std::cout << i + 1 << " " << mp[complement] + 1 << '\n';
      return 0;
    } else {
      mp[nums[i]] = i;
    }
  }

  std::cout << "IMPOSSIBLE" << '\n';
  return 0;
}
