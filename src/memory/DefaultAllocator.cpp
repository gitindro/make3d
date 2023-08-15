#include "DefaultAllocator.h"
#include "./../../Dependencies/rpmalloc/rpmalloc/rpmalloc.h"

namespace m3d
{

	void* DefaultAllocator::Allocate(const std::size_t size, const std::size_t alignment) 
	{
		return rpmalloc(size);
	}

	void DefaultAllocator::Free(void* ptr)
	{
		rpfree(ptr);
	}

	void DefaultAllocator::Init()
	{
		m_totalSize = m_totalSize;
		m_usedSize = 0;
		m_peakSize = 0;
	}
}