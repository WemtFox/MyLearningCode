#include <Windows.h>
#include <stdio.h>

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
	MyWnd.lpszClassName = "Hello";
	MyWnd.lpszMenuName = NULL;
	MyWnd.style = CS_HREDRAW | CS_VREDRAW;

	//style = 0����������ΪĬ�����ͣ����ڲ�����Ϊ���ڳߴ�ı仯���ػ�
	//���Թ۲쵽��ʱWM_LBUTTONDOWN�е����֣������ڳߴ�ı仯ʱ�ᱣ������
	//	MyWnd.style = 0;

	//2.2����ƺõĴ��������ע��
	RegisterClass(&MyWnd);

	//2.3��������
	HWND hWnd;
	hWnd = CreateWindow("Hello", "ʾ��", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

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
	switch (uMsg)
	{
	case WM_PAINT:
		HDC hpaintDC;
		hpaintDC = BeginPaint(hwnd, &ps);
		TextOut(hpaintDC,400, 300, "���ɶ���", strlen("���ɶ���"));
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
