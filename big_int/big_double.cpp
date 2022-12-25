#include "big_double.h"
#include "big_int.h"
#include <iostream>
#include <string>

void BigDouble::Reduce() {
  BigInt lim("1000000");
  if (Numerator > lim || Denominator > lim)
    return;

  BigInt min = Numerator;
  BigInt zero("0");
  if (Denominator < Numerator)
    min = Denominator;

  for (BigInt i = 2; i < min; i++)
    while (Numerator % i == zero && Denominator % i == zero) {
      Numerator /= i;
      Denominator /= i;
    }
}

BigDouble Abs(const BigDouble &other) {
  BigDouble temp(other);
  temp.is_negative = false;
  return temp;
}

BigDouble Sum(BigDouble& first, const BigDouble &second) {
  first.Numerator = first.Numerator * second.Denominator + second.Numerator * first.Denominator;
  first.Denominator *= second.Denominator;
  first.Reduce();
  return first;
}

BigDouble Sub(BigDouble& first, const BigDouble &second) {
  first.Numerator = first.Numerator * second.Denominator - second.Numerator * first.Denominator;
  first.Denominator *= second.Denominator;
  first.Reduce();
  return first;
}

BigDouble::BigDouble(const BigInt &numerator, const BigInt &denominator) {
  Numerator = Abs(numerator);
  Denominator = Abs(denominator);

  if (numerator.is_negative != denominator.is_negative)
    is_negative = true;
  else
    is_negative = false;
}

BigDouble::BigDouble(const char *numerator, const char *denominator) {
  BigInt big_int_numerator(numerator);
  BigInt big_int_denominator(denominator);
  Numerator = Abs(big_int_numerator);
  Denominator = Abs(big_int_denominator);

  if (big_int_numerator.is_negative != big_int_denominator.is_negative)
    is_negative = true;
  else
    is_negative = false;
}

BigDouble::BigDouble(const long long numerator, const long long denominator) {
  BigInt big_int_numerator(numerator);
  BigInt big_int_denominator(denominator);
  Numerator = big_int_numerator;
  Denominator = big_int_denominator;
  Numerator.is_negative = false;
  Denominator.is_negative = false;

  if (big_int_numerator.is_negative != big_int_denominator.is_negative)
    is_negative = true;
  else
    is_negative = false;
}

BigDouble::BigDouble(const BigDouble &other) {
  Numerator = other.Numerator;
  Denominator = other.Denominator;
  is_negative = other.is_negative;
}

BigDouble &BigDouble::operator=(const BigDouble &other) {
  Numerator = other.Numerator;
  Denominator = other.Denominator;
  is_negative = other.is_negative;
  return *this;
}

BigDouble &BigDouble::operator+=(const BigDouble &other) {
  if (is_negative != other.is_negative) {
    BigDouble this_abs = Abs(*this);
    BigDouble other_abs = Abs(other);
    bool negative = false;
    if (this_abs > other_abs) {
      negative = is_negative;
      *this = Sub(this_abs, other_abs);
    } else {
      negative = other.is_negative;
      *this = Sub(other_abs, this_abs);
    }
    is_negative = negative;
    return *this;
  }
  *this = Sum(*this, other);
  if (is_negative && other.is_negative)
    is_negative = true;
  return *this;
}

BigDouble operator+(const BigDouble &first, const BigDouble &second) {
  BigDouble temp;
  temp = first;
  temp += second;
  return temp;
}

BigDouble &BigDouble::operator-=(const BigDouble &other) {
  if (is_negative && !other.is_negative) {
    *this = Sum(*this, other);
    is_negative = true;
    return *this;
  }
  BigDouble this_abs = Abs(*this);
  BigDouble other_abs = Abs(other);
  if (is_negative && other.is_negative){
    if (this_abs > other_abs) {
      *this = Sub(this_abs, other_abs);
      is_negative = true;
      return *this;
    } else {
      *this = Sub(other_abs, this_abs);
      is_negative = false;
      return *this;
    }
  }
  if (!is_negative && other.is_negative) {
    *this = Sum(this_abs, other_abs);
    is_negative = false;
    return *this;
  }
  if (this_abs < other_abs) {
    *this = Sub(other_abs, this_abs);
    is_negative = true;
    return *this;
  }
  *this = Sub(*this, other);
  is_negative = false;
  return *this;
}

