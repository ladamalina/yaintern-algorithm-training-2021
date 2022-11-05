#include <cassert>
#include <iostream>
#include <vector>

std::pair<int, int> Solution(int w1, int h1, int w2, int h2) {
  const int max1 = std::max(w1, h1);
  const int min1 = std::min(w1, h1);

  const int max2 = std::max(w2, h2);
  const int min2 = std::min(w2, h2);

  /*
   *                –––––––
   *                |     |
   *   –––––––––––––|  2  |
   *   |     1      |     |
   *   ––––––––––––––––––––
   */
  const int pos1_w = max1 + min2;
  const int pos1_h = std::max(min1, max2);
  const int square1 = pos1_w * pos1_h;

  /*
   *   ––––––––––––––
   *   |      1     |
   *   ––––––––––––––
   *   |     |
   *   |  2  |
   *   |     |
   *   –––––––
   */
  const int pos2_w = std::max(max1, min2);
  const int pos2_h = min1 + max2;
  const int square2 = pos2_w * pos2_h;

  /*
   *                –––––––––––––––––
   *   –––––––––––––|       2       |
   *   |     1      |               |
   *   ––––––––––––––––––––––––––––––
   */
  const int pos3_w = max1 + max2;
  const int pos3_h = std::max(min1, min2);
  const int square3 = pos3_w * pos3_h;

  /*
   *
   *   –––––––––––––
   *   |     1     |
   *   –––––––––––––––––
   *   |       2       |
   *   |               |
   *   –––––––––––––––––
   */
  const int pos4_w = std::max(max1, max2);
  const int pos4_h = min1 + min2;
  const int square4 = pos4_w * pos4_h;

  const int min_square = std::min({square1, square2, square3, square4});
  if (min_square == square1)
    return {pos1_w, pos1_h};
  if (min_square == square2)
    return {pos2_w, pos2_h};
  if (min_square == square3)
    return {pos3_w, pos3_h};
  if (min_square == square4)
    return {pos4_w, pos4_h};

  return {};
}

void TestSolution() {
  {
    auto result = Solution(10, 2, 2, 10);
    std::vector<std::pair<int, int>> possible_results{{20,2},{2,20},{10,4},{4,10}};
    bool success = false;
    for (const auto& [w, h] : possible_results) {
      if (w == result.first && h == result.second)
        success = true;
    }
    assert(success);
  }
  {
    auto result = Solution(5, 7, 3, 2);
    std::vector<std::pair<int, int>> possible_results{{9,5},{5,9}};
    bool success = false;
    for (const auto& [w, h] : possible_results) {
      if (w == result.first && h == result.second)
        success = true;
    }
    assert(success);
  }

  std::cerr << "TestSolution OK" << std::endl;
}

int main() {
//  TestSolution();

  int w1, h1, w2, h2;
  std::cin >> w1 >> h1 >> w2 >> h2;
  const auto result = Solution(w1, h1, w2, h2);
  std::cout << result.first << ' ' << result.second << std::endl;

  return 0;
}
