#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

inline const double T_MIN = 30.0;
inline const double T_MAX = 4000.0;
inline const double EPSILON = 10e-6;

struct Call {
  double freq = 0;
  bool is_closer = false;
};

using Range = std::pair<double, double>;

Range GetRangeAfterTwoCalls(const Call& call_a, const Call& call_b, const Range& initial_range) {
  double mid_freq = (call_a.freq + call_b.freq) / 2.0;
  if (call_b.is_closer) {
    if (call_a.freq < call_b.freq)
      return {std::max(mid_freq, initial_range.first), initial_range.second};
    else
      return {initial_range.first, std::min(mid_freq, initial_range.second)};
  } else { // call_b is further
    if (call_a.freq < call_b.freq)
      return {initial_range.first, std::min(mid_freq, initial_range.second)};
    else
      return {std::max(mid_freq, initial_range.first), initial_range.second};
  }
}

Range GetMinRange(const std::vector<Call>& calls) {
  Range range{T_MIN, T_MAX};
  for (size_t i = 1; i < calls.size(); ++i) {
    range = GetRangeAfterTwoCalls(calls[i-1], calls[i], range);
  }

  return range;
}

void TestGetRangeAfterTwoCalls() {
  {
    const Call call_a{100, false};
    const Call call_b{500, true};
    const Range initial_range{T_MIN, T_MAX};
    const Range expected_range{300, T_MAX};
    const Range actual_range = GetRangeAfterTwoCalls(call_a, call_b, initial_range);
    assert(actual_range == expected_range);
  }
  {
    const Call call_a{100, false};
    const Call call_b{500, false};
    const Range initial_range{T_MIN, T_MAX};
    const Range expected_range{T_MIN, 300};
    const Range actual_range = GetRangeAfterTwoCalls(call_a, call_b, initial_range);
    assert(actual_range == expected_range);
  }
}

int main() {
  TestGetRangeAfterTwoCalls();

  uint16_t n_calls = 0;
  std::cin >> n_calls;

  std::vector<Call> calls(n_calls);
  std::string is_closer_str;
  for (uint16_t i = 0; i < n_calls; ++i) {
    if (i == 0) {
      std::cin >> calls[i].freq;
      continue;
    }
    std::cin >> calls[i].freq >> is_closer_str;
    calls[i].is_closer = (is_closer_str == "closer");
  }

  auto min_range = GetMinRange(calls);

  std::cout << std::setprecision(6) << std::fixed << min_range.first << ' ' << min_range.second << std::endl;

  return 0;
}
