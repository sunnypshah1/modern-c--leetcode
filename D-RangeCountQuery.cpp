#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n{};
  std::cin >> n;
  std::vector<std::vector<int>> nums(n + 1);

  for (int i{}; i < n; ++i) {
    int temp{};
    std::cin >> temp;
    nums[temp].push_back(i);
  }

  int q{};
  std::cin >> q;
  while (q--) {
    int l{};
    int r{};
    int x{};

    std::cin >> l >> r >> x;

    std::cout << std::lower_bound(nums[x].begin(), nums[x].end(), r) -
                     std::lower_bound(nums[x].begin(), nums[x].end(), l - 1)
              << "\n";
  }

  return 0;
}
