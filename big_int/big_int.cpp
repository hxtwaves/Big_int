#include "big_int.h"
#include <vector>

BigInt::BigInt(std::string &str) {
  digits = "";
  int offset = 0;
  int size = str.size();
  if (size == 0)
    throw("Null input");
  if (str[0] == '-') {
    is_negative = true;
    offset = 1;
  } else
    is_negative = false;

  for (int i = size - 1; i >= offset; i--) {
    if (!isdigit(str[i]))
      throw("ERROR");
    digits.push_back(str[i] - '0');
  }
}

BigInt::BigInt(long long num) {
  if (num < 0)
    is_negative = true;
  num = abs(num);
  do {
    digits.push_back(num % 10);
    num /= 10;
  } while (num);
}

BigInt::BigInt(const char *s) {
  digits = "";
  int offset = 0;
  int size = strlen(s);
  if (size == 0)
    throw("Null input");
  if (s[0] == '-') {
    is_negative = true;
    offset = 1;
  } else
    is_negative = false;
  for (int i = strlen(s) - 1; i >= offset; i--) {
    if (!isdigit(s[i]))
      throw("ERROR");
    digits.push_back(s[i] - '0');
  }
}

BigInt::BigInt(BigInt &other) {
  digits = other.digits;
  is_negative = other.is_negative;
}

BigInt Abs(const BigInt &other) {
  BigInt temp;
  temp.digits = other.digits;
  temp.is_negative = false;
  return temp;
}

BigInt Sum(BigInt &a, const BigInt &b) {
  int t = 0;
  int s;
  int n = Length(a);
  int m = Length(b);
  if (m > n)
    a.digits.append(m - n, 0);
  n = Length(a);
  for (int i = 0; i < n; i++) {
    if (i < m)
      s = (a.digits[i] + b.digits[i]) + t;
    else
      s = a.digits[i] + t;
    t = s / 10;
    a.digits[i] = (s % 10);
  }
  if (t)
    a.digits.push_back(t);
  return a;
}

BigInt Sub(BigInt &a, const BigInt &b) {
  if (a < b)
    throw("Error: first num < second num");
  int n = Length(a);
  int m = Length(b);
  int t = 0;
  int s;
  for (int i = 0; i < n; i++) {
    if (i < m)
      s = a.digits[i] - b.digits[i] + t;
    else
      s = a.digits[i] + t;
    if (s < 0) {
      s += 10;
      t = -1;
    } else
      t = 0;
    a.digits[i] = s;
  }
  while (n > 1 && a.digits[n - 1] == 0)
    a.digits.pop_back(), n--;
  return a;
}

bool Null(const BigInt &num) {
  if (num.digits.size() == 1 && num.digits[0] == 0)
    return true;
  return false;
}

int Length(const BigInt &num) { return num.digits.size(); }

int BigInt::operator[](const int index) const {
  if (digits.size() <= index || index < 0)
    throw("ERROR");
  return digits[index];
}

bool operator==(const BigInt &a, const BigInt &b) {
  return (a.digits == b.digits) && (a.is_negative == b.is_negative);
}

bool operator!=(const BigInt &a, const BigInt &b) { return !(a == b); }

bool operator<(const BigInt &a, const BigInt &b) {
  int n = Length(a);
  int m = Length(b);

  if (!a.is_negative && b.is_negative)
    return false;
  if (a.is_negative && !b.is_negative)
    return true;

  if (n != m) {
    if (a.is_negative && b.is_negative)
      return !(n < m);
    return n < m;
  }
  while (n--)
    if (a.digits[n] != b.digits[n]) {
      if (a.is_negative && b.is_negative)
        return !(a.digits[n] < b.digits[n]);
      return a.digits[n] < b.digits[n];
    }
  return false;
}

bool operator>(const BigInt &a, const BigInt &b) { return b < a; }

bool operator>=(const BigInt &a, const BigInt &b) { return !(a < b); }

bool operator<=(const BigInt &a, const BigInt &b) { return !(b < a); }

BigInt &BigInt::operator=(const BigInt &a) {
  digits = a.digits;
  is_negative = a.is_negative;
  return *this;
}

BigInt &operator+=(BigInt &a, const BigInt &b) {
  if (a.is_negative != b.is_negative) {
    BigInt a_abs = Abs(a);
    BigInt b_abs = Abs(b);
    bool is_negative = false;
    if (a_abs > b_abs) {
      if (a.is_negative)
        is_negative = true;
      else
        is_negative = false;
      a = Sub(a_abs, b_abs);
    } else {
      if (b.is_negative)
        is_negative = true;
      else
        is_negative = false;
      a = Sub(b_abs, a_abs);
    }
    a.is_negative = is_negative;
    return a;
  }
  a = Sum(a, b);
  return a;
}

BigInt operator+(const BigInt &a, const BigInt &b) {
  BigInt temp;
  temp = a;
  temp.is_negative = a.is_negative;
  temp += b;
  return temp;
}

