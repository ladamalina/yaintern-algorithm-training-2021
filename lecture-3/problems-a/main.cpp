#include <iostream>
#include <unordered_set>

int main() {
  std::unordered_set<int> nums;
  int num = 0;
  while (std::cin >> num) {
    nums.insert(num);
  }

  std::cout << nums.size() << std::endl;

  return 0;
}
