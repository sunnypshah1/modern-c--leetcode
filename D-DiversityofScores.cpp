#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
  int n{};
  int times{};
  std::cin >> n >> times;

  std::vector<long long> players(n, 0);

  // score -> number of players with that score
  std::unordered_map<long long, int> frequency;
  frequency[0] = n;

  for (int i{}; i < times; ++i) {
    int player{};
    long long added_time{};
    std::cin >> player >> added_time;

    --player;

    long long old_score{players[player]};

    // Remove the player from their old score group.
    if (--frequency[old_score] == 0) {
      frequency.erase(old_score);
    }

    // Add the player to their new score group.
    players[player] += added_time;
    frequency[players[player]]++;

    std::cout << frequency.size() << '\n';
  }
}
