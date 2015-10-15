#include <Windows.h>

#pragma comment (lib, "FirstDll")

extern "C" VOID MsgBox(char* szMsg);

int main(int argc, char* argv[])
{
	MsgBox("Hello Dll Test !");
	return 0;
}
