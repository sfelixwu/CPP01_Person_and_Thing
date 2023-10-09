
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
  int x = 555;
  int *int_ptr = &x;

  printf("x = %d\n", x);
  printf("address of x = %p\n", &x);
  printf("value of int_ptr = %p\n", int_ptr);
  printf("value of dereferencing int_ptr = %d\n", *int_ptr);
  *int_ptr = 777;
  printf("x = %d\n", x);
  
  return 0;
}
