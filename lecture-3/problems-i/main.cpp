#include <algorithm>
#include <iostream>
#include <set>
#include <string>

int main() {
  int n = 0; // количество школьников
  std::cin >> n;

  std::set<std::string> all_langs;
  std::set<std::string> common_langs;
  int langs_n = 0; // кол-во языков, которые знает i-й школьник
  std::string lang;
  for (int i = 0; i < n; ++i) {
    std::cin >> langs_n;
    std::set<std::string> current_langs;
    for (int j = 0; j < langs_n; ++j) {
      std::cin >> lang;
      all_langs.insert(lang);
      current_langs.insert(lang);
    }
    if (i == 0)
      common_langs = current_langs;
    std::set<std::string> common_langs_intersection;
    std::set_intersection(common_langs.begin(), common_langs.end(),
                          current_langs.begin(), current_langs.end(),
                          std::inserter(common_langs_intersection, common_langs_intersection.begin()));
    common_langs = std::move(common_langs_intersection);
  }

  std::cout << common_langs.size() << std::endl;
  for (const auto& str : common_langs) {
    std::cout << str << std::endl;
  }

  std::cout << all_langs.size() << std::endl;
  for (const auto& str : all_langs) {
    std::cout << str << std::endl;
  }

  return 0;
}
