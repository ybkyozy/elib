// EZipUtils.cpp: ���� DLL Ӧ�ó���ĵ���������
//

#include "elib_sdk/lib2.h"
#include "elib_sdk/lang.h"
#include "elib_sdk/fnshare.h"
#include "elib_sdk/fnshare.cpp"

#include "zip_utils_src/zip.h"
#include "zip_utils_src/unzip.h"

#include "EZipUtils.h"

/************************************************************************/
/* ��������
/************************************************************************/
#ifndef __E_STATIC_LIB
LIB_CONST_INFO s_ConstInfo[] =
{
	/* { ��������, Ӣ������, ��������, �����ȼ�(LVL_), ��������(CT_), �ı�����, ��ֵ���� }   ֻ��������������*/
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
/* �����
/************************************************************************/

// ���� ������ѹ�������ļ���
ARG_INFO s_arg_create_zip_from_file[] =
{
	/* { ��������, ��������, ͼ������, ͼ������, ��������(�μ�SDT_), Ĭ����ֵ, �������(�μ�AS_) } */
	{ _WT("�ļ���"), _WT("ѹ�����ļ���"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("����"), _WT("ѹ��������"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
// ���� ������ѹ�������ڴ桿
ARG_INFO s_arg_create_zip_from_memroy[] =
{
	/* { ��������, ��������, ͼ������, ͼ������, ��������(�μ�SDT_), Ĭ����ֵ, �������(�μ�AS_) } */
	{ _WT("��������ַ"), _WT("���Ϊ0�����ڴ�ҳ���ļ��д���"),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
	{ _WT("��С"), _WT("�ڴ��С"),0,0, SDT_INT, 0, 0 },
	{ _WT("����"), _WT("ѹ��������"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
// ���� ������ѹ�����Ծ����
ARG_INFO s_arg_create_zip_from_handle[] =
{
	/* { ��������, ��������, ͼ������, ͼ������, ��������(�μ�SDT_), Ĭ����ֵ, �������(�μ�AS_) } */
	{ _WT("���"), _WT("�ļ������ܵ����"),0,0, SDT_INT, 0, NULL },
	{ _WT("����"), _WT("ѹ��������"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
// ���� �������Ŀ��
ARG_INFO s_arg_add_item[] =
{
	/* { ��������, ��������, ͼ������, ͼ������, ��������(�μ�SDT_), Ĭ����ֵ, �������(�μ�AS_) } */
	{ _WT("��Ŀ��"), _WT("ѹ���ڵ���Ŀ��"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("�ļ���"), _WT("Ҫѹ�����ļ�·��"),0,0, SDT_TEXT, 0, NULL },
};
// ���� �������Ŀ���ڴ桿
ARG_INFO s_arg_add_item_memory[] =
{
	/* { ��������, ��������, ͼ������, ͼ������, ��������(�μ�SDT_), Ĭ����ֵ, �������(�μ�AS_) } */
	{ _WT("��Ŀ��"), _WT("ѹ���ڵ���Ŀ��"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("�ڴ�����"), _WT("Ҫѹ�����ڴ�����"),0,0, SDT_BIN, 0, NULL },
};
// ���� �������Ŀ�Ծ����
ARG_INFO s_arg_add_item_handle[] =
{
	/* { ��������, ��������, ͼ������, ͼ������, ��������(�μ�SDT_), Ĭ����ֵ, �������(�μ�AS_) } */
	{ _WT("��Ŀ��"), _WT("ѹ���ڵ���Ŀ��"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("���"), _WT("�ļ������ܵ����"),0,0, SDT_INT, 0, NULL },
	{ _WT("����"), _WT(""),0,0, SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
// ���� �����Ŀ¼��
ARG_INFO s_arg_add_folder[] =
{
	/* { ��������, ��������, ͼ������, ͼ������, ��������(�μ�SDT_), Ĭ����ֵ, �������(�μ�AS_) } */
	{ _WT("Ŀ¼��"), _WT("ѹ���ڵ�Ŀ¼��"),0,0, SDT_TEXT, 0, NULL }
};

// ���� �������ڴ桿
ARG_INFO s_arg_unzip_open_momory[] =
{
	/* { ��������, ��������, ͼ������, ͼ������, ��������(�μ�SDT_), Ĭ����ֵ, �������(�μ�AS_) } */
	{ _WT("ZIP����"), _WT("ѹ�����ֽڼ�����"),0,0, SDT_BIN, 0, NULL },
	{ _WT("����"), _WT("ѹ��������"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
// ���� �����Ծ����
ARG_INFO s_arg_unzip_open_handle[] =
{
	/* { ��������, ��������, ͼ������, ͼ������, ��������(�μ�SDT_), Ĭ����ֵ, �������(�μ�AS_) } */
	{ _WT("���"), _WT("�ļ������ܵ����"),0,0, SDT_INT, 0, NULL },
	{ _WT("����"), _WT("ѹ��������"),0,0, SDT_TEXT, 0, AS_DEFAULT_VALUE_IS_EMPTY },
};
// ���� ��ȡ��Ŀ��Ϣ��
ARG_INFO s_arg_unzip_get_item[] =
{
	/* { ��������, ��������, ͼ������, ͼ������, ��������(�μ�SDT_), Ĭ����ֵ, �������(�μ�AS_) } */
	{ _WT("����"), _WT("������0��ʼ"),0,0, SDT_INT, 0, NULL },
};
// ���� ��Ѱ����Ŀ��
ARG_INFO s_arg_unzip_find_item[] =
{
	/* { ��������, ��������, ͼ������, ͼ������, ��������(�μ�SDT_), Ĭ����ֵ, �������(�μ�AS_) } */
	{ _WT("��Ŀ��"), _WT("ҪѰ�ҵ���Ŀ��"),0,0, SDT_TEXT, 0, NULL },
	{ _WT("�����ִ�Сд"), _WT("Ѱ��ƥ��ʱ�Ƿ����ִ�Сд"),0,0, SDT_BOOL, 0, AS_HAS_DEFAULT_VALUE },
	{ _WT("��������"), _WT("����Ѱ�ҵ���������ʧ�ܷ���-1"),0,0, SDT_INT, 0, AS_RECEIVE_VAR },
};
// ���� ����ѹ��Ŀ��
ARG_INFO s_arg_unzip_item[] =
{
	/* { ��������, ��������, ͼ������, ͼ������, ��������(�μ�SDT_), Ĭ����ֵ, �������(�μ�AS_) } */
	{ _WT("����"), _WT("������0��ʼ"),0,0, SDT_INT, 0, NULL },
	{ _WT("�ļ���"), _WT("��ѹ���ļ���"),0,0, SDT_TEXT, 0, NULL },
};
// ���� ����ѹ��Ŀ���ڴ桿
ARG_INFO s_arg_unzip_item_memory[] =
{
	/* { ��������, ��������, ͼ������, ͼ������, ��������(�μ�SDT_), Ĭ����ֵ, �������(�μ�AS_) } */
	{ _WT("����"), _WT("������0��ʼ"),0,0, SDT_INT, 0, NULL },
	{ _WT("��ѹ��С"), _WT("��ѹ���ڴ��С���ɴ� ��Ŀ��Ϣ �л�ȡ"),0,0, SDT_INT, 0, NULL },
	{ _WT("�ֽڼ�����"), _WT("��ѹ�����ֽڼ�"),0,0, SDT_BIN, 0, AS_RECEIVE_VAR },
};
// ���� ����ѹ��Ŀ�������
ARG_INFO s_arg_unzip_item_handle[] =
{
	/* { ��������, ��������, ͼ������, ͼ������, ��������(�μ�SDT_), Ĭ����ֵ, �������(�μ�AS_) } */
	{ _WT("����"), _WT("������0��ʼ"),0,0, SDT_INT, 0, NULL },
	{ _WT("���"), _WT("�ļ������ܵ����"),0,0, SDT_INT, 0, NULL },
};
// ���� �����ý�ѹ��Ŀ¼��
ARG_INFO s_arg_unzip_set_basedir[] =
{
	/* { ��������, ��������, ͼ������, ͼ������, ��������(�μ�SDT_), Ĭ����ֵ, �������(�μ�AS_) } */
	{ _WT("Ŀ¼"), _WT("��ѹ���ļ�������ڴ�Ŀ¼"),0,0, SDT_TEXT, 0, NULL },
};

// ������Ϣ
static CMD_INFO s_CmdInfo[] =
{
	/* { ��������, Ӣ������, ��������, �������(-1���������͵ķ���), ����״̬(CT_), ��������(SDT_), ��ֵ����, ����ȼ�(LVL_), ͼ������, ͼ������, ��������, ������Ϣ } */

	// ����ѹ���ͽ�ѹ����������һ�������Ծʹ�ҹ���һ��
	{
		/*ccname*/	_WT("��������"),
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
		/*ccname*/	_WT("�ر�"),
		/*egname*/	_WT("CloseZip"),
		/*explain*/	_WT("��������������\"ZR_\"��ͷ����"),
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

	//////////////////////////////////////////////////////////////////////////����Ϊ ZIPѹ�� �ķ���
	{
		/*ccname*/	_WT("����"),
		/*egname*/	_WT("CreateZipFile"),
		/*explain*/	_WT("����һ��ѹ������һ���ļ���"),
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
		/*ccname*/	_WT("�������ڴ�"),
		/*egname*/	_WT("CreateZipMemory"),
		/*explain*/	_WT("����һ��ѹ�������ڴ�"),
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
		/*ccname*/	_WT("�����Ծ��"),
		/*egname*/	_WT("CreateZipHandle"),
		/*explain*/	_WT("����һ��ѹ�������ļ����(hFile)��ܵ����(hPipe)"),
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
		/*ccname*/	_WT("�����Ŀ"),
		/*egname*/	_WT("ZipAddItemFlie"),
		/*explain*/	_WT("��ѹ���������Ŀ������\"ZR_\"��ͷ����"),
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
		/*ccname*/	_WT("�����Ŀ�ֽڼ�"),
		/*egname*/	_WT("ZipAddItemMemory"),
		/*explain*/	_WT("��ѹ���������Ŀ������\"ZR_\"��ͷ����"),
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
		/*ccname*/	_WT("�����Ŀ���"),
		/*egname*/	_WT("ZipAddItemHandle"),
		/*explain*/	_WT("��ѹ���������Ŀ������\"ZR_\"��ͷ����"),
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
		/*ccname*/	_WT("���Ŀ¼"),
		/*egname*/	_WT("ZipAddFolder"),
		/*explain*/	_WT("��ѹ�������Ŀ¼������\"ZR_\"��ͷ����"),
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
		/*ccname*/	_WT("ȡ�ֽڼ�"),
		/*egname*/	_WT("ZipGetMemory"),
		/*explain*/	_WT("���ZIP�����ڴ��д����ģ��������ڴ棨0��len������ɵ��ô˷���ȡ���ֽڼ���ע�⣺ȡ���ֽڼ������������Ŀ�ˡ�"),
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


	//////////////////////////////////////////////////////////////////////////����Ϊ ZIP��ѹ�ķ���
	{
		/*ccname*/	_WT("��"),
		/*egname*/	_WT("OpenZipFile"),
		/*explain*/	_WT("��ѹ������һ���ļ���"),
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
		/*ccname*/	_WT("�����ڴ�"),
		/*egname*/	_WT("OpenZipMemory"),
		/*explain*/	_WT("��ѹ�������ڴ�����"),
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
		/*ccname*/	_WT("���Ծ��"),
		/*egname*/	_WT("OpenZipHandle"),
		/*explain*/	_WT("��ѹ������һ���ļ����(hFile) �� �ܵ����(hPipe)"),
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
		/*ccname*/	_WT("ȡ��Ŀ��"),
		/*egname*/	_WT("GetItemCount"),
		/*explain*/	_WT("��ȡѹ�����ڵ���Ŀ����"),
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
		/*ccname*/	_WT("ȡ��Ŀ��Ϣ"),
		/*egname*/	_WT("GetItemInfo"),
		/*explain*/	_WT("��ȡѹ�����ڵ���Ŀ��Ϣ"),
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
		/*ccname*/	_WT("Ѱ����Ŀ"),
		/*egname*/	_WT("FindItemInfo"),
		/*explain*/	_WT("������Ŀ��Ѱ��ָ����Ŀ"),
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
		/*ccname*/	_WT("��ѹ��Ŀ"),
		/*egname*/	_WT("UnZipItem"),
		/*explain*/	_WT("��ѹָ����Ŀ������\"ZR_\"��ͷ����"),
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
		/*ccname*/	_WT("��ѹ��Ŀ���ֽڼ�"),
		/*egname*/	_WT("UnZipItemMemory"),
		/*explain*/	_WT("��ѹָ����Ŀ���ֽڼ�������\"ZR_\"��ͷ����"),
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
		/*ccname*/	_WT("��ѹ��Ŀ�����"),
		/*egname*/	_WT("UnZipItemHandle"),
		/*explain*/	_WT("��ѹָ����Ŀ���ļ������ܵ����������\"ZR_\"��ͷ����"),
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
		/*ccname*/	_WT("�ý�ѹ��Ŀ¼"),
		/*egname*/	_WT("UnZipSetBaseDir"),
		/*explain*/	_WT("���ý�ѹ��Ŀ�ĸ�Ŀ¼������\"ZR_\"��ͷ����"),
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

// ����ʵ��
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

// ѹ��ZIP����

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


// ��ѹZIP����

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




//*** ����ʵ����Ϣ:
#ifndef __E_STATIC_LIB
PFN_EXECUTE_CMD s_RunFunc[] =	// ����Ӧ��s_CmdInfo�е������˳���Ӧ
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
/* �������Ͷ���
/************************************************************************/
#ifndef __E_STATIC_LIB
LIB_DATA_TYPE_ELEMENT s_dt_element_zip[] =
{
	/*{ ��Ա���� ,�����Ա , �������� ,Ӣ������ ,��Ա���� ,��Ա״̬ ,Ĭ��ֵ}*/
	{ SDT_INT, NULL,_WT("hZip"), _WT("hZip"), NULL, LES_HIDED, 0 }
};

LIB_DATA_TYPE_ELEMENT s_dt_element_zip_info[] =
{
	/*{ ��Ա���� ,�����Ա , �������� ,Ӣ������ ,��Ա���� ,��Ա״̬ ,Ĭ��ֵ}*/
	{ SDT_INT, NULL,_WT("����"), _WT("index"), _WT("������0��ʼ"), 0, 0 },
	{ SDT_TEXT, NULL,_WT("����"), _WT("name"), _WT("��Ŀ��"), 0, 0 },
	{ SDT_INT, NULL,_WT("����"), _WT("attr"), _WT("��API GetFileAttributes"), 0, 0 },
	{ SDT_DATE_TIME, NULL,_WT("����ʱ��"), _WT("atime"), NULL, 0, 0 },
	{ SDT_DATE_TIME, NULL,_WT("����ʱ��"), _WT("ctime"), NULL, 0, 0 },
	{ SDT_DATE_TIME, NULL,_WT("�޸�ʱ��"), _WT("mtime"), NULL, 0, 0 },
	{ SDT_INT, NULL,_WT("ѹ����С"), _WT("comp_size"), _WT("-1��ʾδ֪"), 0, 0 },
	{ SDT_INT, NULL,_WT("��ѹ��С"), _WT("unc_size"), _WT("-1��ʾδ֪"), 0, 0 },
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
	/* { ��������, Ӣ������, ��������, ��������, ��������, ����״̬, ͼ������, �¼�����, �¼�ָ��, ��������, ����ָ��, ����ָ��, Ԫ������, Ԫ��ָ�� } */
	{ _WT("ZIP��Ŀ��Ϣ"), _WT("ZIPENTRY"), _WT("��Ŀ��Ϣ"), 0, NULL, NULL, 0, 0, NULL, 0, NULL, NULL, sizeof(s_dt_element_zip_info) / sizeof(s_dt_element_zip_info[0]), s_dt_element_zip_info },
	{ _WT("ZIPѹ��"), _WT("zip"), _WT("ѹ��ZIP"), sizeof(s_zipCommandIndexs) / sizeof(s_zipCommandIndexs[0]), s_zipCommandIndexs, NULL, 0, 0, NULL, 0, NULL, NULL, sizeof(s_dt_element_zip) / sizeof(s_dt_element_zip[0]), s_dt_element_zip },
	{ _WT("ZIP��ѹ"), _WT("unzip"), _WT("��ѹZIP"), sizeof(s_unzipCommandIndexs) / sizeof(s_unzipCommandIndexs[0]), s_unzipCommandIndexs, NULL, 0, 0, NULL, 0, NULL, NULL, sizeof(s_dt_element_zip) / sizeof(s_dt_element_zip[0]), s_dt_element_zip },

};
#endif


EXTERN_C INT WINAPI  eziputils_ProcessNotifyLib(INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
#ifndef __E_STATIC_LIB
	if (nMsg == NL_GET_CMD_FUNC_NAMES) // ������������ʵ�ֺ����ĵĺ�����������(char*[]), ֧�־�̬����Ķ�̬����봦��
		return (INT)g_CmdNames;
	else if (nMsg == NL_GET_NOTIFY_LIB_FUNC_NAME) // ���ش���ϵͳ֪ͨ�ĺ�������(PFN_NOTIFY_LIB��������), ֧�־�̬����Ķ�̬����봦��
		return (INT)"eziputils_ProcessNotifyLib";
	else if (nMsg == NL_GET_DEPENDENT_LIBS) return (INT)NULL;
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
						sizeof(s_DataTypes) / sizeof(s_DataTypes[0]),
						s_DataTypes,
						//���˵��
#ifndef __COMPILE_FNR
						/*CategoryCount*/   0,			// ���������Ӵ�ֵ��
						/*category*/       	NULL,			// ���˵����ÿ��Ϊһ�ַ���,ǰ��λ���ֱ�ʾͼ��������(��1��ʼ,0��).
	/*CmdCount*/        sizeof(s_CmdInfo) / sizeof(s_ConstInfo[0]),
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

						/*pfnNotify*/				eziputils_ProcessNotifyLib,

						/*pfnRunSuperTemplate*/		NULL,
						/*szzSuperTemplateInfo*/	NULL,

#ifndef __COMPILE_FNR
						/*nLibConstCount*/			sizeof(s_ConstInfo) / sizeof(s_ConstInfo[0]),
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