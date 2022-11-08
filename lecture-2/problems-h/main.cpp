#include <cassert>
#include <iostream>
#include <set>
#include <sstream>
#include <vector>

std::vector<int> GetMaxMultiply(const std::vector<int>& nums) {
  std::multiset<int64_t> top2_min;
  std::multiset<int64_t> top3_max;
  for (const auto num : nums) {
    top2_min.insert(num);
    if (top2_min.size() > 2)
      top2_min.erase(std::prev(top2_min.end()));
    top3_max.insert(num);
    if (top3_max.size() > 3)
      top3_max.erase(top3_max.begin());
  }

  int64_t multiply_neg = *top2_min.begin() * *top2_min.rbegin() * *top3_max.rbegin();
  int64_t multiply_pos = *top3_max.begin() * *std::next(top3_max.begin()) * *top3_max.rbegin();

  if (multiply_pos > multiply_neg)
    return {static_cast<int>(*top3_max.begin()), static_cast<int>(*std::next(top3_max.begin())), static_cast<int>(*top3_max.rbegin())};

  return {static_cast<int>(*top2_min.begin()), static_cast<int>(*top2_min.rbegin()), static_cast<int>(*top3_max.rbegin())};
}

void TestGetMaxMultiply() {
  {
    const std::vector<int> nums{3, 5, 1, 7, 9, 0, 9, -3, 10};
    const std::vector<int> expected{9, 9, 10};
    const std::vector<int> actual = GetMaxMultiply(nums);
    assert(actual == expected);
  }
  {
    const std::vector<int> nums{-5, -30000, -12};
    const std::vector<int> expected{-30000, -12, -5};
    const std::vector<int> actual = GetMaxMultiply(nums);
    assert(actual == expected);
  }
  {
    const std::vector<int> nums{1, 2, 3};
    const std::vector<int> expected{1, 2, 3};
    const std::vector<int> actual = GetMaxMultiply(nums);
    assert(actual == expected);
  }
  {
    const std::vector<int> nums{-100, -50, 0, 1, 2, 3};
    const std::vector<int> expected{-100, -50, 3};
    const std::vector<int> actual = GetMaxMultiply(nums);
    assert(actual == expected);
  }
  {
    const std::vector<int> nums{-100, -50, 0, 1};
    const std::vector<int> expected{-100, -50, 1};
    const std::vector<int> actual = GetMaxMultiply(nums);
    assert(actual == expected);
  }
  {
    const std::vector<int> nums{-100, -50, 0, 1};
    const std::vector<int> expected{-100, -50, 1};
    const std::vector<int> actual = GetMaxMultiply(nums);
    assert(actual == expected);
  }
}

int main() {
  TestGetMaxMultiply();

  std::vector<int> nums;
  int num = 0;
  while (std::cin >> num) {
    nums.push_back(num);
  }

  const auto result = GetMaxMultiply(nums);
  std::cout << result[0] << ' ' << result[1] << ' ' << result[2] << std::endl;

  return 0;
}
