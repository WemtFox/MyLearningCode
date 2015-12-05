#include "stdio.h"

#pragma pack(1)

//struct st{
//	int x;
//	int y;
//};


class st{

public:
	void fun(){
		printf("Hello, world\n");
	}
};
int main(){
	st temp;
//	temp.x = 2;
// 	temp.y = 3;
	temp.fun();

	printf("%d\n", sizeof(st));
	
	return 0;
}