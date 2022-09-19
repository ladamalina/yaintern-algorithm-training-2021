#include <cassert>
#include <iostream>
#include <vector>

struct SolutionResult {
  int entrance_num = 0;
  int floor_num = 0;
};

bool operator== (const SolutionResult& lhs, const SolutionResult& rhs) {
  return lhs.entrance_num == rhs.entrance_num &&
         lhs.floor_num    == rhs.floor_num;
}

std::vector<int> GetPossibleAptsPerFloor(int floors_in_building, int known_apt, int known_entrance,
                                         int known_floor) {
  int range_min = known_apt / (known_floor + floors_in_building * (known_entrance-1));
  int range_max = (known_apt - 1) / (known_floor - 1 + floors_in_building * (known_entrance-1));
  std::vector<int> possible_apts_per_floor;
  possible_apts_per_floor.reserve(range_max - range_min + 1);
  for (int i = range_min; i <= range_max; ++i) {
    if (i == 0) {
      continue;
    }
    if ((known_floor - 1 + floors_in_building * (known_entrance-1)) * i + (known_apt - 1) % i == known_apt-1) {
      possible_apts_per_floor.push_back(i);
    }
  }
  return possible_apts_per_floor;
}

SolutionResult Solution(int apt_to_find, int floors_in_building, int known_apt, int known_entrance, int known_floor) {
  // Проверяем корректность известных данных
  if (known_floor > floors_in_building) {
    return {-1, -1};
  }

  // Ищем возможное число квартир на этаже
  std::vector<int> possible_apts_per_floor;
  if (known_entrance == 1 && known_floor == 1) {
    if (apt_to_find <= known_apt) {
      return {1, 1};
    } else {
      possible_apts_per_floor.reserve(apt_to_find - known_apt + 1);
      for (int i = known_apt; i <= apt_to_find; ++i) {
        possible_apts_per_floor.push_back(i);
      }
    }
  } else {
    possible_apts_per_floor = GetPossibleAptsPerFloor(floors_in_building, known_apt, known_entrance, known_floor);
  }

  int result_entrance_to_find = -1;
  int result_floor_to_find = -1;

  for (const auto apts_per_floor : possible_apts_per_floor) {
    int floor_to_find_abs = (apt_to_find - 1 - (apt_to_find - 1) % apts_per_floor) / apts_per_floor + 1;
    int floor_to_find = floor_to_find_abs % floors_in_building;
    int entrance_to_find = (floor_to_find_abs - floor_to_find) / floors_in_building + 1;
    if (floor_to_find == 0) {
      floor_to_find = floors_in_building;
      --entrance_to_find;
    }
    if (result_entrance_to_find == -1 && result_floor_to_find == -1) { // первое возможное решение найдено
      result_entrance_to_find = entrance_to_find;
      result_floor_to_find = floor_to_find;
    } else { // ранее было найдено решение
      if (result_entrance_to_find != entrance_to_find) {
        result_entrance_to_find = 0;
      }
      if (result_floor_to_find != floor_to_find) {
        result_floor_to_find = 0;
      }
    }
  }

  return {result_entrance_to_find, result_floor_to_find};
}

