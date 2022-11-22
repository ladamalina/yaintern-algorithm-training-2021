#include <iostream>
#include <map>

int main() {
  std::map<std::string, std::map<std::string, int64_t>> orders;
  std::string client, good;
  int count = 0;
  while (std::cin >> client >> good >> count) {
    orders[client][good] += count;
  }
  for (auto& [client_name, goods] : orders) {
    std::cout << client_name << ":\n";
    for (auto& [good_name, good_count] : goods) {
      std::cout << good_name << ' ' << good_count << '\n';
    }
  }

  return 0;
}
