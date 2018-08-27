// esquirrel3.cpp : Defines the entry point for the DLL application.
//

#include "esquirrel3.h"

#include "elib_sdk/lib2.h"
#include "elib_sdk/lang.h"
#include "elib_sdk/fnshare.h"
#include "elib_sdk/fnshare.cpp"


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
	{ _WT("释放回调函数"), _WT("返回值：整数型 （整数型 外部指针，整数型 大小）"),0,0, _SDT_ALL, 0, NULL },
};

ARG_INFO s_arg_setsharedreleasehook[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("释放回调函数"), _WT("返回值：整数型 （整数型 外部共享指针，整数型 大小）"),0,0, _SDT_ALL, 0, NULL },
};

ARG_INFO s_arg_setprintfunc[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("打印回调函数"), _WT("返回值：无 （整数型 虚拟机句柄，文本型 输出文本）"),0,0, _SDT_ALL, 0, NULL },
	{ _WT("错误回调函数"), _WT("返回值：无 （整数型 虚拟机句柄，文本型 输出文本）"),0,0, _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY },
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
	{ _WT("读取回调函数"), _WT("返回值：整数型 （整数型 用户指针）"),0,0, _SDT_ALL, 0, NULL },
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
	{ _WT("编译错误回调函数"), _WT("返回值：无（整数型 虚拟机句柄，文本型 目标，文本型 源，整数型 行号，整数型 列号）"),0,0, _SDT_ALL, 0, NULL },
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
	{ _WT("本地函数"), _WT("返回值：整数型（整数型 虚拟机句柄）\r\n 返回1表示有返回值，这个时候要在栈中压入返回值\r\n 返回0表示没有返回值"),0,0, _SDT_ALL, 0, NULL },
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
	{ _WT("释放钩子"), _WT("返回值：整数型（整数型 用户指针，整数型 大小）"),0,0, _SDT_ALL, 0, NULL },
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
ARG_INFO s_arg_newslot[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("是否静态"), _WT("如果为真，则创建一个静态成员。仅当目标对象是类(class)时才使用此参数。"),0,0, SDT_BOOL, 0, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_deleteslot[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("是否压入值"), _WT("如果为真，则将已删除插槽的值压入栈中。"),0,0, SDT_BOOL, 0, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_newmember[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("是否静态"), _WT("如果为真，则创建一个静态成员。"),0,0, SDT_BOOL, 0, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_arraypop[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("是否压入值"), _WT("如果为真，则将已从数组中弹出的值压入栈。"),0,0, SDT_BOOL, 0, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_arrayresize[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("新大小"), _WT("新的数组大小"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_arrayremove[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("数组项目索引"), _WT("索引从0开始"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_setfreevariable[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("自由变量索引"), _WT("索引从0开始（相对于闭包）"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_call[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("参数数量"), _WT("函数的参数数量"),0,0, SDT_INT, 0, NULL },
	{ _WT("是否返回值"), _WT("如果为真，则将函数返回值压入到栈中"),0,0, SDT_BOOL, 0, AS_HAS_DEFAULT_VALUE },
	{ _WT("是否提出错误"), _WT("如果为真，则在执行调用期间发生运行时错误，虚拟机将调用错误处理程序"),0,0, SDT_BOOL, 1, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_resume[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("是否返回值"), _WT("如果为真，则将生成器的返回值压入到栈中"),0,0, SDT_BOOL, 0, AS_HAS_DEFAULT_VALUE },
	{ _WT("是否提出错误"), _WT("如果为真，则在执行期间发生运行时错误，虚拟机将调用错误处理程序"),0,0, SDT_BOOL, 1, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_getlocal[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("等级"), _WT("调用栈等级，0表示当前函数，1表示调用者，依次类推"),0,0, SDT_INT, 0, NULL },
	{ _WT("索引"), _WT("局部变量索引，从0开始"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_getfreevariable[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("目标闭包的索引"),0,0, SDT_INT, 0, NULL },
	{ _WT("自由变量索引"), _WT("从0开始"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_throwerror[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("错误文本"), _WT("要抛出的错误描述"),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_getstackobj[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("对象句柄"), _WT("返回的对象句柄"),0,0, SDT_INT64, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_pushobject[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("对象句柄"), _WT("HSQOBJECT"),0,0, SDT_INT64, 0, NULL },
};
ARG_INFO s_arg_addref[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("对象句柄"), _WT("HSQOBJECT"),0,0, SDT_INT64, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_pobj[] =
{
	{ _WT("对象句柄"), _WT("HSQOBJECT"),0,0, SDT_INT64, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_getobjtypetag[] =
{
	{ _WT("对象句柄"), _WT("HSQOBJECT"),0,0, SDT_INT64, 0, AS_RECEIVE_VAR },
	{ _WT("类型标签"), _WT("返回的类型标签"),0,0, SDT_INT, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_writeclosure[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("写出回调函数"), _WT("返回值：整数型（整数型 用户指针，整数型 数据指针，整数型 数据大小）"),0,0, _SDT_ALL, 0, NULL },
	{ _WT("用户指针"), _WT("传递给每次回调的用户指针"),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_stackinfos[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("等级"), _WT("调用栈等级，0表示当前函数，1表示调用者，依次类推"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈信息"), _WT("SQStackInfos"),0,0, DTP_SQSTACK_INFO, 0, AS_RECEIVE_VAR },
};
ARG_INFO s_arg_setnativedebughook[] =
{
	{ _WT("虚拟机句柄"), _WT("HSQUIRRELVM"),0,0, SDT_INT, 0, NULL },
	{ _WT("调试回调函数"), _WT("返回值：无（整数型 虚拟机，整数型 类型，文本型 源名称，整数型 行号，文本型 函数名）"),0,0, _SDT_ALL, 0, NULL },
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
		/*ccname*/	_WT("松鼠_新建线程"),
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
		/*explain*/	_WT("返回栈顶的索引"),
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
		/*explain*/	_WT("将源栈指定索引的值压入到目标栈中"),
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
	{
		/*ccname*/	_WT("松鼠_句柄取"),
		/*egname*/	_WT("sq_getbyhandle"),
		/*explain*/	_WT("通过成员句柄获取参数'栈索引'指向的类或实例的成员值，并压入到栈中，成功返回>=0。"),
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
		/*ccname*/	_WT("松鼠_句柄置"),
		/*egname*/	_WT("sq_getbyhandle"),
		/*explain*/	_WT("从栈中弹出一个值，并通过成员句柄设置参数'栈索引'指向的类或实例的成员值，成功返回>=0。"),
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
	//////////////////////////////////////////////////////////////////////////对象操作
	{
		/*ccname*/	_WT("松鼠_压入根表"),
		/*egname*/	_WT("sq_pushroottable"),
		/*explain*/	_WT("将根表压入到栈中"),
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
		/*ccname*/	_WT("松鼠_压入注册表"),
		/*egname*/	_WT("sq_pushregistrytable"),
		/*explain*/	_WT("将注册表压入到栈中。注册表是虚拟机和他所有的线程（友元 虚拟机）之间共享的隐藏表。"),
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
		/*ccname*/	_WT("松鼠_压入常量表"),
		/*egname*/	_WT("sq_pushconsttable"),
		/*explain*/	_WT("将常量表压入到栈中。"),
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
		/*ccname*/	_WT("松鼠_置根表"),
		/*egname*/	_WT("sq_setroottable"),
		/*explain*/	_WT("从栈中弹出一个表，将其设置为根表，成功返回>=0"),
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
		/*ccname*/	_WT("松鼠_置常量表"),
		/*egname*/	_WT("sq_setconsttable"),
		/*explain*/	_WT("从栈中弹出一个表，将其设置为常量表，成功返回>=0"),
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
		/*ccname*/	_WT("松鼠_新建插槽"),
		/*egname*/	_WT("sq_newslot"),
		/*explain*/	_WT("从栈中弹出一个键和一个值，并对'栈索引'位置的表或类执行set操作，如果插槽不存在则将创建它，成功返回>=0"),
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
		/*ccname*/	_WT("松鼠_删除插槽"),
		/*egname*/	_WT("sq_deleteslot"),
		/*explain*/	_WT("从栈中弹出一个键，并对'栈索引'位置的表或类删除指定的插槽，如果插槽不存在，则不会有任何反应，成功返回>=0"),
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
		/*ccname*/	_WT("松鼠_置"),
		/*egname*/	_WT("sq_set"),
		/*explain*/	_WT("从栈中弹出一个键和一个值，并对'栈索引'位置的对象执行set操作，成功返回>=0"),
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
		/*ccname*/	_WT("松鼠_取"),
		/*egname*/	_WT("sq_get"),
		/*explain*/	_WT("从栈中弹出一个键，并对'栈索引'位置的对象执行get操作，将结果压入栈中，成功返回>=0"),
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
		/*ccname*/	_WT("松鼠_原始置"),
		/*egname*/	_WT("sq_rawset"),
		/*explain*/	_WT("从栈中弹出一个键和一个值，并对'栈索引'位置的对象执行set操作，且不使用委托或元方法。成功返回>=0"),
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
		/*ccname*/	_WT("松鼠_原始取"),
		/*egname*/	_WT("sq_rawget"),
		/*explain*/	_WT("从栈中弹出一个键，并对'栈索引'位置的对象执行get操作，且不使用委托或元方法，将结果压入栈中。成功返回>=0"),
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
		/*ccname*/	_WT("松鼠_原始删除插槽"),
		/*egname*/	_WT("sq_rawdeleteslot"),
		/*explain*/	_WT("从栈中弹出一个键，并对'栈索引'位置的表或类删除指定的插槽，且不使用_delslot元方法，如果插槽不存在，则不会有任何反应。成功返回>=0"),
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
		/*ccname*/	_WT("松鼠_新建成员"),
		/*egname*/	_WT("sq_newmember"),
		/*explain*/	_WT("从栈中弹出一个键、一个值和一个对象（将被设置为成员的属性），并对'栈索引'位置的类执行新建插槽操作，如果插槽不存在则将是创建。成功返回>=0\r\n在类中调用_newmember元方法。此方法只适用于类。"),
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
		/*ccname*/	_WT("松鼠_原始新建成员"),
		/*egname*/	_WT("sq_rawnewmember"),
		/*explain*/	_WT("从栈中弹出一个键、一个值和一个对象（将被设置为成员的属性），并对'栈索引'位置的类执行新建插槽操作，如果插槽不存在则将是创建。成功返回>=0\r\n此方法只适用于类。"),
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
		/*ccname*/	_WT("松鼠_数组添加"),
		/*egname*/	_WT("sq_arrayappend"),
		/*explain*/	_WT("从栈中弹出一个值，添加到'栈索引'位置的数组后面。成功返回>=0\r\n此方法只适用于数组。"),
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
		/*ccname*/	_WT("松鼠_数组弹出"),
		/*egname*/	_WT("sq_arraypop"),
		/*explain*/	_WT("从'栈索引'位置的数组弹出一个值。成功返回>=0\r\n此方法只适用于数组。"),
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
		/*ccname*/	_WT("松鼠_数组重置大小"),
		/*egname*/	_WT("sq_arrayresize"),
		/*explain*/	_WT("将'栈索引'位置的数组重新设置大小，如果'新大小'大于当前大小则用null填充。成功返回>=0\r\n此方法只适用于数组。"),
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
		/*ccname*/	_WT("松鼠_数组反转"),
		/*egname*/	_WT("sq_arrayreverse"),
		/*explain*/	_WT("将'栈索引'位置的数组元素反转。成功返回>=0\r\n此方法只适用于数组。"),
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
		/*ccname*/	_WT("松鼠_数组删除"),
		/*egname*/	_WT("sq_arrayremove"),
		/*explain*/	_WT("将'栈索引'位置的数组删除指定索引的成员。成功返回>=0\r\n此方法只适用于数组。"),
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
		/*ccname*/	_WT("松鼠_数组插入"),
		/*egname*/	_WT("sq_arrayinsert"),
		/*explain*/	_WT("从栈中弹出一个值，并在'栈索引'位置的数组插入。成功返回>=0\r\n此方法只适用于数组。"),
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
		/*ccname*/	_WT("松鼠_置委托"),
		/*egname*/	_WT("sq_setdelegate"),
		/*explain*/	_WT("从栈中弹出一个表(table)，并将其设置为'栈索引'位置对象的委托,成功返回>=0。要从对象中删除委托，必须使用null作为委托而不是表(table)。"),
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
		/*ccname*/	_WT("松鼠_取委托"),
		/*egname*/	_WT("sq_setdelegate"),
		/*explain*/	_WT("将'栈索引'位置对象的当前委托，压入到栈中,成功返回>=0。"),
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
		/*ccname*/	_WT("松鼠_克隆"),
		/*egname*/	_WT("sq_clone"),
		/*explain*/	_WT("克隆'栈索引'位置指向的表、数组或实例，并将其压入到栈中,成功返回>=0。"),
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
		/*ccname*/	_WT("松鼠_置自由变量"),
		/*egname*/	_WT("sq_setfreevariable"),
		/*explain*/	_WT("从栈中弹出一个值，并将其设置为'栈索引'位置指向的闭包的自由变量,成功返回>=0。"),
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
		/*ccname*/	_WT("松鼠_下一个"),
		/*egname*/	_WT("sq_next"),
		/*explain*/	_WT("向栈中压入一个键和一个值，它们是参数'栈索引'位置指向的数组、表或类的下一个插槽,成功返回>=0。\r\n要开始迭代，此函数需要在栈顶部保留一个空值; 在每次调用时，函数将使用迭代器替换空值，并压入容器插槽的键和值。每次迭代，应用程序都必须弹出前一个键和值，但保留迭代器（用作下一次迭代的参考点）。 迭代完所有插槽后，该函数将失败"),
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
		/*ccname*/	_WT("松鼠_取弱引用值"),
		/*egname*/	_WT("sq_getweakrefval"),
		/*explain*/	_WT("获取'栈索引'处的弱引用的值，并压入到栈中，成功返回>=0"),
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
		/*ccname*/	_WT("松鼠_清除"),
		/*egname*/	_WT("sq_clear"),
		/*explain*/	_WT("清除'栈索引'处的数组或表的所有值，成功返回>=0。此方法仅适用于表和数组。"),
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
		/*ccname*/	_WT("松鼠_调用"),
		/*egname*/	_WT("sq_call"),
		/*explain*/	_WT("调用闭包或本地闭包，成功返回>=0。\r\n该函数弹出所有参数并将闭包留在栈中; 如果'是否返回值'为真，则压入闭包的返回值。 如果通过 松鼠_暂停虚拟机（）暂停执行该函数，则不会自动从栈中弹出闭包和参数。"),
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
		/*ccname*/	_WT("松鼠_恢复"),
		/*egname*/	_WT("sq_resume"),
		/*explain*/	_WT("恢复一个在栈顶的生成器，成功返回>=0。"),
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
		/*ccname*/	_WT("松鼠_取局部变量"),
		/*egname*/	_WT("sq_getlocal"),
		/*explain*/	_WT("返回指定栈级别和索引的局部变量名称，并压入栈。自由变量被视为局部变量。"),
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
		/*ccname*/	_WT("松鼠_取当前闭包"),
		/*egname*/	_WT("sq_getcallee"),
		/*explain*/	_WT("获取当前运行的闭包，并压入栈，成功返回>=0。"),
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
		/*ccname*/	_WT("松鼠_取自由变量"),
		/*egname*/	_WT("sq_getfreevariable"),
		/*explain*/	_WT("获取'栈索引'位置的闭包的指定索引的自由变量名，成功返回>=0。"),
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
		/*ccname*/	_WT("松鼠_抛出错误"),
		/*egname*/	_WT("sq_throwerror"),
		/*explain*/	_WT("设置虚拟机中的最后错误，并返回本地闭包返回的值，以便在虚拟机中触发异常。"),
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
		/*ccname*/	_WT("松鼠_抛出对象"),
		/*egname*/	_WT("sq_throwobject"),
		/*explain*/	_WT("从栈中弹出一个对象，设置为虚拟机中的最后错误，并返回本地闭包返回的值，以便在虚拟机中触发异常。"),
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
		/*ccname*/	_WT("松鼠_重置错误"),
		/*egname*/	_WT("sq_reseterror"),
		/*explain*/	_WT("将虚拟机中的最后错误重置为 null。"),
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
		/*ccname*/	_WT("松鼠_取最后错误"),
		/*egname*/	_WT("sq_getlasterror"),
		/*explain*/	_WT("将虚拟机的最后错误压入栈"),
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

	//////////////////////////////////////////////////////////////////////////原始对象句柄操作
	{
		/*ccname*/	_WT("松鼠_取栈对象"),
		/*egname*/	_WT("sq_getstackobj"),
		/*explain*/	_WT("从栈中获取一个对象，并储存在一个对象句柄中，成功返回>=0"),
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
		/*ccname*/	_WT("松鼠_压入对象"),
		/*egname*/	_WT("sq_pushobject"),
		/*explain*/	_WT("将对象句柄引用的对象压入栈"),
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
		/*ccname*/	_WT("松鼠_添加引用"),
		/*egname*/	_WT("sq_addref"),
		/*explain*/	_WT("添加对象句柄引用计数"),
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
		/*ccname*/	_WT("松鼠_减少引用"),
		/*egname*/	_WT("sq_release"),
		/*explain*/	_WT("减少对象句柄引用计数"),
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
		/*ccname*/	_WT("松鼠_取引用计数"),
		/*egname*/	_WT("sq_getrefcount"),
		/*explain*/	_WT("获取对象句柄的引用计数"),
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
		/*ccname*/	_WT("松鼠_重置对象"),
		/*egname*/	_WT("sq_resetobject"),
		/*explain*/	_WT("重置（初始化）对象句柄。必须使用此函数初始化每个对象句柄。"),
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
		/*ccname*/	_WT("松鼠_对象到文本"),
		/*egname*/	_WT("sq_objtostring"),
		/*explain*/	_WT("返回原始对象引用的字符串值。"),
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
		/*ccname*/	_WT("松鼠_对象到逻辑"),
		/*egname*/	_WT("sq_objtobool"),
		/*explain*/	_WT("返回原始对象引用的逻辑值。"),
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
		/*ccname*/	_WT("松鼠_对象到整数"),
		/*egname*/	_WT("sq_objtointeger"),
		/*explain*/	_WT("返回原始对象引用的整数值。"),
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
		/*ccname*/	_WT("松鼠_对象到浮点数"),
		/*egname*/	_WT("sq_objtofloat"),
		/*explain*/	_WT("返回原始对象引用的浮点数值。"),
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
		/*ccname*/	_WT("松鼠_对象到用户指针"),
		/*egname*/	_WT("sq_objtouserpointer"),
		/*explain*/	_WT("返回原始对象引用的用户指针。"),
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
		/*ccname*/	_WT("松鼠_取对象类型标签"),
		/*egname*/	_WT("sq_getobjtypetag"),
		/*explain*/	_WT("获取原始对象(userdata 或 class)的类型标签。"),
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
		/*ccname*/	_WT("松鼠_取虚拟机引用计数"),
		/*egname*/	_WT("sq_getvmrefcount"),
		/*explain*/	_WT("获取对象句柄在虚拟机中的引用计数"),
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

	//////////////////////////////////////////////////////////////////////////垃圾回收

	{
		/*ccname*/	_WT("松鼠_垃圾回收"),
		/*egname*/	_WT("sq_collectgarbage"),
		/*explain*/	_WT("运行垃圾回收器，并返回找到的（并删除）引用周期数"),
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
		/*ccname*/	_WT("松鼠_复活无法访问"),
		/*egname*/	_WT("sq_resurrectunreachable"),
		/*explain*/	_WT("运行垃圾回收器，并返回找到所有无法访问的对象，生成一个数组压入栈中。成功返回>=0"),
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

	//////////////////////////////////////////////////////////////////////////序列化

	{
		/*ccname*/	_WT("松鼠_写出闭包"),
		/*egname*/	_WT("sq_writeclosure"),
		/*explain*/	_WT("序列化（write）栈顶部的闭包，目标是通过用户定义的写回调函数，成功返回>=0。带有自由变量的闭包无法序列化"),
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
		/*ccname*/	_WT("松鼠_读入闭包"),
		/*egname*/	_WT("sq_readclosure"),
		/*explain*/	_WT("序列化（read）一个闭包，并压入栈，源是通过用户定义的读回调函数。成功返回>=0"),
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

	//////////////////////////////////////////////////////////////////////////调试
	{
		/*ccname*/	_WT("松鼠_取栈信息"),
		/*egname*/	_WT("sq_stackinfos"),
		/*explain*/	_WT("获取调用栈中某个级别的调用栈信息。成功返回>=0"),
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
		/*ccname*/	_WT("松鼠_置调试钩子"),
		/*egname*/	_WT("sq_setdebughook"),
		/*explain*/	_WT("从栈弹出一个闭包，并将其设置为调试钩子。设置调试钩子时，它会覆盖任何以前设置的本机或非本机钩子。如果钩子为null，则将禁用调试钩子。"),
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
		/*ccname*/	_WT("松鼠_置本地调试钩子"),
		/*egname*/	_WT("sq_setnativedebughook"),
		/*explain*/	_WT("设置本机调试钩子。设置本机钩子时，它会覆盖任何以前设置的本机钩子或非本机钩子。 如果钩子为NULL，则将禁用调试钩子。"),
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

//////////////////////////////////////////////////////////////////////////编译
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

//////////////////////////////////////////////////////////////////////////对象操作


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

////////////////////////////////////////////////////////////原始对象操作

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

//////////////////////////////////////////////////////////////////////////垃圾回收

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

//////////////////////////////////////////////////////////////////////////序列化

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

//////////////////////////////////////////////////////////////////////////调试

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
LIB_DATA_TYPE_ELEMENT s_dt_element_stack_info[] =
{
	/*{ 成员类型 ,数组成员 , 中文名称 ,英文名称 ,成员解释 ,成员状态 ,默认值}*/
	{ SDT_TEXT, NULL,_WT("函数名"), _WT("funcname"), _WT(""), 0, 0 },
	{ SDT_TEXT, NULL,_WT("源文件名"), _WT("source"), _WT("函数所在的源文件名"), 0, 0 },
	{ SDT_INT, NULL,_WT("行号"), _WT("line"), NULL, 0, 0 }
};

static LIB_DATA_TYPE_INFO s_DataTypes[] =
{
	/* { 中文名称, 英文名称, 数据描述, 索引数量, 命令索引, 对象状态, 图标索引, 事件数量, 事件指针, 属性数量, 属性指针, 界面指针, 元素数量, 元素指针 } */
	{ _WT("松鼠函数信息"), _WT("SQFunctionInfo"), _WT("脚本的函数信息，不是本地函数"), 0, NULL, NULL, 0, 0, NULL, 0, NULL, NULL, sizeof(s_dt_element_function_info) / sizeof(s_dt_element_function_info[0]), s_dt_element_function_info },
	{ _WT("松鼠栈信息"), _WT("SQStackInfos"), _WT("调用栈信息"), 0, NULL, NULL, 0, 0, NULL, 0, NULL, NULL, sizeof(s_dt_element_stack_info) / sizeof(s_dt_element_stack_info[0]), s_dt_element_stack_info },
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