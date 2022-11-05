#include <cassert>
#include <iostream>

int Solution(int total, int batch, int detail) {
  if (detail > batch)
    return 0;

  int details = 0;
  while (total >= batch) {
    int current_batches_num = total / batch;
    total = total % batch;

    int current_details_num = (batch / detail) * current_batches_num;
    int current_batches_leftover = (batch % detail) * current_batches_num;
    details += current_details_num;

    total += current_batches_leftover;
  }

  return details;
}

void TestSolution() {
  assert(Solution(10, 5, 2) == 4);
  assert(Solution(13, 5, 3) == 3);
  assert(Solution(14, 5, 3) == 4);

  std::cerr << "TestSolution OK" << std::endl;
}

int main() {
//  TestSolution();

  int total, batch, detail;
  std::cin >> total >> batch >> detail;
  const auto result = Solution(total, batch, detail);
  std::cout << result << std::endl;

  return 0;
}
