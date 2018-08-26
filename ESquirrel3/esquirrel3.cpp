// esquirrel3.cpp : Defines the entry point for the DLL application.
//

#include "esquirrel3.h"

#include "elib_sdk/lib2.h"
#include "elib_sdk/lang.h"
#include "elib_sdk/fnshare.h"
#include "elib_sdk/fnshare.cpp"


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

ARG_INFO s_arg_vm_idx[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
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

ARG_INFO s_arg_pop[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("弹出数量"), _WT("要弹出栈的数量"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_settop[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("新栈顶"), _WT("可用于恢复之前的栈顶索引"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_reservestack[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("新栈大小"), _WT("所需的栈大小"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_move[] =
{
	{ _WT("目标虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("源虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("源栈索引"), _WT("源栈中的索引"),0,0, SDT_INT, 0, NULL }
};
ARG_INFO s_arg_newuserdata[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("大小"), _WT("以字节为单位的大小"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_newtableex[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("表初始数量"), _WT("预分配的键/值对的数量"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_newarray[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("数组大小"), _WT("要创建的数组大小"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_newclosure[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("本地函数"), _WT("返回值：整数型（整数型 虚拟机句柄）\r\n 返回1表示有返回值，这个时候要在栈中压入返回值\r\n 返回0表示没有返回值"),0,0, SDT_INT, 0, NULL },
	{ _WT("自由变量数"), _WT("如果 > 0 则会从栈中弹出N个元素，作为闭包的自由变量"),0,0, SDT_INT, 0, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_setparamscheck[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("参数数量"), _WT(" =0 表示不检查；\r\n >0 表示参数数量(包含隐藏的this参数)\r\n <0 表示参数至少是多少个，比如-3代表至少3个参数"),0,0, SDT_INT, 0, NULL },
	{ _WT("类型掩码"), _WT("'o'null，'i'integer，'f'flora，'n'integer or float，'s'string，'t'table，'a'array，'u'userdata，' c'closure和nativeclosure，'g'generator，'p'userpointer，'v'thread，'x'instance(class instance)，'y'class，'b'bool, '.' 任意类型。可以用'|'来表示或操作。\r\n比如“tsn | p”表示的类型是（table，string，number 或 userpointer）"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY }
};
ARG_INFO s_arg_pushstring[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("文本"), _WT("要压入的文本"),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_pushfloat[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("浮点数"), _WT("要压入的浮点数"),0,0, SDT_FLOAT, 0, NULL },
};
ARG_INFO s_arg_pushintegert[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("整数"), _WT("要压入的整数"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_pushbool[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("逻辑"), _WT("要压入的逻辑值"),0,0, SDT_BOOL, 0, NULL },
};
ARG_INFO s_arg_pushuserpointer[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("用户指针"), _WT("要压入的用户指针"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_pushthread[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("线程"), _WT("要压入的线程（HSQUIRRELVM）"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_getstring[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("返回文本"), _WT("返回的文本"),0,0, SDT_TEXT, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_getinteger[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("返回整数"), _WT("返回的整数"),0,0, SDT_INT, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_getfloat[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("返回浮点数"), _WT("返回的浮点数"),0,0, SDT_FLOAT, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_getbool[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("返回逻辑"), _WT("返回的逻辑值"),0,0, SDT_BOOL, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_getthread[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("返回线程"), _WT("返回的线程(HSQUIRRELVM)"),0,0, SDT_INT, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_getuserpointer[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("返回用户指针"), _WT("返回的用户指针"),0,0, SDT_INT, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_getuserdata[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("返回用户指针"), _WT("返回的用户指针"),0,0, SDT_INT, 0, AS_RECEIVE_VAR },
	{ _WT("返回类型标签"), _WT("返回的类型标签,可参阅 松鼠_置类型标签()"),0,0, SDT_INT, 0, AS_RECEIVE_VAR | AS_DEFAULT_VALUE_IS_EMPTY},
};
ARG_INFO s_arg_settypetag[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("类型标签"), _WT("一个任意的整数"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_gettypetag[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("返回类型标签"), _WT("返回的类型标签"),0,0, SDT_INT, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_setreleasehook[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("释放钩子"), _WT("返回值：整数型（整数型 用户指针，整数型 大小）"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_getscratchpad[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("请求大小"), _WT("向暂存器申请的最小内存大小"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_getfunctioninfo[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("等级"), _WT("调用栈等级，0表示当前函数，1表示调用者，依次类推"),0,0, SDT_INT, 0, NULL },
	{ _WT("返回函数信息"), _WT("返回的函数信息数据类型"),0,0, DTP_SQFUNCTION_INFO, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_getclosureinfo[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("返回参数数"), _WT("返回的闭包参数数量"),0,0, SDT_INT, 0, AS_RECEIVE_VAR },
	{ _WT("返回自由变量数"), _WT("返回的闭包自由变量数量"),0,0, SDT_INT, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_setnativeclosurename[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("名称"), _WT("本地闭包名称"),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_setinstanceup[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("用户指针"), _WT("任意的用户指针"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_getinstanceup[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("返回用户指针"), _WT("返回设置的用户指针"),0,0, SDT_INT, 0, AS_RECEIVE_VAR },
	{ _WT("类型标签"), _WT("要检查的类型标签（typetag），如果此值为0，则忽略"),0,0, SDT_INT, 0, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_setclassudsize[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("用户数据大小"), _WT("以字节为单位"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_newclass[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("是否有基类"), _WT("如果参数为真，则函数需要在栈顶部的基类"),0,0, SDT_BOOL, 0, NULL },
};
ARG_INFO s_arg_getdefaultdelegate[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("对象类型"), _WT("“松鼠类型_”开头常量"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_getmemberhandle[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("返回成员句柄"), _WT("返回的成员句柄"),0,0, SDT_INT64, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_getbyhandle[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("成员句柄"), _WT("HSQMEMBERHANDLE"),0,0, SDT_INT64, 0, AS_RECEIVE_VAR },
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
		/*explain*/	_WT("暂停一个虚拟机的运行，成功返回>=0"),
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
		/*explain*/	_WT("唤醒被暂停的虚拟机，成功返回>=0"),
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
		/*explain*/	_WT("编制松鼠脚本；如果成功返回>=0，将编译后的脚本作为函数压入到栈中，失败不会压入任何内容"),
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
		/*explain*/	_WT("编制松鼠脚本自内存缓冲区；如果成功返回>=0，将编译后的脚本作为函数压入到栈中，失败不会压入任何内容"),
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
	//////////////////////////////////////////////////////////////////////////栈操作
	{
		/*ccname*/	_WT("松鼠_压入"),
		/*egname*/	_WT("sq_push"),
		/*explain*/	_WT("将参数\"栈索引\"中的值压入栈"),
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
		/*ccname*/	_WT("松鼠_弹出"),
		/*egname*/	_WT("sq_pop"),
		/*explain*/	_WT("从栈中弹出指定数量的元素"),
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
		/*ccname*/	_WT("松鼠_弹出栈顶"),
		/*egname*/	_WT("sq_poptop"),
		/*explain*/	_WT("从栈中弹出1个元素"),
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
		/*ccname*/	_WT("松鼠_移除"),
		/*egname*/	_WT("sq_remove"),
		/*explain*/	_WT("从栈中的指定位置移除1个元素"),
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
		/*ccname*/	_WT("松鼠_取栈顶"),
		/*egname*/	_WT("sq_gettop"),
		/*explain*/	_WT("从栈中的指定位置移除1个元素"),
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
		/*ccname*/	_WT("松鼠_置栈顶"),
		/*egname*/	_WT("sq_settop"),
		/*explain*/	_WT("设置新的栈顶索引，如果比旧的栈顶大，则压入空值"),
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
		/*ccname*/	_WT("松鼠_重置栈大小"),
		/*egname*/	_WT("sq_reservestack"),
		/*explain*/	_WT("重置栈大小，成功返回>=0，确保剩余的栈空间至少是指定的大小。如果栈较小，它将自动增长。 如果当前正在运行 元方法(memtamethod)，函数将失败并且栈将不会调整大小，则此情况必须被视为“栈溢出”"),
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
		/*ccname*/	_WT("松鼠_比较"),
		/*egname*/	_WT("sq_cmp"),
		/*explain*/	_WT("比较栈中的两个对象。\r\n 返回 > 0 表示 对象1 > 对象2；\r\n 返回 = 0 表示 相等；\r\n 返回 < 0 表示 对象1 < 对象2 \r\n"),
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
		/*ccname*/	_WT("松鼠_移动"),
		/*egname*/	_WT("sq_move"),
		/*explain*/	_WT("将源栈的位置的值压入到目标栈中"),
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
	//////////////////////////////////////////////////////////////////////////对象创建和处理
	{
		/*ccname*/	_WT("松鼠_新建用户数据"),
		/*egname*/	_WT("sq_newuserdata"),
		/*explain*/	_WT("创建一个新的userdata并将其压入栈，返回用户数据指针"),
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
		/*ccname*/	_WT("松鼠_新建表"),
		/*egname*/	_WT("sq_newtable"),
		/*explain*/	_WT("创建一个新表并将其压入栈"),
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
		/*ccname*/	_WT("松鼠_新建表Ex"),
		/*egname*/	_WT("sq_newtableex"),
		/*explain*/	_WT("创建一个新表并将其压入栈，此函数允许指定表的初始容量，以便在创建时知道所需的插槽数，防止不必要的重置散列。"),
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
		/*ccname*/	_WT("松鼠_新建数组"),
		/*egname*/	_WT("sq_newarray"),
		/*explain*/	_WT("创建一个新数组并将其压入栈"),
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
		/*ccname*/	_WT("松鼠_新建闭包"),
		/*egname*/	_WT("sq_newclosure"),
		/*explain*/	_WT("创建一个本地闭包(函数)并将其压入栈"),
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
		/*ccname*/	_WT("松鼠_置参数检查"),
		/*egname*/	_WT("sq_setparamscheck"),
		/*explain*/	_WT("设置栈顶位置的本地闭包的参数验证方案。允许验证函数接受的参数数量以及可选的类型。如果函数调用不符合设置的参数模式，则抛出异常。返回值>=0表示成功"),
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
		/*ccname*/	_WT("松鼠_绑定环境"),
		/*egname*/	_WT("sq_bindenv"),
		/*explain*/	_WT("从栈中弹出一个对象（必须是表，实例或类）克隆\'栈索引\"处的闭包，并将弹出的对象设置为克隆闭包的环境。然后将新的克隆闭包压入栈顶部。返回值>=0表示成功"),
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
		/*ccname*/	_WT("松鼠_置闭包根"),
		/*egname*/	_WT("sq_setclosureroot"),
		/*explain*/	_WT("从栈中弹出一个表，并将其设置为\"栈索引\"处的闭包的根，返回值>=0表示成功"),
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
		/*ccname*/	_WT("松鼠_取闭包根"),
		/*egname*/	_WT("sq_getclosureroot"),
		/*explain*/	_WT("将\"栈索引\"处指定的闭包的根压入栈，返回值>=0表示成功"),
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
		/*ccname*/	_WT("松鼠_压入文本"),
		/*egname*/	_WT("sq_pushstring"),
		/*explain*/	_WT("压入文本值"),
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
		/*ccname*/	_WT("松鼠_压入浮点数"),
		/*egname*/	_WT("sq_pushfloat"),
		/*explain*/	_WT("压入浮点数"),
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
		/*ccname*/	_WT("松鼠_压入整数"),
		/*egname*/	_WT("sq_pushinteger"),
		/*explain*/	_WT("压入整数"),
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
		/*ccname*/	_WT("松鼠_压入逻辑"),
		/*egname*/	_WT("sq_pushbool"),
		/*explain*/	_WT("压入逻辑值"),
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
		/*ccname*/	_WT("松鼠_压入用户指针"),
		/*egname*/	_WT("sq_pushuserpointer"),
		/*explain*/	_WT("压入用户指针"),
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
		/*ccname*/	_WT("松鼠_压入空"),
		/*egname*/	_WT("sq_pushnull"),
		/*explain*/	_WT("压入null"),
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
		/*ccname*/	_WT("松鼠_压入线程"),
		/*egname*/	_WT("sq_pushthread"),
		/*explain*/	_WT("压入线程"),
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
		/*ccname*/	_WT("松鼠_取类型"),
		/*egname*/	_WT("sq_gettype"),
		/*explain*/	_WT("返回\"栈索引\"位置处对象的类型，\"松鼠类型_\"开头常量"),
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
		/*ccname*/	_WT("松鼠_类型"),
		/*egname*/	_WT("sq_typeof"),
		/*explain*/	_WT("压入\"栈索引\"位置处对象的类型名称，它还为实现它的表和类实例调用_typeof元方法; 在这种情况下，压入的对象可能不是字符串（取决于_typeof实现）。返回值>=0表示成功"),
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
		/*ccname*/	_WT("松鼠_取大小"),
		/*egname*/	_WT("sq_getsize"),
		/*explain*/	_WT("返回\"栈索引\"位置处对象的大小"),
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
		/*ccname*/	_WT("松鼠_取哈希"),
		/*egname*/	_WT("sq_gethash"),
		/*explain*/	_WT("返回\"栈索引\"位置处对象的哈希值"),
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
		/*ccname*/	_WT("松鼠_取基类"),
		/*egname*/	_WT("sq_getbase"),
		/*explain*/	_WT("压入\"栈索引\"位置处class的基类，返回值>=0表示成功"),
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
		/*ccname*/	_WT("松鼠_是否类实例"),
		/*egname*/	_WT("sq_instanceof"),
		/*explain*/	_WT("返回真，表示栈位置-2处的对象是栈位置-1处类的实例"),
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
		/*ccname*/	_WT("松鼠_到文本"),
		/*egname*/	_WT("sq_tostring"),
		/*explain*/	_WT("将\"栈索引\"位置处的对象转换为文本，并把结果文本压入栈中，返回值>=0表示成功"),
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
		/*ccname*/	_WT("松鼠_到逻辑"),
		/*egname*/	_WT("sq_tobool"),
		/*explain*/	_WT("将\"栈索引\"位置处的对象转换为逻辑型，并返回。如果对象不是bool，则函数根据松鼠脚本的规则将值转换为逻辑型。 例如，数字1为真，数字0假。"),
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
		/*ccname*/	_WT("松鼠_取文本"),
		/*egname*/	_WT("sq_getstring"),
		/*explain*/	_WT("获取\"栈索引\"位置处对象的文本，成功返回>=0"),
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
		/*ccname*/	_WT("松鼠_取整数"),
		/*egname*/	_WT("sq_getinteger"),
		/*explain*/	_WT("获取\"栈索引\"位置处对象的整数值，成功返回>=0"),
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
		/*ccname*/	_WT("松鼠_取浮点数"),
		/*egname*/	_WT("sq_getfloat"),
		/*explain*/	_WT("获取\"栈索引\"位置处对象的浮点数值，成功返回>=0"),
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
		/*ccname*/	_WT("松鼠_取逻辑"),
		/*egname*/	_WT("sq_getbool"),
		/*explain*/	_WT("获取\"栈索引\"位置处对象的逻辑值，成功返回>=0"),
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
		/*ccname*/	_WT("松鼠_取线程"),
		/*egname*/	_WT("sq_getthread"),
		/*explain*/	_WT("获取\"栈索引\"位置处对象的线程指针，成功返回>=0"),
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
		/*ccname*/	_WT("松鼠_取用户指针"),
		/*egname*/	_WT("sq_getuserpointer"),
		/*explain*/	_WT("获取\"栈索引\"位置处对象的用户指针，成功返回>=0"),
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
		/*ccname*/	_WT("松鼠_取用户数据"),
		/*egname*/	_WT("sq_getuserdata"),
		/*explain*/	_WT("获取\"栈索引\"位置处对象的用户数据指针，成功返回>=0"),
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
		/*ccname*/	_WT("松鼠_置类型标签"),
		/*egname*/	_WT("sq_settypetag"),
		/*explain*/	_WT("在\"栈索引\"位置处设置对象的类型标签（userdata 或 class），成功返回>=0"),
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
		/*ccname*/	_WT("松鼠_取类型标签"),
		/*egname*/	_WT("sq_settypetag"),
		/*explain*/	_WT("获取\"栈索引\"位置处对象的类型标签（用户数据(userdata) 或 类(class)），该函数也适用于实例(instance)。 如果目标对象是实例，则获取其类的类型标签。成功返回>=0"),
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
		/*ccname*/	_WT("松鼠_置释放钩子"),
		/*egname*/	_WT("sq_setreleasehook"),
		/*explain*/	_WT("设置在\"栈索引\"位置处的对象（用户数据(userdata) 、实例(instance) 或 类(class)）的释放回调函数"),
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
		/*ccname*/	_WT("松鼠_取释放钩子"),
		/*egname*/	_WT("sq_getreleasehook"),
		/*explain*/	_WT("获取在\"栈索引\"位置处的对象（用户数据(userdata) 、实例(instance) 或 类(class)）的释放回调函数"),
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
		/*ccname*/	_WT("松鼠_取暂存指针"),
		/*egname*/	_WT("sq_getscratchpad"),
		/*explain*/	_WT("返回一个指向内存缓冲区的指针，该指针至少与请求的一样大。 指针有效期为，直到下一次调用 松鼠_取暂存指针（）"),
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
		/*ccname*/	_WT("松鼠_取函数信息"),
		/*egname*/	_WT("sq_getfunctioninfo"),
		/*explain*/	_WT("返回在栈顶位置的函数信息，如果是一个本地闭包将会失败。成功返回>=0"),
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
		/*ccname*/	_WT("松鼠_取闭包信息"),
		/*egname*/	_WT("sq_getclosureinfo"),
		/*explain*/	_WT("获取在\"栈索引\"位置的闭包参数数量和自由变量数量。成功返回>=0"),
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
		/*ccname*/	_WT("松鼠_取闭包名"),
		/*egname*/	_WT("sq_getclosurename"),
		/*explain*/	_WT("获取在\"栈索引\"位置的闭包名称，并压入栈，成功返回>=0。请注意，如果闭包是匿名的，则名称可以是字符串，也可以是null，或者没有为其指定名称的本地闭包。"),
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
		/*ccname*/	_WT("松鼠_置本地闭包名"),
		/*egname*/	_WT("sq_setnativeclosurename"),
		/*explain*/	_WT("设置在\"栈索引\"位置的本地闭包名称，成功返回>=0。本地闭包的名称纯粹是为了调试。"),
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
		/*ccname*/	_WT("松鼠_置实例用户指针"),
		/*egname*/	_WT("sq_setinstanceup"),
		/*explain*/	_WT("设置在\"栈索引\"位置的实例（instance）的用户指针（userpointer），成功返回>=0。"),
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
		/*ccname*/	_WT("松鼠_取实例用户指针"),
		/*egname*/	_WT("sq_setinstanceup"),
		/*explain*/	_WT("获取在\"栈索引\"位置的实例（instance）的用户指针（userpointer），成功返回>=0。\r\n如果参数'类型标签'不是0，则该函数检查实例的类或基类是否用指定的标签标记; 如果不是则该函数失败。 如果'类型标签'为0，该函数将忽略标记检查。"),
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
		/*ccname*/	_WT("松鼠_置类用户数据大小"),
		/*egname*/	_WT("sq_setclassudsize"),
		/*explain*/	_WT("设置在\"栈索引\"位置的类（class）的用户数据（userdata）大小，成功返回>=0。\r\n如果“用户数据大小”> 0，当创建类的实例时，将在存储实例的内存块的末尾保留额外的空间。 实例的用户指针也将自动设置到此内存区域。 "),
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
		/*ccname*/	_WT("松鼠_新建类"),
		/*egname*/	_WT("sq_newclass"),
		/*explain*/	_WT("创建一个新的类。如果参数'是否有基类'为真，则该函数从栈中弹出一个类，并新创建的类继承自此类。成功返回>=0"),
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
		/*ccname*/	_WT("松鼠_创建实例"),
		/*egname*/	_WT("sq_createinstance"),
		/*explain*/	_WT("在\"栈索引\"位置的类（class）创建一个实例，并压入栈，成功返回>=0。该函数不会调用实例构造函数。 要创建实例并自动调用其构造函数，必须使用 松鼠_调用() sq_call"),
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
		/*ccname*/	_WT("松鼠_置类属性"),
		/*egname*/	_WT("sq_setattributes"),
		/*explain*/	_WT("设置在\"栈索引\"位置的类（class）的成员属性，成功返回>=0。该函数从栈中弹出一个key和一个value，设置为栈中指定位置类的成员属性，如果key = null，则该函数设置类级别属性。如果函数成功，则将旧属性值压入栈中"),
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
		/*ccname*/	_WT("松鼠_取类属性"),
		/*egname*/	_WT("sq_getattributes"),
		/*explain*/	_WT("获取在\"栈索引\"位置的类（class）的成员属性，成功返回>=0。该函数从栈中弹出一个key，并压入类成员属性值value，如果key = null，则压入类级别属性值"),
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
		/*ccname*/	_WT("松鼠_取类"),
		/*egname*/	_WT("sq_getclass"),
		/*explain*/	_WT("获取在\"栈索引\"位置的实例（class instance）的所属类，并压入到栈中，成功返回>=0。"),
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
		/*ccname*/	_WT("松鼠_弱引用"),
		/*egname*/	_WT("sq_weakref"),
		/*explain*/	_WT("获取在\"栈索引\"位置的对象的弱引用，并压入到栈中。如果对象是一个integer，float，bool或null，则压入对象本身而不是弱引用。"),
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
		/*ccname*/	_WT("松鼠_取默认委托"),
		/*egname*/	_WT("sq_getdefaultdelegate"),
		/*explain*/	_WT("获取指定类型的默认委托，并压入到栈中，成功返回>=0。"),
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
		/*ccname*/	_WT("松鼠_取成员句柄"),
		/*egname*/	_WT("sq_getmemberhandle"),
		/*explain*/	_WT("从栈中弹出一个值并将其用作索引来获取类成员的句柄，成功返回>=0。\r\n此方法仅适用于类和实例。 通过类获取的句柄稍后可用于设置或获取一个类实例的值，反之亦然。 从基类检索的句柄在派生类中仍然有效并且尊重继承规则。"),
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

//////////////////////////////////////////////////////////////////////////栈操作

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

//////////////////////////////////////////////////////////////////////////对象创建和处理

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
	SQRELEASEHOOK func = (SQRELEASEHOOK)zy_get_map_ptr(g_sqPtrMap, pArgInf[2].m_int, 2);
	sq_setreleasehook(vm, pArgInf[1].m_int, func);
}
EXTERN_C void esquirrel3_fn_sq_getreleasehook(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_VM(pArgInf);
	INT func = (INT)sq_getreleasehook(vm, pArgInf[1].m_int);
	pRetData->m_int = zy_get_map_key(g_sqPtrMap, func);
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
	//释放之前的
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
	pRetData->m_int = sq_getmemberhandle(vm, pArgInf[1].m_int, pArgInf[2].m_pInt64);
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
	esquirrel3_fn_sq_getmemberhandle

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
	"esquirrel3_fn_sq_getmemberhandle"
};
#endif


/************************************************************************/
/* 数据类型定义
/************************************************************************/

#ifndef __E_STATIC_LIB


LIB_DATA_TYPE_ELEMENT s_dt_element_function_info[] =
{
	/*{ 成员类型 ,数组成员 , 中文名称 ,英文名称 ,成员解释 ,成员状态 ,默认值}*/
	{ SDT_INT, NULL,_WT("ID"), _WT("funcid"), _WT("函数的唯一标识符"), 0, 0 },
	{ SDT_TEXT, NULL,_WT("名称"), _WT("name"), _WT("函数名"), 0, 0 },
	{ SDT_TEXT, NULL,_WT("源文件名"), _WT("source"), _WT("函数所在的源文件名"), 0, 0 },
	{ SDT_INT, NULL,_WT("行号"), _WT("line"), NULL, 0, 0 }
};


static LIB_DATA_TYPE_INFO s_DataTypes[] =
{
	/* { 中文名称, 英文名称, 数据描述, 索引数量, 命令索引, 对象状态, 图标索引, 事件数量, 事件指针, 属性数量, 属性指针, 界面指针, 元素数量, 元素指针 } */
	{ _WT("松鼠函数信息"), _WT("SQFunctionInfo"), _WT("脚本的函数信息，不是本地函数"), 0, NULL, NULL, 0, 0, NULL, 0, NULL, NULL, sizeof(s_dt_element_function_info) / sizeof(s_dt_element_function_info[0]), s_dt_element_function_info },
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
		sizeof(s_DataTypes) / sizeof(s_DataTypes[0]),
		s_DataTypes,
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