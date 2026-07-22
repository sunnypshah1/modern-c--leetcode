#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
  int n{};
  std::cin >> n;

  std::vector<int> playlist(n);
  for (int &song : playlist) {
    std::cin >> song;
  }

  std::unordered_set<int> songs;
  int left{};
  int answer{};

  for (int right{}; right < n; ++right) {
    while (songs.contains(playlist[right])) {
      songs.erase(playlist[left]);
      ++left;
    }

    songs.insert(playlist[right]);
    answer = std::max(answer, right - left + 1);
  }

  std::cout << answer << '\n';
}
