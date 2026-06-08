#include <iostream>
#include <unordered_set>

int main() {
  int val{};
  std::cin >> val;
  std::unordered_set<int> st{};
  for (int i{val}; i-- > 0;) {
    int temp{};
    std::cin >> temp;
    st.insert(temp);
  }
  std::cout << st.size();
  return 0;
}
