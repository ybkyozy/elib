#pragma once

#include <WTypes.h>
#include <Windows.h>
#include <oleauto.h>

#ifndef __E_STATIC_LIB

#define LIB_GUID_STR "FB41C2BE2B4349F1B187D8CE15D3F292" /*GUID��: // {FB41C2BE-2B43-49F1-B187-D8CE15D3F292}*/
#define LIB_MajorVersion 1 /*�����汾��*/
#define LIB_MinorVersion 0 /*��ΰ汾��*/
#define LIB_BuildNumber 20170802 /*�����汾��*/
#define LIB_SysMajorVer 3 /*ϵͳ���汾��*/
#define LIB_SysMinorVer 0 /*ϵͳ�ΰ汾��*/
#define LIB_KrnlLibMajorVer 3 /*���Ŀ����汾��*/
#define LIB_KrnlLibMinorVer 0 /*���Ŀ�ΰ汾��*/
#define LIB_NAME_STR "EZipUtils" /*֧�ֿ���*/
#define LIB_DESCRIPTION_STR "ZIPѹ����ѹ����֧�ֿ�" /*��������*/
#define LIB_Author "kyozy" /*��������*/
#define LIB_ZipCode "644000" /*��������*/
#define LIB_Address "" /*ͨ�ŵ�ַ*/
#define LIB_Phone	"" /*�绰����*/
#define LIB_Fax		"75602718" /*QQ����*/
#define LIB_Email	 "" /*��������*/
#define LIB_HomePage "" /*��ҳ��ַ*/
#define LIB_Other	"" /*������Ϣ*/
#define LIB_TYPE_COUNT 0 /*�����������*/
#define LIB_TYPE_STR "0000��������\0""\0" /*�������*/
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