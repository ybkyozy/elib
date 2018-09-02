// esquirrel3.cpp : Defines the entry point for the DLL application.
//

#include "elua.h"

#include "elib_sdk/lib2.h"
#include "elib_sdk/lang.h"
#include "elib_sdk/fnshare.h"
#include "elib_sdk/fnshare.cpp"

#include "helper.h"


/************************************************************************/
/* ��������
/************************************************************************/
#ifndef __E_STATIC_LIB
LIB_CONST_INFO s_ConstInfo[] =
{
	/* { ��������, Ӣ������, ����˵��, �����ȼ�(LVL_), ��������(CT_), �ı�����, ��ֵ���� }   ֻ��������������*/
	{ _WT("LUA_OK"), _WT("LUA_OK"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OK },
	{ _WT("LUA_YIELD"), _WT("LUA_YIELD"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_YIELD },
	{ _WT("LUA_ERRRUN"), _WT("LUA_ERRRUN"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_ERRRUN },
	{ _WT("LUA_ERRSYNTAX"), _WT("LUA_ERRSYNTAX"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_ERRSYNTAX },
	{ _WT("LUA_ERRMEM"), _WT("LUA_ERRMEM"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_ERRMEM },
	{ _WT("LUA_ERRGCMM"), _WT("LUA_ERRGCMM"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_ERRGCMM },
	{ _WT("LUA_ERRERR"), _WT("LUA_ERRERR"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_ERRERR },

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

	{ _WT("LUA������_��"), _WT("LUA_OPADD +"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPADD },
	{ _WT("LUA������_��"), _WT("LUA_OPSUB -"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPSUB },
	{ _WT("LUA������_��"), _WT("LUA_OPMUL *"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPMUL },
	{ _WT("LUA������_����"), _WT("LUA_OPMOD %"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPMOD },
	{ _WT("LUA������_��η�"), _WT("LUA_OPPOW ^"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPPOW },
	{ _WT("LUA������_��"), _WT("LUA_OPDIV /"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPDIV },
	{ _WT("LUA������_����"), _WT("LUA_OPIDIV //"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPIDIV },
	{ _WT("LUA������_λ��"), _WT("LUA_OPBAND &"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPBAND },
	{ _WT("LUA������_λ��"), _WT("LUA_OPBOR |"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPBOR },
	{ _WT("LUA������_λ���"), _WT("LUA_OPBXOR ~"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPBXOR },
	{ _WT("LUA������_����"), _WT("LUA_OPSHL <<"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPSHL },
	{ _WT("LUA������_����"), _WT("LUA_OPSHR >>"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPSHR },
	{ _WT("LUA������_��"), _WT("LUA_OPUNM -"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPUNM },
	{ _WT("LUA������_λȡ��"), _WT("LUA_OPBNOT ~"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPBNOT },

	{ _WT("LUA�Ƚ�_���"), _WT("LUA_OPEQ ="), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPEQ },
	{ _WT("LUA�Ƚ�_С��"), _WT("LUA_OPLT <"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPLT },
	{ _WT("LUA�Ƚ�_С�ڵ���"), _WT("LUA_OPLE <="), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPLE },
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
	{ _WT("�ڴ�������ص�����"), _WT("����ֵ�������ͣ������� �û����ݣ������� ָ�룬������ Դ��С�������� �´�С��"),0,0, _SDT_ALL, 0, NULL },
	{ _WT("�û�����"), _WT("�ṩ���ص������Ĳ���"),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_lua_atpanic[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("�������ص�����"), _WT("����ֵ�������ͣ������� Lua״̬��"),0,0, _SDT_ALL, 0, NULL },
};
ARG_INFO s_arg_lua_idx[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_rotate[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("��ת����"), _WT(""),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_copy[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("Դջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("Ŀ��ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_checkstack[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("�������"), _WT("Ҫ���ʣ��ռ������"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_xmove[] =
{
	{ _WT("ԴLua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("Ŀ��Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������"), _WT("Ҫ����ֵ������"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_typename[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("����"), _WT("'LUA����_'��ͷ����"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_lua_tonumberx[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("�Ƿ���ֵ"), _WT("����'ջ����'ָ����ֵ�Ƿ�Ϊ��ֵ"),0,0, SDT_BOOL, 0, AS_DEFAULT_VALUE_IS_EMPTY | AS_RECEIVE_VAR },
};

ARG_INFO s_arg_lua_arith[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("������"), _WT("'LUA������_'��ͷ����"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_rawequal[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����1"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����2"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_compare[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����1"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����2"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("�Ƚϲ���"), _WT("'LUA�Ƚ�_'��ͷ����"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_lua_pushnumber[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("��ֵ"), _WT("Ҫѹ�����ֵ"),0,0, SDT_DOUBLE, 0, NULL },
};
ARG_INFO s_arg_lua_pushinteger[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("����"), _WT("Ҫѹ�������"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_pushlstring[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("�ı�"), _WT("Ҫѹ����ı�"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("����"), _WT("Ҫѹ��ĳ���"),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_lua_pushvfstring[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("��ʽ���ı�"), _WT("��ʽ���ı�"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("����"), _WT("��ʽ���ı��еĲ�����ֻ���ǻ�����������"),0,0, _SDT_ALL, 0, NULL },
};
ARG_INFO s_arg_lua_pushcclosure[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("���غ���"), _WT("����ֵ�������ͣ������� Lua״̬��"),0,0, _SDT_ALL, 0, NULL },
	{ _WT("�û�ֵ����"), _WT("����������>0 (���ǲ���>256)������ջ�е���n��ֵ��Ϊ�հ����û�ֵ�������غ���������ʱ���Ի�ȡ��Щֵ��"),0,0, SDT_INT, 0, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_lua_pushboolean[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("�߼�ֵ"), _WT("Ҫѹ����߼�ֵ"),0,0, SDT_BOOL, 0, NULL },
};
ARG_INFO s_arg_lua_pushlightuserdata[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("�û�ָ��"), _WT("Ҫѹ����û�ָ��"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_lua_pushthread[] =
{
	{ _WT("�߳�"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_lua_getglobal[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("����"), _WT(""),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_lua_getfield[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("����"), _WT(""),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_lua_geti[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("��Ա����"), _WT(""),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_rawgetp[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("�û�ָ��"), _WT(""),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_createtable[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("�����С"), _WT("������鲿�ֳ�ʼ��С"),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
	{ _WT("��ϣ��С"), _WT("��Ĺ�ϣ���ֳ�ʼ��С"),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_lua_newuserdata[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("��С"), _WT("�ֽ�Ϊ��λ"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_callk[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������"), _WT(""),0,0, SDT_INT, 0, NULL },
	{ _WT("����ֵ����"), _WT("�������Ϊ-1�������з���ֵ����ѹ�뵽ջ��"),0,0, SDT_INT, -1, AS_HAS_DEFAULT_VALUE },
	{ _WT("��������������"), _WT("lua_KContext"),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
	{ _WT("��������"), _WT("����ֵ�������ͣ������� Lua״̬�������� status�������� �����ģ�"),0,0, _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_lua_call[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������"), _WT(""),0,0, SDT_INT, 0, NULL },
	{ _WT("����ֵ����"), _WT("�������Ϊ-1�������з���ֵ����ѹ�뵽ջ��"),0,0, SDT_INT, -1, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_lua_pcallk[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������"), _WT(""),0,0, SDT_INT, 0, NULL },
	{ _WT("����ֵ����"), _WT("�������Ϊ-1�������з���ֵ����ѹ�뵽ջ��"),0,0, SDT_INT, -1, AS_HAS_DEFAULT_VALUE },
	{ _WT("������հ�ջ����"), _WT("ָ����Ϊ������ıհ���ջ�е�����"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������������"), _WT("lua_KContext"),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
	{ _WT("��������"), _WT("����ֵ�������ͣ������� Lua״̬�������� status�������� �����ģ�"),0,0, _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_lua_pcall[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������"), _WT(""),0,0, SDT_INT, 0, NULL },
	{ _WT("����ֵ����"), _WT("�������Ϊ-1�������з���ֵ����ѹ�뵽ջ��"),0,0, SDT_INT, -1, AS_HAS_DEFAULT_VALUE },
	{ _WT("������հ�ջ����"), _WT("ָ����Ϊ������ıհ���ջ�е�����"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_load[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("��ȡ����"), _WT("����ֵ��������[ָ��] �������� Lua״̬�������� �û����ݣ�������[�ο�] ��С��"),0,0, SDT_INT, 0, NULL },
	{ _WT("��ȡ�����û�����"), _WT("���ݸ���ȡ�����Ĳ���"),0,0, SDT_INT, 0, AS_HAS_DEFAULT_VALUE },
	{ _WT("������"), _WT("���ڴ�����Ϣ�͵�����Ϣ"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("ģʽ"), _WT("binary��text ?"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_lua_dump[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("д������"), _WT("����ֵ�������� �������� Lua״̬�������� ���ݣ������� ��С�������� �û����ݣ�"),0,0, SDT_INT, 0, NULL },
	{ _WT("д�������û�����"), _WT("���ݸ�д�������Ĳ���"),0,0, SDT_INT, 0, AS_HAS_DEFAULT_VALUE },
	{ _WT("������������Ϣ"), _WT("���Ϊ�棬��ת���Ķ����ƿ鲻����������Ϣ"),0,0, SDT_BOOL, 1, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_lua_yieldk[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("����ֵ����"), _WT("���ظ� LUA_���� �ķ���ֵ����"),0,0, SDT_INT, 0, AS_HAS_DEFAULT_VALUE },
	{ _WT("��������������"), _WT("lua_KContext"),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
	{ _WT("��������"), _WT("����ֵ�������ͣ������� Lua״̬�������� status�������� �����ģ�"),0,0, _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_lua_resume[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("�߳�"), _WT("���ڻָ���Э���߳�"),0,0, SDT_INT, 0, AS_HAS_DEFAULT_VALUE },
	{ _WT("��������"), _WT(""),0,0, SDT_INT, 0, NULL },
};



// ������Ϣ
static CMD_INFO s_CmdInfo[] =
{
	/* { ��������, Ӣ������, ��������, �������(-1���������͵ķ���), ����״̬(CT_), ��������(SDT_), ��ֵ����, ����ȼ�(LVL_), ͼ������, ͼ������, ��������, ������Ϣ } */

	//////////////////////////////////////////////////////////////////////////״̬����
	{
		/*ccname*/	_WT("LUA_�½�"),
		/*egname*/	_WT("lua_newstate"),
		/*explain*/ _WT("����һ�����߳�ִ��״̬���ɹ�����lua_Stateָ�룬ʧ�ܷ���0"),
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
	{
		/*ccname*/	_WT("LUA_�½��߳�"),
		/*egname*/	_WT("lua_close"),
		/*explain*/ _WT("����һ�����̣߳�ѹ�뵽ջ�У����ҷ���lua_Stateָ�롣\r\n�˺������ص����߳���ԭʼ�̹߳�����ȫ�ֻ����������ж�����ִ��ջ������Ҫ��ʾ�ر�����"),
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
	{
		/*ccname*/	_WT("LUA_�ñ�������"),
		/*egname*/	_WT("lua_atpanic"),
		/*explain*/ _WT("����һ���µı���������������֮ǰ���õ��Ǹ���"),
		/*category*/cmd_type_idx_state_manipulation,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_atpanic) / sizeof(s_arg_lua_atpanic[0]),
		/*arg lp*/	s_arg_lua_atpanic,
	},
	{
		/*ccname*/	_WT("LUA_ȡ�汾"),
		/*egname*/	_WT("lua_version"),
		/*explain*/ _WT("���ذ汾��"),
		/*category*/cmd_type_idx_state_manipulation,
		/*state*/	0,
		/*ret*/		SDT_DOUBLE,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua) / sizeof(s_arg_lua[0]),
		/*arg lp*/	s_arg_lua,
	},
	//////////////////////////////////////////////////////////////////////////����ջ����
	{
		/*ccname*/	_WT("LUA_ȡ��������"),
		/*egname*/	_WT("lua_absindex"),
		/*explain*/ _WT("������'ջ����'ת��Ϊ������ջ���ľ�������"),
		/*category*/cmd_type_idx_basic_stack_manipulation,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_idx) / sizeof(s_arg_lua_idx[0]),
		/*arg lp*/	s_arg_lua_idx,
	},
	{
		/*ccname*/	_WT("LUA_ȡջ��"),
		/*egname*/	_WT("lua_gettop"),
		/*explain*/ _WT("����ջ�ж���Ԫ�ص���������Ϊ������1��ʼ�����Դ˽������ջ��Ԫ�ص�����; �������0��ʾ�ն�ջ��"),
		/*category*/cmd_type_idx_basic_stack_manipulation,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua) / sizeof(s_arg_lua[0]),
		/*arg lp*/	s_arg_lua,
	},
	{
		/*ccname*/	_WT("LUA_��ջ��"),
		/*egname*/	_WT("lua_settop"),
		/*explain*/ _WT("����ջ������Ϊָ�������������ջ�����ھ�ջ��������Ԫ�ؽ����Ϊnil�� �������Ϊ0����ɾ������ջԪ�ء�"),
		/*category*/cmd_type_idx_basic_stack_manipulation,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_idx) / sizeof(s_arg_lua_idx[0]),
		/*arg lp*/	s_arg_lua_idx,
	},
	{
		/*ccname*/	_WT("LUA_ѹ��ֵ"),
		/*egname*/	_WT("lua_pushvalue"),
		/*explain*/ _WT("��ָ��������Ԫ�صĸ���ѹ�뵽ջ�С�"),
		/*category*/cmd_type_idx_basic_stack_manipulation,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_idx) / sizeof(s_arg_lua_idx[0]),
		/*arg lp*/	s_arg_lua_idx,
	},
	{
		/*ccname*/	_WT("LUA_��ת"),
		/*egname*/	_WT("lua_rotate"),
		/*explain*/ _WT("����Ч'ջ����'��ջ��֮����תԪ�ء�\r\nԪ����ջ��������תn��Ԫ�أ���ջ�׷�����תn��-n��Ԫ�ء�"),
		/*category*/cmd_type_idx_basic_stack_manipulation,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_rotate) / sizeof(s_arg_lua_rotate[0]),
		/*arg lp*/	s_arg_lua_rotate,
	},
	{
		/*ccname*/	_WT("LUA_����"),
		/*egname*/	_WT("lua_copy"),
		/*explain*/ _WT("��'Դջ����'Ԫ�ظ��Ƶ�'Ŀ��ջ����',�滻��λ�õ�ֵ������λ�õ�ֵ����Ӱ�졣"),
		/*category*/cmd_type_idx_basic_stack_manipulation,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_copy) / sizeof(s_arg_lua_copy[0]),
		/*arg lp*/	s_arg_lua_copy,
	},
	{
		/*ccname*/	_WT("LUA_���ջ"),
		/*egname*/	_WT("lua_checkstack"),
		/*explain*/ _WT("ȷ��ջ������n�������۵Ŀռ䣨Ҳ����˵�������԰�ȫ�ؽ�n��ֵ�������У��� ������޷����������򷵻ؼ�"),
		/*category*/cmd_type_idx_basic_stack_manipulation,
		/*state*/	0,
		/*ret*/		SDT_BOOL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_checkstack) / sizeof(s_arg_lua_checkstack[0]),
		/*arg lp*/	s_arg_lua_checkstack,
	},
	{
		/*ccname*/	_WT("LUA_����"),
		/*egname*/	_WT("lua_xmove"),
		/*explain*/ _WT("����ͬ״̬�Ĳ�ͬ�߳�֮�佻��ֵ�� �˺�����Դջ�е���n��ֵ����������ѹ�뵽Ŀ��ջ�С�"),
		/*category*/cmd_type_idx_basic_stack_manipulation,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_xmove) / sizeof(s_arg_lua_xmove[0]),
		/*arg lp*/	s_arg_lua_xmove,
	},
	//////////////////////////////////////////////////////////////////////////���ʺ�����ջ->�ף�
	{
		/*ccname*/	_WT("LUA_�Ƿ���ֵ"),
		/*egname*/	_WT("lua_isnumber"),
		/*explain*/ _WT("���'ջ����'λ������ֵ�����ת��Ϊ��ֵ�����棬���򷵻ؼ١�"),
		/*category*/cmd_type_idx_access_functions,
		/*state*/	0,
		/*ret*/		SDT_BOOL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_idx) / sizeof(s_arg_lua_idx[0]),
		/*arg lp*/	s_arg_lua_idx,
	},
	{
		/*ccname*/	_WT("LUA_�Ƿ��ı�"),
		/*egname*/	_WT("lua_isstring"),
		/*explain*/ _WT("���'ջ����'λ�����ı������ת��Ϊ�ı�����ֵ�����棬���򷵻ؼ١�"),
		/*category*/cmd_type_idx_access_functions,
		/*state*/	0,
		/*ret*/		SDT_BOOL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_idx) / sizeof(s_arg_lua_idx[0]),
		/*arg lp*/	s_arg_lua_idx,
	},
	{
		/*ccname*/	_WT("LUA_�Ƿ񱾵غ���"),
		/*egname*/	_WT("lua_iscfunction"),
		/*explain*/ _WT("���'ջ����'λ���Ǳ��غ��������棬���򷵻ؼ١�"),
		/*category*/cmd_type_idx_access_functions,
		/*state*/	0,
		/*ret*/		SDT_BOOL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_idx) / sizeof(s_arg_lua_idx[0]),
		/*arg lp*/	s_arg_lua_idx,
	},
	{
		/*ccname*/	_WT("LUA_�Ƿ�����"),
		/*egname*/	_WT("lua_isinteger"),
		/*explain*/ _WT("���'ջ����'λ�������������棬���򷵻ؼ١�"),
		/*category*/cmd_type_idx_access_functions,
		/*state*/	0,
		/*ret*/		SDT_BOOL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_idx) / sizeof(s_arg_lua_idx[0]),
		/*arg lp*/	s_arg_lua_idx,
	},
	{
		/*ccname*/	_WT("LUA_�Ƿ��û�����"),
		/*egname*/	_WT("lua_isuserdata"),
		/*explain*/ _WT("���'ջ����'λ�����û����ݣ��û����� �� �û�ָ�룩�����棬���򷵻ؼ١�"),
		/*category*/cmd_type_idx_access_functions,
		/*state*/	0,
		/*ret*/		SDT_BOOL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_idx) / sizeof(s_arg_lua_idx[0]),
		/*arg lp*/	s_arg_lua_idx,
	},
	{
		/*ccname*/	_WT("LUA_ȡ����"),
		/*egname*/	_WT("lua_type"),
		/*explain*/ _WT("����'ջ����'λ�õ�ֵ���ͣ�'LUA����_'��ͷ����"),
		/*category*/cmd_type_idx_access_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_idx) / sizeof(s_arg_lua_idx[0]),
		/*arg lp*/	s_arg_lua_idx,
	},
	{
		/*ccname*/	_WT("LUA_ȡ������"),
		/*egname*/	_WT("lua_typename"),
		/*explain*/ _WT("����ָ�����͵��ı�����"),
		/*category*/cmd_type_idx_access_functions,
		/*state*/	0,
		/*ret*/		SDT_TEXT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_typename) / sizeof(s_arg_lua_typename[0]),
		/*arg lp*/	s_arg_lua_typename,
	},
	{
		/*ccname*/	_WT("LUA_����ֵX"),
		/*egname*/	_WT("lua_tonumberx"),
		/*explain*/ _WT("����ջ������λ�õ�ֵת��Ϊ˫����С���͡�"),
		/*category*/cmd_type_idx_access_functions,
		/*state*/	0,
		/*ret*/		SDT_DOUBLE,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_tonumberx) / sizeof(s_arg_lua_tonumberx[0]),
		/*arg lp*/	s_arg_lua_tonumberx,
	},
	{
		/*ccname*/	_WT("LUA_������X"),
		/*egname*/	_WT("lua_tointegerx"),
		/*explain*/ _WT("����ջ������λ�õ�ֵת��Ϊ�����͡�"),
		/*category*/cmd_type_idx_access_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_tonumberx) / sizeof(s_arg_lua_tonumberx[0]),
		/*arg lp*/	s_arg_lua_tonumberx,
	},
	{
		/*ccname*/	_WT("LUA_���߼�"),
		/*egname*/	_WT("lua_toboolean"),
		/*explain*/ _WT("����ջ������λ�õ�ֵת��Ϊ�߼��͡�"),
		/*category*/cmd_type_idx_access_functions,
		/*state*/	0,
		/*ret*/		SDT_BOOL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_idx) / sizeof(s_arg_lua_idx[0]),
		/*arg lp*/	s_arg_lua_idx,
	},
	{
		/*ccname*/	_WT("LUA_���ı�"),
		/*egname*/	_WT("lua_tolstring"),
		/*explain*/ _WT("����ջ������λ�õ�ֵת��Ϊ�ı��͡�"),
		/*category*/cmd_type_idx_access_functions,
		/*state*/	0,
		/*ret*/		SDT_TEXT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_idx) / sizeof(s_arg_lua_idx[0]),
		/*arg lp*/	s_arg_lua_idx,
	},
	{
		/*ccname*/	_WT("LUA_ȡԴ����"),
		/*egname*/	_WT("lua_rawlen"),
		/*explain*/ _WT("��ȡ��ջ������λ�õ�ֵ�ĳ��ȡ������ı������ı����ȣ����ڱ��س��������(#)�Ľ��()�������û����ݷ����ڴ��С������ֵ����0"),
		/*category*/cmd_type_idx_access_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_idx) / sizeof(s_arg_lua_idx[0]),
		/*arg lp*/	s_arg_lua_idx,
	},
	{
		/*ccname*/	_WT("LUA_�����غ���"),
		/*egname*/	_WT("lua_tocfunction"),
		/*explain*/ _WT("����ջ������λ�õ�ֵת��Ϊ���غ�����ַ��"),
		/*category*/cmd_type_idx_access_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_idx) / sizeof(s_arg_lua_idx[0]),
		/*arg lp*/	s_arg_lua_idx,
	},
	{
		/*ccname*/	_WT("LUA_���û�����"),
		/*egname*/	_WT("lua_touserdata"),
		/*explain*/ _WT("����ջ������λ�õ�ֵת��Ϊ�û����ݣ�������ָ�롣"),
		/*category*/cmd_type_idx_access_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_idx) / sizeof(s_arg_lua_idx[0]),
		/*arg lp*/	s_arg_lua_idx,
	},
	{
		/*ccname*/	_WT("LUA_���߳�"),
		/*egname*/	_WT("lua_tothread"),
		/*explain*/ _WT("����ջ������λ�õ�ֵת��Ϊ�̣߳�����Lua״̬��"),
		/*category*/cmd_type_idx_access_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_idx) / sizeof(s_arg_lua_idx[0]),
		/*arg lp*/	s_arg_lua_idx,
	},
	{
		/*ccname*/	_WT("LUA_��ָ��"),
		/*egname*/	_WT("lua_topointer"),
		/*explain*/ _WT("����ջ������λ�õ�ֵת��ͨ��ָ�룬ֵ�������û����ݡ����̻߳��������򷵻�0��"),
		/*category*/cmd_type_idx_access_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_idx) / sizeof(s_arg_lua_idx[0]),
		/*arg lp*/	s_arg_lua_idx,
	},
	////////////////////////////////////////////////////////////////////////////�ȽϺ���������

	{
		/*ccname*/	_WT("LUA_��ѧ����"),
		/*egname*/	_WT("lua_arith"),
		/*explain*/ _WT("��ջ����������ֵ������ѧ���㣬ջ���ǵڶ��������������������ǣ��ٽ����ѹ�뵽ջ�С�"),
		/*category*/cmd_type_idx_comparison_and_arithmetic_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_arith) / sizeof(s_arg_lua_arith[0]),
		/*arg lp*/	s_arg_lua_arith,
	},
	{
		/*ccname*/	_WT("LUA_Ԫ���"),
		/*egname*/	_WT("lua_rawequal"),
		/*explain*/ _WT("�Ƚ�����ջ������ֵ���������� __eq Ԫ����������ȷ����棬���κ�һ��������Ч�����ؼ١�"),
		/*category*/cmd_type_idx_comparison_and_arithmetic_functions,
		/*state*/	0,
		/*ret*/		SDT_BOOL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_rawequal) / sizeof(s_arg_lua_rawequal[0]),
		/*arg lp*/	s_arg_lua_rawequal,
	},
	{
		/*ccname*/	_WT("LUA_�Ƚ�"),
		/*egname*/	_WT("lua_compare"),
		/*explain*/ _WT("��ָ���Ĳ������Ƚ�����ջ������ֵ������κ�һ��������Ч���ؼ١�"),
		/*category*/cmd_type_idx_comparison_and_arithmetic_functions,
		/*state*/	0,
		/*ret*/		SDT_BOOL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_compare) / sizeof(s_arg_lua_compare[0]),
		/*arg lp*/	s_arg_lua_compare,
	},
	//////////////////////////////////////////////////////////////////////////ѹջ����
	{
		/*ccname*/	_WT("LUA_ѹ���"),
		/*egname*/	_WT("lua_pushnil"),
		/*explain*/ _WT("ѹ�� nil ��ջ��"),
		/*category*/cmd_type_idx_push_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua) / sizeof(s_arg_lua[0]),
		/*arg lp*/	s_arg_lua,
	},
	{
		/*ccname*/	_WT("LUA_ѹ����ֵ"),
		/*egname*/	_WT("lua_pushnumber"),
		/*explain*/ _WT("ѹ����ֵ��ջ��"),
		/*category*/cmd_type_idx_push_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_pushnumber) / sizeof(s_arg_lua_pushnumber[0]),
		/*arg lp*/	s_arg_lua_pushnumber,
	},
	{
		/*ccname*/	_WT("LUA_ѹ������"),
		/*egname*/	_WT("lua_pushinteger"),
		/*explain*/ _WT("ѹ��������ջ��"),
		/*category*/cmd_type_idx_push_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_pushinteger) / sizeof(s_arg_lua_pushinteger[0]),
		/*arg lp*/	s_arg_lua_pushinteger,
	},
	{
		/*ccname*/	_WT("LUA_ѹ���ı�"),
		/*egname*/	_WT("lua_pushlstring"),
		/*explain*/ _WT("ѹ���ı���ջ�У������ڲ�������ָ�롣�������0����nilѹ��ջ��"),
		/*category*/cmd_type_idx_push_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_pushlstring) / sizeof(s_arg_lua_pushlstring[0]),
		/*arg lp*/	s_arg_lua_pushlstring,
	},
	{
		/*ccname*/	_WT("LUA_ѹ���ʽ���ı�"),
		/*egname*/	_WT("lua_pushvfstring"),
		/*explain*/ _WT("ѹ���ʽ���ı���ջ�У������ڲ�������ָ�롣�������0����nilѹ��ջ��"),
		/*category*/cmd_type_idx_push_functions,
		/*state*/	CT_ALLOW_APPEND_NEW_ARG,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_pushvfstring) / sizeof(s_arg_lua_pushvfstring[0]),
		/*arg lp*/	s_arg_lua_pushvfstring,
	},
	{
		/*ccname*/	_WT("LUA_ѹ�뱾�غ���"),
		/*egname*/	_WT("lua_pushcclosure"),
		/*explain*/ _WT("�����غ���ѹ�뵽ջ�С�"),
		/*category*/cmd_type_idx_push_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_pushcclosure) / sizeof(s_arg_lua_pushcclosure[0]),
		/*arg lp*/	s_arg_lua_pushcclosure,
	},
	{
		/*ccname*/	_WT("LUA_ѹ���߼�"),
		/*egname*/	_WT("lua_pushboolean"),
		/*explain*/ _WT("ѹ���߼�ֵ��ջ�С�"),
		/*category*/cmd_type_idx_push_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_pushboolean) / sizeof(s_arg_lua_pushboolean[0]),
		/*arg lp*/	s_arg_lua_pushboolean,
	},
	{
		/*ccname*/	_WT("LUA_ѹ���û�ָ��"),
		/*egname*/	_WT("lua_pushlightuserdata"),
		/*explain*/ _WT("ѹ���û�ָ�뵽ջ�С�"),
		/*category*/cmd_type_idx_push_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_pushlightuserdata) / sizeof(s_arg_lua_pushlightuserdata[0]),
		/*arg lp*/	s_arg_lua_pushlightuserdata,
	},
	{
		/*ccname*/	_WT("LUA_ѹ���߳�"),
		/*egname*/	_WT("lua_pushthread"),
		/*explain*/ _WT("ѹ���̵߳�ջ�С���������߳������̣߳�����1"),
		/*category*/cmd_type_idx_push_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_pushthread) / sizeof(s_arg_lua_pushthread[0]),
		/*arg lp*/	s_arg_lua_pushthread,
	},

	//////////////////////////////////////////////////////////////////////////ȡֵ����
	{
		/*ccname*/	_WT("LUA_ȡȫ��ֵ"),
		/*egname*/	_WT("lua_getglobal"),
		/*explain*/ _WT("��ȫ�����Ƶ�ֵѹ��ջ�У����ظ�ֵ�����͡��ᴥ��Ԫ�����ġ�index���¼�"),
		/*category*/cmd_type_idx_get_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_getglobal) / sizeof(s_arg_lua_getglobal[0]),
		/*arg lp*/	s_arg_lua_getglobal,
	},
	{
		/*ccname*/	_WT("LUA_ȡ��ֵ"),
		/*egname*/	_WT("lua_gettable"),
		/*explain*/ _WT("��ջ�е���һ���������ݡ�ջ������ָ��ı��ȡһ��ֵ����ѹ�뵽ջ�У����ظ�ֵ�����͡��ᴥ��Ԫ�����ġ�index���¼�"),
		/*category*/cmd_type_idx_get_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_idx) / sizeof(s_arg_lua_idx[0]),
		/*arg lp*/	s_arg_lua_idx,
	},
	{
		/*ccname*/	_WT("LUA_ȡ�ֶ�ֵ"),
		/*egname*/	_WT("lua_getfield"),
		/*explain*/ _WT("���ݡ�ջ������ָ��ı��͡���������ȡһ��ֵ����ѹ�뵽ջ�У����ظ�ֵ�����͡��ᴥ��Ԫ�����ġ�index���¼�"),
		/*category*/cmd_type_idx_get_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_getfield) / sizeof(s_arg_lua_getfield[0]),
		/*arg lp*/	s_arg_lua_getfield,
	},
	{
		/*ccname*/	_WT("LUA_ȡ����ֵ"),
		/*egname*/	_WT("lua_getfield"),
		/*explain*/ _WT("���ݡ�ջ������ָ��ı��͡���Ա��������ȡһ��ֵ����ѹ�뵽ջ�У����ظ�ֵ�����͡��ᴥ��Ԫ�����ġ�index���¼�"),
		/*category*/cmd_type_idx_get_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_geti) / sizeof(s_arg_lua_geti[0]),
		/*arg lp*/	s_arg_lua_geti,
	},
	{
		/*ccname*/	_WT("LUA_Ԫȡֵ"),
		/*egname*/	_WT("lua_rawget"),
		/*explain*/ _WT("��ջ�е���һ���������ݡ�ջ������ָ��ı���ȡһ��ֵ����ѹ�뵽ջ�У����ظ�ֵ�����͡����ᴥ��Ԫ����"),
		/*category*/cmd_type_idx_get_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_idx) / sizeof(s_arg_lua_idx[0]),
		/*arg lp*/	s_arg_lua_idx,
	},
	{
		/*ccname*/	_WT("LUA_Ԫȡֵ����"),
		/*egname*/	_WT("lua_rawgeti"),
		/*explain*/ _WT("���ݡ�ջ������ָ��ı��͡���Ա��������ȡһ��ֵ����ѹ�뵽ջ�У����ظ�ֵ�����͡����ᴥ��Ԫ����"),
		/*category*/cmd_type_idx_get_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_geti) / sizeof(s_arg_lua_geti[0]),
		/*arg lp*/	s_arg_lua_geti,
	},
	{
		/*ccname*/	_WT("LUA_Ԫȡֵָ��"),
		/*egname*/	_WT("lua_rawgetp"),
		/*explain*/ _WT("���ݡ�ջ������ָ��ı��͡��û�ָ�롯��Ϊ������ȡһ��ֵ����ѹ�뵽ջ�У����ظ�ֵ�����͡����ᴥ��Ԫ����"),
		/*category*/cmd_type_idx_get_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_rawgetp) / sizeof(s_arg_lua_rawgetp[0]),
		/*arg lp*/	s_arg_lua_rawgetp,
	},
	{
		/*ccname*/	_WT("LUA_������"),
		/*egname*/	_WT("lua_createtable"),
		/*explain*/ _WT("����һ������ѹ�뵽ջ�С���������ָ����ʼ���������ṩЧ�ʡ�"),
		/*category*/cmd_type_idx_get_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_createtable) / sizeof(s_arg_lua_createtable[0]),
		/*arg lp*/	s_arg_lua_createtable,
	},
	{
		/*ccname*/	_WT("LUA_�½��û�����"),
		/*egname*/	_WT("lua_newuserdata"),
		/*explain*/ _WT("����һ���Զ��������ڴ�飬��ѹ�뵽ջ�У��ҷ��ظ�ָ�룬Ӧ�ó�����������д��"),
		/*category*/cmd_type_idx_get_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_newuserdata) / sizeof(s_arg_lua_newuserdata[0]),
		/*arg lp*/	s_arg_lua_newuserdata,
	},
	{
		/*ccname*/	_WT("LUA_ȡԪ��"),
		/*egname*/	_WT("lua_getmetatable"),
		/*explain*/ _WT("�����ջ����������ֵ����metatable����ѹ�뵽ջ�в������棬���򷵻ؼ١�"),
		/*category*/cmd_type_idx_get_functions,
		/*state*/	0,
		/*ret*/		SDT_BOOL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_idx) / sizeof(s_arg_lua_idx[0]),
		/*arg lp*/	s_arg_lua_idx,
	},
	{
		/*ccname*/	_WT("LUA_ȡ�û�ֵ"),
		/*egname*/	_WT("lua_getuservalue"),
		/*explain*/ _WT("��'ջ����'�����û������������� Lua ֵѹ�뵽ջ�С�����ѹ��ֵ�����͡�"),
		/*category*/cmd_type_idx_get_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_idx) / sizeof(s_arg_lua_idx[0]),
		/*arg lp*/	s_arg_lua_idx,
	},

	//////////////////////////////////////////////////////////////////////////��ֵ����//////////////////////////////////////////////////////////////////////////

	{
		/*ccname*/	_WT("LUA_��ȫ��ֵ"),
		/*egname*/	_WT("lua_setglobal"),
		/*explain*/ _WT("��ջ�е���һ��ֵ������Ϊȫ��ָ�����Ƶ���ֵ��"),
		/*category*/cmd_type_idx_set_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_getglobal) / sizeof(s_arg_lua_getglobal[0]),
		/*arg lp*/	s_arg_lua_getglobal,
	},
	{
		/*ccname*/	_WT("LUA_�ñ�ֵ"),
		/*egname*/	_WT("lua_settable"),
		/*explain*/ _WT("��ջ�е���һ������һ��ֵ��ֵ��ջ������������Ϊ��ջ�����������Ա��ֵ�����ܴ�����newindex���¼���Ԫ����"),
		/*category*/cmd_type_idx_set_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_idx) / sizeof(s_arg_lua_idx[0]),
		/*arg lp*/	s_arg_lua_idx,
	},
	{
		/*ccname*/	_WT("LUA_���ֶ�ֵ"),
		/*egname*/	_WT("lua_setfield"),
		/*explain*/ _WT("��ջ�е���һ��ֵ���Ͳ��������ġ����ơ�������Ϊ��ջ�����������Ա��ֵ�����ܴ�����newindex���¼���Ԫ����"),
		/*category*/cmd_type_idx_set_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_getfield) / sizeof(s_arg_lua_getfield[0]),
		/*arg lp*/	s_arg_lua_getfield,
	},
	{
		/*ccname*/	_WT("LUA_������ֵ"),
		/*egname*/	_WT("lua_seti"),
		/*explain*/ _WT("��ջ�е���һ��ֵ���Ͳ��������ġ���Ա������������Ϊ��ջ�����������Ա��ֵ�����ܴ�����newindex���¼���Ԫ����"),
		/*category*/cmd_type_idx_set_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_geti) / sizeof(s_arg_lua_geti[0]),
		/*arg lp*/	s_arg_lua_geti,
	},
	{
		/*ccname*/	_WT("LUA_Ԫ��ֵ"),
		/*egname*/	_WT("lua_rawset"),
		/*explain*/ _WT("��ջ�е���һ������һ��ֵ��ֵ��ջ������������Ϊ��ջ�����������Ա��ֵ��������Ԫ����"),
		/*category*/cmd_type_idx_set_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_idx) / sizeof(s_arg_lua_idx[0]),
		/*arg lp*/	s_arg_lua_idx,
	},
	{
		/*ccname*/	_WT("LUA_Ԫ��ֵ����"),
		/*egname*/	_WT("lua_rawseti"),
		/*explain*/ _WT("��ջ�е���һ��ֵ��������Ϊ��ջ����������ġ���Ա����������ֵ��������Ԫ����"),
		/*category*/cmd_type_idx_set_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_geti) / sizeof(s_arg_lua_geti[0]),
		/*arg lp*/	s_arg_lua_geti,
	},
	{
		/*ccname*/	_WT("LUA_Ԫ��ֵָ��"),
		/*egname*/	_WT("lua_rawsetp"),
		/*explain*/ _WT("��ջ�е���һ��ֵ��������Ϊ��ջ����������ġ��û�ָ�롯����ֵ��������Ԫ����"),
		/*category*/cmd_type_idx_set_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_rawgetp) / sizeof(s_arg_lua_rawgetp[0]),
		/*arg lp*/	s_arg_lua_rawgetp,
	},
	{
		/*ccname*/	_WT("LUA_��Ԫ��"),
		/*egname*/	_WT("lua_setmetatable"),
		/*explain*/ _WT("��ջ�е���һ��ֵ��������Ϊ��ջ���������������Ԫ��"),
		/*category*/cmd_type_idx_set_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_idx) / sizeof(s_arg_lua_idx[0]),
		/*arg lp*/	s_arg_lua_idx,
	},
	{
		/*ccname*/	_WT("LUA_���û�ֵ"),
		/*egname*/	_WT("lua_setuservalue"),
		/*explain*/ _WT("��ջ�е���һ��ֵ��������Ϊ��ջ���������û����ݵ���ֵ��"),
		/*category*/cmd_type_idx_set_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_idx) / sizeof(s_arg_lua_idx[0]),
		/*arg lp*/	s_arg_lua_idx,
	},

	//////////////////////////////////////////////////////////////////////////��������в���

	{
		/*ccname*/	_WT("LUA_����K"),
		/*egname*/	_WT("lua_callk"),
		/*explain*/ _WT("����һ������������֮ǰ�������Ͳ���ѹ��ջ��������Ϻ�����ͺ������ᵯ��ջ������ָ�������ķ���ֵѹ��ջ�����ҿ���ָ��һ������������"),
		/*category*/cmd_type_idx_load_and_call_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_callk) / sizeof(s_arg_lua_callk[0]),
		/*arg lp*/	s_arg_lua_callk,
	},
	{
		/*ccname*/	_WT("LUA_����"),
		/*egname*/	_WT("lua_call"),
		/*explain*/ _WT("����һ������������֮ǰ�������Ͳ���ѹ��ջ��������Ϻ�����ͺ������ᵯ��ջ������ָ�������ķ���ֵѹ��ջ��"),
		/*category*/cmd_type_idx_load_and_call_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_call) / sizeof(s_arg_lua_call[0]),
		/*arg lp*/	s_arg_lua_call,
	},
	{
		/*ccname*/	_WT("LUA_��ȫ����K"),
		/*egname*/	_WT("lua_pcall"),
		/*explain*/ _WT("����һ������������������һ��������հ�������֮ǰ�������Ͳ���ѹ��ջ��������Ϻ�����ͺ������ᵯ��ջ������ָ�������ķ���ֵѹ��ջ��"),
		/*category*/cmd_type_idx_load_and_call_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_pcallk) / sizeof(s_arg_lua_pcallk[0]),
		/*arg lp*/	s_arg_lua_pcallk,
	},
	{
		/*ccname*/	_WT("LUA_����"),
		/*egname*/	_WT("lua_load"),
		/*explain*/ _WT("����һ��lua�ű������ǲ������������û�д�������Ϊ����ѹ�뵽ջ�У�����ѹ��һ��������Ϣ������ LUA_ ��ͷ������"),
		/*category*/cmd_type_idx_load_and_call_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_load) / sizeof(s_arg_lua_load[0]),
		/*arg lp*/	s_arg_lua_load,
	},
	{
		/*ccname*/	_WT("LUA_����"),
		/*egname*/	_WT("lua_dump"),
		/*explain*/ _WT("��ջ���ĺ�������Ϊ�����ƿ飬�����ƿ�����ٴ����롣���ᵯ��ջ���ĺ��������� LUA_ ��ͷ������"),
		/*category*/cmd_type_idx_load_and_call_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_dump) / sizeof(s_arg_lua_dump[0]),
		/*arg lp*/	s_arg_lua_dump,
	},

	//////////////////////////////////////////////////////////////////////////Э�̲���

	{
		/*ccname*/	_WT("LUA_��ͣ"),
		/*egname*/	_WT("lua_yieldk"),
		/*explain*/ _WT("��ͣ�������е�Эͬ���򣬲��� 'LUA_�ָ�' ���أ����� LUA_ ��ͷ������\r\n����������ֵ��������ջ�н���Ϊ������ݸ�LUA_����ֵ��������\r\n��Эͬ�����ٴλָ�ʱ��Lua���ø�����'��������'����ִ�С��˼���������ǰһ������������ͬ��ջ��ɾ��n��������滻Ϊ���ݸ� 'LUA_�ָ�' �Ĳ��������⣬�����������մ��ݸ� LUA_��ͣ ��������ֵ��"),
		/*category*/cmd_type_idx_coroutine_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_yieldk) / sizeof(s_arg_lua_yieldk[0]),
		/*arg lp*/	s_arg_lua_yieldk,
	},
	{
		/*ccname*/	_WT("LUA_�ָ�"),
		/*egname*/	_WT("lua_resume"),
		/*explain*/ _WT("�ڸ������߳��п�ʼ���ָ�Э�̣����� LUA_ ��ͷ������\r\nҪ����һ��Э�̣�����Խ������������κβ���ѹ�뵽�߳�ջ; Ȼ����� LUA_�ָ�����Эͬ������ͣ�������ִ��ʱ���˵��ý����ء� ����ʱ��ջ����'LUA_��ͣ'���ݵ�����ֵ�����߰���body�������ص�����ֵ�� ���Э����ͣ����'LUA_�ָ�'����LUA_YIELD�����Э�����ִ��û�д����򷵻�LUA_OK��������ִ����򷵻ش�����롣"),
		/*category*/cmd_type_idx_coroutine_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_resume) / sizeof(s_arg_lua_resume[0]),
		/*arg lp*/	s_arg_lua_resume,
	},

};
#endif

//////////////////////////////////////////////////////////////////////////״̬����
EXTERN_C void elua_fn_lua_newstate(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = (INT)lua_newstate((lua_Alloc)pArgInf[0].m_dwSubCodeAdr, (void*)pArgInf[1].m_int);
}

EXTERN_C void elua_fn_lua_close(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	lua_close((lua_State*)pArgInf[0].m_int);
}
EXTERN_C void elua_fn_lua_newthread(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = (INT)lua_newthread((lua_State*)pArgInf[0].m_int);
}
EXTERN_C void elua_fn_lua_atpanic(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = (INT)lua_atpanic((lua_State*)pArgInf[0].m_int, (lua_CFunction)pArgInf[1].m_pdwSubCodeAdr);
}
EXTERN_C void elua_fn_lua_version(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	const lua_Number* ver = lua_version((lua_State*)pArgInf[0].m_int);
	pRetData->m_double = *ver;
}

//////////////////////////////////////////////////////////////////////////����ջ����
EXTERN_C void elua_fn_lua_absindex(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = lua_absindex((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_gettop(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = lua_gettop((lua_State*)pArgInf[0].m_int);
}
EXTERN_C void elua_fn_lua_settop(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	lua_settop((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int);
}

EXTERN_C void elua_fn_lua_pushvalue(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	lua_pushvalue((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_rotate(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	lua_rotate((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int, pArgInf[2].m_int);
}
EXTERN_C void elua_fn_lua_copy(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	lua_copy((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int, pArgInf[2].m_int);
}
EXTERN_C void elua_fn_lua_checkstack(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_bool = lua_checkstack((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_xmove(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	lua_xmove((lua_State*)pArgInf[0].m_int, (lua_State*)pArgInf[1].m_int, pArgInf[2].m_int);
}

//////////////////////////////////////////////////////////////////////////���ʺ�����ջ->�ף�

EXTERN_C void elua_fn_lua_isnumber(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_bool = lua_isnumber((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int);
}

EXTERN_C void elua_fn_lua_isstring(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_bool = lua_isstring((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_iscfunction(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_bool = lua_iscfunction((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_isinteger(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_bool = lua_isinteger((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_isuserdata(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_bool = lua_isuserdata((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_type(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = lua_type((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_typename(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	const char* name = lua_typename((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int);
	pRetData->m_pText = zy_clone_text(name);
}
EXTERN_C void elua_fn_lua_tonumberx(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	int isNum = 0;
	pRetData->m_double = lua_tonumberx((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int, &isNum);
	if (pArgInf[2].m_dtDataType!= _SDT_NULL)
	{
		*pArgInf[2].m_pBool = isNum;
	}

}
EXTERN_C void elua_fn_lua_tointegerx(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	int isNum = 0;
	pRetData->m_int = lua_tointegerx((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int, &isNum);
	if (pArgInf[2].m_dtDataType != _SDT_NULL)
	{
		*pArgInf[2].m_pBool = isNum;
	}
}
EXTERN_C void elua_fn_lua_toboolean(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_bool = lua_toboolean((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_tolstring(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	size_t len = 0;
	const char* name = lua_tolstring((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int, &len);
	pRetData->m_pText = zy_clone_textlen(name, len);
}
EXTERN_C void elua_fn_lua_rawlen(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = lua_rawlen((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_tocfunction(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = (INT)lua_tocfunction((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_touserdata(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = (INT)lua_touserdata((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_tothread(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = (INT)lua_tothread((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_topointer(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = (INT)lua_topointer((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int);
}

////////////////////////////////////////////////////////////////////////////�ȽϺ���������


EXTERN_C void elua_fn_lua_arith(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	lua_arith((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int);
}

EXTERN_C void elua_fn_lua_rawequal(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_bool = lua_rawequal((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int, pArgInf[2].m_int);
}

EXTERN_C void elua_fn_lua_compare(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_bool = lua_compare((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int, pArgInf[2].m_int, pArgInf[3].m_int);
}

////////////////////////////////////////////////////////////////////////////ѹջ����

EXTERN_C void elua_fn_lua_pushnil(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	lua_pushnil((lua_State*)pArgInf[0].m_int);
}
EXTERN_C void elua_fn_lua_pushnumber(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	lua_pushnumber((lua_State*)pArgInf[0].m_int, pArgInf[1].m_double);
}
EXTERN_C void elua_fn_lua_pushinteger(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	lua_pushinteger((lua_State*)pArgInf[0].m_int, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_pushlstring(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	if (pArgInf[2].m_dtDataType == _SDT_NULL)
	{
		pRetData->m_int = (INT)lua_pushstring(L, pArgInf[1].m_pText);
	}
	else
	{
		pRetData->m_int = (INT)lua_pushlstring(L, pArgInf[1].m_pText, pArgInf[2].m_int);
	}
}


EXTERN_C void elua_fn_lua_pushvfstring(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);

	const char* fmt = pArgInf[1].m_pText;
	int len = 0;
	int i = 2;
	for (; i < iArgCount; i++)
	{
		DATA_TYPE t = pArgInf[i].m_dtDataType;
		if (t == SDT_DOUBLE || t == SDT_INT64 || t== SDT_DATE_TIME)
		{
			len += 8;
		}
		else
		{
			len += 4;
		}
	}
	char* list = new char[len];
	len = 0;
	for (i = 2; i < iArgCount; i++)
	{
		DATA_TYPE t = pArgInf[i].m_dtDataType;
		switch (t)
		{
		case SDT_BYTE:
		case SDT_SHORT:
		case SDT_BOOL:
		case SDT_INT:
		case SDT_SUB_PTR:
			memcpy(list + len, &pArgInf[i].m_int, sizeof(INT));
			len += sizeof(INT);
			break;
		case SDT_FLOAT:
			memcpy(list + len, &pArgInf[i].m_float, sizeof(FLOAT));
			len += sizeof(FLOAT);
			break;
		case SDT_TEXT:    // �ı��ͺ��ֽڼ���Ϊһ��ָ��,���Ϊ�ĸ��ֽ�.
			memcpy(list + len, &pArgInf[i].m_pText, sizeof(char*));
			len += sizeof(char*);
			break;
		case SDT_BIN:
		{
			LPBYTE p = pArgInf[i].m_pBin + sizeof(INT) * 2;
			memcpy(list + len, &p, sizeof(LPBYTE));
			len += sizeof(LPBYTE);
			break;
		}
		case SDT_INT64:
		{
			memcpy(list + len, &pArgInf[i].m_int64, sizeof(INT64));
			len += sizeof(INT64);
			break;
		}
		case SDT_DOUBLE:
		case SDT_DATE_TIME:
			memcpy(list + len, &pArgInf[i].m_double, sizeof(DOUBLE));
			len += sizeof(DOUBLE);
			break;
		default:
			break;
		}
	}
	pRetData->m_int = (INT)lua_pushvfstring(L, fmt, list);
	delete[] list;
}


EXTERN_C void elua_fn_lua_pushcclosure(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_pushcclosure(L, (lua_CFunction)pArgInf[1].m_dwSubCodeAdr, pArgInf[2].m_int);
}
EXTERN_C void elua_fn_lua_pushboolean(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_pushboolean(L, pArgInf[1].m_bool);
}
EXTERN_C void elua_fn_lua_pushlightuserdata(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_pushlightuserdata(L, (void*)pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_pushthread(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_pushthread(L);
}


//////////////////////////////////////////////////////////////////////////ȡֵ����

EXTERN_C void elua_fn_lua_getglobal(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = lua_getglobal(L, pArgInf[1].m_pText);
}
EXTERN_C void elua_fn_lua_gettable(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = lua_gettable(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_getfield(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = lua_getfield(L, pArgInf[1].m_int, pArgInf[2].m_pText);
}
EXTERN_C void elua_fn_lua_geti(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = lua_geti(L, pArgInf[1].m_int, pArgInf[2].m_int);
}
EXTERN_C void elua_fn_lua_rawget(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = lua_rawget(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_rawgeti(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = lua_rawgeti(L, pArgInf[1].m_int, pArgInf[2].m_int);
}
EXTERN_C void elua_fn_lua_rawgetp(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = lua_rawgetp(L, pArgInf[1].m_int, (void*)pArgInf[2].m_int);
}
EXTERN_C void elua_fn_lua_createtable(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_createtable(L, pArgInf[1].m_int, pArgInf[2].m_int);
}
EXTERN_C void elua_fn_lua_newuserdata(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = (INT)lua_newuserdata(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_getmetatable(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_bool = lua_getmetatable(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_getuservalue(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = lua_getuservalue(L, pArgInf[1].m_int);
}

//////////////////////////////////////////////////////////////////////////��ֵ����

EXTERN_C void elua_fn_lua_setglobal(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_setglobal(L, pArgInf[1].m_pText);
}
EXTERN_C void elua_fn_lua_settable(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_settable(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_setfield(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_setfield(L, pArgInf[1].m_int, pArgInf[2].m_pText);
}
EXTERN_C void elua_fn_lua_seti(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_seti(L, pArgInf[1].m_int, pArgInf[2].m_int);
}
EXTERN_C void elua_fn_lua_rawset(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_rawset(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_rawseti(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_rawseti(L, pArgInf[1].m_int, pArgInf[2].m_int);
}
EXTERN_C void elua_fn_lua_rawsetp(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_rawsetp(L, pArgInf[1].m_int, (void*)pArgInf[2].m_int);
}
EXTERN_C void elua_fn_lua_setmetatable(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_setmetatable(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_setuservalue(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_setuservalue(L, pArgInf[1].m_int);
}

//////////////////////////////////////////////////////////////////////////��������в���

EXTERN_C void elua_fn_lua_callk(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_KFunction funk = NULL;
	if (pArgInf[4].m_dtDataType!=_SDT_NULL)
	{
		funk = (lua_KFunction)pArgInf[4].m_dwSubCodeAdr;
	}
	lua_callk(L, pArgInf[1].m_int, pArgInf[2].m_int, pArgInf[3].m_int, funk);
}

EXTERN_C void elua_fn_lua_call(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_call(L, pArgInf[1].m_int, pArgInf[2].m_int);
}

EXTERN_C void elua_fn_lua_pcallk(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_KFunction funk = NULL;
	if (pArgInf[5].m_dtDataType != _SDT_NULL)
	{
		funk = (lua_KFunction)pArgInf[5].m_dwSubCodeAdr;
	}
	lua_pcallk(L, pArgInf[1].m_int, pArgInf[2].m_int, pArgInf[3].m_int, pArgInf[4].m_int, funk);
}

EXTERN_C void elua_fn_lua_pcall(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_pcall(L, pArgInf[1].m_int, pArgInf[2].m_int, pArgInf[3].m_int);
}

EXTERN_C void elua_fn_lua_load(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = lua_load(L, (lua_Reader)pArgInf[1].m_dwSubCodeAdr, (void*)pArgInf[2].m_int, pArgInf[3].m_pText, pArgInf[4].m_pText);
}

EXTERN_C void elua_fn_lua_dump(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = lua_dump(L, (lua_Writer)pArgInf[1].m_dwSubCodeAdr, (void*)pArgInf[2].m_int, pArgInf[3].m_bool);
}

//////////////////////////////////////////////////////////////////////////Э�̲���

EXTERN_C void elua_fn_lua_yieldk(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_KFunction funk = NULL;
	if (pArgInf[3].m_dtDataType != _SDT_NULL)
	{
		funk = (lua_KFunction)pArgInf[3].m_dwSubCodeAdr;
	}
	pRetData->m_int = lua_yieldk(L, pArgInf[1].m_int, pArgInf[2].m_int, funk);
}
EXTERN_C void elua_fn_lua_resume(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = lua_resume(L, (lua_State*)pArgInf[1].m_int, pArgInf[2].m_int);
}



#ifndef __E_STATIC_LIB
PFN_EXECUTE_CMD s_RunFunc[] =	// ����Ӧ��s_CmdInfo�е������˳���Ӧ
{
	//״̬����
	elua_fn_lua_newstate,
	elua_fn_lua_close,
	elua_fn_lua_newthread,
	elua_fn_lua_atpanic,
	elua_fn_lua_version,
	//����ջ����
	elua_fn_lua_absindex,
	elua_fn_lua_gettop,
	elua_fn_lua_settop,
	elua_fn_lua_pushvalue,
	elua_fn_lua_rotate,
	elua_fn_lua_copy,
	elua_fn_lua_checkstack,
	elua_fn_lua_xmove,
	//���ʺ���
	elua_fn_lua_isnumber,
	elua_fn_lua_isstring,
	elua_fn_lua_iscfunction,
	elua_fn_lua_isinteger,
	elua_fn_lua_isuserdata,
	elua_fn_lua_type,
	elua_fn_lua_typename,
	elua_fn_lua_tonumberx,
	elua_fn_lua_tointegerx,
	elua_fn_lua_toboolean,
	elua_fn_lua_tolstring,
	elua_fn_lua_rawlen,
	elua_fn_lua_tocfunction,
	elua_fn_lua_touserdata,
	elua_fn_lua_tothread,
	elua_fn_lua_topointer,
	//�ȽϺ���������
	elua_fn_lua_arith,
	elua_fn_lua_rawequal,
	elua_fn_lua_compare,
	//ѹջ����
	elua_fn_lua_pushnil,
	elua_fn_lua_pushnumber,
	elua_fn_lua_pushinteger,
	elua_fn_lua_pushlstring,
	elua_fn_lua_pushvfstring,
	elua_fn_lua_pushcclosure,
	elua_fn_lua_pushboolean,
	elua_fn_lua_pushlightuserdata,
	elua_fn_lua_pushthread,
	//ȡֵ����
	elua_fn_lua_getglobal,
	elua_fn_lua_gettable,
	elua_fn_lua_getfield,
	elua_fn_lua_geti,
	elua_fn_lua_rawget,
	elua_fn_lua_rawgeti,
	elua_fn_lua_rawgetp,
	elua_fn_lua_createtable,
	elua_fn_lua_newuserdata,
	elua_fn_lua_getmetatable,
	elua_fn_lua_getuservalue,
	//��ֵ����
	elua_fn_lua_setglobal,
	elua_fn_lua_settable,
	elua_fn_lua_setfield,
	elua_fn_lua_seti,
	elua_fn_lua_rawset,
	elua_fn_lua_rawseti,
	elua_fn_lua_rawsetp,
	elua_fn_lua_setmetatable,
	elua_fn_lua_setuservalue,
	//��������в���
	elua_fn_lua_callk,
	elua_fn_lua_call,
	elua_fn_lua_pcallk,
	elua_fn_lua_pcall,
	elua_fn_lua_load,
	elua_fn_lua_dump,
	//Э�̲���
	elua_fn_lua_yieldk,
	elua_fn_lua_resume,
};

static const char* const g_CmdNames[] =
{
	//״̬����
	"elua_fn_lua_newstate",
	"elua_fn_lua_close",
	"elua_fn_lua_newthread",
	"elua_fn_lua_atpanic",
	"elua_fn_lua_version",
	//����ջ����
	"elua_fn_lua_absindex",
	"elua_fn_lua_gettop",
	"elua_fn_lua_settop",
	"elua_fn_lua_pushvalue",
	"elua_fn_lua_rotate",
	"elua_fn_lua_copy",
	"elua_fn_lua_checkstack",
	"elua_fn_lua_xmove",
	//���ʺ���
	"elua_fn_lua_isnumber",
	"elua_fn_lua_isstring",
	"elua_fn_lua_iscfunction",
	"elua_fn_lua_isinteger",
	"elua_fn_lua_isuserdata",
	"elua_fn_lua_type",
	"elua_fn_lua_typename",
	"elua_fn_lua_tonumberx",
	"elua_fn_lua_tointegerx",
	"elua_fn_lua_toboolean",
	"elua_fn_lua_tolstring",
	"elua_fn_lua_rawlen",
	"elua_fn_lua_tocfunction",
	"elua_fn_lua_touserdata",
	"elua_fn_lua_tothread",
	"elua_fn_lua_topointer",
	//�ȽϺ���������
	"elua_fn_lua_arith",
	"elua_fn_lua_rawequal",
	"elua_fn_lua_compare",
	//ѹջ����
	"elua_fn_lua_pushnil",
	"elua_fn_lua_pushnumber",
	"elua_fn_lua_pushinteger",
	"elua_fn_lua_pushlstring",
	"elua_fn_lua_pushvfstring",
	"elua_fn_lua_pushcclosure",
	"elua_fn_lua_pushboolean",
	"elua_fn_lua_pushlightuserdata",
	"elua_fn_lua_pushthread",
	//ȡֵ����
	"elua_fn_lua_getglobal",
	"elua_fn_lua_gettable",
	"elua_fn_lua_getfield",
	"elua_fn_lua_geti",
	"elua_fn_lua_rawget",
	"elua_fn_lua_rawgeti",
	"elua_fn_lua_rawgetp",
	"elua_fn_lua_createtable",
	"elua_fn_lua_newuserdata",
	"elua_fn_lua_getmetatable",
	"elua_fn_lua_getuservalue",
	//��ֵ����
	"elua_fn_lua_setglobal",
	"elua_fn_lua_settable",
	"elua_fn_lua_setfield",
	"elua_fn_lua_seti",
	"elua_fn_lua_rawset",
	"elua_fn_lua_rawseti",
	"elua_fn_lua_rawsetp",
	"elua_fn_lua_setmetatable",
	"elua_fn_lua_setuservalue",
	//��������в���
	"elua_fn_lua_callk",
	"elua_fn_lua_call",
	"elua_fn_lua_pcallk",
	"elua_fn_lua_pcall",
	"elua_fn_lua_load",
	"elua_fn_lua_dump",
	//Э�̲���
	"elua_fn_lua_yieldk",
	"elua_fn_lua_resume",
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