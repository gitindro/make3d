#include "LineraAllocator.h"
#include <stdlib.h>
#include <algorithm>
#include "MemUtils.h"
#include <assert.h>

namespace m3d
{
	LinearAllocator::LinearAllocator(const std::size_t totalSize):Allocator(totalSize)
	{
		m_offset = 0;
		m_prevOffset = 0;
		m_ptrStart = 0;
	}

	void LinearAllocator::Init()
	{
		if(nullptr != m_ptrStart)
			free(m_ptrStart);

		m_ptrStart = (unsigned char*)malloc(m_totalSize);
		m_offset = 0;
		m_prevOffset = 0;
	}

	LinearAllocator::~LinearAllocator()
	{
		free(m_ptrStart);
		m_ptrStart = nullptr;
	}

	void* LinearAllocator::Allocate(const std::size_t size, const std::size_t alignment)
	{
		std::size_t currentPtr = (std::size_t)m_ptrStart + m_offset;
		std::size_t offset = MemUtils::AlignForward(currentPtr, alignment);
		offset -= (std::size_t)m_ptrStart;

		if (offset + size <= m_totalSize)
		{
			void* ptr = &(m_ptrStart[offset]);

			m_prevOffset = offset;
			m_offset = offset + size;
			m_usedSize += size;
			memset(ptr, 0, size);
			return ptr;
		}

		return nullptr;
	}

	void LinearAllocator::Free(void* ptr)
	{
		// nothing to do
	}

	void* LinearAllocator::Resize(void* oldMemory, const::size_t oldSize, const std::size_t newSize, const std::size_t align)
	{
		unsigned char* old = (unsigned char*)oldMemory;
		assert(MemUtils::IsPowerOfTwo(align));

		if (old == NULL || oldSize == 0)
		{
			return Allocate(newSize, align);
		}
		else if (m_ptrStart <= oldMemory && oldMemory < m_ptrStart+m_totalSize)
		{
			if (m_ptrStart + m_prevOffset == oldMemory) // IF THIS IS THE LAST ALOCATION
			{
				m_offset = m_prevOffset + newSize;
				if (newSize > oldSize)
					memset(&(m_ptrStart[m_offset]), 0, newSize);

				return oldMemory;
			}
			else
			{
				void* newMemory = Allocate(newSize, align);
				std::size_t copy_size = oldSize > newSize ? newSize:oldSize;
				memmove(newMemory, oldMemory, copy_size);

				return newMemory;
			}
		}
		else
		{
			assert(0 && "Memory is out of bound of this buffer");
			return NULL;
		}
	}

	void LinearAllocator::Reset()
	{
		m_offset = 0;
		m_prevOffset = 0;
	}
}