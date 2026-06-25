#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

int main() {
  int n1{};
  int n2{};
  std::cin >> n1 >> n2;
  std::vector<int> nums1{};
  std::vector<int> nums2{};

  for (int i{}; i < n1; ++i) {
    int temp{};
    std::cin >> temp;
    nums1.push_back(temp);
  }

  for (int i{}; i < n2; ++i) {
    int temp{};
    std::cin >> temp;
    nums2.push_back(temp);
  }

  std::sort(nums1.begin(), nums1.end());

  for (int i{}; i < nums2.size(); ++i) {
    auto it = std::upper_bound(nums1.begin(), nums1.end(), nums2[i]);
    std::size_t index = std::distance(nums1.begin(), it);

    std::cout << index << ' ';
  }
  return 0;
}
