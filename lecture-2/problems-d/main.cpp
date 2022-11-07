#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  std::string input_str;
  std::getline(std::cin, input_str);
  std::stringstream input(input_str);

  std::vector<int> nums;
  nums.reserve(input_str.size() / 2);
  int num = 0;
  while (input >> num)
    nums.push_back(num);

  if (nums.size() <= 2) {
    std::cout << 0 << std::endl;
    return 0;
  }

  int count = 0;
  for (size_t i = 1; i + 1 < nums.size(); ++i) {
    count += (nums[i-1] < nums[i] && nums[i] > nums[i+1]) ? 1 : 0;
  }
  std::cout << count << std::endl;

  return 0;
}
