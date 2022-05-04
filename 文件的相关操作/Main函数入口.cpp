#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "chs");
	//删除文件
	//DeleteFileW(L"E:\\新建文本文档.txt");
	
	//复制文件
	//CopyFileW(L"E:\\新建文本文档.txt", L"F:\\新建文本文档.txt", FALSE);

	//新建或者打开文件并且返回句柄
// 	SECURITY_ATTRIBUTES 安全描述符 = { 0 };
// 	安全描述符.nLength = sizeof(SECURITY_ATTRIBUTES);
// 	安全描述符.lpSecurityDescriptor = NULL;
// 	安全描述符.bInheritHandle = TRUE;
// 	HANDLE 文件句柄 = CreateFileW(L"E:\\新建文本文档.txt", GENERIC_READ, FILE_SHARE_READ,&安全描述符, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	
	//移动文件
	//MoveFileW(L"E:\\新建文本文档.txt", L"F:\\新建文本文档.txt");

	//读文件 
	//ReadFile();
	
	//写文件
	//WriteFile();
	
	//获取文件大小
// 	OFSTRUCT 文件的信息 = { 0 };
// 	HFILE 打开文件的句柄 = OpenFile("E:\\新建文本文档.txt", &文件的信息, OF_READWRITE);
// 	DWORD 文件大小 = 0;
// 	GetFileSize((HANDLE)打开文件的句柄,&文件大小);
// 	
	//创建目录
	//CreateDirectoryW(L"E:\\11111", NULL);

	//获得当前模块全路径
// 	WCHAR 字符串Buffer[1024] = { 0 };
// 	HMODULE 指定的模块句柄 = GetModuleHandleW(0); //获取指定模块句柄
// 	GetModuleFileNameW(指定的模块句柄, 字符串Buffer, 1024);
// 	printf("%ls\n", 字符串Buffer);

	//查找指定目录下的第一个文件
// 	WIN32_FIND_DATAW 文件的信息 = { 0 };
// 	HANDLE 搜索句柄 = FindFirstFileW(L"E:\\*",&文件的信息);
// 	BOOL 下一个文件信息 = 1;
// 	SYSTEMTIME 文件时间 = { 0 };
// 	
// 	if (搜索句柄 != INVALID_HANDLE_VALUE)
//     {
// 		while (下一个文件信息!=0)
// 		{
// 
// 			FileTimeToSystemTime(&文件的信息.ftCreationTime, &文件时间); //将文件时间转换为本地时间
// 			if (文件的信息.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN)
// 			{
// 
// 				printf("%ls %d 文件被隐藏\n ", 文件的信息.cFileName, 文件时间.wYear);
// 			}
// 			else
// 			{
// 				printf("%ls %d 文件没有被隐藏\n ", 文件的信息.cFileName, 文件时间.wYear);
// 			}
// 			下一个文件信息=FindNextFileW(搜索句柄, &文件的信息);
// 		}
// 	}

	//获取文件或目录属性
	//GetFileAttributesExW();

	//设置文件属性
	//SetFileAttributesW();

	//将文件时间转换为本地文件时间
	//FileTimeToLocalFileTime();

	//关闭文件句柄
	//FindClose()
	return 0;
}