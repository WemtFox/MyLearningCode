// 012������.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "014������3.h"
#include "strsafe.h"

#define MAX_LOADSTRING 100
#define MAX_LINE 50

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
	LoadString(hInstance, IDC_MY0143, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ִ��Ӧ�ó����ʼ��:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY0143));

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
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY0143));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_MY0143);
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
	SCROLLINFO si;
	static int cxChar, cyChar, xUpper;//����ƽ����ȣ���ֱ�߶ȣ���д��ĸˮƽ���
	static int cx, cy, scrollYPos, scrollXPos, cxMax;//�ͻ�����ȣ��߶ȣ���ֱ����λ��,ˮƽ����λ�ã� �ͻ�����ʾ���ݵ�����ȣ�����������������
	static int iVscrollPos;
	int x, y; //ˮƽ�ʹ�ֱ����
	HRESULT hr;
	int FirstLine, LastLine; //ʧЧ�����һ�У����һ��
	switch (message)
	{
	case WM_CREATE:
		hdc = GetDC(hWnd);
		GetTextMetrics(hdc, &tm);
		cxChar = tm.tmAveCharWidth;
		cxMax = (tm.tmPitchAndFamily & 1? 3: 2) * cxChar / 2;
		cyChar = tm.tmHeight + tm.tmExternalLeading;
		ReleaseDC(hWnd, hdc);
		//SetScrollRange(hWnd, SB_VERT, 0, 49, FALSE);
		
		cxMax = cxChar*48 + cxMax*12; //���ÿͻ�����ʾ�ַ��������
		break;
	case WM_VSCROLL:
		//��ȡ��ֱ������������Ϣ
		si.cbSize = sizeof(&si);
		si.fMask = SIF_ALL;
		GetScrollInfo(hWnd, SB_VERT, &si);

		//���浱ǰ����λ��
		scrollYPos = si.nPos;
		switch (LOWORD(wParam))
		{
		case SB_TOP://Home��
			si.nPos = si.nMin;
			break;
		case SB_BOTTOM://End��
			si.nPos = si.nMax;
			break;
		case SB_LINEUP:
			si.nPos -= 1;
			break;
		case SB_LINEDOWN:
			si.nPos += 1;
			break;
		case SB_PAGEUP:
			si.nPos -= si.nPage;
			break;
		case SB_PAGEDOWN:
			si.nPos += si.nPage;
			break;
		case SB_THUMBTRACK:
			si.nPos = si.nTrackPos;
			break;
		/*case SB_THUMBPOSITION:
			si.nPos = si.nTrackPos;*/
			break;
		default:
			break;
		}
		

		//���ù�������λ��
		si.fMask = SIF_POS;
		SetScrollInfo(hWnd, SB_VERT, &si, TRUE);

		//��ȡ����λ��
		GetScrollInfo(hWnd, SB_VERT, &si);

		//�Ƚ�
		if (si.nPos != scrollYPos)
		{
			ScrollWindow(hWnd, 0, cyChar * (scrollYPos - si.nPos), NULL, NULL);
			UpdateWindow(hWnd);
		}
		////����λ��
		//SetScrollPos(hWnd, SB_VERT, iVscrollPos, TRUE);
		////�����ػ�
		//InvalidateRect(hWnd, NULL, TRUE);
		break;
	case  WM_HSCROLL:
		//��ȡˮƽ������������Ϣ
		si.cbSize = sizeof(&si);
		si.fMask = SIF_ALL;
		GetScrollInfo(hWnd, SB_HORZ, &si);
		
		//���浱ǰ�����λ�ã���Щ���бȽ�
		scrollXPos = si.nPos;
		switch (LOWORD(wParam))
		{
		case SB_LINELEFT:
			si.nPos -= 1;
			break;
		case SB_LINERIGHT:
			si.nPos += 1;
			break;
		case SB_PAGELEFT:
			si.nPos -= si.nPage;
			break;
		case SB_PAGERIGHT:
			si.nPos += si.nPage;
			break;
		case SB_THUMBTRACK:
			si.nPos = si.nTrackPos;
			break;
		
		default:
			break;
		}

		//���ù�������λ��
		si.fMask = SIF_POS;
		SetScrollInfo(hWnd, SB_HORZ, &si, TRUE);

		//��ù�����λ��
		GetScrollInfo(hWnd, SB_HORZ, &si);

		//���ǰ��ֵ�Ƚϣ���ͬ���������
		if (si.nPage != scrollXPos)
		{
			ScrollWindow(hWnd, cxChar *(scrollXPos -si.nPos), 0, NULL, NULL);
		}

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
		//׼������
		hdc = BeginPaint(hWnd, &ps);
		// TODO: �ڴ���������ͼ����...

		//��ô�ֱ��������λ��
		si.cbSize = sizeof(si);
		si.fMask = SIF_POS;
		GetScrollInfo(hWnd, SB_VERT, &si);
		scrollYPos = si.nPos;

		//���ˮƽ��������λ��
		GetScrollInfo(hWnd, SB_HORZ, &si);
		scrollXPos = si.nPos;

		//������Ҫ�ػ������
		FirstLine = max(0, scrollYPos + ps.rcPaint.top / cyChar);
		LastLine = min(MAX_LINE - 1, scrollYPos + ps.rcPaint.bottom / cyChar );
		GetClientRect(hWnd, &rect);
		for (int i = FirstLine; i <= LastLine; i++)
		{
			x = (1 - scrollXPos) * cxChar;
			y = (i - scrollYPos) * cyChar;

			StringCchPrintf(szBuffer, 128, TEXT("λ�ã�%d"), i);
			StringCchLength(szBuffer, 128, &iTarget);
			TextOut(hdc, x , y, szBuffer, iTarget);
		}
		EndPaint(hWnd, &ps);
		break;
	case WM_SIZE:
		
		cx = LOWORD(lParam);//��ȡ�ͻ������
		cy = HIWORD(lParam);//��ȡ�ͻ����߶�

		//���ô�ֱ�������ķ�Χ��ҳ���С��ҳ���С��������Ĵ�С��
		si.cbSize = sizeof(si);
		si.fMask = SIF_RANGE | SIF_PAGE;
		si.nMin = 0;
		si.nMax = MAX_LINE -1;
		si.nPage = cy / cyChar;
		SetScrollInfo(hWnd, SB_VERT, &si, TRUE);

		//����ˮƽ�������ķ�Χ��ҳ���С��ҳ���С��������Ĵ�С��
		si.cbSize = sizeof(si);
		si.fMask = SIF_RANGE | SIF_PAGE;
		si.nMin = 0;
		si.nMax = 2 + cxMax /cxChar;
		si.nPage = cx / cxChar;
		SetScrollInfo(hWnd, SB_HORZ, &si, TRUE);

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
