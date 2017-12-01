#include <stdio.h>
#include <stdlib.h>

int recur(int n);
void main(void){
	int result = recur(10);

	printf("The recursion sum is %d \n", result);


}

int recur(int n){
	if(n == 0)
		return 0;
	else
		return n + recur(n-1);
}
