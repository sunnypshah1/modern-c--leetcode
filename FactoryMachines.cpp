#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

bool isFeasible(const std::vector<long long> &machines, long long products,
                long long time) {
  long long total = 0;

  for (long long machineTime : machines) {
    total += time / machineTime;

    // Avoid unnecessary work and possible overflow.
    if (total >= products) {
      return true;
    }
  }

  return false;
}

int main() {
  int machinesCount;
  long long products;
  std::cin >> machinesCount >> products;

  std::vector<long long> machines(machinesCount);
  for (long long &machine : machines) {
    std::cin >> machine;
  }

  long long left = 0;
  long long right =
      *std::min_element(machines.begin(), machines.end()) * products;

  while (left < right) {
    long long mid = std::midpoint(left, right);

    if (isFeasible(machines, products, mid)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  std::cout << left << '\n';
}
