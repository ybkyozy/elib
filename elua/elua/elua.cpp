// esquirrel3.cpp : Defines the entry point for the DLL application.
//

#include "elua.h"

#include "elib_sdk/lib2.h"
#include "elib_sdk/lang.h"
#include "elib_sdk/fnshare.h"
#include "elib_sdk/fnshare.cpp"


/************************************************************************/
/* ��������
/************************************************************************/
#ifndef __E_STATIC_LIB
LIB_CONST_INFO s_ConstInfo[] =
{
	/* { ��������, Ӣ������, ����˵��, �����ȼ�(LVL_), ��������(CT_), �ı�����, ��ֵ���� }   ֻ��������������*/
	{ _WT("LUA����_δ֪"), _WT("LUA_TNONE"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_TNONE },
	{ _WT("LUA����_��"), _WT("LUA_TNIL"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_TNIL },
	{ _WT("LUA����_�߼�"), _WT("LUA_TBOOLEAN"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_TBOOLEAN },
	{ _WT("LUA����_�û�ָ��"), _WT("LUA_TLIGHTUSERDATA"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_TLIGHTUSERDATA },
	{ _WT("LUA����_��ֵ"), _WT("LUA_TNUMBER"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_TNUMBER },
	{ _WT("LUA����_�ı�"), _WT("LUA_TSTRING"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_TSTRING },
	{ _WT("LUA����_��"), _WT("LUA_TTABLE"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_TTABLE },
	{ _WT("LUA����_����"), _WT("LUA_TFUNCTION"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_TFUNCTION },
	{ _WT("LUA����_�û�����"), _WT("LUA_TUSERDATA"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_TUSERDATA },
	{ _WT("LUA����_�߳�"), _WT("LUA_TTHREAD"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_TTHREAD },
};

#endif


#ifndef __E_STATIC_LIB

// ���� 
ARG_INFO s_arg_lua[] =
{
	/* { ��������, ��������, ͼ������, ͼ������, ��������(�μ�SDT_), Ĭ����ֵ, �������(�μ�AS_) } */
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_newstate[] =
{
	/* { ��������, ��������, ͼ������, ͼ������, ��������(�μ�SDT_), Ĭ����ֵ, �������(�μ�AS_) } */
	{ _WT("�ڴ�������ص�����"), _WT("����ֵ�������ͣ������� �û����ݣ������� ָ�룬������ Դ��С�������� �´�С��"),0,0, _SDT_ALL, 0, NULL },
	{ _WT("�û�����"), _WT("�ṩ���ص������Ĳ���"),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};


// ������Ϣ
static CMD_INFO s_CmdInfo[] =
{
	/* { ��������, Ӣ������, ��������, �������(-1���������͵ķ���), ����״̬(CT_), ��������(SDT_), ��ֵ����, ����ȼ�(LVL_), ͼ������, ͼ������, ��������, ������Ϣ } */

	//////////////////////////////////////////////////////////////////////////�����
	{
		/*ccname*/	_WT("LUA_�½�״̬"),
		/*egname*/	_WT("lua_newstate"),
		/*explain*/ _WT("����һ�����߳�״̬��ʧ�ܷ���0"),
		/*category*/cmd_type_idx_state_manipulation,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_newstate) / sizeof(s_arg_lua_newstate[0]),
		/*arg lp*/	s_arg_lua_newstate,
	},
	{
		/*ccname*/	_WT("LUA_�ر�"),
		/*egname*/	_WT("lua_close"),
		/*explain*/ _WT("�ر�״̬"),
		/*category*/cmd_type_idx_state_manipulation,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua) / sizeof(s_arg_lua[0]),
		/*arg lp*/	s_arg_lua,
	},
};
#endif



EXTERN_C void elua_fn_lua_newstate(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = (INT)lua_newstate((lua_Alloc)pArgInf[0].m_dwSubCodeAdr, (void*)pArgInf[1].m_int);
}

EXTERN_C void elua_fn_lua_close(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	lua_close((lua_State*)pArgInf[0].m_int);
}


#ifndef __E_STATIC_LIB
PFN_EXECUTE_CMD s_RunFunc[] =	// ����Ӧ��s_CmdInfo�е������˳���Ӧ
{
	elua_fn_lua_newstate,
	elua_fn_lua_close,
};

static const char* const g_CmdNames[] =
{
	"elua_fn_lua_newstate",
	"elua_fn_lua_close",
};

#endif


/************************************************************************/
/* �������Ͷ���
/************************************************************************/

//#ifndef __E_STATIC_LIB
//
//
//LIB_DATA_TYPE_ELEMENT s_dt_element[] =
//{
//	/*{ ��Ա���� ,�����Ա , �������� ,Ӣ������ ,��Ա���� ,��Ա״̬ ,Ĭ��ֵ}*/
//	//{ SDT_INT, NULL,_WT("test"), _WT("test"), _WT("test"), 0, 0 },
//
//};
//
//
//static LIB_DATA_TYPE_INFO s_DataTypes[] =
//{
//	/* { ��������, Ӣ������, ��������, ��������, ��������, ����״̬, ͼ������, �¼�����, �¼�ָ��, ��������, ����ָ��, ����ָ��, Ԫ������, Ԫ��ָ�� } */
//	//{ _WT("testinfo"), _WT("testinfo"), _WT("testinfo"), 0, NULL, NULL, 0, 0, NULL, 0, NULL, NULL, sizeof(s_dt_element) / sizeof(s_dt_element[0]), s_dt_element },
//};
//#endif

EXTERN_C INT WINAPI  elua_ProcessNotifyLib(INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
#ifndef __E_STATIC_LIB
	if (nMsg == NL_GET_CMD_FUNC_NAMES) // ������������ʵ�ֺ����ĵĺ�����������(char*[]), ֧�־�̬����Ķ�̬����봦��
		return (INT)g_CmdNames;
	else if (nMsg == NL_GET_NOTIFY_LIB_FUNC_NAME) // ���ش���ϵͳ֪ͨ�ĺ�������(PFN_NOTIFY_LIB��������), ֧�־�̬����Ķ�̬����봦��
		return (INT)"elua_ProcessNotifyLib";
	else if (nMsg == NL_GET_DEPENDENT_LIBS) return NULL;
	// ���ؾ�̬����������������̬���ļ����б�(��ʽΪ\0�ָ����ı�,��β����\0), ֧�־�̬����Ķ�̬����봦��
	// kernel32.lib user32.lib gdi32.lib �ȳ��õ�ϵͳ�ⲻ��Ҫ���ڴ��б���
	// ����NULL��NR_ERR��ʾ��ָ�������ļ�  
#endif
	return ProcessNotifyLib(nMsg, dwParam1, dwParam2);
};

#ifndef __E_STATIC_LIB
static LIB_INFO s_LibInfo =
{
		LIB_FORMAT_VER,				//���ʽ��
		_T(LIB_GUID_STR),			//GUID
		LIB_MajorVersion,			//��������汾��
		LIB_MinorVersion,			//����Ĵΰ汾��
		LIB_BuildNumber,			//�����汾��
		LIB_SysMajorVer,			//����Ҫ��������ϵͳ�����汾��
		LIB_SysMinorVer,			//����Ҫ��������ϵͳ�Ĵΰ汾��
		LIB_KrnlLibMajorVer,		//����Ҫ��ϵͳ����֧�ֿ�����汾��
		LIB_KrnlLibMinorVer,		//����Ҫ��ϵͳ����֧�ֿ�Ĵΰ汾��
		_T(LIB_NAME_STR),			//����
		__GBK_LANG_VER,				//����֧�ֵ�����
		_WT(LIB_DESCRIPTION_STR),	//����ϸ����
		
#ifndef __COMPILE_FNR			//״̬
		/*dwState*/				_LIB_OS(__OS_WIN),
#else
		/*dwState*/				LBS_NO_EDIT_INFO | _LIB_OS(__OS_WIN) | LBS_LIB_INFO2,
#endif	
		
		_WT(LIB_Author),			//����
		_WT(LIB_ZipCode),			//��������
		NULL,				//ͨ�ŵ�ַ
		NULL,				//�绰����
		NULL,				//����
		NULL,				//�����ַ
		NULL,				//��ҳ
		NULL,				//������Ϣ
		
		//�Զ�����������
		0,
		NULL,
		//���˵��
#ifndef __COMPILE_FNR
		/*CategoryCount*/   LIB_TYPE_COUNT,			// ���������Ӵ�ֵ��
		/*category*/       	_WT(LIB_TYPE_STR),			// ���˵����ÿ��Ϊһ�ַ���,ǰ��λ���ֱ�ʾͼ��������(��1��ʼ,0��).
		/*CmdCount*/        sizeof(s_CmdInfo) / sizeof(s_CmdInfo[0]),
		/*BeginCmd*/        s_CmdInfo,
#else
		// fnr�汾����Ҫ������Ϣ
		/*CategoryCount*/   0,
		/*category*/        NULL,
		/*CmdCount*/        0,
		/*BeginCmd*/        NULL,
#endif
		/*m_pCmdsFunc*/             s_RunFunc,
		/*pfnRunAddInFn*/			NULL,
		/*szzAddInFnInfo*/			NULL,
		
		/*pfnNotify*/				elua_ProcessNotifyLib,
		
		/*pfnRunSuperTemplate*/		NULL,
		/*szzSuperTemplateInfo*/	NULL,
		
#ifndef __COMPILE_FNR
		/*nLibConstCount*/			sizeof(s_ConstInfo)/ sizeof(s_ConstInfo[0]),
		/*pLibConst*/				s_ConstInfo,
#else
		// fnr�汾����Ҫ������Ϣ
		/*nLibConstCount*/			0,
		/*pLibConst*/				NULL,
#endif
		
		/*szzDependFiles*/			NULL
		
};

PLIB_INFO WINAPI GetNewInf()
{
	return (&s_LibInfo);
};

#endif