// EZipUtils.cpp: 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "../../elib_sdk/lib2.h"
#include "../../elib_sdk/lang.h"
#include "../../elib_sdk/fnshare.h"
#include "../../elib_sdk/fnshare.cpp"
#include "zip_utils_src/zip.h"
#include "zip_utils_src/unzip.h"

#include "EZipUtils.h"

/************************************************************************/
/* 常量定义
/************************************************************************/
#ifndef __E_STATIC_LIB
LIB_CONST_INFO s_ConstInfo[] =
{

{ _WT("ZR_OK"), _WT("ZR_OK"), NULL, LVL_SIMPLE, CT_NUM, NULL, ZR_OK },
{ _WT("ZR_RECENT"), _WT("ZR_RECENT"), NULL, LVL_SIMPLE, CT_NUM, NULL, ZR_RECENT },
{ _WT("ZR_GENMASK"), _WT("ZR_GENMASK"), NULL, LVL_SIMPLE, CT_NUM, NULL, ZR_GENMASK },
{ _WT("ZR_NODUPH"), _WT("ZR_NODUPH"), NULL, LVL_SIMPLE, CT_NUM, NULL, ZR_NODUPH },
{ _WT("ZR_NOFILE"), _WT("ZR_NOFILE"), NULL, LVL_SIMPLE, CT_NUM, NULL, ZR_NOFILE },
{ _WT("ZR_NOALLOC"), _WT("ZR_NOALLOC"), NULL, LVL_SIMPLE, CT_NUM, NULL, ZR_NOALLOC },
{ _WT("ZR_WRITE"), _WT("ZR_WRITE"), NULL, LVL_SIMPLE, CT_NUM, NULL, ZR_WRITE },
{ _WT("ZR_NOTFOUND"), _WT("ZR_NOTFOUND"), NULL, LVL_SIMPLE, CT_NUM, NULL, ZR_NOTFOUND },
{ _WT("ZR_MORE"), _WT("ZR_MORE"), NULL, LVL_SIMPLE, CT_NUM, NULL, ZR_MORE },
{ _WT("ZR_CORRUPT"), _WT("ZR_CORRUPT"), NULL, LVL_SIMPLE, CT_NUM, NULL, ZR_CORRUPT },
{ _WT("ZR_READ"), _WT("ZR_READ"), NULL, LVL_SIMPLE, CT_NUM, NULL, ZR_READ },
{ _WT("ZR_CALLERMASK"), _WT("ZR_CALLERMASK"), NULL, LVL_SIMPLE, CT_NUM, NULL, ZR_CALLERMASK },
{ _WT("ZR_ARGS"), _WT("ZR_ARGS"), NULL, LVL_SIMPLE, CT_NUM, NULL, ZR_ARGS },
{ _WT("ZR_NOTMMAP"), _WT("ZR_NOTMMAP"), NULL, LVL_SIMPLE, CT_NUM, NULL, ZR_NOTMMAP },
{ _WT("ZR_MEMSIZE"), _WT("ZR_MEMSIZE"), NULL, LVL_SIMPLE, CT_NUM, NULL, ZR_MEMSIZE },
{ _WT("ZR_FAILED"), _WT("ZR_FAILED"), NULL, LVL_SIMPLE, CT_NUM, NULL, ZR_FAILED },
{ _WT("ZR_ENDED"), _WT("ZR_ENDED"), NULL, LVL_SIMPLE, CT_NUM, NULL, ZR_ENDED },
{ _WT("ZR_MISSIZE"), _WT("ZR_MISSIZE"), NULL, LVL_SIMPLE, CT_NUM, NULL, ZR_MISSIZE },
{ _WT("ZR_PARTIALUNZ"), _WT("ZR_PARTIALUNZ"), NULL, LVL_SIMPLE, CT_NUM, NULL, ZR_PARTIALUNZ },
{ _WT("ZR_ZMODE"), _WT("ZR_ZMODE"), NULL, LVL_SIMPLE, CT_NUM, NULL, ZR_ZMODE },
{ _WT("ZR_BUGMASK"), _WT("ZR_BUGMASK"), NULL, LVL_SIMPLE, CT_NUM, NULL, ZR_BUGMASK },
{ _WT("ZR_NOTINITED"), _WT("ZR_NOTINITED"), NULL, LVL_SIMPLE, CT_NUM, NULL, ZR_NOTINITED },
{ _WT("ZR_SEEK"), _WT("ZR_SEEK"), NULL, LVL_SIMPLE, CT_NUM, NULL, ZR_SEEK },
{ _WT("ZR_NOCHANGE"), _WT("ZR_NOCHANGE"), NULL, LVL_SIMPLE, CT_NUM, NULL, ZR_NOCHANGE },
{ _WT("ZR_FLATE"), _WT("ZR_FLATE"), NULL, LVL_SIMPLE, CT_NUM, NULL, ZR_FLATE },

};

