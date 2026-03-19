#include <array>
#include <iostream>
#include <span>
#include <string>
#include <unordered_map>
#include <vector>

[[nodiscard]] std::vector<std::vector<std::string>>
groupAnagrams(std::span<const std::string> strs) {
  std::unordered_map<std::string, std::vector<std::string>> groups;

  for (const std::string &str : strs) {
    std::array<int, 26> freq{};
    for (char c : str) {
      freq[c - 'a']++;
    }

    std::string key;
    for (int count : freq) {
      key += std::to_string(count);
      key += '#';
    }

    groups[key].push_back(str);
  }

  std::vector<std::vector<std::string>> result;
  for (const auto &kv : groups) {
    result.push_back(kv.second);
  }
  return result;
}

int main() {
  std::vector<std::string> v1{"eat", "tea", "tan", "ate", "nat", "bat"};
  std::vector<std::string> v2{""};
  std::vector<std::string> v3{"a"};

  auto a1 = groupAnagrams(v1);
  auto a2 = groupAnagrams(v2);
  auto a3 = groupAnagrams(v3);

  for (const auto &group : a1) {
    std::cout << "[ ";
    for (const auto &s : group) {
      std::cout << s << " ";
    }
    std::cout << "] ";
  }

  std::cout << "\n";

  for (const auto &group : a2) {
    std::cout << "[ ";
    for (const auto &s : group) {
      std::cout << s << " ";
    }
    std::cout << "] ";
  }

  std::cout << "\n";

  for (const auto &group : a3) {
    std::cout << "[ ";
    for (const auto &s : group) {
      std::cout << s << " ";
    }
    std::cout << "] ";
  }

  std::cout << "\n";
}
