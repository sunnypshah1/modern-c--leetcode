#include <iostream>
#include <unordered_map>
#include <vector>

std::unordered_map<int, std::vector<int>> possibleVals{
    {0, {0, 8}},    {1, {1, 3, 7, 8, 9}}, {2, {2, 8}},    {3, {3, 8, 9}},
    {4, {4, 8, 9}}, {5, {5, 6, 8, 9}},    {6, {6, 8, 9}}, {7, {7, 3, 0, 8, 9}},
    {8, {8}},       {9, {9, 8}}};

int main() {
  int val{};
  std::cin >> val;
  int zerosDig{val % 10};
  val = val / 10;
  int onesDig{val % 10};

  std::cout << possibleVals[zerosDig].size() * possibleVals[onesDig].size()
            << "\n";

  return 0;
}
