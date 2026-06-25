#include <iostream>
#include <queue>
int main() {
  int n{};
  std::cin >> n;
  std::queue<int> q;
  for (int i{1}; i <= n; ++i) {
    q.push(i);
  }
  while (!q.empty()) {
    q.push(q.front());
    q.pop();

    std::cout << q.front() << " ";
    q.pop();
  }
  return 0;
}
