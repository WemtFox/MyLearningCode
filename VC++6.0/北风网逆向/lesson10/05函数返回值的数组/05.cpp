#include "stdio.h"

char* fun(){
	char str[] = "hello\n";
	return str;

}

int main(){
 	
	char str[20];
	printf(fun());
	return 0;
}