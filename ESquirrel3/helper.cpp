#include "helper.h"


void * zy_stdcall_to_cdecl(void * pStdcall, int num_args)
{
	LPVOID pCdecl = ::VirtualAlloc(NULL, 14 + 6 * num_args, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	if (!pCdecl)
	{
		return NULL;
	}
	static unsigned char header[] = { 85, 137, 229, 184 };
	static unsigned char push[] = { 255, 117 };
	static unsigned char call[] = { 255, 208, 137, 236, 93, 195 };

	unsigned char* ptr = (unsigned char*)pCdecl;
	
	memcpy(ptr, header, 4); // push ebp ; mov ebp,esp
	ptr += 4;
	memcpy(ptr, pStdcall, sizeof(void*)); //mov eax,lpfunction
	ptr += 4;

	for (int i = 0; i < num_args; i++)
	{
		UINT idx = (num_args - i) * 4 + 4;
		memcpy(ptr, push, 2);
		ptr += 2;
		memcpy(ptr, &idx, sizeof(int)); // push [ebp+4+(num_args -i)*4]
		ptr += 4;
	}
	memcpy(ptr, call, 6); //call eax ; mov esp,ebp ; pop ebp; ret
	return pStdcall;
}

void zy_stdcall_to_cdecl_free(void * pCdecl)
{
	VirtualFree(pCdecl, 0, MEM_RELEASE);
}

void* zy_get_map_ptr(std::map<INT, INT>& ptr_map, INT key, int num_args)
{
	void* hook = NULL;
	if (key == 0)
	{
		return hook;
	}
	std::map<INT, INT>::iterator iter = ptr_map.find(key);
	if (iter != ptr_map.end())
	{
		hook = (void*)iter->second;
	}
	else
	{
		hook = zy_stdcall_to_cdecl((LPVOID)key, num_args);
		g_sqPtrMap[key] = (INT)hook;
	}
	return hook;
}

class zyFinder
{
public:
	zyFinder(const INT cmp_value) :value_(cmp_value) {}
	bool operator ()(const std::map<INT, INT>::value_type &item)
	{
		return item.second == value_;
	}
private:
	INT value_;
};

INT zy_get_map_key(std::map<INT, INT>& ptr_map, INT value)
{
	std::map<INT, INT>::iterator find_item = std::find_if(ptr_map.begin(), ptr_map.end(), zyFinder(value));

	INT key = 0;
	if (find_item != ptr_map.end())
	{
		key = (*find_item).first;
	}
	return key;
}

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
