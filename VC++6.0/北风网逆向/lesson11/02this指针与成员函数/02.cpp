#include "stdio.h"

#pragma pack(1)

class st{

public:
	char c;
	int x;
	static int y;
	static char c2;
	void fun(){
		scanf("%d", &y);
		printf("%d\n", y);
	}	
};

int st::y = 0;
int main(){
	st temp,temp2;
	temp.fun();
	temp2.fun();
	printf("%d\n", sizeof(st));
	
	return 0;
}