#pragma once

#include <Windows.h>
#include <oleauto.h>

#ifndef __E_STATIC_LIB

#define LIB_GUID_STR "FB41C2BE2B4349F1B187D8CE15D3F292" /*GUID串: // {FB41C2BE-2B43-49F1-B187-D8CE15D3F292}*/
#define LIB_MajorVersion 1 /*库主版本号*/
#define LIB_MinorVersion 0 /*库次版本号*/
#define LIB_BuildNumber 20170802 /*构建版本号*/
#define LIB_SysMajorVer 3 /*系统主版本号*/
#define LIB_SysMinorVer 0 /*系统次版本号*/
#define LIB_KrnlLibMajorVer 3 /*核心库主版本号*/
#define LIB_KrnlLibMinorVer 0 /*核心库次版本号*/
#define LIB_NAME_STR "EZipUtils" /*支持库名*/
#define LIB_DESCRIPTION_STR "ZIP压缩解压操作支持库" /*功能描述*/
#define LIB_Author "kyozy" /*作者名称*/
#define LIB_ZipCode "644000" /*邮政编码*/
#define LIB_Address "" /*通信地址*/
#define LIB_Phone	"" /*电话号码*/
#define LIB_Fax		"75602718" /*QQ号码*/
#define LIB_Email	 "" /*电子邮箱*/
#define LIB_HomePage "" /*主页地址*/
#define LIB_Other	"" /*其它信息*/
#define LIB_TYPE_COUNT 0 /*命令分类数量*/
#define LIB_TYPE_STR "0000基本命令\0""\0" /*命令分类*/
#endif

struct ZipStruct
{
	HZIP m_hZip;
};

#pragma pack(4)
struct ZipInfoStruct
{
	int index;
	LPTSTR name;
	int attr;
	double atime;
	double ctime;
	double mtime;
	int comp_size; 
	int unc_size;
};
#pragma pack()
#define DTP_ZIPINFO		MAKELONG(1,0)