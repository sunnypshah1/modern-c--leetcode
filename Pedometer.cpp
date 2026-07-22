#include <iostream>
#include <unordered_map>
#include <vector>

/*
 * 9 5
 * 9 9 8 2 4 4 3 5 3 9 9 8 2 4 4 3 5 3
 * */

// map: 0 : 1, 4 : 3, 3 : 2, 1 : 2, 2 : 1
// pfsum: 9, 18, 26, 28, 32, 36, 39, 44, 47, 56
// remainder: 4, 3, 1, 3, 2, 1, 4, 4, 2, 1
// ans: 8

int main() {
  int n{};
  int mod{};
  std::cin >> n >> mod;
  std::vector<int> pit_stops(n);
  for (int &x : pit_stops) {
    std::cin >> x;
  }
  for (int i{}; i < n; ++i) {
    pit_stops.push_back(pit_stops[i]);
  }
  std::unordered_map<int, int> remainders{};
  std::vector<int> remainder_at_idx(n * 2 + 1);
  remainder_at_idx[0] = 0;
  remainders[0] = 1;
  int pfsum{};
  int ans{};

  for (int i{}; i < 2 * n - 1; ++i) {
    if (i >= n) {
      int old_idx{i - n};
      remainders[remainder_at_idx[old_idx]]--;
    }

    pfsum += pit_stops[i];
    int remainder{pfsum % mod};

    int prefix_idx{i + 1};
    remainder_at_idx[prefix_idx] = remainder;

    ans += remainders[remainder];

    if (prefix_idx < n) {
      remainders[remainder]++;
    }
  }
  std::cout << ans << '\n';

  return 0;
}
