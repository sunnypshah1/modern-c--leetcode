#include <cstddef>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
  int size{};
  int q{};

  std::cin >> size;
  std::cin >> q;

  std::string s{};

  std::cin >> s;

  std::vector<std::pair<int, int>> queries{};

  for (int i{}; i < q; i++) {
    std::pair<int, int> temp{};
    std::cin >> temp.first >> temp.second;
    queries.push_back(temp);
  }

  for (size_t i{}; i < queries.size(); i++) {
    std::string subst{s.substr(queries[i].first - 1,
                               queries[i].second - queries[i].first + 1)};
    int count{};
    for (size_t j{}; j < subst.size(); j++) {
      if (subst[j] == subst[j + 1])
        count++;
    }
    std::cout << count << "\n";
  }

  return 0;
}
