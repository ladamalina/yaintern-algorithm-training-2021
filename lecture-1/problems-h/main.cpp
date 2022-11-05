#include <cassert>
#include <iostream>

std::pair<int, int> Solution(int interval_a, int interval_b, int num_a, int num_b) {
  int min_a = num_a + interval_a * (num_a - 1);
  int max_a = num_a + interval_a * (num_a + 1);

  int min_b = num_b + interval_b * (num_b - 1);
  int max_b = num_b + interval_b * (num_b + 1);

  int intersection_begin = std::max(min_a, min_b);
  int intersection_end = std::min(max_a, max_b);

  if (intersection_begin <= intersection_end)
    return {intersection_begin, intersection_end};

  return {-1, -1};
}

void TestSolution() {
  {
    const std::pair<int, int> expected{5,7};
    assert(Solution(1,3,3,2) == expected);
  }
  {
    const std::pair<int, int> expected{-1,-1};
    assert(Solution(1,5,1,2) == expected);
  }

  std::cerr << "TestSolution OK" << std::endl;
}

int main() {
//  TestSolution();

  int interval_a, interval_b, num_a, num_b;
  std::cin >> interval_a >> interval_b >> num_a >> num_b;
  const auto result = Solution(interval_a, interval_b, num_a, num_b);
  std::cout << (result.first == -1
                ? std::to_string(-1)
                : std::to_string(result.first) + " " + std::to_string(result.second)
                ) << std::endl;

  return 0;
}
