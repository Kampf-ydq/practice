#ifndef MYCOMCLASS_H
#define MYCOMCLASS_H

#include "MyConstant.h"
//openmp֧��
#include <omp.h>
/********�������װ********/

class PortOperate
{
public:
	PortOperate()
	{
	}
	~PortOperate()
	{}
	//�ܳ�ʼ������
	bool Initial();
	/***************
	���ڹ��ܺ���:
	��opencomm
	��ȡReadData
	д��WriteData
	�ر�CloseComm
	***************/
	int OpenComm();

	int ReadData(unsigned char *pBuffer, unsigned char ulen);

	int WriteData(unsigned char *pBuffer, unsigned char uLen);

	void CloseComm();

	/****У��ͼ��㺯��********/
	unsigned char  CheckSum(unsigned char *uBuff, unsigned char uBuffLen);

	//���ܺ���
	bool SendAction(char direction, char speed = 0);
	bool SendShoot();
	bool SendLocation(unsigned short angle, char speed);
	bool SendAngle(unsigned short angle, unsigned short nVangle, unsigned short shoot);
	bool SendAngleLocation(short int nHangle, short int  nVangle, short int  nPixelX, short int  nPixelY);
	bool SendOK();

public:
	int fd1;
	unsigned char str[100];
	unsigned char tmpchar[12];
};


#endif
