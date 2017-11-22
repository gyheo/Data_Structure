#include <stdio.h>

void main(void){
  int x = 1, y = 2;
  int *ip = NULL;
  char str[] = "hello";
  char str2[4];

  str2[0] = 'C';
  str2[1] = '+';
  str2[2] = '+';
  str2[3] = '\0';

  ip = &x;
  printf("%d \n", *ip);

  y = *ip;

  printf("%d \n", y);
  printf("%s \n", str);
  printf("%s \n", str2);

  return ;
}
