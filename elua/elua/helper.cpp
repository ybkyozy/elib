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

char* zy_clone_text(const char* text)
{
	if (text == NULL || *text == '\0')
		return NULL;

	INT nTextLen = strlen(text);
	char* pd = (char*)malloc(nTextLen + 1);
	memcpy(pd, text, nTextLen);
	pd[nTextLen] = '\0';
	return pd;
}

char* zy_clone_textlen(const char* text, int len)
{
	if (text == NULL || *text == '\0')
		return NULL;

	char* pd = (char*)malloc(len + 1);
	memcpy(pd, text, len);
	pd[len] = '\0';
	return pd;
}
