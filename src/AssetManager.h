#ifndef _AssetManagerh_
#define _AssetManagerh_

#include "Headers.h"
#include  "physfs.h"

namespace m3d
{
    class AssetManager
    {
    public:
        bool Initialize();
        void Shutdown();
    private:
        AssetManager();
        AssetManager(const AssetManager&) = delete;
        char* ReadFile(const char* filepath);

        friend class Engine;
    };
}
#endif //