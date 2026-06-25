#include <iostream>

int main() {
  int bills{};
  int sum{};

  std::cin >> bills >> sum;

  constexpr int Tenk{10'000};
  constexpr int Fivek{5'000};
  constexpr int Onek{1'000};

  for (int i{}; i <= bills; ++i) {
    for (int j{}; j <= bills; ++j) {
      int total{i * Tenk + j * Fivek};
      int remainder{sum - total};

      if (remainder < 0) {
        continue;
      }

      if (remainder % Onek != 0) {
        continue;
      }

      int k{remainder / Onek};

      if (i + j + k == bills) {
        std::cout << i << " " << j << " " << k << "\n";
        return 0;
      }
    }
  }

  std::cout << -1 << " " << -1 << " " << -1 << "\n";
  return 0;
}
