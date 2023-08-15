#include "Allocator.h"


namespace m3d
{
	class DefaultAllocator
	{
	protected:
		std::size_t m_totalSize;
		std::size_t m_usedSize;
		std::size_t m_peakSize;

	public:
		DefaultAllocator(const std::size_t totalSize);

		virtual ~DefaultAllocator()
		{
			m_totalSize = 0;
		}

		virtual void* Allocate(const std::size_t size, const std::size_t alignment = 0) = 0;

		virtual void Free(void* ptr) = 0;

		virtual void Init() = 0;
	};
}