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
#define LIB_TYPE_COUNT 1 /*命令分类数量*/
#define LIB_TYPE_STR	"0000状态操作\0" \
						"\0" /*命令分类*/


#define cmd_type_idx_state_manipulation	1

#endif

//#define DTP_STRUCT1		MAKELONG(1,0)
//#define DTP_STRUCT2		MAKELONG(2,0)