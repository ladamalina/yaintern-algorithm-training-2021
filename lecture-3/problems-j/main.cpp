#include <algorithm>
#include <iostream>
#include <set>

using Point = std::pair<int, int>;
struct Area {
  int min_xmy = 0; // min x
  int max_xmy = 0; // max x
  int min_xpy = 0; // min y
  int max_xpy = 0; // max y

  [[nodiscard]] std::set<Point> Points() const {
    std::set<Point> points;
    for (int p = min_xmy; p <= max_xmy; ++p) {
      for (int q = min_xpy; q <= max_xpy; ++q) {
        if ((p + q) % 2 == 0) {
          int x = (p + q) / 2;
          int y = x - p;
          points.insert({x, y});
        }
      }
    }

    return points;
  }
};

Area Intersect(const Area& a, const Area& b) {
  return {
    std::max(a.min_xmy, b.min_xmy),
    std::min(a.max_xmy, b.max_xmy),
    std::max(a.min_xpy, b.min_xpy),
    std::min(a.max_xpy, b.max_xpy),
  };
}

Area GetNavigatorArea(const Point& point, const int navigator_d) {
  int p = point.first - point.second; // x
  int q = point.first + point.second; // y

  return {p - navigator_d, p + navigator_d, q - navigator_d, q + navigator_d};
}

Area ExtendArea(const Area& area, const int navigator_d) {
  return {
    area.min_xmy - navigator_d,
    area.max_xmy + navigator_d,
    area.min_xpy - navigator_d,
    area.max_xpy + navigator_d
  };
}

int main() {
//  TestGetPossiblePoints();

  int navigator_t = 0; // навигатор, который каждые t минут говорит Мише, в какой точке он находится
  int navigator_d = 0; // навигатор показывает не точное положение Миши, он может показать любую из точек, манхэттенское расстояние от которых до Миши не превышает d
  int navigator_n = 0; // Через t × n минут от начала пробежки, получив n-е сообщение от навигатора, Миша решил, что пора бежать домой
  std::cin >> navigator_t >> navigator_d >> navigator_n;

  Area prev_accessible_area{-navigator_t, navigator_t, -navigator_t, navigator_t};
  Area last_intersection;
  for (int i = 0; i < navigator_n; ++i) {
    Point last_center;
    std::cin >> last_center.first >> last_center.second;
    Area last_possible_points = GetNavigatorArea(last_center, navigator_d);
    auto intersection = Intersect(prev_accessible_area, last_possible_points);
    prev_accessible_area = ExtendArea(intersection, navigator_t);
    last_intersection = intersection;
  }

  auto points = last_intersection.Points();
  std::cout << points.size() << std::endl;
  for (const auto& [x, y] : points)
    std::cout << x << ' ' << y << std::endl;

  return 0;
}
