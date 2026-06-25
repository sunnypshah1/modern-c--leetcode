#include <iostream>
#include <utility>
#include <vector>

int main() {
  int height{};
  int width{};
  int str_len{};
  std::cin >> height >> width >> str_len;
  std::string moves{};
  std::cin >> moves;
  std::vector<std::vector<char>> grid(height, std::vector<char>(width));
  int ans{};
  for (int i{}; i < height; ++i) {
    for (int j{}; j < width; ++j) {
      char temp{};
      std::cin >> temp;
      grid[i][j] = temp;
    }
  }

  bool not_prom{};
  for (int i{}; i < height; ++i) {
    for (int j{}; j < width; ++j) {
      if (grid[i][j] == '#')
        continue;
      not_prom = false;
      std::pair<int, int> cur_pos{i, j};
      for (char t : moves) {
        std::pair<int, int> next_pos{cur_pos};
        if (t == 'U')
          next_pos.first--;
        if (t == 'L')
          next_pos.second--;
        if (t == 'R')
          next_pos.second++;
        if (t == 'D')
          next_pos.first++;
        if (grid[next_pos.first][next_pos.second] == '#') {
          not_prom = true;
          break;
        } else {
          cur_pos = next_pos;
        }
      }
      if (not_prom) {
        continue;
      }
      ans++;
    }
  }

  std::cout << ans << "\n";

  return 0;
}
