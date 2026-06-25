#include <iostream>

int main() {
  int n{};
  std::cin >> n;
  std::vector<int> parents(n + 1);

  for (int i{2}; i <= n; i++) {
    std::cin >> parents[i];
  }

  int curr{n};
  int ans{};

  while (curr != 1) {
    curr = parents[curr];
    ans++;
  }

  std::cout << ans << "\n";
  return 0;
}
