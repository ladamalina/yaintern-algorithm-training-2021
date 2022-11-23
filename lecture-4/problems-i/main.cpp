#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

std::string ToLowercase(const std::string& word) {
  std::string lowercase_word(word.size(), ' ');
  std::transform(word.begin(), word.end(), lowercase_word.begin(),
                 [](const char c){ return std::tolower(c); });

  return lowercase_word;
}

int CountUppercaseChars(const std::string& word) {
  return static_cast<int>(std::count_if(word.begin(), word.end(),
                                        [](const char ch) { return 'A' <= ch && ch <= 'Z'; }));
}

int main() {
  int dict_n = 0;
  std::cin >> dict_n;
  std::unordered_map<std::string, std::unordered_set<std::string>> dict; // lowercase word -> set of possible use cases
  for (int i = 0; i < dict_n; ++i) {
    std::string dict_word;
    std::cin >> dict_word;
    dict[ToLowercase(dict_word)].insert(std::move(dict_word));
  }

  int errors_n = 0;
  std::string word;
  while (std::cin >> word) {
    std::string lowercase_word = ToLowercase(word);
    if (dict.count(lowercase_word) > 0) { // слово есть в словаре
      errors_n += (dict.at(lowercase_word).count(word) == 0);
      continue;
    } // слова нет в словаре
    int uppercase_chars_n = CountUppercaseChars(word);
    errors_n += (uppercase_chars_n != 1);
  }

  std::cout << errors_n << std::endl;

  return 0;
}
