#include <windows.h>
#include "resource.h"
//(创建模板对话框的回调函数)
//处理消息
INT_PTR  WINAPI Dlgproc(
	HWND 对话框句柄,//对话框的句柄。
	UINT uMsg,   //消息
	WPARAM wParam,//消息的信息
	LPARAM lParam //消息的信息
)
{
	switch (uMsg)
	{
		case WM_INITDIALOG: //对话框创建消息
		{
			MessageBoxW(对话框句柄, 0, 0, MB_OK);
			break;
		}
		case WM_CLOSE: //对话框关闭消息
		{
			EndDialog(对话框句柄, NULL);
		}

		case WM_COMMAND: //控件消息
		{
			WORD 控件标识符 = LOWORD(wParam);
			switch (控件标识符)
			{
				case IDC_BUTTON1: //按钮1
				{
					MessageBoxW(对话框句柄, L"按钮1被单击", L"提示", MB_OK);
				    break;
				}
				case IDC_BUTTON2: //按钮2
				{
					MessageBoxW(对话框句柄, L"按钮2被单击", L"提示", MB_OK);
					break;
				}
				case IDC_CHECK1: //单选框1
				{
					if (IDC_CHECK1 == 1)
					{
						MessageBoxW(对话框句柄, L"单选框1被单击", L"提示", MB_OK);
					}
					break;
				}
				case IDC_CHECK2: //单选框2
				{
					MessageBoxW(对话框句柄, L"单选框2被单击", L"提示", MB_OK);
					break;
				}
				case IDC_CHECK3: //单选框3
				{
					MessageBoxW(对话框句柄, L"单选框3被单击", L"提示", MB_OK);
					break;
				}

			}
			break;
		}

		default: //返回没有处理的消息
		{
			return FALSE;
			break;
		}
	}

}
//程序入口
int WINAPI WinMain(
	_In_ HINSTANCE hInstance, //应用程序当前实例的句柄。
	_In_ HINSTANCE hPrevInstance, //应用程序前一个实例的句柄。
	_In_ LPSTR     lpCmdLine, //应用程序的命令行，不包括程序名。
	_In_ int       nShowCmd //应用程序的命令行，不包括程序名。
)
{
	//创建模板对话框
	DialogBoxW(hInstance, (LPCTSTR)IDD_DIALOG1, NULL, Dlgproc);
	
	return 0;
}