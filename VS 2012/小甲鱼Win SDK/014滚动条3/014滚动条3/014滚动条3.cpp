// 012滚动条.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "014滚动条3.h"
#include "strsafe.h"

#define MAX_LOADSTRING 100
#define MAX_LINE 50

// 全局变量:
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名

// 此代码模块中包含的函数的前向声明:
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

 	// TODO: 在此放置代码。
	MSG msg;
	HACCEL hAccelTable;

	// 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_MY0143, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY0143));

	// 主消息循环:
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
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
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
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // 将实例句柄存储在全局变量中

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
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的: 处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
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
	static int cxChar, cyChar, xUpper;//字体平均宽度，垂直高度，大写字母水平宽度
	static int cx, cy, scrollYPos, scrollXPos, cxMax;//客户区宽度，高度，垂直滑块位置,水平滑块位置， 客户区显示内容的最大宽度（超过则加入滚动条）
	static int iVscrollPos;
	int x, y; //水平和垂直坐标
	HRESULT hr;
	int FirstLine, LastLine; //失效区域第一行，最后一行
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
		
		cxMax = cxChar*48 + cxMax*12; //设置客户区显示字符的最大宽度
		break;
	case WM_VSCROLL:
		//获取垂直滚条的所有信息
		si.cbSize = sizeof(&si);
		si.fMask = SIF_ALL;
		GetScrollInfo(hWnd, SB_VERT, &si);

		//保存当前滑块位置
		scrollYPos = si.nPos;
		switch (LOWORD(wParam))
		{
		case SB_TOP://Home键
			si.nPos = si.nMin;
			break;
		case SB_BOTTOM://End键
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
		

		//设置滚动条新位置
		si.fMask = SIF_POS;
		SetScrollInfo(hWnd, SB_VERT, &si, TRUE);

		//获取滑块位置
		GetScrollInfo(hWnd, SB_VERT, &si);

		//比较
		if (si.nPos != scrollYPos)
		{
			ScrollWindow(hWnd, 0, cyChar * (scrollYPos - si.nPos), NULL, NULL);
			UpdateWindow(hWnd);
		}
		////设置位置
		//SetScrollPos(hWnd, SB_VERT, iVscrollPos, TRUE);
		////可以重绘
		//InvalidateRect(hWnd, NULL, TRUE);
		break;
	case  WM_HSCROLL:
		//获取水平滚条的所有信息
		si.cbSize = sizeof(&si);
		si.fMask = SIF_ALL;
		GetScrollInfo(hWnd, SB_HORZ, &si);
		
		//保存当前滑块的位置，迟些进行比较
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

		//设置滚动条新位置
		si.fMask = SIF_POS;
		SetScrollInfo(hWnd, SB_HORZ, &si, TRUE);

		//获得滚动条位置
		GetScrollInfo(hWnd, SB_HORZ, &si);

		//与此前的值比较，不同则滚动窗口
		if (si.nPage != scrollXPos)
		{
			ScrollWindow(hWnd, cxChar *(scrollXPos -si.nPos), 0, NULL, NULL);
		}

		break;
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// 分析菜单选择:
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
		//准备绘制
		hdc = BeginPaint(hWnd, &ps);
		// TODO: 在此添加任意绘图代码...

		//获得垂直滚动条的位置
		si.cbSize = sizeof(si);
		si.fMask = SIF_POS;
		GetScrollInfo(hWnd, SB_VERT, &si);
		scrollYPos = si.nPos;

		//获得水平滚动条的位置
		GetScrollInfo(hWnd, SB_HORZ, &si);
		scrollXPos = si.nPos;

		//计算需要重绘的区域
		FirstLine = max(0, scrollYPos + ps.rcPaint.top / cyChar);
		LastLine = min(MAX_LINE - 1, scrollYPos + ps.rcPaint.bottom / cyChar );
		GetClientRect(hWnd, &rect);
		for (int i = FirstLine; i <= LastLine; i++)
		{
			x = (1 - scrollXPos) * cxChar;
			y = (i - scrollYPos) * cyChar;

			StringCchPrintf(szBuffer, 128, TEXT("位置：%d"), i);
			StringCchLength(szBuffer, 128, &iTarget);
			TextOut(hdc, x , y, szBuffer, iTarget);
		}
		EndPaint(hWnd, &ps);
		break;
	case WM_SIZE:
		
		cx = LOWORD(lParam);//获取客户区宽度
		cy = HIWORD(lParam);//获取客户区高度

		//设置垂直滚动条的范围和页面大小（页面大小决定滑块的大小）
		si.cbSize = sizeof(si);
		si.fMask = SIF_RANGE | SIF_PAGE;
		si.nMin = 0;
		si.nMax = MAX_LINE -1;
		si.nPage = cy / cyChar;
		SetScrollInfo(hWnd, SB_VERT, &si, TRUE);

		//设置水平滚动条的范围和页面大小（页面大小决定滑块的大小）
		si.cbSize = sizeof(si);
		si.fMask = SIF_RANGE | SIF_PAGE;
		si.nMin = 0;
		si.nMax = 2 + cxMax /cxChar;
		si.nPage = cx / cxChar;
		SetScrollInfo(hWnd, SB_HORZ, &si, TRUE);

		/*hdc = GetDC(hWnd);
		StringCchPrintf(szBuffer, 128, TEXT("客户区的大小为：%d * %d"), cx, cy);
		StringCchLength(szBuffer, 128, &iTarget);
		for (int i =0; i < 50; i++)
		{
			StringCchPrintf(szBuffer, 128, TEXT("客户区的大小为：%d * %d, 位置：%d"), cx, cy, i);
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

// “关于”框的消息处理程序。
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
