#include <iostream>
#include <set>

int main() {
  int dist{};
  int lights{};
  std::cin >> dist >> lights;
  std::set<int> light_pos{};
  light_pos.insert(0);
  light_pos.insert(dist);
  std::multiset<int> distances{};
  distances.insert(dist);
  for (int i{}; i < lights; ++i) {
    int new_light{};
    std::cin >> new_light;
    // First existing light to the right of new_light
    auto it = light_pos.lower_bound(new_light);

    // Existing light immediately to the left
    auto it2 = std::prev(it);
    light_pos.insert(new_light);
    int distance{*it - *it2};
    auto it3{std::lower_bound(distances.begin(), distances.end(), distance)};
    int curr{*it3};
    distances.erase(it3);
    distances.insert(*it - new_light);
    distances.insert(new_light - *it2);
    std::cout << *distances.rbegin() << '\n';
  }
  return 0;
}
