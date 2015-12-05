#include "stdio.h"

#pragma pack(1)

class st{

public:
	char c;
	int x;
};

int fun(st object){
	return (object.c + object.x);
}

int main(){
	st temp;
	fun(temp);
	printf("%d\n", sizeof(st));
	
	return 0;
}