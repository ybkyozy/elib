// esquirrel3.cpp : Defines the entry point for the DLL application.
//

#include "elua.h"

#include "elib_sdk/lib2.h"
#include "elib_sdk/lang.h"
#include "elib_sdk/fnshare.h"
#include "elib_sdk/fnshare.cpp"

#include "helper.h"


/************************************************************************/
/* 常量定义
/************************************************************************/
#ifndef __E_STATIC_LIB
LIB_CONST_INFO s_ConstInfo[] =
{
	/* { 中文名称, 英文名称, 常量说明, 常量等级(LVL_), 参数类型(CT_), 文本内容, 数值内容 }   只有两种数据类型*/
	{ _WT("LUA_OK"), _WT("LUA_OK"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OK },
	{ _WT("LUA_YIELD"), _WT("LUA_YIELD"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_YIELD },
	{ _WT("LUA_ERRRUN"), _WT("LUA_ERRRUN"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_ERRRUN },
	{ _WT("LUA_ERRSYNTAX"), _WT("LUA_ERRSYNTAX"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_ERRSYNTAX },
	{ _WT("LUA_ERRMEM"), _WT("LUA_ERRMEM"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_ERRMEM },
	{ _WT("LUA_ERRGCMM"), _WT("LUA_ERRGCMM"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_ERRGCMM },
	{ _WT("LUA_ERRERR"), _WT("LUA_ERRERR"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_ERRERR },

	{ _WT("LUA类型_未知"), _WT("LUA_TNONE"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_TNONE },
	{ _WT("LUA类型_空"), _WT("LUA_TNIL"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_TNIL },
	{ _WT("LUA类型_逻辑"), _WT("LUA_TBOOLEAN"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_TBOOLEAN },
	{ _WT("LUA类型_用户指针"), _WT("LUA_TLIGHTUSERDATA"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_TLIGHTUSERDATA },
	{ _WT("LUA类型_数值"), _WT("LUA_TNUMBER"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_TNUMBER },
	{ _WT("LUA类型_文本"), _WT("LUA_TSTRING"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_TSTRING },
	{ _WT("LUA类型_表"), _WT("LUA_TTABLE"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_TTABLE },
	{ _WT("LUA类型_函数"), _WT("LUA_TFUNCTION"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_TFUNCTION },
	{ _WT("LUA类型_用户数据"), _WT("LUA_TUSERDATA"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_TUSERDATA },
	{ _WT("LUA类型_线程"), _WT("LUA_TTHREAD"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_TTHREAD },

	{ _WT("LUA操作符_加"), _WT("LUA_OPADD"), _WT("+"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPADD },
	{ _WT("LUA操作符_减"), _WT("LUA_OPSUB"), _WT("-"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPSUB },
	{ _WT("LUA操作符_乘"), _WT("LUA_OPMUL"), _WT("*"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPMUL },
	{ _WT("LUA操作符_求余"), _WT("LUA_OPMOD"), _WT("%"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPMOD },
	{ _WT("LUA操作符_求次方"), _WT("LUA_OPPOW"), _WT("^"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPPOW },
	{ _WT("LUA操作符_除"), _WT("LUA_OPDIV"), _WT("/"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPDIV },
	{ _WT("LUA操作符_整除"), _WT("LUA_OPIDIV"), _WT("//"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPIDIV },
	{ _WT("LUA操作符_位与"), _WT("LUA_OPBAND"), _WT("&"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPBAND },
	{ _WT("LUA操作符_位或"), _WT("LUA_OPBOR"), _WT("|"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPBOR },
	{ _WT("LUA操作符_位异或"), _WT("LUA_OPBXOR"), _WT("~"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPBXOR },
	{ _WT("LUA操作符_左移"), _WT("LUA_OPSHL"), _WT("<<"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPSHL },
	{ _WT("LUA操作符_右移"), _WT("LUA_OPSHR"), _WT(">>"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPSHR },
	{ _WT("LUA操作符_负"), _WT("LUA_OPUNM"), _WT("-"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPUNM },
	{ _WT("LUA操作符_位取反"), _WT("LUA_OPBNOT"), _WT("~"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPBNOT },

	{ _WT("LUA比较_相等"), _WT("LUA_OPEQ"), _WT("="), LVL_SIMPLE, CT_NUM, NULL, LUA_OPEQ },
	{ _WT("LUA比较_小于"), _WT("LUA_OPLT"), _WT("<"), LVL_SIMPLE, CT_NUM, NULL, LUA_OPLT },
	{ _WT("LUA比较_小于等于"), _WT("LUA_OPLE"), _WT("<="), LVL_SIMPLE, CT_NUM, NULL, LUA_OPLE },

	{ _WT("LUAGC_停止"), _WT("LUA_GCSTOP"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_GCSTOP },
	{ _WT("LUAGC_重启"), _WT("LUA_GCRESTART"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_GCRESTART },
	{ _WT("LUAGC_垃圾回收"), _WT("LUA_GCCOLLECT"), _WT("执行完整的垃圾回收"), LVL_SIMPLE, CT_NUM, NULL, LUA_GCCOLLECT },
	{ _WT("LUAGC_内存使用数"), _WT("LUA_GCCOUNT"), _WT(" 返回当前使用的内存大小(以KB为单位"), LVL_SIMPLE, CT_NUM, NULL, LUA_GCCOUNT },
	{ _WT("LUAGC_内存使用字节数"), _WT("LUA_GCCOUNTB"), _WT(" 返回当前使用的内存大小(以字节为单位)"), LVL_SIMPLE, CT_NUM, NULL, LUA_GCCOUNTB },
	{ _WT("LUAGC_单步"), _WT("LUA_GCSTEP"), _WT("单步执行垃圾回收"), LVL_SIMPLE, CT_NUM, NULL, LUA_GCSTEP },
	{ _WT("LUAGC_置暂停"), _WT("LUA_GCSETPAUSE"), _WT(" 将数据设置为垃圾回收暂停的新值，并返回旧值"), LVL_SIMPLE, CT_NUM, NULL, LUA_GCSETPAUSE },
	{ _WT("LUAGC_置步长乘数"), _WT("LUA_GCSETSTEPMUL"), _WT("将数据设置为垃圾回收步长乘数的新值，并返回旧值"), LVL_SIMPLE, CT_NUM, NULL, LUA_GCSETSTEPMUL },
	{ _WT("LUAGC_是否在运行"), _WT("LUA_GCISRUNNING"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_GCISRUNNING },

	{ _WT("LUA_注册表索引"), _WT("LUA_REGISTRYINDEX"), _WT("指向注册表的虚拟索引。"), LVL_SIMPLE, CT_NUM, NULL, LUA_REGISTRYINDEX },
	{ _WT("LUA_RIDX_主线程"), _WT("LUA_RIDX_MAINTHREAD"), _WT("注册表中的主线程索引。"), LVL_SIMPLE, CT_NUM, NULL, LUA_RIDX_MAINTHREAD },
	{ _WT("LUA_RIDX_全局表"), _WT("LUA_RIDX_GLOBALS"), _WT("注册表中的全局表索引。"), LVL_SIMPLE, CT_NUM, NULL, LUA_RIDX_GLOBALS },

	{ _WT("LUA_HOOKCALL"), _WT("LUA_HOOKCALL"), _WT("调用钩子"), LVL_SIMPLE, CT_NUM, NULL, LUA_HOOKCALL },
	{ _WT("LUA_HOOKRET"), _WT("LUA_HOOKRET"), _WT(""), LVL_SIMPLE, CT_NUM, NULL, LUA_HOOKRET },
	{ _WT("LUA_HOOKLINE"), _WT("LUA_HOOKLINE"), _WT(""), LVL_SIMPLE, CT_NUM, NULL, LUA_HOOKLINE },
	{ _WT("LUA_HOOKCOUNT"), _WT("LUA_HOOKCOUNT"), _WT(""), LVL_SIMPLE, CT_NUM, NULL, LUA_HOOKCOUNT },
	{ _WT("LUA_HOOKTAILCALL"), _WT("LUA_HOOKTAILCALL"), _WT("尾调用钩子"), LVL_SIMPLE, CT_NUM, NULL, LUA_HOOKTAILCALL },

	{ _WT("LUA_MASKCALL"), _WT("LUA_MASKCALL"), _WT(""), LVL_SIMPLE, CT_NUM, NULL, LUA_MASKCALL },
	{ _WT("LUA_MASKRET"), _WT("LUA_MASKRET"), _WT(""), LVL_SIMPLE, CT_NUM, NULL, LUA_MASKRET },
	{ _WT("LUA_MASKLINE"), _WT("LUA_MASKLINE"), _WT(""), LVL_SIMPLE, CT_NUM, NULL, LUA_MASKLINE },
	{ _WT("LUA_MASKCOUNT"), _WT("LUA_MASKCOUNT"), _WT(""), LVL_SIMPLE, CT_NUM, NULL, LUA_MASKCOUNT },

	{ _WT("LUA_空引用"), _WT("LUA_REFNIL"), _WT(""), LVL_SIMPLE, CT_NUM, NULL, LUA_REFNIL },
};

#endif


#ifndef __E_STATIC_LIB

// 参数 
ARG_INFO s_arg_lua[] =
{
	/* { 参数名称, 参数描述, 图像索引, 图像数量, 参数类型(参见SDT_), 默认数值, 参数类别(参见AS_) } */
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_newstate[] =
{
	{ _WT("内存分配器回调函数"), _WT("返回值：整数型（整数型 用户数据，整数型 指针，整数型 源大小，整数型 新大小）"),0,0, _SDT_ALL, 0, NULL },
	{ _WT("用户数据"), _WT("提供给回调函数的参数"),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_lua_atpanic[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("将崩溃回调函数"), _WT("返回值：整数型（整数型 Lua状态）"),0,0, _SDT_ALL, 0, NULL },
};
ARG_INFO s_arg_lua_idx[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_rotate[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("旋转数量"), _WT(""),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_copy[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("源栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("目标栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_checkstack[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("检查数量"), _WT("要检查剩余空间的数量"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_xmove[] =
{
	{ _WT("源Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("目标Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("交换数量"), _WT("要交换值的数量"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_typename[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("类型"), _WT("'LUA类型_'开头常量"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_lua_tonumberx[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("是否数值"), _WT("返回'栈索引'指定的值是否为数值"),0,0, SDT_BOOL, 0, AS_DEFAULT_VALUE_IS_EMPTY | AS_RECEIVE_VAR },
};

ARG_INFO s_arg_lua_arith[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("操作符"), _WT("'LUA操作符_'开头常量"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_rawequal[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引1"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引2"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_compare[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引1"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引2"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("比较操作"), _WT("'LUA比较_'开头常量"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_lua_pushnumber[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("数值"), _WT("要压入的数值"),0,0, SDT_DOUBLE, 0, NULL },
};
ARG_INFO s_arg_lua_pushinteger[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("整数"), _WT("要压入的整数"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_pushlstring[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("文本"), _WT("要压入的文本"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("长度"), _WT("要压入的长度"),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_lua_pushvfstring[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("格式化文本"), _WT("格式化文本"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("参数"), _WT("格式化文本中的参数，只能是基本数据类型"),0,0, _SDT_ALL, 0, NULL },
};
ARG_INFO s_arg_lua_pushcclosure[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("本地函数"), _WT("返回值：整数型（整数型 Lua状态）"),0,0, _SDT_ALL, 0, NULL },
	{ _WT("上值数量"), _WT("如果这个参数>0 (但是不能>256)，则会从栈中弹出n个值作为闭包的上值，当本地函数被调用时可以获取这些值。"),0,0, SDT_INT, 0, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_lua_pushboolean[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("逻辑值"), _WT("要压入的逻辑值"),0,0, SDT_BOOL, 0, NULL },
};
ARG_INFO s_arg_lua_pushlightuserdata[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("用户指针"), _WT("要压入的用户指针"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_lua_pushthread[] =
{
	{ _WT("线程"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
};

ARG_INFO s_arg_lua_getglobal[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("名称"), _WT(""),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_lua_getfield[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("键名"), _WT(""),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_lua_geti[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("成员索引"), _WT(""),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_rawgetp[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("用户指针"), _WT(""),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_createtable[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("数组大小"), _WT("表的数组部分初始大小"),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
	{ _WT("哈希大小"), _WT("表的哈希部分初始大小"),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_lua_newuserdata[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("大小"), _WT("字节为单位"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_callk[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("参数个数"), _WT(""),0,0, SDT_INT, 0, NULL },
	{ _WT("返回值个数"), _WT("如果设置为-1，则所有返回值都会压入到栈中"),0,0, SDT_INT, -1, AS_HAS_DEFAULT_VALUE },
	{ _WT("继续函数上下文"), _WT("lua_KContext"),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
	{ _WT("继续函数"), _WT("返回值：整数型（整数型 Lua状态，整数型 status，整数型 上下文）"),0,0, _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_lua_call[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("参数个数"), _WT(""),0,0, SDT_INT, 0, NULL },
	{ _WT("返回值个数"), _WT("如果设置为-1，则所有返回值都会压入到栈中"),0,0, SDT_INT, -1, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_lua_pcallk[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("参数个数"), _WT(""),0,0, SDT_INT, 0, NULL },
	{ _WT("返回值个数"), _WT("如果设置为-1，则所有返回值都会压入到栈中"),0,0, SDT_INT, -1, AS_HAS_DEFAULT_VALUE },
	{ _WT("错误处理闭包栈索引"), _WT("指定作为错误处理的闭包在栈中的索引"),0,0, SDT_INT, 0, NULL },
	{ _WT("继续函数上下文"), _WT("lua_KContext"),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
	{ _WT("继续函数"), _WT("返回值：整数型（整数型 Lua状态，整数型 status，整数型 上下文）"),0,0, _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_lua_pcall[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("参数个数"), _WT(""),0,0, SDT_INT, 0, NULL },
	{ _WT("返回值个数"), _WT("如果设置为-1，则所有返回值都会压入到栈中"),0,0, SDT_INT, -1, AS_HAS_DEFAULT_VALUE },
	{ _WT("错误处理闭包栈索引"), _WT("指定作为错误处理的闭包在栈中的索引"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_load[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("读取函数"), _WT("返回值：整数型[指针] （整数型 Lua状态，整数型 用户数据，整数型[参考] 大小）"),0,0, SDT_INT, 0, NULL },
	{ _WT("读取函数用户数据"), _WT("传递给读取函数的参数"),0,0, SDT_INT, 0, AS_HAS_DEFAULT_VALUE },
	{ _WT("块名称"), _WT("用于错误消息和调试信息"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("模式"), _WT("binary、text、bt"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_lua_dump[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("写出函数"), _WT("返回值：整数型 （整数型 Lua状态，整数型 数据，整数型 大小，整数型 用户数据）"),0,0, SDT_INT, 0, NULL },
	{ _WT("写出函数用户数据"), _WT("传递给写出函数的参数"),0,0, SDT_INT, 0, AS_HAS_DEFAULT_VALUE },
	{ _WT("不包含调试信息"), _WT("如果为真，则转储的二进制块不包含调试信息"),0,0, SDT_BOOL, 1, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_lua_yieldk[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("返回值个数"), _WT("返回给 LUA_继续 的返回值个数"),0,0, SDT_INT, 0, AS_HAS_DEFAULT_VALUE },
	{ _WT("继续函数上下文"), _WT("lua_KContext"),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
	{ _WT("继续函数"), _WT("返回值：整数型（整数型 Lua状态，整数型 status，整数型 上下文）"),0,0, _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_lua_resume[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("线程"), _WT("正在恢复的协程线程"),0,0, SDT_INT, 0, AS_HAS_DEFAULT_VALUE },
	{ _WT("参数个数"), _WT(""),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_gc[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("操作"), _WT("LUAGC_ 开头常量"),0,0, SDT_INT, 0, NULL },
	{ _WT("数据"), _WT(""),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_lua_concat[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("操作数量"), _WT("要连接的值的数量"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_stringtonumber[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("文本"), _WT("要转为为数值的文本"),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_lua_getallocf[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("返回用户数据"), _WT("返回在设置内存分配器时给定的用户数据"),0,0, SDT_INT, 0, AS_RECEIVE_VAR | AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_lua_setallocf[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("内存分配函数"), _WT("返回值：整数型（整数型 用户数据，整数型 指针，整数型 源大小，整数型 新大小）"),0,0, SDT_INT, 0, NULL },
	{ _WT("用户数据"), _WT("内存分配回调函数的参数"),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_lua_pop[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("弹出数"), _WT("要弹出栈的数量"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_register[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("函数名"), _WT(""),0,0, SDT_TEXT, 0, NULL },
	{ _WT("本地函数"), _WT("返回值：整数型（整数型 Lua状态）"),0,0, _SDT_ALL, 0, NULL },
};
ARG_INFO s_arg_lua_pushcfunction[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("本地函数"), _WT("返回值：整数型（整数型 Lua状态）"),0,0, _SDT_ALL, 0, NULL },
};
ARG_INFO s_arg_lua_upvalueindex[] =
{
	{ _WT("栈索引"), _WT(""),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_getstack[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("等级"), _WT("0是当前函数，1是调用者，依次类推。"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_freedebugptr[] =
{
	{ _WT("调试指针"), _WT("由 LUA_取栈指针（）返回的指针"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_getinfo[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("文本掩码"), _WT("what"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("调试指针"), _WT("由 LUA_取栈指针（）返回的指针 或 钩子HOOK 回调函数的参数的调试指针"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_getlocal[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("调试指针"), _WT("由 LUA_取栈指针（）返回的指针 或 钩子HOOK 回调函数的参数的调试指针"),0,0, SDT_INT, 0, NULL },
	{ _WT("变量索引"), _WT("1表示第一个变量，2表示第二个，以此类推。-1表示vararg参数"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_getupvalue[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("函数索引"), _WT("函数所在的栈索引"),0,0, SDT_INT, 0, NULL },
	{ _WT("上值索引"), _WT("1表示第一个上值"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_upvaluejoin[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("函数索引1"), _WT("函数所在的栈索引"),0,0, SDT_INT, 0, NULL },
	{ _WT("上值索引1"), _WT("1表示第一个上值"),0,0, SDT_INT, 0, NULL },
	{ _WT("函数索引2"), _WT("函数所在的栈索引"),0,0, SDT_INT, 0, NULL },
	{ _WT("上值索引2"), _WT("1表示第一个上值"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_lua_sethook[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("钩子函数"), _WT("返回值：无（整数型 Lua状态，整数型 调试指针）"),0,0, _SDT_ALL, 0, NULL },
	{ _WT("掩码"), _WT("LUA_MASK 开头常量"),0,0, SDT_INT, 0, NULL },
	{ _WT("数量"), _WT("count"),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_luaL_getmetafield[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("对象索引"), _WT("obj"),0,0, _SDT_ALL, 0, NULL },
	{ _WT("字段名"), _WT("e"),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_luaL_tolstring[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("返回长度"), _WT(""),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY | AS_RECEIVE_VAR },
};
ARG_INFO s_arg_luaL_argerror[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("函数栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("额外信息"), _WT(""),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_luaL_checklstring[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("参数索引"), _WT("1表示第一个参数"),0,0, SDT_INT, 0, NULL },
	{ _WT("返回长度"), _WT(""),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY | AS_RECEIVE_VAR },
};
ARG_INFO s_arg_luaL_optlstring[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("参数索引"), _WT("1表示第一个参数"),0,0, SDT_INT, 0, NULL },
	{ _WT("默认值"), _WT(""),0,0, SDT_TEXT, 0, NULL },
	{ _WT("返回长度"), _WT(""),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY | AS_RECEIVE_VAR },
};
ARG_INFO s_arg_luaL_arg[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("参数索引"), _WT("1表示第一个参数"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_luaL_optnumber[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("参数索引"), _WT("1表示第一个参数"),0,0, SDT_INT, 0, NULL },
	{ _WT("默认值"), _WT(""),0,0, SDT_DOUBLE, 0, NULL },
};
ARG_INFO s_arg_luaL_optinteger[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("参数索引"), _WT("1表示第一个参数"),0,0, SDT_INT, 0, NULL },
	{ _WT("默认值"), _WT(""),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_luaL_checkstack[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("大小"), _WT("要增加栈元素的大小"),0,0, SDT_INT, 0, NULL },
	{ _WT("错误文本"), _WT("当发生错误时的附件信息"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_luaL_checktype[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("参数索引"), _WT("1表示第一个参数"),0,0, SDT_INT, 0, NULL },
	{ _WT("类型"), _WT("LUA类型_ 开头常量"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_luaL_newmetatable[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("类型名"), _WT("tname"),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_luaL_testudata[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("参数索引"), _WT("1表示第一个参数"),0,0, SDT_INT, 0, NULL },
	{ _WT("类型名"), _WT("tname"),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_luaL_where[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("等级"), _WT("0表示当前函数，1表示调用者"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_luaL_error[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("错误文本"), _WT(""),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_luaL_checkoption[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("参数索引"), _WT("1表示第一个参数"),0,0, SDT_INT, 0, NULL },
	{ _WT("默认值"), _WT("def"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
	{ _WT("选项"), _WT("option"),0,0, SDT_TEXT, 0, AS_RECEIVE_ARRAY_DATA},
};
ARG_INFO s_arg_luaL_ref[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("表栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_luaL_unref[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("表栈索引"), _WT("-1表示栈顶，1表示栈底"),0,0, SDT_INT, 0, NULL },
	{ _WT("引用对象"), _WT("由 LUAL_引用（）返回"),0,0, SDT_INT, 0, NULL },
};
ARG_INFO s_arg_luaL_loadfilex[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("文件名"), _WT("脚本文件名"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("模式"), _WT("binary、text、bt"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_luaL_loadbufferx[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("脚本数据"), _WT(""),0,0, _SDT_ALL, 0, NULL },
	{ _WT("块名称"), _WT("用于错误消息和调试信息"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("模式"), _WT("binary、text、bt"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
ARG_INFO s_arg_luaL_loadstring[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("文本脚本"), _WT(""),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_luaL_gsub[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("源文本"), _WT(""),0,0, SDT_TEXT, 0, NULL },
	{ _WT("要替换的子文本"), _WT(""),0,0, SDT_TEXT, 0, NULL },
	{ _WT("用作替换的文本"), _WT(""),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_luaL_setfuncs[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("注册数组"), _WT("LUA_注册 结构体数组"),0,0, DTP_LUA_REG, 0, AS_RECEIVE_ARRAY_DATA },
	{ _WT("上值数"), _WT("如果此参数>0，则在注册之前，在栈中压入相同数量的值，来作为所有函数的上值。"),0,0, SDT_INT, 0, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_luaL_getsubtable[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("栈索引"), _WT("指向table值的栈索引"),0,0, SDT_INT, 0, NULL },
	{ _WT("表名"), _WT("fname"),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_luaL_traceback[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("Lua状态1"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("消息"), _WT("msg"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
	{ _WT("等级"), _WT("level"),0,0, SDT_INT, 1, AS_HAS_DEFAULT_VALUE },
};
ARG_INFO s_arg_luaL_requiref[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("模块名"), _WT("modname"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("公开函数"), _WT("openf"),0,0, _SDT_ALL, 0, NULL },
	{ _WT("全局"), _WT("glb"),0,0, SDT_BOOL },
};
ARG_INFO s_arg_luaL_newlibtable[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("注册数组"), _WT("LUA_注册 结构体数组"),0,0, DTP_LUA_REG, 0, AS_RECEIVE_ARRAY_DATA },
};
ARG_INFO s_arg_luaL_argcheck[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("条件"), _WT(""),0,0, SDT_BOOL, 0, NULL },
	{ _WT("参数索引"), _WT("1表示第一个参数"),0,0, SDT_INT, 0, NULL },
	{ _WT("错误信息"), _WT(""),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_luaL_dofile[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("文件名"), _WT(""),0,0, SDT_TEXT, 0, NULL },
};
ARG_INFO s_arg_luaL_dostring[] =
{
	{ _WT("Lua状态"), _WT("lua_State*"),0,0, SDT_INT, 0, NULL },
	{ _WT("脚本文本"), _WT(""),0,0, SDT_TEXT, 0, NULL },
};

// 命令信息
static CMD_INFO s_CmdInfo[] =
{
	/* { 中文名称, 英文名称, 对象描述, 所属类别(-1是数据类型的方法), 命令状态(CT_), 返回类型(SDT_), 此值保留, 对象等级(LVL_), 图像索引, 图像数量, 参数个数, 参数信息 } */

	//////////////////////////////////////////////////////////////////////////状态操作
	{
		/*ccname*/	_WT("LUA_新建"),
		/*egname*/	_WT("lua_newstate"),
		/*explain*/ _WT("创建一个主线程执行状态，成功返回lua_State指针，失败返回0"),
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
		/*ccname*/	_WT("LUA_关闭"),
		/*egname*/	_WT("lua_close"),
		/*explain*/ _WT("关闭状态"),
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
		/*ccname*/	_WT("LUA_新建线程"),
		/*egname*/	_WT("lua_close"),
		/*explain*/ _WT("创建一个新线程，压入到栈中，并且返回lua_State指针。\r\n此函数返回的新线程与原始线程共享其全局环境，但具有独立的执行栈。不需要显示关闭它。"),
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
		/*ccname*/	_WT("LUA_置崩溃函数"),
		/*egname*/	_WT("lua_atpanic"),
		/*explain*/ _WT("设置一个新的崩溃函数，并返回之前设置的那个。"),
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
		/*ccname*/	_WT("LUA_取版本"),
		/*egname*/	_WT("lua_version"),
		/*explain*/ _WT("返回版本号"),
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
	//////////////////////////////////////////////////////////////////////////基本栈操作
	{
		/*ccname*/	_WT("LUA_取绝对索引"),
		/*egname*/	_WT("lua_absindex"),
		/*explain*/ _WT("将参数'栈索引'转换为不依赖栈顶的绝对索引"),
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
		/*ccname*/	_WT("LUA_取栈顶"),
		/*egname*/	_WT("lua_gettop"),
		/*explain*/ _WT("返回栈中顶部元素的索引。因为索引从1开始，所以此结果等于栈中元素的数量; 特殊情况0表示空堆栈。"),
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
		/*ccname*/	_WT("LUA_置栈顶"),
		/*egname*/	_WT("lua_settop"),
		/*explain*/ _WT("并将栈顶设置为指定索引。如果新栈顶大于旧栈顶，则新元素将填充为nil。 如果索引为0，则删除所有栈元素。"),
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
		/*ccname*/	_WT("LUA_压入值"),
		/*egname*/	_WT("lua_pushvalue"),
		/*explain*/ _WT("将指定索引处元素的副本压入到栈中。"),
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
		/*ccname*/	_WT("LUA_旋转"),
		/*egname*/	_WT("lua_rotate"),
		/*explain*/ _WT("在有效'栈索引'和栈顶之间旋转元素。\r\n元素在栈顶方向旋转n个元素，在栈底方向旋转n或-n个元素。"),
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
		/*ccname*/	_WT("LUA_复制"),
		/*egname*/	_WT("lua_copy"),
		/*explain*/ _WT("将'源栈索引'元素复制到'目标栈索引',替换该位置的值。其他位置的值不受影响。"),
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
		/*ccname*/	_WT("LUA_检查栈"),
		/*egname*/	_WT("lua_checkstack"),
		/*explain*/ _WT("确保栈有至少n个额外插槽的空间（也就是说，您可以安全地将n个值插入其中）。 如果它无法满足请求，则返回假"),
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
		/*ccname*/	_WT("LUA_交换"),
		/*egname*/	_WT("lua_xmove"),
		/*explain*/ _WT("在相同状态的不同线程之间交换值。 此函数从源栈中弹出n个值，并将它们压入到目标栈中。"),
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
	//////////////////////////////////////////////////////////////////////////访问函数（栈->易）
	{
		/*ccname*/	_WT("LUA_是否数值"),
		/*egname*/	_WT("lua_isnumber"),
		/*explain*/ _WT("如果'栈索引'位置是数值或可以转换为数值返回真，否则返回假。"),
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
		/*ccname*/	_WT("LUA_是否文本"),
		/*egname*/	_WT("lua_isstring"),
		/*explain*/ _WT("如果'栈索引'位置是文本或可以转换为文本的数值返回真，否则返回假。"),
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
		/*ccname*/	_WT("LUA_是否本地函数"),
		/*egname*/	_WT("lua_iscfunction"),
		/*explain*/ _WT("如果'栈索引'位置是本地函数返回真，否则返回假。"),
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
		/*ccname*/	_WT("LUA_是否整数"),
		/*egname*/	_WT("lua_isinteger"),
		/*explain*/ _WT("如果'栈索引'位置是整数返回真，否则返回假。"),
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
		/*ccname*/	_WT("LUA_是否用户数据"),
		/*egname*/	_WT("lua_isuserdata"),
		/*explain*/ _WT("如果'栈索引'位置是用户数据（用户数据 或 用户指针）返回真，否则返回假。"),
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
		/*ccname*/	_WT("LUA_取类型"),
		/*egname*/	_WT("lua_type"),
		/*explain*/ _WT("返回'栈索引'位置的值类型，'LUA类型_'开头常量"),
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
		/*ccname*/	_WT("LUA_取类型名"),
		/*egname*/	_WT("lua_typename"),
		/*explain*/ _WT("返回指定类型的文本名称"),
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
		/*ccname*/	_WT("LUA_到数值X"),
		/*egname*/	_WT("lua_tonumberx"),
		/*explain*/ _WT("将‘栈索引’位置的值转换为双精度小数型。"),
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
		/*ccname*/	_WT("LUA_到整数X"),
		/*egname*/	_WT("lua_tointegerx"),
		/*explain*/ _WT("将‘栈索引’位置的值转换为整数型。"),
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
		/*ccname*/	_WT("LUA_到逻辑"),
		/*egname*/	_WT("lua_toboolean"),
		/*explain*/ _WT("将‘栈索引’位置的值转换为逻辑型。"),
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
		/*ccname*/	_WT("LUA_到文本"),
		/*egname*/	_WT("lua_tolstring"),
		/*explain*/ _WT("将‘栈索引’位置的值转换为文本型。"),
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
		/*ccname*/	_WT("LUA_取源长度"),
		/*egname*/	_WT("lua_rawlen"),
		/*explain*/ _WT("获取‘栈索引’位置的值的长度。对于文本返回文本长度，对于表返回长度运算符(#)的结果()，对于用户数据返回内存大小，其他值返回0"),
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
		/*ccname*/	_WT("LUA_到本地函数"),
		/*egname*/	_WT("lua_tocfunction"),
		/*explain*/ _WT("将‘栈索引’位置的值转换为本地函数地址。"),
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
		/*ccname*/	_WT("LUA_到用户数据"),
		/*egname*/	_WT("lua_touserdata"),
		/*explain*/ _WT("将‘栈索引’位置的值转换为用户数据，返回其指针。"),
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
		/*ccname*/	_WT("LUA_到线程"),
		/*egname*/	_WT("lua_tothread"),
		/*explain*/ _WT("将‘栈索引’位置的值转换为线程，返回Lua状态。"),
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
		/*ccname*/	_WT("LUA_到指针"),
		/*egname*/	_WT("lua_topointer"),
		/*explain*/ _WT("将‘栈索引’位置的值转换通用指针，值可以是用户数据、表、线程或函数，否则返回0。"),
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
	////////////////////////////////////////////////////////////////////////////比较和算术函数

	{
		/*ccname*/	_WT("LUA_数学操作"),
		/*egname*/	_WT("lua_arith"),
		/*explain*/ _WT("对栈顶部的两个值进行数学运算，栈顶是第二个操作数，并弹出他们，再将结果压入到栈中。"),
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
		/*ccname*/	_WT("LUA_元相等"),
		/*egname*/	_WT("lua_rawequal"),
		/*explain*/ _WT("比较两个栈索引的值（即不调用 __eq 元方法），相等返回真，有任何一个索引无效都返回假。"),
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
		/*ccname*/	_WT("LUA_比较"),
		/*egname*/	_WT("lua_compare"),
		/*explain*/ _WT("用指定的操作符比较两个栈索引的值，如果任何一个索引无效返回假。"),
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
	//////////////////////////////////////////////////////////////////////////压栈操作
	{
		/*ccname*/	_WT("LUA_压入空"),
		/*egname*/	_WT("lua_pushnil"),
		/*explain*/ _WT("压入 nil 到栈中"),
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
		/*ccname*/	_WT("LUA_压入数值"),
		/*egname*/	_WT("lua_pushnumber"),
		/*explain*/ _WT("压入数值到栈中"),
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
		/*ccname*/	_WT("LUA_压入整数"),
		/*egname*/	_WT("lua_pushinteger"),
		/*explain*/ _WT("压入整数到栈中"),
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
		/*ccname*/	_WT("LUA_压入文本"),
		/*egname*/	_WT("lua_pushlstring"),
		/*explain*/ _WT("压入文本到栈中，返回内部拷贝的指针。如果返回0，则将nil压入栈。"),
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
		/*ccname*/	_WT("LUA_压入格式化文本"),
		/*egname*/	_WT("lua_pushvfstring"),
		/*explain*/ _WT("压入格式化文本到栈中，返回内部拷贝的指针。如果返回0，则将nil压入栈。"),
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
		/*ccname*/	_WT("LUA_压入闭包"),
		/*egname*/	_WT("lua_pushcclosure"),
		/*explain*/ _WT("将本地函数压入到栈中。"),
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
		/*ccname*/	_WT("LUA_压入逻辑"),
		/*egname*/	_WT("lua_pushboolean"),
		/*explain*/ _WT("压入逻辑值到栈中。"),
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
		/*ccname*/	_WT("LUA_压入用户指针"),
		/*egname*/	_WT("lua_pushlightuserdata"),
		/*explain*/ _WT("压入用户指针到栈中。"),
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
		/*ccname*/	_WT("LUA_压入线程"),
		/*egname*/	_WT("lua_pushthread"),
		/*explain*/ _WT("压入线程到栈中。如果参数线程是主线程，返回1"),
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

	//////////////////////////////////////////////////////////////////////////取值操作
	{
		/*ccname*/	_WT("LUA_取全局值"),
		/*egname*/	_WT("lua_getglobal"),
		/*explain*/ _WT("将全局名称的值压入栈中，返回该值的类型。会触发元方法的‘index’事件"),
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
		/*ccname*/	_WT("LUA_取表值"),
		/*egname*/	_WT("lua_gettable"),
		/*explain*/ _WT("从栈中弹出一个键，根据‘栈索引’指向的表获取一个值，并压入到栈中，返回该值的类型。会触发元方法的‘index’事件"),
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
		/*ccname*/	_WT("LUA_取字段值"),
		/*egname*/	_WT("lua_getfield"),
		/*explain*/ _WT("根据‘栈索引’指向的表，和‘键名’获取一个值，并压入到栈中，返回该值的类型。会触发元方法的‘index’事件"),
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
		/*ccname*/	_WT("LUA_取索引值"),
		/*egname*/	_WT("lua_getfield"),
		/*explain*/ _WT("根据‘栈索引’指向的表，和‘成员索引’获取一个值，并压入到栈中，返回该值的类型。会触发元方法的‘index’事件"),
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
		/*ccname*/	_WT("LUA_元取值"),
		/*egname*/	_WT("lua_rawget"),
		/*explain*/ _WT("从栈中弹出一个键，根据‘栈索引’指向的表，获取一个值，并压入到栈中，返回该值的类型。不会触发元方法"),
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
		/*ccname*/	_WT("LUA_元取值索引"),
		/*egname*/	_WT("lua_rawgeti"),
		/*explain*/ _WT("根据‘栈索引’指向的表，和‘成员索引’获取一个值，并压入到栈中，返回该值的类型。不会触发元方法"),
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
		/*ccname*/	_WT("LUA_元取值指针"),
		/*egname*/	_WT("lua_rawgetp"),
		/*explain*/ _WT("根据‘栈索引’指向的表，和‘用户指针’作为键，获取一个值，并压入到栈中，返回该值的类型。不会触发元方法"),
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
		/*ccname*/	_WT("LUA_创建表"),
		/*egname*/	_WT("lua_createtable"),
		/*explain*/ _WT("创建一个表，并压入到栈中。参数可以指定初始容量，可提供效率。"),
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
		/*ccname*/	_WT("LUA_新建用户数据"),
		/*egname*/	_WT("lua_newuserdata"),
		/*explain*/ _WT("创建一个自定义数据内存块，并压入到栈中，且返回该指针，应用程序可以随意读写。"),
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
		/*ccname*/	_WT("LUA_取元表"),
		/*egname*/	_WT("lua_getmetatable"),
		/*explain*/ _WT("如果‘栈索引’处的值具有metatable，则将压入到栈中并返回真，否则返回假。"),
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
		/*ccname*/	_WT("LUA_取用户值"),
		/*egname*/	_WT("lua_getuservalue"),
		/*explain*/ _WT("将'栈索引'处的用户数据所关联的 Lua 值压入到栈中。返回压入值的类型。"),
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

	//////////////////////////////////////////////////////////////////////////赋值函数//////////////////////////////////////////////////////////////////////////

	{
		/*ccname*/	_WT("LUA_置全局值"),
		/*egname*/	_WT("lua_setglobal"),
		/*explain*/ _WT("从栈中弹出一个值，设置为全局指定名称的新值。"),
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
		/*ccname*/	_WT("LUA_置表值"),
		/*egname*/	_WT("lua_settable"),
		/*explain*/ _WT("从栈中弹出一个键和一个值（值在栈顶），并设置为‘栈索引’处表成员的值。可能触发“newindex”事件的元方法"),
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
		/*ccname*/	_WT("LUA_置字段值"),
		/*egname*/	_WT("lua_setfield"),
		/*explain*/ _WT("从栈中弹出一个值，和参数给定的‘名称’，设置为‘栈索引’处表成员的值。可能触发“newindex”事件的元方法"),
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
		/*ccname*/	_WT("LUA_置索引值"),
		/*egname*/	_WT("lua_seti"),
		/*explain*/ _WT("从栈中弹出一个值，和参数给定的‘成员索引’，设置为‘栈索引’处表成员的值。可能触发“newindex”事件的元方法"),
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
		/*ccname*/	_WT("LUA_元赋值"),
		/*egname*/	_WT("lua_rawset"),
		/*explain*/ _WT("从栈中弹出一个键和一个值（值在栈顶），并设置为‘栈索引’处表成员的值。不触发元方法"),
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
		/*ccname*/	_WT("LUA_元赋值索引"),
		/*egname*/	_WT("lua_rawseti"),
		/*explain*/ _WT("从栈中弹出一个值，并设置为‘栈索引’处表的‘成员索引’处的值。不触发元方法"),
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
		/*ccname*/	_WT("LUA_元赋值指针"),
		/*egname*/	_WT("lua_rawsetp"),
		/*explain*/ _WT("从栈中弹出一个值，并设置为‘栈索引’处表的‘用户指针’处的值。不触发元方法"),
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
		/*ccname*/	_WT("LUA_置元表"),
		/*egname*/	_WT("lua_setmetatable"),
		/*explain*/ _WT("从栈中弹出一个值，并设置为‘栈索引’处对象的新元表。"),
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
		/*ccname*/	_WT("LUA_置用户值"),
		/*egname*/	_WT("lua_setuservalue"),
		/*explain*/ _WT("从栈中弹出一个值，并设置为‘栈索引’处用户数据的新值。"),
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

	//////////////////////////////////////////////////////////////////////////载入和运行操作

	{
		/*ccname*/	_WT("LUA_调用K"),
		/*egname*/	_WT("lua_callk"),
		/*explain*/ _WT("调用一个函数，调用之前将函数和参数压入栈，调用完毕后参数和函数都会弹出栈，并将指定数量的返回值压入栈。并且可以指定一个继续函数。"),
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
		/*ccname*/	_WT("LUA_调用"),
		/*egname*/	_WT("lua_call"),
		/*explain*/ _WT("调用一个函数，调用之前将函数和参数压入栈，调用完毕后参数和函数都会弹出栈，并将指定数量的返回值压入栈。"),
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
		/*ccname*/	_WT("LUA_安全调用K"),
		/*egname*/	_WT("lua_pcallK"),
		/*explain*/ _WT("调用一个函数，并允许设置一个错误处理闭包。调用之前将函数和参数压入栈，调用完毕后参数和函数都会弹出栈，并将指定数量的返回值压入栈。"),
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
		/*ccname*/	_WT("LUA_安全调用"),
		/*egname*/	_WT("lua_pcall"),
		/*explain*/ _WT("调用一个函数，并允许设置一个错误处理闭包。调用之前将函数和参数压入栈，调用完毕后参数和函数都会弹出栈，并将指定数量的返回值压入栈。"),
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
		/*ccname*/	_WT("LUA_载入"),
		/*egname*/	_WT("lua_load"),
		/*explain*/ _WT("载入一个lua脚本，但是不运行它，如果没有错误则作为函数压入到栈中，否则压入一个错误消息。返回 LUA_ 开头常量。"),
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
		/*ccname*/	_WT("LUA_导出"),
		/*egname*/	_WT("lua_dump"),
		/*explain*/ _WT("将栈顶的函数导出为二进制块，二进制块可以再次载入。不会弹出栈顶的函数。返回 LUA_ 开头常量。"),
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

	//////////////////////////////////////////////////////////////////////////协程操作

	{
		/*ccname*/	_WT("LUA_暂停"),
		/*egname*/	_WT("lua_yieldk"),
		/*explain*/ _WT("暂停正在运行的协程，并对 'LUA_恢复' 返回，返回 LUA_ 开头常量。\r\n参数‘返回值个数’是栈中将作为结果传递给 LUA_继续 值的数量。\r\n当协程再次恢复时，Lua调用给定的'继续函数'继续执行。此继续函数从前一个函数接收相同的栈，删除n个结果并替换为传递给 'LUA_恢复' 的参数。此外，继续函数接收传递给 LUA_暂停 的上下文值。"),
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
		/*ccname*/	_WT("LUA_恢复"),
		/*egname*/	_WT("lua_resume"),
		/*explain*/ _WT("在给定的线程中开始并恢复协程，返回 LUA_ 开头常量。\r\n要启动一个协程，你可以将主函数加入任何参数压入到线程栈; 然后调用 LUA_恢复。当协程暂停或完成其执行时，此调用将返回。 返回时，栈包含'LUA_暂停'传递的所有值。 如果协程暂停，则'LUA_恢复'返回LUA_YIELD，如果协程完成执行没有错误，则返回LUA_OK，如果出现错误，则返回错误代码。"),
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
		/*ccname*/	_WT("LUA_取状态"),
		/*egname*/	_WT("lua_status"),
		/*explain*/ _WT("返回线程状态， LUA_ 开头常量。"),
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
		/*ccname*/	_WT("LUA_是否暂停"),
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

	//////////////////////////////////////////////////////////////////////////垃圾回收

	{
		/*ccname*/	_WT("LUA_垃圾回收"),
		/*egname*/	_WT("lua_gc"),
		/*explain*/ _WT("控制垃圾回收器操作"),
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

	//////////////////////////////////////////////////////////////////////////杂项操作

	{
		/*ccname*/	_WT("LUA_置错误"),
		/*egname*/	_WT("lua_error"),
		/*explain*/ _WT("将栈顶的值设置为LUA错误"),
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
		/*ccname*/	_WT("LUA_下一个"),
		/*egname*/	_WT("lua_next"),
		/*explain*/ _WT("从栈中弹出一个键，然后压入一个键和一个值（这键值对是参数‘栈索引’指向的表的成员），如果表没有成员了，返回0"),
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
		/*ccname*/	_WT("LUA_连接"),
		/*egname*/	_WT("lua_concat"),
		/*explain*/ _WT("从栈中弹出n个值，然后连接起来，压入到栈中。如果n=1，不做任何处理，如果n=0，则压入空字符串。"),
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
		/*ccname*/	_WT("LUA_取长度"),
		/*egname*/	_WT("lua_len"),
		/*explain*/ _WT("将'栈索引'指定的值的长度，压入到栈中，可能会触发'length'元方法。"),
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
		/*ccname*/	_WT("LUA_文本到数值"),
		/*egname*/	_WT("lua_stringtonumber"),
		/*explain*/ _WT("将'文本'转换为数值，并压入到栈中，返回0表示失败，否则返回文本总长度(含\0)。"),
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
		/*ccname*/	_WT("LUA_取内存分配器"),
		/*egname*/	_WT("lua_getallocf"),
		/*explain*/ _WT("返回设置的内存分配回调函数。"),
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
		/*ccname*/	_WT("LUA_置内存分配器"),
		/*egname*/	_WT("lua_setallocf"),
		/*explain*/ _WT("设置的内存分配回调函数。"),
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

	//////////////////////////////////////////////////////////////////////////实用函数

	{
		/*ccname*/	_WT("LUA_取扩展空间"),
		/*egname*/	_WT("lua_getextraspace"),
		/*explain*/ _WT("返回与Lua状态关联的额外空间指针，大小是一个指针的大小"),
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
		/*ccname*/	_WT("LUA_到数值"),
		/*egname*/	_WT("lua_tonumber"),
		/*explain*/ _WT("将‘栈索引’位置的值转换为双精度小数型。"),
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
		/*ccname*/	_WT("LUA_到整数"),
		/*egname*/	_WT("lua_tointeger"),
		/*explain*/ _WT("将‘栈索引’位置的值转换为整数型。"),
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
		/*ccname*/	_WT("LUA_弹出"),
		/*egname*/	_WT("lua_pop"),
		/*explain*/ _WT("弹出指定数量的元素。"),
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
		/*ccname*/	_WT("LUA_新建表"),
		/*egname*/	_WT("lua_newtable"),
		/*explain*/ _WT("创建一个表，并压入到栈中。"),
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
		/*ccname*/	_WT("LUA_注册函数"),
		/*egname*/	_WT("lua_register"),
		/*explain*/ _WT("注册一个全局函数。"),
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
		/*ccname*/	_WT("LUA_压入函数"),
		/*egname*/	_WT("lua_pushcfunction"),
		/*explain*/ _WT("将一个本地函数压入到栈中。"),
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
		/*ccname*/	_WT("LUA_是否函数"),
		/*egname*/	_WT("lua_isfunction"),
		/*explain*/ _WT("返回‘栈索引’指向的值是否为函数。"),
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
		/*ccname*/	_WT("LUA_是否表"),
		/*egname*/	_WT("lua_istable"),
		/*explain*/ _WT("返回‘栈索引’指向的值是否为表。"),
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
		/*ccname*/	_WT("LUA_是否用户指针"),
		/*egname*/	_WT("lua_islightuserdata"),
		/*explain*/ _WT("返回‘栈索引’指向的值是否为用户指针。"),
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
		/*ccname*/	_WT("LUA_是否空"),
		/*egname*/	_WT("lua_isnil"),
		/*explain*/ _WT("返回‘栈索引’指向的值是否为空。"),
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
		/*ccname*/	_WT("LUA_是否逻辑型"),
		/*egname*/	_WT("lua_isboolean"),
		/*explain*/ _WT("返回‘栈索引’指向的值是否为逻辑型。"),
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
		/*ccname*/	_WT("LUA_是否线程"),
		/*egname*/	_WT("lua_isthread"),
		/*explain*/ _WT("返回‘栈索引’指向的值是否为线程。"),
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
		/*ccname*/	_WT("LUA_是否未知"),
		/*egname*/	_WT("lua_isnone"),
		/*explain*/ _WT("返回‘栈索引’指向的值是否未知。"),
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
		/*ccname*/	_WT("LUA_是否未知或空"),
		/*egname*/	_WT("lua_isnoneornil"),
		/*explain*/ _WT("返回‘栈索引’指向的值是否未知或空。"),
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
		/*ccname*/	_WT("LUA_压入全局表"),
		/*egname*/	_WT("lua_pushglobaltable"),
		/*explain*/ _WT("将全局环境表压入到栈中。"),
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
		/*ccname*/	_WT("LUA_插入"),
		/*egname*/	_WT("lua_insert"),
		/*explain*/ _WT("将栈顶的元素移动到参数‘栈索引’位置中，之前的‘栈索引’元素上移。"),
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
		/*ccname*/	_WT("LUA_移除"),
		/*egname*/	_WT("lua_remove"),
		/*explain*/ _WT("移除‘栈索引’位置的元素，上面的元素下移。"),
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
		/*ccname*/	_WT("LUA_替换"),
		/*egname*/	_WT("lua_replace"),
		/*explain*/ _WT("将栈顶的元素移动到‘栈索引’位置，并弹出栈顶元素。"),
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
		/*ccname*/	_WT("LUA_取上值索引"),
		/*egname*/	_WT("lua_upvalueindex"),
		/*explain*/ _WT("获取闭包上值的虚拟索引。"),
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

	//////////////////////////////////////////////////////////////////////////调试接口

	{
		/*ccname*/	_WT("LUA_取栈调试指针"),
		/*egname*/	_WT("lua_getstack"),
		/*explain*/ _WT("获取有关解释器运行时栈的信息的调试指针，成功返回这个指针，不使用后需要调用 LUA_释放调试指针（），失败返回0。"),
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
		/*ccname*/	_WT("LUA_释放调试指针"),
		/*egname*/	_WT("lua_freedebugptr"),
		/*explain*/ _WT("释放由 LUA_取栈调试指针() 返回的指针"),
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
		/*ccname*/	_WT("LUA_取调试信息"),
		/*egname*/	_WT("lua_getinfo"),
		/*explain*/ _WT("返回一个指定的函数或函数调用的调试信息结构体。\r\n用于获取一个函数的信息时，可以把这个函数压入栈，然后把 '文本掩码' 参数以字符 '>' 起头。（这个情况下，LUA_取调试信息 从栈顶上弹出函数。）\r\n'文本掩码' 参数中的每个字符都筛选出结构 LUA_调试信息 结构中一些域用于填充，或是把一个值压入栈：\r\n'n': 填充 name 及 namewhat 域；\r\n'S': 填充 source， short_src，linedefined，lastlinedefined，以及 what 域；\r\n'l': 填充 currentline 域；\r\n'u': 填充 nups 域；\r\n'f': 把正在运行中指定级别处函数压入堆栈；\r\n'L': 压一个 table 入栈，这个 table 中的整数索引用于描述函数中哪些行是有效行。 "),
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
		/*ccname*/	_WT("LUA_取变量"),
		/*egname*/	_WT("lua_getlocal"),
		/*explain*/ _WT("获得一个局部变量，将变量的值压入栈，并且返回变量名"),
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
		/*ccname*/	_WT("LUA_置变量"),
		/*egname*/	_WT("lua_setlocal"),
		/*explain*/ _WT("从栈顶弹出一个值赋值给变量，并且返回变量名。"),
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
		/*ccname*/	_WT("LUA_取上值"),
		/*egname*/	_WT("lua_getupvalue"),
		/*explain*/ _WT("获得一个上值，将上值的值压入栈，并且返回变量名。"),
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
		/*ccname*/	_WT("LUA_置上值"),
		/*egname*/	_WT("lua_getupvalue"),
		/*explain*/ _WT("从栈顶弹出一个值赋值给上值，并且返回变量名。"),
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
		/*ccname*/	_WT("LUA_取上值ID"),
		/*egname*/	_WT("lua_upvalueid"),
		/*explain*/ _WT("返回一个上值的ID，"),
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
		/*ccname*/	_WT("LUA_上值连接"),
		/*egname*/	_WT("lua_upvaluejoin"),
		/*explain*/ _WT("将‘函数索引1’指定的上值指向‘函数索引2’指定的上值。"),
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
		/*ccname*/	_WT("LUA_置钩子"),
		/*egname*/	_WT("lua_sethook"),
		/*explain*/ _WT("设置调试钩子回调函数。"),
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
		/*ccname*/	_WT("LUA_取钩子"),
		/*egname*/	_WT("lua_gethook"),
		/*explain*/ _WT("获取调试钩子回调函数。"),
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
		/*ccname*/	_WT("LUA_取钩子掩码"),
		/*egname*/	_WT("lua_gethookmask"),
		/*explain*/ _WT("获取调试钩子掩码，返回 LUA_HOOK 开头常量。"),
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
		/*ccname*/	_WT("LUA_取钩子数"),
		/*egname*/	_WT("lua_gethookcount"),
		/*explain*/ _WT("获取调试钩子数。"),
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
	//////////////////////////////////////////////////////////////////////////辅助库
	{
		/*ccname*/	_WT("LUAL_检查版本"),
		/*egname*/	_WT("luaL_checkversion"),
		/*explain*/ _WT("检查运行调用的核心，创建Lua状态的核心以及进行调用的代码是否都使用相同版本的Lua。"),
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
		/*ccname*/	_WT("LUAL_取元表字段"),
		/*egname*/	_WT("luaL_getmetafield"),
		/*explain*/ _WT("从'对象索引'中的元表获取指定字段，并压入到栈中，返回字段类型。"),
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
		/*ccname*/	_WT("LUAL_调用元方法"),
		/*egname*/	_WT("luaL_callmeta"),
		/*explain*/ _WT("如果'对象索引'处的对象具有metatable并且存在'字段名'，则此函数调用此字段将对象作为其唯一参数传递。 在这种情况下，此函数返回真，并将调用返回的值压入栈。 如果没有metatable或没有metamethod，则此函数返回假（不在栈上压入任何值）。"),
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
		/*ccname*/	_WT("LUAL_到文本"),
		/*egname*/	_WT("luaL_tolstring"),
		/*explain*/ _WT("将'栈索引'指定的值转为为字符串，压入栈，并由函数返回。如果值具有__tostring 元方法，则把值作为参数传递给元方法，并使用调用的结果。"),
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
		/*ccname*/	_WT("LUAL_参数错误"),
		/*egname*/	_WT("luaL_argerror"),
		/*explain*/ _WT("引发参数错误的报告。"),
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
		/*ccname*/	_WT("LUAL_检查文本"),
		/*egname*/	_WT("luaL_checklstring"),
		/*explain*/ _WT("检查函数参数是否为字符串并返回该字符串。"),
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
		/*ccname*/	_WT("LUAL_选择文本"),
		/*egname*/	_WT("luaL_optlstring"),
		/*explain*/ _WT("如果参数是字符串，则返回该字符串；如果不是字符串或为空，则返回参数‘默认值’，其他情况会引发错误。"),
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
		/*ccname*/	_WT("LUAL_检查数值"),
		/*egname*/	_WT("luaL_checknumber"),
		/*explain*/ _WT("检查函数参数是否为数值并返回该数值。"),
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
		/*ccname*/	_WT("LUAL_选择数值"),
		/*egname*/	_WT("luaL_optnumber"),
		/*explain*/ _WT("如果参数是数值，则返回该数值；如果不是数值或为空，则返回参数‘默认值’，其他情况会引发错误。"),
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
		/*ccname*/	_WT("LUAL_检查整数"),
		/*egname*/	_WT("luaL_checkinteger"),
		/*explain*/ _WT("检查函数参数是否为整数并返回该整数。"),
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
		/*ccname*/	_WT("LUAL_选择整数"),
		/*egname*/	_WT("luaL_optinteger"),
		/*explain*/ _WT("如果参数是整数，则返回该整数；如果不是整数或为空，则返回参数‘默认值’，其他情况会引发错误。"),
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
		/*ccname*/	_WT("LUAL_检查栈"),
		/*egname*/	_WT("luaL_checkstack"),
		/*explain*/ _WT("将栈增加到 栈顶+参数'大小' 个元素。如果无法增加到该大小，则引发错误，参数‘错误文本’是附件错误信息。"),
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
		/*ccname*/	_WT("LUAL_检查类型"),
		/*egname*/	_WT("luaL_checktype"),
		/*explain*/ _WT("检查参数是否具有指定类型。"),
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
		/*ccname*/	_WT("LUAL_检查任意类型"),
		/*egname*/	_WT("luaL_checkany"),
		/*explain*/ _WT("检查参数是否具有任意类型，包括nil。"),
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
		/*ccname*/	_WT("LUAL_新建元表"),
		/*egname*/	_WT("luaL_newmetatable"),
		/*explain*/ _WT("在注册表中新建元表，作为userdata的元表，如果'类型名'已经存在，则返回假。这两种情况都会把元表压入到栈中"),
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
		/*ccname*/	_WT("LUAL_置元表"),
		/*egname*/	_WT("luaL_setmetatable"),
		/*explain*/ _WT("将栈顶对象的元表设置为注册表中与类型名相关联的元表。"),
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
		/*ccname*/	_WT("LUAL_测试用户数据"),
		/*egname*/	_WT("luaL_testudata"),
		/*explain*/ _WT("检查用户数据是否指定的‘类型名’，并返回该用户数据指针。失败返回0"),
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
		/*ccname*/	_WT("LUAL_检查用户数据"),
		/*egname*/	_WT("luaL_checkudata"),
		/*explain*/ _WT("检查用户数据是否指定的‘类型名’，并返回该用户数据指针。失败会发生异常。"),
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
		/*ccname*/	_WT("LUAL_何处"),
		/*egname*/	_WT("luaL_where"),
		/*explain*/ _WT("压入一个字符串，该字符串包含调用栈指定等级中的位置。格式是：chunkname:currentline:"),
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
		/*ccname*/	_WT("LUAL_错误"),
		/*egname*/	_WT("luaL_error"),
		/*explain*/ _WT("引发一个错误。"),
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
		/*ccname*/	_WT("LUAL_检查选项"),
		/*egname*/	_WT("luaL_checkoption"),
		/*explain*/ _WT("检查参数是否为一个字符串，如果是则在参数‘选项’中搜索，并返回找到的索引。如果参数不是字符串或无法在‘选项’中找到，则引发异常。\r\n如果指定了参数‘默认值’，则当参数不是字符串或为nil的时候使用此默认值到‘选项’中查找。"),
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
		/*ccname*/	_WT("LUAL_引用"),
		/*egname*/	_WT("luaL_ref"),
		/*explain*/ _WT("在‘表栈索引’的表中创建并返回栈顶部对象的引用（并弹出栈顶的对象）。引用值是唯一的，可以看做是在表中的索引，如果栈顶部的对象是nil，则返回 LUA_空引用。"),
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
		/*ccname*/	_WT("LUAL_释放引用"),
		/*egname*/	_WT("luaL_unref"),
		/*explain*/ _WT("释放‘表栈索引’的表中释放引用对象，从表中删除，以便可以垃圾回收。"),
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
		/*ccname*/	_WT("LUAL_载入文件"),
		/*egname*/	_WT("luaL_loadfilex"),
		/*explain*/ _WT("从文件中载入一个lua脚本，但是不运行它，如果没有错误则作为函数压入到栈中，否则压入一个错误消息。返回 LUA_ 开头常量。"),
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
		/*ccname*/	_WT("LUAL_载入数据"),
		/*egname*/	_WT("luaL_loadbufferx"),
		/*explain*/ _WT("从内存中载入一个lua脚本，但是不运行它，如果没有错误则作为函数压入到栈中，否则压入一个错误消息。返回 LUA_ 开头常量。"),
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
		/*ccname*/	_WT("LUAL_载入文本"),
		/*egname*/	_WT("luaL_loadstring"),
		/*explain*/ _WT("从文本中载入一个lua脚本，但是不运行它，如果没有错误则作为函数压入到栈中，否则压入一个错误消息。返回 LUA_ 开头常量。"),
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
		/*ccname*/	_WT("LUAL_新建状态"),
		/*egname*/	_WT("luaL_newstate"),
		/*explain*/ _WT("创建一个主线程执行状态，成功返回lua_State指针，失败返回0。"),
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
		/*ccname*/	_WT("LUAL_取长度"),
		/*egname*/	_WT("luaL_len"),
		/*explain*/ _WT("返回指定'栈索引'的'length'值。"),
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
		/*ccname*/	_WT("LUAL_子文本替换"),
		/*egname*/	_WT("luaL_gsub"),
		/*explain*/ _WT("将替换后的文本压入到栈中，并返回它。"),
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
		/*ccname*/	_WT("LUAL_置函数数组"),
		/*egname*/	_WT("luaL_setfuncs"),
		/*explain*/ _WT("注册数组中的所有函数到栈顶位置的表中。"),
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
		/*ccname*/	_WT("LUAL_取子表"),
		/*egname*/	_WT("luaL_getsubtable"),
		/*explain*/ _WT("确保 t[表名] 的值是一个表，(t 是参数'栈索引'指向的表)，并将值压入到栈中。返回真表示找到之前的表，将表示创建的新表。"),
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
		/*ccname*/	_WT("LUAL_回溯"),
		/*egname*/	_WT("luaL_traceback"),
		/*explain*/ _WT("创建并压入回溯到 'Lua状态1' 的栈中。 如果参数‘消息’不为空，则会在回溯的开头附加。 '等级'参数指示启动回溯的级别。"),
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
		/*ccname*/	_WT("LUAL_需求"),
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
		/*ccname*/	_WT("LUAL_新建库表"),
		/*egname*/	_WT("luaL_newlibtable"),
		/*explain*/ _WT("创建一个表并压入到栈中。初始表大小已经经过优化。"),
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
		/*ccname*/	_WT("LUAL_新建库"),
		/*egname*/	_WT("luaL_newlib"),
		/*explain*/ _WT("创建一个表并压入到栈中，并且将函数注册到表中。"),
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
		/*ccname*/	_WT("LUAL_参数检查"),
		/*egname*/	_WT("luaL_argcheck"),
		/*explain*/ _WT("如果'条件'不等于真，则引发错误（luaL_argerror）。"),
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
		/*ccname*/	_WT("LUAL_取类型名"),
		/*egname*/	_WT("luaL_typename"),
		/*explain*/ _WT("返回‘栈索引’的值的类型名称。"),
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
		/*ccname*/	_WT("LUAL_执行文件"),
		/*egname*/	_WT("luaL_dofile"),
		/*explain*/ _WT("从文件加载并运行脚本。"),
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
		/*ccname*/	_WT("LUAL_执行文本"),
		/*egname*/	_WT("luaL_dostring"),
		/*explain*/ _WT("从文本加载并运行脚本。"),
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
		/*ccname*/	_WT("LUAL_取元表"),
		/*egname*/	_WT("luaL_getmetatable"),
		/*explain*/ _WT("从注册表中获取指定名称的元表，并压入到栈中。如果名称不存在则压入nil。返回压入值的类型。"),
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

	//////////////////////////////////////////////////////////////////////////标准库

	{
		/*ccname*/	_WT("LUAL_打开所有标准库"),
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

//////////////////////////////////////////////////////////////////////////状态操作
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

//////////////////////////////////////////////////////////////////////////基本栈操作
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

//////////////////////////////////////////////////////////////////////////访问函数（栈->易）

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

////////////////////////////////////////////////////////////////////////////比较和算术函数


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

////////////////////////////////////////////////////////////////////////////压栈操作

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
		case SDT_TEXT:    // 文本型和字节集型为一个指针,因此为四个字节.
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


//////////////////////////////////////////////////////////////////////////取值操作

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

//////////////////////////////////////////////////////////////////////////赋值函数

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

//////////////////////////////////////////////////////////////////////////载入和运行操作

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

//////////////////////////////////////////////////////////////////////////协程操作

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

//////////////////////////////////////////////////////////////////////////垃圾回收

EXTERN_C void elua_fn_lua_gc(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	pRetData->m_int = lua_gc(L, pArgInf[1].m_int, pArgInf[2].m_int);
}

//////////////////////////////////////////////////////////////////////////杂项操作

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

//////////////////////////////////////////////////////////////////////////实用函数

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

//////////////////////////////////////////////////////////////////////////调试接口

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

//////////////////////////////////////////////////////////////////////////辅助库

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

//////////////////////////////////////////////////////////////////////////标准库
EXTERN_C void elua_fn_luaL_openlibs(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	SETUP_LUA_STATE(pArgInf);
	luaL_openlibs(L);
}


#ifndef __E_STATIC_LIB
PFN_EXECUTE_CMD s_RunFunc[] =	// 索引应与s_CmdInfo中的命令定义顺序对应
{
	//状态操作
	elua_fn_lua_newstate,
	elua_fn_lua_close,
	elua_fn_lua_newthread,
	elua_fn_lua_atpanic,
	elua_fn_lua_version,
	//基本栈操作
	elua_fn_lua_absindex,
	elua_fn_lua_gettop,
	elua_fn_lua_settop,
	elua_fn_lua_pushvalue,
	elua_fn_lua_rotate,
	elua_fn_lua_copy,
	elua_fn_lua_checkstack,
	elua_fn_lua_xmove,
	//访问函数
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
	//比较和算术函数
	elua_fn_lua_arith,
	elua_fn_lua_rawequal,
	elua_fn_lua_compare,
	//压栈操作
	elua_fn_lua_pushnil,
	elua_fn_lua_pushnumber,
	elua_fn_lua_pushinteger,
	elua_fn_lua_pushlstring,
	elua_fn_lua_pushvfstring,
	elua_fn_lua_pushcclosure,
	elua_fn_lua_pushboolean,
	elua_fn_lua_pushlightuserdata,
	elua_fn_lua_pushthread,
	//取值操作
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
	//赋值操作
	elua_fn_lua_setglobal,
	elua_fn_lua_settable,
	elua_fn_lua_setfield,
	elua_fn_lua_seti,
	elua_fn_lua_rawset,
	elua_fn_lua_rawseti,
	elua_fn_lua_rawsetp,
	elua_fn_lua_setmetatable,
	elua_fn_lua_setuservalue,
	//载入和运行操作
	elua_fn_lua_callk,
	elua_fn_lua_call,
	elua_fn_lua_pcallk,
	elua_fn_lua_pcall,
	elua_fn_lua_load,
	elua_fn_lua_dump,
	//协程操作
	elua_fn_lua_yieldk,
	elua_fn_lua_resume,
	elua_fn_lua_status,
	elua_fn_lua_isyieldable,
	//垃圾回收
	elua_fn_lua_gc,
	//杂项操作
	elua_fn_lua_error,
	elua_fn_lua_next,
	elua_fn_lua_concat,
	elua_fn_lua_len,
	elua_fn_lua_stringtonumber,
	elua_fn_lua_getallocf,
	elua_fn_lua_setallocf,
	//实用函数(宏)
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
	//调试接口
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
	//辅助库
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
	//标准库
		elua_fn_luaL_openlibs
};

static const char* const g_CmdNames[] =
{
	//状态操作
	"elua_fn_lua_newstate",
	"elua_fn_lua_close",
	"elua_fn_lua_newthread",
	"elua_fn_lua_atpanic",
	"elua_fn_lua_version",
	//基本栈操作
	"elua_fn_lua_absindex",
	"elua_fn_lua_gettop",
	"elua_fn_lua_settop",
	"elua_fn_lua_pushvalue",
	"elua_fn_lua_rotate",
	"elua_fn_lua_copy",
	"elua_fn_lua_checkstack",
	"elua_fn_lua_xmove",
	//访问函数
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
	//比较和算术函数
	"elua_fn_lua_arith",
	"elua_fn_lua_rawequal",
	"elua_fn_lua_compare",
	//压栈操作
	"elua_fn_lua_pushnil",
	"elua_fn_lua_pushnumber",
	"elua_fn_lua_pushinteger",
	"elua_fn_lua_pushlstring",
	"elua_fn_lua_pushvfstring",
	"elua_fn_lua_pushcclosure",
	"elua_fn_lua_pushboolean",
	"elua_fn_lua_pushlightuserdata",
	"elua_fn_lua_pushthread",
	//取值操作
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
	//赋值操作
	"elua_fn_lua_setglobal",
	"elua_fn_lua_settable",
	"elua_fn_lua_setfield",
	"elua_fn_lua_seti",
	"elua_fn_lua_rawset",
	"elua_fn_lua_rawseti",
	"elua_fn_lua_rawsetp",
	"elua_fn_lua_setmetatable",
	"elua_fn_lua_setuservalue",
	//载入和运行操作
	"elua_fn_lua_callk",
	"elua_fn_lua_call",
	"elua_fn_lua_pcallk",
	"elua_fn_lua_pcall",
	"elua_fn_lua_load",
	"elua_fn_lua_dump",
	//协程操作
	"elua_fn_lua_yieldk",
	"elua_fn_lua_resume",
	"elua_fn_lua_status",
	"elua_fn_lua_isyieldable",
	//垃圾回收
	"elua_fn_lua_gc",
	//杂项操作
	"elua_fn_lua_error",
	"elua_fn_lua_next",
	"elua_fn_lua_concat",
	"elua_fn_lua_len",
	"elua_fn_lua_stringtonumber",
	"elua_fn_lua_getallocf",
	"elua_fn_lua_setallocf",
	//实用函数（宏）
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
	//调试接口
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
	//辅助库
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
	//标准库
		"elua_fn_luaL_openlibs"
};

#endif


/************************************************************************/
/* 数据类型定义
/************************************************************************/

#ifndef __E_STATIC_LIB


LIB_DATA_TYPE_ELEMENT s_dt_element_lua_debug[] =
{
	/*{ 成员类型 ,数组成员 , 中文名称 ,英文名称 ,成员解释 ,成员状态 ,默认值}*/
	{ SDT_INT, NULL,_WT("事件"), _WT("event"), _WT(""), 0, 0 },
	{ SDT_TEXT, NULL,_WT("名称"), _WT("name"), _WT(""), 0, 0 },
	{ SDT_TEXT, NULL,_WT("名称属于"), _WT("namewhat"), _WT("可以是‘global’, ‘local’, ‘method’, ‘field’, ‘upvalue’, 或 '' "), 0, 0 },
	{ SDT_TEXT, NULL,_WT("函数属于"), _WT("what"), _WT("如果函数是一个 Lua 函数，则为 'Lua' ； 如果是一个本地函数，'C'； 如果它是一个 chunk 的主体部分，则为 'main'； 如果是一个作了尾调用的函数，则为 'tail'。别的情况下，Lua 没有关于函数的别的信息。"), 0, 0 },
	{ SDT_TEXT, NULL,_WT("源"), _WT("source"), _WT("如果函数是定义在一个字符串中，source 就是这个字符串。 如果函数定义在一个文件中， source 是一个以 '@' 开头的文件名。"), 0, 0 },
	{ SDT_INT, NULL,_WT("当前行"), _WT("currentline"), _WT("给定函数正在执行的那一行。 "), 0, 0 },
	{ SDT_INT, NULL,_WT("定义开始行"), _WT("linedefined"), _WT("函数定义开始处的行号。 "), 0, 0 },
	{ SDT_INT, NULL,_WT("定义结束行"), _WT("lastlinedefined"), _WT("函数定义结束处的行号。 "), 0, 0 },
	{ SDT_SHORT, NULL,_WT("用户值数量"), _WT("nups"), _WT("函数的 upvalue 的个数。"), 0, 0 },
	{ SDT_SHORT, NULL,_WT("参数数量"), _WT("nparams"), _WT("函数的 参数 的个数。"), 0, 0 },
	{ SDT_BOOL, NULL,_WT("是否可变参数"), _WT("isvararg"), _WT(""), 0, 0 },
	{ SDT_BOOL, NULL,_WT("是否尾调用"), _WT("istailcall"), _WT(""), 0, 0 },
	{ SDT_TEXT, NULL,_WT("短源"), _WT("short_src"), _WT("可打印版本的源"), 0, 0 },
};
LIB_DATA_TYPE_ELEMENT s_dt_element_lua_reg[] =
{
	/*{ 成员类型 ,数组成员 , 中文名称 ,英文名称 ,成员解释 ,成员状态 ,默认值}*/
	{ SDT_TEXT, NULL,_WT("名称"), _WT("name"), _WT("函数名"), 0, 0 },
	{ SDT_SUB_PTR, NULL,_WT("函数"), _WT("func"), _WT("返回值：整数型（整数型 Lua状态）"), 0, 0 },
};

static LIB_DATA_TYPE_INFO s_DataTypes[] =
{
	/* { 中文名称, 英文名称, 数据描述, 索引数量, 命令索引, 对象状态, 图标索引, 事件数量, 事件指针, 属性数量, 属性指针, 界面指针, 元素数量, 元素指针 } */
	{ _WT("LUA_调试信息"), _WT("lua_debug"), _WT(""), 0, NULL, NULL, 0, 0, NULL, 0, NULL, NULL, sizeof(s_dt_element_lua_debug) / sizeof(s_dt_element_lua_debug[0]), s_dt_element_lua_debug },
	{ _WT("LUA_注册"), _WT("lua_reg"), _WT(""), 0, NULL, NULL, 0, 0, NULL, 0, NULL, NULL, sizeof(s_dt_element_lua_reg) / sizeof(s_dt_element_lua_reg[0]), s_dt_element_lua_reg },
};
#endif

EXTERN_C INT WINAPI  elua_ProcessNotifyLib(INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
#ifndef __E_STATIC_LIB
	if (nMsg == NL_GET_CMD_FUNC_NAMES) // 返回所有命令实现函数的的函数名称数组(char*[]), 支持静态编译的动态库必须处理
		return (INT)g_CmdNames;
	else if (nMsg == NL_GET_NOTIFY_LIB_FUNC_NAME) // 返回处理系统通知的函数名称(PFN_NOTIFY_LIB函数名称), 支持静态编译的动态库必须处理
		return (INT)"elua_ProcessNotifyLib";
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
		
		/*pfnNotify*/				elua_ProcessNotifyLib,
		
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