#include "ÔÓÏî.h"
void µ÷ÊÔÊä³ö(LPCWSTR format, ...)
{
	WCHAR wchar_Buff[100] = { 0 };
	va_list arglist;
	va_start(arglist, format);
	wvsprintfW(wchar_Buff, format, arglist);
	va_end(arglist);
	OutputDebugStringW(wchar_Buff);
}