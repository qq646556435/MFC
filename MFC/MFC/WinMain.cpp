#include <iostream>
#include <windows.h>
#include <CommCtrl.h>
#include"resource.h"
#include "����.h"
#define _in_ 
#define _out_
#define ��ť1 0x100
#define ��ť2 0x101
#define ��ť3 0x102
#define ��ť4 0x103
#define �༭��1 0x200
//(//ö���Ӵ��ڵĻص�����)ö���Ӵ���
BOOL CALLBACK EnumChildProc(_In_ HWND   hwnd,_In_ LPARAM lParam)
{
	WCHAR Buffer[100] = { 0 };
	GetWindowTextW(hwnd, Buffer, 100);
	�������(L"%ls\n", Buffer);
	
	return TRUE;
}
//(����һ��������Ļص�����)������Ϣ��������Ϣ
LRESULT Wndproc(HWND ���ھ��,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	HMODULE ��ǰ���ڵ�ʵ����� = GetModuleHandleW(0);
	RECT �����ڵĴ�����Ϣ = { 0 };
	static HWND �༭��1�ľ�� = NULL;
	static HWND a = NULL;


	switch (uMsg)
	{

	case WM_CREATE://���ڴ�����Ϣ
		 {
			a = CreateWindowW(L"BUTTON", L"��ť1_�ƶ���ť1����", WS_CHILD | WS_VISIBLE, 20, 20, 200, 40, ���ھ��, (HMENU)��ť1, ��ǰ���ڵ�ʵ�����, 0);
			CreateWindowW(L"BUTTON", L"��ť2_��ȡ�༭��1.����", WS_CHILD | WS_VISIBLE, 20, 80, 200, 40, ���ھ��, (HMENU)��ť2, ��ǰ���ڵ�ʵ�����, 0);
			CreateWindowW(L"BUTTON", L"��ť3_���ñ༭��1.����", WS_CHILD | WS_VISIBLE, 20, 140, 200, 40, ���ھ��, (HMENU)��ť3, ��ǰ���ڵ�ʵ�����, 0);
			CreateWindowW(L"BUTTON", L"��ť4_ö���Ӵ���", WS_CHILD | WS_VISIBLE, 20, 200, 200, 40, ���ھ��, (HMENU)��ť4, ��ǰ���ڵ�ʵ�����, 0);
			CreateWindowW(L"EDIT", L"�༭��1.����1111", WS_CHILD | WS_BORDER | WS_VISIBLE, 20, 500, 200, 40, ���ھ��, (HMENU)�༭��1, ��ǰ���ڵ�ʵ�����, 0);
			�༭��1�ľ�� = GetDlgItem(���ھ��, �༭��1); //��ȡָ���ؼ��༭��1�ľ��;
			break;
		 }
	case WM_CLOSE: //���ڹر���Ϣ
		{
			MessageBoxW(���ھ��, L"���ڹر���", L"��ʾ", MB_OK);
			DestroyWindow(���ھ��);//���ٴ���
			PostQuitMessage(0); //�����˳���Ϣ
			break;
		}

	case WM_COMMAND: //ͨ�ÿؼ���Ϣ
		{
			WORD �ؼ���ʶ�� = LOWORD(wParam);
			switch (�ؼ���ʶ��)
			{
			case ��ť1: //�ƶ���ť1����
				{
					GetClientRect(���ھ��, &�����ڵĴ�����Ϣ); //��ø����ڵľ�����Ϣ
					int �������x = rand() % (�����ڵĴ�����Ϣ.right - 200);
					int �������y = rand() % (�����ڵĴ�����Ϣ.bottom - 40);
					MoveWindow(a, �������x, �������y, 200, 40, TRUE); //�ƶ�����
					break;
				}
			

			case ��ť2: //��ȡ�༭��1������

				{	WCHAR Buffer[100] = { 0 };

					GetWindowTextW(�༭��1�ľ��, Buffer, 100);     //��ȡ�༭��1������
					MessageBoxW(���ھ��, Buffer, L"��ʾ", MB_OK);
					break;

				}
				

			case ��ť3: //���ñ༭��1������
				{

					SetWindowTextW(�༭��1�ľ��, L"������"); //���ñ༭��1������
					break;
			    }
			

			case ��ť4: //ö���Ӵ���
				{
					EnumChildWindows(���ھ��, EnumChildProc, lParam);//ö���Ӵ���
					break;
				}
			

			}
			break;
		}
	
	}
	switch (wParam)
	{
	case ID_40001: //�Ӳ˵�1
		{
			MessageBoxW(0, 0, 0, 0);
			break;
		}
	}

		return DefWindowProcW(���ھ��, uMsg, wParam, lParam); //��û�д������Ϣ���س�ȥ
}



