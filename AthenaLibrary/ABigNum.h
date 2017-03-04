/*

AthenaClasses Library For Microsoft Visual C++

Copyright @2016 CDU INnoVation Studio
All rights reserved.

�ļ����ƣ�ABigNum.h
ժҪ��
1.���ļ����������������ʵ����ABigNum.cpp��

��ǰ�汾��V3.0
���ߣ�����
e-mail��1397011447@qq.com
�������ڣ�2016��07��18��
�������ڣ�2016��12��28��

������־��
V1.1���޸���metaDivi�е�һ��bug���޸���operator/=�еľ޴�������
V2.0���������������������˽�г�Ա���ⲻ�ɼ���
V3.0�������˸��ֱȽ��������

*/

#pragma once

#include <iostream>
#include <memory>

#include "ACore.h"

ATHENA_BEGIN

struct bigNumData;

class ABigNum final
{
public:
	ABigNum();
	explicit ABigNum(long long);
	ABigNum(ABigNum &&);
	ABigNum(const ABigNum &);
	friend std::ostream & operator<<(std::ostream &,const ABigNum &);
	friend std::istream & operator>>(std::istream &,  ABigNum &);
	ABigNum & operator+=(const ABigNum &);
	ABigNum & operator-=(const ABigNum &);
	ABigNum & operator*=(const ABigNum &);
	ABigNum & operator/=(const ABigNum &);
	ABigNum &operator=(const ABigNum &);
	ABigNum &operator=(ABigNum &&);
	ABigNum operator-(const ABigNum &) const;
	ABigNum operator+(const ABigNum &) const;
	ABigNum operator*(const ABigNum &) const;
	ABigNum operator/(const ABigNum &) const;
	bool operator>(const ABigNum&) const;
	bool operator<(const ABigNum&) const;
	bool operator==(const ABigNum&) const;
	bool operator<=(const ABigNum&) const;
	bool operator>=(const ABigNum&) const;
	bool operator!=(const ABigNum&) const;
	bool less(const ABigNum &) const;
	bool greater(const ABigNum &) const;
	bool equal(const ABigNum &) const;
	bool lessEqual(const ABigNum &) const;
	bool greaterEqual(const ABigNum &) const;
	bool notEqual(const ABigNum &) const;
	bool isOk() const;
	int getLength() const;
	const char *getBase() const;
	~ABigNum();
protected:
	bool compare(const bool *, const ABigNum &) const;
	void metaAdd(ABigNum *, const ABigNum *, const ABigNum *) const;
	void metaSub(ABigNum *, const ABigNum *, const ABigNum *) const;
	void metaMulti(ABigNum *, const ABigNum *, const ABigNum *) const;
	void metaDivi(ABigNum *, const ABigNum *, const ABigNum *) const;
	void resetSize(int);
protected:
	std::unique_ptr<bigNumData> data;
	const static int baseSize = 2000;
};

ATHENA_END