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

	{ _WT("LUA������_��"), _WT("LUA_OPADD"), _WT("+"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPADD },
	{ _WT("LUA������_��"), _WT("LUA_OPSUB"), _WT("-"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPSUB },
	{ _WT("LUA������_��"), _WT("LUA_OPMUL"), _WT("*"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPMUL },
	{ _WT("LUA������_����"), _WT("LUA_OPMOD"), _WT("%"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPMOD },
	{ _WT("LUA������_��η�"), _WT("LUA_OPPOW"), _WT("^"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPPOW },
	{ _WT("LUA������_��"), _WT("LUA_OPDIV"), _WT("/"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPDIV },
	{ _WT("LUA������_����"), _WT("LUA_OPIDIV"), _WT("//"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPIDIV },
	{ _WT("LUA������_λ��"), _WT("LUA_OPBAND"), _WT("&"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPBAND },
	{ _WT("LUA������_λ��"), _WT("LUA_OPBOR"), _WT("|"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPBOR },
	{ _WT("LUA������_λ���"), _WT("LUA_OPBXOR"), _WT("~"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPBXOR },
	{ _WT("LUA������_����"), _WT("LUA_OPSHL"), _WT("<<"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPSHL },
	{ _WT("LUA������_����"), _WT("LUA_OPSHR"), _WT(">>"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPSHR },
	{ _WT("LUA������_��"), _WT("LUA_OPUNM"), _WT("-"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPUNM },
	{ _WT("LUA������_λȡ��"), _WT("LUA_OPBNOT"), _WT("~"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPBNOT },

	{ _WT("LUA�Ƚ�_���"), _WT("LUA_OPEQ"), _WT("="), LVL_SIMPLE, CT_NUM, NULL, LUA_OPEQ },
	{ _WT("LUA�Ƚ�_С��"), _WT("LUA_OPLT"), _WT("<"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPLT },
	{ _WT("LUA�Ƚ�_С�ڵ���"), _WT("LUA_OPLE"), _WT("<="), LVL_SIMPLE, CT_NUM, NULL, LUA_OPLE },

	{ _WT("LUAGC_ֹͣ"), _WT("LUA_GCSTOP"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_GCSTOP },
	{ _WT("LUAGC_����"), _WT("LUA_GCRESTART"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_GCRESTART },
	{ _WT("LUAGC_��������"), _WT("LUA_GCCOLLECT"), _WT("ִ����������������"), LVL_SIMPLE, CT_NUM, NULL, LUA_GCCOLLECT },
	{ _WT("LUAGC_�ڴ�ʹ����"), _WT("LUA_GCCOUNT"), _WT(" ���ص�ǰʹ�õ��ڴ��С(��KBΪ��λ"), LVL_SIMPLE, CT_NUM, NULL, LUA_GCCOUNT },
	{ _WT("LUAGC_�ڴ�ʹ���ֽ���"), _WT("LUA_GCCOUNTB"), _WT(" ���ص�ǰʹ�õ��ڴ��С(���ֽ�Ϊ��λ)"), LVL_SIMPLE, CT_NUM, NULL, LUA_GCCOUNTB },
	{ _WT("LUAGC_����"), _WT("LUA_GCSTEP"), _WT("����ִ����������"), LVL_SIMPLE, CT_NUM, NULL, LUA_GCSTEP },
	{ _WT("LUAGC_����ͣ"), _WT("LUA_GCSETPAUSE"), _WT(" ����������Ϊ����������ͣ����ֵ�������ؾ�ֵ"), LVL_SIMPLE, CT_NUM, NULL, LUA_GCSETPAUSE },
	{ _WT("LUAGC_�ò�������"), _WT("LUA_GCSETSTEPMUL"), _WT("����������Ϊ�������ղ�����������ֵ�������ؾ�ֵ"), LVL_SIMPLE, CT_NUM, NULL, LUA_GCSETSTEPMUL },
	{ _WT("LUAGC_�Ƿ�������"), _WT("LUA_GCISRUNNING"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_GCISRUNNING },

	{ _WT("LUA_ע�������"), _WT("LUA_REGISTRYINDEX"), _WT("ָ��ע��������������"), LVL_SIMPLE, CT_NUM, NULL, LUA_REGISTRYINDEX },
	{ _WT("LUA_RIDX_���߳�"), _WT("LUA_RIDX_MAINTHREAD"), _WT("ע����е����߳�������"), LVL_SIMPLE, CT_NUM, NULL, LUA_RIDX_MAINTHREAD },
	{ _WT("LUA_RIDX_ȫ�ֱ�"), _WT("LUA_RIDX_GLOBALS"), _WT("ע����е�ȫ�ֱ�������"), LVL_SIMPLE, CT_NUM, NULL, LUA_RIDX_GLOBALS },

	{ _WT("LUA_HOOKCALL"), _WT("LUA_HOOKCALL"), _WT("���ù���"), LVL_SIMPLE, CT_NUM, NULL, LUA_HOOKCALL },
	{ _WT("LUA_HOOKRET"), _WT("LUA_HOOKRET"), _WT(""), LVL_SIMPLE, CT_NUM, NULL, LUA_HOOKRET },
	{ _WT("LUA_HOOKLINE"), _WT("LUA_HOOKLINE"), _WT(""), LVL_SIMPLE, CT_NUM, NULL, LUA_HOOKLINE },
	{ _WT("LUA_HOOKCOUNT"), _WT("LUA_HOOKCOUNT"), _WT(""), LVL_SIMPLE, CT_NUM, NULL, LUA_HOOKCOUNT },
	{ _WT("LUA_HOOKTAILCALL"), _WT("LUA_HOOKTAILCALL"), _WT("β���ù���"), LVL_SIMPLE, CT_NUM, NULL, LUA_HOOKTAILCALL },

	{ _WT("LUA_MASKCALL"), _WT("LUA_MASKCALL"), _WT(""), LVL_SIMPLE, CT_NUM, NULL, LUA_MASKCALL },
	{ _WT("LUA_MASKRET"), _WT("LUA_MASKRET"), _WT(""), LVL_SIMPLE, CT_NUM, NULL, LUA_MASKRET },
	{ _WT("LUA_MASKLINE"), _WT("LUA_MASKLINE"), _WT(""), LVL_SIMPLE, CT_NUM, NULL, LUA_MASKLINE },
	{ _WT("LUA_MASKCOUNT"), _WT("LUA_MASKCOUNT"), _WT(""), LVL_SIMPLE, CT_NUM, NULL, LUA_MASKCOUNT },

	{ _WT("LUA_������"), _WT("LUA_REFNIL"), _WT(""), LVL_SIMPLE, CT_NUM, NULL, LUA_REFNIL },
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
	{ _WT("��ֵ����"), _WT("����������>0 (���ǲ���>256)������ջ�е���n��ֵ��Ϊ�հ�����ֵ�������غ���������ʱ���Ի�ȡ��Щֵ��"),0,0, SDT_INT, 0, AS_HAS_DEFAULT_VALUE },
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
	{ _WT("ģʽ"), _WT("binary��text��bt"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
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
ARG_INFO s_arg_lua_gc[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("����"), _WT("LUAGC_ ��ͷ����"),0,0, SDT_INT, 0, NULL },
	{ _WT("����"), _WT(""),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_lua_concat[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������"), _WT("Ҫ���ӵ�ֵ������"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_stringtonumber[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("�ı�"), _WT("ҪתΪΪ��ֵ���ı�"),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_lua_getallocf[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("�����û�����"), _WT("�����������ڴ������ʱ�������û�����"),0,0, SDT_INT, 0, AS_RECEIVE_VAR | AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_lua_setallocf[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("�ڴ���亯��"), _WT("����ֵ�������ͣ������� �û����ݣ������� ָ�룬������ Դ��С�������� �´�С��"),0,0, SDT_INT, 0, NULL },
	{ _WT("�û�����"), _WT("�ڴ����ص������Ĳ���"),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_lua_pop[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("������"), _WT("Ҫ����ջ������"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_register[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("������"), _WT(""),0,0, SDT_TEXT, 0, NULL },
	{ _WT("���غ���"), _WT("����ֵ�������ͣ������� Lua״̬��"),0,0, _SDT_ALL, 0, NULL },
};
ARG_INFO s_arg_lua_pushcfunction[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("���غ���"), _WT("����ֵ�������ͣ������� Lua״̬��"),0,0, _SDT_ALL, 0, NULL },
};
ARG_INFO s_arg_lua_upvalueindex[] =
{
	{ _WT("ջ����"), _WT(""),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_getstack[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("�ȼ�"), _WT("0�ǵ�ǰ������1�ǵ����ߣ��������ơ�"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_freedebugptr[] =
{
	{ _WT("����ָ��"), _WT("�� LUA_ȡջָ�루�����ص�ָ��"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_getinfo[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("�ı�����"), _WT("what"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("����ָ��"), _WT("�� LUA_ȡջָ�루�����ص�ָ�� �� ����HOOK �ص������Ĳ����ĵ���ָ��"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_getlocal[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("����ָ��"), _WT("�� LUA_ȡջָ�루�����ص�ָ�� �� ����HOOK �ص������Ĳ����ĵ���ָ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������"), _WT("1��ʾ��һ��������2��ʾ�ڶ������Դ����ơ�-1��ʾvararg����"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_getupvalue[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������"), _WT("�������ڵ�ջ����"),0,0, SDT_INT, 0, NULL },
	{ _WT("��ֵ����"), _WT("1��ʾ��һ����ֵ"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_upvaluejoin[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������1"), _WT("�������ڵ�ջ����"),0,0, SDT_INT, 0, NULL },
	{ _WT("��ֵ����1"), _WT("1��ʾ��һ����ֵ"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������2"), _WT("�������ڵ�ջ����"),0,0, SDT_INT, 0, NULL },
	{ _WT("��ֵ����2"), _WT("1��ʾ��һ����ֵ"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_sethook[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("���Ӻ���"), _WT("����ֵ���ޣ������� Lua״̬�������� ����ָ�룩"),0,0, _SDT_ALL, 0, NULL },
	{ _WT("����"), _WT("LUA_MASK ��ͷ����"),0,0, SDT_INT, 0, NULL },
	{ _WT("����"), _WT("count"),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_luaL_getmetafield[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������"), _WT("obj"),0,0, _SDT_ALL, 0, NULL },
	{ _WT("�ֶ���"), _WT("e"),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_luaL_tolstring[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("���س���"), _WT(""),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY | AS_RECEIVE_VAR },
};
ARG_INFO s_arg_luaL_argerror[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("����ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("������Ϣ"), _WT(""),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_luaL_checklstring[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������"), _WT("1��ʾ��һ������"),0,0, SDT_INT, 0, NULL },
	{ _WT("���س���"), _WT(""),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY | AS_RECEIVE_VAR },
};
ARG_INFO s_arg_luaL_optlstring[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������"), _WT("1��ʾ��һ������"),0,0, SDT_INT, 0, NULL },
	{ _WT("Ĭ��ֵ"), _WT(""),0,0, SDT_TEXT, 0, NULL },
	{ _WT("���س���"), _WT(""),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY | AS_RECEIVE_VAR },
};
ARG_INFO s_arg_luaL_arg[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������"), _WT("1��ʾ��һ������"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_luaL_optnumber[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������"), _WT("1��ʾ��һ������"),0,0, SDT_INT, 0, NULL },
	{ _WT("Ĭ��ֵ"), _WT(""),0,0, SDT_DOUBLE, 0, NULL },
};
ARG_INFO s_arg_luaL_optinteger[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������"), _WT("1��ʾ��һ������"),0,0, SDT_INT, 0, NULL },
	{ _WT("Ĭ��ֵ"), _WT(""),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_luaL_checkstack[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("��С"), _WT("Ҫ����ջԪ�صĴ�С"),0,0, SDT_INT, 0, NULL },
	{ _WT("�����ı�"), _WT("����������ʱ�ĸ�����Ϣ"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_luaL_checktype[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������"), _WT("1��ʾ��һ������"),0,0, SDT_INT, 0, NULL },
	{ _WT("����"), _WT("LUA����_ ��ͷ����"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_luaL_newmetatable[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("������"), _WT("tname"),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_luaL_testudata[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������"), _WT("1��ʾ��һ������"),0,0, SDT_INT, 0, NULL },
	{ _WT("������"), _WT("tname"),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_luaL_where[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("�ȼ�"), _WT("0��ʾ��ǰ������1��ʾ������"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_luaL_error[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("�����ı�"), _WT(""),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_luaL_checkoption[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������"), _WT("1��ʾ��һ������"),0,0, SDT_INT, 0, NULL },
	{ _WT("Ĭ��ֵ"), _WT("def"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
	{ _WT("ѡ��"), _WT("option"),0,0, SDT_TEXT, 0, AS_RECEIVE_ARRAY_DATA},
};
ARG_INFO s_arg_luaL_ref[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("��ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_luaL_unref[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("��ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("���ö���"), _WT("�� LUAL_���ã�������"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_luaL_loadfilex[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("�ļ���"), _WT("�ű��ļ���"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("ģʽ"), _WT("binary��text��bt"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_luaL_loadbufferx[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("�ű�����"), _WT(""),0,0, _SDT_ALL, 0, NULL },
	{ _WT("������"), _WT("���ڴ�����Ϣ�͵�����Ϣ"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("ģʽ"), _WT("binary��text��bt"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_luaL_loadstring[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("�ı��ű�"), _WT(""),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_luaL_gsub[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("Դ�ı�"), _WT(""),0,0, SDT_TEXT, 0, NULL },
	{ _WT("Ҫ�滻�����ı�"), _WT(""),0,0, SDT_TEXT, 0, NULL },
	{ _WT("�����滻���ı�"), _WT(""),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_luaL_setfuncs[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("ע������"), _WT("LUA_ע�� �ṹ������"),0,0, DTP_LUA_REG, 0, AS_RECEIVE_ARRAY_DATA },
	{ _WT("��ֵ��"), _WT("����˲���>0������ע��֮ǰ����ջ��ѹ����ͬ������ֵ������Ϊ���к�������ֵ��"),0,0, SDT_INT, 0, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_luaL_getsubtable[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("ָ��tableֵ��ջ����"),0,0, SDT_INT, 0, NULL },
	{ _WT("����"), _WT("fname"),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_luaL_traceback[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("Lua״̬1"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("��Ϣ"), _WT("msg"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
	{ _WT("�ȼ�"), _WT("level"),0,0, SDT_INT, 1, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_luaL_requiref[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("ģ����"), _WT("modname"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("��������"), _WT("openf"),0,0, _SDT_ALL, 0, NULL },
	{ _WT("ȫ��"), _WT("glb"),0,0, SDT_BOOL },
};
ARG_INFO s_arg_luaL_newlibtable[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("ע������"), _WT("LUA_ע�� �ṹ������"),0,0, DTP_LUA_REG, 0, AS_RECEIVE_ARRAY_DATA },
};
ARG_INFO s_arg_luaL_argcheck[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("����"), _WT(""),0,0, SDT_BOOL, 0, NULL },
	{ _WT("��������"), _WT("1��ʾ��һ������"),0,0, SDT_INT, 0, NULL },
	{ _WT("������Ϣ"), _WT(""),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_luaL_dofile[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("�ļ���"), _WT(""),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_luaL_dostring[] =
{
	{ _WT("Lua״̬"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("�ű��ı�"), _WT(""),0,0, SDT_TEXT, 0, NULL },
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
		/*ccname*/	_WT("LUA_ѹ��հ�"),
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
		/*egname*/	_WT("lua_pcallK"),
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
		/*ccname*/	_WT("LUA_��ȫ����"),
		/*egname*/	_WT("lua_pcall"),
		/*explain*/ _WT("����һ������������������һ��������հ�������֮ǰ�������Ͳ���ѹ��ջ��������Ϻ�����ͺ������ᵯ��ջ������ָ�������ķ���ֵѹ��ջ��"),
		/*category*/cmd_type_idx_load_and_call_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_pcall) / sizeof(s_arg_lua_pcall[0]),
		/*arg lp*/	s_arg_lua_pcall,
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
		/*explain*/ _WT("��ͣ�������е�Э�̣����� 'LUA_�ָ�' ���أ����� LUA_ ��ͷ������\r\n����������ֵ��������ջ�н���Ϊ������ݸ� LUA_���� ֵ��������\r\n��Э���ٴλָ�ʱ��Lua���ø�����'��������'����ִ�С��˼���������ǰһ������������ͬ��ջ��ɾ��n��������滻Ϊ���ݸ� 'LUA_�ָ�' �Ĳ��������⣬�����������մ��ݸ� LUA_��ͣ ��������ֵ��"),
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
		/*explain*/ _WT("�ڸ������߳��п�ʼ���ָ�Э�̣����� LUA_ ��ͷ������\r\nҪ����һ��Э�̣�����Խ������������κβ���ѹ�뵽�߳�ջ; Ȼ����� LUA_�ָ�����Э����ͣ�������ִ��ʱ���˵��ý����ء� ����ʱ��ջ����'LUA_��ͣ'���ݵ�����ֵ�� ���Э����ͣ����'LUA_�ָ�'����LUA_YIELD�����Э�����ִ��û�д����򷵻�LUA_OK��������ִ����򷵻ش�����롣"),
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
	{
		/*ccname*/	_WT("LUA_ȡ״̬"),
		/*egname*/	_WT("lua_status"),
		/*explain*/ _WT("�����߳�״̬�� LUA_ ��ͷ������"),
		/*category*/cmd_type_idx_coroutine_functions,
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
		/*ccname*/	_WT("LUA_�Ƿ���ͣ"),
		/*egname*/	_WT("lua_isyieldable"),
		/*explain*/ _WT(""),
		/*category*/cmd_type_idx_coroutine_functions,
		/*state*/	0,
		/*ret*/		SDT_BOOL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua) / sizeof(s_arg_lua[0]),
		/*arg lp*/	s_arg_lua,
	},

	//////////////////////////////////////////////////////////////////////////��������

	{
		/*ccname*/	_WT("LUA_��������"),
		/*egname*/	_WT("lua_gc"),
		/*explain*/ _WT("������������������"),
		/*category*/cmd_type_idx_gc_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_gc) / sizeof(s_arg_lua_gc[0]),
		/*arg lp*/	s_arg_lua_gc,
	},

	//////////////////////////////////////////////////////////////////////////�������

	{
		/*ccname*/	_WT("LUA_�ô���"),
		/*egname*/	_WT("lua_error"),
		/*explain*/ _WT("��ջ����ֵ����ΪLUA����"),
		/*category*/cmd_type_idx_miscellaneous_functions,
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
		/*ccname*/	_WT("LUA_��һ��"),
		/*egname*/	_WT("lua_next"),
		/*explain*/ _WT("��ջ�е���һ������Ȼ��ѹ��һ������һ��ֵ�����ֵ���ǲ�����ջ������ָ��ı�ĳ�Ա���������û�г�Ա�ˣ�����0"),
		/*category*/cmd_type_idx_miscellaneous_functions,
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
		/*ccname*/	_WT("LUA_����"),
		/*egname*/	_WT("lua_concat"),
		/*explain*/ _WT("��ջ�е���n��ֵ��Ȼ������������ѹ�뵽ջ�С����n=1�������κδ������n=0����ѹ����ַ�����"),
		/*category*/cmd_type_idx_miscellaneous_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_concat) / sizeof(s_arg_lua_concat[0]),
		/*arg lp*/	s_arg_lua_concat,
	},
	{
		/*ccname*/	_WT("LUA_ȡ����"),
		/*egname*/	_WT("lua_len"),
		/*explain*/ _WT("��'ջ����'ָ����ֵ�ĳ��ȣ�ѹ�뵽ջ�У����ܻᴥ��'length'Ԫ������"),
		/*category*/cmd_type_idx_miscellaneous_functions,
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
		/*ccname*/	_WT("LUA_�ı�����ֵ"),
		/*egname*/	_WT("lua_stringtonumber"),
		/*explain*/ _WT("��'�ı�'ת��Ϊ��ֵ����ѹ�뵽ջ�У�����0��ʾʧ�ܣ����򷵻��ı��ܳ���(��\0)��"),
		/*category*/cmd_type_idx_miscellaneous_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_stringtonumber) / sizeof(s_arg_lua_stringtonumber[0]),
		/*arg lp*/	s_arg_lua_stringtonumber,
	},
	{
		/*ccname*/	_WT("LUA_ȡ�ڴ������"),
		/*egname*/	_WT("lua_getallocf"),
		/*explain*/ _WT("�������õ��ڴ����ص�������"),
		/*category*/cmd_type_idx_miscellaneous_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_getallocf) / sizeof(s_arg_lua_getallocf[0]),
		/*arg lp*/	s_arg_lua_getallocf,
	},
	{
		/*ccname*/	_WT("LUA_���ڴ������"),
		/*egname*/	_WT("lua_setallocf"),
		/*explain*/ _WT("���õ��ڴ����ص�������"),
		/*category*/cmd_type_idx_miscellaneous_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_setallocf) / sizeof(s_arg_lua_setallocf[0]),
		/*arg lp*/	s_arg_lua_setallocf,
	},

	//////////////////////////////////////////////////////////////////////////ʵ�ú���

	{
		/*ccname*/	_WT("LUA_ȡ��չ�ռ�"),
		/*egname*/	_WT("lua_getextraspace"),
		/*explain*/ _WT("������Lua״̬�����Ķ���ռ�ָ�룬��С��һ��ָ��Ĵ�С"),
		/*category*/cmd_type_idx_useful_functions,
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
		/*ccname*/	_WT("LUA_����ֵ"),
		/*egname*/	_WT("lua_tonumber"),
		/*explain*/ _WT("����ջ������λ�õ�ֵת��Ϊ˫����С���͡�"),
		/*category*/cmd_type_idx_useful_functions,
		/*state*/	0,
		/*ret*/		SDT_DOUBLE,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_idx) / sizeof(s_arg_lua_idx[0]),
		/*arg lp*/	s_arg_lua_idx,
	},
	{
		/*ccname*/	_WT("LUA_������"),
		/*egname*/	_WT("lua_tointeger"),
		/*explain*/ _WT("����ջ������λ�õ�ֵת��Ϊ�����͡�"),
		/*category*/cmd_type_idx_useful_functions,
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
		/*ccname*/	_WT("LUA_����"),
		/*egname*/	_WT("lua_pop"),
		/*explain*/ _WT("����ָ��������Ԫ�ء�"),
		/*category*/cmd_type_idx_useful_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_pop) / sizeof(s_arg_lua_pop[0]),
		/*arg lp*/	s_arg_lua_pop,
	},
	{
		/*ccname*/	_WT("LUA_�½���"),
		/*egname*/	_WT("lua_newtable"),
		/*explain*/ _WT("����һ������ѹ�뵽ջ�С�"),
		/*category*/cmd_type_idx_useful_functions,
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
		/*ccname*/	_WT("LUA_ע�ắ��"),
		/*egname*/	_WT("lua_register"),
		/*explain*/ _WT("ע��һ��ȫ�ֺ�����"),
		/*category*/cmd_type_idx_useful_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_register) / sizeof(s_arg_lua_register[0]),
		/*arg lp*/	s_arg_lua_register,
	},
	{
		/*ccname*/	_WT("LUA_ѹ�뺯��"),
		/*egname*/	_WT("lua_pushcfunction"),
		/*explain*/ _WT("��һ�����غ���ѹ�뵽ջ�С�"),
		/*category*/cmd_type_idx_useful_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_pushcfunction) / sizeof(s_arg_lua_pushcfunction[0]),
		/*arg lp*/	s_arg_lua_pushcfunction,
	},
	{
		/*ccname*/	_WT("LUA_�Ƿ���"),
		/*egname*/	_WT("lua_isfunction"),
		/*explain*/ _WT("���ء�ջ������ָ���ֵ�Ƿ�Ϊ������"),
		/*category*/cmd_type_idx_useful_functions,
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
		/*ccname*/	_WT("LUA_�Ƿ��"),
		/*egname*/	_WT("lua_istable"),
		/*explain*/ _WT("���ء�ջ������ָ���ֵ�Ƿ�Ϊ��"),
		/*category*/cmd_type_idx_useful_functions,
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
		/*ccname*/	_WT("LUA_�Ƿ��û�ָ��"),
		/*egname*/	_WT("lua_islightuserdata"),
		/*explain*/ _WT("���ء�ջ������ָ���ֵ�Ƿ�Ϊ�û�ָ�롣"),
		/*category*/cmd_type_idx_useful_functions,
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
		/*ccname*/	_WT("LUA_�Ƿ��"),
		/*egname*/	_WT("lua_isnil"),
		/*explain*/ _WT("���ء�ջ������ָ���ֵ�Ƿ�Ϊ�ա�"),
		/*category*/cmd_type_idx_useful_functions,
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
		/*ccname*/	_WT("LUA_�Ƿ��߼���"),
		/*egname*/	_WT("lua_isboolean"),
		/*explain*/ _WT("���ء�ջ������ָ���ֵ�Ƿ�Ϊ�߼��͡�"),
		/*category*/cmd_type_idx_useful_functions,
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
		/*ccname*/	_WT("LUA_�Ƿ��߳�"),
		/*egname*/	_WT("lua_isthread"),
		/*explain*/ _WT("���ء�ջ������ָ���ֵ�Ƿ�Ϊ�̡߳�"),
		/*category*/cmd_type_idx_useful_functions,
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
		/*ccname*/	_WT("LUA_�Ƿ�δ֪"),
		/*egname*/	_WT("lua_isnone"),
		/*explain*/ _WT("���ء�ջ������ָ���ֵ�Ƿ�δ֪��"),
		/*category*/cmd_type_idx_useful_functions,
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
		/*ccname*/	_WT("LUA_�Ƿ�δ֪���"),
		/*egname*/	_WT("lua_isnoneornil"),
		/*explain*/ _WT("���ء�ջ������ָ���ֵ�Ƿ�δ֪��ա�"),
		/*category*/cmd_type_idx_useful_functions,
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
		/*ccname*/	_WT("LUA_ѹ��ȫ�ֱ�"),
		/*egname*/	_WT("lua_pushglobaltable"),
		/*explain*/ _WT("��ȫ�ֻ�����ѹ�뵽ջ�С�"),
		/*category*/cmd_type_idx_useful_functions,
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
		/*ccname*/	_WT("LUA_����"),
		/*egname*/	_WT("lua_insert"),
		/*explain*/ _WT("��ջ����Ԫ���ƶ���������ջ������λ���У�֮ǰ�ġ�ջ������Ԫ�����ơ�"),
		/*category*/cmd_type_idx_useful_functions,
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
		/*ccname*/	_WT("LUA_�Ƴ�"),
		/*egname*/	_WT("lua_remove"),
		/*explain*/ _WT("�Ƴ���ջ������λ�õ�Ԫ�أ������Ԫ�����ơ�"),
		/*category*/cmd_type_idx_useful_functions,
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
		/*ccname*/	_WT("LUA_�滻"),
		/*egname*/	_WT("lua_replace"),
		/*explain*/ _WT("��ջ����Ԫ���ƶ�����ջ������λ�ã�������ջ��Ԫ�ء�"),
		/*category*/cmd_type_idx_useful_functions,
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
		/*ccname*/	_WT("LUA_ȡ��ֵ����"),
		/*egname*/	_WT("lua_upvalueindex"),
		/*explain*/ _WT("��ȡ�հ���ֵ������������"),
		/*category*/cmd_type_idx_useful_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_upvalueindex) / sizeof(s_arg_lua_upvalueindex[0]),
		/*arg lp*/	s_arg_lua_upvalueindex,
	},

	//////////////////////////////////////////////////////////////////////////���Խӿ�

	{
		/*ccname*/	_WT("LUA_ȡջ����ָ��"),
		/*egname*/	_WT("lua_getstack"),
		/*explain*/ _WT("��ȡ�йؽ���������ʱջ����Ϣ�ĵ���ָ�룬�ɹ��������ָ�룬��ʹ�ú���Ҫ���� LUA_�ͷŵ���ָ�루����ʧ�ܷ���0��"),
		/*category*/cmd_type_idx_debug_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_getstack) / sizeof(s_arg_lua_getstack[0]),
		/*arg lp*/	s_arg_lua_getstack,
	},
	{
		/*ccname*/	_WT("LUA_�ͷŵ���ָ��"),
		/*egname*/	_WT("lua_freedebugptr"),
		/*explain*/ _WT("�ͷ��� LUA_ȡջ����ָ��() ���ص�ָ��"),
		/*category*/cmd_type_idx_debug_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_freedebugptr) / sizeof(s_arg_lua_freedebugptr[0]),
		/*arg lp*/	s_arg_lua_freedebugptr,
	},
	{
		/*ccname*/	_WT("LUA_ȡ������Ϣ"),
		/*egname*/	_WT("lua_getinfo"),
		/*explain*/ _WT("����һ��ָ���ĺ����������õĵ�����Ϣ�ṹ�塣\r\n���ڻ�ȡһ����������Ϣʱ�����԰��������ѹ��ջ��Ȼ��� '�ı�����' �������ַ� '>' ��ͷ�����������£�LUA_ȡ������Ϣ ��ջ���ϵ�����������\r\n'�ı�����' �����е�ÿ���ַ���ɸѡ���ṹ LUA_������Ϣ �ṹ��һЩ��������䣬���ǰ�һ��ֵѹ��ջ��\r\n'n': ��� name �� namewhat ��\r\n'S': ��� source�� short_src��linedefined��lastlinedefined���Լ� what ��\r\n'l': ��� currentline ��\r\n'u': ��� nups ��\r\n'f': ������������ָ�����𴦺���ѹ���ջ��\r\n'L': ѹһ�� table ��ջ����� table �е�������������������������Щ������Ч�С� "),
		/*category*/cmd_type_idx_debug_functions,
		/*state*/	0,
		/*ret*/		DTP_LUA_DEBUG,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_getinfo) / sizeof(s_arg_lua_getinfo[0]),
		/*arg lp*/	s_arg_lua_getinfo,
	},
	{
		/*ccname*/	_WT("LUA_ȡ����"),
		/*egname*/	_WT("lua_getlocal"),
		/*explain*/ _WT("���һ���ֲ���������������ֵѹ��ջ�����ҷ��ر�����"),
		/*category*/cmd_type_idx_debug_functions,
		/*state*/	0,
		/*ret*/		SDT_TEXT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_getlocal) / sizeof(s_arg_lua_getlocal[0]),
		/*arg lp*/	s_arg_lua_getlocal,
	},
	{
		/*ccname*/	_WT("LUA_�ñ���"),
		/*egname*/	_WT("lua_setlocal"),
		/*explain*/ _WT("��ջ������һ��ֵ��ֵ�����������ҷ��ر�������"),
		/*category*/cmd_type_idx_debug_functions,
		/*state*/	0,
		/*ret*/		SDT_TEXT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_getlocal) / sizeof(s_arg_lua_getlocal[0]),
		/*arg lp*/	s_arg_lua_getlocal,
	},
	{
		/*ccname*/	_WT("LUA_ȡ��ֵ"),
		/*egname*/	_WT("lua_getupvalue"),
		/*explain*/ _WT("���һ����ֵ������ֵ��ֵѹ��ջ�����ҷ��ر�������"),
		/*category*/cmd_type_idx_debug_functions,
		/*state*/	0,
		/*ret*/		SDT_TEXT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_getupvalue) / sizeof(s_arg_lua_getupvalue[0]),
		/*arg lp*/	s_arg_lua_getupvalue,
	},
	{
		/*ccname*/	_WT("LUA_����ֵ"),
		/*egname*/	_WT("lua_getupvalue"),
		/*explain*/ _WT("��ջ������һ��ֵ��ֵ����ֵ�����ҷ��ر�������"),
		/*category*/cmd_type_idx_debug_functions,
		/*state*/	0,
		/*ret*/		SDT_TEXT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_getupvalue) / sizeof(s_arg_lua_getupvalue[0]),
		/*arg lp*/	s_arg_lua_getupvalue,
	},
	{
		/*ccname*/	_WT("LUA_ȡ��ֵID"),
		/*egname*/	_WT("lua_upvalueid"),
		/*explain*/ _WT("����һ����ֵ��ID��"),
		/*category*/cmd_type_idx_debug_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_getupvalue) / sizeof(s_arg_lua_getupvalue[0]),
		/*arg lp*/	s_arg_lua_getupvalue,
	},
	{
		/*ccname*/	_WT("LUA_��ֵ����"),
		/*egname*/	_WT("lua_upvaluejoin"),
		/*explain*/ _WT("������������1��ָ������ֵָ�򡮺�������2��ָ������ֵ��"),
		/*category*/cmd_type_idx_debug_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_upvaluejoin) / sizeof(s_arg_lua_upvaluejoin[0]),
		/*arg lp*/	s_arg_lua_upvaluejoin,
	},
	{
		/*ccname*/	_WT("LUA_�ù���"),
		/*egname*/	_WT("lua_sethook"),
		/*explain*/ _WT("���õ��Թ��ӻص�������"),
		/*category*/cmd_type_idx_debug_functions,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua_sethook) / sizeof(s_arg_lua_sethook[0]),
		/*arg lp*/	s_arg_lua_sethook,
	},
	{
		/*ccname*/	_WT("LUA_ȡ����"),
		/*egname*/	_WT("lua_gethook"),
		/*explain*/ _WT("��ȡ���Թ��ӻص�������"),
		/*category*/cmd_type_idx_debug_functions,
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
		/*ccname*/	_WT("LUA_ȡ��������"),
		/*egname*/	_WT("lua_gethookmask"),
		/*explain*/ _WT("��ȡ���Թ������룬���� LUA_HOOK ��ͷ������"),
		/*category*/cmd_type_idx_debug_functions,
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
		/*ccname*/	_WT("LUA_ȡ������"),
		/*egname*/	_WT("lua_gethookcount"),
		/*explain*/ _WT("��ȡ���Թ�������"),
		/*category*/cmd_type_idx_debug_functions,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_lua) / sizeof(s_arg_lua[0]),
		/*arg lp*/	s_arg_lua,
	},
	//////////////////////////////////////////////////////////////////////////������
	{
		/*ccname*/	_WT("LUAL_���汾"),
		/*egname*/	_WT("luaL_checkversion"),
		/*explain*/ _WT("������е��õĺ��ģ�����Lua״̬�ĺ����Լ����е��õĴ����Ƿ�ʹ����ͬ�汾��Lua��"),
		/*category*/cmd_type_idx_auxiliary_library,
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
		/*ccname*/	_WT("LUAL_ȡԪ���ֶ�"),
		/*egname*/	_WT("luaL_getmetafield"),
		/*explain*/ _WT("��'��������'�е�Ԫ���ȡָ���ֶΣ���ѹ�뵽ջ�У������ֶ����͡�"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_getmetafield) / sizeof(s_arg_luaL_getmetafield[0]),
		/*arg lp*/	s_arg_luaL_getmetafield,
	},
	{
		/*ccname*/	_WT("LUAL_����Ԫ����"),
		/*egname*/	_WT("luaL_callmeta"),
		/*explain*/ _WT("���'��������'���Ķ������metatable���Ҵ���'�ֶ���'����˺������ô��ֶν�������Ϊ��Ψһ�������ݡ� ����������£��˺��������棬�������÷��ص�ֵѹ��ջ�� ���û��metatable��û��metamethod����˺������ؼ٣�����ջ��ѹ���κ�ֵ����"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		SDT_BOOL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_getmetafield) / sizeof(s_arg_luaL_getmetafield[0]),
		/*arg lp*/	s_arg_luaL_getmetafield,
	},
	{
		/*ccname*/	_WT("LUAL_���ı�"),
		/*egname*/	_WT("luaL_tolstring"),
		/*explain*/ _WT("��'ջ����'ָ����ֵתΪΪ�ַ�����ѹ��ջ�����ɺ������ء����ֵ����__tostring Ԫ���������ֵ��Ϊ�������ݸ�Ԫ��������ʹ�õ��õĽ����"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		SDT_TEXT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_tolstring) / sizeof(s_arg_luaL_tolstring[0]),
		/*arg lp*/	s_arg_luaL_tolstring,
	},
	{
		/*ccname*/	_WT("LUAL_��������"),
		/*egname*/	_WT("luaL_argerror"),
		/*explain*/ _WT("������������ı��档"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_argerror) / sizeof(s_arg_luaL_argerror[0]),
		/*arg lp*/	s_arg_luaL_argerror,
	},
	{
		/*ccname*/	_WT("LUAL_����ı�"),
		/*egname*/	_WT("luaL_checklstring"),
		/*explain*/ _WT("��麯�������Ƿ�Ϊ�ַ��������ظ��ַ�����"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		SDT_TEXT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_checklstring) / sizeof(s_arg_luaL_checklstring[0]),
		/*arg lp*/	s_arg_luaL_checklstring,
	},
	{
		/*ccname*/	_WT("LUAL_ѡ���ı�"),
		/*egname*/	_WT("luaL_optlstring"),
		/*explain*/ _WT("����������ַ������򷵻ظ��ַ�������������ַ�����Ϊ�գ��򷵻ز�����Ĭ��ֵ���������������������"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		SDT_TEXT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_checklstring) / sizeof(s_arg_luaL_checklstring[0]),
		/*arg lp*/	s_arg_luaL_checklstring,
	},
	{
		/*ccname*/	_WT("LUAL_�����ֵ"),
		/*egname*/	_WT("luaL_checknumber"),
		/*explain*/ _WT("��麯�������Ƿ�Ϊ��ֵ�����ظ���ֵ��"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		SDT_DOUBLE,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_arg) / sizeof(s_arg_luaL_arg[0]),
		/*arg lp*/	s_arg_luaL_arg,
	},
	{
		/*ccname*/	_WT("LUAL_ѡ����ֵ"),
		/*egname*/	_WT("luaL_optnumber"),
		/*explain*/ _WT("�����������ֵ���򷵻ظ���ֵ�����������ֵ��Ϊ�գ��򷵻ز�����Ĭ��ֵ���������������������"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		SDT_DOUBLE,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_arg) / sizeof(s_arg_luaL_arg[0]),
		/*arg lp*/	s_arg_luaL_arg,
	},
	{
		/*ccname*/	_WT("LUAL_�������"),
		/*egname*/	_WT("luaL_checkinteger"),
		/*explain*/ _WT("��麯�������Ƿ�Ϊ���������ظ�������"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_arg) / sizeof(s_arg_luaL_arg[0]),
		/*arg lp*/	s_arg_luaL_arg,
	},
	{
		/*ccname*/	_WT("LUAL_ѡ������"),
		/*egname*/	_WT("luaL_optinteger"),
		/*explain*/ _WT("����������������򷵻ظ��������������������Ϊ�գ��򷵻ز�����Ĭ��ֵ���������������������"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_optinteger) / sizeof(s_arg_luaL_optinteger[0]),
		/*arg lp*/	s_arg_luaL_optinteger,
	},
	{
		/*ccname*/	_WT("LUAL_���ջ"),
		/*egname*/	_WT("luaL_checkstack"),
		/*explain*/ _WT("��ջ���ӵ� ջ��+����'��С' ��Ԫ�ء�����޷����ӵ��ô�С�����������󣬲����������ı����Ǹ���������Ϣ��"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_checkstack) / sizeof(s_arg_luaL_checkstack[0]),
		/*arg lp*/	s_arg_luaL_checkstack,
	},
	{
		/*ccname*/	_WT("LUAL_�������"),
		/*egname*/	_WT("luaL_checktype"),
		/*explain*/ _WT("�������Ƿ����ָ�����͡�"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_checktype) / sizeof(s_arg_luaL_checktype[0]),
		/*arg lp*/	s_arg_luaL_checktype,
	},
	{
		/*ccname*/	_WT("LUAL_�����������"),
		/*egname*/	_WT("luaL_checkany"),
		/*explain*/ _WT("�������Ƿ�����������ͣ�����nil��"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_arg) / sizeof(s_arg_luaL_arg[0]),
		/*arg lp*/	s_arg_luaL_arg,
	},
	{
		/*ccname*/	_WT("LUAL_�½�Ԫ��"),
		/*egname*/	_WT("luaL_newmetatable"),
		/*explain*/ _WT("��ע������½�Ԫ����Ϊuserdata��Ԫ�����'������'�Ѿ����ڣ��򷵻ؼ١���������������Ԫ��ѹ�뵽ջ��"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		SDT_BOOL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_newmetatable) / sizeof(s_arg_luaL_newmetatable[0]),
		/*arg lp*/	s_arg_luaL_newmetatable,
	},
	{
		/*ccname*/	_WT("LUAL_��Ԫ��"),
		/*egname*/	_WT("luaL_setmetatable"),
		/*explain*/ _WT("��ջ�������Ԫ������Ϊע��������������������Ԫ��"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_newmetatable) / sizeof(s_arg_luaL_newmetatable[0]),
		/*arg lp*/	s_arg_luaL_newmetatable,
	},
	{
		/*ccname*/	_WT("LUAL_�����û�����"),
		/*egname*/	_WT("luaL_testudata"),
		/*explain*/ _WT("����û������Ƿ�ָ���ġ����������������ظ��û�����ָ�롣ʧ�ܷ���0"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_testudata) / sizeof(s_arg_luaL_testudata[0]),
		/*arg lp*/	s_arg_luaL_testudata,
	},
	{
		/*ccname*/	_WT("LUAL_����û�����"),
		/*egname*/	_WT("luaL_checkudata"),
		/*explain*/ _WT("����û������Ƿ�ָ���ġ����������������ظ��û�����ָ�롣ʧ�ܻᷢ���쳣��"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_testudata) / sizeof(s_arg_luaL_testudata[0]),
		/*arg lp*/	s_arg_luaL_testudata,
	},
	{
		/*ccname*/	_WT("LUAL_�δ�"),
		/*egname*/	_WT("luaL_where"),
		/*explain*/ _WT("ѹ��һ���ַ��������ַ�����������ջָ���ȼ��е�λ�á���ʽ�ǣ�chunkname:currentline:"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_where) / sizeof(s_arg_luaL_where[0]),
		/*arg lp*/	s_arg_luaL_where,
	},
	{
		/*ccname*/	_WT("LUAL_����"),
		/*egname*/	_WT("luaL_error"),
		/*explain*/ _WT("����һ������"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_error) / sizeof(s_arg_luaL_error[0]),
		/*arg lp*/	s_arg_luaL_error,
	},
	{
		/*ccname*/	_WT("LUAL_���ѡ��"),
		/*egname*/	_WT("luaL_checkoption"),
		/*explain*/ _WT("�������Ƿ�Ϊһ���ַ�������������ڲ�����ѡ����������������ҵ���������������������ַ������޷��ڡ�ѡ����ҵ����������쳣��\r\n���ָ���˲�����Ĭ��ֵ�����򵱲��������ַ�����Ϊnil��ʱ��ʹ�ô�Ĭ��ֵ����ѡ��в��ҡ�"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_checkoption) / sizeof(s_arg_luaL_checkoption[0]),
		/*arg lp*/	s_arg_luaL_checkoption,
	},
	{
		/*ccname*/	_WT("LUAL_����"),
		/*egname*/	_WT("luaL_ref"),
		/*explain*/ _WT("�ڡ���ջ�������ı��д���������ջ������������ã�������ջ���Ķ��󣩡�����ֵ��Ψһ�ģ����Կ������ڱ��е����������ջ�����Ķ�����nil���򷵻� LUA_�����á�"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_ref) / sizeof(s_arg_luaL_ref[0]),
		/*arg lp*/	s_arg_luaL_ref,
	},
	{
		/*ccname*/	_WT("LUAL_�ͷ�����"),
		/*egname*/	_WT("luaL_unref"),
		/*explain*/ _WT("�ͷš���ջ�������ı����ͷ����ö��󣬴ӱ���ɾ�����Ա�����������ա�"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_unref) / sizeof(s_arg_luaL_unref[0]),
		/*arg lp*/	s_arg_luaL_unref,
	},
	{
		/*ccname*/	_WT("LUAL_�����ļ�"),
		/*egname*/	_WT("luaL_loadfilex"),
		/*explain*/ _WT("���ļ�������һ��lua�ű������ǲ������������û�д�������Ϊ����ѹ�뵽ջ�У�����ѹ��һ��������Ϣ������ LUA_ ��ͷ������"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_loadfilex) / sizeof(s_arg_luaL_loadfilex[0]),
		/*arg lp*/	s_arg_luaL_loadfilex,
	},
	{
		/*ccname*/	_WT("LUAL_��������"),
		/*egname*/	_WT("luaL_loadbufferx"),
		/*explain*/ _WT("���ڴ�������һ��lua�ű������ǲ������������û�д�������Ϊ����ѹ�뵽ջ�У�����ѹ��һ��������Ϣ������ LUA_ ��ͷ������"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_loadbufferx) / sizeof(s_arg_luaL_loadbufferx[0]),
		/*arg lp*/	s_arg_luaL_loadbufferx,
	},
	{
		/*ccname*/	_WT("LUAL_�����ı�"),
		/*egname*/	_WT("luaL_loadstring"),
		/*explain*/ _WT("���ı�������һ��lua�ű������ǲ������������û�д�������Ϊ����ѹ�뵽ջ�У�����ѹ��һ��������Ϣ������ LUA_ ��ͷ������"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_loadstring) / sizeof(s_arg_luaL_loadstring[0]),
		/*arg lp*/	s_arg_luaL_loadstring,
	},
	{
		/*ccname*/	_WT("LUAL_�½�״̬"),
		/*egname*/	_WT("luaL_newstate"),
		/*explain*/ _WT("����һ�����߳�ִ��״̬���ɹ�����lua_Stateָ�룬ʧ�ܷ���0��"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/0,
		/*arg lp*/	NULL,
	},
	{
		/*ccname*/	_WT("LUAL_ȡ����"),
		/*egname*/	_WT("luaL_len"),
		/*explain*/ _WT("����ָ��'ջ����'��'length'ֵ��"),
		/*category*/cmd_type_idx_auxiliary_library,
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
		/*ccname*/	_WT("LUAL_���ı��滻"),
		/*egname*/	_WT("luaL_gsub"),
		/*explain*/ _WT("���滻����ı�ѹ�뵽ջ�У�����������"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		SDT_TEXT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_gsub) / sizeof(s_arg_luaL_gsub[0]),
		/*arg lp*/	s_arg_luaL_gsub,
	},
	{
		/*ccname*/	_WT("LUAL_�ú�������"),
		/*egname*/	_WT("luaL_setfuncs"),
		/*explain*/ _WT("ע�������е����к�����ջ��λ�õı��С�"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_setfuncs) / sizeof(s_arg_luaL_setfuncs[0]),
		/*arg lp*/	s_arg_luaL_setfuncs,
	},
	{
		/*ccname*/	_WT("LUAL_ȡ�ӱ�"),
		/*egname*/	_WT("luaL_getsubtable"),
		/*explain*/ _WT("ȷ�� t[����] ��ֵ��һ����(t �ǲ���'ջ����'ָ��ı�)������ֵѹ�뵽ջ�С��������ʾ�ҵ�֮ǰ�ı�����ʾ�������±�"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		SDT_BOOL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
/*bmp inx*/	0,
/*bmp num*/	0,
/*ArgCount*/sizeof(s_arg_luaL_getsubtable) / sizeof(s_arg_luaL_getsubtable[0]),
/*arg lp*/	s_arg_luaL_getsubtable,
	},
	{
		/*ccname*/	_WT("LUAL_����"),
		/*egname*/	_WT("luaL_traceback"),
		/*explain*/ _WT("������ѹ����ݵ� 'Lua״̬1' ��ջ�С� �����������Ϣ����Ϊ�գ�����ڻ��ݵĿ�ͷ���ӡ� '�ȼ�'����ָʾ�������ݵļ���"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_traceback) / sizeof(s_arg_luaL_traceback[0]),
		/*arg lp*/	s_arg_luaL_traceback,
	},
	{
		/*ccname*/	_WT("LUAL_����"),
		/*egname*/	_WT("luaL_requiref"),
		/*explain*/ _WT(""),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_requiref) / sizeof(s_arg_luaL_requiref[0]),
		/*arg lp*/	s_arg_luaL_requiref,
	},
	{
		/*ccname*/	_WT("LUAL_�½����"),
		/*egname*/	_WT("luaL_newlibtable"),
		/*explain*/ _WT("����һ����ѹ�뵽ջ�С���ʼ���С�Ѿ������Ż���"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_newlibtable) / sizeof(s_arg_luaL_newlibtable[0]),
		/*arg lp*/	s_arg_luaL_newlibtable,
	},
	{
		/*ccname*/	_WT("LUAL_�½���"),
		/*egname*/	_WT("luaL_newlib"),
		/*explain*/ _WT("����һ����ѹ�뵽ջ�У����ҽ�����ע�ᵽ���С�"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_newlibtable) / sizeof(s_arg_luaL_newlibtable[0]),
		/*arg lp*/	s_arg_luaL_newlibtable,
	},
	{
		/*ccname*/	_WT("LUAL_�������"),
		/*egname*/	_WT("luaL_argcheck"),
		/*explain*/ _WT("���'����'�������棬����������luaL_argerror����"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_argcheck) / sizeof(s_arg_luaL_argcheck[0]),
		/*arg lp*/	s_arg_luaL_argcheck,
	},
	{
		/*ccname*/	_WT("LUAL_ȡ������"),
		/*egname*/	_WT("luaL_typename"),
		/*explain*/ _WT("���ء�ջ��������ֵ���������ơ�"),
		/*category*/cmd_type_idx_auxiliary_library,
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
		/*ccname*/	_WT("LUAL_ִ���ļ�"),
		/*egname*/	_WT("luaL_dofile"),
		/*explain*/ _WT("���ļ����ز����нű���"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		SDT_BOOL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_dofile) / sizeof(s_arg_luaL_dofile[0]),
		/*arg lp*/	s_arg_luaL_dofile,
	},
	{
		/*ccname*/	_WT("LUAL_ִ���ı�"),
		/*egname*/	_WT("luaL_dostring"),
		/*explain*/ _WT("���ı����ز����нű���"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		SDT_BOOL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_dostring) / sizeof(s_arg_luaL_dostring[0]),
		/*arg lp*/	s_arg_luaL_dostring,
	},
	{
		/*ccname*/	_WT("LUAL_ȡԪ��"),
		/*egname*/	_WT("luaL_getmetatable"),
		/*explain*/ _WT("��ע����л�ȡָ�����Ƶ�Ԫ����ѹ�뵽ջ�С�������Ʋ�������ѹ��nil������ѹ��ֵ�����͡�"),
		/*category*/cmd_type_idx_auxiliary_library,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_luaL_newmetatable) / sizeof(s_arg_luaL_newmetatable[0]),
		/*arg lp*/	s_arg_luaL_newmetatable,
	},

	//////////////////////////////////////////////////////////////////////////��׼��

	{
		/*ccname*/	_WT("LUAL_�����б�׼��"),
		/*egname*/	_WT("luaL_openlibs"),
		/*explain*/ _WT(""),
		/*category*/cmd_type_idx_standard_library,
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
	pRetData->m_pText = CloneTextData((char*)name);
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
	pRetData->m_pText = CloneTextData((char*)name, len);
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
EXTERN_C void elua_fn_lua_status(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = lua_status(L);
}
EXTERN_C void elua_fn_lua_isyieldable(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_bool = lua_isyieldable(L);
}

//////////////////////////////////////////////////////////////////////////��������

EXTERN_C void elua_fn_lua_gc(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = lua_gc(L, pArgInf[1].m_int, pArgInf[2].m_int);
}

//////////////////////////////////////////////////////////////////////////�������

EXTERN_C void elua_fn_lua_error(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = lua_error(L);
}

EXTERN_C void elua_fn_lua_next(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = lua_next(L, pArgInf[1].m_int);
}

EXTERN_C void elua_fn_lua_concat(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_concat(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_len(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_len(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_stringtonumber(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = lua_stringtonumber(L, pArgInf[1].m_pText);
}
EXTERN_C void elua_fn_lua_getallocf(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	void* ud = NULL;
	pRetData->m_int = (INT)lua_getallocf(L, &ud);

	if (pArgInf[1].m_dtDataType!= _SDT_NULL)
	{
		*pArgInf[1].m_pInt = (INT)ud;
	}
}
EXTERN_C void elua_fn_lua_setallocf(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_setallocf(L, (lua_Alloc)pArgInf[1].m_dwSubCodeAdr, (void*)pArgInf[2].m_int);
}

//////////////////////////////////////////////////////////////////////////ʵ�ú���

EXTERN_C void elua_fn_lua_getextraspace(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = (INT)lua_getextraspace(L);
}
EXTERN_C void elua_fn_lua_tonumber(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_double = lua_tonumber(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_tointeger(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = lua_tointeger(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_pop(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_pop(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_newtable(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_newtable(L);
}
EXTERN_C void elua_fn_lua_register(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_register(L, pArgInf[1].m_pText, (lua_CFunction)pArgInf[2].m_dwSubCodeAdr);
}
EXTERN_C void elua_fn_lua_pushcfunction(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_pushcfunction(L, (lua_CFunction)pArgInf[1].m_dwSubCodeAdr);
}

EXTERN_C void elua_fn_lua_isfunction(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_bool = lua_isfunction(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_istable(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_bool = lua_istable(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_islightuserdata(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_bool = lua_islightuserdata(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_isnil(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_bool = lua_isnil(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_isboolean(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_bool = lua_isboolean(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_isthread(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_bool = lua_isthread(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_isnone(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_bool = lua_isnone(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_isnoneornil(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_bool = lua_isnoneornil(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_pushglobaltable(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_pushglobaltable(L);
}
EXTERN_C void elua_fn_lua_insert(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_insert(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_remove(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_remove(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_replace(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_replace(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_lua_upvalueindex(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = lua_upvalueindex(pArgInf[0].m_int);
}

//////////////////////////////////////////////////////////////////////////���Խӿ�

EXTERN_C void elua_fn_lua_getstack(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_Debug* pDebug = new lua_Debug();
	int ret = lua_getstack(L, pArgInf[1].m_int, pDebug);
	if (ret)
	{
		pRetData->m_int = (INT)pDebug;
	}
	delete pDebug;
	pRetData->m_int = NULL;
}
EXTERN_C void elua_fn_lua_freedebugptr(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	if (pArgInf[0].m_int)
	{
		delete (lua_Debug*)pArgInf[0].m_int;
	}
}
EXTERN_C void elua_fn_lua_getinfo(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_Debug* ar = (lua_Debug*)pArgInf[2].m_int;
	int ret = lua_getinfo(L, pArgInf[1].m_pText, ar);
	CFreqMem freqMem;
	if (ret)
	{
		freqMem.AddDWord(ar->event);
		freqMem.AddDWord((DWORD)CloneTextData((char*)ar->name));
		freqMem.AddDWord((DWORD)CloneTextData((char*)ar->namewhat));
		freqMem.AddDWord((DWORD)CloneTextData((char*)ar->what));
		freqMem.AddDWord((DWORD)CloneTextData((char*)ar->source));
		freqMem.AddDWord(ar->currentline);
		freqMem.AddDWord(ar->linedefined);
		freqMem.AddDWord(ar->lastlinedefined);
		freqMem.AddDWord(ar->nups);
		freqMem.AddDWord(ar->nparams);
		freqMem.AddDWord(ar->isvararg);
		freqMem.AddDWord(ar->istailcall);
		freqMem.AddDWord((DWORD)CloneTextData(ar->short_src));
	}
	pRetData->m_pCompoundData = freqMem.GetPtr();
}
EXTERN_C void elua_fn_lua_getlocal(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	const char* name = lua_getlocal(L, (lua_Debug*)pArgInf[1].m_int, pArgInf[2].m_int);
	pRetData->m_pText = CloneTextData((char*)name);
}
EXTERN_C void elua_fn_lua_setlocal(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	const char* name = lua_setlocal(L, (lua_Debug*)pArgInf[1].m_int, pArgInf[2].m_int);
	pRetData->m_pText = CloneTextData((char*)name);
}
EXTERN_C void elua_fn_lua_getupvalue(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	const char* name = lua_getupvalue(L, pArgInf[1].m_int, pArgInf[2].m_int);
	pRetData->m_pText = CloneTextData((char*)name);
}
EXTERN_C void elua_fn_lua_setupvalue(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	const char* name = lua_setupvalue(L, pArgInf[1].m_int, pArgInf[2].m_int);
	pRetData->m_pText = CloneTextData((char*)name);
}
EXTERN_C void elua_fn_lua_upvalueid(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = (INT)lua_upvalueid(L, pArgInf[1].m_int, pArgInf[2].m_int);
}
EXTERN_C void elua_fn_lua_upvaluejoin(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_upvaluejoin(L, pArgInf[1].m_int, pArgInf[2].m_int, pArgInf[3].m_int, pArgInf[4].m_int);
}
EXTERN_C void elua_fn_lua_sethook(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	lua_sethook(L, (lua_Hook)pArgInf[1].m_dwSubCodeAdr, pArgInf[2].m_int, pArgInf[3].m_int);
}
EXTERN_C void elua_fn_lua_gethook(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = (INT)lua_gethook(L);
}
EXTERN_C void elua_fn_lua_gethookmask(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = lua_gethookmask(L);
}
EXTERN_C void elua_fn_lua_gethookcount(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = lua_gethookcount(L);
}

//////////////////////////////////////////////////////////////////////////������

EXTERN_C void elua_fn_luaL_checkversion(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	luaL_checkversion(L);
}
EXTERN_C void elua_fn_luaL_getmetafield(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = luaL_getmetafield(L, pArgInf[1].m_int, pArgInf[2].m_pText);
}
EXTERN_C void elua_fn_luaL_callmeta(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = luaL_callmeta(L, pArgInf[1].m_int, pArgInf[2].m_pText);
}
EXTERN_C void elua_fn_luaL_tolstring(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	size_t len = 0;
	const char* str = luaL_tolstring(L, pArgInf[1].m_int, &len);
	if (pArgInf[2].m_dtDataType!=_SDT_NULL)
	{
		*pArgInf[2].m_pInt = len;
	}
	pRetData->m_pText = CloneTextData((char*)str, len);
}
EXTERN_C void elua_fn_luaL_argerror(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	luaL_argerror(L, pArgInf[1].m_int, pArgInf[2].m_pText);
}
EXTERN_C void elua_fn_luaL_checklstring(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	size_t len = 0;
	const char* str = luaL_checklstring(L, pArgInf[1].m_int, &len);
	if (pArgInf[2].m_dtDataType != _SDT_NULL)
	{
		*pArgInf[2].m_pInt = len;
	}
	pRetData->m_pText = CloneTextData((char*)str, len);
}
EXTERN_C void elua_fn_luaL_optlstring(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	size_t len = 0;
	const char* str = luaL_optlstring(L, pArgInf[1].m_int, pArgInf[2].m_pText, &len);
	if (pArgInf[3].m_dtDataType != _SDT_NULL)
	{
		*pArgInf[3].m_pInt = len;
	}
	pRetData->m_pText = CloneTextData((char*)str, len);
}
EXTERN_C void elua_fn_luaL_checknumber(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_double = luaL_checknumber(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_luaL_optnumber(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_double = luaL_optnumber(L, pArgInf[1].m_int, pArgInf[2].m_double);
}
EXTERN_C void elua_fn_luaL_checkinteger(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = luaL_checkinteger(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_luaL_optinteger(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = luaL_optinteger(L, pArgInf[1].m_int, pArgInf[2].m_int);
}
EXTERN_C void elua_fn_luaL_checkstack(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	luaL_checkstack(L, pArgInf[1].m_int, pArgInf[2].m_pText);
}
EXTERN_C void elua_fn_luaL_checktype(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	luaL_checktype(L, pArgInf[1].m_int, pArgInf[2].m_int);
}
EXTERN_C void elua_fn_luaL_checkany(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	luaL_checkany(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_luaL_newmetatable(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_bool = luaL_newmetatable(L, pArgInf[1].m_pText);
}
EXTERN_C void elua_fn_luaL_setmetatable(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	luaL_setmetatable(L, pArgInf[1].m_pText);
}
EXTERN_C void elua_fn_luaL_testudata(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = (INT)luaL_testudata(L, pArgInf[1].m_int, pArgInf[2].m_pText);
}
EXTERN_C void elua_fn_luaL_checkudata(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = (INT)luaL_checkudata(L, pArgInf[1].m_int, pArgInf[2].m_pText);
}
EXTERN_C void elua_fn_luaL_where(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	luaL_where(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_luaL_error(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = luaL_error(L, pArgInf[1].m_pText);
}
EXTERN_C void elua_fn_luaL_checkoption(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	char** option = (char**)((LPBYTE)pArgInf[3].m_pAryData + sizeof(INT) * 2);
	pRetData->m_int = luaL_checkoption(L, pArgInf[1].m_int, pArgInf[2].m_pText, option);
}
EXTERN_C void elua_fn_luaL_ref(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = luaL_ref(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_luaL_unref(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	luaL_unref(L, pArgInf[1].m_int, pArgInf[2].m_int);
}
EXTERN_C void elua_fn_luaL_loadfilex(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = luaL_loadfilex(L, pArgInf[1].m_pText, pArgInf[2].m_pText);
}
EXTERN_C void elua_fn_luaL_loadbufferx(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	size_t len = 0;
	char* buf = NULL;
	if (pArgInf[1].m_dtDataType == SDT_TEXT)
	{
		len = strlen(pArgInf[1].m_pText);
		buf = pArgInf[1].m_pText;
	}
	else if(pArgInf[1].m_dtDataType == SDT_BIN)
	{
		len = *(LPINT)(pArgInf[1].m_pBin + sizeof(INT));
		buf = (char*)(pArgInf[1].m_pBin + sizeof(INT) * 2);
	}

	pRetData->m_int = luaL_loadbufferx(L, buf, len, pArgInf[2].m_pText, pArgInf[3].m_pText);
}
EXTERN_C void elua_fn_luaL_loadstring(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = luaL_loadstring(L, pArgInf[1].m_pText);
}
EXTERN_C void elua_fn_luaL_newstate(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = (INT)luaL_newstate();
}
EXTERN_C void elua_fn_luaL_len(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = (INT)luaL_len(L, pArgInf[1].m_int);
}
EXTERN_C void elua_fn_luaL_gsub(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	const char* str = luaL_gsub(L, pArgInf[1].m_pText, pArgInf[2].m_pText, pArgInf[3].m_pText);
	pRetData->m_pText = CloneTextData((char*)str);
}
EXTERN_C void elua_fn_luaL_setfuncs(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	int count = *(LPINT)((LPBYTE)pArgInf[1].m_pAryData + sizeof(INT));
	LPBYTE pData = (LPBYTE)((LPBYTE)pArgInf[1].m_pAryData + sizeof(INT) * 2);

	luaL_Reg* regs = new luaL_Reg[count + 1];
	for (int i = 0; i < count; i++)
	{
		LPBYTE pitem = (LPBYTE)*((LPINT)(pData + i * sizeof(INT)));
		regs[i].name = (char*)*((LPINT)(pitem));
		regs[i].func = (lua_CFunction)*((LPINT)(pitem + sizeof(INT)));
	}
	regs[count].name = NULL;
	regs[count].func = NULL;
	luaL_setfuncs(L, regs, pArgInf[2].m_int);
	delete[] regs;

}
EXTERN_C void elua_fn_luaL_getsubtable(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_bool = luaL_getsubtable(L, pArgInf[1].m_int, pArgInf[2].m_pText);
}
EXTERN_C void elua_fn_luaL_traceback(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	luaL_traceback(L, (lua_State*)pArgInf[1].m_int, pArgInf[2].m_pText, pArgInf[3].m_int);
}
EXTERN_C void elua_fn_luaL_requiref(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	luaL_requiref(L, pArgInf[1].m_pText, (lua_CFunction)pArgInf[2].m_dwSubCodeAdr, pArgInf[3].m_bool);
}
EXTERN_C void elua_fn_luaL_newlibtable(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	int count = *(LPINT)((LPBYTE)pArgInf[1].m_pAryData + sizeof(INT));
	luaL_Reg* regs = new luaL_Reg[count + 1];
	luaL_newlibtable(L, regs);
	delete[] regs;
}
EXTERN_C void elua_fn_luaL_newlib(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	int count = *(LPINT)((LPBYTE)pArgInf[1].m_pAryData + sizeof(INT));
	LPBYTE pData = (LPBYTE)((LPBYTE)pArgInf[1].m_pAryData + sizeof(INT) * 2);
	luaL_Reg* regs = new luaL_Reg[count + 1];
	for (int i = 0; i < count; i++)
	{
		LPBYTE pitem = (LPBYTE)*((LPINT)(pData + i * sizeof(INT)));
		regs[i].name = (char*)*((LPINT)(pitem));
		regs[i].func = (lua_CFunction)*((LPINT)(pitem + sizeof(INT)));
	}
	regs[count].name = NULL;
	regs[count].func = NULL;
	luaL_newlib(L, regs);
	delete[] regs;
}
EXTERN_C void elua_fn_luaL_argcheck(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	luaL_argcheck(L, pArgInf[1].m_bool, pArgInf[2].m_int, pArgInf[3].m_pText);
}
EXTERN_C void elua_fn_luaL_typename(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	const char* name = luaL_typename(L, pArgInf[1].m_int);
	pRetData->m_pText = CloneTextData((char*)name);
}
EXTERN_C void elua_fn_luaL_dofile(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_bool = luaL_dofile (L, pArgInf[1].m_pText);
}
EXTERN_C void elua_fn_luaL_dostring(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_bool = luaL_dostring(L, pArgInf[1].m_pText);
}
EXTERN_C void elua_fn_luaL_getmetatable(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = luaL_getmetatable(L, pArgInf[1].m_pText);
}

//////////////////////////////////////////////////////////////////////////��׼��
EXTERN_C void elua_fn_luaL_openlibs(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	luaL_openlibs(L);
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
	elua_fn_lua_status,
	elua_fn_lua_isyieldable,
	//��������
	elua_fn_lua_gc,
	//�������
	elua_fn_lua_error,
	elua_fn_lua_next,
	elua_fn_lua_concat,
	elua_fn_lua_len,
	elua_fn_lua_stringtonumber,
	elua_fn_lua_getallocf,
	elua_fn_lua_setallocf,
	//ʵ�ú���(��)
	elua_fn_lua_getextraspace,
	elua_fn_lua_tonumber,
	elua_fn_lua_tointeger,
	elua_fn_lua_pop,
	elua_fn_lua_newtable,
	elua_fn_lua_register,
	elua_fn_lua_pushcfunction,
	elua_fn_lua_isfunction,
	elua_fn_lua_istable,
	elua_fn_lua_islightuserdata,
	elua_fn_lua_isnil,
	elua_fn_lua_isboolean,
	elua_fn_lua_isthread,
	elua_fn_lua_isnone,
	elua_fn_lua_isnoneornil,
	elua_fn_lua_pushglobaltable,
	elua_fn_lua_insert,
	elua_fn_lua_remove,
	elua_fn_lua_replace,
	elua_fn_lua_upvalueindex,
	//���Խӿ�
	elua_fn_lua_getstack,
	elua_fn_lua_freedebugptr,
	elua_fn_lua_getinfo,
	elua_fn_lua_getlocal,
	elua_fn_lua_setlocal,
	elua_fn_lua_getupvalue,
	elua_fn_lua_setupvalue,
	elua_fn_lua_upvalueid,
	elua_fn_lua_upvaluejoin,
	elua_fn_lua_sethook,
	elua_fn_lua_gethook,
	elua_fn_lua_gethookmask,
	elua_fn_lua_gethookcount,
	//������
		elua_fn_luaL_checkversion,
		elua_fn_luaL_getmetafield,
		elua_fn_luaL_callmeta,
		elua_fn_luaL_tolstring,
		elua_fn_luaL_argerror,
		elua_fn_luaL_checklstring,
		elua_fn_luaL_optlstring,
		elua_fn_luaL_checknumber,
		elua_fn_luaL_optnumber,
		elua_fn_luaL_checkinteger,
		elua_fn_luaL_optinteger,
		elua_fn_luaL_checkstack,
		elua_fn_luaL_checktype,
		elua_fn_luaL_checkany,
		elua_fn_luaL_newmetatable,
		elua_fn_luaL_setmetatable,
		elua_fn_luaL_testudata,
		elua_fn_luaL_checkudata,
		elua_fn_luaL_where,
		elua_fn_luaL_error,
		elua_fn_luaL_checkoption,
		elua_fn_luaL_ref,
		elua_fn_luaL_unref,
		elua_fn_luaL_loadfilex,
		elua_fn_luaL_loadbufferx,
		elua_fn_luaL_loadstring,
		elua_fn_luaL_newstate,
		elua_fn_luaL_len,
		elua_fn_luaL_gsub,
		elua_fn_luaL_setfuncs,
		elua_fn_luaL_getsubtable,
		elua_fn_luaL_traceback,
		elua_fn_luaL_requiref,
		elua_fn_luaL_newlibtable,
		elua_fn_luaL_newlib,
		elua_fn_luaL_argcheck,
		elua_fn_luaL_typename,
		elua_fn_luaL_dofile,
		elua_fn_luaL_dostring,
		elua_fn_luaL_getmetatable,
	//��׼��
		elua_fn_luaL_openlibs
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
	"elua_fn_lua_status",
	"elua_fn_lua_isyieldable",
	//��������
	"elua_fn_lua_gc",
	//�������
	"elua_fn_lua_error",
	"elua_fn_lua_next",
	"elua_fn_lua_concat",
	"elua_fn_lua_len",
	"elua_fn_lua_stringtonumber",
	"elua_fn_lua_getallocf",
	"elua_fn_lua_setallocf",
	//ʵ�ú������꣩
	"elua_fn_lua_getextraspace",
	"elua_fn_lua_tonumber",
	"elua_fn_lua_tointeger",
	"elua_fn_lua_pop",
	"elua_fn_lua_newtable",
	"elua_fn_lua_register",
	"elua_fn_lua_pushcfunction",
	"elua_fn_lua_isfunction",
	"elua_fn_lua_istable",
	"elua_fn_lua_islightuserdata",
	"elua_fn_lua_isnil",
	"elua_fn_lua_isboolean",
	"elua_fn_lua_isthread",
	"elua_fn_lua_isnone",
	"elua_fn_lua_isnoneornil",
	"elua_fn_lua_pushglobaltable",
	"elua_fn_lua_insert",
	"elua_fn_lua_remove",
	"elua_fn_lua_replace",
	"elua_fn_lua_upvalueindex",
	//���Խӿ�
	"elua_fn_lua_getstack",
	"elua_fn_lua_freedebugptr",
	"elua_fn_lua_getinfo",
	"elua_fn_lua_getlocal",
	"elua_fn_lua_setlocal",
	"elua_fn_lua_getupvalue",
	"elua_fn_lua_setupvalue",
	"elua_fn_lua_upvalueid",
	"elua_fn_lua_upvaluejoin",
	"elua_fn_lua_sethook",
	"elua_fn_lua_gethook",
	"elua_fn_lua_gethookmask",
	"elua_fn_lua_gethookcount",
	//������
		"elua_fn_luaL_checkversion",
		"elua_fn_luaL_getmetafield",
		"elua_fn_luaL_callmeta",
		"elua_fn_luaL_tolstring",
		"elua_fn_luaL_argerror",
		"elua_fn_luaL_checklstring",
		"elua_fn_luaL_optlstring",
		"elua_fn_luaL_checknumber",
		"elua_fn_luaL_optnumber",
		"elua_fn_luaL_checkinteger",
		"elua_fn_luaL_optinteger",
		"elua_fn_luaL_checkstack",
		"elua_fn_luaL_checktype",
		"elua_fn_luaL_checkany",
		"elua_fn_luaL_newmetatable",
		"elua_fn_luaL_setmetatable",
		"elua_fn_luaL_testudata",
		"elua_fn_luaL_checkudata",
		"elua_fn_luaL_where",
		"elua_fn_luaL_error",
		"elua_fn_luaL_checkoption",
		"elua_fn_luaL_ref",
		"elua_fn_luaL_unref",
		"elua_fn_luaL_loadfilex",
		"elua_fn_luaL_loadbufferx",
		"elua_fn_luaL_loadstring",
		"elua_fn_luaL_newstate",
		"elua_fn_luaL_len",
		"elua_fn_luaL_gsub",
		"elua_fn_luaL_setfuncs",
		"elua_fn_luaL_getsubtable",
		"elua_fn_luaL_traceback",
		"elua_fn_luaL_requiref",
		"elua_fn_luaL_newlibtable",
		"elua_fn_luaL_newlib",
		"elua_fn_luaL_argcheck",
		"elua_fn_luaL_typename",
		"elua_fn_luaL_dofile",
		"elua_fn_luaL_dostring",
		"elua_fn_luaL_getmetatable",
	//��׼��
		"elua_fn_luaL_openlibs"
};

#endif


/************************************************************************/
/* �������Ͷ���
/************************************************************************/

#ifndef __E_STATIC_LIB


LIB_DATA_TYPE_ELEMENT s_dt_element_lua_debug[] =
{
	/*{ ��Ա���� ,�����Ա , �������� ,Ӣ������ ,��Ա���� ,��Ա״̬ ,Ĭ��ֵ}*/
	{ SDT_INT, NULL,_WT("�¼�"), _WT("event"), _WT(""), 0, 0 },
	{ SDT_TEXT, NULL,_WT("����"), _WT("name"), _WT(""), 0, 0 },
	{ SDT_TEXT, NULL,_WT("��������"), _WT("namewhat"), _WT("�����ǡ�global��, ��local��, ��method��, ��field��, ��upvalue��, �� '' "), 0, 0 },
	{ SDT_TEXT, NULL,_WT("��������"), _WT("what"), _WT("���������һ�� Lua ��������Ϊ 'Lua' �� �����һ�����غ�����'C'�� �������һ�� chunk �����岿�֣���Ϊ 'main'�� �����һ������β���õĺ�������Ϊ 'tail'���������£�Lua û�й��ں����ı����Ϣ��"), 0, 0 },
	{ SDT_TEXT, NULL,_WT("Դ"), _WT("source"), _WT("��������Ƕ�����һ���ַ����У�source ��������ַ����� �������������һ���ļ��У� source ��һ���� '@' ��ͷ���ļ�����"), 0, 0 },
	{ SDT_INT, NULL,_WT("��ǰ��"), _WT("currentline"), _WT("������������ִ�е���һ�С� "), 0, 0 },
	{ SDT_INT, NULL,_WT("���忪ʼ��"), _WT("linedefined"), _WT("�������忪ʼ�����кš� "), 0, 0 },
	{ SDT_INT, NULL,_WT("���������"), _WT("lastlinedefined"), _WT("����������������кš� "), 0, 0 },
	{ SDT_SHORT, NULL,_WT("�û�ֵ����"), _WT("nups"), _WT("������ upvalue �ĸ�����"), 0, 0 },
	{ SDT_SHORT, NULL,_WT("��������"), _WT("nparams"), _WT("������ ���� �ĸ�����"), 0, 0 },
	{ SDT_BOOL, NULL,_WT("�Ƿ�ɱ����"), _WT("isvararg"), _WT(""), 0, 0 },
	{ SDT_BOOL, NULL,_WT("�Ƿ�β����"), _WT("istailcall"), _WT(""), 0, 0 },
	{ SDT_TEXT, NULL,_WT("��Դ"), _WT("short_src"), _WT("�ɴ�ӡ�汾��Դ"), 0, 0 },
};
LIB_DATA_TYPE_ELEMENT s_dt_element_lua_reg[] =
{
	/*{ ��Ա���� ,�����Ա , �������� ,Ӣ������ ,��Ա���� ,��Ա״̬ ,Ĭ��ֵ}*/
	{ SDT_TEXT, NULL,_WT("����"), _WT("name"), _WT("������"), 0, 0 },
	{ SDT_SUB_PTR, NULL,_WT("����"), _WT("func"), _WT("����ֵ�������ͣ������� Lua״̬��"), 0, 0 },
};

static LIB_DATA_TYPE_INFO s_DataTypes[] =
{
	/* { ��������, Ӣ������, ��������, ��������, ��������, ����״̬, ͼ������, �¼�����, �¼�ָ��, ��������, ����ָ��, ����ָ��, Ԫ������, Ԫ��ָ�� } */
	{ _WT("LUA_������Ϣ"), _WT("lua_debug"), _WT(""), 0, NULL, NULL, 0, 0, NULL, 0, NULL, NULL, sizeof(s_dt_element_lua_debug) / sizeof(s_dt_element_lua_debug[0]), s_dt_element_lua_debug },
	{ _WT("LUA_ע��"), _WT("lua_reg"), _WT(""), 0, NULL, NULL, 0, 0, NULL, 0, NULL, NULL, sizeof(s_dt_element_lua_reg) / sizeof(s_dt_element_lua_reg[0]), s_dt_element_lua_reg },
};
#endif

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
		sizeof(s_DataTypes) / sizeof(s_DataTypes[0]),
		s_DataTypes,
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