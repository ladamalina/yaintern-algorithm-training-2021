#include <iostream>
#include <vector>

int main() {
  int keys_n = 0;
  std::cin >> keys_n;
  std::vector<int> keys_capacity(keys_n);
  for (int i = 0; i < keys_n; ++i) {
    std::cin >> keys_capacity[i];
  }

  int press_n = 0;
  std::cin >> press_n;
  int key = 0;
  for (int i = 0; i < press_n; ++i) {
    std::cin >> key;
    --keys_capacity[key - 1];
  }

  for (int i = 0; i < keys_n; ++i) {
    std::cout << (keys_capacity[i] >= 0 ? "NO" : "YES") << '\n';
  }

  return 0;
}
