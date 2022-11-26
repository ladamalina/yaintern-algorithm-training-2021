#include <cassert>
#include <iostream>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int CountRanges(const std::vector<int>& nums, int64_t target_sum) {
  std::unordered_map<int64_t, std::unordered_set<size_t>> prefix_sum_to_indices{{0,{0}}};
  int64_t prev_partial_sum = 0;
  for (size_t i = 0; i < nums.size(); ++i) {
    prev_partial_sum += nums[i];
    prefix_sum_to_indices[prev_partial_sum].insert(i + 1);
  }

  size_t ranges_n = 0;
  for (const auto& [prefix_sum, indices] : prefix_sum_to_indices) {
    auto target_pair_sum = prefix_sum - target_sum;
    if (target_pair_sum == prefix_sum) {
      ranges_n += indices.size() - 1;
      continue;
    } // target_pair_sum != prefix_sum

    auto it = prefix_sum_to_indices.find(target_pair_sum);
    if (it == prefix_sum_to_indices.end()) {
      continue;
    }
    ranges_n += it->second.size();
  }

  return static_cast<int>(ranges_n);
}

void TestCountRanges() {
  {
    const std::vector<int> nums{17, 7, 10, 7, 10};
    const int64_t target_sum = 17;
    const auto ranges_n = CountRanges(nums, target_sum);
    assert(ranges_n == 4);
  }
  {
    const std::vector<int> nums{1, 2, 3, 4, 1};
    const int64_t target_sum = 10;
    const auto ranges_n = CountRanges(nums, target_sum);
    assert(ranges_n == 2);
  }
}

int main() {
//  TestCountRanges();

  int64_t cars_n, target_sum;
  std::cin >> cars_n >> target_sum;
  std::vector<int> cars(cars_n);
  for (int64_t i = 0; i < cars_n; ++i) {
    std::cin >> cars[i];
  }

  const auto ranges_n = CountRanges(cars, target_sum);
  std::cout << ranges_n << std::endl;

  return 0;
}
