#include <iostream>
#include <stdexcept>
using namespace std;

int Largest(int a, int b, int c) {
  int d = 0;
  if (a > b) {
    d = a;
  }
  else {
    d = b;
  }
  if (d > c) {
  }
  else {
    d = c;
  }
  return d;
}

bool SumIsEven(int a, int b) {
  int i = (a + b) % 2;
  if (i == 1 || i == -1) {
    return false;
  }
  else {
    return true;
  }
}

int BoxesNeeded(int apples) {
  int i = apples % 20;
  if (apples < 0) {
    return 0;
  }
  if (i > 0) {
    return 1 + (apples / 20);
  }
  else {
    return apples / 20;
  }
}

bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total) {
  double a = A_correct * 1.0 / A_total;
  double b = B_correct * 1.0 / B_total;
    if (A_correct < 0 || A_total < 0 || B_correct < 0 || B_total < 0) {
      throw invalid_argument("Invalid inputs");
    }
    else if (A_correct > A_total || B_correct > B_total) {
      throw invalid_argument("Correct scores are larger than total");
    }
  return (a > b ? 1 : 0);
}

bool GoodDinner(int pizzas, bool is_weekend) {
  bool truthValue = false;
  if (pizzas >= 10 && pizzas <= 20) {
    truthValue = true;
  }
  if (is_weekend && pizzas >= 10) {
    truthValue = true;
  }
  return truthValue;
}

int SumBetween(int low, int high) {
  int value = 0;
  if (low > high) {
    throw invalid_argument("Low integer greater than high");
  }
  if (low == high) {
    return low;
  }

  if (low < 0 && high > 0) {
    if (low * -1 > high) {
      high += low;
    }
    else if (low * -1 == high) {
      return 0;
    }
    else {
      low += high;
    }
  }

  for (int n = low; n <= high; n++) {
    if (n < 0) {
      if (value < INT32_MIN - n) {
        throw overflow_error("The sumation is too large");
      }
    }
    else if (n >= 0) {
      if (value > INT32_MAX - n) {
        throw overflow_error("The sumation is too large");
      }
    }
    value += n;
  }
  return value;


}

int Product(int a, int b) {
  int product;
  bool neg = false;
  if ((b < 0 && a < 0) || (b > 0 && a > 0)) {
    if (b < 0 && a < 0) {
      a *= -1;
      b *= -1;
    }
    if (a > INT32_MAX / b) {
      throw overflow_error("The product is too large");
    }
  }
  else {
    if (b == -1) {
      neg = true;
      b = 1;
    }
    if (a < INT32_MIN / b) {
      throw overflow_error("The product is too large");
    }
  }

  product = a * b;

  return neg ? -1 * product : product;
}