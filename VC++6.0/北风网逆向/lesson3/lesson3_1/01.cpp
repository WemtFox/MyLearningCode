#include "iostream"
using namespace std;

int main(){
	int n = 5;
	
	int *pn = &n;

	int **ppn = &pn;
	
	//����0x0018ff44Ϊ����n�ĵ�ַ
	//cout << *(0x0018ff44) << endl;
	//ת��Ϊָ�����ȷ���5
	cout << *((int *)0x0018ff44) << endl;	
	//cout << *((char *)0x0018ff44) << endl;
	

	//ָ��ָ���ָ��
	cout<<*ppn<<endl;	//�������pnָ������ĵ�ַ
	//cout<<**ppn<<endl;
	return 0;
}