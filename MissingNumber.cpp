#include <iostream>
#include <unordered_set>

int main() {
  int size{};
  std::cin >> size;
  std::unordered_set<int> st{};
  st.reserve(size - 1);
  for (int i{size - 1}; i-- > 0;) {
    int temp{};
    std::cin >> temp;
    st.insert(temp);
  }

  for (int i{1}; i <= size; i++) {
    if (st.find(i) == st.end()) {
      std::cout << i;
      break;
    } else {
      continue;
    }
  }
  return 0;
}
