// esquirrel3.cpp : Defines the entry point for the DLL application.
//

#include "esquirrel3.h"

#include "elib_sdk/lib2.h"
#include "elib_sdk/lang.h"
#include "elib_sdk/fnshare.h"
#include "elib_sdk/fnshare.cpp"
#include "squirrel.h"


std::map<INT, INT> g_sqPtrMap;

/************************************************************************/
/* 常量定义
/************************************************************************/
#ifndef __E_STATIC_LIB
LIB_CONST_INFO s_ConstInfo[] =
{
	/* { 中文名称, 英文名称, 常量说明, 常量等级(LVL_), 参数类型(CT_), 文本内容, 数值内容 }   只有两种数据类型*/
	{ _WT("松鼠类型_空"), _WT("OT_NULL"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_NULL },
	{ _WT("松鼠类型_整数"), _WT("OT_INTEGER"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_INTEGER },
	{ _WT("松鼠类型_浮点数"), _WT("OT_FLOAT"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_FLOAT },
	{ _WT("松鼠类型_逻辑"), _WT("OT_BOOL"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_BOOL },
	{ _WT("松鼠类型_文本"), _WT("OT_STRING"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_STRING },
	{ _WT("松鼠类型_表"), _WT("OT_TABLE"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_TABLE },
	{ _WT("松鼠类型_数组"), _WT("OT_ARRAY"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_ARRAY },
	{ _WT("松鼠类型_用户数据"), _WT("OT_USERDATA"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_USERDATA },
	{ _WT("松鼠类型_闭包"), _WT("OT_CLOSURE"), _WT("脚本函数"), LVL_SIMPLE, CT_NUM, NULL, OT_CLOSURE },
	{ _WT("松鼠类型_本地闭包"), _WT("OT_NATIVECLOSURE"), _WT("本地函数"), LVL_SIMPLE, CT_NUM, NULL, OT_NATIVECLOSURE },
	{ _WT("松鼠类型_生成器"), _WT("OT_GENERATOR"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_GENERATOR },
	{ _WT("松鼠类型_用户指针"), _WT("OT_USERPOINTER"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_USERPOINTER },
	{ _WT("松鼠类型_线程"), _WT("OT_THREAD"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_THREAD },
	{ _WT("松鼠类型_类"), _WT("OT_CLASS"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_CLASS },
	{ _WT("松鼠类型_实例"), _WT("OT_INSTANCE"), _WT("类的实例"), LVL_SIMPLE, CT_NUM, NULL, OT_INSTANCE },
	{ _WT("松鼠类型_弱引用"), _WT("OT_WEAKREF"), NULL, LVL_SIMPLE, CT_NUM, NULL, OT_WEAKREF },

	{ _WT("松鼠状态_空闲"), _WT("SQ_VMSTATE_IDLE"), NULL, LVL_SIMPLE, CT_NUM, NULL, SQ_VMSTATE_IDLE },
	{ _WT("松鼠状态_正在运行"), _WT("SQ_VMSTATE_RUNNING"), NULL, LVL_SIMPLE, CT_NUM, NULL, SQ_VMSTATE_RUNNING },
	{ _WT("松鼠状态_已暂停"), _WT("SQ_VMSTATE_SUSPENDED"), NULL, LVL_SIMPLE, CT_NUM, NULL, SQ_VMSTATE_SUSPENDED },
};

#endif


#ifndef __E_STATIC_LIB

// 参数 
ARG_INFO s_arg_open[] =
{
	/* { 参数名称, 参数描述, 图像索引, 图像数量, 参数类型(参见SDT_), 默认数值, 参数类别(参见AS_) } */
	{ _WT("栈大小"), _WT("相当于对象数"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_newthread[] =
{
	{ _WT("友元虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈大小"), _WT("相当于对象数"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_onlyvm[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_setforeignptr[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("用户指针"), _WT("用户自定义指针"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_setvmreleasehook[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("释放回调函数"), _WT("返回值：整数型 （整数型 外部指针，整数型 大小）"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_setsharedreleasehook[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("释放回调函数"), _WT("返回值：整数型 （整数型 外部共享指针，整数型 大小）"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_setprintfunc[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("打印回调函数"), _WT("返回值：无 （整数型 虚拟机句柄，文本型 输出文本）"),0,0, SDT_INT, 0, NULL },
	{ _WT("错误回调函数"), _WT("返回值：无 （整数型 虚拟机句柄，文本型 输出文本）"),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_wakeupvm[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("暂停返回值"), _WT("如果为真，则从栈中弹出一个作为之前暂停的返回值"),0,0, SDT_BOOL, 0, AS_HAS_DEFAULT_VALUE },
	{ _WT("返回值"), _WT("如果为真，则压入执行暂停函数或主函数的返回值"),0,0, SDT_BOOL, 0, AS_HAS_DEFAULT_VALUE },
	{ _WT("错误处理"), _WT("如果为真，在发生运行时错误时调用错误处理程序"),0,0, SDT_BOOL, 1, AS_HAS_DEFAULT_VALUE },
	{ _WT("抛出异常"), _WT("如果为真，则虚拟机将在恢复后立即发出异常"),0,0, SDT_BOOL, 0, AS_HAS_DEFAULT_VALUE },
};

ARG_INFO s_arg_compile[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("读取回调函数"), _WT("返回值：整数型 （整数型 用户指针）"),0,0, SDT_INT, 0, NULL },
	{ _WT("用户指针"), _WT("传递给 读取回调函数 的参数"),0,0, SDT_INT, 0, NULL },
	{ _WT("源名称"), _WT("程序的符号名称（仅用于更有意义的运行时错误）"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("错误处理"), _WT("如果为真，则在发生错误时将调用编译器错误处理程序"),0,0, SDT_BOOL, 1, AS_HAS_DEFAULT_VALUE },
};

ARG_INFO s_arg_compilebuffer[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("松鼠脚本"), _WT("只能是文本型或字节集型"),0,0, _SDT_ALL, 0, NULL },
	{ _WT("源名称"), _WT("程序的符号名称（仅用于更有意义的运行时错误）"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("错误处理"), _WT("如果为真，则在发生错误时将调用编译器错误处理程序"),0,0, SDT_BOOL, 1, AS_HAS_DEFAULT_VALUE },
};

ARG_INFO s_arg_enabledebuginfo[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("启用"), _WT("如果为真，则生成调试信息"),0,0, SDT_BOOL, 0, NULL },
};

ARG_INFO s_arg_notifyallexceptions[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("启用"), _WT("如果为真，则通知已处理处理异常的错误回调"),0,0, SDT_BOOL, 0, NULL },
};

ARG_INFO s_arg_setcompilererrorhandler[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("编译错误回调函数"), _WT("返回值：无（整数型 虚拟机句柄，文本型 目标，文本型 源，整数型 行号，整数型 列号）"),0,0, SDT_INT, 0, NULL },
};

// 命令信息
static CMD_INFO s_CmdInfo[] =
{
	/* { 中文名称, 英文名称, 对象描述, 所属类别(-1是数据类型的方法), 命令状态(CT_), 返回类型(SDT_), 此值保留, 对象等级(LVL_), 图像索引, 图像数量, 参数个数, 参数信息 } */

	//////////////////////////////////////////////////////////////////////////虚拟机
	{
		/*ccname*/	_WT("松鼠_打开"),
		/*egname*/	_WT("sq_open"),
		/*explain*/ _WT("创建一个新的包含执行栈的虚拟机，并返回虚拟机句柄"),
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
		/*ccname*/	_WT("松鼠_创建线程"),
		/*egname*/	_WT("sq_newthread"),
		/*explain*/	_WT("创建一个新的线程，并压入到栈中"),
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
		/*ccname*/	_WT("松鼠_置错误处理程序"),
		/*egname*/	_WT("sq_seterrorhandler"),
		/*explain*/	_WT("从栈弹出一个闭包或本机闭包，并将其设置为运行时错误处理程序"),
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
		/*ccname*/	_WT("松鼠_关闭"),
		/*egname*/	_WT("sq_close"),
		/*explain*/	_WT("释放打开的虚拟机和其有关的所有友元虚拟机"),
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
		/*ccname*/	_WT("松鼠_置外部指针"),
		/*egname*/	_WT("sq_setforeignptr"),
		/*explain*/	_WT("设置一个与虚拟机关联的外部指针"),
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
		/*ccname*/	_WT("松鼠_取外部指针"),
		/*egname*/	_WT("sq_getforeignptr"),
		/*explain*/	_WT("获取一个与虚拟机关联的外部指针"),
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
		/*ccname*/	_WT("松鼠_置共享外部指针"),
		/*egname*/	_WT("sq_setsharedforeignptr"),
		/*explain*/	_WT("设置一个与虚拟机关联的外部共享指针，这个外部指针是可以与线程的虚拟机共享的"),
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
		/*ccname*/	_WT("松鼠_取共享外部指针"),
		/*egname*/	_WT("sq_getsharedforeignptr"),
		/*explain*/	_WT("获取一个与虚拟机关联的外部共享指针，这个外部指针是可以与线程的虚拟机共享的"),
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
		/*ccname*/	_WT("松鼠_置虚拟机释放钩子"),
		/*egname*/	_WT("sq_setvmreleasehook"),
		/*explain*/	_WT("当一个虚拟机被释放时，调用这个钩子回调函数，SQUserPointer 是 松鼠_置外部指针() 设置的指针"),
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
		/*ccname*/	_WT("松鼠_取虚拟机释放钩子"),
		/*egname*/	_WT("sq_getvmreleasehook"),
		/*explain*/	_WT("获取虚拟机的释放钩子回调函数"),
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
		/*ccname*/	_WT("松鼠_置共享释放钩子"),
		/*egname*/	_WT("sq_setsharedreleasehook"),
		/*explain*/	_WT("设置一个虚拟机的共享释放回调函数，调用这个钩子回调函数，用户指针 是 松鼠_置外部共享指针() 设置的指针"),
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
		/*ccname*/	_WT("松鼠_取共享释放钩子"),
		/*egname*/	_WT("sq_getsharedreleasehook"),
		/*explain*/	_WT("获取虚拟机的共享释放钩子回调函数，打开 和 新建线程 之间的虚拟机共享这个钩子"),
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
		/*ccname*/	_WT("松鼠_置打印回调函数"),
		/*egname*/	_WT("sq_setprintfunc"),
		/*explain*/	_WT("当然脚本调用 print() 时，设置自己的打印输出回调函数"),
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
		/*ccname*/	_WT("松鼠_取打印回调函数"),
		/*egname*/	_WT("sq_getprintfunc"),
		/*explain*/	_WT("获取虚拟机打印回调函数"),
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
		/*ccname*/	_WT("松鼠_取错误回调函数"),
		/*egname*/	_WT("sq_geterrorfunc"),
		/*explain*/	_WT("获取虚拟机错误回调函数"),
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
		/*ccname*/	_WT("松鼠_暂停虚拟机"),
		/*egname*/	_WT("sq_suspendvm"),
		/*explain*/	_WT("暂停一个虚拟机的运行"),
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
		/*ccname*/	_WT("松鼠_唤醒虚拟机"),
		/*egname*/	_WT("sq_wakeupvm"),
		/*explain*/	_WT("唤醒被暂停的虚拟机"),
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
		/*ccname*/	_WT("松鼠_取虚拟机状态"),
		/*egname*/	_WT("sq_getvmstate"),
		/*explain*/	_WT("获取指定虚拟机状态，返回\"松鼠状态_\"开头常量"),
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
		/*ccname*/	_WT("松鼠_取版本"),
		/*egname*/	_WT("sq_getversion"),
		/*explain*/	_WT("返回版本号"),
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
	//////////////////////////////////////////////////////////////////////////编译
	{
		/*ccname*/	_WT("松鼠_编译"),
		/*egname*/	_WT("sq_compile"),
		/*explain*/	_WT("编制松鼠脚本；如果成功返回0，将编译后的脚本作为函数压入到栈中，失败不会压入任何内容"),
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
		/*ccname*/	_WT("松鼠_编译缓冲区"),
		/*egname*/	_WT("sq_compilebuffer"),
		/*explain*/	_WT("编制松鼠脚本自内存缓冲区；如果成功返回0，将编译后的脚本作为函数压入到栈中，失败不会压入任何内容"),
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
		/*ccname*/	_WT("松鼠_启用调试信息"),
		/*egname*/	_WT("sq_enabledebuginfo"),
		/*explain*/	_WT("在编译时 启用/禁用 生成调试行信息，该函数也会影响所有线程"),
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
		/*ccname*/	_WT("松鼠_启用通知所有异常"),
		/*egname*/	_WT("sq_notifyallexceptions"),
		/*explain*/	_WT("启用/禁用 通知已处理异常的错误回调。默认情况下，仅当未处理异常（调用栈中不存在try / catch）时，VM才会调用错误回调。 如果启用通知所有异常，则即使在try / catch块之间，VM也会对任何异常调用错误回调。此功能对于实现调试器很有用。"),
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
		/*ccname*/	_WT("松鼠_置编译错误处理函数"),
		/*egname*/	_WT("sq_setcompilererrorhandler"),
		/*explain*/	_WT("设置编译器错误处理函数，编译器错误处理函数在友元VM之间共享"),
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
};
#endif


//////////////////////////////////////////////////////////////////////////虚拟机
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
	std::map<INT, INT>::iterator iter = g_sqPtrMap.find(1 + (INT)v);
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
	std::map<INT, INT>::iterator iter = g_sqPtrMap.find(2 + (INT)v);
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
	g_sqPtrMap[pArgInf[0].m_int + 1] = pArgInf[1].m_int;
	g_sqPtrMap[pArgInf[0].m_int + 2] = pArgInf[2].m_int;
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

//////////////////////////////////////////////////////////////////////////编译
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

EXTERN_C void esquirrel3_fn_sq_setcompilererrorhandler(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SQCOMPILERERROR func = (SQCOMPILERERROR)zy_get_map_ptr(g_sqPtrMap, pArgInf[1].m_int, 5);

	sq_setcompilererrorhandler((HSQUIRRELVM)pArgInf[0].m_int, func);
}

#ifndef __E_STATIC_LIB
PFN_EXECUTE_CMD s_RunFunc[] =	// 索引应与s_CmdInfo中的命令定义顺序对应
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
};
#endif

EXTERN_C INT WINAPI  esquirrel3_ProcessNotifyLib(INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
#ifndef __E_STATIC_LIB
	if (nMsg == NL_GET_CMD_FUNC_NAMES) // 返回所有命令实现函数的的函数名称数组(char*[]), 支持静态编译的动态库必须处理
		return (INT)g_CmdNames;
	else if (nMsg == NL_GET_NOTIFY_LIB_FUNC_NAME) // 返回处理系统通知的函数名称(PFN_NOTIFY_LIB函数名称), 支持静态编译的动态库必须处理
		return (INT)"esquirrel3_ProcessNotifyLib";
	else if (nMsg == NL_GET_DEPENDENT_LIBS) return NULL;
	// 返回静态库所依赖的其它静态库文件名列表(格式为\0分隔的文本,结尾两个\0), 支持静态编译的动态库必须处理
	// kernel32.lib user32.lib gdi32.lib 等常用的系统库不需要放在此列表中
	// 返回NULL或NR_ERR表示不指定依赖文件  
#endif
	return ProcessNotifyLib(nMsg, dwParam1, dwParam2);
};

#ifndef __E_STATIC_LIB
static LIB_INFO s_LibInfo =
{
		LIB_FORMAT_VER,				//库格式号
		_T(LIB_GUID_STR),			//GUID
		LIB_MajorVersion,			//本库的主版本号
		LIB_MinorVersion,			//本库的次版本号
		LIB_BuildNumber,			//构建版本号
		LIB_SysMajorVer,			//所需要的易语言系统的主版本号
		LIB_SysMinorVer,			//所需要的易语言系统的次版本号
		LIB_KrnlLibMajorVer,		//所需要的系统核心支持库的主版本号
		LIB_KrnlLibMinorVer,		//所需要的系统核心支持库的次版本号
		_T(LIB_NAME_STR),			//库名
		__GBK_LANG_VER,				//库所支持的语言
		_WT(LIB_DESCRIPTION_STR),	//库详细解释
		
#ifndef __COMPILE_FNR			//状态
		/*dwState*/				_LIB_OS(__OS_WIN),
#else
		/*dwState*/				LBS_NO_EDIT_INFO | _LIB_OS(__OS_WIN) | LBS_LIB_INFO2,
#endif	
		
		_WT(LIB_Author),			//作者
		_WT(LIB_ZipCode),			//邮政编码
		NULL,				//通信地址
		NULL,				//电话号码
		NULL,				//传真
		NULL,				//邮箱地址
		NULL,				//主页
		NULL,				//其他信息
		
		//自定义数据类型
		0,
		NULL,
		//类别说明
#ifndef __COMPILE_FNR
		/*CategoryCount*/   LIB_TYPE_COUNT,			// 加了类别需加此值。
		/*category*/       	_WT(LIB_TYPE_STR),			// 类别说明表每项为一字符串,前四位数字表示图象索引号(从1开始,0无).
		/*CmdCount*/        sizeof(s_CmdInfo) / sizeof(s_CmdInfo[0]),
		/*BeginCmd*/        s_CmdInfo,
#else
		// fnr版本不需要以下信息
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
		// fnr版本不需要以下信息
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