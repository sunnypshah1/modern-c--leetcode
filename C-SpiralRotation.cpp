#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n{};
  std::cin >> n;

  std::vector<std::vector<char>> grid(n, std::vector<char>(n));
  std::vector<std::vector<char>> ans(n, std::vector<char>(n));

  for (int i{}; i < n; ++i) {
    for (int j{}; j < n; ++j) {
      std::cin >> grid[i][j];
    }
  }

  for (int i{}; i < n; ++i) {
    for (int j{}; j < n; ++j) {
      int layer = std::min({i, j, n - 1 - i, n - 1 - j});
      int times = (layer + 1) % 4;

      int r = i;
      int c = j;

      for (int t{}; t < times; ++t) {
        int nr = c;
        int nc = n - 1 - r;
        r = nr;
        c = nc;
      }

      ans[r][c] = grid[i][j];
    }
  }

  for (int i{}; i < n; ++i) {
    for (int j{}; j < n; ++j) {
      std::cout << ans[i][j];
    }
    std::cout << '\n';
  }
}
