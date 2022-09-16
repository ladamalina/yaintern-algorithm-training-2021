#include <cassert>
#include <iostream>

bool MayBeTriangle(const int a, const int b, const int c) {
  if (a + b <= c) {
    return false;
  }
  if (a + c <= b) {
    return false;
  }
  if (b + c <= a) {
    return false;
  }
  return true;
}

void TestMayBeTriangle() {
  assert(MayBeTriangle(3,3,3));

  assert(MayBeTriangle(9,3,3) == false);
  assert(MayBeTriangle(3,9,3) == false);
  assert(MayBeTriangle(3,3,9) == false);

  assert(MayBeTriangle(6,3,3) == false);
  assert(MayBeTriangle(3,6,3) == false);
  assert(MayBeTriangle(3,3,6) == false);

  assert(MayBeTriangle(5,3,3));
  assert(MayBeTriangle(3,5,3));
  assert(MayBeTriangle(3,3,5));
}

int main() {
  // TestMayBeTriangle();

  int a, b, c;
  std::cin >> a >> b >> c;

  std::cout << (MayBeTriangle(a, b, c) ? "YES" : "NO") << std::endl;

  return 0;
}
