#include "stdio.h"

int main(){
	int *p = new int[4];
	char *p2 = new char[4];
	

	delete p;
	delete p2;
	
	return 0;
}