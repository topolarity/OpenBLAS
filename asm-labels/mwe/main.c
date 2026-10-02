#include <stdio.h>
int f(void), g(void);
int main(void) {
  printf("f() = %d\n", f());
  printf("g() = %d\n", g());
  return 0;
}
