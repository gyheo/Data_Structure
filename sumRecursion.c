#include <stdio.h>
#include <stdlib.h>

int recur(int n);
void main(void){
	int result = recur(10);
	
	// int result = recur(1000000);
	/*
		위의 경우 백만번 호출..
		stack 영역이 무진장 커져서 프로세스가 다른 메모리를 침범할 가능성이 ↑
		(중요) callback에 대한 제한을 두고 있음
		Segmentation fault (core dumped) 오류 발생
	*/
	printf("The recursion sum is %d \n", result);


}

int recur(int n){
	if(n == 0)
		return 0;
	else
		return n + recur(n-1);
}