BigInt &operator-=(BigInt &a, const BigInt &b) {
  if (a.is_negative && !b.is_negative) {
    a = Sum(a, b);
    a.is_negative = true;
    return a;
  }
  BigInt a_abs = Abs(a);
  BigInt b_abs = Abs(b);
  if (a.is_negative && b.is_negative) {
    if (a_abs > b_abs) {
      a = Sub(a_abs, b_abs);
      a.is_negative = true;
      return a;
    } else {
      a = Sub(b_abs, a_abs);
      a.is_negative = false;
      return a;
    }
  }
  if (!a.is_negative && b.is_negative) {
    a = Sum(a_abs, b_abs);
    a.is_negative = false;
    return a;
  }
  if (a_abs < b_abs) {
    a = Sub(b_abs, a_abs);
    a.is_negative = true;
    return a;
  }
  a = Sub(a, b);
  a.is_negative = false;
  return a;
}

BigInt operator-(const BigInt &a, const BigInt &b) {
  BigInt temp;
  temp = a;
  temp -= b;
  return temp;
}

BigInt &operator*=(BigInt &a, const BigInt &b) {
  if (Null(a) || Null(b)) {
    a = BigInt();
    return a;
  }
  if (a.is_negative != b.is_negative)
    a.is_negative = true;
  if (!a.is_negative && !b.is_negative)
    a.is_negative = false;
  int n = a.digits.size(), m = b.digits.size();
  std::vector<int> v(n + m, 0);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      v[i + j] += (a.digits[i]) * (b.digits[j]);
    }
  n += m;
  a.digits.resize(v.size());
  for (int s, i = 0, t = 0; i < n; i++) {
    s = t + v[i];
    v[i] = s % 10;
    t = s / 10;
    a.digits[i] = v[i];
  }
  for (int i = n - 1; i >= 1 && !v[i]; i--)
    a.digits.pop_back();
  return a;
}

BigInt operator*(const BigInt &a, const BigInt &b) {
  BigInt temp;
  temp = a;
  temp *= b;
  return temp;
}

BigInt &operator/=(BigInt &a, const BigInt &b) {
  if (Null(b))
    throw("Arithmetic Error: Division By 0");

  if (a.is_negative != b.is_negative)
    a.is_negative = true;
  else if (a.is_negative && b.is_negative)
    a.is_negative = false;

  if (Abs(a) < Abs(b)) {
    a = BigInt();
    return a;
  }
  if (a == b) {
    a = BigInt(1);
    return a;
  }

  int i;
  int lgcat = 0;
  int cc;
  int n = Length(a);
  int m = Length(b);
  std::vector<int> cat(n, 0);
  BigInt t;
  for (i = n - 1; t * 10 + a.digits[i] < Abs(b); i--) {
    t *= 10;
    t += a.digits[i];
  }
  for (; i >= 0; i--) {
    t = t * 10 + a.digits[i];
    for (cc = 9; cc * Abs(b) > Abs(t); cc--)
      ;
    t -= cc * b;
    cat[lgcat++] = cc;
  }
  a.digits.resize(cat.size());
  for (i = 0; i < lgcat; i++)
    a.digits[i] = cat[lgcat - i - 1];
  a.digits.resize(lgcat);
  return a;
}

BigInt operator/(const BigInt &a, const BigInt &b) {
  BigInt temp;
  temp = a;
  temp /= b;
  return temp;
}

BigInt &operator%=(BigInt &a, const BigInt &b) {
  if (Null(b))
    throw("Arithmetic Error: Division By 0");
  if (a < b) {
    return a;
  }
  if (a == b) {
    a = BigInt();
    return a;
  }
  int i, lgcat = 0, cc;
  int n = Length(a), m = Length(b);
  std::vector<int> cat(n, 0);
  BigInt t;
  for (i = n - 1; t * 10 + a.digits[i] < b; i--) {
    t *= 10;
    t += a.digits[i];
  }
  for (; i >= 0; i--) {
    t = t * 10 + a.digits[i];
    for (cc = 9; cc * b > t; cc--)
      ;
    t -= cc * b;
    cat[lgcat++] = cc;
  }
  a = t;
  return a;
}

BigInt operator%(const BigInt &a, const BigInt &b) {
  BigInt temp;
  temp = a;
  temp %= b;
  return temp;
}

BigInt &BigInt::operator++() {
  *this += 1;
  return *this;
}

BigInt BigInt::operator++(int other) {
  BigInt temp;
  temp = *this;
  ++(*this);
  return temp;
}

BigInt &BigInt::operator--() {
  *this -= 1;
  return *this;
}

BigInt BigInt::operator--(int other) {
  BigInt temp;
  temp = *this;
  --(*this);
  return temp;
}

std::ostream &operator<<(std::ostream &out, const BigInt &a) {
  if (a.is_negative && !Null(a))
    std::cout << '-';
  for (int i = a.digits.size() - 1; i >= 0; i--)
    std::cout << (short)a.digits[i];
  return std::cout;
}
