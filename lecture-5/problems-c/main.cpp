#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

template<typename It>
std::vector<int64_t> GetPrefixHeightSums(const It begin_it, const It end_it) {
  std::vector<int64_t> prefix_sums(end_it - begin_it + 1);
  prefix_sums[0] = 0;
  prefix_sums[1] = 0;

  int64_t prefix_sum = 0;
  auto it = std::next(begin_it);
  for (size_t i = 2; i < prefix_sums.size(); ++i) {
    int64_t height = std::max(static_cast<int64_t>(0),
                              static_cast<int64_t>(it->second) - static_cast<int64_t>(std::prev(it)->second));
    prefix_sum += height;
    prefix_sums[i] = prefix_sum;
    ++it;
  }

  return prefix_sums;
}

int64_t GetHeightSum(const std::vector<int64_t>& left_to_right_sums,
                 const std::vector<int64_t>& right_to_left_sums,
                 const int start_i,
                 const int finish_i) {
  return start_i <= finish_i
         ? left_to_right_sums[finish_i] - left_to_right_sums[start_i]
         : right_to_left_sums[finish_i-1] - right_to_left_sums[start_i-1];
}

void TestGetHeightSum() {
  {
    const std::vector<std::pair<int, int>> points{{2,1},{4,5},{7,4},{8,2},{9,6},{11,3},{15,3}};
    const std::vector<int64_t> left_to_right_sums = GetPrefixHeightSums(points.begin(), points.end());
    std::vector<int64_t> right_to_left_sums = GetPrefixHeightSums(points.rbegin(), points.rend());
    std::reverse(right_to_left_sums.begin(), right_to_left_sums.end());
    {
      const int start_i = 2;
      const int finish_i = 2;
      assert(GetHeightSum(left_to_right_sums, right_to_left_sums, start_i, finish_i) == 0);
    }
    {
      const int start_i = 1;
      const int finish_i = 2;
      assert(GetHeightSum(left_to_right_sums, right_to_left_sums, start_i, finish_i) == 4);
    }
    {
      const int start_i = 2;
      const int finish_i = 3;
      assert(GetHeightSum(left_to_right_sums, right_to_left_sums, start_i, finish_i) == 0);
    }
    {
      const int start_i = 1;
      const int finish_i = 5;
      assert(GetHeightSum(left_to_right_sums, right_to_left_sums, start_i, finish_i) == 8);
    }
    {
      const int start_i = 1;
      const int finish_i = 7;
      assert(GetHeightSum(left_to_right_sums, right_to_left_sums, start_i, finish_i) == 8);
    }
    {
      const int start_i = 7;
      const int finish_i = 7;
      assert(GetHeightSum(left_to_right_sums, right_to_left_sums, start_i, finish_i) == 0);
    }
    {
      const int start_i = 7;
      const int finish_i = 6;
      assert(GetHeightSum(left_to_right_sums, right_to_left_sums, start_i, finish_i) == 0);
    }
    {
      const int start_i = 7;
      const int finish_i = 5;
      assert(GetHeightSum(left_to_right_sums, right_to_left_sums, start_i, finish_i) == 3);
    }
    {
      const int start_i = 7;
      const int finish_i = 1;
      assert(GetHeightSum(left_to_right_sums, right_to_left_sums, start_i, finish_i) == 6);
    }
    {
      const int start_i = 2;
      const int finish_i = 1;
      assert(GetHeightSum(left_to_right_sums, right_to_left_sums, start_i, finish_i) == 0);
    }
    {
      const int start_i = 3;
      const int finish_i = 2;
      assert(GetHeightSum(left_to_right_sums, right_to_left_sums, start_i, finish_i) == 1);
    }
  }
  {
    const std::vector<std::pair<int, int>> points{{2,1}};
    const std::vector<int64_t> left_to_right_sums = GetPrefixHeightSums(points.begin(), points.end());
    std::vector<int64_t> right_to_left_sums = GetPrefixHeightSums(points.rbegin(), points.rend());
    std::reverse(right_to_left_sums.begin(), right_to_left_sums.end());
    {
      const int start_i = 1;
      const int finish_i = 1;
      assert(GetHeightSum(left_to_right_sums, right_to_left_sums, start_i, finish_i) == 0);
    }
  }
  {
    const std::vector<std::pair<int, int>> points{{2,1},{3,10}};
    const std::vector<int64_t> left_to_right_sums = GetPrefixHeightSums(points.begin(), points.end());
    std::vector<int64_t> right_to_left_sums = GetPrefixHeightSums(points.rbegin(), points.rend());
    std::reverse(right_to_left_sums.begin(), right_to_left_sums.end());
    {
      const int start_i = 1;
      const int finish_i = 1;
      assert(GetHeightSum(left_to_right_sums, right_to_left_sums, start_i, finish_i) == 0);
    }
    {
      const int start_i = 1;
      const int finish_i = 2;
      assert(GetHeightSum(left_to_right_sums, right_to_left_sums, start_i, finish_i) == 9);
    }
    {
      const int start_i = 2;
      const int finish_i = 2;
      assert(GetHeightSum(left_to_right_sums, right_to_left_sums, start_i, finish_i) == 0);
    }
    {
      const int start_i = 2;
      const int finish_i = 1;
      assert(GetHeightSum(left_to_right_sums, right_to_left_sums, start_i, finish_i) == 0);
    }
  }
}

int main() {
//  TestGetHeightSum();

  int points_n = 0;
  std::cin >> points_n;
  std::vector<std::pair<int, int>> points(points_n);
  for (int i = 0; i < points_n; ++i) {
    std::cin >> points[i].first >> points[i].second;
  }

  std::vector<int64_t> left_to_right_sums = GetPrefixHeightSums(points.begin(), points.end());
  std::vector<int64_t> right_to_left_sums = GetPrefixHeightSums(points.rbegin(), points.rend());
  std::reverse(right_to_left_sums.begin(), right_to_left_sums.end());

  int routes_n = 0;
  std::cin >> routes_n;
  for (int i = 0; i < routes_n; ++i) {
    int start_i, finish_i;
    std::cin >> start_i >> finish_i;
    std::cout << GetHeightSum(left_to_right_sums, right_to_left_sums, start_i, finish_i) << std::endl;
  }

  return 0;
}
