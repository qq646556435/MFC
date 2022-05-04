#include <iostream>
#include <windows.h>
#include "resource.h"
using namespace std;

//(创建对话框模板的回调函数) 处理接收到的消息
INT_PTR CALLBACK DialogProc(HWND 对话框句柄, UINT 消息, WPARAM wParam, LPARAM lParam)
{
	//开始处理消息
	switch (消息)
	{
		case WM_COPYDATA:
		{
			COPYDATASTRUCT* 拷贝数据 = (COPYDATASTRUCT*)lParam;
		}
		case WM_CLOSE : //接收到对话框关闭的消息
		{
			EndDialog(对话框句柄,0);
			break;
		}
		default: //处理没有剩余的消息
		{
			return FALSE;
			break;

		}
	}
}

//程序入口
int WINAPI WinMain(
	HINSTANCE hInstance,      // 实力句柄
	HINSTANCE hPrevInstance,  // 废弃不用
	LPSTR lpCmdLine,          // 命令行
	int nCmdShow              // 显示窗口的方式
)
{
	//创建对话框模板
	DialogBoxW(hInstance, (LPCWSTR)IDD_DIALOG1,NULL, DialogProc);

	return 0;
}
