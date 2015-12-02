#include "iostream"
using namespace std;

int main(){
	int n = 5;
	
	int *pn = &n;

	int **ppn = &pn;
	
	//报错，0x0018ff44为变量n的地址
	//cout << *(0x0018ff44) << endl;
	//转化为指针就正确输出5
	cout << *((int *)0x0018ff44) << endl;	
	//cout << *((char *)0x0018ff44) << endl;
	

	//指向指针的指针
	cout<<*ppn<<endl;	//输出的是pn指针变量的地址
	//cout<<**ppn<<endl;
	return 0;
}