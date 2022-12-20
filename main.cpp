#include <iostream>
#include "big_int.h"

int main() {
  std::cout << "Example with small numbers" << std::endl;
  BigInt small_negative("-100");
  BigInt small_positive("30");
  std::cout << "a: " << small_negative << std::endl << "b: " << small_positive << std::endl;
  std::cout << "sum: " << small_negative + small_positive << std::endl;
  std::cout << "sub: " << small_negative - small_positive << std::endl;
  std::cout << "mult: " << small_negative * small_positive << std::endl;
  std::cout << "div: " << small_negative / small_positive << std::endl;
  std::cout << "Example with very big numbers" << std::endl;
  BigInt big_positive("9387450293847520938457012938759283467892");
  BigInt big_negative("-239487523049856276345578237840967089252983740398475");
  std::cout << "a: " << big_positive << std::endl << "b: " << big_negative << std::endl;
  std::cout << "sum: " << big_positive + big_negative << std::endl;
  std::cout << "sub: " << big_positive - big_negative << std::endl;
  std::cout << "mult: " << big_positive * big_negative << std::endl;
  std::cout << "div: " << big_positive / big_negative << std::endl;
  return 0;
}
