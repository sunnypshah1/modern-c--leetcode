#include <iostream>
#include <pair>
#include <priority_queue>
#include <unordered_map>
#include <vector>

struct CustomComparator {
  bool operator()(std::pair<int, int> a, std::pair<int, int> b) {
    return a.second < b.second;
  }
};

[[nodiscard]] std::vector<int> topKFrequent(std::span<const int> nums, int k) {
  std::unordered_map<int, int> freq{};
  for (const auto i : nums) {
    freq[i]++;
  }

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      CustomComparator>
      pq{};

  for (const auto &kv : freq) {
    pq.push({kv.first, kv.second});
  }

  std::vector<int> result;
  for (int i{}; i < k; i++) {
    result.push_back(pq.top().first);
    pq.pop();
  }
  return result;
}

int main() { return 0; }
