#include <iostream>
#include <unordered_map>
#include <vector>

size_t CountShots(const std::vector<std::pair<int, int>>& birds) {
  std::unordered_map<int, int> x_to_max_y;
  for (const auto& bird : birds) {
    auto x_it = x_to_max_y.find(bird.first);
    if (x_it == x_to_max_y.end())
      x_to_max_y[bird.first] = bird.second;
    else
      x_it->second = std::max(x_it->second, bird.second);
  }
  return x_to_max_y.size();
}

int main() {
  int total_n = 0;
  std::cin >> total_n;

  std::vector<std::pair<int, int>> birds(total_n);
  for (int i = 0; i < total_n; ++i)
    std::cin >> birds[i].first >> birds[i].second;

  auto count = CountShots(birds);
  std::cout << count << std::endl;

  return 0;
}
