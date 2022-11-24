#include <iostream>
#include <limits>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

std::string ToLowercase(const std::string& word) {
  std::string lowercase_word(word.size(), ' ');
  std::transform(word.begin(), word.end(), lowercase_word.begin(),
                 [](const char c){ return std::tolower(c); });

  return lowercase_word;
}

bool IsValidIdentifierChar(const char ch) {
  return ('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z') || ('0' <= ch && ch <= '9') || ch == '_';
}

bool IsDigit(const char ch) {
  return '0' <= ch && ch <= '9';
}

bool IsValidIdentifier(const std::string& str, const bool may_start_with_digit) {
  if (str.empty()) {
    return false;
  } // str not empty
  if (!may_start_with_digit && IsDigit(str[0])) {
    return false;
  } // may_start_with_digit or first char is not a digit
  if (!std::all_of(str.begin(), str.end(), [](const char ch) { return IsValidIdentifierChar(ch); })) {
    return false;
  } // all chars are valid for identifier
  if (std::all_of(str.begin(), str.end(), [](const char ch) { return IsDigit(ch); })) {
    return false;
  } // has at least 1 non-digit char

  return true;
}

int main() {
  int keywords_n = 0;
  std::string is_register_sensitive_str, may_start_with_digit_str;
  std::cin >> keywords_n >> is_register_sensitive_str >> may_start_with_digit_str;
  const bool is_register_sensitive = (is_register_sensitive_str == "yes");
  const bool may_start_with_digit = (may_start_with_digit_str == "yes");

  std::unordered_set<std::string> keywords;
  for (int i = 0; i < keywords_n; ++i) {
    std::string keyword;
    std::cin >> keyword;
    keyword = is_register_sensitive ? keyword : ToLowercase(keyword);
    keywords.insert(keyword);
  }

  std::unordered_map<std::string, int> identifier_to_frequency;
  std::unordered_map<std::string, int> identifier_to_first_pos;
  std::string top_identifier;
  int top_identifier_frequency = 0;
  int top_identifier_first_pos = std::numeric_limits<int>::max();

  std::stringstream text;
  char text_ch;
  std::string identifier;
  int ch_pos = 0;
  while (std::cin.get(text_ch)) {
    ++ch_pos;
    if (IsValidIdentifierChar(text_ch)) {
      identifier += text_ch;
    } else {
      if (IsValidIdentifier(identifier, may_start_with_digit)) {
        identifier = is_register_sensitive ? identifier : ToLowercase(identifier);
        if (keywords.count(identifier) == 0) { // is valid identifier and is not a keyword
          ++identifier_to_frequency[identifier];
          if (identifier_to_first_pos.find(identifier) == identifier_to_first_pos.end()) {
            identifier_to_first_pos[identifier] = ch_pos - static_cast<int>(identifier.size());
          }
          if (identifier_to_frequency[identifier] > top_identifier_frequency ||
              (identifier_to_frequency[identifier] == top_identifier_frequency && identifier_to_first_pos[identifier] < top_identifier_first_pos)) {
            top_identifier = identifier;
            top_identifier_frequency = identifier_to_frequency[identifier];
            top_identifier_first_pos = identifier_to_first_pos[identifier];
          }
        } // is a keyword
      } // not a valid identifier
      identifier.clear();
    }
  }

  if (!identifier.empty()) {
    if (IsValidIdentifier(identifier, may_start_with_digit)) {
      identifier = is_register_sensitive ? identifier : ToLowercase(identifier);
      if (keywords.count(identifier) == 0) { // is valid identifier and is not a keyword
        ++identifier_to_frequency[identifier];
        if (identifier_to_first_pos.find(identifier) == identifier_to_first_pos.end()) {
          identifier_to_first_pos[identifier] = ch_pos - static_cast<int>(identifier.size());
        }
        if (identifier_to_frequency[identifier] > top_identifier_frequency ||
            (identifier_to_frequency[identifier] == top_identifier_frequency && identifier_to_first_pos[identifier] < top_identifier_first_pos)) {
          top_identifier = identifier;
          top_identifier_frequency = identifier_to_frequency[identifier];
          top_identifier_first_pos = identifier_to_first_pos[identifier];
        }
      } // is a keyword
    } // not a valid identifier
  }

  std::cout << top_identifier << std::endl;

  return 0;
}
