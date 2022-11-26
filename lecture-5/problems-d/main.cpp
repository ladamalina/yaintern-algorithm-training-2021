#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

int64_t CountStatemetsPairs(const std::vector<int64_t>& statements, const int64_t min_distance) {
  int64_t count = 0;
  size_t right_i = 1;
  for (size_t left_i = 0; left_i < statements.size(); ++left_i) {
    while (right_i < statements.size() && statements[right_i] - statements[left_i] <= min_distance) {
      ++right_i;
    }
    count += static_cast<int64_t>(statements.size()) - static_cast<int64_t>(right_i);
  }

  return count;
}

int main() {
  int64_t statements_n, min_distance;
  std::cin >> statements_n >> min_distance;
  std::vector<int64_t> statements(statements_n);
  for (int i = 0; i < statements_n; ++i) {
    std::cin >> statements[i];
  }

  std::cout << CountStatemetsPairs(statements, min_distance) << std::endl;

  return 0;
}
