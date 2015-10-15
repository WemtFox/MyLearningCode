#include <Windows.h>
#include <stdio.h>

LRESULT CALLBACK MyWinProc(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
	);

//1.入口函数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrecInstance, LPSTR lpCmdLine, int nCmdShow){
	//2 创建窗口
	//2.1 设计一个窗口类
	WNDCLASS MyWnd;
	MyWnd.cbClsExtra = NULL;
	MyWnd.cbWndExtra = NULL;
	MyWnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	MyWnd.hCursor = LoadCursor(NULL, IDC_NO);
	MyWnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	MyWnd.hInstance = hInstance;
	MyWnd.lpfnWndProc = MyWinProc;
	MyWnd.lpszClassName = "Hello";
	MyWnd.lpszMenuName = NULL;
	MyWnd.style = CS_HREDRAW | CS_VREDRAW;

	//style = 0，窗口类风格为默认类型，窗口不会因为窗口尺寸的变化而重画
	//可以观察到此时WM_LBUTTONDOWN中的文字，当窗口尺寸的变化时会保留下来
	//	MyWnd.style = 0;

	//2.2对设计好的窗口类进行注册
	RegisterClass(&MyWnd);

	//2.3创建窗口
	HWND hWnd;
	hWnd = CreateWindow("Hello", "示例", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	//2.4显示及更新窗口
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
	//如果有无效区，则马上发送WM_PAINT到窗口处理过程，
	//不进消息队列进行排队等待，立即刷新窗口，否则，什么都不做。 

	//3.消息循环
	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0))//从消息队列中获取消息
	{
		//消息解析
		TranslateMessage(&msg);
		//发送消息，发送到“窗口过程”：其实是先给操作系统，操作系统再调用窗口过程函数
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

//4.“窗口过程函数”（编写消息响应代码）
LRESULT CALLBACK MyWinProc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	PAINTSTRUCT ps;
	switch (uMsg)
	{
	case WM_PAINT:
		HDC hpaintDC;
		hpaintDC = BeginPaint(hwnd, &ps);
		TextOut(hpaintDC,400, 300, "勾股定理", strlen("勾股定理"));
		EndPaint(hwnd,&ps);
		break;
	case WM_CHAR:
		char str[255];
		sprintf(str,"char is %d", wParam);
		MessageBox(hwnd,str,"按键响应",0);
		break;
	case WM_LBUTTONDOWN:
		MessageBox(hwnd, "鼠标左键按下", "鼠标事件", MB_OK);
		break;
	case WM_CLOSE:
		if (IDYES == MessageBox(hwnd, "真的想退出吗？", "退出", MB_YESNO))
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
