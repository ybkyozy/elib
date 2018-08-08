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
	1,2
};
INT s_unzipCommandIndexs[] =
{
	1,2
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

// 参数
ARG_INFO s_arg_create_zip_from_file[]
{
	/* { 参数名称, 参数描述, 图像索引, 图像数量, 参数类型(参见SDT_), 默认数值, 参数类别(参见AS_) } */
	{ _WT("文件名"), _WT("压缩包文件名"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("密码"), _WT("压缩包密码"),0,0, SDT_TEXT, 0, AS_HAS_DEFAULT_VALUE },
};

// 命令信息
static CMD_INFO s_CmdInfo[] =
{
	/* { 中文名称, 英文名称, 对象描述, 所属类别(-1是数据类型的方法), 命令状态(CT_), 返回类型(SDT_), 此值保留, 对象等级(LVL_), 图像索引, 图像数量, 参数个数, 参数信息 } */
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
	

}