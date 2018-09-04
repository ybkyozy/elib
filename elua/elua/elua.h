#pragma once

#include <Windows.h>
#include <lua.hpp>


#ifndef __E_STATIC_LIB

#define LIB_GUID_STR "69D738519E1D44BE9466AFA2ED770D5F" /*GUID串: {69D73851-9E1D-44BE-9466-AFA2ED770D5F} */
#define LIB_MajorVersion 1 /*库主版本号*/
#define LIB_MinorVersion 0 /*库次版本号*/
#define LIB_BuildNumber 0 /*构建版本号*/
#define LIB_SysMajorVer 3 /*系统主版本号*/
#define LIB_SysMinorVer 0 /*系统次版本号*/
#define LIB_KrnlLibMajorVer 3 /*核心库主版本号*/
#define LIB_KrnlLibMinorVer 0 /*核心库次版本号*/
#define LIB_NAME_STR "Lua脚本支持库" /*支持库名*/
#define LIB_DESCRIPTION_STR "封装lua脚本，实现程序和脚本交互" /*功能描述*/
#define LIB_Author "kyozy" /*作者名称*/
#define LIB_ZipCode "644000" /*邮政编码*/
#define LIB_Address "" /*通信地址*/
#define LIB_Phone	"" /*电话号码*/
#define LIB_Fax		"75602718" /*QQ号码*/
#define LIB_Email	 "" /*电子邮箱*/
#define LIB_HomePage "" /*主页地址*/
#define LIB_Other	"" /*其它信息*/
#define LIB_TYPE_COUNT 14 /*命令分类数量*/
#define LIB_TYPE_STR	"0000状态操作\0" \
						"0000基本栈操作\0" \
						"0000访问操作\0" \
						"0000比较和算术操作\0" \
						"0000压栈操作\0" \
						"0000取值操作\0" \
						"0000赋值操作\0" \
						"0000载入和运行操作\0" \
						"0000协程操作\0" \
						"0000垃圾回收\0" \
						"0000杂项操作\0" \
						"0000实用函数\0" \
						"0000调试接口\0" \
						"0000辅助库\0" \
						"\0" /*命令分类*/


#define cmd_type_idx_state_manipulation						1
#define cmd_type_idx_basic_stack_manipulation				2
#define cmd_type_idx_access_functions						3
#define cmd_type_idx_comparison_and_arithmetic_functions	4
#define cmd_type_idx_push_functions							5
#define cmd_type_idx_get_functions							6
#define cmd_type_idx_set_functions							7
#define cmd_type_idx_load_and_call_functions				8
#define cmd_type_idx_coroutine_functions					9
#define cmd_type_idx_gc_functions							10
#define cmd_type_idx_miscellaneous_functions				11
#define cmd_type_idx_useful_functions						12
#define cmd_type_idx_debug_functions						13
#define cmd_type_idx_auxiliary_library						14

#endif

#define DTP_LUA_DEBUG		MAKELONG(1,0)
//#define DTP_STRUCT2		MAKELONG(2,0)

#ifndef SETUP_LUA_STATE
#define	SETUP_LUA_STATE(x)	lua_State * L = (lua_State *)x[0].m_int
#endif