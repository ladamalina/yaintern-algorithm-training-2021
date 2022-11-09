#include <iostream>
#include <vector>

inline const char STAR = '*';
inline const char EMPTY = ' ';

bool IsInField(const std::vector<std::vector<char>>& field, int y, int x) {
  return !(y < 0 || y >= static_cast<int>(field.size()) || x < 0 || x >= static_cast<int>(field[0].size()));
}

void FillCell(std::vector<std::vector<char>>& field, size_t y, size_t x) {
  if (field[y][x] == STAR)
    return;
  int value = 0;
  std::vector<std::pair<int, int>> neighbors{{y-1,x-1}, {y-1,x}, {y-1,x+1},
                                             {y,x-1}, {y,x+1},
                                             {y+1,x-1}, {y+1,x}, {y+1,x+1}};
  for (const auto& [ny, nx] : neighbors)
    value += (IsInField(field, ny, nx) && field[ny][nx] == '*');

  field[y][x] = std::to_string(value)[0];
}

void FillField(std::vector<std::vector<char>>& field, const std::vector<std::pair<int, int>>& stars) {
  for (const auto& [y, x] : stars)
    field[y-1][x-1] = STAR;

  int n_rows = static_cast<int>(field.size());
  int n_cols = static_cast<int>(field[0].size());

  for (int y = 0; y < n_rows; ++y) {
    for (int x = 0; x < n_cols; ++x) {
      FillCell(field, y, x);
    }
  }
}


int main() {
  int n_rows, n_cols, n_stars;
  std::cin >> n_rows >> n_cols >> n_stars;

  const std::vector<char> field_row(n_cols, EMPTY);
  std::vector<std::vector<char>> field(n_rows, field_row);

  std::vector<std::pair<int, int>> stars(n_stars);
  for (int i = 0; i < n_stars; ++i)
    std::cin >> stars[i].first >> stars[i].second;

  FillField(field, stars);

  for (int y = 0; y < n_rows; ++y) {
    for (int x = 0; x < n_cols; ++x) {
      std::cout << (x == 0 ? "" : " ");
      std::cout << field[y][x];
    }
    std::cout << std::endl;
  }

  return 0;
}
