#include <iostream>
#include <windows.h>
using namespace std;
#pragma comment(lib,"DLL¶¯Ì¬Á´½Ó¿â.lib")
extern"C" int Add(int In_a, int In_b);
extern"C" int Sub(int , int );
int main()
{
	printf("%d\n",Add(1, 2));
	printf("%d\n", Sub(10, 5));



	return 0;
}