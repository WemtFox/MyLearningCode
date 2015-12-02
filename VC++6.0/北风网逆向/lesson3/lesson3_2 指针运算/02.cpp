#include "iostream"
using namespace std;
int main(){
//	int n = 5;
//	int *p = &n;
//	float n = 5;
//	float *p = &n;
//	double n = 5;
//	double *p = &n;
	char n = '5';
	char *p = &n;
	cout << p << endl;
	p = p + 1;
	cout << p <<endl;
	return 0;
}