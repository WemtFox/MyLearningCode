#include <windows.h>


int WINAPI WinMain (HINSTANCE hInstance ,HINSTANCE hprevInstance ,PSTR szCmdLine ,int iCmdShow)
{
	MessageBox(NULL, TEXT("Hello World"),TEXT("Title"), MB_OK );

	return 0;
}