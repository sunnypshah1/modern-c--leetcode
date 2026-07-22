#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
  int n{};
  std::cin >> n;
  std::vector<int> pf(n);
  for (int &x : pf) {
    std::cin >> x;
  }
  int ans{};
  int pfsum{};
  std::unordered_map<int, int> mp{};
  mp[0] = 1;
  for (int i{}; i < n; ++i) {
    pfsum += pf[i];
    int remainder{((pfsum % n) + n) % n};
    if (mp.contains(remainder)) {
      ans += mp[remainder];
    }
    mp[remainder]++;
  }
  std::cout << ans << '\n';
  return 0;
}
