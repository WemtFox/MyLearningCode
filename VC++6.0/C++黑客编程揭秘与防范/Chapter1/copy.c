#include<windows.h>



void CopySelf();

int main(){

	CopySelf();
	return 0;
}

void CopySelf(){

	//�������⣺s�Ǵ����ַ�����z������0��β
	//���һ������ڱ������� ��ʾ��������������β�ı�׼c�ַ���

	char szSelfName[300] = {0};	//��������·��
	char szWindowsPath[300] = {0};	//����windowsĿ¼��·��
	char szSystemPath[300] = {0};	//����ϵͳĿ¼��·��
	char szTmpPath[300] = {0};	//��ʱ·������

	GetModuleFileName(NULL,(LPWSTR)szSelfName,300);		//��ȡ������·��
	GetWindowsDirectory((LPWSTR)szWindowsPath, 300);	//��ȡwindows��·��
	GetSystemDirectory((LPWSTR)szSystemPath, 300);		//��ȡϵͳĿ¼��·��

	strcat(szSystemPath, "\\backdoor.exe");// \Ϊת���
	strcat(szWindowsPath, "\\backdoor.exe");//ͬ��

	//���
	puts(szSelfName);
	printf("\n");
	puts(szSystemPath);
	printf("\n");
	puts(szWindowsPath);
	printf("\n");
}