int WINAPI WinMain(
	_in_ HINSTANCE hInstance,//Ӧ�ó���ǰʵ���ľ����
	_in_ HINSTANCE hPrevInstance,//Ӧ�ó���ǰʵ���ľ����
	_in_ LPSTR     lpCmdLine,//Ӧ�ó���������У���������������
	_in_ int       nShowCmd //���������ʾ���ڡ�
)
{

	//����һ��������
	WNDCLASSW wnd;
	memset(&wnd, 0, sizeof(WNDCLASSW));
	wnd.style = NULL;//���ڷ��
	wnd.lpfnWndProc = (WNDPROC)Wndproc;//���ڹ��̵Ļص�����
	wnd.hInstance = hInstance; //ʵ���ľ�������а�����Ĵ��ڹ��̡�
	wnd.hIcon = LoadIconW(hInstance, (LPCWSTR)IDI_ICON1); //��ͼ��ľ�����˳�Ա������ͼ����Դ�ľ��������ó�ԱΪNULL����ϵͳ�ṩһ��Ĭ��ͼ�ꡣ
	wnd.hCursor = LoadCursorW(hInstance, (LPCWSTR)IDC_CURSOR1); //���α�ľ�����˳�Ա�������α���Դ�ľ��������ó�ԱΪNULL��������ƶ���Ӧ�ó���Ĵ���ʱ��Ӧ�ó��������ʽ�����ù�����״��
	wnd.hbrBackground = CreateSolidBrush(RGB(255,255,255));//�౳��
	wnd.lpszMenuName = NULL; //��˵�����Դ��������Դ�ļ�����ʾ�����ơ�
	wnd.lpszClassName = L"��������"; //��������
	
	//ע�ᴰ����
	RegisterClassW(&wnd);

	//��������
	HWND ���ھ�� = 0; //�����Ĵ��ھ��
	HMENU �˵���� = LoadMenuW(hInstance,(LPCWSTR)IDR_MENU1);
	���ھ��= CreateWindowW(
		_in_  wnd.lpszClassName,//��������
		_in_  L"���ڱ���",//���ڱ���
		_in_  WS_OVERLAPPEDWINDOW,//���ڵ���ʽ�� 
		_in_  CW_USEDEFAULT,//���ڵĳ�ʼˮƽλ�á�
		_in_  0, //���ڵĳ�ʼ��ֱλ�á�
		_in_  CW_USEDEFAULT, //���ڵĿ��
		_in_  0, //���ڵĸ߶�
		_in_  NULL, //���ڴ����Ĵ��ڵĸ����ڻ������ߴ��ڵľ����
		_in_  �˵����, //�˵����������ݴ�����ʽָ���Ӵ��ڱ�ʶ����
		_in_  hInstance, //Ҫ�봰�ڹ�����ģ��ʵ���ľ����
		_in_  NULL //���Ӧ�ó������CreateWindow������MDI�ͻ��˴��ڣ�lpParamӦ��ָ��CLIENTCREATESTRUCT�ṹ
	);

	//��ʾ����
	ShowWindow(���ھ��, SW_SHOWNORMAL);
	


	//������Ϣ
	MSG msg;
	memset(&msg, 0, sizeof(MSG));
	BOOL bRet;
    while ((bRet = GetMessage(&msg, 0, 0, 0)) != 0) //��ȡ��Ϣ
	{
		if (bRet == -1)
		{
			// handle the error and possibly exit
		}
		else
		{
			
			TranslateMessage(&msg); //������Ϣ
			DispatchMessage(&msg);  //������Ϣ
		}
	}
}