#include <stdio.h>
#include "fibonacci_no_recursion.h"
#include "fibonacci_recursion.h"

int main() {
  int N = 10;
  for (int i = 0; i < N; ++i)
  {
    printf("%d ", fibonacci_no_recursion(i));
  }

  printf("\n");

  for (int i = 0; i < N; ++i)
  {
    printf("%d ", fibonacci_recursion(i));
  }
}