#include <iostream>
#include <windows.h>
using namespace std;
typedef int(*My_Add)(int, int);
int main()
{

	HMODULE DLL句柄 = LoadLibraryW(L"DLL动态链接库.dll");//获取模块句柄
	My_Add 加法 = (My_Add)GetProcAddress(DLL句柄, "Add"); //获得函数地址
	printf("%d\n", 加法(1,2));
	return 0;
}

