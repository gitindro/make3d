#ifndef _IM3DGfxDevice_h_
#define _IM3DGfxDevice_h_
#include "Headers.h"

namespace m3d
{
	class  IM3DGfxDevice
	{
	protected:
		GLFWwindow* m_window;
		MUINT m_windowWidth;
		MUINT m_windowHeight;
		cstring m_name;

	public:
		IM3DGfxDevice() = default;
		IM3DGfxDevice(cstring name)
		{
			m_name = name;
			m_window = nullptr;
			m_windowWidth = 0;
			m_windowHeight = 0;
		}
		virtual ~IM3DGfxDevice() {};

		virtual bool Init(GLFWwindow* hostWindow, MUINT windowWidth, MUINT windowHeight, bool isFullscreen) = 0;
		virtual void Shutdown() = 0;
		virtual void BeginFrame() = 0;
		virtual void EndFrame() = 0;
		virtual void Present() = 0;


	};
	 
}



#endif //_IM3DGfxDevice_h_
