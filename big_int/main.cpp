#include <iostream>
#include "big_int.h"
#include "big_double.h"

int main() {
  std::cout << "\n" << "~~~~~~~~~~~~~~~~~~~~~~~~~~~ BigInt ~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
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
  std::cout << "\n" << "~~~~~~~~~~~~~~~~~~~~~~~~~~~ BigDouble ~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
  std::cout << "Пример c небольшими числами, чтобы убедиться в правильности вычислений" << std::endl;
  BigDouble small_1("10", "3");
  BigDouble small_2(-30, 7);
  std::cout << "Первое число:" << std::endl;
  small_1.Print();
  std::cout << "Второе число:" << std::endl;
  small_2.Print();
  std::cout << "**************" << std::endl;
  std::cout << "Сумма:" << std::endl;
  (small_1 + small_2).Print();
  std::cout << "Разница:" << std::endl;
  (small_1 - small_2).Print();
  std::cout << "Произведение:" << std::endl;
  (small_1 * small_2).Print();
  std::cout << "Частное" << std::endl;
  (small_1 / small_2).Print();
  std::cout << "Пост-инкремент первого:" << std::endl;
  (small_1++).Print();
  std::cout << "Еще раз первое число, чтобы убедиться, что пост-инкремент работает:" << std::endl;
  small_1.Print();
  std::cout << "Пре-декремент второго:" << std::endl;
  (--small_2).Print();
  std::cout << "a < b: " << (small_1 < small_2) << "\na == b: " << (small_1 == small_2) << "\na > b: " << (small_1 > small_2) << std::endl;
  std::cout << std::endl << "*******************************************" << std::endl << std::endl;
  std::cout << "Пример c большими числами" << std::endl;
  BigDouble big_1("3647895629384", "293804572387946592873465");
  BigDouble big_2("8308476592837465", "-5903486598732465987234");
  std::cout << "Первое число:" << std::endl;
  big_1.Print();
  std::cout << "Второе число:" << std::endl;
  big_2.Print();
  std::cout << "********************************************" << std::endl;
  std::cout << "Сумма:" << std::endl;
  (big_1 + big_2).Print();
  std::cout << "Разница:" << std::endl;
  (big_1 - big_2).Print();
  std::cout << "Произведение:" << std::endl;
  (big_1 * big_2).Print();
  std::cout << "Частное:" << std::endl;
  (big_1 / big_2).Print();
  return 0;
}
