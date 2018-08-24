#pragma once
#include <windows.h>

class helper
{
public:
	static void* stdcall_to_cdecl(void* pStdcall, int num_args);
	static void stdcall_to_cdecl_free(void* pCdecl);

};

