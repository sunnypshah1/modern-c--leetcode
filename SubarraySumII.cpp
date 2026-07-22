#include <iostream>
#include <unordered_map>
#include <vector>

// 2, -1, 3, 5, -2
int main() {
  int n{};
  int target{};
  std::cin >> n >> target;
  std::vector<int> nums(n);
  for (int &x : nums) {
    std::cin >> x;
  }
  std::unordered_map<int, int> mp{}; // 0 : 1, 2 : 1, 1 : 1, 4 : 1
  mp[0] = 1;
  int sum{};
  int ans{}; // 1, 2
  for (int i{}; i < n; ++i) {
    sum += nums[i];          // 2, 1, 4, 9, 7
    int comp{sum - target};  // -5, -6, -3, 2, 0
    if (mp.contains(comp)) { // false, false, false, true, true
      ans += mp[comp];
    }
    mp[sum]++;
  }
  std::cout << ans << '\n';
  return 0;
}
