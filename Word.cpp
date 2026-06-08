#include <cctype>
#include <iostream>
#include <string>

int main() {
  std::string word{};
  std::cin >> word;
  int totalUpper{};
  int totalLower{};
  for (char c : word) {
    if (c >= 97)
      totalLower++;
    else
      totalUpper++;
  }
  if (totalUpper > totalLower) {
    for (char &a : word) {
      a = std::toupper(a);
    }
  } else {
    for (char &a : word) {
      a = std::tolower(a);
    }
  }
  std::cout << word << "\n";
  return 0;
}
