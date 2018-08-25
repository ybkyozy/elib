// esquirrel3.cpp : Defines the entry point for the DLL application.
//

#include "esquirrel3.h"

#include "elib_sdk/lib2.h"
#include "elib_sdk/lang.h"
#include "elib_sdk/fnshare.h"
#include "elib_sdk/fnshare.cpp"


std::map<INT, INT> g_sqPtrMap;

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

ARG_INFO s_arg_vm_and_idx[] =
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
	{ _WT("�ͷŻص�����"), _WT("����ֵ�������� �������� �ⲿָ�룬������ ��С��"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_setsharedreleasehook[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("�ͷŻص�����"), _WT("����ֵ�������� �������� �ⲿ����ָ�룬������ ��С��"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_setprintfunc[] =
{
	{ _WT("��������"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("��ӡ�ص�����"), _WT("����ֵ���� �������� �����������ı��� ����ı���"),0,0, SDT_INT, 0, NULL },
	{ _WT("����ص�����"), _WT("����ֵ���� �������� �����������ı��� ����ı���"),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
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
	{ _WT("��ȡ�ص�����"), _WT("����ֵ�������� �������� �û�ָ�룩"),0,0, SDT_INT, 0, NULL },
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
	{ _WT("�������ص�����"), _WT("����ֵ���ޣ������� �����������ı��� Ŀ�꣬�ı��� Դ�������� �кţ������� �кţ�"),0,0, SDT_INT, 0, NULL },
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
	{ _WT("���غ���"), _WT("����ֵ�������ͣ������� ����������\r\n ����1��ʾ�з���ֵ�����ʱ��Ҫ��ջ��ѹ�뷵��ֵ\r\n ����0��ʾû�з���ֵ"),0,0, SDT_INT, 0, NULL },
	{ _WT("���ɱ�����"), _WT("��� > 0 ����ջ�е���N��Ԫ�أ���Ϊ�հ������ɱ���"),0,0, SDT_INT, 0, AS_HAS_DEFAULT_VALUE },
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
		/*ccname*/	_WT("����_�����߳�"),
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
		/*explain*/	_WT("��ͣһ�������������"),
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
		/*explain*/	_WT("���ѱ���ͣ�������"),
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
		/*explain*/	_WT("��������ű�������ɹ�����0���������Ľű���Ϊ����ѹ�뵽ջ�У�ʧ�ܲ���ѹ���κ�����"),
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
		/*explain*/	_WT("��������ű����ڴ滺����������ɹ�����0���������Ľű���Ϊ����ѹ�뵽ջ�У�ʧ�ܲ���ѹ���κ�����"),
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
		/*ArgCount*/sizeof(s_arg_vm_and_idx) / sizeof(s_arg_vm_and_idx[0]),
		/*arg lp*/	s_arg_vm_and_idx,
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
		/*ArgCount*/sizeof(s_arg_vm_and_idx) / sizeof(s_arg_vm_and_idx[0]),
		/*arg lp*/	s_arg_vm_and_idx,
	},
	{
		/*ccname*/	_WT("����_ȡջ��"),
		/*egname*/	_WT("sq_gettop"),
		/*explain*/	_WT("��ջ�е�ָ��λ���Ƴ�1��Ԫ��"),
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
		/*explain*/	_WT("��Դջ��λ�õ�ֵѹ�뵽Ŀ��ջ��"),
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
	SQRELEASEHOOK hook = (SQRELEASEHOOK)zy_get_map_ptr(g_sqPtrMap, pArgInf[1].m_int, 2);
	sq_setvmreleasehook((HSQUIRRELVM)pArgInf[0].m_int, hook);
}

EXTERN_C void esquirrel3_fn_sq_getvmreleasehook(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SQRELEASEHOOK hook = sq_getvmreleasehook((HSQUIRRELVM)pArgInf[0].m_int);
	pRetData->m_int = zy_get_map_key(g_sqPtrMap, (INT)hook);
}

EXTERN_C void esquirrel3_fn_sq_setsharedreleasehook(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SQRELEASEHOOK hook = (SQRELEASEHOOK)zy_get_map_ptr(g_sqPtrMap, pArgInf[1].m_int, 2);
	sq_setsharedreleasehook((HSQUIRRELVM)pArgInf[0].m_int, hook);
}

EXTERN_C void esquirrel3_fn_sq_getsharedreleasehook(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SQRELEASEHOOK hook = sq_getsharedreleasehook((HSQUIRRELVM)pArgInf[0].m_int);
	pRetData->m_int = zy_get_map_key(g_sqPtrMap, (INT)hook);
}

void esquirrel3_printfunction (HSQUIRRELVM v, const SQChar * fmt, ...)
{
	ESQPRINTFUNCTION my_print_func = NULL;
	std::map<INT, INT>::iterator iter = g_sqPtrMap.find(EPRINT_CALLBACK + (INT)v);
	if (iter == g_sqPtrMap.end())
	{
		return;
	}
	my_print_func = (ESQPRINTFUNCTION)iter->second;
	UINT buflenth = 1024;
	SQChar* buff = new SQChar[buflenth];
	UINT index = 0;
	va_list args;
	va_start(args, fmt);
	index = wvsprintf(buff, fmt, args);
	if (index >= buflenth)
	{
		delete[] buff;
		buflenth = index + 1;
		buff = new SQChar[buflenth];
		index = wvsprintf(buff, fmt, args);
	}
	buff[index] = '\0';
	va_end(args);
	my_print_func(v, buff);
	delete[] buff;
}
void esquirrel3_errorfunction(HSQUIRRELVM v, const SQChar * fmt, ...)
{
	ESQPRINTFUNCTION my_print_func = NULL;
	std::map<INT, INT>::iterator iter = g_sqPtrMap.find(EERROR_CALLBACK + (INT)v);
	if (iter == g_sqPtrMap.end())
	{
		return;
	}
	my_print_func = (ESQPRINTFUNCTION)iter->second;
	UINT buflenth = 1024;
	SQChar* buff = new SQChar[buflenth];
	UINT index = 0;
	va_list args;
	va_start(args, fmt);
	index = wvsprintf(buff, fmt, args);
	if (index >= buflenth)
	{
		delete[] buff;
		buflenth = index + 1;
		buff = new SQChar[buflenth];
		index = wvsprintf(buff, fmt, args);
	}
	buff[index] = '\0';
	va_end(args);
	my_print_func(v, buff);
	delete[] buff;
}


EXTERN_C void esquirrel3_fn_sq_setprintfunc(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	g_sqPtrMap[pArgInf[0].m_int + EPRINT_CALLBACK] = pArgInf[1].m_int;
	g_sqPtrMap[pArgInf[0].m_int + EERROR_CALLBACK] = pArgInf[2].m_int;
	SQPRINTFUNCTION printHook = NULL;
	if (pArgInf[1].m_int)
	{
		printHook = esquirrel3_printfunction;
	}
	SQPRINTFUNCTION errorHook = NULL;
	if (pArgInf[2].m_int)
	{
		errorHook = esquirrel3_errorfunction;
	}
	sq_setprintfunc((HSQUIRRELVM)pArgInf[0].m_int, printHook, errorHook);
}

EXTERN_C void esquirrel3_fn_sq_getprintfunc(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = g_sqPtrMap[1 + pArgInf[0].m_int];
}

EXTERN_C void esquirrel3_fn_sq_geterrorfunc(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = g_sqPtrMap[2 + pArgInf[0].m_int];
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
	SQLEXREADFUNC func = (SQLEXREADFUNC)zy_get_map_ptr(g_sqPtrMap, pArgInf[1].m_int, 1);

	pRetData->m_int = sq_compile((HSQUIRRELVM)pArgInf[0].m_int, func, (LPVOID)pArgInf[2].m_int, pArgInf[3].m_pText, pArgInf[4].m_bool);
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
	/*MessageBoxA(NULL, zy_vsprint("%d %s %d %s %d", pArgInf[0].m_int, s, len, pArgInf[2].m_pText, pArgInf[3].m_bool), NULL, 0);*/

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

void esquirrel3_compilererrorfunction(HSQUIRRELVM v, const SQChar* desc, const SQChar* source, SQInteger line, SQInteger column)
{
	ESQCOMPILERERROR my_compilererror_func = NULL;
	std::map<INT, INT>::iterator iter = g_sqPtrMap.find(ECMPILERERROR_CALLBACK + (INT)v);
	if (iter == g_sqPtrMap.end())
	{
		return;
	}
	my_compilererror_func = (ESQCOMPILERERROR)iter->second;
	my_compilererror_func(v, desc, source, line, column);
}

EXTERN_C void esquirrel3_fn_sq_setcompilererrorhandler(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	g_sqPtrMap[pArgInf[0].m_int + ECMPILERERROR_CALLBACK] = pArgInf[1].m_int;

	SQCOMPILERERROR compError = NULL;
	if (pArgInf[1].m_int)
	{
		compError = esquirrel3_compilererrorfunction;
	}
	sq_setcompilererrorhandler((HSQUIRRELVM)pArgInf[0].m_int, compError);
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
	SQFUNCTION func = (SQFUNCTION)zy_get_map_ptr(g_sqPtrMap, pArgInf[1].m_int, 1);

	sq_newclosure(vm, func, pArgInf[2].m_int);
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
	esquirrel3_fn_sq_move,
	esquirrel3_fn_sq_newuserdata,
	esquirrel3_fn_sq_newtable,
	esquirrel3_fn_sq_newtableex,
	esquirrel3_fn_sq_newarray,
	esquirrel3_fn_sq_newclosure
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
	"esquirrel3_fn_sq_move",
	"esquirrel3_fn_sq_newuserdata",
	"esquirrel3_fn_sq_newtable",
	"esquirrel3_fn_sq_newtableex",
	"esquirrel3_fn_sq_newarray",
	"esquirrel3_fn_sq_newclosure"
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