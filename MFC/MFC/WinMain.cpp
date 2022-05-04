#include <iostream>
#include <windows.h>
#include <CommCtrl.h>
#include"resource.h"
#include "杂项.h"
#define _in_ 
#define _out_
#define 按钮1 0x100
#define 按钮2 0x101
#define 按钮3 0x102
#define 按钮4 0x103
#define 编辑框1 0x200
//(//枚举子窗口的回调函数)枚举子窗口
BOOL CALLBACK EnumChildProc(_In_ HWND   hwnd,_In_ LPARAM lParam)
{
	WCHAR Buffer[100] = { 0 };
	GetWindowTextW(hwnd, Buffer, 100);
	调试输出(L"%ls\n", Buffer);
	
	return TRUE;
}
//(创建一个窗口类的回调函数)接收消息并处理消息
LRESULT Wndproc(HWND 窗口句柄,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	HMODULE 当前窗口的实例句柄 = GetModuleHandleW(0);
	RECT 父窗口的窗口信息 = { 0 };
	static HWND 编辑框1的句柄 = NULL;
	static HWND a = NULL;


	switch (uMsg)
	{

	case WM_CREATE://窗口创建消息
		 {
			a = CreateWindowW(L"BUTTON", L"按钮1_移动按钮1窗口", WS_CHILD | WS_VISIBLE, 20, 20, 200, 40, 窗口句柄, (HMENU)按钮1, 当前窗口的实例句柄, 0);
			CreateWindowW(L"BUTTON", L"按钮2_获取编辑框1.内容", WS_CHILD | WS_VISIBLE, 20, 80, 200, 40, 窗口句柄, (HMENU)按钮2, 当前窗口的实例句柄, 0);
			CreateWindowW(L"BUTTON", L"按钮3_设置编辑框1.内容", WS_CHILD | WS_VISIBLE, 20, 140, 200, 40, 窗口句柄, (HMENU)按钮3, 当前窗口的实例句柄, 0);
			CreateWindowW(L"BUTTON", L"按钮4_枚举子窗口", WS_CHILD | WS_VISIBLE, 20, 200, 200, 40, 窗口句柄, (HMENU)按钮4, 当前窗口的实例句柄, 0);
			CreateWindowW(L"EDIT", L"编辑框1.内容1111", WS_CHILD | WS_BORDER | WS_VISIBLE, 20, 500, 200, 40, 窗口句柄, (HMENU)编辑框1, 当前窗口的实例句柄, 0);
			编辑框1的句柄 = GetDlgItem(窗口句柄, 编辑框1); //获取指定控件编辑框1的句柄;
			break;
		 }
	case WM_CLOSE: //窗口关闭消息
		{
			MessageBoxW(窗口句柄, L"窗口关闭了", L"提示", MB_OK);
			DestroyWindow(窗口句柄);//销毁窗口
			PostQuitMessage(0); //发送退出消息
			break;
		}

	case WM_COMMAND: //通用控件消息
		{
			WORD 控件标识符 = LOWORD(wParam);
			switch (控件标识符)
			{
			case 按钮1: //移动按钮1窗口
				{
					GetClientRect(窗口句柄, &父窗口的窗口信息); //获得父窗口的矩形信息
					int 随机坐标x = rand() % (父窗口的窗口信息.right - 200);
					int 随机坐标y = rand() % (父窗口的窗口信息.bottom - 40);
					MoveWindow(a, 随机坐标x, 随机坐标y, 200, 40, TRUE); //移动窗口
					break;
				}
			

			case 按钮2: //获取编辑框1的内容

				{	WCHAR Buffer[100] = { 0 };

					GetWindowTextW(编辑框1的句柄, Buffer, 100);     //获取编辑框1的内容
					MessageBoxW(窗口句柄, Buffer, L"提示", MB_OK);
					break;

				}
				

			case 按钮3: //设置编辑框1的内容
				{

					SetWindowTextW(编辑框1的句柄, L"新内容"); //设置编辑框1的内容
					break;
			    }
			

			case 按钮4: //枚举子窗口
				{
					EnumChildWindows(窗口句柄, EnumChildProc, lParam);//枚举子窗口
					break;
				}
			

			}
			break;
		}
	
	}
	switch (wParam)
	{
	case ID_40001: //子菜单1
		{
			MessageBoxW(0, 0, 0, 0);
			break;
		}
	}

		return DefWindowProcW(窗口句柄, uMsg, wParam, lParam); //把没有处理的消息返回出去
}



int WINAPI WinMain(
	_in_ HINSTANCE hInstance,//应用程序当前实例的句柄。
	_in_ HINSTANCE hPrevInstance,//应用程序当前实例的句柄。
	_in_ LPSTR     lpCmdLine,//应用程序的命令行，不包括程序名。
	_in_ int       nShowCmd //控制如何显示窗口。
)
{

	//创建一个窗口类
	WNDCLASSW wnd;
	memset(&wnd, 0, sizeof(WNDCLASSW));
	wnd.style = NULL;//窗口风格
	wnd.lpfnWndProc = (WNDPROC)Wndproc;//窗口过程的回调函数
	wnd.hInstance = hInstance; //实例的句柄，其中包含类的窗口过程。
	wnd.hIcon = LoadIconW(hInstance, (LPCWSTR)IDI_ICON1); //类图标的句柄。此成员必须是图标资源的句柄。如果该成员为NULL，则系统提供一个默认图标。
	wnd.hCursor = LoadCursorW(hInstance, (LPCWSTR)IDC_CURSOR1); //类游标的句柄。此成员必须是游标资源的句柄。如果该成员为NULL，当鼠标移动到应用程序的窗口时，应用程序必须显式地设置光标的形状。
	wnd.hbrBackground = CreateSolidBrush(RGB(255,255,255));//类背景
	wnd.lpszMenuName = NULL; //类菜单的资源名，如资源文件中显示的名称。
	wnd.lpszClassName = L"窗口类名"; //窗口类名
	
	//注册窗口类
	RegisterClassW(&wnd);

	//创建窗口
	HWND 窗口句柄 = 0; //创建的窗口句柄
	HMENU 菜单句柄 = LoadMenuW(hInstance,(LPCWSTR)IDR_MENU1);
	窗口句柄= CreateWindowW(
		_in_  wnd.lpszClassName,//窗口类名
		_in_  L"窗口标题",//窗口标题
		_in_  WS_OVERLAPPEDWINDOW,//窗口的样式。 
		_in_  CW_USEDEFAULT,//窗口的初始水平位置。
		_in_  0, //窗口的初始垂直位置。
		_in_  CW_USEDEFAULT, //窗口的宽度
		_in_  0, //窗口的高度
		_in_  NULL, //正在创建的窗口的父窗口或所有者窗口的句柄。
		_in_  菜单句柄, //菜单句柄，或根据窗口样式指定子窗口标识符。
		_in_  hInstance, //要与窗口关联的模块实例的句柄。
		_in_  NULL //如果应用程序调用CreateWindow来创建MDI客户端窗口，lpParam应该指向CLIENTCREATESTRUCT结构
	);

	//显示窗口
	ShowWindow(窗口句柄, SW_SHOWNORMAL);
	


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
}