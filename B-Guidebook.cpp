#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Resturant {
  std::string city{};
  int score{};
  int idx{};
};

int main() {
  int n{};
  std::vector<Resturant> resturants{};
  std::cin >> n;
  for (int i{}; i < n; ++i) {
    Resturant temp{};
    std::cin >> temp.city >> temp.score;
    temp.idx = i + 1;
    resturants.push_back(temp);
  }
  std::sort(resturants.begin(), resturants.end(),
            [](const Resturant &a, const Resturant &b) {
              if (a.city == b.city) {
                return a.score > b.score;
              } else {
                return a.city < b.city;
              }
            });

  for (const auto &r : resturants) {
    std::cout << r.idx << "\n";
  }

  return 0;
}
