#include <stdio.h>

#define SIZE 5

int sample(int data[], int n);
int sum(int data[], int n);
int search(int data[], int n, int target);

void main(void){
  int data[SIZE] = {1, 4, 55, 66, 77};
  int result = sample(data, SIZE);
  int total = sum(data, SIZE);
  int index = search(data, SIZE, 66);

  printf("The result is %d \n", result);
  printf("The sum is %d \n", total);
  printf("The index is %d \n", index);
}

// n에 관계없이 상수 시간이 소요
// (중요) 이 경우 알고리즘의 시간 복잡도는 O(1)이다

int sample(int data[], int n){
  int k = n / 2;
  return data[k];
}


// 선형 시간 복잡도(linear time complexity)
// O(n)으로 표시
int sum(int data[], int n){
  int sum = 0;
  for(int i = 0; i < n; i++){
    sum += data[i];
  }

  return sum;
}

// 선형 시간복잡도: 순차탐색
// 최악의 경우 시간복잡도는 O(n)
int search(int data[], int n, int target){
  for(int i=0; i<n; i++){
  	if(data[i] == target){
		    return i;
	  }
  }

  return -1;
}
