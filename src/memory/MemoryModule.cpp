#include "MemoryModule.h"
#include "./../../Dependencies/rpmalloc/rpmalloc/rpmalloc.h"


namespace m3d
{
	void init_memory_module()
	{
		rpmalloc_initialize();

	}

	void shutdown_memory_module()
	{
		//rpmalloc_dump_statistics();
		rpmalloc_finalize();
	}
}