#include "stdio.h"
#include "util/MyClass.h"

int main() {
  MyClass mc;
  if (true) {
    printf("### %d\n", mc.myFunc(1));
  }
}
