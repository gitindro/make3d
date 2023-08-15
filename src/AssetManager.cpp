#include "AssetManager.h"

namespace m3d
{
	AssetManager::AssetManager()
	{

	}

	bool AssetManager::Initialize()
	{
		int ret = PHYSFS_init(NULL);
				
		printf("Base path %s", PHYSFS_getBaseDir());

		PHYSFS_addToSearchPath("../Assets", 1);


		return ret != 0;
	}

	void AssetManager::Shutdown()
	{
		PHYSFS_deinit();
	}

	char* AssetManager::ReadFile(const char* filepath)
	{
		PHYSFS_file* fHandle =  PHYSFS_openRead(filepath);
		PHYSFS_sint64 file_size = PHYSFS_fileLength(fHandle);

		char* readBuffer = new char[file_size];
		int length_read = PHYSFS_read(fHandle, readBuffer, 1, file_size);
		assert(length_read == file_size);

		return readBuffer;
	}
}