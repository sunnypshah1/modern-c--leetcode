#include <algorithm>
#include <iostream>
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
  int tot{};
  std::vector<int> res{};
  for (int i : nums) {
    auto it = std::upper_bound(res.begin(), res.end(), i);
    if (it == res.end()) {
      tot++;
      res.push_back(i);
    } else {
      *it = i;
    }
  }
  std::cout << tot << '\n';
  return 0;
}
