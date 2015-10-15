// 012������.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "012������.h"
#include "strsafe.h"

#define MAX_LOADSTRING 100

// ȫ�ֱ���:
HINSTANCE hInst;								// ��ǰʵ��
TCHAR szTitle[MAX_LOADSTRING];					// �������ı�
TCHAR szWindowClass[MAX_LOADSTRING];			// ����������

// �˴���ģ���а����ĺ�����ǰ������:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: �ڴ˷��ô��롣
	MSG msg;
	HACCEL hAccelTable;

	// ��ʼ��ȫ���ַ���
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_MY012, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ִ��Ӧ�ó����ʼ��:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY012));

	// ����Ϣѭ��:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  ����: MyRegisterClass()
//
//  Ŀ��: ע�ᴰ���ࡣ
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY012));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_MY012);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   ����: InitInstance(HINSTANCE, int)
//
//   Ŀ��: ����ʵ�����������������
//
//   ע��:
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW |WS_VSCROLL |WS_HSCROLL,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ����: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��: ���������ڵ���Ϣ��
//
//  WM_COMMAND	- ����Ӧ�ó���˵�
//  WM_PAINT	- ����������
//  WM_DESTROY	- �����˳���Ϣ������
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rect;
	TCHAR szBuffer[128];
	size_t iTarget;
	TEXTMETRIC tm;
	static int cxChar, cyChar;
	static int cx, cy, scrollY;
	static int iVscrollPos;
	switch (message)
	{
	case WM_CREATE:
		hdc = GetDC(hWnd);
		GetTextMetrics(hdc, &tm);
		cxChar = tm.tmAveCharWidth;
		cyChar = tm.tmHeight + tm.tmExternalLeading;
		ReleaseDC(hWnd, hdc);
		SetScrollRange(hWnd, SB_VERT, 0, 49, FALSE);
		
		break;
	case WM_VSCROLL:
		hdc = GetDC(hWnd);
		SetTextAlign(hdc, TA_TOP |TA_RIGHT);
		switch (LOWORD(wParam))
		{
		case SB_LINEUP:
			iVscrollPos -= 1;
			break;
		case SB_LINEDOWN:
			iVscrollPos += 1;
			break;
		case SB_PAGEUP:
			iVscrollPos -= cy/cyChar;
			break;
		case SB_PAGEDOWN:
			iVscrollPos += cy/cyChar;
			break;
		case SB_THUMBTRACK:
			iVscrollPos = HIWORD(wParam);
			break;
		case SB_THUMBPOSITION:
			iVscrollPos = HIWORD(wParam);
			break;
		default:
			break;
		}
		ReleaseDC(hWnd, hdc);

		iVscrollPos = max(0, min(iVscrollPos, 49));

		if (iVscrollPos != GetScrollPos(hWnd, SB_VERT))
		{
			//����λ��
			SetScrollPos(hWnd, SB_VERT, iVscrollPos, TRUE);
			InvalidateRect(hWnd, NULL, TRUE);
			UpdateWindow(hWnd);
		}
		////����λ��
		//SetScrollPos(hWnd, SB_VERT, iVscrollPos, TRUE);
		////�����ػ�
		//InvalidateRect(hWnd, NULL, TRUE);
		break;
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// �����˵�ѡ��:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: �ڴ���������ͼ����...
		GetClientRect(hWnd, &rect);
		for (int i =0; i < 50; i++)
		{
			StringCchPrintf(szBuffer, 128, TEXT("λ�ã�%d"), i);
			StringCchLength(szBuffer, 128, &iTarget);
			scrollY = cyChar * (i - iVscrollPos);
			TextOut(hdc, cxChar , scrollY, szBuffer, iTarget);
		}
		DrawText(hdc, szBuffer, -1, &rect, DT_VCENTER| DT_CENTER |DT_SINGLELINE);
		EndPaint(hWnd, &ps);
		break;
	case WM_SIZE:
		
		cx = LOWORD(lParam);
		cy = HIWORD(lParam);
		/*hdc = GetDC(hWnd);
		StringCchPrintf(szBuffer, 128, TEXT("�ͻ����Ĵ�СΪ��%d * %d"), cx, cy);
		StringCchLength(szBuffer, 128, &iTarget);
		for (int i =0; i < 50; i++)
		{
			StringCchPrintf(szBuffer, 128, TEXT("�ͻ����Ĵ�СΪ��%d * %d, λ�ã�%d"), cx, cy, i);
			StringCchLength(szBuffer, 128, &iTarget);
			scrollY = cyChar * (i - iVscrollPos);
			TextOut(hdc, cxChar , scrollY, szBuffer, iTarget);
		}
		ReleaseDC(hWnd, hdc);*/
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// �����ڡ������Ϣ�������
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
