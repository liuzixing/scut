#include <stdio.h>
#include <math.h>

int main()
{
  int n = 50000, i, j;

  printf("%d\n", n);
  for (i = 0; i < n; i++) {
    j = rand() % 3;
    if (!j) 
      printf("pick %d\n", rand()&0x3ffffff);
    else if (j==1) 
     printf("eat\n");
    else
     printf("throw\n");
  }

  return 0;
}

