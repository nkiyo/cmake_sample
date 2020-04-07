#include "MyClass.h"
#include <stdio.h>

void MyClass::setX(int x, int* y) {
  printf("hoge\n");
  x_ = x;
  *y = x;
}

int MyClass::myFunc(int n) {
  printf("%d\n", n);
  return n;
}
