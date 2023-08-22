#include "DefaultAllocator.h"
#include "../../external/rpmalloc/rpmalloc/rpmalloc.h"

namespace m3d
{

	void* DefaultAllocator::Allocate(const SIZE_T size, const SIZE_T alignment)
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