#include "stdio.h"

int div(signed int x, signed int y){
	return x/y;
}

void main(){
	int x= 2;
	int y = 3;
	int i = 2;
	int n = i+++i+++i++;
	printf("%d", x+y);
	printf("%d", x-y);
	printf("%d", x*y);
	printf("%d\n", x/y);
	printf("%d", div(-10,3));
	printf("%d", i++);
	printf("%d", ++i);
	printf("%d", i--);
	printf("%d\n", --i);
	printf("%d", n);


	

}