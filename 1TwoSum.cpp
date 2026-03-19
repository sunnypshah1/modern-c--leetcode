#include <array>
#include <cstddef>
#include <iostream>
#include <span>
#include <unordered_map>
#include <vector>

[[nodiscard]] std::vector<int> twoSum(std::span<const int> nums, int target) {
  std::unordered_map<int, int> index_by_value;
  index_by_value.reserve(nums.size());

  for (std::size_t i = 0; i < nums.size(); ++i) {
    const int complement = target - nums[i];

    if (auto it = index_by_value.find(complement); it != index_by_value.end()) {
      return {it->second, static_cast<int>(i)};
    }

    index_by_value.emplace(nums[i], static_cast<int>(i));
  }

  return {};
}

int main() {
  constexpr std::array v1{2, 7, 11, 15};
  constexpr std::array v2{3, 2, 4};
  constexpr std::array v3{3, 3};

  const auto r1 = twoSum(v1, 9);
  const auto r2 = twoSum(v2, 6);
  const auto r3 = twoSum(v3, 6);

  for (const auto &r : {r1, r2, r3}) {
    if (r.empty()) {
      std::cout << "no solution\n";
    } else {
      std::cout << '[' << r[0] << ", " << r[1] << "]\n";
    }
  }
}
