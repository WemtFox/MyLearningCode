#include "stdio.h"

int main(){
	int x = 3;

	int &y = x;
	
	int *z = &x;

	*z = 6;

	y = 5;

	printf("%d\n", x);
}