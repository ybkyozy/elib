#include "helper.h"


char* zy_vsprint(const char* fmt, ...)
{
	static char buff[1024];
	int i;
	va_list args;
	va_start(args, fmt);
	i = wvsprintf(buff, fmt, args);
	buff[i] = '\0';
	va_end(args);
	return buff;
}


