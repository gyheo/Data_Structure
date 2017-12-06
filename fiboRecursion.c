#include <stdio.h>
#include <stdlib.h>

int fibo(int n);

void main(void){
  int *result = NULL;
  result = (int *)malloc(sizeof(int));

  *result = fibo(10);

  printf("피보나치 수열 : %d \n", *result);
  
}
int fibo(int n){
  if(n == 1 || n == 2){
    return 1;
  }

  else{
    return fibo(n-1) + fibo(n-2);
  }
}
