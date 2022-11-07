#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <vector>

using TopIds = std::map<int, std::set<int>>;

TopIds GetTopIds(const std::vector<int>& nums) {
  TopIds top;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    top[nums[i]].insert(i);
  }

  return top;
}

int GetTop1MinId(const TopIds& top_ids) {
  auto top_it = top_ids.rbegin();
  int min_id = *(top_it->second.begin());

  return min_id;
}

int GetMaxPossiblePos(const std::vector<int>& nums) {
  const auto top_ids = GetTopIds(nums);
  const auto top1_min_id = GetTop1MinId(top_ids);

  int max_possible_result = -1;
  for (int i = top1_min_id + 1; i + 1 < static_cast<int>(nums.size()); ++i) {
    if (nums[i] % 10 == 5 && nums[i] > nums[i+1] && nums[i] > max_possible_result)
      max_possible_result = nums[i];
  }
  if (max_possible_result == -1)
    return 0;

  int pos = 1 + std::count_if(nums.begin(), nums.end(),
                              [max_possible_result](const auto num) { return num > max_possible_result; });

  return pos;
}

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> nums(n);
  for (int i = 0; i < n; ++i)
    std::cin >> nums[i];

  std::cout << GetMaxPossiblePos(nums) << std::endl;

  return 0;
}