#endif

/************************************************************************/
/* 数据类型定义
/************************************************************************/
#ifndef __E_STATIC_LIB
LIB_DATA_TYPE_ELEMENT s_zip[]
{
	/*{ 成员类型 ,数组成员 , 中文名称 ,英文名称 ,成员解释 ,成员状态 ,默认值}*/
	{ SDT_INT, NULL,_WT("hZip"), _WT("hZip"), NULL, LES_HIDED, 0 }
};

INT s_zipCommandIndexs[] =
{
	0,1,2,3
};
INT s_unzipCommandIndexs[] =
{
	0
};
static LIB_DATA_TYPE_INFO s_DataTypes[] =
{
	/* { 中文名称, 英文名称, 数据描述, 索引数量, 命令索引, 对象状态, 图标索引, 事件数量, 事件指针, 属性数量, 属性指针, 界面指针, 元素数量, 元素指针 } */
	{ _WT("ZIP压缩"), _WT("zip"), _WT("压缩ZIP"), sizeof(s_zipCommandIndexs) / sizeof(s_zipCommandIndexs[0]), s_zipCommandIndexs, NULL, 0, 0, NULL, 0, NULL, NULL, sizeof(s_zip) / sizeof(s_zip[0]), s_zip },
	{ _WT("ZIP解压"), _WT("unzip"), _WT("解压ZIP"), sizeof(s_unzipCommandIndexs) / sizeof(s_unzipCommandIndexs[0]), s_unzipCommandIndexs, NULL, 0, 0, NULL, 0, NULL, NULL, sizeof(s_zip) / sizeof(s_zip[0]), s_zip },
};
#endif

/************************************************************************/
/* 命令定义
/************************************************************************/

