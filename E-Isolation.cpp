#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
  int nodes{};
  int queries{};
  std::cin >> nodes >> queries;
  std::vector<std::unordered_set<int>> adj(nodes + 1);
  int isolated{nodes};
  for (int i{}; i < queries; ++i) {
    int type{};
    std::cin >> type;
    if (type == 1) {
      int node1{};
      int node2{};
      std::cin >> node1 >> node2;
      if (adj[node1].empty()) {
        isolated--;
      }
      if (adj[node2].empty()) {
        isolated--;
      }
      adj[node1].insert(node2);
      adj[node2].insert(node1);
    } else { // type == 2
      int node{};
      std::cin >> node;
      if (!adj[node].empty()) {
        // Only examine vertices actually connected to node.
        for (int neighbor : adj[node]) {
          adj[neighbor].erase(node);

          // This neighbor became isolated after losing the edge.
          if (adj[neighbor].empty()) {
            isolated++;
          }
        }

        // The selected node also becomes isolated.
        adj[node].clear();
        isolated++;
      }
    }
    std::cout << isolated << '\n';
  }

  return 0;
}
