#include <windows.h>
#include <stdio.h>

LRESULT CALLBACK MyWndProc(
  HWND hwnd,      // handle to window
  UINT uMsg,      // message identifier
  WPARAM wParam,  // first message parameter
  LPARAM lParam   // second message parameter
);

//1 入口函数
int WINAPI WinMain(
  HINSTANCE hInstance,      // handle to current instance
  HINSTANCE hPrevInstance,  // handle to previous instance
  LPSTR lpCmdLine,          // command line
  int nCmdShow              // show state
)
{
//	char str[255];
//	sprintf(str,"%d", nCmdShow);
//	MessageBox(NULL,str,"窗口状态",0);

	//2 创建窗口
	//2.1 设计一个窗口类
	WNDCLASS MyWnd;
	MyWnd.cbClsExtra = NULL;
	MyWnd.cbWndExtra = NULL;
	MyWnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	MyWnd.hCursor = LoadCursor(NULL, IDC_NO);
	MyWnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	MyWnd.hInstance = hInstance;
	MyWnd.lpfnWndProc = MyWndProc;
	MyWnd.lpszClassName = TEXT("Hello");
	MyWnd.lpszMenuName = NULL;
	MyWnd.style = CS_HREDRAW | CS_VREDRAW;

	//style = 0，窗口类风格为默认类型，窗口不会因为窗口尺寸的变化而重画
	//可以观察到此时WM_LBUTTONDOWN中的文字，当窗口尺寸的变化时会保留下来
//	MyWnd.style = 0;

	//2.2 对设计好的窗口类进行注册
    RegisterClass(&MyWnd);

	//2.3 创建窗口
	HWND hWnd;
	hWnd = CreateWindow(TEXT("Hello"),TEXT("Windows编程"), WS_OVERLAPPEDWINDOW /*& ~WS_MAXIMIZEBOX*/, 
		                CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
						//0,0,800,600,
					    NULL,NULL,hInstance,NULL);

	
	//2.4 显示及其更新窗口
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
	//如果有无效区，则马上发送WM_PAINT到窗口处理过程，
	//不进消息队列进行排队等待，立即刷新窗口，否则，什么都不做。 

	//3.消息循环
	MSG msg;

	while (GetMessage(&msg,NULL,0,0)) //从消息队列中获取消息
	{
		TranslateMessage(&msg);    //消息解释
    //发送消息
		DispatchMessage(&msg);     //将消息发送到“窗口过程”
	} 
	return 0;

}

//4.“窗口过程函数”（编写消息响应代码）
LRESULT CALLBACK MyWndProc(
  HWND hwnd,      // handle to window
  UINT uMsg,      // message identifier
  WPARAM wParam,  // first message parameter
  LPARAM lParam   // second message parameter
)
{
	switch (uMsg)
	{
	case WM_PAINT:
		HDC hpaintDC;
		PAINTSTRUCT ps;
		hpaintDC=BeginPaint(hwnd,&ps);
		TextOut(hpaintDC,255,50,TEXT("Hello World!"),strlen("Hello World!"));
		EndPaint(hwnd,&ps);
		break;
	case WM_CHAR:
		char str[255];
		sprintf(str,"char is %d", wParam);
		MessageBox(hwnd,str,TEXT("按键响应"),0);
		break;
	case WM_LBUTTONDOWN:
		MessageBox(hwnd,TEXT("鼠标左键按下"),TEXT("鼠标响应"),0);
		HDC hDC;
		hDC = GetDC(hwnd);
		TextOut(hDC,255,100,TEXT("Hello World!"),strlen("Hello World!"));
		ReleaseDC(hwnd,hDC);
		break;
	case WM_CLOSE:
		if (IDYES == MessageBox(hwnd,TEXT("真的要退出吗？"),TEXT("退出"), MB_YESNO))
		{
			DestroyWindow(hwnd);
		} 
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_RBUTTONDOWN:
		SendMessage(FindWindow(TEXT("CalcFrame"),NULL),WM_SETTEXT,0,(LPARAM)"Hello!");
//		SendMessage(FindWindow(NULL,"计算器"),WM_SETTEXT,0,(LPARAM)"Hello!");
		SendMessage(hwnd,WM_SETTEXT,0,(LPARAM)"Hello!");
		break;
	default:
		return DefWindowProc(hwnd,uMsg,wParam,lParam);
	}
	
	return 0;
}

/*
	int bRet;
	while(bRet = GetMessage(&msg, hWnd, 0, 0))
	{ 
		if (-1 == bRet)
		{
			// handle the error and possibly exit
			return (-1);
		}
		else 
		{
			TranslateMessage(&msg); 
			DispatchMessage(&msg); 
		}
	}
*/

/***** 使用PeekMessage写消息循环

	while(TRUE) { 
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) 
		{ 
			if (msg.message == WM_QUIT) break; 
			TranslateMessage(&msg); 
			DispatchMessage(&msg); 
		}
	}

********************************/
