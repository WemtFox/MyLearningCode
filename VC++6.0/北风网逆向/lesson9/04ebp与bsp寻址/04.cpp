#include "stdio.h"

int fun(int x, int y){
	int z;
	scanf("%d",&z);
	return x+y+z;
}

int main(){

	int n = fun(3,5);
	printf("%d\n",n);
}