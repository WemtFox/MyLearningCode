#include "stdio.h"

int main(){
	int i =0;
	scanf("%d", &i);
	if ( i >30 )
		printf("i>30\n");
	else if (i > 10)
		printf("i>10\n");
	else
		printf("i<=10\n");
	
	return 0;
}
