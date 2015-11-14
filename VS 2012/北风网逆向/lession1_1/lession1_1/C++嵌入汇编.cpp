#include "stdio.h"

int main(){

	int a = 1;
	int b = 2;
	int c = 0;

	__asm{
		mov eax,a
		mov ebx,b
		add eax,ebx
		mov c,eax
	}

	printf("a + b = %d\n", c);

	return 0;
}