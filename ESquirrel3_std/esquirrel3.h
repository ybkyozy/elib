#pragma once


#include <Windows.h>
#include <oleauto.h>
#include "helper.h"
#include <squirrel.h>
#include <sqstdio.h>
#include <sqstdaux.h>
#include <sqstdblob.h>
#include <sqstdmath.h>
#include <sqstdstring.h>
#include <sqstdsystem.h>

#ifndef EPRINT_CALLBACK
#define EPRINT_CALLBACK	1
#endif

#ifndef EERROR_CALLBACK
#define EERROR_CALLBACK	2
#endif

#ifndef ECMPILERERROR_CALLBACK
#define ECMPILERERROR_CALLBACK	3
#endif

#define SETUP_VM(x)	HSQUIRRELVM vm = ((HSQUIRRELVM)x[0].m_int)

#define DTP_SQFUNCTION_INFO		MAKELONG(1,0)
#define DTP_SQSTACK_INFO		MAKELONG(2,0)

#ifndef __E_STATIC_LIB

#define LIB_GUID_STR "FF07834EEC5D4E95B11BFF7CDF8C959B" /*GUID串: // {FF07834E-EC5D-4E95-B11B-FF7CDF8C959B} */
#define LIB_MajorVersion 1 /*库主版本号*/
#define LIB_MinorVersion 0 /*库次版本号*/
#define LIB_BuildNumber 20170823 /*构建版本号*/
#define LIB_SysMajorVer 3 /*系统主版本号*/
#define LIB_SysMinorVer 0 /*系统次版本号*/
#define LIB_KrnlLibMajorVer 3 /*核心库主版本号*/
#define LIB_KrnlLibMinorVer 0 /*核心库次版本号*/
#define LIB_NAME_STR "松鼠脚本支持库" /*支持库名*/
#define LIB_DESCRIPTION_STR "squirrel3封装，含标准库" /*功能描述*/
#define LIB_Author "kyozy" /*作者名称*/
#define LIB_ZipCode "644000" /*邮政编码*/
#define LIB_Address "" /*通信地址*/
#define LIB_Phone	"" /*电话号码*/
#define LIB_Fax		"75602718" /*QQ号码*/
#define LIB_Email	 "" /*电子邮箱*/
#define LIB_HomePage "" /*主页地址*/
#define LIB_Other	"" /*其它信息*/
#define LIB_TYPE_COUNT 11 /*命令分类数量*/
#define LIB_TYPE_STR	"0000虚拟机\0" \
						"0000编译\0" \
						"0000栈操作\0" \
						"0000对象创建和处理\0" \
						"0000对象操作\0" \
						"0000调用\0" \
						"0000原始对象操作\0" \
						"0000垃圾回收\0" \
						"0000序列化\0" \
						"0000调试\0" \
						"0000标准库\0" \
						"\0" /*命令分类*/
#endif