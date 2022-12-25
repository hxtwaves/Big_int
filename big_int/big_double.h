#pragma once

#include "big_int.h"

class BigDouble {
private:
  BigInt Numerator;
  BigInt Denominator;
  bool is_negative;

  void Reduce();

public:
  BigDouble() {}
  BigDouble(const BigInt &, const BigInt &);
  BigDouble(const char *, const char *);
  BigDouble(const long long, const long long);
  BigDouble(const BigDouble &);

  BigDouble &operator=(const BigDouble &);

  BigDouble &operator+=(const BigDouble &);
  BigDouble &operator-=(const BigDouble &);
  BigDouble &operator*=(const BigDouble &);
  BigDouble &operator/=(const BigDouble &);

  BigDouble &operator++();
  BigDouble operator++(int);
  BigDouble &operator--();
  BigDouble operator--(int);

  friend BigDouble operator+(const BigDouble &, const BigDouble &);
  friend BigDouble operator-(const BigDouble &, const BigDouble &);
  friend BigDouble operator*(const BigDouble &, const BigDouble &);
  friend BigDouble operator/(const BigDouble &, const BigDouble &);

  bool operator==(const BigDouble &) const;
  bool operator!=(const BigDouble &) const;
  bool operator<(const BigDouble &) const;
  bool operator>(const BigDouble &) const;
  bool operator<=(const BigDouble &) const;
  bool operator>=(const BigDouble &) const;

  friend BigDouble Abs(const BigDouble &);
  friend BigDouble Sum(BigDouble &, const BigDouble &);
  friend BigDouble Sub(BigDouble &, const BigDouble &);

  void Print();
};
