#include <algorithm>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

struct Range {
  int start{};
  int end{};
  int orig_index{};
};

int main() {
  int n{};
  std::cin >> n;
  std::vector<Range> ranges;
  ranges.reserve(n);
  std::vector<Range> result{};

  std::vector<bool> contains_other(n);
  std::vector<bool> is_contained(n);

  for (int i{}; i < n; ++i) {
    Range temp{};
    std::cin >> temp.start >> temp.end;
    temp.orig_index = i;
    ranges.push_back(temp);
  }

  std::sort(ranges.begin(), ranges.end(),
            [](const auto &a, const auto &b) { return a.start < b.start; });

  result.push_back(ranges[0]);

  std::sort(ranges.begin(), ranges.end(), [](const Range &a, const Range &b) {
    if (a.start == b.start)
      return a.end > b.end;
    return a.start < b.start;
  });

  int maxEnd = -1;
  for (const auto &r : ranges) {
    if (r.end <= maxEnd) {
      is_contained[r.orig_index] = true;
    }
    maxEnd = std::max(maxEnd, r.end);
  }

  int minEnd = 1e9 + 5;
  for (int i = n - 1; i >= 0; --i) {
    const auto &r = ranges[i];
    if (r.end >= minEnd) {
      contains_other[r.orig_index] = true;
    }
    minEnd = std::min(minEnd, r.end);
  }

  for (const auto &b : contains_other) {
    std::cout << b << ' ';
  }

  std::cout << '\n';

  for (const auto &b : is_contained) {
    std::cout << b << ' ';
  }

  return 0;
}
