#include <cstring>
#include <iostream>
#include <string>
#include <vector>

class BigInt {
  std::string digits;
  bool is_negative = false;

public:
  BigInt(long long num = 0);
  BigInt(std::string &);
  BigInt(const char *);
  BigInt(BigInt &);

  friend BigInt Abs(const BigInt &);
  friend BigInt Sum(BigInt &, const BigInt &);
  friend BigInt Sub(BigInt &, const BigInt &);
  friend bool Null(const BigInt &);
  friend int Length(const BigInt &);

  int operator[](const int) const;

  BigInt &operator=(const BigInt &);

  friend BigInt &operator+=(BigInt &, const BigInt &);
  friend BigInt operator+(const BigInt &, const BigInt &);
  friend BigInt &operator-=(BigInt &, const BigInt &);
  friend BigInt operator-(const BigInt &, const BigInt &);

  friend bool operator==(const BigInt &, const BigInt &);
  friend bool operator!=(const BigInt &, const BigInt &);

  friend bool operator>(const BigInt &, const BigInt &);
  friend bool operator>=(const BigInt &, const BigInt &);
  friend bool operator<(const BigInt &, const BigInt &);
  friend bool operator<=(const BigInt &, const BigInt &);

  friend BigInt &operator*=(BigInt &, const BigInt &);
  friend BigInt operator*(const BigInt &, const BigInt &);
  friend BigInt &operator/=(BigInt &, const BigInt &);
  friend BigInt operator/(const BigInt &, const BigInt &);

  friend std::ostream &operator<<(std::ostream &, const BigInt &);
};
