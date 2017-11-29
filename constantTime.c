#include <stdio.h>

#define SIZE 5

int sample(int data[], int n);

void main(void){
  int data[SIZE] = {1, 4, 55, 66, 77};
  int result = sample(data, SIZE);

  printf("The result is %d \n", result);

}

// n에 관계없이 상수 시간이 소요
// (중요) 이 경우 알고리즘의 시간 복잡도는 O(1)표시

int sample(int data[], int n){
  int k = n / 2;
  return data[k];
}
