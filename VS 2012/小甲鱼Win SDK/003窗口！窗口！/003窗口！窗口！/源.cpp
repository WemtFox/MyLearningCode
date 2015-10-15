#include <windows.h>
#include <stdio.h>

LRESULT CALLBACK MyWndProc(
  HWND hwnd,      // handle to window
  UINT uMsg,      // message identifier
  WPARAM wParam,  // first message parameter
  LPARAM lParam   // second message parameter
);

//1 ��ں���
int WINAPI WinMain(
  HINSTANCE hInstance,      // handle to current instance
  HINSTANCE hPrevInstance,  // handle to previous instance
  LPSTR lpCmdLine,          // command line
  int nCmdShow              // show state
)
{
//	char str[255];
//	sprintf(str,"%d", nCmdShow);
//	MessageBox(NULL,str,"����״̬",0);

	//2 ��������
	//2.1 ���һ��������
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

	//style = 0����������ΪĬ�����ͣ����ڲ�����Ϊ���ڳߴ�ı仯���ػ�
	//���Թ۲쵽��ʱWM_LBUTTONDOWN�е����֣������ڳߴ�ı仯ʱ�ᱣ������
//	MyWnd.style = 0;

	//2.2 ����ƺõĴ��������ע��
    RegisterClass(&MyWnd);

	//2.3 ��������
	HWND hWnd;
	hWnd = CreateWindow(TEXT("Hello"),TEXT("Windows���"), WS_OVERLAPPEDWINDOW /*& ~WS_MAXIMIZEBOX*/, 
		                CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
						//0,0,800,600,
					    NULL,NULL,hInstance,NULL);

	
	//2.4 ��ʾ������´���
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
	//�������Ч���������Ϸ���WM_PAINT�����ڴ�����̣�
	//������Ϣ���н����Ŷӵȴ�������ˢ�´��ڣ�����ʲô�������� 

	//3.��Ϣѭ��
	MSG msg;

	while (GetMessage(&msg,NULL,0,0)) //����Ϣ�����л�ȡ��Ϣ
	{
		TranslateMessage(&msg);    //��Ϣ����
    //������Ϣ
		DispatchMessage(&msg);     //����Ϣ���͵������ڹ��̡�
	} 
	return 0;

}

//4.�����ڹ��̺���������д��Ϣ��Ӧ���룩
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
		MessageBox(hwnd,str,TEXT("������Ӧ"),0);
		break;
	case WM_LBUTTONDOWN:
		MessageBox(hwnd,TEXT("����������"),TEXT("�����Ӧ"),0);
		HDC hDC;
		hDC = GetDC(hwnd);
		TextOut(hDC,255,100,TEXT("Hello World!"),strlen("Hello World!"));
		ReleaseDC(hwnd,hDC);
		break;
	case WM_CLOSE:
		if (IDYES == MessageBox(hwnd,TEXT("���Ҫ�˳���"),TEXT("�˳�"), MB_YESNO))
		{
			DestroyWindow(hwnd);
		} 
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_RBUTTONDOWN:
		SendMessage(FindWindow(TEXT("CalcFrame"),NULL),WM_SETTEXT,0,(LPARAM)"Hello!");
//		SendMessage(FindWindow(NULL,"������"),WM_SETTEXT,0,(LPARAM)"Hello!");
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

/***** ʹ��PeekMessageд��Ϣѭ��

	while(TRUE) { 
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) 
		{ 
			if (msg.message == WM_QUIT) break; 
			TranslateMessage(&msg); 
			DispatchMessage(&msg); 
		}
	}

********************************/
