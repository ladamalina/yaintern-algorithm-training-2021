#include <cassert>
#include <iostream>
#include <vector>

bool IsPalindrome(const std::vector<int>& nums, int left_idx, int right_idx) {
  while (left_idx < right_idx) {
    if (nums[left_idx] != nums[right_idx])
      return false;
    ++left_idx;
    --right_idx;
  }
  return true;
}

std::vector<int> GetMinTail(const std::vector<int>& nums) {
  int i = 0;
  int last_idx = static_cast<int>(nums.size()) - 1;
  while (i < last_idx) {
    if (IsPalindrome(nums, i, last_idx)) break;
    ++i;
  }
  std::vector<int> tail(i);
  for (int j = i - 1; j >= 0; --j)
    tail[i - j - 1] = nums[j];

  return tail;
}

void TestGetMinTail() {
  {
    const std::vector<int> nums{1, 2, 3, 4, 5, 4, 3, 2, 1};
    const auto tail = GetMinTail(nums);
    assert(tail.empty());
  }
  {
    const std::vector<int> nums{1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
    const auto tail = GetMinTail(nums);
    assert(tail.empty());
  }
  {
    const std::vector<int> nums{};
    const auto tail = GetMinTail(nums);
    assert(tail.empty());
  }
  {
    const std::vector<int> nums{1};
    const auto tail = GetMinTail(nums);
    assert(tail.empty());
  }
  {
    const std::vector<int> nums{1, 1};
    const auto tail = GetMinTail(nums);
    assert(tail.empty());
  }
  {
    const std::vector<int> nums{1, 2};
    const auto tail = GetMinTail(nums);
    assert(tail.size() == 1u);
    const std::vector<int> tail_expected{1};
    assert(tail == tail_expected);
  }
  {
    const std::vector<int> nums{1, 2, 2};
    const auto tail = GetMinTail(nums);
    assert(tail.size() == 1u);
    const std::vector<int> tail_expected{1};
    assert(tail == tail_expected);
  }
  {
    const std::vector<int> nums{1, 2, 1, 2, 2};
    const auto tail = GetMinTail(nums);
    assert(tail.size() == 3u);
    const std::vector<int> tail_expected{1, 2, 1};
    assert(tail == tail_expected);
  }
  {
    const std::vector<int> nums{1, 2, 3, 4, 5};
    const auto tail = GetMinTail(nums);
    assert(tail.size() == 4u);
    const std::vector<int> tail_expected{4, 3, 2, 1};
    assert(tail == tail_expected);
  }
  {
    const std::vector<int> nums{1, 2, 3, 4, 5, 5};
    const auto tail = GetMinTail(nums);
    assert(tail.size() == 4u);
    const std::vector<int> tail_expected{4, 3, 2, 1};
    assert(tail == tail_expected);
  }
  {
    const std::vector<int> nums{1, 2, 3, 4, 5, 5, 4};
    const auto tail = GetMinTail(nums);
    assert(tail.size() == 3u);
    const std::vector<int> tail_expected{3, 2, 1};
    assert(tail == tail_expected);
  }
}

int main() {
  TestGetMinTail();

  int n = 0;
  std::cin >> n;
  std::vector<int> nums(n);
  for (int i = 0; i < n; ++i)
    std::cin >> nums[i];

  const auto tail = GetMinTail(nums);
  std::cout << tail.size() << std::endl;
  for (const auto num : tail)
    std::cout << num << ' ';
  std::cout << std::endl;

  return 0;
}
