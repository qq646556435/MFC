#include <iostream>
#include <windows.h>
using namespace std;
typedef int(*My_Add)(int, int);
int main()
{

	HMODULE DLL��� = LoadLibraryW(L"DLL��̬���ӿ�.dll");//��ȡģ����
	My_Add �ӷ� = (My_Add)GetProcAddress(DLL���, "Add"); //��ú�����ַ
	printf("%d\n", �ӷ�(1,2));
	return 0;
}

