#include "iostream.h"

int main(){
	char cArray [] = {'a','b','c','d','e'};

	char *pChar = cArray;	//���������������׵�ַ

	cout << *pChar <<endl;

	int *pInt = (int*)pChar;

	cout << *pInt <<endl;

	return 0;
}