#include "stdio.h"
#include <string.h>
int main(){
	
	char str1[] = "Hello";
	char str2[] = "world";
	int ret = strcmp(str2, str1);
	printf("%d",ret);
	return 0;
}