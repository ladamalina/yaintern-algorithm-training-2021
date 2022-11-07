#include <cassert>
#include <iostream>
#include <limits>

int main() {
  bool is_asc = true;
  int prev_num = std::numeric_limits<int>::min();
  int num = 0;
  while (std::cin >> num) {
    if (num <= prev_num)
      is_asc = false;
    prev_num = num;
  }
  std::cout << (is_asc ? "YES" : "NO") << std::endl;

  return 0;
}
