#include <iostream>
#include <windows.h>
#include "resource.h"
using namespace std;

//(�����Ի���ģ��Ļص�����) ������յ�����Ϣ
INT_PTR CALLBACK DialogProc(HWND �Ի�����, UINT ��Ϣ, WPARAM wParam, LPARAM lParam)
{
	//��ʼ������Ϣ
	switch (��Ϣ)
	{
		case WM_COPYDATA:
		{
			COPYDATASTRUCT* �������� = (COPYDATASTRUCT*)lParam;
		}
		case WM_CLOSE : //���յ��Ի���رյ���Ϣ
		{
			EndDialog(�Ի�����,0);
			break;
		}
		default: //����û��ʣ�����Ϣ
		{
			return FALSE;
			break;

		}
	}
}

//�������
int WINAPI WinMain(
	HINSTANCE hInstance,      // ʵ�����
	HINSTANCE hPrevInstance,  // ��������
	LPSTR lpCmdLine,          // ������
	int nCmdShow              // ��ʾ���ڵķ�ʽ
)
{
	//�����Ի���ģ��
	DialogBoxW(hInstance, (LPCWSTR)IDD_DIALOG1,NULL, DialogProc);

	return 0;
}
