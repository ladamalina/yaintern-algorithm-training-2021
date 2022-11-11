#include <iostream>
#include <string>
#include <unordered_set>

int main() {
  std::string genom_a, genom_b;
  std::cin >> genom_a >> genom_b;

  std::unordered_set<std::string_view> codes_b;
  for (size_t i = 1; i < genom_b.size(); ++i)
    codes_b.insert(genom_b.substr(i - 1, 2));

  size_t count = 0;
  for (size_t i = 1; i < genom_a.size(); ++i)
    count += codes_b.count(genom_a.substr(i - 1, 2));

  std::cout << count << std::endl;

  return 0;
}
