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

	{ _WT("LUA操作符_加"), _WT("LUA_OPADD +"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPADD },
	{ _WT("LUA操作符_减"), _WT("LUA_OPSUB -"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPSUB },
	{ _WT("LUA操作符_乘"), _WT("LUA_OPMUL *"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPMUL },
	{ _WT("LUA操作符_求余"), _WT("LUA_OPMOD %"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPMOD },
	{ _WT("LUA操作符_求次方"), _WT("LUA_OPPOW ^"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPPOW },
	{ _WT("LUA操作符_除"), _WT("LUA_OPDIV /"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPDIV },
	{ _WT("LUA操作符_整除"), _WT("LUA_OPIDIV //"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPIDIV },
	{ _WT("LUA操作符_位与"), _WT("LUA_OPBAND &"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPBAND },
	{ _WT("LUA操作符_位或"), _WT("LUA_OPBOR |"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPBOR },
	{ _WT("LUA操作符_位异或"), _WT("LUA_OPBXOR ~"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPBXOR },
	{ _WT("LUA操作符_左移"), _WT("LUA_OPSHL <<"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPSHL },
	{ _WT("LUA操作符_右移"), _WT("LUA_OPSHR >>"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPSHR },
	{ _WT("LUA操作符_负"), _WT("LUA_OPUNM -"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPUNM },
	{ _WT("LUA操作符_位取反"), _WT("LUA_OPBNOT ~"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPBNOT },

	{ _WT("LUA比较_相等"), _WT("LUA_OPEQ ="), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPEQ },
	{ _WT("LUA比较_小于"), _WT("LUA_OPLT <"), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPLT },
	{ _WT("LUA比较_小于等于"), _WT("LUA_OPLE <="), NULL, LVL_SIMPLE, CT_NUM, NULL, LUA_OPLE },
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
	{ _WT("用户值数量"), _WT("如果这个参数>0 (但是不能>256)，则会从栈中弹出n个值作为闭包的用户值，当本地函数被调用时可以获取这些值。"),0,0, SDT_INT, 0, AS_HAS_DEFAULT_VALUE },
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
	{ _WT("模式"), _WT("binary、text ?"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
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
		/*ccname*/	_WT("LUA_压入本地函数"),
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
		/*egname*/	_WT("lua_pcall"),
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
		/*ccname*/	_WT("LUA_载入"),
		/*egname*/	_WT("lua_load"),
		/*explain*/ _WT("载入一个lua脚本，但是不允许它，如果没有错误则作为函数压入到栈中，否则压入一个错误消息。返回 LUA_ 开头常量。"),
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
		/*explain*/ _WT("暂停正在运行的协同程序，并对 'LUA_恢复' 返回，返回 LUA_ 开头常量。\r\n参数‘返回值个数’是栈中将作为结果传递给LUA_继续值的数量。\r\n当协同程序再次恢复时，Lua调用给定的'继续函数'继续执行。此继续函数从前一个函数接收相同的栈，删除n个结果并替换为传递给 'LUA_恢复' 的参数。此外，继续函数接收传递给 LUA_暂停 的上下文值。"),
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
		/*explain*/ _WT("在给定的线程中开始并恢复协程，返回 LUA_ 开头常量。\r\n要启动一个协程，你可以将主函数加入任何参数压入到线程栈; 然后调用 LUA_恢复。当协同程序暂停或完成其执行时，此调用将返回。 返回时，栈包含'LUA_暂停'传递的所有值，或者包含body函数返回的所有值。 如果协程暂停，则'LUA_恢复'返回LUA_YIELD，如果协程完成执行没有错误，则返回LUA_OK，如果出现错误，则返回错误代码。"),
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
};

#endif


/************************************************************************/
/* 数据类型定义
/************************************************************************/

//#ifndef __E_STATIC_LIB
//
//
//LIB_DATA_TYPE_ELEMENT s_dt_element[] =
//{
//	/*{ 成员类型 ,数组成员 , 中文名称 ,英文名称 ,成员解释 ,成员状态 ,默认值}*/
//	//{ SDT_INT, NULL,_WT("test"), _WT("test"), _WT("test"), 0, 0 },
//
//};
//
//
//static LIB_DATA_TYPE_INFO s_DataTypes[] =
//{
//	/* { 中文名称, 英文名称, 数据描述, 索引数量, 命令索引, 对象状态, 图标索引, 事件数量, 事件指针, 属性数量, 属性指针, 界面指针, 元素数量, 元素指针 } */
//	//{ _WT("testinfo"), _WT("testinfo"), _WT("testinfo"), 0, NULL, NULL, 0, 0, NULL, 0, NULL, NULL, sizeof(s_dt_element) / sizeof(s_dt_element[0]), s_dt_element },
//};
//#endif

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