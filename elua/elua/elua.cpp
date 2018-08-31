// esquirrel3.cpp : Defines the entry point for the DLL application.
//

#include "elua.h"

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

// 命令信息
static CMD_INFO s_CmdInfo[] =
{
	/* { 中文名称, 英文名称, 对象描述, 所属类别(-1是数据类型的方法), 命令状态(CT_), 返回类型(SDT_), 此值保留, 对象等级(LVL_), 图像索引, 图像数量, 参数个数, 参数信息 } */

	//////////////////////////////////////////////////////////////////////////状态操作
	{
		/*ccname*/	_WT("LUA_新建"),
		/*egname*/	_WT("lua_newstate"),
		/*explain*/ _WT("创建一个新线程执行状态，成功返回lua_State指针，失败返回0"),
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

#ifndef __E_STATIC_LIB
PFN_EXECUTE_CMD s_RunFunc[] =	// 索引应与s_CmdInfo中的命令定义顺序对应
{
	elua_fn_lua_newstate,
	elua_fn_lua_close,
	elua_fn_lua_newthread,
	elua_fn_lua_atpanic,
	elua_fn_lua_version,
	elua_fn_lua_absindex,
	elua_fn_lua_gettop,
	elua_fn_lua_settop,
	elua_fn_lua_pushvalue,
	elua_fn_lua_rotate,
	elua_fn_lua_copy,
	elua_fn_lua_checkstack,
	elua_fn_lua_xmove,
};

static const char* const g_CmdNames[] =
{
	"elua_fn_lua_newstate",
	"elua_fn_lua_close",
	"elua_fn_lua_newthread",
	"elua_fn_lua_atpanic",
	"elua_fn_lua_version",
	"elua_fn_lua_absindex",
	"elua_fn_lua_gettop",
	"elua_fn_lua_settop",
	"elua_fn_lua_pushvalue",
	"elua_fn_lua_rotate",
	"elua_fn_lua_copy",
	"elua_fn_lua_checkstack",
	"elua_fn_lua_xmove",
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