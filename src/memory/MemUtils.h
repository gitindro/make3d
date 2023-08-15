#ifndef _MEM_UTILS_H_
#define _MEM_UTILS_H_
#include <cstddef>
#include <stdlib.h>
#include <assert.h>

namespace m3d
{
	class  MemUtils
	{
	public:

		static bool IsPowerOfTwo(const std::size_t x)
		{
			return (x & (x - 1)) == 0;
		}

		static const std::size_t AlignForward(const std::size_t baseAddress, const std::size_t alignment)
		{
			std::size_t p, a, modulo;

			assert(IsPowerOfTwo(alignment));
			p = baseAddress;
			a = alignment;
			// Same as (p % a) but faster as 'a' is a power of two
			modulo = p & (a - 1);

			if (modulo != 0)
			{
				p += a - modulo;
			}

			return p;
		}

		static void* AllocateAligned(const std::size_t sizeIn_bytes, const std::size_t alignment)
		{
			//total amount to allocate
			const std::size_t expanededSize_bytes = sizeIn_bytes + alignment;
			const std::size_t unalignedAddress = (std::size_t)malloc(expanededSize_bytes);

			//calcualate adjustment for alignment
			const std::size_t mask = alignment - 1;
			const std::size_t unaligned_by = unalignedAddress & mask;
			const std::size_t adjustment = alignment - unaligned_by;

			//aligned address 
			const std::size_t alignedAddress = unalignedAddress + adjustment;

			return (void*)alignedAddress;
		}


	};

}

#endif //_MEM_UTILS_H_
