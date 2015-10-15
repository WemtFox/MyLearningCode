#include<windows.h>



void CopySelf();

int main(){

	CopySelf();
	return 0;
}

void CopySelf(){

	//命名问题：s是代表字符串，z代表是0结尾
	//这个一般出现在变量名中 表示这个变量是以零结尾的标准c字符串

	char szSelfName[300] = {0};	//保存自身路径
	char szWindowsPath[300] = {0};	//保存windows目录的路径
	char szSystemPath[300] = {0};	//保存系统目录的路径
	char szTmpPath[300] = {0};	//临时路径变量

	GetModuleFileName(NULL,(LPWSTR)szSelfName,300);		//获取程序本身路径
	GetWindowsDirectory((LPWSTR)szWindowsPath, 300);	//获取windows的路径
	GetSystemDirectory((LPWSTR)szSystemPath, 300);		//获取系统目录的路径

	strcat(szSystemPath, "\\backdoor.exe");// \为转义符
	strcat(szWindowsPath, "\\backdoor.exe");//同上

	//输出
	puts(szSelfName);
	printf("\n");
	puts(szSystemPath);
	printf("\n");
	puts(szWindowsPath);
	printf("\n");
}