/********************************************************************
	created:	2011/02/17
	created:	17:2:2011   15:58
	filename: 	inc\SqlDataReader.h
	file base:	SqlDataReader
	file ext:	h
	author:		zn
	fix:		wk
	
	purpose:	��ȡ���ݼ����࣬�����ݲ����ӿڴ������У�ͨ�������ȡ���з��ص�����
*********************************************************************/
#ifndef __SQL_DATA_READER_H__INCLUDE_
#define __SQL_DATA_READER_H__INCLUDE_
#include <stdlib.h>
#include "DBDefine.h"
#include "SqlCommand.h"

class CSqlDataReader
{
public:
	CSqlDataReader();
	CSqlDataReader(CSqlCommand* pInterface);
	~CSqlDataReader();

public:
	//��ȡ����
	template<class ParamType>
	bool getInt(int index, ParamType& returnValue)
	{
		if(m_Interface == NULL)
		{
			return false;
		}

		//m_Interface->nextRow();

		if(m_Interface->m_szRow == NULL)
		{
			return false;
		}

		if (m_Interface->m_szRow[index] == NULL)
		{
			return false;
		}

		returnValue = (ParamType)atoi(m_Interface->m_szRow[index]);

		return true;
	}

	//��ȡ����������
	bool				getBinary(int index, void* returnValue, int maxLen);
	//��ȡ�ַ���
	bool				getString(int index, char* returnValue, int maxLen);
	//��ȡ���ֽ�
	bool				getStringW(int index, wchar_t* returnValue, int maxLen);
	//��ȡ�޷�������
	bool				getUInt(int index, unsigned int& returnValue);

	//��ȡ64����
	bool				getUInt64(int index, db_uint64& returnValue);
	bool             getInt64(int index, db_int64& returnValue);
	//��ȡ������
	bool				getFloat(int index, float& returnValue);

	bool				fetchResult();

private:
	CSqlCommand*		m_Interface;
};

#endif
