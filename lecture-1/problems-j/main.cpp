#include <iostream>

int main() {
  double a, b, c, d, e, f;
  std::cin >> a >> b >> c >> d >> e >> f;
  double delta = a * d - c * b;
  double delta1 = e * d - f * b;
  double delta2 = a * f - c * e;
  if (delta != 0) {
    std::cout << 2 << " " << delta1 / delta << " " << delta2 / delta << std::endl;
    return 0;
  } // delta == 0.0

  if (delta1 != 0 || delta2 != 0) {
    std::cout << 0 << std::endl;
    return 0;
  } // delta1 == 0 && delta2 == 0

  if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) {
    std::cout << 5 << std::endl;
    return 0;
  } // есть хотя бы один ненулевой коэффициент

  if (a != 0 && b != 0) {
    std::cout << 1 << " " << -a / b << " " << e / b << std::endl;
    return 0;
  } // a или b равен нулю

  if (c != 0 && d != 0) {
    std::cout << 1 << " " << -c / d << " " << f / d << std::endl;
    return 0;
  } // c или d равен нулю

  if (a != 0) {
    std::cout << 3 << " " << e / a << std::endl;
    return 0;
  }
  if (b != 0) {
    std::cout << 4 << " " << e / b << std::endl;
    return 0;
  }
  if (c != 0) {
    std::cout << 3 << " " << f / c << std::endl;
    return 0;
  }
  if (d != 0) {
    std::cout << 4 << " " << f / d << std::endl;
    return 0;
  }

  std::cout << 0 << std::endl;

  return 0;
}
