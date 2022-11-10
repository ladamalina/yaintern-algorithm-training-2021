#include <algorithm>
#include <iostream>
#include <sstream>
#include <set>

int main() {
  int toys_a_n = 0;
  int toys_b_n = 0;
  std::cin >> toys_a_n >> toys_b_n;

  std::set<int> toys_a;
  for (int i = 0; i < toys_a_n; ++i) {
    int toy = 0;
    std::cin >> toy;
    toys_a.insert(toy);
  }

  std::set<int> toys_b;
  for (int i = 0; i < toys_b_n; ++i) {
    int toy = 0;
    std::cin >> toy;
    toys_b.insert(toy);
  }

  std::set<int> toys_ab;
  std::set_intersection(toys_a.begin(), toys_a.end(), toys_b.begin(), toys_b.end(),
                        std::inserter(toys_ab, toys_ab.begin()));

  std::cout << toys_ab.size() << std::endl;
  for (const auto toy : toys_ab) {
    if (toy != *toys_ab.begin())
      std::cout << ' ';
    std::cout << toy;
  }
  std::cout << std::endl;

  std::cout << (toys_a.size() - toys_ab.size()) << std::endl;
  bool first_a = true;
  for (const auto toy : toys_a) {
    if (!first_a)
      std::cout << ' ';
    if (toys_ab.count(toy) == 0) {
      std::cout << toy;
      first_a = false;
    }
  }
  std::cout << std::endl;

  std::cout << (toys_b.size() - toys_ab.size()) << std::endl;
  bool first_b = true;
  for (const auto toy : toys_b) {
    if (!first_b)
      std::cout << ' ';
    if (toys_ab.count(toy) == 0) {
      std::cout << toy;
      first_b = false;
    }
  }
  std::cout << std::endl;

  return 0;
}
