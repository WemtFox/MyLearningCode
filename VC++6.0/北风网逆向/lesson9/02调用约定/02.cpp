#include "stdio.h"

int __fastcall fun(int x, int y, int i, int j, int k){
	int z;
	z = x + y + i + j + k;
	return z;
}

int main(){
	fun(3,5,7,5,9);
}