#include "M3DRenderer.h"
#include "M3DNullGfxDevice.h"

namespace m3d
{
	M3DRenderer::M3DRenderer()
	{
		m_renderDeviceType = RenderDeviceType::Null;
		m_gfxDevice = nullptr;
	}

	M3DRenderer::~M3DRenderer()
	{

	}

	bool M3DRenderer::Initialize(RenderDeviceType deviceType, GLFWwindow* window, MUINT width, MUINT height, bool fullscreen)
	{
		if (RenderDeviceType::Null == deviceType)
		{
			m_gfxDevice = new M3DNullGfxDevice("NULL");
		}


		if (!m_gfxDevice->Init(window, width, height, fullscreen))
		{
			return false;
		}

		return true;
	}

	void M3DRenderer::Shutdown()
	{
		if (nullptr != m_gfxDevice)
		{
			m_gfxDevice->Shutdown();
		}
	}
}
