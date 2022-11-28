#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>

int GetMinCost(const std::vector<int>& rooms, const std::vector<std::pair<int, int>>& conditioners) {
  std::set<std::pair<int, int>> prices;
  for (const auto& [power, price] : conditioners) {
    prices.insert({price, power});
  }

  int cost = 0;
  int c_id = 0;
  for (const auto room : rooms) {
    while (conditioners[c_id].first < room) {
      prices.erase({conditioners[c_id].second, conditioners[c_id].first});
      ++c_id;
    } // conditioners[c_id].first >= room
    cost += prices.begin()->first;
  }

  return cost;
}

int main() {
  int rooms_n;
  std::cin >> rooms_n;
  std::vector<int> rooms(rooms_n);
  for (int i = 0; i < rooms_n; ++i) {
    std::cin >> rooms[i];
  }
  std::sort(rooms.begin(), rooms.end());

  int conditioners_n;
  std::cin >> conditioners_n;
  std::vector<std::pair<int, int>> conditioners(conditioners_n);
  for (int i = 0; i < conditioners_n; ++i) {
    std::cin >> conditioners[i].first >> conditioners[i].second;
  }
  std::sort(conditioners.begin(), conditioners.end());

  const auto min_cost = GetMinCost(rooms, conditioners);
  std::cout << min_cost << std::endl;

  return 0;
}
