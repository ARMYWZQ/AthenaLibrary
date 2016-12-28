/*

Yuyue's Classes Library For Microsoft Visual C++

Copyright @2016 CDU INnoVation Studio
All rights reserved. 

�ļ����ƣ�AMemPool.h
ժҪ��
1.���ļ������ڴ�����������ʵ����AMemPool.cpp�С�
2.�ڴ���Ƕ��ڴ���亯���Ļ��壬�ھ�����Ҫ�ڴ����/���յĳ���ʹ���ڴ�أ���������������Ч�ʡ�
3.�ڴ�ص�ʵ������Ӧ�þ����٣������ڴ����ʹ���˵���ģʽ����ơ�
4.�ṩ�˰󶨵��ڴ�ض���ķ����ӣ�ʹSTL��������ֱ�Ӵ��ڴ���л�ȡ�ڴ档
5.�ṩ����������ָ�룬�����ṩ�Զ��ڴ���յĹ��ܡ�

��ǰ�汾��V2.0
���ߣ�����
e-mail��1397011447@qq.com
�������ڣ�2016��08��06��
�������ڣ�2016��08��15��

������־��
V2.0����������������ָ��

*/

#pragma once

#include "ACore.h"
#include <cstdlib>

ATHENA_BEGIN

class AMemPool final
{
public:
	AMemPool(const AMemPool&) = delete;
	AMemPool& operator=(const AMemPool&) = delete;
	void *allocate(size_t);
	bool deallocate(void *);
	static bool iniPool(int, size_t);
	static AMemPool & getMemPool();
private:
	AMemPool();
	~AMemPool();
	struct memNode;
	struct autoPtr
	{
		AMemPool *p=nullptr;
		~autoPtr(){ delete p;}
	};
	static autoPtr pool;
	static size_t nodeSize;
	static int nodeNum;
	memNode *currentNode;
	memNode *lastNode;
	memNode *firstNode;
	int currentNodeNum;
};

template<class T>
class APoolAllocator
{
public:
	typedef T value_type;
	typedef value_type* pointer;
	typedef const value_type* const_pointer;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	template<class U>
	struct rebind
	{
		typedef APoolAllocator<U> other;
	};
public:
	APoolAllocator():pool(AMemPool::getMemPool()){}

	APoolAllocator(const APoolAllocator<T>&) :pool(AMemPool::getMemPool()) {}

	template<class U>
	APoolAllocator(const APoolAllocator<U>&) : pool(AMemPool::getMemPool()) {}

	template<class U>
	APoolAllocator<U>& operator=(const APoolAllocator<U>&)
	{	
		return (*this);
	}

	pointer address(reference r) const
	{
		return &r;
	}
	const_pointer address(const_reference r) const
	{
		return &r;
	}
	pointer allocate(size_type n, const_pointer = 0) 
	{
		void* p = pool.allocate(n*sizeof(value_type));
		if (!p)
		{
			throw ABadAlloc("BadAlloc In APoolAllocator::allocate(size_type, const_pointer)\n");
		}
		return reinterpret_cast<pointer>(p);
	}
	void deallocate(pointer p, size_type) 
	{
		pool.deallocate(p);
	}
	size_type max_size() const 
	{
		return static_cast<size_type>(-1) / sizeof(value_type);
	}
	void construct(pointer p, const value_type& x) 
	{
		new(p) value_type(x);
	}
	void destroy(pointer p) 
	{ 
		p->~value_type(); 
	}
	AMemPool &pool;
};

class poolPtr
{
public:
	poolPtr(const poolPtr &) = delete;
	poolPtr(poolPtr &&) = delete;
	poolPtr& operator=(const poolPtr &) = delete;
	explicit poolPtr(size_t);
	virtual ~poolPtr();
	void reset(size_t);
	void *get();
protected:
	void *ptr;
	AMemPool &pool;
};

template<class T>
class objectPtr :protected poolPtr
{
public:
	objectPtr() :poolPtr(sizeof(T))
	{
		new(ptr) T;
	}
	objectPtr(const objectPtr &) = delete;
	virtual ~objectPtr()
	{
		get()->~T();
	}
	T *get()
	{
		return reinterpret_cast<T *>(ptr);
	}
	T *operator->()
	{
		return reinterpret_cast<T *>(ptr);
	}
	T &operator*()
	{
		return *reinterpret_cast<T *>(ptr);
	}
};

ATHENA_END
