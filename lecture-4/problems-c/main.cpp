#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>

int main() {
  std::unordered_map<std::string, int> word_to_frequency;
  std::map<int, std::set<std::string>> frequency_to_words;
  std::string word;
  while (std::cin >> word) {
    auto prev_frequency = word_to_frequency[word];
    if (prev_frequency > 0) {
      frequency_to_words[prev_frequency].erase(word);
    }
    auto frequency = ++word_to_frequency[word];
    frequency_to_words[frequency].insert(word);
  }

  std::cout << *(std::prev(frequency_to_words.end())->second.begin()) << std::endl;

  return 0;
}
