#include <iostream>
#include <windows.h>
#include <Tlhelp32.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "chs");
// 	STARTUPINFO ������Ϣ = {0};  //����������
// 	PROCESS_INFORMATION �����߳���Ϣ = { 0 }; //���������´����Ľ��̼������̵߳���Ϣ��
// 	CreateProcessW(L"C:\\Users\\2303132\\Desktop\\PETools_downcc\\PETools.exe",NULL, NULL, NULL,TRUE,0,NULL, NULL ,&������Ϣ,&�����߳���Ϣ);
// 
// 	CloseHandle(�����߳���Ϣ.hThread);
// 	CloseHandle(�����߳���Ϣ.hProcess);
// 
// 	//��ô��ھ��
	HWND PETools���ھ�� = FindWindowW(L"#32770",L"PE Tools v1.5 Xmas �汾 - by NEOx/[uinC], http://www.uinc.ru/ cao_cong����");
	
	//��ȡ����PID
	DWORD PETools����Pid = 0;
	GetWindowThreadProcessId(PETools���ھ��, &PETools����Pid);
	
	//��һ�����̻�ȡ�ý��̾��
	HANDLE PETools���̾�� = OpenProcess(PROCESS_ALL_ACCESS, TRUE, PETools����Pid);
	

	//��ָֹ���Ľ���
	//TerminateProcess(PETools���̾��, 0);

	//�������̿���
	MODULEENTRY32 ָ���Ľ�����Ϣ = { 0 };//�����б���Ϣ�ṹ��
	ָ���Ľ�����Ϣ.dwSize = sizeof(MODULEENTRY32);
	HANDLE PETools���̿��վ�� = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, PETools����Pid);//��ÿ��վ��
	BOOL PETools��һ��ģ����Ϣ = Module32FirstW(PETools���̿��վ��, &ָ���Ľ�����Ϣ);//��һ��������Ϣ
	
	
		while (PETools��һ��ģ����Ϣ)
		{
			printf("%ls\n", ָ���Ľ�����Ϣ.szModule);
			PETools��һ��ģ����Ϣ = Module32NextW(PETools���̿��վ��, &ָ���Ľ�����Ϣ); //��һ��������Ϣ
		}
	
	return 0;
}