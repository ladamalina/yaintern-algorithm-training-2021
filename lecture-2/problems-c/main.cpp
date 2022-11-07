#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;

  std::vector<int> nums(n);
  for (int i = 0; i < n; ++i)
    std::cin >> nums[i];

  int target_num = 0;
  std::cin >> target_num;

  int min_diff = std::numeric_limits<int>::max();
  int closest_num = 0;
  for (const int num : nums) {
    int diff = std::abs(num - target_num);
    if (diff < min_diff) {
      min_diff = diff;
      closest_num = num;
    }
  }

  std::cout << closest_num << std::endl;

  return 0;
}
