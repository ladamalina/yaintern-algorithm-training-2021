#include <iostream>
#include <unordered_set>

int main() {
  int x, y, z, n;
  std::cin >> x >> y >> z >> n;

  std::unordered_set<int> need_button;
  if (n == 0 && n != x && n != y && n != z)
    need_button.insert(n);

  while (n > 0) {
    int d = n % 10;
    n = n / 10;
    if (d != x && d != y && d != z)
      need_button.insert(d);
  }

  std::cout << need_button.size() << std::endl;

  return 0;
}
