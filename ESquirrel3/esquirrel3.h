#pragma once


#include <Windows.h>
#include <oleauto.h>
#include "helper.h"
#include <squirrel.h>

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


#ifndef __E_STATIC_LIB

#define LIB_GUID_STR "FF07834EEC5D4E95B11BFF7CDF8C959B" /*GUID��: // {FF07834E-EC5D-4E95-B11B-FF7CDF8C959B} */
#define LIB_MajorVersion 1 /*�����汾��*/
#define LIB_MinorVersion 0 /*��ΰ汾��*/
#define LIB_BuildNumber 20170823 /*�����汾��*/
#define LIB_SysMajorVer 3 /*ϵͳ���汾��*/
#define LIB_SysMinorVer 0 /*ϵͳ�ΰ汾��*/
#define LIB_KrnlLibMajorVer 3 /*���Ŀ����汾��*/
#define LIB_KrnlLibMinorVer 0 /*���Ŀ�ΰ汾��*/
#define LIB_NAME_STR "����ű�֧�ֿ�" /*֧�ֿ���*/
#define LIB_DESCRIPTION_STR "squirrel3��װ" /*��������*/
#define LIB_Author "kyozy" /*��������*/
#define LIB_ZipCode "644000" /*��������*/
#define LIB_Address "" /*ͨ�ŵ�ַ*/
#define LIB_Phone	"" /*�绰����*/
#define LIB_Fax		"75602718" /*QQ����*/
#define LIB_Email	 "" /*��������*/
#define LIB_HomePage "" /*��ҳ��ַ*/
#define LIB_Other	"" /*������Ϣ*/
#define LIB_TYPE_COUNT 11 /*�����������*/
#define LIB_TYPE_STR	"0000�����\0" \
						"0000����\0" \
						"0000ջ����\0" \
						"0000���󴴽��ʹ���\0" \
						"0000�������\0" \
						"0000����\0" \
						"0000ԭʼ�������\0" \
						"0000��������\0" \
						"0000���л�\0" \
						"0000�ڴ����\0" \
						"0000����\0" \
						"\0" /*�������*/
#endif

typedef void(CALLBACK *ESQPRINTFUNCTION)(HSQUIRRELVM, const SQChar *);
typedef void(CALLBACK *ESQCOMPILERERROR)(HSQUIRRELVM, const SQChar * /*desc*/, const SQChar * /*source*/, SQInteger /*line*/, SQInteger /*column*/);