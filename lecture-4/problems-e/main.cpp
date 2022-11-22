#include <iostream>
#include <unordered_map>

int main() {
  int blocks_n = 0;
  std::cin >> blocks_n;
  std::unordered_map<int, int> bricks;
  int w = 0;
  int h = 0;
  for (int i = 0; i < blocks_n; ++i) {
    std::cin >> w >> h;
    bricks[w] = h > bricks[w] ? h : bricks[w];
  }
  int64_t height = 0;
  for (auto [brick_w, brick_h] : bricks) {
    height += brick_h;
  }
  std::cout << height << std::endl;

  return 0;
}
