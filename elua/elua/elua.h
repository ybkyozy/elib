#pragma once

#include <Windows.h>
#include <lua.hpp>


#ifndef __E_STATIC_LIB

#define LIB_GUID_STR "69D738519E1D44BE9466AFA2ED770D5F" /*GUID��: {69D73851-9E1D-44BE-9466-AFA2ED770D5F} */
#define LIB_MajorVersion 1 /*�����汾��*/
#define LIB_MinorVersion 0 /*��ΰ汾��*/
#define LIB_BuildNumber 0 /*�����汾��*/
#define LIB_SysMajorVer 3 /*ϵͳ���汾��*/
#define LIB_SysMinorVer 0 /*ϵͳ�ΰ汾��*/
#define LIB_KrnlLibMajorVer 3 /*���Ŀ����汾��*/
#define LIB_KrnlLibMinorVer 0 /*���Ŀ�ΰ汾��*/
#define LIB_NAME_STR "Lua�ű�֧�ֿ�" /*֧�ֿ���*/
#define LIB_DESCRIPTION_STR "��װlua�ű���ʵ�ֳ���ͽű�����" /*��������*/
#define LIB_Author "kyozy" /*��������*/
#define LIB_ZipCode "644000" /*��������*/
#define LIB_Address "" /*ͨ�ŵ�ַ*/
#define LIB_Phone	"" /*�绰����*/
#define LIB_Fax		"75602718" /*QQ����*/
#define LIB_Email	 "" /*��������*/
#define LIB_HomePage "" /*��ҳ��ַ*/
#define LIB_Other	"" /*������Ϣ*/
#define LIB_TYPE_COUNT 14 /*�����������*/
#define LIB_TYPE_STR	"0000״̬����\0" \
						"0000����ջ����\0" \
						"0000���ʲ���\0" \
						"0000�ȽϺ���������\0" \
						"0000ѹջ����\0" \
						"0000ȡֵ����\0" \
						"0000��ֵ����\0" \
						"0000��������в���\0" \
						"0000Э�̲���\0" \
						"0000��������\0" \
						"0000�������\0" \
						"0000ʵ�ú���\0" \
						"0000���Խӿ�\0" \
						"0000������\0" \
						"\0" /*�������*/


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