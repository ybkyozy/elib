#pragma once

#include <windows.h>
#include "string.h"
#include <algorithm>

char* zy_vsprint(const char* fmt, ...);
char* zy_clone_text(const char* text);
char* zy_clone_textlen(const char* text, int len);

class CFreqMem
{
private:
	unsigned char* m_pdata;
	size_t m_datalen, m_bufferlen;
public:
	CFreqMem()
	{
		m_pdata = NULL; m_datalen = m_bufferlen = 0;
	}
	void* GetPtr()
	{
		return (m_datalen == 0 ? NULL : m_pdata);
	}
	void AddDWord(DWORD dw)
	{
		AppendData(&dw, sizeof(dw));
	}
	void AppendData(void* pdata, size_t size)
	{
		if (m_bufferlen - m_datalen < size)
		{
			if (m_pdata == NULL)
			{
				m_bufferlen = 128;
				m_pdata = (unsigned char*)malloc(m_bufferlen);
				//assert(m_datalen == 0);
			}
			while (m_bufferlen - m_datalen < size)
			{
				m_bufferlen *= 2;
			};
			m_pdata = (unsigned char*)realloc(m_pdata, m_bufferlen);
		}
		memcpy(m_pdata + m_datalen, pdata, size);
		m_datalen += size;
	}
};