// esquirrel3.cpp : Defines the entry point for the DLL application.
//

#include "esquirrel3.h"

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
	{ _WT("��������_��"), _WT("OT_NULL"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_NULL },
	{ _WT("��������_����"), _WT("OT_INTEGER"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_INTEGER },
	{ _WT("��������_������"), _WT("OT_FLOAT"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_FLOAT },
	{ _WT("��������_�߼�"), _WT("OT_BOOL"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_BOOL },
	{ _WT("��������_�ı�"), _WT("OT_STRING"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_STRING },
	{ _WT("��������_��"), _WT("OT_TABLE"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_TABLE },
	{ _WT("��������_����"), _WT("OT_ARRAY"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_ARRAY },
	{ _WT("��������_�û�����"), _WT("OT_USERDATA"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_USERDATA },
	{ _WT("��������_�հ�"), _WT("OT_CLOSURE"), _WT("�ű�����"), LVL_SIMPLE, CT_NUM, NULL, OT_CLOSURE },
	{ _WT("��������_���رհ�"), _WT("OT_NATIVECLOSURE"), _WT("���غ���"), LVL_SIMPLE, CT_NUM, NULL, OT_NATIVECLOSURE },
	{ _WT("��������_������"), _WT("OT_GENERATOR"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_GENERATOR },
	{ _WT("��������_�û�ָ��"), _WT("OT_USERPOINTER"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_USERPOINTER },
	{ _WT("��������_�߳�"), _WT("OT_THREAD"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_THREAD },
	{ _WT("��������_��"), _WT("OT_CLASS"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_CLASS },
	{ _WT("��������_ʵ��"), _WT("OT_INSTANCE"), _WT("���ʵ��"), LVL_SIMPLE, CT_NUM, NULL, OT_INSTANCE },
	{ _WT("��������_������"), _WT("OT_WEAKREF"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_WEAKREF },

	{ _WT("����״̬_����"), _WT("SQ_VMSTATE_IDLE"), NULL, LVL_SIMPLE, CT_NUM, NULL, SQ_VMSTATE_IDLE },
	{ _WT("����״̬_��������"), _WT("SQ_VMSTATE_RUNNING"), NULL, LVL_SIMPLE, CT_NUM, NULL, SQ_VMSTATE_RUNNING },
	{ _WT("����״̬_����ͣ"), _WT("SQ_VMSTATE_SUSPENDED"), NULL, LVL_SIMPLE, CT_NUM, NULL, SQ_VMSTATE_SUSPENDED },
};

#endif


#ifndef __E_STATIC_LIB

// ���� 
ARG_INFO s_arg_open[] =
{
	/* { ��������, ��������, ͼ������, ͼ������, ��������(�μ�SDT_), Ĭ����ֵ, �������(�μ�AS_) } */
	{ _WT("ջ��С"), _WT("�൱�ڶ�����"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_newthread[] =
{
	{ _WT("��Ԫ��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ��С"), _WT("�൱�ڶ�����"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_onlyvm[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_vm_idx[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_setforeignptr[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("�û�ָ��"), _WT("�û��Զ���ָ��"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_setvmreleasehook[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("�ͷŻص�����"), _WT("����ֵ�������� �������� �ⲿָ�룬������ ��С��"),0,0, _SDT_ALL, 0, NULL },
};

ARG_INFO s_arg_setsharedreleasehook[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("�ͷŻص�����"), _WT("����ֵ�������� �������� �ⲿ����ָ�룬������ ��С��"),0,0, _SDT_ALL, 0, NULL },
};

ARG_INFO s_arg_setprintfunc[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("��ӡ�ص�����"), _WT("����ֵ���� �������� �����������ı��� ����ı���"),0,0, _SDT_ALL, 0, NULL },
	{ _WT("����ص�����"), _WT("����ֵ���� �������� �����������ı��� ����ı���"),0,0, _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_wakeupvm[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("��ͣ����ֵ"), _WT("���Ϊ�棬���ջ�е���һ����Ϊ֮ǰ��ͣ�ķ���ֵ"),0,0, SDT_BOOL, 0, AS_HAS_DEFAULT_VALUE },
	{ _WT("����ֵ"), _WT("���Ϊ�棬��ѹ��ִ����ͣ�������������ķ���ֵ"),0,0, SDT_BOOL, 0, AS_HAS_DEFAULT_VALUE },
	{ _WT("������"), _WT("���Ϊ�棬�ڷ�������ʱ����ʱ���ô��������"),0,0, SDT_BOOL, 1, AS_HAS_DEFAULT_VALUE },
	{ _WT("�׳��쳣"), _WT("���Ϊ�棬����������ڻָ������������쳣"),0,0, SDT_BOOL, 0, AS_HAS_DEFAULT_VALUE },
};

ARG_INFO s_arg_compile[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("��ȡ�ص�����"), _WT("����ֵ�������� �������� �û�ָ�룩"),0,0, _SDT_ALL, 0, NULL },
	{ _WT("�û�ָ��"), _WT("���ݸ� ��ȡ�ص����� �Ĳ���"),0,0, SDT_INT, 0, NULL },
	{ _WT("Դ����"), _WT("����ķ������ƣ������ڸ������������ʱ����"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("������"), _WT("���Ϊ�棬���ڷ�������ʱ�����ñ��������������"),0,0, SDT_BOOL, 1, AS_HAS_DEFAULT_VALUE },
};

ARG_INFO s_arg_compilebuffer[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("����ű�"), _WT("ֻ�����ı��ͻ��ֽڼ���"),0,0, _SDT_ALL, 0, NULL },
	{ _WT("Դ����"), _WT("����ķ������ƣ������ڸ������������ʱ����"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("������"), _WT("���Ϊ�棬���ڷ�������ʱ�����ñ��������������"),0,0, SDT_BOOL, 1, AS_HAS_DEFAULT_VALUE },
};

ARG_INFO s_arg_enabledebuginfo[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("����"), _WT("���Ϊ�棬�����ɵ�����Ϣ"),0,0, SDT_BOOL, 0, NULL },
};

ARG_INFO s_arg_notifyallexceptions[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("����"), _WT("���Ϊ�棬��֪ͨ�Ѵ������쳣�Ĵ���ص�"),0,0, SDT_BOOL, 0, NULL },
};

ARG_INFO s_arg_setcompilererrorhandler[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("�������ص�����"), _WT("����ֵ���ޣ������� �����������ı��� Ŀ�꣬�ı��� Դ�������� �кţ������� �кţ�"),0,0, _SDT_ALL, 0, NULL },
};

ARG_INFO s_arg_pop[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������"), _WT("Ҫ����ջ������"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_settop[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("��ջ��"), _WT("�����ڻָ�֮ǰ��ջ������"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_reservestack[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("��ջ��С"), _WT("�����ջ��С"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_move[] =
{
	{ _WT("Ŀ����������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("Դ��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("Դջ����"), _WT("Դջ�е�����"),0,0, SDT_INT, 0, NULL }
};
ARG_INFO s_arg_newuserdata[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("��С"), _WT("���ֽ�Ϊ��λ�Ĵ�С"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_newtableex[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("���ʼ����"), _WT("Ԥ����ļ�/ֵ�Ե�����"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_newarray[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("�����С"), _WT("Ҫ�����������С"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_newclosure[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("���غ���"), _WT("����ֵ�������ͣ������� ����������\r\n ����1��ʾ�з���ֵ�����ʱ��Ҫ��ջ��ѹ�뷵��ֵ\r\n ����0��ʾû�з���ֵ"),0,0, _SDT_ALL, 0, NULL },
	{ _WT("���ɱ�����"), _WT("��� > 0 ����ջ�е���N��Ԫ�أ���Ϊ�հ������ɱ���"),0,0, SDT_INT, 0, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_setparamscheck[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������"), _WT(" =0 ��ʾ����飻\r\n >0 ��ʾ��������(�������ص�this����)\r\n <0 ��ʾ���������Ƕ��ٸ�������-3��������3������"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������"), _WT("'o'null��'i'integer��'f'flora��'n'integer or float��'s'string��'t'table��'a'array��'u'userdata��' c'closure��nativeclosure��'g'generator��'p'userpointer��'v'thread��'x'instance(class instance)��'y'class��'b'bool, '.' �������͡�������'|'����ʾ�������\r\n���硰tsn | p����ʾ�������ǣ�table��string��number �� userpointer��"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY }
};
ARG_INFO s_arg_pushstring[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("�ı�"), _WT("Ҫѹ����ı�"),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_pushfloat[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("������"), _WT("Ҫѹ��ĸ�����"),0,0, SDT_FLOAT, 0, NULL },
};
ARG_INFO s_arg_pushintegert[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("����"), _WT("Ҫѹ�������"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_pushbool[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("�߼�"), _WT("Ҫѹ����߼�ֵ"),0,0, SDT_BOOL, 0, NULL },
};
ARG_INFO s_arg_pushuserpointer[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("�û�ָ��"), _WT("Ҫѹ����û�ָ��"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_pushthread[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("�߳�"), _WT("Ҫѹ����̣߳�HSQUIRRELVM��"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_getstring[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("�����ı�"), _WT("���ص��ı�"),0,0, SDT_TEXT, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_getinteger[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������"), _WT("���ص�����"),0,0, SDT_INT, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_getfloat[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("���ظ�����"), _WT("���صĸ�����"),0,0, SDT_FLOAT, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_getbool[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("�����߼�"), _WT("���ص��߼�ֵ"),0,0, SDT_BOOL, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_getthread[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("�����߳�"), _WT("���ص��߳�(HSQUIRRELVM)"),0,0, SDT_INT, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_getuserpointer[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("�����û�ָ��"), _WT("���ص��û�ָ��"),0,0, SDT_INT, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_getuserdata[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("�����û�ָ��"), _WT("���ص��û�ָ��"),0,0, SDT_INT, 0, AS_RECEIVE_VAR },
	{ _WT("�������ͱ�ǩ"), _WT("���ص����ͱ�ǩ,�ɲ��� ����_�����ͱ�ǩ()"),0,0, SDT_INT, 0, AS_RECEIVE_VAR | AS_DEFAULT_VALUE_IS_EMPTY},
};
ARG_INFO s_arg_settypetag[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("���ͱ�ǩ"), _WT("һ�����������"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_gettypetag[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("�������ͱ�ǩ"), _WT("���ص����ͱ�ǩ"),0,0, SDT_INT, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_setreleasehook[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("�ͷŹ���"), _WT("����ֵ�������ͣ������� �û�ָ�룬������ ��С��"),0,0, _SDT_ALL, 0, NULL },
};
ARG_INFO s_arg_getscratchpad[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("�����С"), _WT("���ݴ����������С�ڴ��С"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_getfunctioninfo[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("�ȼ�"), _WT("����ջ�ȼ���0��ʾ��ǰ������1��ʾ�����ߣ���������"),0,0, SDT_INT, 0, NULL },
	{ _WT("���غ�����Ϣ"), _WT("���صĺ�����Ϣ��������"),0,0, DTP_SQFUNCTION_INFO, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_getclosureinfo[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("���ز�����"), _WT("���صıհ���������"),0,0, SDT_INT, 0, AS_RECEIVE_VAR },
	{ _WT("�������ɱ�����"), _WT("���صıհ����ɱ�������"),0,0, SDT_INT, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_setnativeclosurename[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("����"), _WT("���رհ�����"),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_setinstanceup[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("�û�ָ��"), _WT("������û�ָ��"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_getinstanceup[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("�����û�ָ��"), _WT("�������õ��û�ָ��"),0,0, SDT_INT, 0, AS_RECEIVE_VAR },
	{ _WT("���ͱ�ǩ"), _WT("Ҫ�������ͱ�ǩ��typetag���������ֵΪ0�������"),0,0, SDT_INT, 0, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_setclassudsize[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("�û����ݴ�С"), _WT("���ֽ�Ϊ��λ"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_newclass[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("�Ƿ��л���"), _WT("�������Ϊ�棬������Ҫ��ջ�����Ļ���"),0,0, SDT_BOOL, 0, NULL },
};
ARG_INFO s_arg_getdefaultdelegate[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������"), _WT("����������_����ͷ����"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_getmemberhandle[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("���س�Ա���"), _WT("���صĳ�Ա���"),0,0, SDT_INT64, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_getbyhandle[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("��Ա���"), _WT("HSQMEMBERHANDLE"),0,0, SDT_INT64, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_newslot[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("�Ƿ�̬"), _WT("���Ϊ�棬�򴴽�һ����̬��Ա������Ŀ���������(class)ʱ��ʹ�ô˲�����"),0,0, SDT_BOOL, 0, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_deleteslot[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("�Ƿ�ѹ��ֵ"), _WT("���Ϊ�棬����ɾ����۵�ֵѹ��ջ�С�"),0,0, SDT_BOOL, 0, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_newmember[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("�Ƿ�̬"), _WT("���Ϊ�棬�򴴽�һ����̬��Ա��"),0,0, SDT_BOOL, 0, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_arraypop[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("�Ƿ�ѹ��ֵ"), _WT("���Ϊ�棬���Ѵ������е�����ֵѹ��ջ��"),0,0, SDT_BOOL, 0, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_arrayresize[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("�´�С"), _WT("�µ������С"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_arrayremove[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("������Ŀ����"), _WT("������0��ʼ"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_setfreevariable[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("���ɱ�������"), _WT("������0��ʼ������ڱհ���"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_call[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("��������"), _WT("�����Ĳ�������"),0,0, SDT_INT, 0, NULL },
	{ _WT("�Ƿ񷵻�ֵ"), _WT("���Ϊ�棬�򽫺�������ֵѹ�뵽ջ��"),0,0, SDT_BOOL, 0, AS_HAS_DEFAULT_VALUE },
	{ _WT("�Ƿ��������"), _WT("���Ϊ�棬����ִ�е����ڼ䷢������ʱ��������������ô��������"),0,0, SDT_BOOL, 1, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_resume[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("�Ƿ񷵻�ֵ"), _WT("���Ϊ�棬���������ķ���ֵѹ�뵽ջ��"),0,0, SDT_BOOL, 0, AS_HAS_DEFAULT_VALUE },
	{ _WT("�Ƿ��������"), _WT("���Ϊ�棬����ִ���ڼ䷢������ʱ��������������ô��������"),0,0, SDT_BOOL, 1, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_getlocal[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("�ȼ�"), _WT("����ջ�ȼ���0��ʾ��ǰ������1��ʾ�����ߣ���������"),0,0, SDT_INT, 0, NULL },
	{ _WT("����"), _WT("�ֲ�������������0��ʼ"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_getfreevariable[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("Ŀ��հ�������"),0,0, SDT_INT, 0, NULL },
	{ _WT("���ɱ�������"), _WT("��0��ʼ"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_throwerror[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("�����ı�"), _WT("Ҫ�׳��Ĵ�������"),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_getstackobj[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ����"), _WT("-1��ʾջ����1��ʾջ��"),0,0, SDT_INT, 0, NULL },
	{ _WT("������"), _WT("���صĶ�����"),0,0, SDT_INT64, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_pushobject[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("������"), _WT("HSQOBJECT"),0,0, SDT_INT64, 0, NULL },
};
ARG_INFO s_arg_addref[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("������"), _WT("HSQOBJECT"),0,0, SDT_INT64, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_pobj[] =
{
	{ _WT("������"), _WT("HSQOBJECT"),0,0, SDT_INT64, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_getobjtypetag[] =
{
	{ _WT("������"), _WT("HSQOBJECT"),0,0, SDT_INT64, 0, AS_RECEIVE_VAR },
	{ _WT("���ͱ�ǩ"), _WT("���ص����ͱ�ǩ"),0,0, SDT_INT, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_writeclosure[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("д���ص�����"), _WT("����ֵ�������ͣ������� �û�ָ�룬������ ����ָ�룬������ ���ݴ�С��"),0,0, _SDT_ALL, 0, NULL },
	{ _WT("�û�ָ��"), _WT("���ݸ�ÿ�λص����û�ָ��"),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_stackinfos[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("�ȼ�"), _WT("����ջ�ȼ���0��ʾ��ǰ������1��ʾ�����ߣ���������"),0,0, SDT_INT, 0, NULL },
	{ _WT("ջ��Ϣ"), _WT("SQStackInfos"),0,0, DTP_SQSTACK_INFO, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_setnativedebughook[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("���Իص�����"), _WT("����ֵ���ޣ������� ������������� ���ͣ��ı��� Դ���ƣ������� �кţ��ı��� ��������"),0,0, _SDT_ALL, 0, NULL },
};

// ������Ϣ
static CMD_INFO s_CmdInfo[] =
{
	/* { ��������, Ӣ������, ��������, �������(-1���������͵ķ���), ����״̬(CT_), ��������(SDT_), ��ֵ����, ����ȼ�(LVL_), ͼ������, ͼ������, ��������, ������Ϣ } */

	//////////////////////////////////////////////////////////////////////////�����
	{
		/*ccname*/	_WT("����_��"),
		/*egname*/	_WT("sq_open"),
		/*explain*/ _WT("����һ���µİ���ִ��ջ�����������������������"),
		/*category*/1,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_open) / sizeof(s_arg_open[0]),
		/*arg lp*/	s_arg_open,
	},
	{
		/*ccname*/	_WT("����_�½��߳�"),
		/*egname*/	_WT("sq_newthread"),
		/*explain*/	_WT("����һ���µ��̣߳���ѹ�뵽ջ��"),
		/*category*/1,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_newthread) / sizeof(s_arg_newthread[0]),
		/*arg lp*/	s_arg_newthread,
	},
	{
		/*ccname*/	_WT("����_�ô��������"),
		/*egname*/	_WT("sq_seterrorhandler"),
		/*explain*/	_WT("��ջ����һ���հ��򱾻��հ�������������Ϊ����ʱ���������"),
		/*category*/1,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_�ر�"),
		/*egname*/	_WT("sq_close"),
		/*explain*/	_WT("�ͷŴ򿪵�����������йص�������Ԫ�����"),
		/*category*/1,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_���ⲿָ��"),
		/*egname*/	_WT("sq_setforeignptr"),
		/*explain*/	_WT("����һ����������������ⲿָ��"),
		/*category*/1,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_setforeignptr) / sizeof(s_arg_setforeignptr[0]),
		/*arg lp*/	s_arg_setforeignptr,
	},
	{
		/*ccname*/	_WT("����_ȡ�ⲿָ��"),
		/*egname*/	_WT("sq_getforeignptr"),
		/*explain*/	_WT("��ȡһ����������������ⲿָ��"),
		/*category*/1,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_�ù����ⲿָ��"),
		/*egname*/	_WT("sq_setsharedforeignptr"),
		/*explain*/	_WT("����һ����������������ⲿ����ָ�룬����ⲿָ���ǿ������̵߳�����������"),
		/*category*/1,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_setforeignptr) / sizeof(s_arg_setforeignptr[0]),
		/*arg lp*/	s_arg_setforeignptr,
	},
	{
		/*ccname*/	_WT("����_ȡ�����ⲿָ��"),
		/*egname*/	_WT("sq_getsharedforeignptr"),
		/*explain*/	_WT("��ȡһ����������������ⲿ����ָ�룬����ⲿָ���ǿ������̵߳�����������"),
		/*category*/1,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_��������ͷŹ���"),
		/*egname*/	_WT("sq_setvmreleasehook"),
		/*explain*/	_WT("��һ����������ͷ�ʱ������������ӻص�������SQUserPointer �� ����_���ⲿָ��() ���õ�ָ��"),
		/*category*/1,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_setvmreleasehook) / sizeof(s_arg_setvmreleasehook[0]),
		/*arg lp*/	s_arg_setvmreleasehook,
	},
	{
		/*ccname*/	_WT("����_ȡ������ͷŹ���"),
		/*egname*/	_WT("sq_getvmreleasehook"),
		/*explain*/	_WT("��ȡ��������ͷŹ��ӻص�����"),
		/*category*/1,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_�ù����ͷŹ���"),
		/*egname*/	_WT("sq_setsharedreleasehook"),
		/*explain*/	_WT("����һ��������Ĺ����ͷŻص�����������������ӻص��������û�ָ�� �� ����_���ⲿ����ָ��() ���õ�ָ��"),
		/*category*/1,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_setsharedreleasehook) / sizeof(s_arg_setsharedreleasehook[0]),
		/*arg lp*/	s_arg_setsharedreleasehook,
	},
	{
		/*ccname*/	_WT("����_ȡ�����ͷŹ���"),
		/*egname*/	_WT("sq_getsharedreleasehook"),
		/*explain*/	_WT("��ȡ������Ĺ����ͷŹ��ӻص��������� �� �½��߳� ֮�������������������"),
		/*category*/1,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_�ô�ӡ�ص�����"),
		/*egname*/	_WT("sq_setprintfunc"),
		/*explain*/	_WT("��Ȼ�ű����� print() ʱ�������Լ��Ĵ�ӡ����ص�����"),
		/*category*/1,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_setprintfunc) / sizeof(s_arg_setprintfunc[0]),
		/*arg lp*/	s_arg_setprintfunc,
	},
	{
		/*ccname*/	_WT("����_ȡ��ӡ�ص�����"),
		/*egname*/	_WT("sq_getprintfunc"),
		/*explain*/	_WT("��ȡ�������ӡ�ص�����"),
		/*category*/1,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_ȡ����ص�����"),
		/*egname*/	_WT("sq_geterrorfunc"),
		/*explain*/	_WT("��ȡ���������ص�����"),
		/*category*/1,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_��ͣ�����"),
		/*egname*/	_WT("sq_suspendvm"),
		/*explain*/	_WT("��ͣһ������������У��ɹ�����>=0"),
		/*category*/1,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_���������"),
		/*egname*/	_WT("sq_wakeupvm"),
		/*explain*/	_WT("���ѱ���ͣ����������ɹ�����>=0"),
		/*category*/1,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_wakeupvm) / sizeof(s_arg_wakeupvm[0]),
		/*arg lp*/	s_arg_wakeupvm,
	},
	{
		/*ccname*/	_WT("����_ȡ�����״̬"),
		/*egname*/	_WT("sq_getvmstate"),
		/*explain*/	_WT("��ȡָ�������״̬������\"����״̬_\"��ͷ����"),
		/*category*/1,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_ȡ�汾"),
		/*egname*/	_WT("sq_getversion"),
		/*explain*/	_WT("���ذ汾��"),
		/*category*/1,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/0,
		/*arg lp*/	NULL,
	},
	//////////////////////////////////////////////////////////////////////////����
	{
		/*ccname*/	_WT("����_����"),
		/*egname*/	_WT("sq_compile"),
		/*explain*/	_WT("��������ű�������ɹ�����>=0���������Ľű���Ϊ����ѹ�뵽ջ�У�ʧ�ܲ���ѹ���κ�����"),
		/*category*/2,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_compile) / sizeof(s_arg_compile[0]),
		/*arg lp*/	s_arg_compile,
	},
	{
		/*ccname*/	_WT("����_���뻺����"),
		/*egname*/	_WT("sq_compilebuffer"),
		/*explain*/	_WT("��������ű����ڴ滺����������ɹ�����>=0���������Ľű���Ϊ����ѹ�뵽ջ�У�ʧ�ܲ���ѹ���κ�����"),
		/*category*/2,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_compilebuffer) / sizeof(s_arg_compilebuffer[0]),
		/*arg lp*/	s_arg_compilebuffer,
	},
	{
		/*ccname*/	_WT("����_���õ�����Ϣ"),
		/*egname*/	_WT("sq_enabledebuginfo"),
		/*explain*/	_WT("�ڱ���ʱ ����/���� ���ɵ�������Ϣ���ú���Ҳ��Ӱ�������߳�"),
		/*category*/2,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_enabledebuginfo) / sizeof(s_arg_enabledebuginfo[0]),
		/*arg lp*/	s_arg_enabledebuginfo,
	},
	{
		/*ccname*/	_WT("����_����֪ͨ�����쳣"),
		/*egname*/	_WT("sq_notifyallexceptions"),
		/*explain*/	_WT("����/���� ֪ͨ�Ѵ����쳣�Ĵ���ص���Ĭ������£�����δ�����쳣������ջ�в�����try / catch��ʱ��VM�Ż���ô���ص��� �������֪ͨ�����쳣����ʹ��try / catch��֮�䣬VMҲ����κ��쳣���ô���ص����˹��ܶ���ʵ�ֵ����������á�"),
		/*category*/2,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_notifyallexceptions) / sizeof(s_arg_notifyallexceptions[0]),
		/*arg lp*/	s_arg_notifyallexceptions,
	},
	{
		/*ccname*/	_WT("����_�ñ����������"),
		/*egname*/	_WT("sq_setcompilererrorhandler"),
		/*explain*/	_WT("���ñ���������������������������������ԪVM֮�乲��"),
		/*category*/2,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_setcompilererrorhandler) / sizeof(s_arg_setcompilererrorhandler[0]),
		/*arg lp*/	s_arg_setcompilererrorhandler,
	},
	//////////////////////////////////////////////////////////////////////////ջ����
	{
		/*ccname*/	_WT("����_ѹ��"),
		/*egname*/	_WT("sq_push"),
		/*explain*/	_WT("������\"ջ����\"�е�ֵѹ��ջ"),
		/*category*/3,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_����"),
		/*egname*/	_WT("sq_pop"),
		/*explain*/	_WT("��ջ�е���ָ��������Ԫ��"),
		/*category*/3,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_pop) / sizeof(s_arg_pop[0]),
		/*arg lp*/	s_arg_pop,
	},
	{
		/*ccname*/	_WT("����_����ջ��"),
		/*egname*/	_WT("sq_poptop"),
		/*explain*/	_WT("��ջ�е���1��Ԫ��"),
		/*category*/3,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_�Ƴ�"),
		/*egname*/	_WT("sq_remove"),
		/*explain*/	_WT("��ջ�е�ָ��λ���Ƴ�1��Ԫ��"),
		/*category*/3,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_ȡջ��"),
		/*egname*/	_WT("sq_gettop"),
		/*explain*/	_WT("����ջ��������"),
		/*category*/3,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_��ջ��"),
		/*egname*/	_WT("sq_settop"),
		/*explain*/	_WT("�����µ�ջ������������Ⱦɵ�ջ������ѹ���ֵ"),
		/*category*/3,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_settop) / sizeof(s_arg_settop[0]),
		/*arg lp*/	s_arg_settop,
	},
	{
		/*ccname*/	_WT("����_����ջ��С"),
		/*egname*/	_WT("sq_reservestack"),
		/*explain*/	_WT("����ջ��С���ɹ�����>=0��ȷ��ʣ���ջ�ռ�������ָ���Ĵ�С�����ջ��С�������Զ������� �����ǰ�������� Ԫ����(memtamethod)��������ʧ�ܲ���ջ�����������С�����������뱻��Ϊ��ջ�����"),
		/*category*/3,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_reservestack) / sizeof(s_arg_reservestack[0]),
		/*arg lp*/	s_arg_reservestack,
	},
	{
		/*ccname*/	_WT("����_�Ƚ�"),
		/*egname*/	_WT("sq_cmp"),
		/*explain*/	_WT("�Ƚ�ջ�е���������\r\n ���� > 0 ��ʾ ����1 > ����2��\r\n ���� = 0 ��ʾ ��ȣ�\r\n ���� < 0 ��ʾ ����1 < ����2 \r\n"),
		/*category*/3,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_�ƶ�"),
		/*egname*/	_WT("sq_move"),
		/*explain*/	_WT("��Դջָ��������ֵѹ�뵽Ŀ��ջ��"),
		/*category*/3,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_move) / sizeof(s_arg_move[0]),
		/*arg lp*/	s_arg_move,
	},
	//////////////////////////////////////////////////////////////////////////���󴴽��ʹ���
	{
		/*ccname*/	_WT("����_�½��û�����"),
		/*egname*/	_WT("sq_newuserdata"),
		/*explain*/	_WT("����һ���µ�userdata������ѹ��ջ�������û�����ָ��"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_newuserdata) / sizeof(s_arg_newuserdata[0]),
		/*arg lp*/	s_arg_newuserdata,
	},
	{
		/*ccname*/	_WT("����_�½���"),
		/*egname*/	_WT("sq_newtable"),
		/*explain*/	_WT("����һ���±�����ѹ��ջ"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_�½���Ex"),
		/*egname*/	_WT("sq_newtableex"),
		/*explain*/	_WT("����һ���±�����ѹ��ջ���˺�������ָ����ĳ�ʼ�������Ա��ڴ���ʱ֪������Ĳ��������ֹ����Ҫ������ɢ�С�"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_newtableex) / sizeof(s_arg_newtableex[0]),
		/*arg lp*/	s_arg_newtableex,
	},
	{
		/*ccname*/	_WT("����_�½�����"),
		/*egname*/	_WT("sq_newarray"),
		/*explain*/	_WT("����һ�������鲢����ѹ��ջ"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_newarray) / sizeof(s_arg_newarray[0]),
		/*arg lp*/	s_arg_newarray,
	},
	{
		/*ccname*/	_WT("����_�½��հ�"),
		/*egname*/	_WT("sq_newclosure"),
		/*explain*/	_WT("����һ�����رհ�(����)������ѹ��ջ"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_newclosure) / sizeof(s_arg_newclosure[0]),
		/*arg lp*/	s_arg_newclosure,
	},
	{
		/*ccname*/	_WT("����_�ò������"),
		/*egname*/	_WT("sq_setparamscheck"),
		/*explain*/	_WT("����ջ��λ�õı��رհ��Ĳ�����֤������������֤�������ܵĲ��������Լ���ѡ�����͡�����������ò��������õĲ���ģʽ�����׳��쳣������ֵ>=0��ʾ�ɹ�"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_setparamscheck) / sizeof(s_arg_setparamscheck[0]),
		/*arg lp*/	s_arg_setparamscheck,
	},
	{
		/*ccname*/	_WT("����_�󶨻���"),
		/*egname*/	_WT("sq_bindenv"),
		/*explain*/	_WT("��ջ�е���һ�����󣨱����Ǳ�ʵ�����ࣩ��¡\'ջ����\"���ıհ������������Ķ�������Ϊ��¡�հ��Ļ�����Ȼ���µĿ�¡�հ�ѹ��ջ����������ֵ>=0��ʾ�ɹ�"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_�ñհ���"),
		/*egname*/	_WT("sq_setclosureroot"),
		/*explain*/	_WT("��ջ�е���һ��������������Ϊ\"ջ����\"���ıհ��ĸ�������ֵ>=0��ʾ�ɹ�"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_ȡ�հ���"),
		/*egname*/	_WT("sq_getclosureroot"),
		/*explain*/	_WT("��\"ջ����\"��ָ���ıհ��ĸ�ѹ��ջ������ֵ>=0��ʾ�ɹ�"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_ѹ���ı�"),
		/*egname*/	_WT("sq_pushstring"),
		/*explain*/	_WT("ѹ���ı�ֵ"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_pushstring) / sizeof(s_arg_pushstring[0]),
		/*arg lp*/	s_arg_pushstring,
	},
	{
		/*ccname*/	_WT("����_ѹ�븡����"),
		/*egname*/	_WT("sq_pushfloat"),
		/*explain*/	_WT("ѹ�븡����"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_pushfloat) / sizeof(s_arg_pushfloat[0]),
		/*arg lp*/	s_arg_pushfloat,
	},
	{
		/*ccname*/	_WT("����_ѹ������"),
		/*egname*/	_WT("sq_pushinteger"),
		/*explain*/	_WT("ѹ������"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_pushintegert) / sizeof(s_arg_pushintegert[0]),
		/*arg lp*/	s_arg_pushintegert,
	},
	{
		/*ccname*/	_WT("����_ѹ���߼�"),
		/*egname*/	_WT("sq_pushbool"),
		/*explain*/	_WT("ѹ���߼�ֵ"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_pushbool) / sizeof(s_arg_pushbool[0]),
		/*arg lp*/	s_arg_pushbool,
	},
	{
		/*ccname*/	_WT("����_ѹ���û�ָ��"),
		/*egname*/	_WT("sq_pushuserpointer"),
		/*explain*/	_WT("ѹ���û�ָ��"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_pushuserpointer) / sizeof(s_arg_pushuserpointer[0]),
		/*arg lp*/	s_arg_pushuserpointer,
	},
	{
		/*ccname*/	_WT("����_ѹ���"),
		/*egname*/	_WT("sq_pushnull"),
		/*explain*/	_WT("ѹ��null"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_ѹ���߳�"),
		/*egname*/	_WT("sq_pushthread"),
		/*explain*/	_WT("ѹ���߳�"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_pushthread) / sizeof(s_arg_pushthread[0]),
		/*arg lp*/	s_arg_pushthread,
	},
	{
		/*ccname*/	_WT("����_ȡ����"),
		/*egname*/	_WT("sq_gettype"),
		/*explain*/	_WT("����\"ջ����\"λ�ô���������ͣ�\"��������_\"��ͷ����"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_����"),
		/*egname*/	_WT("sq_typeof"),
		/*explain*/	_WT("ѹ��\"ջ����\"λ�ô�������������ƣ�����Ϊʵ�����ı����ʵ������_typeofԪ����; ����������£�ѹ��Ķ�����ܲ����ַ�����ȡ����_typeofʵ�֣�������ֵ>=0��ʾ�ɹ�"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_ȡ��С"),
		/*egname*/	_WT("sq_getsize"),
		/*explain*/	_WT("����\"ջ����\"λ�ô�����Ĵ�С"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_ȡ��ϣ"),
		/*egname*/	_WT("sq_gethash"),
		/*explain*/	_WT("����\"ջ����\"λ�ô�����Ĺ�ϣֵ"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_ȡ����"),
		/*egname*/	_WT("sq_getbase"),
		/*explain*/	_WT("ѹ��\"ջ����\"λ�ô�class�Ļ��࣬����ֵ>=0��ʾ�ɹ�"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_�Ƿ���ʵ��"),
		/*egname*/	_WT("sq_instanceof"),
		/*explain*/	_WT("�����棬��ʾջλ��-2���Ķ�����ջλ��-1�����ʵ��"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_BOOL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_���ı�"),
		/*egname*/	_WT("sq_tostring"),
		/*explain*/	_WT("��\"ջ����\"λ�ô��Ķ���ת��Ϊ�ı������ѽ���ı�ѹ��ջ�У�����ֵ>=0��ʾ�ɹ�"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_���߼�"),
		/*egname*/	_WT("sq_tobool"),
		/*explain*/	_WT("��\"ջ����\"λ�ô��Ķ���ת��Ϊ�߼��ͣ������ء����������bool��������������ű��Ĺ���ֵת��Ϊ�߼��͡� ���磬����1Ϊ�棬����0�١�"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_BOOL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_ȡ�ı�"),
		/*egname*/	_WT("sq_getstring"),
		/*explain*/	_WT("��ȡ\"ջ����\"λ�ô�������ı����ɹ�����>=0"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_getstring) / sizeof(s_arg_getstring[0]),
		/*arg lp*/	s_arg_getstring,
	},
	{
		/*ccname*/	_WT("����_ȡ����"),
		/*egname*/	_WT("sq_getinteger"),
		/*explain*/	_WT("��ȡ\"ջ����\"λ�ô����������ֵ���ɹ�����>=0"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_getinteger) / sizeof(s_arg_getinteger[0]),
		/*arg lp*/	s_arg_getinteger,
	},
	{
		/*ccname*/	_WT("����_ȡ������"),
		/*egname*/	_WT("sq_getfloat"),
		/*explain*/	_WT("��ȡ\"ջ����\"λ�ô�����ĸ�����ֵ���ɹ�����>=0"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_getfloat) / sizeof(s_arg_getfloat[0]),
		/*arg lp*/	s_arg_getfloat,
	},
	{
		/*ccname*/	_WT("����_ȡ�߼�"),
		/*egname*/	_WT("sq_getbool"),
		/*explain*/	_WT("��ȡ\"ջ����\"λ�ô�������߼�ֵ���ɹ�����>=0"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_getbool) / sizeof(s_arg_getbool[0]),
		/*arg lp*/	s_arg_getbool,
	},
	{
		/*ccname*/	_WT("����_ȡ�߳�"),
		/*egname*/	_WT("sq_getthread"),
		/*explain*/	_WT("��ȡ\"ջ����\"λ�ô�������߳�ָ�룬�ɹ�����>=0"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_getthread) / sizeof(s_arg_getthread[0]),
		/*arg lp*/	s_arg_getthread,
	},
	{
		/*ccname*/	_WT("����_ȡ�û�ָ��"),
		/*egname*/	_WT("sq_getuserpointer"),
		/*explain*/	_WT("��ȡ\"ջ����\"λ�ô�������û�ָ�룬�ɹ�����>=0"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_getuserpointer) / sizeof(s_arg_getuserpointer[0]),
		/*arg lp*/	s_arg_getuserpointer,
	},
	{
		/*ccname*/	_WT("����_ȡ�û�����"),
		/*egname*/	_WT("sq_getuserdata"),
		/*explain*/	_WT("��ȡ\"ջ����\"λ�ô�������û�����ָ�룬�ɹ�����>=0"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_getuserdata) / sizeof(s_arg_getuserdata[0]),
		/*arg lp*/	s_arg_getuserdata,
	},
	{
		/*ccname*/	_WT("����_�����ͱ�ǩ"),
		/*egname*/	_WT("sq_settypetag"),
		/*explain*/	_WT("��\"ջ����\"λ�ô����ö�������ͱ�ǩ��userdata �� class�����ɹ�����>=0"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_settypetag) / sizeof(s_arg_settypetag[0]),
		/*arg lp*/	s_arg_settypetag,
	},
	{
		/*ccname*/	_WT("����_ȡ���ͱ�ǩ"),
		/*egname*/	_WT("sq_settypetag"),
		/*explain*/	_WT("��ȡ\"ջ����\"λ�ô���������ͱ�ǩ���û�����(userdata) �� ��(class)�����ú���Ҳ������ʵ��(instance)�� ���Ŀ�������ʵ�������ȡ��������ͱ�ǩ���ɹ�����>=0"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_gettypetag) / sizeof(s_arg_gettypetag[0]),
		/*arg lp*/	s_arg_gettypetag,
	},
	{
		/*ccname*/	_WT("����_���ͷŹ���"),
		/*egname*/	_WT("sq_setreleasehook"),
		/*explain*/	_WT("������\"ջ����\"λ�ô��Ķ����û�����(userdata) ��ʵ��(instance) �� ��(class)�����ͷŻص�����"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_gettypetag) / sizeof(s_arg_gettypetag[0]),
		/*arg lp*/	s_arg_gettypetag,
	},
	{
		/*ccname*/	_WT("����_ȡ�ͷŹ���"),
		/*egname*/	_WT("sq_getreleasehook"),
		/*explain*/	_WT("��ȡ��\"ջ����\"λ�ô��Ķ����û�����(userdata) ��ʵ��(instance) �� ��(class)�����ͷŻص�����"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_ȡ�ݴ�ָ��"),
		/*egname*/	_WT("sq_getscratchpad"),
		/*explain*/	_WT("����һ��ָ���ڴ滺������ָ�룬��ָ�������������һ���� ָ����Ч��Ϊ��ֱ����һ�ε��� ����_ȡ�ݴ�ָ�루��"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_getscratchpad) / sizeof(s_arg_getscratchpad[0]),
		/*arg lp*/	s_arg_getscratchpad,
	},
	{
		/*ccname*/	_WT("����_ȡ������Ϣ"),
		/*egname*/	_WT("sq_getfunctioninfo"),
		/*explain*/	_WT("������ջ��λ�õĺ�����Ϣ�������һ�����رհ�����ʧ�ܡ��ɹ�����>=0"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_getfunctioninfo) / sizeof(s_arg_getfunctioninfo[0]),
		/*arg lp*/	s_arg_getfunctioninfo,
	},
	{
		/*ccname*/	_WT("����_ȡ�հ���Ϣ"),
		/*egname*/	_WT("sq_getclosureinfo"),
		/*explain*/	_WT("��ȡ��\"ջ����\"λ�õıհ��������������ɱ����������ɹ�����>=0"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_getclosureinfo) / sizeof(s_arg_getclosureinfo[0]),
		/*arg lp*/	s_arg_getclosureinfo,
	},
	{
		/*ccname*/	_WT("����_ȡ�հ���"),
		/*egname*/	_WT("sq_getclosurename"),
		/*explain*/	_WT("��ȡ��\"ջ����\"λ�õıհ����ƣ���ѹ��ջ���ɹ�����>=0����ע�⣬����հ��������ģ������ƿ������ַ�����Ҳ������null������û��Ϊ��ָ�����Ƶı��رհ���"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_�ñ��رհ���"),
		/*egname*/	_WT("sq_setnativeclosurename"),
		/*explain*/	_WT("������\"ջ����\"λ�õı��رհ����ƣ��ɹ�����>=0�����رհ������ƴ�����Ϊ�˵��ԡ�"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_setnativeclosurename) / sizeof(s_arg_setnativeclosurename[0]),
		/*arg lp*/	s_arg_setnativeclosurename,
	},
	{
		/*ccname*/	_WT("����_��ʵ���û�ָ��"),
		/*egname*/	_WT("sq_setinstanceup"),
		/*explain*/	_WT("������\"ջ����\"λ�õ�ʵ����instance�����û�ָ�루userpointer�����ɹ�����>=0��"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_setinstanceup) / sizeof(s_arg_setinstanceup[0]),
		/*arg lp*/	s_arg_setinstanceup,
	},
	{
		/*ccname*/	_WT("����_ȡʵ���û�ָ��"),
		/*egname*/	_WT("sq_setinstanceup"),
		/*explain*/	_WT("��ȡ��\"ջ����\"λ�õ�ʵ����instance�����û�ָ�루userpointer�����ɹ�����>=0��\r\n�������'���ͱ�ǩ'����0����ú������ʵ�����������Ƿ���ָ���ı�ǩ���; ���������ú���ʧ�ܡ� ���'���ͱ�ǩ'Ϊ0���ú��������Ա�Ǽ�顣"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_getinstanceup) / sizeof(s_arg_getinstanceup[0]),
		/*arg lp*/	s_arg_getinstanceup,
	},
	{
		/*ccname*/	_WT("����_�����û����ݴ�С"),
		/*egname*/	_WT("sq_setclassudsize"),
		/*explain*/	_WT("������\"ջ����\"λ�õ��ࣨclass�����û����ݣ�userdata����С���ɹ�����>=0��\r\n������û����ݴ�С��> 0�����������ʵ��ʱ�����ڴ洢ʵ�����ڴ���ĩβ��������Ŀռ䡣 ʵ�����û�ָ��Ҳ���Զ����õ����ڴ����� "),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_setclassudsize) / sizeof(s_arg_setclassudsize[0]),
		/*arg lp*/	s_arg_setclassudsize,
	},
	{
		/*ccname*/	_WT("����_�½���"),
		/*egname*/	_WT("sq_newclass"),
		/*explain*/	_WT("����һ���µ��ࡣ�������'�Ƿ��л���'Ϊ�棬��ú�����ջ�е���һ���࣬���´�������̳��Դ��ࡣ�ɹ�����>=0"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_newclass) / sizeof(s_arg_newclass[0]),
		/*arg lp*/	s_arg_newclass,
	},
	{
		/*ccname*/	_WT("����_����ʵ��"),
		/*egname*/	_WT("sq_createinstance"),
		/*explain*/	_WT("��\"ջ����\"λ�õ��ࣨclass������һ��ʵ������ѹ��ջ���ɹ�����>=0���ú����������ʵ�����캯���� Ҫ����ʵ�����Զ������乹�캯��������ʹ�� ����_����() sq_call"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_��������"),
		/*egname*/	_WT("sq_setattributes"),
		/*explain*/	_WT("������\"ջ����\"λ�õ��ࣨclass���ĳ�Ա���ԣ��ɹ�����>=0���ú�����ջ�е���һ��key��һ��value������Ϊջ��ָ��λ����ĳ�Ա���ԣ����key = null����ú��������༶�����ԡ���������ɹ����򽫾�����ֵѹ��ջ��"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_ȡ������"),
		/*egname*/	_WT("sq_getattributes"),
		/*explain*/	_WT("��ȡ��\"ջ����\"λ�õ��ࣨclass���ĳ�Ա���ԣ��ɹ�����>=0���ú�����ջ�е���һ��key����ѹ�����Ա����ֵvalue�����key = null����ѹ���༶������ֵ"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_ȡ��"),
		/*egname*/	_WT("sq_getclass"),
		/*explain*/	_WT("��ȡ��\"ջ����\"λ�õ�ʵ����class instance���������࣬��ѹ�뵽ջ�У��ɹ�����>=0��"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_������"),
		/*egname*/	_WT("sq_weakref"),
		/*explain*/	_WT("��ȡ��\"ջ����\"λ�õĶ���������ã���ѹ�뵽ջ�С����������һ��integer��float��bool��null����ѹ�����������������á�"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_ȡĬ��ί��"),
		/*egname*/	_WT("sq_getdefaultdelegate"),
		/*explain*/	_WT("��ȡָ�����͵�Ĭ��ί�У���ѹ�뵽ջ�У��ɹ�����>=0��"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_getdefaultdelegate) / sizeof(s_arg_getdefaultdelegate[0]),
		/*arg lp*/	s_arg_getdefaultdelegate,
	},
	{
		/*ccname*/	_WT("����_ȡ��Ա���"),
		/*egname*/	_WT("sq_getmemberhandle"),
		/*explain*/	_WT("��ջ�е���һ��ֵ������������������ȡ���Ա�ľ�����ɹ�����>=0��\r\n�˷��������������ʵ���� ͨ�����ȡ�ľ���Ժ���������û��ȡһ����ʵ����ֵ����֮��Ȼ�� �ӻ�������ľ��������������Ȼ��Ч�������ؼ̳й���"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_getmemberhandle) / sizeof(s_arg_getmemberhandle[0]),
		/*arg lp*/	s_arg_getmemberhandle,
	},
	{
		/*ccname*/	_WT("����_���ȡ"),
		/*egname*/	_WT("sq_getbyhandle"),
		/*explain*/	_WT("ͨ����Ա�����ȡ����'ջ����'ָ������ʵ���ĳ�Աֵ����ѹ�뵽ջ�У��ɹ�����>=0��"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_getbyhandle) / sizeof(s_arg_getbyhandle[0]),
		/*arg lp*/	s_arg_getbyhandle,
	},
	{
		/*ccname*/	_WT("����_�����"),
		/*egname*/	_WT("sq_getbyhandle"),
		/*explain*/	_WT("��ջ�е���һ��ֵ����ͨ����Ա������ò���'ջ����'ָ������ʵ���ĳ�Աֵ���ɹ�����>=0��"),
		/*category*/4,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_getbyhandle) / sizeof(s_arg_getbyhandle[0]),
		/*arg lp*/	s_arg_getbyhandle,
	},
	//////////////////////////////////////////////////////////////////////////�������
	{
		/*ccname*/	_WT("����_ѹ�����"),
		/*egname*/	_WT("sq_pushroottable"),
		/*explain*/	_WT("������ѹ�뵽ջ��"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_ѹ��ע���"),
		/*egname*/	_WT("sq_pushregistrytable"),
		/*explain*/	_WT("��ע���ѹ�뵽ջ�С�ע�����������������е��̣߳���Ԫ �������֮�乲������ر�"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_ѹ�볣����"),
		/*egname*/	_WT("sq_pushconsttable"),
		/*explain*/	_WT("��������ѹ�뵽ջ�С�"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_�ø���"),
		/*egname*/	_WT("sq_setroottable"),
		/*explain*/	_WT("��ջ�е���һ������������Ϊ�����ɹ�����>=0"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_�ó�����"),
		/*egname*/	_WT("sq_setconsttable"),
		/*explain*/	_WT("��ջ�е���һ������������Ϊ�������ɹ�����>=0"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_�½����"),
		/*egname*/	_WT("sq_newslot"),
		/*explain*/	_WT("��ջ�е���һ������һ��ֵ������'ջ����'λ�õı����ִ��set�����������۲������򽫴��������ɹ�����>=0"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_newslot) / sizeof(s_arg_newslot[0]),
		/*arg lp*/	s_arg_newslot,
	},
	{
		/*ccname*/	_WT("����_ɾ�����"),
		/*egname*/	_WT("sq_deleteslot"),
		/*explain*/	_WT("��ջ�е���һ����������'ջ����'λ�õı����ɾ��ָ���Ĳ�ۣ������۲����ڣ��򲻻����κη�Ӧ���ɹ�����>=0"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_deleteslot) / sizeof(s_arg_deleteslot[0]),
		/*arg lp*/	s_arg_deleteslot,
	},
	{
		/*ccname*/	_WT("����_��"),
		/*egname*/	_WT("sq_set"),
		/*explain*/	_WT("��ջ�е���һ������һ��ֵ������'ջ����'λ�õĶ���ִ��set�������ɹ�����>=0"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_ȡ"),
		/*egname*/	_WT("sq_get"),
		/*explain*/	_WT("��ջ�е���һ����������'ջ����'λ�õĶ���ִ��get�����������ѹ��ջ�У��ɹ�����>=0"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_ԭʼ��"),
		/*egname*/	_WT("sq_rawset"),
		/*explain*/	_WT("��ջ�е���һ������һ��ֵ������'ջ����'λ�õĶ���ִ��set�������Ҳ�ʹ��ί�л�Ԫ�������ɹ�����>=0"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_ԭʼȡ"),
		/*egname*/	_WT("sq_rawget"),
		/*explain*/	_WT("��ջ�е���һ����������'ջ����'λ�õĶ���ִ��get�������Ҳ�ʹ��ί�л�Ԫ�����������ѹ��ջ�С��ɹ�����>=0"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_ԭʼɾ�����"),
		/*egname*/	_WT("sq_rawdeleteslot"),
		/*explain*/	_WT("��ջ�е���һ����������'ջ����'λ�õı����ɾ��ָ���Ĳ�ۣ��Ҳ�ʹ��_delslotԪ�����������۲����ڣ��򲻻����κη�Ӧ���ɹ�����>=0"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_deleteslot) / sizeof(s_arg_deleteslot[0]),
		/*arg lp*/	s_arg_deleteslot,
	},
	{
		/*ccname*/	_WT("����_�½���Ա"),
		/*egname*/	_WT("sq_newmember"),
		/*explain*/	_WT("��ջ�е���һ������һ��ֵ��һ�����󣨽�������Ϊ��Ա�����ԣ�������'ջ����'λ�õ���ִ���½���۲����������۲��������Ǵ������ɹ�����>=0\r\n�����е���_newmemberԪ�������˷���ֻ�������ࡣ"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_newmember) / sizeof(s_arg_newmember[0]),
		/*arg lp*/	s_arg_newmember,
	},
	{
		/*ccname*/	_WT("����_ԭʼ�½���Ա"),
		/*egname*/	_WT("sq_rawnewmember"),
		/*explain*/	_WT("��ջ�е���һ������һ��ֵ��һ�����󣨽�������Ϊ��Ա�����ԣ�������'ջ����'λ�õ���ִ���½���۲����������۲��������Ǵ������ɹ�����>=0\r\n�˷���ֻ�������ࡣ"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_newmember) / sizeof(s_arg_newmember[0]),
		/*arg lp*/	s_arg_newmember,
	},
	{
		/*ccname*/	_WT("����_�������"),
		/*egname*/	_WT("sq_arrayappend"),
		/*explain*/	_WT("��ջ�е���һ��ֵ����ӵ�'ջ����'λ�õ�������档�ɹ�����>=0\r\n�˷���ֻ���������顣"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_���鵯��"),
		/*egname*/	_WT("sq_arraypop"),
		/*explain*/	_WT("��'ջ����'λ�õ����鵯��һ��ֵ���ɹ�����>=0\r\n�˷���ֻ���������顣"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_arraypop) / sizeof(s_arg_arraypop[0]),
		/*arg lp*/	s_arg_arraypop,
	},
	{
		/*ccname*/	_WT("����_�������ô�С"),
		/*egname*/	_WT("sq_arrayresize"),
		/*explain*/	_WT("��'ջ����'λ�õ������������ô�С�����'�´�С'���ڵ�ǰ��С����null��䡣�ɹ�����>=0\r\n�˷���ֻ���������顣"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_arrayresize) / sizeof(s_arg_arrayresize[0]),
		/*arg lp*/	s_arg_arrayresize,
	},
	{
		/*ccname*/	_WT("����_���鷴ת"),
		/*egname*/	_WT("sq_arrayreverse"),
		/*explain*/	_WT("��'ջ����'λ�õ�����Ԫ�ط�ת���ɹ�����>=0\r\n�˷���ֻ���������顣"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_����ɾ��"),
		/*egname*/	_WT("sq_arrayremove"),
		/*explain*/	_WT("��'ջ����'λ�õ�����ɾ��ָ�������ĳ�Ա���ɹ�����>=0\r\n�˷���ֻ���������顣"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_arrayremove) / sizeof(s_arg_arrayremove[0]),
		/*arg lp*/	s_arg_arrayremove,
	},
	{
		/*ccname*/	_WT("����_�������"),
		/*egname*/	_WT("sq_arrayinsert"),
		/*explain*/	_WT("��ջ�е���һ��ֵ������'ջ����'λ�õ�������롣�ɹ�����>=0\r\n�˷���ֻ���������顣"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_arrayremove) / sizeof(s_arg_arrayremove[0]),
		/*arg lp*/	s_arg_arrayremove,
	},
	{
		/*ccname*/	_WT("����_��ί��"),
		/*egname*/	_WT("sq_setdelegate"),
		/*explain*/	_WT("��ջ�е���һ����(table)������������Ϊ'ջ����'λ�ö����ί��,�ɹ�����>=0��Ҫ�Ӷ�����ɾ��ί�У�����ʹ��null��Ϊί�ж����Ǳ�(table)��"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_ȡί��"),
		/*egname*/	_WT("sq_setdelegate"),
		/*explain*/	_WT("��'ջ����'λ�ö���ĵ�ǰί�У�ѹ�뵽ջ��,�ɹ�����>=0��"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_��¡"),
		/*egname*/	_WT("sq_clone"),
		/*explain*/	_WT("��¡'ջ����'λ��ָ��ı������ʵ����������ѹ�뵽ջ��,�ɹ�����>=0��"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_�����ɱ���"),
		/*egname*/	_WT("sq_setfreevariable"),
		/*explain*/	_WT("��ջ�е���һ��ֵ������������Ϊ'ջ����'λ��ָ��ıհ������ɱ���,�ɹ�����>=0��"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_setfreevariable) / sizeof(s_arg_setfreevariable[0]),
		/*arg lp*/	s_arg_setfreevariable,
	},
	{
		/*ccname*/	_WT("����_��һ��"),
		/*egname*/	_WT("sq_next"),
		/*explain*/	_WT("��ջ��ѹ��һ������һ��ֵ�������ǲ���'ջ����'λ��ָ������顢��������һ�����,�ɹ�����>=0��\r\nҪ��ʼ�������˺�����Ҫ��ջ��������һ����ֵ; ��ÿ�ε���ʱ��������ʹ�õ������滻��ֵ����ѹ��������۵ļ���ֵ��ÿ�ε�����Ӧ�ó��򶼱��뵯��ǰһ������ֵ����������������������һ�ε����Ĳο��㣩�� ���������в�ۺ󣬸ú�����ʧ��"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_ȡ������ֵ"),
		/*egname*/	_WT("sq_getweakrefval"),
		/*explain*/	_WT("��ȡ'ջ����'���������õ�ֵ����ѹ�뵽ջ�У��ɹ�����>=0"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},
	{
		/*ccname*/	_WT("����_���"),
		/*egname*/	_WT("sq_clear"),
		/*explain*/	_WT("���'ջ����'���������������ֵ���ɹ�����>=0���˷����������ڱ�����顣"),
		/*category*/5,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_vm_idx) / sizeof(s_arg_vm_idx[0]),
		/*arg lp*/	s_arg_vm_idx,
	},

	//////////////////////////////////////////////////////////////////////////calls

	{
		/*ccname*/	_WT("����_����"),
		/*egname*/	_WT("sq_call"),
		/*explain*/	_WT("���ñհ��򱾵رհ����ɹ�����>=0��\r\n�ú����������в��������հ�����ջ��; ���'�Ƿ񷵻�ֵ'Ϊ�棬��ѹ��հ��ķ���ֵ�� ���ͨ�� ����_��ͣ�����������ִͣ�иú������򲻻��Զ���ջ�е����հ��Ͳ�����"),
		/*category*/6,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_call) / sizeof(s_arg_call[0]),
		/*arg lp*/	s_arg_call,
	},
	{
		/*ccname*/	_WT("����_�ָ�"),
		/*egname*/	_WT("sq_resume"),
		/*explain*/	_WT("�ָ�һ����ջ�������������ɹ�����>=0��"),
		/*category*/6,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_resume) / sizeof(s_arg_resume[0]),
		/*arg lp*/	s_arg_resume,
	},
	{
		/*ccname*/	_WT("����_ȡ�ֲ�����"),
		/*egname*/	_WT("sq_getlocal"),
		/*explain*/	_WT("����ָ��ջ����������ľֲ��������ƣ���ѹ��ջ�����ɱ�������Ϊ�ֲ�������"),
		/*category*/6,
		/*state*/	0,
		/*ret*/		SDT_TEXT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_getlocal) / sizeof(s_arg_getlocal[0]),
		/*arg lp*/	s_arg_getlocal,
	},
	{
		/*ccname*/	_WT("����_ȡ��ǰ�հ�"),
		/*egname*/	_WT("sq_getcallee"),
		/*explain*/	_WT("��ȡ��ǰ���еıհ�����ѹ��ջ���ɹ�����>=0��"),
		/*category*/6,
		/*state*/	0,
		/*ret*/		SDT_TEXT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_ȡ���ɱ���"),
		/*egname*/	_WT("sq_getfreevariable"),
		/*explain*/	_WT("��ȡ'ջ����'λ�õıհ���ָ�����������ɱ��������ɹ�����>=0��"),
		/*category*/6,
		/*state*/	0,
		/*ret*/		SDT_TEXT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_getfreevariable) / sizeof(s_arg_getfreevariable[0]),
		/*arg lp*/	s_arg_getfreevariable,
	},
	{
		/*ccname*/	_WT("����_�׳�����"),
		/*egname*/	_WT("sq_throwerror"),
		/*explain*/	_WT("����������е������󣬲����ر��رհ����ص�ֵ���Ա���������д����쳣��"),
		/*category*/6,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_throwerror) / sizeof(s_arg_throwerror[0]),
		/*arg lp*/	s_arg_throwerror,
	},
	{
		/*ccname*/	_WT("����_�׳�����"),
		/*egname*/	_WT("sq_throwobject"),
		/*explain*/	_WT("��ջ�е���һ����������Ϊ������е������󣬲����ر��رհ����ص�ֵ���Ա���������д����쳣��"),
		/*category*/6,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_���ô���"),
		/*egname*/	_WT("sq_reseterror"),
		/*explain*/	_WT("��������е�����������Ϊ null��"),
		/*category*/6,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_ȡ������"),
		/*egname*/	_WT("sq_getlasterror"),
		/*explain*/	_WT("���������������ѹ��ջ"),
		/*category*/6,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},

	//////////////////////////////////////////////////////////////////////////ԭʼ����������
	{
		/*ccname*/	_WT("����_ȡջ����"),
		/*egname*/	_WT("sq_getstackobj"),
		/*explain*/	_WT("��ջ�л�ȡһ�����󣬲�������һ���������У��ɹ�����>=0"),
		/*category*/7,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_getstackobj) / sizeof(s_arg_getstackobj[0]),
		/*arg lp*/	s_arg_getstackobj,
	},
	{
		/*ccname*/	_WT("����_ѹ�����"),
		/*egname*/	_WT("sq_pushobject"),
		/*explain*/	_WT("�����������õĶ���ѹ��ջ"),
		/*category*/7,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_pushobject) / sizeof(s_arg_pushobject[0]),
		/*arg lp*/	s_arg_pushobject,
	},
	{
		/*ccname*/	_WT("����_�������"),
		/*egname*/	_WT("sq_addref"),
		/*explain*/	_WT("��Ӷ��������ü���"),
		/*category*/7,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_addref) / sizeof(s_arg_addref[0]),
		/*arg lp*/	s_arg_addref,
	},
	{
		/*ccname*/	_WT("����_��������"),
		/*egname*/	_WT("sq_release"),
		/*explain*/	_WT("���ٶ��������ü���"),
		/*category*/7,
		/*state*/	0,
		/*ret*/		SDT_BOOL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_addref) / sizeof(s_arg_addref[0]),
		/*arg lp*/	s_arg_addref,
	},
	{
		/*ccname*/	_WT("����_ȡ���ü���"),
		/*egname*/	_WT("sq_getrefcount"),
		/*explain*/	_WT("��ȡ�����������ü���"),
		/*category*/7,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_addref) / sizeof(s_arg_addref[0]),
		/*arg lp*/	s_arg_addref,
	},
	{
		/*ccname*/	_WT("����_���ö���"),
		/*egname*/	_WT("sq_resetobject"),
		/*explain*/	_WT("���ã���ʼ����������������ʹ�ô˺�����ʼ��ÿ����������"),
		/*category*/7,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_pobj) / sizeof(s_arg_pobj[0]),
		/*arg lp*/	s_arg_pobj,
	},
	{
		/*ccname*/	_WT("����_�����ı�"),
		/*egname*/	_WT("sq_objtostring"),
		/*explain*/	_WT("����ԭʼ�������õ��ַ���ֵ��"),
		/*category*/7,
		/*state*/	0,
		/*ret*/		SDT_TEXT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_pobj) / sizeof(s_arg_pobj[0]),
		/*arg lp*/	s_arg_pobj,
	},
	{
		/*ccname*/	_WT("����_�����߼�"),
		/*egname*/	_WT("sq_objtobool"),
		/*explain*/	_WT("����ԭʼ�������õ��߼�ֵ��"),
		/*category*/7,
		/*state*/	0,
		/*ret*/		SDT_BOOL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_pobj) / sizeof(s_arg_pobj[0]),
		/*arg lp*/	s_arg_pobj,
	},
	{
		/*ccname*/	_WT("����_��������"),
		/*egname*/	_WT("sq_objtointeger"),
		/*explain*/	_WT("����ԭʼ�������õ�����ֵ��"),
		/*category*/7,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_pobj) / sizeof(s_arg_pobj[0]),
		/*arg lp*/	s_arg_pobj,
	},
	{
		/*ccname*/	_WT("����_���󵽸�����"),
		/*egname*/	_WT("sq_objtofloat"),
		/*explain*/	_WT("����ԭʼ�������õĸ�����ֵ��"),
		/*category*/7,
		/*state*/	0,
		/*ret*/		SDT_FLOAT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_pobj) / sizeof(s_arg_pobj[0]),
		/*arg lp*/	s_arg_pobj,
	},
	{
		/*ccname*/	_WT("����_�����û�ָ��"),
		/*egname*/	_WT("sq_objtouserpointer"),
		/*explain*/	_WT("����ԭʼ�������õ��û�ָ�롣"),
		/*category*/7,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_pobj) / sizeof(s_arg_pobj[0]),
		/*arg lp*/	s_arg_pobj,
	},
	{
		/*ccname*/	_WT("����_ȡ�������ͱ�ǩ"),
		/*egname*/	_WT("sq_getobjtypetag"),
		/*explain*/	_WT("��ȡԭʼ����(userdata �� class)�����ͱ�ǩ��"),
		/*category*/7,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_getobjtypetag) / sizeof(s_arg_getobjtypetag[0]),
		/*arg lp*/	s_arg_getobjtypetag,
	},
	{
		/*ccname*/	_WT("����_ȡ��������ü���"),
		/*egname*/	_WT("sq_getvmrefcount"),
		/*explain*/	_WT("��ȡ��������������е����ü���"),
		/*category*/7,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_addref) / sizeof(s_arg_addref[0]),
		/*arg lp*/	s_arg_addref,
	},

	//////////////////////////////////////////////////////////////////////////��������

	{
		/*ccname*/	_WT("����_��������"),
		/*egname*/	_WT("sq_collectgarbage"),
		/*explain*/	_WT("�����������������������ҵ��ģ���ɾ��������������"),
		/*category*/8,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_�����޷�����"),
		/*egname*/	_WT("sq_resurrectunreachable"),
		/*explain*/	_WT("�����������������������ҵ������޷����ʵĶ�������һ������ѹ��ջ�С��ɹ�����>=0"),
		/*category*/8,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},

	//////////////////////////////////////////////////////////////////////////���л�

	{
		/*ccname*/	_WT("����_д���հ�"),
		/*egname*/	_WT("sq_writeclosure"),
		/*explain*/	_WT("���л���write��ջ�����ıհ���Ŀ����ͨ���û������д�ص��������ɹ�����>=0���������ɱ����ıհ��޷����л�"),
		/*category*/9,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_writeclosure) / sizeof(s_arg_writeclosure[0]),
		/*arg lp*/	s_arg_writeclosure,
	},

	{
		/*ccname*/	_WT("����_����հ�"),
		/*egname*/	_WT("sq_readclosure"),
		/*explain*/	_WT("���л���read��һ���հ�����ѹ��ջ��Դ��ͨ���û�����Ķ��ص��������ɹ�����>=0"),
		/*category*/9,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_writeclosure) / sizeof(s_arg_writeclosure[0]),
		/*arg lp*/	s_arg_writeclosure,
	},

	//////////////////////////////////////////////////////////////////////////����
	{
		/*ccname*/	_WT("����_ȡջ��Ϣ"),
		/*egname*/	_WT("sq_stackinfos"),
		/*explain*/	_WT("��ȡ����ջ��ĳ������ĵ���ջ��Ϣ���ɹ�����>=0"),
		/*category*/10,
		/*state*/	0,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_stackinfos) / sizeof(s_arg_stackinfos[0]),
		/*arg lp*/	s_arg_stackinfos,
	},
	{
		/*ccname*/	_WT("����_�õ��Թ���"),
		/*egname*/	_WT("sq_setdebughook"),
		/*explain*/	_WT("��ջ����һ���հ�������������Ϊ���Թ��ӡ����õ��Թ���ʱ�����Ḳ���κ���ǰ���õı�����Ǳ������ӡ��������Ϊnull���򽫽��õ��Թ��ӡ�"),
		/*category*/10,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_onlyvm) / sizeof(s_arg_onlyvm[0]),
		/*arg lp*/	s_arg_onlyvm,
	},
	{
		/*ccname*/	_WT("����_�ñ��ص��Թ���"),
		/*egname*/	_WT("sq_setnativedebughook"),
		/*explain*/	_WT("���ñ������Թ��ӡ����ñ�������ʱ�����Ḳ���κ���ǰ���õı������ӻ�Ǳ������ӡ� �������ΪNULL���򽫽��õ��Թ��ӡ�"),
		/*category*/10,
		/*state*/	0,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_setnativedebughook) / sizeof(s_arg_setnativedebughook[0]),
		/*arg lp*/	s_arg_setnativedebughook,
	},
};
#endif


//////////////////////////////////////////////////////////////////////////�����
EXTERN_C void esquirrel3_fn_sq_open(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = (INT)sq_open(pArgInf[0].m_int);
}
EXTERN_C void esquirrel3_fn_sq_newthread(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = (INT)sq_newthread((HSQUIRRELVM)pArgInf[0].m_int, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_seterrorhandler(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	sq_seterrorhandler((HSQUIRRELVM)pArgInf[0].m_int);
}

EXTERN_C void esquirrel3_fn_sq_close(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	sq_close((HSQUIRRELVM)pArgInf[0].m_int);
}

EXTERN_C void esquirrel3_fn_sq_setforeignptr(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	sq_setforeignptr((HSQUIRRELVM)pArgInf[0].m_int, (SQUserPointer)pArgInf[1].m_int);
}

EXTERN_C void esquirrel3_fn_sq_getforeignptr(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = (INT)sq_getforeignptr((HSQUIRRELVM)pArgInf[0].m_int);
}

EXTERN_C void esquirrel3_fn_sq_setsharedforeignptr(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	sq_setsharedforeignptr((HSQUIRRELVM)pArgInf[0].m_int, (SQUserPointer)pArgInf[1].m_int);
}

EXTERN_C void esquirrel3_fn_sq_getsharedforeignptr(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = (INT)sq_getsharedforeignptr((HSQUIRRELVM)pArgInf[0].m_int);
}

EXTERN_C void esquirrel3_fn_sq_setvmreleasehook(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SQRELEASEHOOK hook = (SQRELEASEHOOK)pArgInf[1].m_int;
	sq_setvmreleasehook((HSQUIRRELVM)pArgInf[0].m_int, hook);
}

EXTERN_C void esquirrel3_fn_sq_getvmreleasehook(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = (INT)sq_getvmreleasehook((HSQUIRRELVM)pArgInf[0].m_int);
}

EXTERN_C void esquirrel3_fn_sq_setsharedreleasehook(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SQRELEASEHOOK hook = (SQRELEASEHOOK)pArgInf[1].m_int;
	sq_setsharedreleasehook((HSQUIRRELVM)pArgInf[0].m_int, hook);
}

EXTERN_C void esquirrel3_fn_sq_getsharedreleasehook(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = (INT)sq_getsharedreleasehook((HSQUIRRELVM)pArgInf[0].m_int);
}


EXTERN_C void esquirrel3_fn_sq_setprintfunc(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	sq_setprintfunc((HSQUIRRELVM)pArgInf[0].m_int, (SQPRINTFUNCTION)pArgInf[1].m_int, (SQPRINTFUNCTION)pArgInf[2].m_int);
}

EXTERN_C void esquirrel3_fn_sq_getprintfunc(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = (INT)sq_getprintfunc(vm);
}

EXTERN_C void esquirrel3_fn_sq_geterrorfunc(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = (INT)sq_geterrorfunc(vm);
}
EXTERN_C void esquirrel3_fn_sq_suspendvm(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = sq_suspendvm((HSQUIRRELVM)pArgInf[0].m_int);
}
EXTERN_C void esquirrel3_fn_sq_wakeupvm(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = sq_wakeupvm((HSQUIRRELVM)pArgInf[0].m_int, pArgInf[1].m_bool, pArgInf[2].m_bool, pArgInf[3].m_bool, pArgInf[4].m_bool);
}

EXTERN_C void esquirrel3_fn_sq_getvmstate(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = sq_getvmstate((HSQUIRRELVM)pArgInf[0].m_int);
}

EXTERN_C void esquirrel3_fn_sq_getversion(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = sq_getversion();
}

//////////////////////////////////////////////////////////////////////////����
EXTERN_C void esquirrel3_fn_sq_compile(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = sq_compile((HSQUIRRELVM)pArgInf[0].m_int, (SQLEXREADFUNC)pArgInf[1].m_int, (LPVOID)pArgInf[2].m_int, pArgInf[3].m_pText, pArgInf[4].m_bool);
}

EXTERN_C void esquirrel3_fn_sq_compilebuffer(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	DATA_TYPE t = pArgInf[1].m_dtDataType;
	SQChar * s = NULL;
	SQInteger len = 0;
	if (t == SDT_TEXT)
	{
		s = pArgInf[1].m_pText;
		len = strlen(s);
	}
	else if(t == SDT_BIN)
	{
		s = (SQChar*)pArgInf[1].m_pBin + sizeof(INT) * 2;
		len = *(LPINT)(pArgInf[1].m_pBin + sizeof(INT));
	}
	pRetData->m_int = sq_compilebuffer((HSQUIRRELVM)pArgInf[0].m_int, s, len, pArgInf[2].m_pText, pArgInf[3].m_bool);

}

EXTERN_C void esquirrel3_fn_sq_enabledebuginfo(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	sq_enabledebuginfo((HSQUIRRELVM)pArgInf[0].m_int, pArgInf[1].m_bool);
}

EXTERN_C void esquirrel3_fn_sq_notifyallexceptions(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	sq_notifyallexceptions((HSQUIRRELVM)pArgInf[0].m_int, pArgInf[1].m_bool);
}

EXTERN_C void esquirrel3_fn_sq_setcompilererrorhandler(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_setcompilererrorhandler(vm, (SQCOMPILERERROR)pArgInf[1].m_int);
}

//////////////////////////////////////////////////////////////////////////ջ����

EXTERN_C void esquirrel3_fn_sq_push(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_push(vm, pArgInf[1].m_int);
}

EXTERN_C void esquirrel3_fn_sq_pop(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_pop(vm, pArgInf[1].m_int);
}

EXTERN_C void esquirrel3_fn_sq_poptop(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_poptop(vm);
}
EXTERN_C void esquirrel3_fn_sq_remove(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_remove(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_gettop(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_gettop(vm);
}
EXTERN_C void esquirrel3_fn_sq_settop(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_settop(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_reservestack(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_reservestack(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_cmp(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_cmp(vm);
}
EXTERN_C void esquirrel3_fn_sq_move(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_move(vm, (HSQUIRRELVM)pArgInf[1].m_int, pArgInf[2].m_int);
}

//////////////////////////////////////////////////////////////////////////���󴴽��ʹ���

EXTERN_C void esquirrel3_fn_sq_newuserdata(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = (INT)sq_newuserdata(vm, pArgInf[1].m_int);
}

EXTERN_C void esquirrel3_fn_sq_newtable(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_newtable(vm);
}
EXTERN_C void esquirrel3_fn_sq_newtableex(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_newtableex(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_newarray(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_newarray(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_newclosure(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_newclosure(vm, (SQFUNCTION)pArgInf[1].m_int, pArgInf[2].m_int);
}
EXTERN_C void esquirrel3_fn_sq_setparamscheck(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_setparamscheck(vm, pArgInf[1].m_int, pArgInf[2].m_pText);
}

EXTERN_C void esquirrel3_fn_sq_bindenv(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_bindenv(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_setclosureroot(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_setclosureroot(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_getclosureroot(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_getclosureroot(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_pushstring(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_pushstring(vm, pArgInf[1].m_pText, -1);
}
EXTERN_C void esquirrel3_fn_sq_pushfloat(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_pushfloat(vm, pArgInf[1].m_float);
}
EXTERN_C void esquirrel3_fn_sq_pushinteger(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_pushinteger(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_pushbool(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_pushbool(vm, pArgInf[1].m_bool);
}
EXTERN_C void esquirrel3_fn_sq_pushuserpointer(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_pushuserpointer(vm, (SQUserPointer)pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_pushnull(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_pushnull(vm);
}
EXTERN_C void esquirrel3_fn_sq_pushthread(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_pushthread(vm, (HSQUIRRELVM)pArgInf[1].m_int);
}

EXTERN_C void esquirrel3_fn_sq_gettype(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_gettype(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_typeof(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_typeof(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_getsize(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_getsize(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_gethash(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_gethash(vm, pArgInf[1].m_int);
}

EXTERN_C void esquirrel3_fn_sq_getbase(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_getbase(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_instanceof(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_bool = sq_instanceof(vm);
}
EXTERN_C void esquirrel3_fn_sq_tostring(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_tostring(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_tobool(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	SQBool b = 0;
	sq_tobool(vm, pArgInf[1].m_int, &b);
	pRetData->m_bool = b;
}
EXTERN_C void esquirrel3_fn_sq_getstring(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	const SQChar* pString = NULL;
	pRetData->m_int = sq_getstring(vm, pArgInf[1].m_int, &pString);
	free(*pArgInf[2].m_ppText);
	*pArgInf[2].m_ppText = zy_clone_text(pString);
}
EXTERN_C void esquirrel3_fn_sq_getinteger(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_getinteger(vm, pArgInf[1].m_int, pArgInf[2].m_pInt);
}
EXTERN_C void esquirrel3_fn_sq_getfloat(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_getfloat(vm, pArgInf[1].m_int, pArgInf[2].m_pFloat);
}
EXTERN_C void esquirrel3_fn_sq_getbool(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_getbool(vm, pArgInf[1].m_int, (SQBool*)pArgInf[2].m_pBool);
}
EXTERN_C void esquirrel3_fn_sq_getthread(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_getthread(vm, pArgInf[1].m_int, (HSQUIRRELVM*)pArgInf[2].m_pInt);
}
EXTERN_C void esquirrel3_fn_sq_getuserpointer(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_getuserpointer(vm, pArgInf[1].m_int, (SQUserPointer*)pArgInf[2].m_pInt);
}
EXTERN_C void esquirrel3_fn_sq_getuserdata(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	SQUserPointer typetag;
	pRetData->m_int = sq_getuserdata(vm, pArgInf[1].m_int, (SQUserPointer*)pArgInf[2].m_pInt, &typetag);
	if (pArgInf[3].m_dtDataType != _SDT_NULL)
	{
		*pArgInf[3].m_pInt = (INT)typetag;
	}
}
EXTERN_C void esquirrel3_fn_sq_settypetag(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_settypetag(vm, pArgInf[1].m_int, (SQUserPointer)pArgInf[2].m_int);
}

EXTERN_C void esquirrel3_fn_sq_gettypetag(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_gettypetag(vm, pArgInf[1].m_int, (SQUserPointer*)pArgInf[2].m_pInt);
}

EXTERN_C void esquirrel3_fn_sq_setreleasehook(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	SQRELEASEHOOK func = (SQRELEASEHOOK)pArgInf[2].m_int;
	sq_setreleasehook(vm, pArgInf[1].m_int, func);
}
EXTERN_C void esquirrel3_fn_sq_getreleasehook(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = (INT)sq_getreleasehook(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_getscratchpad(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = (INT)sq_getscratchpad(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_getfunctioninfo(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	SQFunctionInfo sqinfo, temp;
	ZeroMemory(&sqinfo, sizeof(SQFunctionInfo));
	pRetData->m_int = sq_getfunctioninfo(vm, pArgInf[1].m_int, &sqinfo);
	//�ͷ�֮ǰ��
	LPBYTE ptr = (LPBYTE)*pArgInf[2].m_ppCompoundData;
	if (ptr)
	{
		memcpy(&temp, ptr, sizeof(SQFunctionInfo));
		if (temp.name)
		{
			free((void*)temp.name);
		}
		if (temp.source)
		{
			free((void*)temp.source);
		}
		free(ptr);
	}
	ptr = (LPBYTE)malloc(sizeof(SQFunctionInfo));
	memcpy(ptr, &sqinfo, sizeof(SQFunctionInfo));
	*pArgInf[2].m_ppCompoundData = ptr;
}
EXTERN_C void esquirrel3_fn_sq_getclosureinfo(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_getclosureinfo(vm, pArgInf[1].m_int, (SQUnsignedInteger*)pArgInf[2].m_pUInt, (SQUnsignedInteger*)pArgInf[3].m_pUInt);
}
EXTERN_C void esquirrel3_fn_sq_getclosurename(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_getclosurename(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_setnativeclosurename(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_setnativeclosurename(vm, pArgInf[1].m_int, pArgInf[2].m_pText);
}
EXTERN_C void esquirrel3_fn_sq_setinstanceup(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_setinstanceup(vm, pArgInf[1].m_int, (SQUserPointer)pArgInf[2].m_int);
}
EXTERN_C void esquirrel3_fn_sq_getinstanceup(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_getinstanceup(vm, pArgInf[1].m_int, (SQUserPointer*)pArgInf[2].m_pInt, (SQUserPointer)pArgInf[3].m_int);
}
EXTERN_C void esquirrel3_fn_sq_setclassudsize(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_setclassudsize(vm, pArgInf[1].m_int, pArgInf[2].m_int);
}
EXTERN_C void esquirrel3_fn_sq_newclass(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_newclass(vm, pArgInf[1].m_bool);
}
EXTERN_C void esquirrel3_fn_sq_createinstance(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_createinstance(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_setattributes(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_setattributes(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_getattributes(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_getattributes(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_getclass(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_getclass(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_weakref(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_weakref(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_getdefaultdelegate(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_getdefaultdelegate(vm, (SQObjectType)pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_getmemberhandle(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_getmemberhandle(vm, pArgInf[1].m_int, (HSQMEMBERHANDLE*)pArgInf[2].m_pInt64);
}
EXTERN_C void esquirrel3_fn_sq_getbyhandle(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_getbyhandle(vm, pArgInf[1].m_int, (HSQMEMBERHANDLE*)pArgInf[2].m_pInt64);
}
EXTERN_C void esquirrel3_fn_sq_setbyhandle(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_setbyhandle(vm, pArgInf[1].m_int, (HSQMEMBERHANDLE*)pArgInf[2].m_pInt64);
}

//////////////////////////////////////////////////////////////////////////�������


EXTERN_C void esquirrel3_fn_sq_pushroottable(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_pushroottable(vm);
}
EXTERN_C void esquirrel3_fn_sq_pushregistrytable(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_pushregistrytable(vm);
}
EXTERN_C void esquirrel3_fn_sq_pushconsttable(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_pushconsttable(vm);
}
EXTERN_C void esquirrel3_fn_sq_setroottable(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_setroottable(vm);
}
EXTERN_C void esquirrel3_fn_sq_setconsttable(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_setconsttable(vm);
}
EXTERN_C void esquirrel3_fn_sq_newslot(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_newslot(vm, pArgInf[1].m_int, pArgInf[2].m_bool);
}
EXTERN_C void esquirrel3_fn_sq_deleteslot(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_deleteslot(vm, pArgInf[1].m_int, pArgInf[2].m_bool);
}
EXTERN_C void esquirrel3_fn_sq_set(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_set(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_get(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_get(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_rawset(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_rawset(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_rawget(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_rawget(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_rawdeleteslot(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_rawdeleteslot(vm, pArgInf[1].m_int, pArgInf[2].m_bool);
}
EXTERN_C void esquirrel3_fn_sq_newmember(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_newmember(vm, pArgInf[1].m_int, pArgInf[2].m_bool);
}
EXTERN_C void esquirrel3_fn_sq_rawnewmember(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_rawnewmember(vm, pArgInf[1].m_int, pArgInf[2].m_bool);
}
EXTERN_C void esquirrel3_fn_sq_arrayappend(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_arrayappend(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_arraypop(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_arraypop(vm, pArgInf[1].m_int, pArgInf[2].m_bool);
}
EXTERN_C void esquirrel3_fn_sq_arrayresize(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_arrayresize(vm, pArgInf[1].m_int, pArgInf[2].m_int);
}
EXTERN_C void esquirrel3_fn_sq_arrayreverse(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_arrayreverse(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_arrayremove(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_arrayremove(vm, pArgInf[1].m_int, pArgInf[2].m_int);
}
EXTERN_C void esquirrel3_fn_sq_arrayinsert(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_arrayinsert(vm, pArgInf[1].m_int, pArgInf[2].m_int);
}
EXTERN_C void esquirrel3_fn_sq_setdelegate(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_setdelegate(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_getdelegate(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_getdelegate(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_clone(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_clone(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_setfreevariable(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_setfreevariable(vm, pArgInf[1].m_int, pArgInf[2].m_int);
}
EXTERN_C void esquirrel3_fn_sq_next(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_next(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_getweakrefval(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_getweakrefval(vm, pArgInf[1].m_int);
}
EXTERN_C void esquirrel3_fn_sq_clear(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_clear(vm, pArgInf[1].m_int);
}

//////////////////////////////////////////////////////////////////////////calls

EXTERN_C void esquirrel3_fn_sq_call(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_call(vm, pArgInf[1].m_int, pArgInf[2].m_bool, pArgInf[3].m_bool);
}

EXTERN_C void esquirrel3_fn_sq_resume(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_resume(vm, pArgInf[1].m_bool, pArgInf[2].m_bool);
}

EXTERN_C void esquirrel3_fn_sq_getlocal(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	const SQChar* name = sq_getlocal(vm, pArgInf[1].m_int, pArgInf[2].m_int);
	if (name)
	{
		pRetData->m_pText = zy_clone_text(name);
	}
}

EXTERN_C void esquirrel3_fn_sq_getcallee(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_getcallee(vm);
}
EXTERN_C void esquirrel3_fn_sq_getfreevariable(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	const SQChar* name = sq_getfreevariable(vm, pArgInf[1].m_int, pArgInf[2].m_int);
	if (name)
	{
		pRetData->m_pText = zy_clone_text(name);
	}
}
EXTERN_C void esquirrel3_fn_sq_throwerror(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_throwerror(vm, pArgInf[1].m_pText);
}
EXTERN_C void esquirrel3_fn_sq_throwobject(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_throwobject(vm);
}
EXTERN_C void esquirrel3_fn_sq_reseterror(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_reseterror(vm);
}
EXTERN_C void esquirrel3_fn_sq_getlasterror(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_getlasterror(vm);
}

////////////////////////////////////////////////////////////ԭʼ�������

EXTERN_C void esquirrel3_fn_sq_getstackobj(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_getstackobj(vm, pArgInf[1].m_int, (HSQOBJECT*)pArgInf[2].m_pInt64);
}
EXTERN_C void esquirrel3_fn_sq_pushobject(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	HSQOBJECT obj;
	memcpy(&obj, &pArgInf[1].m_int64, sizeof(HSQOBJECT));
	sq_pushobject(vm, obj);
}
EXTERN_C void esquirrel3_fn_sq_addref(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_addref(vm, (HSQOBJECT*)pArgInf[1].m_pInt64);
}
EXTERN_C void esquirrel3_fn_sq_release(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_bool = sq_release(vm, (HSQOBJECT*)pArgInf[1].m_pInt64);
}
EXTERN_C void esquirrel3_fn_sq_getrefcount(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_getrefcount(vm, (HSQOBJECT*)pArgInf[1].m_pInt64);
}
EXTERN_C void esquirrel3_fn_sq_resetobject(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	sq_resetobject((HSQOBJECT*)pArgInf[0].m_pInt64);
}
EXTERN_C void esquirrel3_fn_sq_objtostring(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	const SQChar* str = sq_objtostring((HSQOBJECT*)pArgInf[0].m_pInt64);
	if (str)
	{
		pRetData->m_pText = zy_clone_text(str);
	}
}
EXTERN_C void esquirrel3_fn_sq_objtobool(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_bool = sq_objtobool((HSQOBJECT*)pArgInf[0].m_pInt64);
}
EXTERN_C void esquirrel3_fn_sq_objtointeger(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = sq_objtointeger((HSQOBJECT*)pArgInf[0].m_pInt64);
}
EXTERN_C void esquirrel3_fn_sq_objtofloat(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_float = sq_objtofloat((HSQOBJECT*)pArgInf[0].m_pInt64);
}
EXTERN_C void esquirrel3_fn_sq_objtouserpointer(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = (INT)sq_objtouserpointer((HSQOBJECT*)pArgInf[0].m_pInt64);
}
EXTERN_C void esquirrel3_fn_sq_getobjtypetag(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = (INT)sq_getobjtypetag((HSQOBJECT*)pArgInf[0].m_pInt64, (SQUserPointer*)pArgInf[1].m_pInt);
}
EXTERN_C void esquirrel3_fn_sq_getvmrefcount(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_getvmrefcount(vm, (HSQOBJECT*)pArgInf[1].m_pInt64);
}

//////////////////////////////////////////////////////////////////////////��������

EXTERN_C void esquirrel3_fn_sq_collectgarbage(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_collectgarbage(vm);
}
EXTERN_C void esquirrel3_fn_sq_resurrectunreachable(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	pRetData->m_int = sq_resurrectunreachable(vm);
}

//////////////////////////////////////////////////////////////////////////���л�

EXTERN_C void esquirrel3_fn_sq_writeclosure(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	SQWRITEFUNC func = (SQWRITEFUNC)pArgInf[1].m_int;

	pRetData->m_int = sq_writeclosure(vm, func, (SQUserPointer)pArgInf[2].m_int);
}

EXTERN_C void esquirrel3_fn_sq_readclosure(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	SQREADFUNC func = (SQREADFUNC)pArgInf[1].m_int;

	pRetData->m_int = sq_readclosure(vm, func, (SQUserPointer)pArgInf[2].m_int);
}

//////////////////////////////////////////////////////////////////////////����

EXTERN_C void esquirrel3_fn_sq_stackinfos(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	SQStackInfos infos, tmp;
	ZeroMemory(&infos, sizeof(SQStackInfos));
	void* ptr = *pArgInf[2].m_ppCompoundData;
	if (ptr)
	{
		memcpy(&tmp, ptr, sizeof(SQStackInfos));
		if (tmp.funcname)
		{
			free((void*)tmp.funcname);
		}
		if (tmp.source)
		{
			free((void*)tmp.source);
		}
		free(ptr);
	}
	pRetData->m_int = sq_stackinfos(vm, pArgInf[1].m_int, &infos);
	ptr = malloc(sizeof(SQStackInfos));
	memcpy(ptr, &infos, sizeof(SQStackInfos));
	*pArgInf[2].m_ppCompoundData = ptr;

}
EXTERN_C void esquirrel3_fn_sq_setdebughook(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	sq_setdebughook(vm);
}
EXTERN_C void esquirrel3_fn_sq_setnativedebughook(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	SQDEBUGHOOK hook = (SQDEBUGHOOK)pArgInf[1].m_int;
	sq_setnativedebughook(vm, hook);
}

#ifndef __E_STATIC_LIB
PFN_EXECUTE_CMD s_RunFunc[] =	// ����Ӧ��s_CmdInfo�е������˳���Ӧ
{
	esquirrel3_fn_sq_open,
	esquirrel3_fn_sq_newthread,
	esquirrel3_fn_sq_seterrorhandler,
	esquirrel3_fn_sq_close,
	esquirrel3_fn_sq_setforeignptr,
	esquirrel3_fn_sq_getforeignptr,
	esquirrel3_fn_sq_setsharedforeignptr,
	esquirrel3_fn_sq_getsharedforeignptr,
	esquirrel3_fn_sq_setvmreleasehook,
	esquirrel3_fn_sq_getvmreleasehook,
	esquirrel3_fn_sq_setsharedreleasehook,
	esquirrel3_fn_sq_getsharedreleasehook,
	esquirrel3_fn_sq_setprintfunc,
	esquirrel3_fn_sq_getprintfunc,
	esquirrel3_fn_sq_geterrorfunc,
	esquirrel3_fn_sq_suspendvm,
	esquirrel3_fn_sq_wakeupvm,
	esquirrel3_fn_sq_getvmstate,
	esquirrel3_fn_sq_getversion,
	esquirrel3_fn_sq_compile,
	esquirrel3_fn_sq_compilebuffer,
	esquirrel3_fn_sq_enabledebuginfo,
	esquirrel3_fn_sq_notifyallexceptions,
	esquirrel3_fn_sq_setcompilererrorhandler,
	esquirrel3_fn_sq_push,
	esquirrel3_fn_sq_pop,
	esquirrel3_fn_sq_poptop,
	esquirrel3_fn_sq_remove,
	esquirrel3_fn_sq_gettop,
	esquirrel3_fn_sq_settop,
	esquirrel3_fn_sq_reservestack,
	esquirrel3_fn_sq_cmp,
	esquirrel3_fn_sq_move,
	esquirrel3_fn_sq_newuserdata,
	esquirrel3_fn_sq_newtable,
	esquirrel3_fn_sq_newtableex,
	esquirrel3_fn_sq_newarray,
	esquirrel3_fn_sq_newclosure,
	esquirrel3_fn_sq_setparamscheck,
	esquirrel3_fn_sq_bindenv,
	esquirrel3_fn_sq_setclosureroot,
	esquirrel3_fn_sq_getclosureroot,
	esquirrel3_fn_sq_pushstring,
	esquirrel3_fn_sq_pushfloat,
	esquirrel3_fn_sq_pushinteger,
	esquirrel3_fn_sq_pushbool,
	esquirrel3_fn_sq_pushuserpointer,
	esquirrel3_fn_sq_pushnull,
	esquirrel3_fn_sq_pushthread,
	esquirrel3_fn_sq_gettype,
	esquirrel3_fn_sq_typeof,
	esquirrel3_fn_sq_getsize,
	esquirrel3_fn_sq_gethash,
	esquirrel3_fn_sq_getbase,
	esquirrel3_fn_sq_instanceof,
	esquirrel3_fn_sq_tostring,
	esquirrel3_fn_sq_tobool,
	esquirrel3_fn_sq_getstring,
	esquirrel3_fn_sq_getinteger,
	esquirrel3_fn_sq_getfloat,
	esquirrel3_fn_sq_getbool,
	esquirrel3_fn_sq_getthread,
	esquirrel3_fn_sq_getuserpointer,
	esquirrel3_fn_sq_getuserdata,
	esquirrel3_fn_sq_settypetag,
	esquirrel3_fn_sq_gettypetag,
	esquirrel3_fn_sq_setreleasehook,
	esquirrel3_fn_sq_getreleasehook,
	esquirrel3_fn_sq_getscratchpad,
	esquirrel3_fn_sq_getfunctioninfo,
	esquirrel3_fn_sq_getclosureinfo,
	esquirrel3_fn_sq_getclosurename,
	esquirrel3_fn_sq_setnativeclosurename,
	esquirrel3_fn_sq_setinstanceup,
	esquirrel3_fn_sq_getinstanceup,
	esquirrel3_fn_sq_setclassudsize,
	esquirrel3_fn_sq_newclass,
	esquirrel3_fn_sq_createinstance,
	esquirrel3_fn_sq_setattributes,
	esquirrel3_fn_sq_getattributes,
	esquirrel3_fn_sq_getclass,
	esquirrel3_fn_sq_weakref,
	esquirrel3_fn_sq_getdefaultdelegate,
	esquirrel3_fn_sq_getmemberhandle,
	esquirrel3_fn_sq_getbyhandle,
	esquirrel3_fn_sq_setbyhandle,
	esquirrel3_fn_sq_pushroottable,
	esquirrel3_fn_sq_pushregistrytable,
	esquirrel3_fn_sq_pushconsttable,
	esquirrel3_fn_sq_setroottable,
	esquirrel3_fn_sq_setconsttable,
	esquirrel3_fn_sq_newslot,
	esquirrel3_fn_sq_deleteslot,
	esquirrel3_fn_sq_set,
	esquirrel3_fn_sq_get,
	esquirrel3_fn_sq_rawset,
	esquirrel3_fn_sq_rawget,
	esquirrel3_fn_sq_rawdeleteslot,
	esquirrel3_fn_sq_newmember,
	esquirrel3_fn_sq_rawnewmember,
	esquirrel3_fn_sq_arrayappend,
	esquirrel3_fn_sq_arraypop,
	esquirrel3_fn_sq_arrayresize,
	esquirrel3_fn_sq_arrayreverse,
	esquirrel3_fn_sq_arrayremove,
	esquirrel3_fn_sq_arrayinsert,
	esquirrel3_fn_sq_setdelegate,
	esquirrel3_fn_sq_getdelegate,
	esquirrel3_fn_sq_clone,
	esquirrel3_fn_sq_setfreevariable,
	esquirrel3_fn_sq_next,
	esquirrel3_fn_sq_getweakrefval,
	esquirrel3_fn_sq_clear,
	esquirrel3_fn_sq_call,
	esquirrel3_fn_sq_resume,
	esquirrel3_fn_sq_getlocal,
	esquirrel3_fn_sq_getcallee,
	esquirrel3_fn_sq_getfreevariable,
	esquirrel3_fn_sq_throwerror,
	esquirrel3_fn_sq_throwobject,
	esquirrel3_fn_sq_reseterror,
	esquirrel3_fn_sq_getlasterror,
	esquirrel3_fn_sq_getstackobj,
	esquirrel3_fn_sq_pushobject,
	esquirrel3_fn_sq_addref,
	esquirrel3_fn_sq_release,
	esquirrel3_fn_sq_getrefcount,
	esquirrel3_fn_sq_resetobject,
	esquirrel3_fn_sq_objtostring,
	esquirrel3_fn_sq_objtobool,
	esquirrel3_fn_sq_objtointeger,
	esquirrel3_fn_sq_objtofloat,
	esquirrel3_fn_sq_objtouserpointer,
	esquirrel3_fn_sq_getobjtypetag,
	esquirrel3_fn_sq_getvmrefcount,
	esquirrel3_fn_sq_collectgarbage,
	esquirrel3_fn_sq_resurrectunreachable,
	esquirrel3_fn_sq_writeclosure,
	esquirrel3_fn_sq_readclosure,
	esquirrel3_fn_sq_stackinfos,
	esquirrel3_fn_sq_setdebughook,
	esquirrel3_fn_sq_setnativedebughook
};

static const char* const g_CmdNames[] =
{
	"esquirrel3_fn_sq_open",
	"esquirrel3_fn_sq_newthread",
	"esquirrel3_fn_sq_seterrorhandler",
	"esquirrel3_fn_sq_close",
	"esquirrel3_fn_sq_setforeignptr",
	"esquirrel3_fn_sq_getforeignptr",
	"esquirrel3_fn_sq_setsharedforeignptr",
	"esquirrel3_fn_sq_getsharedforeignptr",
	"esquirrel3_fn_sq_setvmreleasehook",
	"esquirrel3_fn_sq_getvmreleasehook",
	"esquirrel3_fn_sq_setsharedreleasehook",
	"esquirrel3_fn_sq_getsharedreleasehook",
	"esquirrel3_fn_sq_setprintfunc",
	"esquirrel3_fn_sq_getprintfunc",
	"esquirrel3_fn_sq_geterrorfunc",
	"esquirrel3_fn_sq_suspendvm",
	"esquirrel3_fn_sq_wakeupvm",
	"esquirrel3_fn_sq_getvmstate",
	"esquirrel3_fn_sq_getversion",
	"esquirrel3_fn_sq_compile",
	"esquirrel3_fn_sq_compilebuffer",
	"esquirrel3_fn_sq_enabledebuginfo",
	"esquirrel3_fn_sq_notifyallexceptions",
	"esquirrel3_fn_sq_setcompilererrorhandler",
	"esquirrel3_fn_sq_push",
	"esquirrel3_fn_sq_pop",
	"esquirrel3_fn_sq_poptop",
	"esquirrel3_fn_sq_remove",
	"esquirrel3_fn_sq_gettop",
	"esquirrel3_fn_sq_settop",
	"esquirrel3_fn_sq_reservestack",
	"esquirrel3_fn_sq_cmp",
	"esquirrel3_fn_sq_move",
	"esquirrel3_fn_sq_newuserdata",
	"esquirrel3_fn_sq_newtable",
	"esquirrel3_fn_sq_newtableex",
	"esquirrel3_fn_sq_newarray",
	"esquirrel3_fn_sq_newclosure",
	"esquirrel3_fn_sq_setparamscheck",
	"esquirrel3_fn_sq_bindenv",
	"esquirrel3_fn_sq_setclosureroot",
	"esquirrel3_fn_sq_getclosureroot",
	"esquirrel3_fn_sq_pushstring",
	"esquirrel3_fn_sq_pushfloat",
	"esquirrel3_fn_sq_pushinteger",
	"esquirrel3_fn_sq_pushbool",
	"esquirrel3_fn_sq_pushuserpointer",
	"esquirrel3_fn_sq_pushnull",
	"esquirrel3_fn_sq_pushthread",
	"esquirrel3_fn_sq_gettype",
	"esquirrel3_fn_sq_typeof",
	"esquirrel3_fn_sq_getsize",
	"esquirrel3_fn_sq_gethash",
	"esquirrel3_fn_sq_getbase",
	"esquirrel3_fn_sq_instanceof",
	"esquirrel3_fn_sq_tostring",
	"esquirrel3_fn_sq_tobool",
	"esquirrel3_fn_sq_getstring",
	"esquirrel3_fn_sq_getinteger",
	"esquirrel3_fn_sq_getfloat",
	"esquirrel3_fn_sq_getbool",
	"esquirrel3_fn_sq_getthread",
	"esquirrel3_fn_sq_getuserpointer",
	"esquirrel3_fn_sq_getuserdata",
	"esquirrel3_fn_sq_settypetag",
	"esquirrel3_fn_sq_gettypetag",
	"esquirrel3_fn_sq_setreleasehook",
	"esquirrel3_fn_sq_getreleasehook",
	"esquirrel3_fn_sq_getscratchpad",
	"esquirrel3_fn_sq_getfunctioninfo",
	"esquirrel3_fn_sq_getclosureinfo",
	"esquirrel3_fn_sq_getclosurename",
	"esquirrel3_fn_sq_setnativeclosurename",
	"esquirrel3_fn_sq_setinstanceup",
	"esquirrel3_fn_sq_getinstanceup",
	"esquirrel3_fn_sq_setclassudsize",
	"esquirrel3_fn_sq_newclass",
	"esquirrel3_fn_sq_createinstance",
	"esquirrel3_fn_sq_setattributes",
	"esquirrel3_fn_sq_getattributes",
	"esquirrel3_fn_sq_getclass",
	"esquirrel3_fn_sq_weakref",
	"esquirrel3_fn_sq_getdefaultdelegate",
	"esquirrel3_fn_sq_getmemberhandle",
	"esquirrel3_fn_sq_getbyhandle",
	"esquirrel3_fn_sq_setbyhandle",
	"esquirrel3_fn_sq_pushroottable",
	"esquirrel3_fn_sq_pushregistrytable",
	"esquirrel3_fn_sq_pushconsttable",
	"esquirrel3_fn_sq_setroottable",
	"esquirrel3_fn_sq_setconsttable",
	"esquirrel3_fn_sq_newslot",
	"esquirrel3_fn_sq_deleteslot",
	"esquirrel3_fn_sq_set",
	"esquirrel3_fn_sq_get",
	"esquirrel3_fn_sq_rawset",
	"esquirrel3_fn_sq_rawget",
	"esquirrel3_fn_sq_rawdeleteslot",
	"esquirrel3_fn_sq_newmember",
	"esquirrel3_fn_sq_rawnewmember",
	"esquirrel3_fn_sq_arrayappend",
	"esquirrel3_fn_sq_arraypop",
	"esquirrel3_fn_sq_arrayresize",
	"esquirrel3_fn_sq_arrayreverse",
	"esquirrel3_fn_sq_arrayremove",
	"esquirrel3_fn_sq_arrayinsert",
	"esquirrel3_fn_sq_setdelegate",
	"esquirrel3_fn_sq_getdelegate",
	"esquirrel3_fn_sq_clone",
	"esquirrel3_fn_sq_setfreevariable",
	"esquirrel3_fn_sq_next",
	"esquirrel3_fn_sq_getweakrefval",
	"esquirrel3_fn_sq_clear",
	"esquirrel3_fn_sq_call",
	"esquirrel3_fn_sq_resume",
	"esquirrel3_fn_sq_getlocal",
	"esquirrel3_fn_sq_getcallee",
	"esquirrel3_fn_sq_getfreevariable",
	"esquirrel3_fn_sq_throwerror",
	"esquirrel3_fn_sq_throwobject",
	"esquirrel3_fn_sq_reseterror",
	"esquirrel3_fn_sq_getlasterror",
	"esquirrel3_fn_sq_getstackobj",
	"esquirrel3_fn_sq_pushobject",
	"esquirrel3_fn_sq_addref",
	"esquirrel3_fn_sq_release",
	"esquirrel3_fn_sq_getrefcount",
	"esquirrel3_fn_sq_resetobject",
	"esquirrel3_fn_sq_objtostring",
	"esquirrel3_fn_sq_objtobool",
	"esquirrel3_fn_sq_objtointeger",
	"esquirrel3_fn_sq_objtofloat",
	"esquirrel3_fn_sq_objtouserpointer",
	"esquirrel3_fn_sq_getobjtypetag",
	"esquirrel3_fn_sq_getvmrefcount",
	"esquirrel3_fn_sq_collectgarbage",
	"esquirrel3_fn_sq_resurrectunreachable",
	"esquirrel3_fn_sq_writeclosure",
	"esquirrel3_fn_sq_readclosure",
	"esquirrel3_fn_sq_stackinfos",
	"esquirrel3_fn_sq_setdebughook",
	"esquirrel3_fn_sq_setnativedebughook"
};

#endif


/************************************************************************/
/* �������Ͷ���
/************************************************************************/

#ifndef __E_STATIC_LIB


LIB_DATA_TYPE_ELEMENT s_dt_element_function_info[] =
{
	/*{ ��Ա���� ,�����Ա , �������� ,Ӣ������ ,��Ա���� ,��Ա״̬ ,Ĭ��ֵ}*/
	{ SDT_INT, NULL,_WT("ID"), _WT("funcid"), _WT("������Ψһ��ʶ��"), 0, 0 },
	{ SDT_TEXT, NULL,_WT("����"), _WT("name"), _WT("������"), 0, 0 },
	{ SDT_TEXT, NULL,_WT("Դ�ļ���"), _WT("source"), _WT("�������ڵ�Դ�ļ���"), 0, 0 },
	{ SDT_INT, NULL,_WT("�к�"), _WT("line"), NULL, 0, 0 }
};
LIB_DATA_TYPE_ELEMENT s_dt_element_stack_info[] =
{
	/*{ ��Ա���� ,�����Ա , �������� ,Ӣ������ ,��Ա���� ,��Ա״̬ ,Ĭ��ֵ}*/
	{ SDT_TEXT, NULL,_WT("������"), _WT("funcname"), _WT(""), 0, 0 },
	{ SDT_TEXT, NULL,_WT("Դ�ļ���"), _WT("source"), _WT("�������ڵ�Դ�ļ���"), 0, 0 },
	{ SDT_INT, NULL,_WT("�к�"), _WT("line"), NULL, 0, 0 }
};

static LIB_DATA_TYPE_INFO s_DataTypes[] =
{
	/* { ��������, Ӣ������, ��������, ��������, ��������, ����״̬, ͼ������, �¼�����, �¼�ָ��, ��������, ����ָ��, ����ָ��, Ԫ������, Ԫ��ָ�� } */
	{ _WT("��������Ϣ"), _WT("SQFunctionInfo"), _WT("�ű��ĺ�����Ϣ�����Ǳ��غ���"), 0, NULL, NULL, 0, 0, NULL, 0, NULL, NULL, sizeof(s_dt_element_function_info) / sizeof(s_dt_element_function_info[0]), s_dt_element_function_info },
	{ _WT("����ջ��Ϣ"), _WT("SQStackInfos"), _WT("����ջ��Ϣ"), 0, NULL, NULL, 0, 0, NULL, 0, NULL, NULL, sizeof(s_dt_element_stack_info) / sizeof(s_dt_element_stack_info[0]), s_dt_element_stack_info },
};
#endif

EXTERN_C INT WINAPI  esquirrel3_ProcessNotifyLib(INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
#ifndef __E_STATIC_LIB
	if (nMsg == NL_GET_CMD_FUNC_NAMES) // ������������ʵ�ֺ����ĵĺ�����������(char*[]), ֧�־�̬����Ķ�̬����봦��
		return (INT)g_CmdNames;
	else if (nMsg == NL_GET_NOTIFY_LIB_FUNC_NAME) // ���ش���ϵͳ֪ͨ�ĺ�������(PFN_NOTIFY_LIB��������), ֧�־�̬����Ķ�̬����봦��
		return (INT)"esquirrel3_ProcessNotifyLib";
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
		
		/*pfnNotify*/				esquirrel3_ProcessNotifyLib,
		
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