#include "iostream.h"

int main(){
	char cArray [] = {'a','b','c','d','e'};

	char *pChar = cArray;	//数组名代表数组首地址

	cout << *pChar <<endl;

	int *pInt = (int*)pChar;

	cout << *pInt <<endl;

	return 0;
}