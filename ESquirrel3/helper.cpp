#include "helper.h"
#include "string.h"

void* helper::stdcall_to_cdecl(void* pStdcall, int num_args)
{
	LPVOID pCdecl = ::VirtualAlloc(NULL, 12 + 6 * num_args, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	if(!pCdecl)
	{
		return NULL;
	}
	static unsigned char header[] = { 85, 139, 236, 184 };
	static unsigned char push[] = { 255, 181 };
	static unsigned char call[] = { 255, 208, 93, 195 };

	unsigned char* ptr = (unsigned char*)pCdecl;

	memcpy(ptr, header, 4);
	ptr += 4;
	memcpy(ptr, pStdcall, sizeof(void*));
	ptr += 4;

	for (int i = 0; i < num_args; ++i)
	{
		int idx = (num_args - i) * sizeof(int) + sizeof(int);
		memcpy(ptr, push, 2);
		ptr += 2;
		memcpy(ptr, &idx, sizeof(int));
		ptr += sizeof(int);
	}
	memcpy(ptr, call, 4);
	return pStdcall;
}

void helper::stdcall_to_cdecl_free(void* pCdecl)
{
	VirtualFree(pCdecl, 0, MEM_RELEASE);
}
