#include <stdio.h>
#include <stdlib.h>

int POW(int x, int n);

void main(void){
  int *power = NULL;
  power = (int *)malloc(sizeof(int));

  *power = POW(3, 5);

  printf("3의 5제곱은 %d \n", *power);
}

int POW(int x, int n){
  if(n == 0){
    return 1;
  }

  else{
    return x * POW(x, n-1);
  }
}
