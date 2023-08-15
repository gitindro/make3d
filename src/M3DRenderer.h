#ifndef _M3D_Window_h_
#define _M3D_Window_h_

#include "SystemTypes.h"
#include "Headers.h"

namespace m3d
{
    class  IM3DGfxDevice;

    enum RenderDeviceType
    {
        Null,
        Vulkan
    };

    class M3DRenderer
    {
    private:
        M3DRenderer(const M3DRenderer& window) = delete;
        RenderDeviceType m_renderDeviceType;
        IM3DGfxDevice*   m_gfxDevice;

    public:
        M3DRenderer();
        bool Initialize(RenderDeviceType deviceType, GLFWwindow* window, MUINT width, MUINT height, bool fullscreen);
        void Shutdown();
        ~M3DRenderer();
    };
}


#endif //_M3D_Window_h_