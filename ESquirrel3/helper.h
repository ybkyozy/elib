#pragma once
#pragma warning(disable : 4786)
#include <windows.h>
#include <map>

extern std::map<INT, INT> g_sqPtrMap;

void* stdcall_to_cdecl(void* pStdcall, int num_args);
void stdcall_to_cdecl_free(void* pCdecl);
void* get_map_ptr(std::map<INT, INT>& ptr_map, INT key);

