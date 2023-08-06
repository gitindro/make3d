#ifndef _RenderDevice_h_
#define _RenderDevice_h_
#include "SystemTypes.h"

namespace m3d
{
    class GLFWwindow;

    /**
     * @brief 
     * Root of the render system, with following responsibilities
     * 1. Creates OS window (glfw for now TODO: SDL)
     * 2. create  RenderDevice (OpenGL on only at the moment)
     * 3. Handle/pass window resize etc events to RenderDevice 
     */
    class M3DRenderer
    {
        public:
            M3DRenderer(void);
            virtual ~M3DRenderer(void); 
            virtual bool Initialize(GLFWwindow* windiow, UINT width, UINT height, bool fullscreen);
        private:
            GLFWwindow* m_ptrWindow;
    }
}

#endif//_RenderDevice_h_