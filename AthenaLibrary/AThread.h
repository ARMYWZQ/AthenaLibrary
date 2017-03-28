/*

Athena Classes Library For Microsoft Visual C++

Copyright @2016 CDU INnoVation Studio
All rights reserved.

�ļ����ƣ�ADBConnector.h
ժҪ��
1.���ļ�����MySQL���ݿ�������������ʵ����ADBConnector.cpp�С�
2.ADBConnector��Ķ�����ʵ������MySQL���ݿ⣬��ִ����صĲ�����
3.���еĹ��ܾ��Ƕ�MySQL�ṩC API�ķ�װ��
4.ͨ��ADBConnector���������ݿⲢ����ȴ�C API������Ϊ���ݿ������ƿ���������ݿⱾ���Լ�Ӳ�̡�

��ǰ�汾��V1.0
���ߣ�����
e-mail��1397011447@qq.com
�������ڣ�2016��12��03��
�������ڣ�2016��12��26��

������־��

*/

#pragma once

#include <memory>

#include "ACore.h"

ATHENA_BEGIN

struct threadData;

class AThread
{
public:
	AThread();
	virtual ~AThread();
	void start();
	bool isRunning();
	bool isFinished();
protected:
	virtual void exec();
	virtual void run();
protected:
	std::unique_ptr<threadData> data;
};

ATHENA_END