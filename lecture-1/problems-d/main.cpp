#include <cassert>
#include <iostream>
#include <tuple>

struct SolutionResult {
  bool has_no_solution = false;
  bool has_many_solutions = false;
  int  solution = 0;
};

bool operator== (const SolutionResult& lhs, const SolutionResult& rhs) {
  return std::tie(lhs.has_no_solution, lhs.has_many_solutions, lhs.solution) ==
         std::tie(rhs.has_no_solution, rhs.has_many_solutions, rhs.solution);
}

SolutionResult Solution(int a, int b, int c) {
  // Решите в целых числах уравнение sqrt(ax+b) = c
  if (c < 0) {
    return {true, false};
  }
  int rhs = c*c - b;
  if (a == 0 && rhs == 0) {
    return {false, true};
  }
  if (a == 0 && rhs != 0) {
    return {true, false};
  }
  if (a != 0 && rhs == 0) {
    return {false, false, 0};
  } // a != 0 && rhs != 0
  if (rhs % a) {
    return {true, false};
  } // rhs % a == 0
  int x = rhs / a;
  if (a * x + b < 0) {
    return {true, false};
  }
  return {false, false, x};
}

void TestSolution() {
  assert(Solution(0, 0, 0).has_many_solutions);
  assert(Solution(1, 0, 0).solution == 0);
  assert(Solution(1, 2, 3).solution == 7);
  assert(Solution(1, 2, -3).has_no_solution);
}

int main() {
  // TestSolution();

  int a, b, c;
  std::cin >> a >> b >> c;

  const SolutionResult result = Solution(a, b, c);
  if (result.has_no_solution) {
    std::cout << "NO SOLUTION" << std::endl;
  } else if (result.has_many_solutions) {
    std::cout << "MANY SOLUTIONS" << std::endl;
  } else {
    std::cout << result.solution << std::endl;
  }

  return 0;
}
