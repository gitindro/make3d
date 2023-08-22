#include "Allocator.h"
#

namespace m3d
{
	class DefaultAllocator : public Allocator
	{
	protected:
		SIZE_T m_totalSize;
		SIZE_T m_usedSize;
		SIZE_T m_peakSize;

	public:
		DefaultAllocator(const SIZE_T totalSize) : Allocator(totalSize){}

		virtual ~DefaultAllocator()
		{
			m_totalSize = 0;
		}

		virtual void* Allocate(const SIZE_T size, const SIZE_T alignment = 0) = 0;

		virtual void Free(void* ptr) = 0;

		virtual void Init() = 0;
	};
}