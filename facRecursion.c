#include <stdio.h>
#include <stdlib.h>

int factorial(int n);
void main(void){
  int *result = NULL;
  result = (int *)malloc(sizeof(int));

  // *result = factorial(5);
  *result = factorial(10000000);
  /* 이런 경우에도 OS 자체에서 stack 영역에 대해 오류 발생 */
  printf("factorial(5) result is %d \n", *result);
}

int factorial(int n){
  if(n == 0)
    return 1;
  else
    return n * factorial(n-1);
}
