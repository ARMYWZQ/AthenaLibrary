/*

Athena Classes Library For Microsoft Visual C++

Copyright @2016 CDU INnoVation Studio
All rights reserved.

�ļ����ƣ�ADBConnector.h
ժҪ��
1.���ļ����ж��߳����������ʵ����AThread.cpp�С�
2.AThread���ṩ��һ���̸߳��÷�����һ���̱߳������󣬲���ֻ����һ�ξ�ʧЧ�������Ա����ʹ�á�
3.���߳���ʵ�����ǶԱ�׼���е�thread��ķ�װ�����߳�Ĭ�������̷߳��롣
4.����start����������Ŀ���̣߳��߳�����ʱ�����õĺ���Ϊrun��run�����ɱ���д��

��ǰ�汾��V1.1
���ߣ�����
e-mail��1397011447@qq.com
�������ڣ�2017��03��28��
�������ڣ�2017��03��28��

������־��
V1.1�������߳�start��ʱ�򣬿��԰�����callable������ֻ�ǰ���run�����ϡ�

*/

#pragma once

#include <memory>
#include <functional>

#include "ACore.h"

ATHENA_BEGIN

struct threadData;

class AThread
{
public:
	AThread();
	virtual ~AThread();
	void start();
	void start(std::function<void()> fun);
	bool isRunning();
	bool isFinished();
protected:
	virtual void exec();
	virtual void run();
protected:
	std::unique_ptr<threadData> data;
};

ATHENA_END