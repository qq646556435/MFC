#include<windows.h>
#include "resource.h"
INT_PTR WINAPI Dlgproc(
	HWND �Ի�����, //�Ի���ľ����
	UINT uMsg, //��Ϣ��
	WPARAM wParam, //������Ϣ����Ϣ��
	LPARAM lParam //������Ϣ����Ϣ��
)
{

	switch (uMsg)
	{
		case WM_INITDIALOG: //�Ի��򴴽���Ϣ
		{
			MessageBoxW(�Ի�����, 0, 0, MB_OK);
			break;
		}
		case WM_CLOSE: //�Ի���ر���Ϣ
		{
			DestroyWindow(�Ի�����);
			PostQuitMessage(0);
		}

		default: //����û�д������Ϣ
		{
			return FALSE;
			break;
		}
	}
}
//�������
int WINAPI WinMain(
	_In_ HINSTANCE hInstance, //Ӧ�ó���ǰʵ���ľ����
	_In_ HINSTANCE hPrevInstance, //Ӧ�ó���ǰһ��ʵ���ľ����
	_In_ LPSTR     lpCmdLine, //Ӧ�ó���������У���������������
	_In_ int       nShowCmd //Ӧ�ó���������У���������������
)
{
	//������ģ̬�Ի���
	HWND �Ի����� = CreateDialogW(hInstance, (LPCTSTR)IDD_DIALOG1, NULL, Dlgproc);
	//��ʾ�Ի���
	ShowWindow(�Ի�����, SW_SHOWNOACTIVATE);
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

	return 0;
}