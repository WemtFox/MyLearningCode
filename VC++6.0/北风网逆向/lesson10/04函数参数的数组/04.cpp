#include "stdio.h"

void fun(char str[]){
	printf(str);
// 	printf("%d\n", sizeof(str));
}

int main(){

// 	char str[] = "hello\n";
	char str[] = "%d";
	fun(str);
// 	printf("%d\n", sizeof(str));
	return 0;
}