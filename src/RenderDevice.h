#ifndef _RenderDevice_h_
#define _RenderDevice_h_
#include "SystemTypes.h"

namespace m3d
{
	class GLFWwindow;
	class IRenderDevice
	{
	public:
		IRenderDevice(void) {}
		virtual ~IRenderDevice(void) {}
		virtual bool Init(GLFWwindow* ptrWindow, UINT width, UINT height, bool fullscreen);
		virtual void Draw
	private:
		GLFWwindow* m_ptrWindow;
	};
}

#endif//_RenderDevice_h_