void TestSolution() {
  // ---------- многоэтажные дома ----------

  // можем посчитать число квартир на этаже. средние этажи
  {
    auto actual_result = Solution(89, 20, 41, 1, 11);
    SolutionResult expected_result{2, 3};
    assert(actual_result == expected_result);
  }
  // можем посчитать число квартир на этаже. краевые случаи
  {
    auto actual_result = Solution(8, 4, 10, 1, 4);
    SolutionResult expected_result{1, 3};
    assert(actual_result == expected_result);
  }
  // можем посчитать число квартир на этаже. краевые случаи
  {
    auto actual_result = Solution(8, 4, 12, 1, 4);
    SolutionResult expected_result{1, 3};
    assert(actual_result == expected_result);
  }
  // можем посчитать число квартир на этаже. краевые случаи
  {
    auto actual_result = Solution(8, 4, 13, 2, 1);
    SolutionResult expected_result{1, 3};
    assert(actual_result == expected_result);
  }
  // можем посчитать число квартир на этаже. краевые случаи
  {
    auto actual_result = Solution(8, 4, 15, 2, 1);
    SolutionResult expected_result{1, 3};
    assert(actual_result == expected_result);
  }
  // можем посчитать число квартир на этаже. краевые случаи
  {
    auto actual_result = Solution(8, 4, 22, 2, 4);
    SolutionResult expected_result{1, 3};
    assert(actual_result == expected_result);
  }
  // можем посчитать число квартир на этаже. краевые случаи
  {
    auto actual_result = Solution(8, 4, 24, 2, 4);
    SolutionResult expected_result{1, 3};
    assert(actual_result == expected_result);
  }
  // можем посчитать число квартир на этаже. краевые случаи
  {
    auto actual_result = Solution(12, 4, 24, 2, 4);
    SolutionResult expected_result{1, 4};
    assert(actual_result == expected_result);
  }
  // можем посчитать число квартир на этаже. краевые случаи
  {
    auto actual_result = Solution(22, 4, 24, 2, 4);
    SolutionResult expected_result{2, 4};
    assert(actual_result == expected_result);
  }
  // можем посчитать число квартир на этаже. краевые случаи
  {
    auto actual_result = Solution(13, 4, 24, 2, 4);
    SolutionResult expected_result{2, 1};
    assert(actual_result == expected_result);
  }
  // можем посчитать число квартир на этаже. краевые случаи
  {
    auto actual_result = Solution(15, 4, 24, 2, 4);
    SolutionResult expected_result{2, 1};
    assert(actual_result == expected_result);
  }
  // можем посчитать число квартир на этаже. краевые случаи
  {
    auto actual_result = Solution(1, 4, 24, 2, 4);
    SolutionResult expected_result{1, 1};
    assert(actual_result == expected_result);
  }
  // можем посчитать число квартир на этаже. краевые случаи
  {
    auto actual_result = Solution(3, 4, 24, 2, 4);
    SolutionResult expected_result{1, 1};
    assert(actual_result == expected_result);
  }

  // ---------- одноэтажные дома с 1 квартирой на этаже ----------

  {
    auto actual_result = Solution(4, 1, 1, 1, 1);
    SolutionResult expected_result{0, 1};
    assert(actual_result == expected_result);
  }
  {
    auto actual_result = Solution(4, 1, 2, 2, 1);
    SolutionResult expected_result{4, 1};
    assert(actual_result == expected_result);
  }
  {
    auto actual_result = Solution(1, 1, 2, 2, 1);
    SolutionResult expected_result{1, 1};
    assert(actual_result == expected_result);
  }
  {
    auto actual_result = Solution(4, 1, 3, 3, 1);
    SolutionResult expected_result{4, 1};
    assert(actual_result == expected_result);
  }
  {
    auto actual_result = Solution(2, 1, 3, 3, 1);
    SolutionResult expected_result{2, 1};
    assert(actual_result == expected_result);
  }

  // ---------- одноэтажные дома с 3 квартирами на этаже ----------
  {
    auto actual_result = Solution(4, 1, 1, 1, 1);
    SolutionResult expected_result{0, 1};
    assert(actual_result == expected_result);
  }
  {
    auto actual_result = Solution(4, 1, 3, 1, 1);
    SolutionResult expected_result{0, 1};
    assert(actual_result == expected_result);
  }
  {
    auto actual_result = Solution(2, 1, 3, 1, 1);
    SolutionResult expected_result{1, 1};
    assert(actual_result == expected_result);
  }
  // входные данные не позволяют однозначно определить
  // [1,2][3,4] или [1,2,3][4,5,6]
  {
    auto actual_result = Solution(3, 1, 4, 2, 1);
    SolutionResult expected_result{0, 1};
    assert(actual_result == expected_result);
  }

  // ---------- негативные случаи ----------

  // не можем посчитать число квартир на этаже. невозможно определить подъезд
  {
    auto actual_result = Solution(11, 1, 1, 1, 1);
    SolutionResult expected_result{0, 1};
    assert(actual_result == expected_result);
  }
  // не можем посчитать число квартир на этаже. невозможно определить этаж
  {
    auto actual_result = Solution(11, 12, 1, 1, 1);
    SolutionResult expected_result{1, 0};
    assert(actual_result == expected_result);
  }
  // не можем посчитать число квартир на этаже. обе квартиры на первом
  {
    auto actual_result = Solution(2, 12, 3, 1, 1);
    SolutionResult expected_result{1, 1};
    assert(actual_result == expected_result);
  }
  // не можем посчитать число квартир на этаже. невозможно определить ни подъезд, ни этаж
  {
    auto actual_result = Solution(13, 12, 1, 1, 1);
    SolutionResult expected_result{0, 0};
    assert(actual_result == expected_result);
  }
  // не можем посчитать число квартир на этаже. можем предположить подъезд
  {
    auto actual_result = Solution(10, 4, 3, 1, 1);
    SolutionResult expected_result{1, 0};
    assert(actual_result == expected_result);
  }
  // не можем посчитать число квартир на этаже. невозможно определить ни подъезд, ни этаж
  {
    auto actual_result = Solution(20, 4, 3, 1, 1);
    SolutionResult expected_result{0, 0};
    assert(actual_result == expected_result);
  }
  // некорректные данные на входе
  {
    auto actual_result = Solution(3, 2, 2, 2, 1);
    SolutionResult expected_result{-1, -1};
    assert(actual_result == expected_result);
  }

  std::cerr << "TestSolution OK" << std::endl;
}

int main() {
  TestSolution();

  int apt_to_find, floors_in_building, known_apt, known_entrance, known_floor;
  std::cin >> apt_to_find >> floors_in_building >> known_apt >> known_entrance >> known_floor;

  const SolutionResult result = Solution(apt_to_find, floors_in_building, known_apt, known_entrance, known_floor);
  std::cout << result.entrance_num << " " << result.floor_num << std::endl;

  return 0;
}