BigDouble operator-(const BigDouble &first, const BigDouble &second) {
  BigDouble temp;
  temp = first;
  temp -= second;
  return temp;
}

BigDouble &BigDouble::operator*=(const BigDouble &other) {
  if (is_negative != other.is_negative)
    is_negative = true;
  else
    is_negative = false;
  Numerator *= other.Numerator;
  Denominator *= other.Denominator;
  Reduce();
  return *this;
}

BigDouble operator*(const BigDouble &first, const BigDouble &second) {
  BigDouble temp;
  temp = first;
  temp *= second;
  return temp;
}

BigDouble &BigDouble::operator/=(const BigDouble &other) {
  if (is_negative != other.is_negative)
    is_negative = true;
  else
    is_negative = false;
  Numerator *= other.Denominator;
  Denominator *= other.Numerator;
  Reduce();
  return *this;
}

BigDouble operator/(const BigDouble &first, const BigDouble &second) {
  BigDouble temp;
  temp = first;
  temp /= second;
  return temp;
}

BigDouble &BigDouble::operator++() {
  Numerator += Denominator;
  Reduce();
  return *this;
}

BigDouble BigDouble::operator++(int other) {
  BigDouble temp;
  temp = *this;
  ++(*this);
  return temp;
}

BigDouble &BigDouble::operator--() {
  Numerator -= Denominator;
  return *this;
}

BigDouble BigDouble::operator--(int other) {
  BigDouble temp;
  temp = *this;
  --(*this);
  return temp;
}

bool BigDouble::operator==(const BigDouble &other) const {
  if (Numerator == other.Numerator && Denominator == other.Denominator &&
      is_negative == other.is_negative)
    return true;
  return false;
}

bool BigDouble::operator!=(const BigDouble &other) const {
  return !(*this == other);
}

bool BigDouble::operator<(const BigDouble &other) const {
  if (is_negative != other.is_negative)
    if (is_negative)
      return true;
    else 
      return false;

  bool result = false;
  if (Numerator * other.Denominator < Denominator * other.Numerator)
    result = true;
  else 
    result = false;

  if (is_negative && other.is_negative)
    result = !result;

  return result;
}

bool BigDouble::operator>(const BigDouble &other) const {
  return other < *this;
}

bool BigDouble::operator<=(const BigDouble &other) const {
  return !(other < *this);
}

bool BigDouble::operator>=(const BigDouble &other) const {
  return !(*this < other);
}

void BigDouble::Print() {
  int offset = 0;
  std::string minus = "";
  if (is_negative){
    minus = "- ";
    offset = 2;
  }
  std::string shift(offset, ' ');
  int numerator_offset = 0;
  int denominator_offset = 0;
  int lines_count = 0;
  if (Numerator < Denominator) {
    numerator_offset = abs(Numerator.digits.size() - Denominator.digits.size()) / 2;
    lines_count = Denominator.digits.size();
  } else {
    denominator_offset =
        abs(Numerator.digits.size() - Denominator.digits.size()) / 2;
    lines_count = Numerator.digits.size();
  }
  Numerator.is_negative = false;
  Denominator.is_negative = false;
  std::string lines(lines_count, '-');
  std::string num_offset(numerator_offset, ' ');
  std::string denom_offset(denominator_offset, ' ');
  std::cout << shift << num_offset << Numerator << std::endl;
  std::cout << minus << lines << std::endl;
  std::cout << shift << denom_offset << Denominator << std::endl;
}
