#include "M3DNullGfxDevice.h"
#include "Headers.h"

namespace m3d
{
	M3DNullGfxDevice::M3DNullGfxDevice(cstring name)
	{
		m_name = name;
		m_window = nullptr;
	}
	
	bool M3DNullGfxDevice::Init(GLFWwindow* hostWindow, MUINT windowWidth, MUINT windowHeight, bool isFullscreen)
	{
		LOG_F(INFO, "Init Null gfx device");

		return true;// never fail cause we are doing nothing :)
	}

	void M3DNullGfxDevice::Shutdown()
	{
		LOG_F(INFO, "Shutdown Null gfx device");
	}

	void M3DNullGfxDevice::BeginFrame()
	{

	}
	
	void M3DNullGfxDevice::EndFrame()
	{

	}

	void M3DNullGfxDevice::Present()
	{

	}
}