#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>

struct pair_hash {
  inline std::size_t operator()(const std::pair<int,int>& v) const {
    return v.first * 31 + v.second;
  }
};

size_t CountTrue(const int total, const std::vector<std::pair<int, int>>& stats) {
  std::unordered_set<std::pair<int, int>, pair_hash> pairs;

  for (const auto& stat : stats) {
    if (stat.first < 0 || stat.second < 0)
      continue;
    if (stat.first + stat.second + 1 != total)
      continue;
    auto pair_it = pairs.find({stat.first, stat.second});
    if (pair_it == pairs.end())
      pairs.insert({stat.first, stat.second});
  }

  return pairs.size();
}

void TestCountTrue() {
  {
    const int total_n = 3;
    const std::vector<std::pair<int, int>> stats{{2,0},{0,2},{2,2}};
    const auto actual = CountTrue(total_n, stats);
    assert(actual == 2);
  }
  {
    const int total_n = 3;
    const std::vector<std::pair<int, int>> stats{{2,0},{-2,2},{2,2}};
    const auto actual = CountTrue(total_n, stats);
    assert(actual == 1);
  }
  {
    const int total_n = 5;
    const std::vector<std::pair<int, int>> stats{{0,4},{1,3},{2,2},{3,1},{4,0}};
    const auto actual = CountTrue(total_n, stats);
    assert(actual == 5);
  }
  {
    const int total_n = 10;
    const std::vector<std::pair<int, int>> stats{{9,1},{8,1},{7,2},{6,2},{5,3},{4,4},{3,6},{2,7},{1,9},{0,8}};
    const auto actual = CountTrue(total_n, stats);
    assert(actual == 4);
  }
  {
    const int total_n = 1;
    const std::vector<std::pair<int, int>> stats{{0,0}};
    const auto actual = CountTrue(total_n, stats);
    assert(actual == 1);
  }
  {
    const int total_n = 1;
    const std::vector<std::pair<int, int>> stats{{2,2}};
    const auto actual = CountTrue(total_n, stats);
    assert(actual == 0);
  }
}

int main() {
  TestCountTrue();

  int total_n = 0;
  std::cin >> total_n;

  std::vector<std::pair<int, int>> stats(total_n);
  for (int i = 0; i < total_n; ++i)
    std::cin >> stats[i].first >> stats[i].second;

  auto count = CountTrue(total_n, stats);
  std::cout << count << std::endl;

  return 0;
}
