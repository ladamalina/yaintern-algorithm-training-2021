#include <cassert>
#include <iostream>

const std::string T_MODE_FREEZE = "freeze";
const std::string T_MODE_HEAT   = "heat";
const std::string T_MODE_AUTO   = "auto";
const std::string T_MODE_FAN    = "fan";

int TargetTemperature(const int t_room, const int t_cond, const std::string& t_mode) {
  if (t_mode == T_MODE_FREEZE) {
    return std::min(t_room, t_cond);
  } else if (t_mode == T_MODE_HEAT) {
    return std::max(t_room, t_cond);
  } else if (t_mode == T_MODE_AUTO) {
    return t_cond;
  } // t_mode == T_MODE_FAN
  return t_room;
}

void TestTargetTemperature() {
  assert(TargetTemperature(10, 20, T_MODE_FREEZE) == 10);
  assert(TargetTemperature(10, 10, T_MODE_FREEZE) == 10);
  assert(TargetTemperature(20, 10, T_MODE_FREEZE) == 10);

  assert(TargetTemperature(10, 20, T_MODE_HEAT) == 20);
  assert(TargetTemperature(10, 10, T_MODE_HEAT) == 10);
  assert(TargetTemperature(20, 10, T_MODE_HEAT) == 20);

  assert(TargetTemperature(10, 20, T_MODE_AUTO) == 20);
  assert(TargetTemperature(10, 10, T_MODE_AUTO) == 10);
  assert(TargetTemperature(20, 10, T_MODE_AUTO) == 10);

  assert(TargetTemperature(10, 20, T_MODE_FAN) == 10);
  assert(TargetTemperature(10, 10, T_MODE_FAN) == 10);
  assert(TargetTemperature(20, 10, T_MODE_FAN) == 20);
}

int main() {
  // TestTargetTemperature();

  int t_room, t_cond;
  std::cin >> t_room >> t_cond;
  std::string t_mode;
  std::cin >> t_mode;

  std::cout << TargetTemperature(t_room, t_cond, t_mode) << std::endl;

  return 0;
}
