
/******************************************************************* 
 *  Copyright(c) 2000-2013 linghegu
 *  All rights reserved. 
 *   
 *  �ļ�����: err description
 *  ��Ҫ����: 
 *   
 *  ��������: 2014/4/14
 *  ����:	      wangbin
 *  ˵��: 	      
 ******************************************************************/
#pragma once




#define output_error(x)   const char *errstr = strerror (x);\            
					   fprintf (stderr, "%s (%s:%d)\n", errstr, __FILE__, __LINE__);\           
					   abort();

























