#include <iostream>
#include <vector>

const long long LIMIT = 1'000'000'000'000'000'000;

long long problem(std::vector<long long> values, int size) {
  long long total{values[0]};
  for (size_t i{1}; i < size; i++) {
    if (values[i] == 0) {
      return 0;
    }

    if (total > LIMIT / values[i]) {
      return -1;
    }
    total *= values[i];
  }
  if (total > 1'000'000'000'000'000'000)
    return -1;
  return total;
}

int main() {
  std::vector<long long> vals;
  long long size;
  std::cin >> size;
  for (int i{}; i < size; i++) {
    long long val;
    std::cin >> val;
    vals.push_back(val);
  }
  long long total{static_cast<int>(problem(vals, size))};
  std::cout << total << "\n";
  return 0;
}
