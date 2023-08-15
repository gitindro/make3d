#ifndef _ALLOCATOR_H_
#define _ALLOCATOR_H_
#include <cstddef>

namespace m3d
{
	class Allocator
	{
	protected:
		std::size_t m_totalSize;
		std::size_t m_usedSize;
		std::size_t m_peakSize;

	public:
		Allocator(const std::size_t totalSize) : m_totalSize(totalSize), m_usedSize(0), m_peakSize(0) {/*empty*/ }

		virtual ~Allocator()
		{
			m_totalSize = 0;
		}

		virtual void* Allocate(const std::size_t size, const std::size_t alignment = 0) = 0;

		virtual void Free(void* ptr) = 0;

		virtual void Init() = 0;
	};
}

#endif //_ALLOCATOR_H_