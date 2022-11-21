#include <iostream>
#include <string>
#include <unordered_map>

int main() {
  std::unordered_map<std::string, std::string> dict;
  int num = 0;
  std::cin >> num;
  std::string word_a, word_b;
  for (int i = 0; i < num; ++i) {
    std::cin >> word_a >> word_b;
    dict[word_a] = word_b;
    dict[word_b] = word_a;
  }
  std::string word;
  std::cin >> word;

  std::cout << dict[word] << std::endl;

  return 0;
}
