#include <iostream>
#include <vector>

int main() {
  int numTestCases{};
  std::cin >> numTestCases;
  for (int i{}; i < numTestCases; ++i) {
    int numRows{};
    int numColumns{};
    std::cin >> numRows >> numColumns;
    std::vector<std::vector<char>> grid{};
    grid.resize(numRows);
    for (int j{}; j < numRows; ++j) {
      grid[j].resize(numColumns);
    }
    for (int j{}; j < numRows; ++j) {
      for (int k{}; k < numColumns; ++k) {
        char temp{};
        std::cin >> temp;
        grid[j][k] = temp;
      }
    }
    for (int j{}; j < numColumns; ++j) {
      int emptyRow{numRows - 1};
      for (int k{numRows - 1}; k >= 0; --k) {
        if (grid[k][j] == 'o') {
          emptyRow = k - 1;
        } else if (grid[k][j] == '*') {
          grid[k][j] = '.';
          grid[emptyRow][j] = '*';
          emptyRow--;
        }
      }
    }
    for (int j{}; j < numRows; ++j) {
      for (int k{}; k < numColumns; ++k) {
        std::cout << grid[j][k];
      }
      std::cout << "\n";
    }
    std::cout << "\n";
  }
  return 0;
}
