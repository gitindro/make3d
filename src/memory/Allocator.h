#ifndef _ALLOCATOR_H_
#define _ALLOCATOR_H_
#include "../SystemTypes.h"

namespace m3d
{
	class Allocator
	{
	protected:
		SIZE_T m_totalSize;
		SIZE_T m_usedSize;
		SIZE_T m_peakSize;

	public:
		Allocator(const SIZE_T totalSize) : m_totalSize(totalSize), m_usedSize(0), m_peakSize(0) {/*empty*/ }

		virtual ~Allocator()
		{
			m_totalSize = 0;
		}

		virtual void* Allocate(const SIZE_T size, const SIZE_T alignment = 0) = 0;

		virtual void Free(void* ptr) = 0;

		virtual void Init() = 0;
	};
}

#endif //_ALLOCATOR_H_