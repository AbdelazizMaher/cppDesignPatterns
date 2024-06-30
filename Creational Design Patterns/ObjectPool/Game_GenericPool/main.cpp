#include "ObjectPool.h"


class Test
{
private:
	Test() = default;
public:
	void Func() {

	}
	friend class TestAllocator;
};

class TestAllocator
{
public:
	Test* operator()()
	{
		return new Test{};
	}
	void operator()(Test* ptr)
	{
		delete ptr;
	}
	void resetState()
	{

	}
};

int main()
{
	using IntPool = ObjectPool<Test, 2, TestAllocator>;

	auto o1 = IntPool::aquireObject();
	auto o2 = IntPool::aquireObject();
	auto o3 = IntPool::aquireObject();

	IntPool::releaseObject(o1);

	auto o4 = IntPool::aquireObject();

	IntPool::destroyObjects();

	return 0;
}