#include <iostream>
#include <string>
#include <unordered_map>

int main() {
  std::unordered_map<std::string, int> dict;
  std::string word;
  while (std::cin >> word) {
    std::cout << dict[word] << ' ';
    ++dict[word];
  }

  return 0;
}
