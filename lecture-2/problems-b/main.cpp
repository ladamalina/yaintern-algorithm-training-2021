#include <iostream>

inline const int LAST_NUM = -2'000'000'000;

int main() {
  bool seen_asc = false;
  bool seen_desc = false;
  bool seen_eq = false;

  int prev_num = 0;
  std::cin >> prev_num;
  int num = 0;
  while (std::cin >> num) {
    if (num == LAST_NUM)
      break;
    if (prev_num == num) seen_eq = true;
    if (prev_num < num)  seen_asc = true;
    if (prev_num > num)  seen_desc = true;

    prev_num = num;
  }

  if (seen_asc && seen_desc) {
    std::cout << "RANDOM" << std::endl;
    return 0;
  }

  if (seen_eq) {
    if (seen_asc) {
      std::cout << "WEAKLY ASCENDING" << std::endl;
      return 0;
    }
    if (seen_desc) {
      std::cout << "WEAKLY DESCENDING" << std::endl;
      return 0;
    }
    std::cout << "CONSTANT" << std::endl;
    return 0;
  } // seen_eq == false

  if (seen_asc) {
    std::cout << "ASCENDING" << std::endl;
    return 0;
  }

  if (seen_desc) {
    std::cout << "DESCENDING" << std::endl;
    return 0;
  }

  // seen_asc == false && seen_asc == false && seen_desc == false
  std::cout << "CONSTANT" << std::endl;
  return 0;
}
