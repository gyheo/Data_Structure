#include <stdio.h>

int main(void)
{
    int sum, i, average;
    int num[10];
    for(i=0; i<10; i++){
      scanf("%d", &num[i]);
    }
    sum = calculate_sum(num);
    average = sum / 10;
    printf("%d \n", average);

    return 0;
}

int calculate_sum(int *array){
    int sum, i;
    sum = 0;
    for(i=0; i<10; i++){
      // sum += array[i];
      sum = sum + *(array + i);
    }

    return sum;
}
