#include<windows.h>
#include "resource.h"
INT_PTR WINAPI Dlgproc(
	HWND 对话框句柄, //对话框的句柄。
	UINT uMsg, //消息。
	WPARAM wParam, //附加消息的信息。
	LPARAM lParam //附加消息的信息。
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
			DestroyWindow(对话框句柄);
			PostQuitMessage(0);
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
	//创建非模态对话框
	HWND 对话框句柄 = CreateDialogW(hInstance, (LPCTSTR)IDD_DIALOG1, NULL, Dlgproc);
	//显示对话框
	ShowWindow(对话框句柄, SW_SHOWNOACTIVATE);
	//发送消息
	MSG msg;
	memset(&msg, 0, sizeof(MSG));
	BOOL bRet;
	while ((bRet = GetMessage(&msg, 0, 0, 0)) != 0) //获取消息
	{
		if (bRet == -1)
		{
			// handle the error and possibly exit
		}
		else
		{

			TranslateMessage(&msg); //翻译消息
			DispatchMessage(&msg);  //发送消息
		}
	}

	return 0;
}