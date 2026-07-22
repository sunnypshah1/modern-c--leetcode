#include <algorithm>
#include <iostream>
#include <numeric>
#include <span>
#include <vector>

bool feasible(std::span<const int> cur_votes, int m, int k, int cur_idx,
              int adt) {
  int sum{cur_votes[cur_idx] + k};

  std::vector<int> needed{};
  for (int i{}; i < cur_votes.size(); ++i) {
    if (i == cur_idx)
      continue;

    needed.push_back(std::max(0, sum + 1 - cur_votes[i]));
  }

  std::sort(needed.begin(), needed.end());

  int tot{};
  for (int i{}; i < m; ++i) {
    tot += needed[i];
  }

  return tot > adt;
}

int main() {
  int n{};
  int m{};
  int k{};
  std::cin >> n >> m >> k;
  std::vector<int> cur_votes(n);
  int total{};
  for (int i{}; i < n; ++i) {
    std::cin >> cur_votes[i];
    total += cur_votes[i];
  }
  // std::cout << total << '\n';
  int remaining{k - total};
  // std::cout << remaining << '\n';
  std::vector<int> result{};
  for (int i{}; i < n; ++i) {
    int left{};
    int right{remaining};
    while (left < right) {
      int mid{std::midpoint(left, right)};
      int adt{remaining - mid};
      // std::cout << mid << "\n";
      if (feasible(cur_votes, m, mid, i, adt)) {
        right = mid;
        // std::cout << "feas" << "\n";
      } else {
        // std::cout << "not feas" << "\n";
        left = mid + 1;
      }
    }

    if (feasible(cur_votes, m, left, i, remaining - left)) {
      result.push_back(left);
    } else {
      result.push_back(-1);
    }
  }
  for (const auto &a : result) {
    std::cout << a << " ";
  }
  return 0;
}
