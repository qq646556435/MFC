#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "chs");
	//ɾ���ļ�
	//DeleteFileW(L"E:\\�½��ı��ĵ�.txt");
	
	//�����ļ�
	//CopyFileW(L"E:\\�½��ı��ĵ�.txt", L"F:\\�½��ı��ĵ�.txt", FALSE);

	//�½����ߴ��ļ����ҷ��ؾ��
// 	SECURITY_ATTRIBUTES ��ȫ������ = { 0 };
// 	��ȫ������.nLength = sizeof(SECURITY_ATTRIBUTES);
// 	��ȫ������.lpSecurityDescriptor = NULL;
// 	��ȫ������.bInheritHandle = TRUE;
// 	HANDLE �ļ���� = CreateFileW(L"E:\\�½��ı��ĵ�.txt", GENERIC_READ, FILE_SHARE_READ,&��ȫ������, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	
	//�ƶ��ļ�
	//MoveFileW(L"E:\\�½��ı��ĵ�.txt", L"F:\\�½��ı��ĵ�.txt");

	//���ļ� 
	//ReadFile();
	
	//д�ļ�
	//WriteFile();
	
	//��ȡ�ļ���С
// 	OFSTRUCT �ļ�����Ϣ = { 0 };
// 	HFILE ���ļ��ľ�� = OpenFile("E:\\�½��ı��ĵ�.txt", &�ļ�����Ϣ, OF_READWRITE);
// 	DWORD �ļ���С = 0;
// 	GetFileSize((HANDLE)���ļ��ľ��,&�ļ���С);
// 	
	//����Ŀ¼
	//CreateDirectoryW(L"E:\\11111", NULL);

	//��õ�ǰģ��ȫ·��
// 	WCHAR �ַ���Buffer[1024] = { 0 };
// 	HMODULE ָ����ģ���� = GetModuleHandleW(0); //��ȡָ��ģ����
// 	GetModuleFileNameW(ָ����ģ����, �ַ���Buffer, 1024);
// 	printf("%ls\n", �ַ���Buffer);

	//����ָ��Ŀ¼�µĵ�һ���ļ�
// 	WIN32_FIND_DATAW �ļ�����Ϣ = { 0 };
// 	HANDLE ������� = FindFirstFileW(L"E:\\*",&�ļ�����Ϣ);
// 	BOOL ��һ���ļ���Ϣ = 1;
// 	SYSTEMTIME �ļ�ʱ�� = { 0 };
// 	
// 	if (������� != INVALID_HANDLE_VALUE)
//     {
// 		while (��һ���ļ���Ϣ!=0)
// 		{
// 
// 			FileTimeToSystemTime(&�ļ�����Ϣ.ftCreationTime, &�ļ�ʱ��); //���ļ�ʱ��ת��Ϊ����ʱ��
// 			if (�ļ�����Ϣ.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN)
// 			{
// 
// 				printf("%ls %d �ļ�������\n ", �ļ�����Ϣ.cFileName, �ļ�ʱ��.wYear);
// 			}
// 			else
// 			{
// 				printf("%ls %d �ļ�û�б�����\n ", �ļ�����Ϣ.cFileName, �ļ�ʱ��.wYear);
// 			}
// 			��һ���ļ���Ϣ=FindNextFileW(�������, &�ļ�����Ϣ);
// 		}
// 	}

	//��ȡ�ļ���Ŀ¼����
	//GetFileAttributesExW();

	//�����ļ�����
	//SetFileAttributesW();

	//���ļ�ʱ��ת��Ϊ�����ļ�ʱ��
	//FileTimeToLocalFileTime();

	//�ر��ļ����
	//FindClose()
	return 0;
}