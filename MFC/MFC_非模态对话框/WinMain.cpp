#include <windows.h>
#include "resource.h"
//(����ģ��Ի���Ļص�����)
//������Ϣ
INT_PTR  WINAPI Dlgproc(
	HWND �Ի�����,//�Ի���ľ����
	UINT uMsg,   //��Ϣ
	WPARAM wParam,//��Ϣ����Ϣ
	LPARAM lParam //��Ϣ����Ϣ
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
			EndDialog(�Ի�����, NULL);
		}

		case WM_COMMAND: //�ؼ���Ϣ
		{
			WORD �ؼ���ʶ�� = LOWORD(wParam);
			switch (�ؼ���ʶ��)
			{
				case IDC_BUTTON1: //��ť1
				{
					MessageBoxW(�Ի�����, L"��ť1������", L"��ʾ", MB_OK);
				    break;
				}
				case IDC_BUTTON2: //��ť2
				{
					MessageBoxW(�Ի�����, L"��ť2������", L"��ʾ", MB_OK);
					break;
				}
				case IDC_CHECK1: //��ѡ��1
				{
					if (IDC_CHECK1 == 1)
					{
						MessageBoxW(�Ի�����, L"��ѡ��1������", L"��ʾ", MB_OK);
					}
					break;
				}
				case IDC_CHECK2: //��ѡ��2
				{
					MessageBoxW(�Ի�����, L"��ѡ��2������", L"��ʾ", MB_OK);
					break;
				}
				case IDC_CHECK3: //��ѡ��3
				{
					MessageBoxW(�Ի�����, L"��ѡ��3������", L"��ʾ", MB_OK);
					break;
				}

			}
			break;
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
	//����ģ��Ի���
	DialogBoxW(hInstance, (LPCTSTR)IDD_DIALOG1, NULL, Dlgproc);
	
	return 0;
}