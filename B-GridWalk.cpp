#include <iostream>
#include <string>
#include <vector>

int main() {
  int height{};
  int width{};
  std::cin >> height >> width;

  int start_row{};
  int start_col{};
  std::cin >> start_row >> start_col;

  std::vector<std::string> grid{};
  for (int i{}; i < height; i++) {
    std::string temp{};
    std::cin >> temp;
    grid.push_back(temp);
  }

  std::string moves{};
  std::cin >> moves;

  start_row--;
  start_col--;

  std::pair<int, int> curr_pos{start_row, start_col};

  for (size_t i{}; i < moves.size(); i++) {
    char curr_move{moves[i]};

    if (curr_move == 'U') {
      if (curr_pos.first - 1 < 0)
        continue;
      if (grid[curr_pos.first - 1][curr_pos.second] == '#')
        continue;
      curr_pos.first--;
    }

    if (curr_move == 'D') {
      if (curr_pos.first + 1 >= height)
        continue;
      if (grid[curr_pos.first + 1][curr_pos.second] == '#')
        continue;
      curr_pos.first++;
    }

    if (curr_move == 'L') {
      if (curr_pos.second - 1 < 0)
        continue;
      if (grid[curr_pos.first][curr_pos.second - 1] == '#')
        continue;
      curr_pos.second--;
    }

    if (curr_move == 'R') {
      if (curr_pos.second + 1 >= width)
        continue;
      if (grid[curr_pos.first][curr_pos.second + 1] == '#')
        continue;
      curr_pos.second++;
    }
  }

  std::cout << curr_pos.first + 1 << ' ' << curr_pos.second + 1 << '\n';
  return 0;
}
