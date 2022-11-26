#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

std::pair<int, int> GetClosestNums(const std::vector<int>& a, const std::vector<int>& b) {
  int closest_a = a[0];
  int closest_b = b[0];
  int min_diff = std::abs(closest_a - closest_b);

  size_t last_b_id = 0;
  for (size_t a_id = 0; a_id < a.size(); ++a_id) {
    int prev_diff = std::abs(a[a_id] - b[last_b_id]);
    for (size_t b_id = last_b_id; b_id < b.size() && std::abs(a[a_id] - b[b_id]) <= prev_diff; ++b_id) {
      int diff = std::abs(a[a_id] - b[b_id]);
      if (diff < min_diff) {
        closest_a = a[a_id];
        closest_b = b[b_id];
        min_diff = diff;
      }
      prev_diff = diff;
      last_b_id = b_id;
    }
  }

  return {closest_a, closest_b};
}

void TestGetClosestNums() {
  {
    const std::vector<int> a{3,4};
    const std::vector<int> b{1,2,3};
    const std::pair<int, int> expected = {3,3};
    const auto actual = GetClosestNums(a, b);
    assert(expected == actual);
  }
  {
    const std::vector<int> a{4,5};
    const std::vector<int> b{1,2,3};
    const std::pair<int, int> expected = {4,3};
    const auto actual = GetClosestNums(a, b);
    assert(expected == actual);
  }
  {
    const std::vector<int> a{1,2,3,4,5};
    const std::vector<int> b{1,2,3,4,5};
    const std::pair<int, int> expected = {1,1};
    const auto actual = GetClosestNums(a, b);
    assert(expected == actual);
  }
  {
    const std::vector<int> a{1};
    const std::vector<int> b{1,2,3,4,5};
    const std::pair<int, int> expected = {1,1};
    const auto actual = GetClosestNums(a, b);
    assert(expected == actual);
  }
  {
    const std::vector<int> a{3};
    const std::vector<int> b{1,2,3,4,5};
    const std::pair<int, int> expected = {3,3};
    const auto actual = GetClosestNums(a, b);
    assert(expected == actual);
  }
  {
    const std::vector<int> a{5};
    const std::vector<int> b{1,2,3,4,5};
    const std::pair<int, int> expected = {5,5};
    const auto actual = GetClosestNums(a, b);
    assert(expected == actual);
  }
  {
    const std::vector<int> a{1,2,3,4,5};
    const std::vector<int> b{1};
    const std::pair<int, int> expected = {1,1};
    const auto actual = GetClosestNums(a, b);
    assert(expected == actual);
  }
  {
    const std::vector<int> a{1,2,3,4,5};
    const std::vector<int> b{3};
    const std::pair<int, int> expected = {3,3};
    const auto actual = GetClosestNums(a, b);
    assert(expected == actual);
  }
  {
    const std::vector<int> a{1,2,3,4,5};
    const std::vector<int> b{5};
    const std::pair<int, int> expected = {5,5};
    const auto actual = GetClosestNums(a, b);
    assert(expected == actual);
  }
}

int main() {
  TestGetClosestNums();

  int top_n = 0;
  std::cin >> top_n;
  std::vector<int> top_colors(top_n);
  for (int i = 0; i < top_n; ++i) {
    std::cin >> top_colors[i];
  }

  int bottom_n = 0;
  std::cin >> bottom_n;
  std::vector<int> bottom_colors(bottom_n);
  for (int i = 0; i < bottom_n; ++i) {
    std::cin >> bottom_colors[i];
  }

  const auto [top, bottom] = GetClosestNums(top_colors, bottom_colors);
  std::cout << top << ' ' << bottom << std::endl;

  return 0;
}
