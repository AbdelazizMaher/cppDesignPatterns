#pragma once

#include <iostream>
#include <vector>

template<typename T>
class DefaultAllocator
{
public:
	T* operator()()
	{
		return new T{};
	}
	void operator()(T* ptr)
	{
		delete ptr;
	}
	void resetState()
	{

	}
};

template<typename T, 
	size_t m_maxSize = std::numeric_limits<size_t>::max(),
	typename AllocatorT = DefaultAllocator<T>>
class ObjectPool
{
private:
	struct objectInfo
	{
		bool isUsed{ true };
		T* m_pObject{};
	};
	inline static std::vector<objectInfo> m_PoolObjects{};
	inline static AllocatorT m_Allocator{};
public:
	[[nodiscard("Object will remain unused")]]
	static T* aquireObject()
	{
		for (auto& object : m_PoolObjects)
		{
			if (!object.isUsed)
			{
				std::cout << "[POOL]: Returning an existing actor of type " << std::endl;
				
				object.isUsed = true;
				return object.m_pObject;
			}
		}

		std::cout << "[POOL]: Creating a new object " << std::endl;

		if (m_maxSize == m_PoolObjects.size())
		{
			std::cout << "[ERROR]: Pool is full" << std::endl;
			return nullptr;
		}

		auto p_object = m_Allocator();
		m_PoolObjects.push_back({true,p_object});
		return p_object;
	}
	static void releaseObject(const T* p_Object)
	{
		for (auto& object : m_PoolObjects)
		{
			if (object.m_pObject == p_Object)
			{
				object.isUsed = false;
				break;
			}
		}
	}
	static void destroyObjects()
	{
		for (auto& object : m_PoolObjects)
		{
			if (object.isUsed)
				std::cout << "[WARNING]: Deleting an object still in use" << std::endl;
			m_Allocator(object.m_pObject);
		}
		m_Allocator.resetState();
		m_PoolObjects.clear();
	}
};

