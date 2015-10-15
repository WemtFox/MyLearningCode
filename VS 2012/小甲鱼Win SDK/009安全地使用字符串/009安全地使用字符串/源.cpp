#include <Windows.h>
#include <stdio.h>
#include <atlstr.h>
#include "strsafe.h"

LRESULT CALLBACK MyWinProc(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
	);

//1.��ں���
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrecInstance, LPSTR lpCmdLine, int nCmdShow){

	//2 ��������
	//2.1 ���һ��������
	WNDCLASS MyWnd;
	MyWnd.cbClsExtra = NULL;
	MyWnd.cbWndExtra = NULL;
	MyWnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	MyWnd.hCursor = LoadCursor(NULL, IDC_NO);
	MyWnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	MyWnd.hInstance = hInstance;
	MyWnd.lpfnWndProc = MyWinProc;
	MyWnd.lpszClassName = TEXT("Hello");
	MyWnd.lpszMenuName = NULL;
	MyWnd.style = CS_HREDRAW | CS_VREDRAW;

	//style = 0����������ΪĬ�����ͣ����ڲ�����Ϊ���ڳߴ�ı仯���ػ�
	//���Թ۲쵽��ʱWM_LBUTTONDOWN�е����֣������ڳߴ�ı仯ʱ�ᱣ������
	//	MyWnd.style = 0;

	//2.2����ƺõĴ��������ע��
	RegisterClass(&MyWnd);

	//2.3��������
	HWND hWnd;
	hWnd = CreateWindow("Hello", TEXT("ʾ��"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	//2.4��ʾ�����´���
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
	//�������Ч���������Ϸ���WM_PAINT�����ڴ�����̣�
	//������Ϣ���н����Ŷӵȴ�������ˢ�´��ڣ�����ʲô�������� 

	//3.��Ϣѭ��
	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0))//����Ϣ�����л�ȡ��Ϣ
	{
		//��Ϣ����
		TranslateMessage(&msg);
		//������Ϣ�����͵������ڹ��̡�����ʵ���ȸ�����ϵͳ������ϵͳ�ٵ��ô��ڹ��̺���
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

//4.�����ڹ��̺���������д��Ϣ��Ӧ���룩
LRESULT CALLBACK MyWinProc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	PAINTSTRUCT ps;
	TCHAR szBuffer[128],string[128] = "����һ���ַ���";
	size_t iTarget;
	HDC hpaintDC;
	static int cxChar, cyChar;
	TEXTMETRIC tm;
	switch (uMsg)
	{
	case WM_CREATE:
		hpaintDC = GetDC(hwnd);
		GetTextMetrics(hpaintDC, &tm);
		cxChar = tm.tmAveCharWidth;
		cyChar = tm.tmHeight + tm.tmExternalLeading;
		ReleaseDC(hwnd, hpaintDC);
	case WM_PAINT:
		
		hpaintDC = BeginPaint(hwnd, &ps);
		for (int i = 0; i < 10; i++)
		{
			//����ȫ
			/*wsprintf(szBuffer, "%d: %s", i+1, "����һ���ַ���");
			TextOut(hpaintDC,0, 20*i, szBuffer, lstrlen(szBuffer));*/
			//TextOut(hpaintDC,0, 20*i, szBuffer, strlen(szBuffer));

			//��ȫ��
			StringCchPrintf(szBuffer, 128, TEXT("%d: %s"), i+1, string);
			StringCchLength(szBuffer, 128, &iTarget);
			TextOut(hpaintDC,cxChar, i*cyChar, szBuffer, iTarget);

		}
		/*TextOut(hpaintDC,400, 300, TEXT("���ɶ���"), strlen("���ɶ���"));*/
		EndPaint(hwnd,&ps);
		break;
	case WM_CHAR:
		char str[255];
		sprintf(str,"char is %d", wParam);
		MessageBox(hwnd,str,"������Ӧ",0);
		break;
	case WM_LBUTTONDOWN:
		MessageBox(hwnd, "����������", "����¼�", MB_OK);
		break;
	case WM_CLOSE:
		if (IDYES == MessageBox(hwnd, "������˳���", "�˳�", MB_YESNO))
		{
			DestroyWindow(hwnd);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

	return 0;
}
