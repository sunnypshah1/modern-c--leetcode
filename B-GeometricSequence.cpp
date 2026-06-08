#include <iostream>

int main() {
  int size{};
  std::cin >> size;
  if (size == 2) {
    std::cout << "Yes";
    return 0;
  }
  std::vector<int> vals(size);
  for (int i{}; i < size; i++) {
    std::cin >> vals[i];
  }
  double div = vals[1] / vals[0];
  for (int i{2}; i < size; i++) {
    double currDiv = vals[i] / vals[i - 1];
    if (currDiv != div) {
      std::cout << "No";
      return 0;
    }
  }
  std::cout << "Yes";
  return 0;
}
