#include "stdio.h"

int main(){
	int i =0;
	scanf("%d", &i);
	switch(i) {
	case 1:
		printf("i==1\n");
		break;
	case 2:
		printf("i==2\n");
		break;
	case 3:
		printf("i==1\n");
		break;
	case 4:
		printf("i==2\n");
		break;
	case 5:
		printf("i==1\n");
		break;
	case 6:
		printf("i==2\n");
		break;
	default:
		printf("unknow\n");
	}
	return 0;
}
