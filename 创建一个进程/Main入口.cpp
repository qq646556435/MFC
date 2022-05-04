#include <iostream>
#include <windows.h>
#include <Tlhelp32.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "chs");
// 	STARTUPINFO 启动信息 = {0};  //主窗口属性
// 	PROCESS_INFORMATION 进程线程信息 = { 0 }; //包含关于新创建的进程及其主线程的信息。
// 	CreateProcessW(L"C:\\Users\\2303132\\Desktop\\PETools_downcc\\PETools.exe",NULL, NULL, NULL,TRUE,0,NULL, NULL ,&启动信息,&进程线程信息);
// 
// 	CloseHandle(进程线程信息.hThread);
// 	CloseHandle(进程线程信息.hProcess);
// 
// 	//获得窗口句柄
	HWND PETools窗口句柄 = FindWindowW(L"#32770",L"PE Tools v1.5 Xmas 版本 - by NEOx/[uinC], http://www.uinc.ru/ cao_cong汉化");
	
	//获取进程PID
	DWORD PETools进程Pid = 0;
	GetWindowThreadProcessId(PETools窗口句柄, &PETools进程Pid);
	
	//打开一个进程获取该进程句柄
	HANDLE PETools进程句柄 = OpenProcess(PROCESS_ALL_ACCESS, TRUE, PETools进程Pid);
	

	//终止指定的进程
	//TerminateProcess(PETools进程句柄, 0);

	//创建进程快照
	MODULEENTRY32 指定的进程信息 = { 0 };//进程列表信息结构体
	指定的进程信息.dwSize = sizeof(MODULEENTRY32);
	HANDLE PETools进程快照句柄 = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, PETools进程Pid);//获得快照句柄
	BOOL PETools第一条模块信息 = Module32FirstW(PETools进程快照句柄, &指定的进程信息);//第一个进程信息
	
	
		while (PETools第一条模块信息)
		{
			printf("%ls\n", 指定的进程信息.szModule);
			PETools第一条模块信息 = Module32NextW(PETools进程快照句柄, &指定的进程信息); //下一条进程信息
		}
	
	return 0;
}