#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

bool Solution(int brick_w, int brick_h, int brick_l, int hole_w, int hole_h) {
  int hole_min = std::min(hole_w, hole_h);
  int hole_max = std::max(hole_w, hole_h);

  std::vector<int> brick_sizes{brick_w, brick_h, brick_l};
  std::sort(brick_sizes.begin(), brick_sizes.end());

  return brick_sizes[0] <= hole_min && brick_sizes[1] <= hole_max;
}

void TestSolution() {
  assert(Solution(1,1,1,1,1));
  assert(!Solution(2,2,2,1,1));

  std::cerr << "TestSolution OK" << std::endl;
}

int main() {
//  TestSolution();

  int brick_w, brick_h, brick_l, hole_w, hole_h;
  std::cin >> brick_w >> brick_h >> brick_l >> hole_w >> hole_h;
  const auto result = Solution(brick_w, brick_h, brick_l, hole_w, hole_h);
  std::cout << (result ? "YES" : "NO") << std::endl;

  return 0;
}
