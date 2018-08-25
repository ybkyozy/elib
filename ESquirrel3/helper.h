#pragma once
#pragma warning(disable : 4786)
#include <windows.h>
#include <map>
#include "squirrel.h"

typedef void(CALLBACK *ESQPRINTFUNCTION)(HSQUIRRELVM, const SQChar *);

extern std::map<INT, INT> g_sqPtrMap;

void* zy_stdcall_to_cdecl(void* pStdcall, int num_args);
void zy_stdcall_to_cdecl_free(void* pCdecl);
void* zy_get_map_ptr(std::map<INT, INT>& ptr_map, INT key, int num_args);
INT zy_get_map_key(std::map<INT, INT>& ptr_map, INT value);
SQChar* zy_vsprint(const SQChar* fmt, ...);
