#include "stdio.h"

int main(){
	int n;
	float f;

	n = 3;
	f = (float)n;
	printf("f = %f\n", f);

	f = 10.75;
	n = (int)f;

	printf("n = %d\n", n);
	return 0;
}