#include <stdio.h>

#define SIZE 5

int sample(int data[], int n);

void main(void){
  int data[SIZE] = {1, 4, 55, 66, 77};
  int result = sample(data, SIZE);

  printf("The result is %d \n", result);

}

int sample(int data[], int n){
  int k = n / 2;
  return data[k];
}
