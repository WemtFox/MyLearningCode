#include "stdio.h"

void fun(int n){
	static i = 2;
	i = n;
	printf("%d\n", i);
}

int main(){
	for (int i = 0; i < 10; i++)
	{
		fun(i);
	}
	
	return 0;
}