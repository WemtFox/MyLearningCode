#include "stdio.h"

int __fastcall fun(){
	double d = 2.2;
	return (int)d;
}

int main(){

	int n = fun();
	printf("%d\n",n);
}