#include <iostream>

bool f(bool x, bool y, bool z) {
  bool value = false; 
  // write your code to compute f(x,y,z) here
  if ((x && y && z) || (!x && y && !z) || (!x && !y && z)) {
    value = true;
  }
  else {
    value = false;
  }
  return value;
}