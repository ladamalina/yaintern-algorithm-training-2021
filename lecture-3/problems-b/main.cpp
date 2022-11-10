#include <algorithm>
#include <iostream>
#include <sstream>
#include <set>

int main() {
  std::string in_a_str;
  std::getline(std::cin, in_a_str);
  std::stringstream in_a(in_a_str);

  std::string in_b_str;
  std::getline(std::cin, in_b_str);
  std::stringstream in_b(in_b_str);

  std::set<int> nums_a;
  int num_a = 0;
  while (in_a >> num_a)
    nums_a.insert(num_a);

  std::set<int> nums_b;
  int num_b = 0;
  while (in_b >> num_b)
    nums_b.insert(num_b);

  std::set<int> intersect;
  std::set_intersection(nums_a.begin(), nums_a.end(), nums_b.begin(), nums_b.end(),
                        std::inserter(intersect, intersect.begin()));

  for (const auto n : intersect) {
    if (n != *intersect.begin())
      std::cout << ' ';
    std::cout << n;
  }

  std::cout << std::endl;

  return 0;
}
