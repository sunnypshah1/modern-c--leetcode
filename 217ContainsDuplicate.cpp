#include <iostream>
#include <span>
#include <unordered_set>
#include <vector>

[[nodiscard]] bool containsDuplicate(std::span<const int> values) {
  std::unordered_set<int> seen;
  seen.reserve(values.size());
  for (int v : values) {
    if (!seen.insert(v).second) {
      return true;
    }
  }
  return false;
}

int main() {
  std::vector<int> nums1{1, 2, 3, 1};
  std::vector<int> nums2{1, 2, 3, 4};
  std::vector<int> nums3{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

  std::cout << "nums1: " << containsDuplicate(nums1) << "\n";
  std::cout << "nums2: " << containsDuplicate(nums2) << "\n";
  std::cout << "nums3: " << containsDuplicate(nums3) << "\n";

  return 0;
}
