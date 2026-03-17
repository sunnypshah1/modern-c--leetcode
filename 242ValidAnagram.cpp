#include <array>
#include <iostream>
#include <string_view>

[[nodiscard]] bool isAnagram(std::string_view s, std::string_view t) {
  if (s.size() != t.size())
    return false;

  std::array<int, 26> map{};

  for (char c : s)
    map[static_cast<std::size_t>(c - 'a')]++;
  for (char c : t) {
    if (--map[static_cast<std::size_t>(c - 'a')] < 0) {
      return false;
    }
  }

  return true;
}

int main() {
  std::string_view s = "anagram", t = "nagaram";
  std::string_view s1 = "rat", t1 = "car";

  std::cout << "one: " << isAnagram(s, t) << "\n";
  std::cout << "two: " << isAnagram(s1, t1) << "\n";

  return 0;
}
