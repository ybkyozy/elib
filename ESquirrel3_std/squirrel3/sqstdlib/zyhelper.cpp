#include "zyhelper.h"
#include <stdio.h>
#include "sqconfig.h"

void zy_printf(HSQUIRRELVM vm, SQPRINTFUNCTION fp, const SQChar* fmt, ...)
{
	int len = 1024;
	SQChar* buff = new SQChar[len];
	va_list args;
	va_start(args, fmt);
	len = scvsprintf(buff, len, fmt, args);
	if (len < 0)
	{
		return;
	}
	if (len >= 1024)
	{
		buff = new SQChar[len + 1];
		len = scvsprintf(buff,len, fmt, args);
	}
	va_end(args);
	buff[len] = _SC('\0');
	fp(vm, buff);
	delete[] buff;
}

