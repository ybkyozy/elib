// EZipUtils.cpp: 定义 DLL 应用程序的导出函数。
//

#include "elib_sdk/lib2.h"
#include "elib_sdk/lang.h"
#include "elib_sdk/fnshare.h"
#include "elib_sdk/fnshare.cpp"

#include "zip_utils_src/zip.h"
#include "zip_utils_src/unzip.h"

#include "EZipUtils.h"

/************************************************************************/
/* 常量定义
/************************************************************************/
#ifndef __E_STATIC_LIB
LIB_CONST_INFO s_ConstInfo[] =
{
	/* { 中文名称, 英文名称, 常量布局, 常量等级(LVL_), 参数类型(CT_), 文本内容, 数值内容 }   只有两种数据类型*/
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


#ifndef __E_STATIC_LIB
/************************************************************************/
/* 命令定义
/************************************************************************/

// 参数 【创建压缩包自文件】
ARG_INFO s_arg_create_zip_from_file[] =
{
	/* { 参数名称, 参数描述, 图像索引, 图像数量, 参数类型(参见SDT_), 默认数值, 参数类别(参见AS_) } */
	{ _WT("文件名"), _WT("压缩包文件名"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("密码"), _WT("压缩包密码"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
// 参数 【创建压缩包自内存】
ARG_INFO s_arg_create_zip_from_memroy[] =
{
	/* { 参数名称, 参数描述, 图像索引, 图像数量, 参数类型(参见SDT_), 默认数值, 参数类别(参见AS_) } */
	{ _WT("缓冲区地址"), _WT("如果为0则在内存页面文件中创建"),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
	{ _WT("大小"), _WT("内存大小"),0,0, SDT_INT, 0, 0 },
	{ _WT("密码"), _WT("压缩包密码"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
// 参数 【创建压缩包自句柄】
ARG_INFO s_arg_create_zip_from_handle[] =
{
	/* { 参数名称, 参数描述, 图像索引, 图像数量, 参数类型(参见SDT_), 默认数值, 参数类别(参见AS_) } */
	{ _WT("句柄"), _WT("文件句柄或管道句柄"),0,0, SDT_INT, 0, NULL },
	{ _WT("密码"), _WT("压缩包密码"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
// 参数 【添加项目】
ARG_INFO s_arg_add_item[] =
{
	/* { 参数名称, 参数描述, 图像索引, 图像数量, 参数类型(参见SDT_), 默认数值, 参数类别(参见AS_) } */
	{ _WT("项目名"), _WT("压缩内的项目名"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("文件名"), _WT("要压缩的文件路径"),0,0, SDT_TEXT, 0, NULL },
};
// 参数 【添加项目自内存】
ARG_INFO s_arg_add_item_memory[] =
{
	/* { 参数名称, 参数描述, 图像索引, 图像数量, 参数类型(参见SDT_), 默认数值, 参数类别(参见AS_) } */
	{ _WT("项目名"), _WT("压缩内的项目名"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("内存数据"), _WT("要压缩的内存数据"),0,0, SDT_BIN, 0, NULL },
};
// 参数 【添加项目自句柄】
ARG_INFO s_arg_add_item_handle[] =
{
	/* { 参数名称, 参数描述, 图像索引, 图像数量, 参数类型(参见SDT_), 默认数值, 参数类别(参见AS_) } */
	{ _WT("项目名"), _WT("压缩内的项目名"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("句柄"), _WT("文件句柄或管道句柄"),0,0, SDT_INT, 0, NULL },
	{ _WT("长度"), _WT(""),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
// 参数 【添加目录】
ARG_INFO s_arg_add_folder[] =
{
	/* { 参数名称, 参数描述, 图像索引, 图像数量, 参数类型(参见SDT_), 默认数值, 参数类别(参见AS_) } */
	{ _WT("目录名"), _WT("压缩内的目录名"),0,0, SDT_TEXT, 0, NULL }
};

// 参数 【打开自内存】
ARG_INFO s_arg_unzip_open_momory[] =
{
	/* { 参数名称, 参数描述, 图像索引, 图像数量, 参数类型(参见SDT_), 默认数值, 参数类别(参见AS_) } */
	{ _WT("ZIP数据"), _WT("压缩包字节集数据"),0,0, SDT_BIN, 0, NULL },
	{ _WT("密码"), _WT("压缩包密码"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
// 参数 【打开自句柄】
ARG_INFO s_arg_unzip_open_handle[] =
{
	/* { 参数名称, 参数描述, 图像索引, 图像数量, 参数类型(参见SDT_), 默认数值, 参数类别(参见AS_) } */
	{ _WT("句柄"), _WT("文件句柄或管道句柄"),0,0, SDT_INT, 0, NULL },
	{ _WT("密码"), _WT("压缩包密码"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
// 参数 【取项目信息】
ARG_INFO s_arg_unzip_get_item[] =
{
	/* { 参数名称, 参数描述, 图像索引, 图像数量, 参数类型(参见SDT_), 默认数值, 参数类别(参见AS_) } */
	{ _WT("索引"), _WT("索引从0开始"),0,0, SDT_INT, 0, NULL },
};
// 参数 【寻找项目】
ARG_INFO s_arg_unzip_find_item[] =
{
	/* { 参数名称, 参数描述, 图像索引, 图像数量, 参数类型(参见SDT_), 默认数值, 参数类别(参见AS_) } */
	{ _WT("项目名"), _WT("要寻找的项目名"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("不区分大小写"), _WT("寻找匹配时是否不区分大小写"),0,0, SDT_BOOL, 0, AS_HAS_DEFAULT_VALUE },
	{ _WT("返回索引"), _WT("返回寻找到的索引，失败返回-1"),0,0, SDT_INT, 0, AS_RECEIVE_VAR },
};
// 参数 【解压项目】
ARG_INFO s_arg_unzip_item[] =
{
	/* { 参数名称, 参数描述, 图像索引, 图像数量, 参数类型(参见SDT_), 默认数值, 参数类别(参见AS_) } */
	{ _WT("索引"), _WT("索引从0开始"),0,0, SDT_INT, 0, NULL },
	{ _WT("文件名"), _WT("解压后文件名"),0,0, SDT_TEXT, 0, NULL },
};
// 参数 【解压项目到内存】
ARG_INFO s_arg_unzip_item_memory[] =
{
	/* { 参数名称, 参数描述, 图像索引, 图像数量, 参数类型(参见SDT_), 默认数值, 参数类别(参见AS_) } */
	{ _WT("索引"), _WT("索引从0开始"),0,0, SDT_INT, 0, NULL },
	{ _WT("解压大小"), _WT("解压后内存大小，可从 项目信息 中获取"),0,0, SDT_INT, 0, NULL },
	{ _WT("字节集变量"), _WT("解压到此字节集"),0,0, SDT_BIN, 0, AS_RECEIVE_VAR },
};
// 参数 【解压项目到句柄】
ARG_INFO s_arg_unzip_item_handle[] =
{
	/* { 参数名称, 参数描述, 图像索引, 图像数量, 参数类型(参见SDT_), 默认数值, 参数类别(参见AS_) } */
	{ _WT("索引"), _WT("索引从0开始"),0,0, SDT_INT, 0, NULL },
	{ _WT("句柄"), _WT("文件句柄或管道句柄"),0,0, SDT_INT, 0, NULL },
};
// 参数 【设置解压根目录】
ARG_INFO s_arg_unzip_set_basedir[] =
{
	/* { 参数名称, 参数描述, 图像索引, 图像数量, 参数类型(参见SDT_), 默认数值, 参数类别(参见AS_) } */
	{ _WT("目录"), _WT("解压的文件名相对于此目录"),0,0, SDT_TEXT, 0, NULL },
};

// 命令信息
static CMD_INFO s_CmdInfo[] =
{
	/* { 中文名称, 英文名称, 对象描述, 所属类别(-1是数据类型的方法), 命令状态(CT_), 返回类型(SDT_), 此值保留, 对象等级(LVL_), 图像索引, 图像数量, 参数个数, 参数信息 } */

	// 由于压缩和解压的析构代码一样，所以就大家共享一个
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
		/*ccname*/	_WT("关闭"),
		/*egname*/	_WT("CloseZip"),
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

	//////////////////////////////////////////////////////////////////////////以下为 ZIP压缩 的方法
	{
		/*ccname*/	_WT("创建"),
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
		/*ccname*/	_WT("创建自内存"),
		/*egname*/	_WT("CreateZipMemory"),
		/*explain*/	_WT("创建一个压缩包自内存"),
		/*category*/-1,
		/*state*/	NULL,
		/*ret*/		SDT_BOOL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_create_zip_from_memroy) / sizeof(s_arg_create_zip_from_memroy[0]),
		/*arg lp*/	s_arg_create_zip_from_memroy,
	},
	{
		/*ccname*/	_WT("创建自句柄"),
		/*egname*/	_WT("CreateZipHandle"),
		/*explain*/	_WT("创建一个压缩包自文件句柄(hFile)或管道句柄(hPipe)"),
		/*category*/-1,
		/*state*/	NULL,
		/*ret*/		SDT_BOOL,
		/*reserved*/0,
		/*level*/	LVL_HIGH,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_create_zip_from_handle) / sizeof(s_arg_create_zip_from_handle[0]),
		/*arg lp*/	s_arg_create_zip_from_handle,
	},
	{
		/*ccname*/	_WT("添加项目"),
		/*egname*/	_WT("ZipAddItemFlie"),
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
		/*ccname*/	_WT("添加项目字节集"),
		/*egname*/	_WT("ZipAddItemMemory"),
		/*explain*/	_WT("向压缩包添加项目，返回\"ZR_\"开头常量"),
		/*category*/-1,
		/*state*/	NULL,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_add_item_memory) / sizeof(s_arg_add_item_memory[0]),
		/*arg lp*/	s_arg_add_item_memory,
	},
	{
		/*ccname*/	_WT("添加项目句柄"),
		/*egname*/	_WT("ZipAddItemHandle"),
		/*explain*/	_WT("向压缩包添加项目，返回\"ZR_\"开头常量"),
		/*category*/-1,
		/*state*/	NULL,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_HIGH,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_add_item_handle) / sizeof(s_arg_add_item_handle[0]),
		/*arg lp*/	s_arg_add_item_handle,
	},
	{
		/*ccname*/	_WT("添加目录"),
		/*egname*/	_WT("ZipAddFolder"),
		/*explain*/	_WT("向压缩包添加目录，返回\"ZR_\"开头常量"),
		/*category*/-1,
		/*state*/	NULL,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_add_folder) / sizeof(s_arg_add_folder[0]),
		/*arg lp*/	s_arg_add_folder,
	},
	{
		/*ccname*/	_WT("取字节集"),
		/*egname*/	_WT("ZipGetMemory"),
		/*explain*/	_WT("如果ZIP是在内存中创建的，创建自内存（0，len），则可调用此方法取出字节集。注意：取出字节集后不能再添加项目了。"),
		/*category*/-1,
		/*state*/	NULL,
		/*ret*/		SDT_BIN,
		/*reserved*/0,
		/*level*/	LVL_SECONDARY,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/0,
		/*arg lp*/	NULL,
	},


	//////////////////////////////////////////////////////////////////////////以下为 ZIP解压的方法
	{
		/*ccname*/	_WT("打开"),
		/*egname*/	_WT("OpenZipFile"),
		/*explain*/	_WT("打开压缩包自一个文件名"),
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
		/*ccname*/	_WT("打开自内存"),
		/*egname*/	_WT("OpenZipMemory"),
		/*explain*/	_WT("打开压缩包自内存数据"),
		/*category*/-1,
		/*state*/	NULL,
		/*ret*/		SDT_BOOL,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_unzip_open_momory) / sizeof(s_arg_unzip_open_momory[0]),
		/*arg lp*/	s_arg_unzip_open_momory,
	},
	{
		/*ccname*/	_WT("打开自句柄"),
		/*egname*/	_WT("OpenZipHandle"),
		/*explain*/	_WT("打开压缩包自一个文件句柄(hFile) 或 管道句柄(hPipe)"),
		/*category*/-1,
		/*state*/	NULL,
		/*ret*/		SDT_BOOL,
		/*reserved*/0,
		/*level*/	LVL_HIGH,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_unzip_open_handle) / sizeof(s_arg_unzip_open_handle[0]),
		/*arg lp*/	s_arg_unzip_open_handle,
	},
	{
		/*ccname*/	_WT("取项目数"),
		/*egname*/	_WT("GetItemCount"),
		/*explain*/	_WT("获取压缩包内的项目总数"),
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
	{
		/*ccname*/	_WT("取项目信息"),
		/*egname*/	_WT("GetItemInfo"),
		/*explain*/	_WT("获取压缩包内的项目信息"),
		/*category*/-1,
		/*state*/	NULL,
		/*ret*/		DTP_ZIPINFO,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_unzip_get_item) / sizeof(s_arg_unzip_get_item[0]),
		/*arg lp*/	s_arg_unzip_get_item,
	},
	{
		/*ccname*/	_WT("寻找项目"),
		/*egname*/	_WT("FindItemInfo"),
		/*explain*/	_WT("根据项目名寻找指定项目"),
		/*category*/-1,
		/*state*/	NULL,
		/*ret*/		DTP_ZIPINFO,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_unzip_find_item) / sizeof(s_arg_unzip_find_item[0]),
		/*arg lp*/	s_arg_unzip_find_item,
	},
	{
		/*ccname*/	_WT("解压项目"),
		/*egname*/	_WT("UnZipItem"),
		/*explain*/	_WT("解压指定项目，返回\"ZR_\"开头常量"),
		/*category*/-1,
		/*state*/	NULL,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_unzip_item) / sizeof(s_arg_unzip_item[0]),
		/*arg lp*/	s_arg_unzip_item,
	},
	{
		/*ccname*/	_WT("解压项目到字节集"),
		/*egname*/	_WT("UnZipItemMemory"),
		/*explain*/	_WT("解压指定项目到字节集，返回\"ZR_\"开头常量"),
		/*category*/-1,
		/*state*/	NULL,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_unzip_item_memory) / sizeof(s_arg_unzip_item_memory[0]),
		/*arg lp*/	s_arg_unzip_item_memory,
	},
	{
		/*ccname*/	_WT("解压项目到句柄"),
		/*egname*/	_WT("UnZipItemHandle"),
		/*explain*/	_WT("解压指定项目到文件句柄或管道句柄，返回\"ZR_\"开头常量"),
		/*category*/-1,
		/*state*/	NULL,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_HIGH,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_unzip_item_handle) / sizeof(s_arg_unzip_item_handle[0]),
		/*arg lp*/	s_arg_unzip_item_handle,
	},
	{
		/*ccname*/	_WT("置解压根目录"),
		/*egname*/	_WT("UnZipSetBaseDir"),
		/*explain*/	_WT("设置解压项目的根目录，返回\"ZR_\"开头常量"),
		/*category*/-1,
		/*state*/	NULL,
		/*ret*/		SDT_INT,
		/*reserved*/0,
		/*level*/	LVL_SIMPLE,
		/*bmp inx*/	0,
		/*bmp num*/	0,
		/*ArgCount*/sizeof(s_arg_unzip_set_basedir) / sizeof(s_arg_unzip_set_basedir[0]),
		/*arg lp*/	s_arg_unzip_set_basedir,
	},
};
#endif

// 命令实现
EXTERN_C void eziputils_fnZipDestruct(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	HZIP hZip = ((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip;
	if (hZip)
	{
		CloseZip(hZip);
		((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip = NULL;
	}
}
EXTERN_C void eziputils_fnZipClose(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	HZIP hZip = ((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip;
	if (hZip)
	{
		CloseZip(hZip);
		SetIntByIndex(pArgInf, 0, 0);
	}
}

// 压缩ZIP方法

EXTERN_C void eziputils_fnZipCreateFromFile(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	HZIP hZip = ((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip;
	if (hZip)
	{
		CloseZip(hZip);
	}
	hZip = CreateZip(pArgInf[1].m_pText, pArgInf[2].m_pText);
	((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip = hZip;
	pRetData->m_bool = hZip != NULL;
}
EXTERN_C void eziputils_fnZipCreateFromMemory(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	HZIP hZip = ((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip;
	if (hZip)
	{
		CloseZip(hZip);
	}
	hZip = CreateZip((void*)pArgInf[1].m_int, pArgInf[2].m_int, pArgInf[3].m_pText);
	((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip = hZip;
	pRetData->m_bool = hZip != NULL;
}
EXTERN_C void eziputils_fnZipCreateFromHandle(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	HZIP hZip = ((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip;
	if (hZip)
	{
		CloseZip(hZip);
	}
	hZip = CreateZipHandle((HANDLE)pArgInf[1].m_int, pArgInf[2].m_pText);
	((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip = hZip;
	pRetData->m_bool = hZip != NULL;
}
EXTERN_C void eziputils_fnZipAddItem(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	HZIP hZip = ((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip;
	if (hZip)
	{
		pRetData->m_int = ZipAdd(hZip, pArgInf[1].m_pText, pArgInf[2].m_pText);
	}
	else
	{
		pRetData->m_int = ZR_FAILED;
	}
}
EXTERN_C void eziputils_fnZipAddItemMemory(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	HZIP hZip = ((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip;
	if (hZip)
	{
		LPBYTE pData = NULL;
		int len = 0;
		if (pArgInf[2].m_pBin)
		{
			pData = pArgInf[2].m_pBin + sizeof(INT) * 2;
			len = *(LPINT)(pArgInf[2].m_pBin + sizeof(INT));
		}
		pRetData->m_int = ZipAdd(hZip, pArgInf[1].m_pText, pData, len);
	}
	else
	{
		pRetData->m_int = ZR_FAILED;
	}
}
EXTERN_C void eziputils_fnZipAddItemHandle(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	HZIP hZip = ((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip;
	if (hZip)
	{
		pRetData->m_int = ZipAdd(hZip, pArgInf[1].m_pText, (HANDLE)pArgInf[2].m_int, pArgInf[3].m_int);
	}
	else
	{
		pRetData->m_int = ZR_FAILED;
	}
	
}
EXTERN_C void eziputils_fnZipAddFolder(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	HZIP hZip = ((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip;
	if (hZip)
	{
		pRetData->m_int = ZipAddFolder(hZip, pArgInf[1].m_pText);
	}
	else
	{
		pRetData->m_int = ZR_FAILED;
	}
}
EXTERN_C void eziputils_fnZipGetMemory(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	HZIP hZip = ((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip;
	if (hZip)
	{
		void* buf = NULL;
		unsigned long len = 0;
		ZRESULT ret = ZipGetMemory(hZip, &buf, &len);
		if (ret == ZR_OK)
		{
			pRetData->m_pBin = CloneBinData((LPBYTE)buf, len);
			return;
		}
	}
	LPBYTE pd = (LPBYTE)MMalloc(sizeof(INT) * 2);
	*(LPINT)pd = 1;
	*(LPINT)(pd + sizeof(INT)) = 0;
	pRetData->m_pBin = pd;
}


// 解压ZIP方法

EXTERN_C void eziputils_fnUnZipOpenFromFile(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	HZIP hZip = ((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip;
	if (hZip)
	{
		CloseZip(hZip);
	}
	hZip = OpenZip(pArgInf[1].m_pText, pArgInf[2].m_pText);
	((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip = hZip;
	pRetData->m_bool = hZip != NULL;
}
EXTERN_C void eziputils_fnUnZipOpenFromMemory(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	HZIP hZip = ((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip;
	if (hZip)
	{
		CloseZip(hZip);
	}
	LPBYTE pData = pArgInf[1].m_pBin;
	if (pData)
	{
		hZip = OpenZip(pData + sizeof(INT) * 2, *(PINT)(pData + sizeof(INT)), pArgInf[2].m_pText);
		((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip = hZip;
		pRetData->m_bool = hZip != NULL;
	}
}
EXTERN_C void eziputils_fnUnZipOpenFromHandle(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	HZIP hZip = ((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip;
	if (hZip)
	{
		CloseZip(hZip);
	}
	hZip = OpenZipHandle((HANDLE)pArgInf[1].m_int, pArgInf[2].m_pText);
	((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip = hZip;
	pRetData->m_bool = hZip != NULL;
}
EXTERN_C void eziputils_fnUnZipGetItemCount(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	HZIP hZip = ((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip;
	if (hZip)
	{
		ZIPENTRY ze;
		GetZipItem(hZip, -1, &ze);
		pRetData->m_int = ze.index;
	}
}
EXTERN_C void eziputils_fnUnZipGetItemInfo(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	HZIP hZip = ((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip;
	ZipInfoStruct* pInfo = (ZipInfoStruct*)MMalloc(sizeof(ZipInfoStruct));
	pInfo->index = -1;
	if (hZip)
	{
		ZIPENTRY ze;
		ZRESULT ret = GetZipItem(hZip, pArgInf[1].m_int, &ze);
		
		if (ret == ZR_OK)
		{
			pInfo->index = ze.index;
			pInfo->name = CloneTextData(ze.name);
			pInfo->attr = ze.attr;

			SYSTEMTIME sysTime;
			FILETIME localTime;
			double dateTime;
			FileTimeToLocalFileTime(&ze.atime, &localTime);
			FileTimeToSystemTime(&localTime, &sysTime);
			SystemTimeToVariantTime(&sysTime, &dateTime);
			pInfo->atime = dateTime;

			FileTimeToLocalFileTime(&ze.ctime, &localTime);
			FileTimeToSystemTime(&localTime, &sysTime);
			SystemTimeToVariantTime(&sysTime, &dateTime);
			pInfo->ctime = dateTime;

			FileTimeToLocalFileTime(&ze.mtime, &localTime);
			FileTimeToSystemTime(&localTime, &sysTime);
			SystemTimeToVariantTime(&sysTime, &dateTime);
			pInfo->mtime = dateTime;

			pInfo->comp_size = ze.comp_size;
			pInfo->unc_size = ze.unc_size;

			/*char buf[200];
			sprintf_s(buf, "%f %f %f %d %d %d", pInfo->atime, pInfo->ctime, pInfo->mtime, pInfo->comp_size, pInfo->unc_size, sizeof(ZipInfoStruct));
			OutputDebugStringA(buf);*/
		}
	}
	pRetData->m_pCompoundData = pInfo;
}

EXTERN_C void eziputils_fnUnZipFindItemInfo(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	HZIP hZip = ((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip;
	ZipInfoStruct* pInfo = (ZipInfoStruct*)MMalloc(sizeof(ZipInfoStruct));
	pInfo->index = -1;
	*pArgInf[3].m_pInt = -1;
	if (hZip)
	{
		ZIPENTRY ze;
		ZRESULT ret = FindZipItem(hZip, pArgInf[1].m_pText, pArgInf[2].m_bool?true:false, pArgInf[3].m_pInt, &ze);
		if (ret == ZR_OK)
		{
			pInfo->index = ze.index;
			pInfo->name = CloneTextData(ze.name);
			pInfo->attr = ze.attr;

			SYSTEMTIME sysTime;
			FILETIME localTime;
			double dateTime;
			FileTimeToLocalFileTime(&ze.atime, &localTime);
			FileTimeToSystemTime(&localTime, &sysTime);
			SystemTimeToVariantTime(&sysTime, &dateTime);
			pInfo->atime = dateTime;

			FileTimeToLocalFileTime(&ze.ctime, &localTime);
			FileTimeToSystemTime(&localTime, &sysTime);
			SystemTimeToVariantTime(&sysTime, &dateTime);
			pInfo->ctime = dateTime;

			FileTimeToLocalFileTime(&ze.mtime, &localTime);
			FileTimeToSystemTime(&localTime, &sysTime);
			SystemTimeToVariantTime(&sysTime, &dateTime);
			pInfo->mtime = dateTime;

			pInfo->comp_size = ze.comp_size;
			pInfo->unc_size = ze.unc_size;
		}
	}
	pRetData->m_pCompoundData = pInfo;
}

EXTERN_C void eziputils_fnUnZipItem(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	HZIP hZip = ((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip;
	pRetData->m_int = ZR_FAILED;
	if (hZip)
	{
		pRetData->m_int = UnzipItem(hZip, pArgInf[1].m_int, pArgInf[2].m_pText);
	}
}
EXTERN_C void eziputils_fnUnZipItemMemory(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	HZIP hZip = ((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip;
	pRetData->m_int = ZR_FAILED;

	LPBYTE buf = (LPBYTE)MMalloc(pArgInf[2].m_int + sizeof(INT) * 2);
	*(LPINT)buf = 1;
	*(LPINT)(buf + sizeof(INT)) = pArgInf[2].m_int;
	if (hZip)
	{
		MFree(*pArgInf[3].m_ppBin);
		pRetData->m_int = UnzipItem(hZip, pArgInf[1].m_int, buf + sizeof(INT)*2, pArgInf[2].m_int);
		*pArgInf[3].m_ppBin = buf;
	}
	
}
EXTERN_C void eziputils_fnUnZipItemHandle(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	HZIP hZip = ((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip;
	pRetData->m_int = ZR_FAILED;
	if (hZip)
	{
		pRetData->m_int = UnzipItemHandle(hZip, pArgInf[1].m_int, (HANDLE)pArgInf[2].m_int);
	}
}
EXTERN_C void eziputils_fnUnZipSetBaseDir(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	HZIP hZip = ((ZipStruct*)pArgInf->m_pCompoundData)->m_hZip;
	pRetData->m_int = ZR_FAILED;
	if (hZip)
	{
		pRetData->m_int = SetUnzipBaseDir(hZip, pArgInf[1].m_pText);
	}
}




//*** 命令实现信息:
#ifndef __E_STATIC_LIB
PFN_EXECUTE_CMD s_RunFunc[] =	// 索引应与s_CmdInfo中的命令定义顺序对应
{
	eziputils_fnZipDestruct,
	eziputils_fnZipClose,
	eziputils_fnZipCreateFromFile,
	eziputils_fnZipCreateFromMemory,
	eziputils_fnZipCreateFromHandle,
	eziputils_fnZipAddItem,
	eziputils_fnZipAddItemMemory,
	eziputils_fnZipAddItemHandle,
	eziputils_fnZipAddFolder,
	eziputils_fnZipGetMemory,
	eziputils_fnUnZipOpenFromFile,
	eziputils_fnUnZipOpenFromMemory,
	eziputils_fnUnZipOpenFromHandle,
	eziputils_fnUnZipGetItemCount,
	eziputils_fnUnZipGetItemInfo,
	eziputils_fnUnZipFindItemInfo,
	eziputils_fnUnZipItem,
	eziputils_fnUnZipItemMemory,
	eziputils_fnUnZipItemHandle,
	eziputils_fnUnZipSetBaseDir
};

static const char* const g_CmdNames[] =
{
	"eziputils_fnZipDestruct",
	"eziputils_fnZipClose",
	"eziputils_fnZipCreateFromFile",
	"eziputils_fnZipCreateFromMemory",
	"eziputils_fnZipCreateFromHandle",
	"eziputils_fnZipAddItem",
	"eziputils_fnZipAddItemMemory",
	"eziputils_fnZipAddItemHandle",
	"eziputils_fnZipAddFolder",
	"eziputils_fnZipGetMemory",
	"eziputils_fnUnZipOpenFromFile",
	"eziputils_fnUnZipOpenFromMemory",
	"eziputils_fnUnZipOpenFromHandle",
	"eziputils_fnUnZipGetItemCount",
	"eziputils_fnUnZipGetItemInfo",
	"eziputils_fnUnZipFindItemInfo",
	"eziputils_fnUnZipItem",
	"eziputils_fnUnZipItemMemory",
	"eziputils_fnUnZipItemHandle",
	"eziputils_fnUnZipSetBaseDir"
};
#endif

/************************************************************************/
/* 数据类型定义
/************************************************************************/
#ifndef __E_STATIC_LIB
LIB_DATA_TYPE_ELEMENT s_dt_element_zip[] =
{
	/*{ 成员类型 ,数组成员 , 中文名称 ,英文名称 ,成员解释 ,成员状态 ,默认值}*/
	{ SDT_INT, NULL,_WT("hZip"), _WT("hZip"), NULL, LES_HIDED, 0 }
};

LIB_DATA_TYPE_ELEMENT s_dt_element_zip_info[] =
{
	/*{ 成员类型 ,数组成员 , 中文名称 ,英文名称 ,成员解释 ,成员状态 ,默认值}*/
	{ SDT_INT, NULL,_WT("索引"), _WT("index"), _WT("索引从0开始"), 0, 0 },
	{ SDT_TEXT, NULL,_WT("名称"), _WT("name"), _WT("项目名"), 0, 0 },
	{ SDT_INT, NULL,_WT("属性"), _WT("attr"), _WT("见API GetFileAttributes"), 0, 0 },
	{ SDT_DATE_TIME, NULL,_WT("访问时间"), _WT("atime"), NULL, 0, 0 },
	{ SDT_DATE_TIME, NULL,_WT("创建时间"), _WT("ctime"), NULL, 0, 0 },
	{ SDT_DATE_TIME, NULL,_WT("修改时间"), _WT("mtime"), NULL, 0, 0 },
	{ SDT_INT, NULL,_WT("压缩大小"), _WT("comp_size"), _WT("-1表示未知"), 0, 0 },
	{ SDT_INT, NULL,_WT("解压大小"), _WT("unc_size"), _WT("-1表示未知"), 0, 0 },
};

INT s_zipCommandIndexs[] =
{
	0,1,2,3,4,5,6,7,8,9
};
INT s_unzipCommandIndexs[] =
{
	0,1,10,11,12,13,14,15,16,17,18,19
};
static LIB_DATA_TYPE_INFO s_DataTypes[] =
{
	/* { 中文名称, 英文名称, 数据描述, 索引数量, 命令索引, 对象状态, 图标索引, 事件数量, 事件指针, 属性数量, 属性指针, 界面指针, 元素数量, 元素指针 } */
	{ _WT("ZIP项目信息"), _WT("ZIPENTRY"), _WT("项目信息"), 0, NULL, NULL, 0, 0, NULL, 0, NULL, NULL, sizeof(s_dt_element_zip_info) / sizeof(s_dt_element_zip_info[0]), s_dt_element_zip_info },
	{ _WT("ZIP压缩"), _WT("zip"), _WT("压缩ZIP"), sizeof(s_zipCommandIndexs) / sizeof(s_zipCommandIndexs[0]), s_zipCommandIndexs, NULL, 0, 0, NULL, 0, NULL, NULL, sizeof(s_dt_element_zip) / sizeof(s_dt_element_zip[0]), s_dt_element_zip },
	{ _WT("ZIP解压"), _WT("unzip"), _WT("解压ZIP"), sizeof(s_unzipCommandIndexs) / sizeof(s_unzipCommandIndexs[0]), s_unzipCommandIndexs, NULL, 0, 0, NULL, 0, NULL, NULL, sizeof(s_dt_element_zip) / sizeof(s_dt_element_zip[0]), s_dt_element_zip },

};
#endif


EXTERN_C INT WINAPI  eziputils_ProcessNotifyLib(INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
#ifndef __E_STATIC_LIB
	if (nMsg == NL_GET_CMD_FUNC_NAMES) // 返回所有命令实现函数的的函数名称数组(char*[]), 支持静态编译的动态库必须处理
		return (INT)g_CmdNames;
	else if (nMsg == NL_GET_NOTIFY_LIB_FUNC_NAME) // 返回处理系统通知的函数名称(PFN_NOTIFY_LIB函数名称), 支持静态编译的动态库必须处理
		return (INT)"eziputils_ProcessNotifyLib";
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
						sizeof(s_DataTypes) / sizeof(s_DataTypes[0]),
						s_DataTypes,
						//类别说明
#ifndef __COMPILE_FNR
						/*CategoryCount*/   0,			// 加了类别需加此值。
						/*category*/       	NULL,			// 类别说明表每项为一字符串,前四位数字表示图象索引号(从1开始,0无).
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

						/*pfnNotify*/				eziputils_ProcessNotifyLib,

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