#include "stdio.h"
#include <string.h>
int main(){
	
	char str1[] = "Hello";
	int size = sizeof(str1);	//6
	int n = strlen(str1);	//5
	printf("%d",n);
	return 0;
}