#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

template <typename It>
std::unordered_map<int, int> GetColorsCounter(It begin_it, It end_it) {
  std::unordered_map<int, int> counter;
  for (auto it = begin_it; it != end_it; ++it) {
    ++counter[*it];
  }

  return counter;
}

std::pair<int, int> GetShortestRange(const std::vector<int>& trees, const int colors_n) {
  int trees_n = static_cast<int>(trees.size());

  int r_idx = colors_n - 1;
  auto colors_counter = GetColorsCounter(trees.begin(), trees.begin() + r_idx + 1);
  while (r_idx + 1 < trees_n && static_cast<int>(colors_counter.size()) < colors_n) {
    ++r_idx;
    ++colors_counter[trees[r_idx]];
  }
  int best_l = 0;
  int best_r = r_idx;
  int best_len = r_idx + 1;

  if (best_len == colors_n) {
    return {best_l, best_r};
  }

  for (int l_idx = 1; l_idx <= trees_n - colors_n; ++l_idx) {
    --colors_counter[trees[l_idx - 1]];
    if (colors_counter[trees[l_idx - 1]] == 0) {
      colors_counter.erase(trees[l_idx - 1]);
    }
    while (r_idx + 1 < trees_n && static_cast<int>(colors_counter.size()) < colors_n) {
      ++r_idx;
      ++colors_counter[trees[r_idx]];
    }
    while (r_idx > l_idx && static_cast<int>(colors_counter.size()) > colors_n) {
      --colors_counter[trees[r_idx]];
      if (colors_counter[trees[r_idx]] == 0) {
        colors_counter.erase(trees[r_idx]);
      }
      --r_idx;
    }
    if (static_cast<int>(colors_counter.size()) == colors_n) {
      int len = r_idx - l_idx + 1;
      if (len < best_len) {
        best_l = l_idx;
        best_r = r_idx;
        best_len = len;

        if (best_len == colors_n) {
          return {best_l, best_r};
        }
      }
    } else {
      break;
    }
  }

  return {best_l, best_r};
}

void TestGetShortestRange() {
  {
    const std::vector<int> trees{1, 2, 1, 3, 2};
    const int colors_n = 3;
    const auto range = GetShortestRange(trees, colors_n);
    const std::pair<int, int> expected{1, 3};
    assert(range == expected);
  }
  {
    const std::vector<int> trees{1, 3, 1, 3, 2};
    const int colors_n = 3;
    const auto range = GetShortestRange(trees, colors_n);
    const std::pair<int, int> expected{2, 4};
    assert(range == expected);
  }
  {
    const std::vector<int> trees{1, 2, 2, 3, 3, 1, 3, 2};
    const int colors_n = 3;
    const auto range = GetShortestRange(trees, colors_n);
    const std::pair<int, int> expected{5, 7};
    assert(range == expected);
  }
  {
    const std::vector<int> trees{2, 4, 2, 3, 3, 1};
    const int colors_n = 4;
    const auto range = GetShortestRange(trees, colors_n);
    const std::pair<int, int> expected{1, 5};
    assert(range == expected);
  }
  {
    const std::vector<int> trees{1};
    const int colors_n = 1;
    const auto range = GetShortestRange(trees, colors_n);
    const std::pair<int, int> expected{0, 0};
    assert(range == expected);
  }
  {
    const std::vector<int> trees{1, 1};
    const int colors_n = 1;
    const auto range = GetShortestRange(trees, colors_n);
    const std::pair<int, int> expected{0, 0};
    assert(range == expected);
  }
  {
    const std::vector<int> trees{1, 2};
    const int colors_n = 2;
    const auto range = GetShortestRange(trees, colors_n);
    const std::pair<int, int> expected{0, 1};
    assert(range == expected);
  }
}

int main() {
//  TestGetShortestRange();

  int trees_n, colors_n;
  std::cin >> trees_n >> colors_n;

  std::vector<int> trees(trees_n);
  for (int i = 0; i < trees_n; ++i) {
    std::cin >> trees[i];
  }

  const auto [l_idx, r_idx] = GetShortestRange(trees, colors_n);
  std::cout << l_idx + 1 << ' ' << r_idx + 1 << std::endl;

  return 0;
}
