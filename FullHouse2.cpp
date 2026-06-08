#include <array>
#include <iostream>

int main() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;

  std::array<int, 13> map{};
  map[a]++;
  map[b]++;
  map[c]++;
  map[d]++;

  bool oneTwo{false};
  bool happened{};
  for (int i : map) {
    if (i == 3) {
      std::cout << "Yes" << "\n";
      happened = true;
    }
    if (i == 2 && oneTwo == true) {
      std::cout << "Yes" << "\n";
      happened = true;
    }
    if (i == 2)
      oneTwo = true;
  }
  if (!happened)
    std::cout << "No" << "\n";
  return 0;
}
