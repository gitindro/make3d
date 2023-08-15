#ifndef _LINEAR_ALLOCATOR_H_
#define _LINEAR_ALLOCATOR_H_

#include "Allocator.h"


namespace m3d
{
	class LinearAllocator : public Allocator
	{
	protected:
		unsigned char* m_ptrStart = nullptr;
		std::size_t m_prevOffset;
		std::size_t m_offset;

	public:
		LinearAllocator(const std::size_t totalSize);

		virtual ~LinearAllocator();

		virtual void* Allocate(const std::size_t size, const std::size_t alingment = 0);

		virtual void Free(void* ptr);

		virtual void Init();

		virtual void Reset();

		virtual void* Resize(void* oldMemory, const::size_t oldSize, const std::size_t newSize, const std::size_t align);

	private:
		LinearAllocator(LinearAllocator& linearAlloc); // disable copy constructor
	};
}

#endif //_LINEAR_ALLOCATOR_H_