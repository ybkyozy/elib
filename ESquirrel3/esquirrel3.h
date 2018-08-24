#pragma once


#include <Windows.h>
#include <oleauto.h>
#include "helper.h"

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
#define LIB_DESCRIPTION_STR "squirrel3封装" /*功能描述*/
#define LIB_Author "kyozy" /*作者名称*/
#define LIB_ZipCode "644000" /*邮政编码*/
#define LIB_Address "" /*通信地址*/
#define LIB_Phone	"" /*电话号码*/
#define LIB_Fax		"75602718" /*QQ号码*/
#define LIB_Email	 "" /*电子邮箱*/
#define LIB_HomePage "" /*主页地址*/
#define LIB_Other	"" /*其它信息*/
#define LIB_TYPE_COUNT 1 /*命令分类数量*/
#define LIB_TYPE_STR "0000虚拟机\0""\0" /*命令分类*/
#endif

