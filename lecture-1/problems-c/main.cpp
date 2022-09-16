#include <cassert>
#include <iostream>

struct PhoneNumber {
  explicit PhoneNumber(const std::string& input) {
    // std::cerr << "Input: " << input << std::endl;
    num.reserve(7);
    code.reserve(3);
    for (auto it = input.rbegin(); it != input.rend(); ++it) {
      if ('0' <= *it && *it <= '9') {
        if (num.size() < 7) {
          num += *it;
          continue;
        }
        if (code.size() < 3) {
          code += *it;
        }
      }
    }
    std::reverse(num.begin(), num.end());
    if (code.empty()) {
      code = "495";
    } else {
      std::reverse(code.begin(), code.end());
    }
    // std::cerr << "code = " << code << ", num = " << num << std::endl;
  }
  std::string code;
  std::string num;
};

bool operator== (const PhoneNumber& lhs, const PhoneNumber& rhs) {
  return lhs.num == rhs.num && lhs.code == rhs.code;
}

bool operator!= (const PhoneNumber& lhs, const PhoneNumber& rhs) {
  return !(lhs == rhs);
}

void TestComparePhoneNumbers() {
  assert(PhoneNumber{"8(495)430-23-97"} == PhoneNumber{"+7-4-9-5-43-023-97"});
  assert(PhoneNumber{"8(495)430-23-97"} == PhoneNumber{"4-3-0-2-3-9-7"});
  assert(PhoneNumber{"8(495)430-23-97"} != PhoneNumber{"8-495-430"});

  assert(PhoneNumber{"86406361642"} != PhoneNumber{"83341994118"});
  assert(PhoneNumber{"86406361642"} == PhoneNumber{"86406361642"});
  assert(PhoneNumber{"86406361642"} != PhoneNumber{"83341994118"});

  assert(PhoneNumber{"+78047952807"} == PhoneNumber{"+78047952807"});
  assert(PhoneNumber{"+78047952807"} != PhoneNumber{"+76147514928"});
  assert(PhoneNumber{"+78047952807"} == PhoneNumber{"88047952807"});
}

int main() {
  // TestComparePhoneNumbers();

  std::string phone_new, phone1, phone2, phone3;
  std::cin >> phone_new >> phone1 >> phone2 >> phone3;

  std::cout << (PhoneNumber{phone_new} == PhoneNumber{phone1} ? "YES" : "NO") << std::endl;
  std::cout << (PhoneNumber{phone_new} == PhoneNumber{phone2} ? "YES" : "NO") << std::endl;
  std::cout << (PhoneNumber{phone_new} == PhoneNumber{phone3} ? "YES" : "NO") << std::endl;

  return 0;
}