// 参数 【创建压缩包自文件】
ARG_INFO s_arg_create_zip_from_file[]
{
	/* { 参数名称, 参数描述, 图像索引, 图像数量, 参数类型(参见SDT_), 默认数值, 参数类别(参见AS_) } */
	{ _WT("文件名"), _WT("压缩包文件名"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("密码"), _WT("压缩包密码"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
// 参数 【添加项目】
ARG_INFO s_arg_add_item[]
{
	/* { 参数名称, 参数描述, 图像索引, 图像数量, 参数类型(参见SDT_), 默认数值, 参数类别(参见AS_) } */
	{ _WT("项目名"), _WT("压缩内的项目名"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("文件名"), _WT("要压缩的文件路径"),0,0, SDT_TEXT, 0, NULL },
};


// 命令信息
static CMD_INFO s_CmdInfo[] =
{
	/* { 中文名称, 英文名称, 对象描述, 所属类别(-1是数据类型的方法), 命令状态(CT_), 返回类型(SDT_), 此值保留, 对象等级(LVL_), 图像索引, 图像数量, 参数个数, 参数信息 } */
	{
		/*ccname*/	_WT("析构函数"),
		/*egname*/	_WT("ZipDestruct"),
		/*explain*/	NULL,
		/*category*/-1,
		/*state*/	CT_IS_OBJ_FREE_CMD | CT_IS_HIDED,
		/*ret*/		_SDT_NULL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/0,
		/*arg lp*/	NULL,
	},
	{
		/*ccname*/	_WT("创建自文件"),
		/*egname*/	_WT("CreateZipFile"),
		/*explain*/	_WT("创建一个压缩包自一个文件名"),
		/*category*/-1,
		/*state*/	NULL,
		/*ret*/		SDT_BOOL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_create_zip_from_file) / sizeof(s_arg_create_zip_from_file[0]),
		/*arg lp*/	s_arg_create_zip_from_file,
	},
	{
		/*ccname*/	_WT("添加项目"),
		/*egname*/	_WT("AddItem"),
		/*explain*/	_WT("向压缩包添加项目，返回\"ZR_\"开头常量"),
		/*category*/-1,
		/*state*/	NULL,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_add_item) / sizeof(s_arg_add_item[0]),
		/*arg lp*/	s_arg_add_item,
	},
	{
		/*ccname*/	_WT("关闭"),
		/*egname*/	_WT("Close"),
		/*explain*/	_WT("结束操作，返回\"ZR_\"开头常量"),
		/*category*/-1,
		/*state*/	NULL,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/0,
		/*arg lp*/	NULL,
	},
};

// 命令实现
EXTERN_C void EZipUtils_fnZipDestruct(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	HZIP hZip = ((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip;
	if (hZip)
	{
		CloseZip(hZip);
		((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip = NULL;
	}
	return;
}
EXTERN_C void EZipUtils_fnZipCreateFromFile(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	HZIP hZip = ((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip;
	if (hZip)
	{
		CloseZip(hZip);
	}
	hZip = CreateZip(pArgInf[1].m_pText, pArgInf[2].m_pText);
	((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip = hZip;
	pRetData->m_bool = hZip != NULL;
	return;
}
EXTERN_C void EZipUtils_fnZipAddItem(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	HZIP hZip = ((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip;
	if (hZip)
	{
		pRetData->m_int = ZipAdd(hZip, pArgInf[1].m_pText, pArgInf[2].m_pText);
	}
	return;
}
EXTERN_C void EZipUtils_fnZipClose(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	HZIP hZip = ((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip;
	if (hZip)
	{
		CloseZip(hZip);
		SetIntByIndex(pArgInf, 0, 0);
	}
	return;
}

//*** 命令实现信息:
#ifndef __E_STATIC_LIB
PFN_EXECUTE_CMD s_RunFunc[] =	// 索引应与s_CmdInfo中的命令定义顺序对应
{
	EZipUtils_fnZipDestruct,
	EZipUtils_fnZipCreateFromFile,
	EZipUtils_fnZipAddItem,
	EZipUtils_fnZipClose
};

static const char* const g_CmdNames[] =
{
	"EZipUtils_fnZipDestruct",
	"EZipUtils_fnZipCreateFromFile",
	"EZipUtils_fnZipAddItem",
	"EZipUtils_fnZipClose"
};
#endif


EXTERN_C INT WINAPI  EZipUtils_ProcessNotifyLib(INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
#ifndef __E_STATIC_LIB
	if (nMsg == NL_GET_CMD_FUNC_NAMES) // 返回所有命令实现函数的的函数名称数组(char*[]), 支持静态编译的动态库必须处理
		return (INT)g_CmdNames;
	else if (nMsg == NL_GET_NOTIFY_LIB_FUNC_NAME) // 返回处理系统通知的函数名称(PFN_NOTIFY_LIB函数名称), 支持静态编译的动态库必须处理
		return (INT)"EZipUtils_ProcessNotifyLib";
	else if (nMsg == NL_GET_DEPENDENT_LIBS) return (INT)NULL;
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
						sizeof(s_DataTypes) / sizeof(s_DataTypes),
						s_DataTypes,
						//类别说明
#ifndef __COMPILE_FNR
						/*CategoryCount*/   0,			// 加了类别需加此值。
						/*category*/       	NULL,			// 类别说明表每项为一字符串,前四位数字表示图象索引号(从1开始,0无).
	/*CmdCount*/        sizeof(s_CmdInfo) / sizeof(s_ConstInfo[0]),
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

						/*pfnNotify*/				EZipUtils_ProcessNotifyLib,

						/*pfnRunSuperTemplate*/		NULL,
						/*szzSuperTemplateInfo*/	NULL,

#ifndef __COMPILE_FNR
						/*nLibConstCount*/			sizeof(s_ConstInfo) / sizeof(s_ConstInfo[0]),
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