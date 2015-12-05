#include "stdio.h"

int main(){

	int array[] = {32, 43, 432, 3};
	int *p = array;
	int n = 3;
	printf("%d\n",array[n]);
	printf("%d\n",p[3]);
	printf("%d\n",*(p+3));
	return 0;
}