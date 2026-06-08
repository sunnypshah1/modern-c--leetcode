#include <iostream>
#include <vector>

int main() {
  int num_snakes{};
  int up_to_d{};

  std::cin >> num_snakes >> up_to_d;

  std::vector<std::pair<int, int>> snakes;

  for (int i{}; i < num_snakes; i++) {
    std::pair<int, int> temp_snake{};
    std::cin >> temp_snake.first >> temp_snake.second;
    snakes.push_back(temp_snake);
  }

  for (int i{1}; i <= up_to_d; i++) {
    int highest_weight{};
    for (auto &s : snakes) {
      int weight = s.first * (s.second + i);
      if (weight >= highest_weight)
        highest_weight = weight;
    }
    std::cout << highest_weight << "\n";
  }

  return 0;
}
