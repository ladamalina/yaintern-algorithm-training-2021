#include <iostream>
#include <unordered_map>

int main() {
  int word_len = 0;
  int str_len = 0;
  std::cin >> word_len >> str_len;
  if (word_len > str_len) {
    std::cout << 0 << std::endl;
    return 0;
  } // word_len <= str_len

  std::string word, str;
  std::cin >> word >> str;

  std::unordered_map<char, int> word_dict;
  for (const auto ch : word) {
    ++word_dict[ch];
  }

  int pos_count = 0;

  std::unordered_map<char, int> substr_dict;
  for (int i = 0; i < word_len; ++i) {
    ++substr_dict[str[i]];
  }
  if (word_dict == substr_dict) {
    ++pos_count;
  }

  for (int i = word_len; i < str_len; ++i) {
    ++substr_dict[str[i]];
    --substr_dict[str[i - word_len]];
    if (substr_dict[str[i - word_len]] <= 0) {
      substr_dict.erase(str[i - word_len]);
    }
    if (word_dict == substr_dict) {
      ++pos_count;
    }
  }

  std::cout << pos_count << std::endl;

  return 0;
}
