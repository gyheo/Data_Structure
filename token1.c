#include <stdio.h>
#include <string.h>

int main(void){
  int i = 0;
  char str[] = "now # is the time # to start preparing ### for the exam#";
  char delim[] = "#";
  char *token;

  token = strtok(str, delim);
  // printf("first token is %s \n", token);
  while(token != NULL){
    printf("next token is : %s:%d\n", token, strlen(token));
    token = strtok(NULL, delim);
    printf("%dst token is %s \n", i+1, token);
    i++;
  }

  return 0;
}
