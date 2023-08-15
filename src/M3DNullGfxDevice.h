#pragma once

#include "SystemTypes.h"
#include "IM3DGfxDevice.h"

namespace m3d
{
	class M3DNullGfxDevice : public IM3DGfxDevice
	{
		M3DNullGfxDevice() = default;
	public:
		
		M3DNullGfxDevice(cstring name);
		bool Init(GLFWwindow* hostWindow, MUINT windowWidth, MUINT windowHeight, bool isFullscreen) override;
		void Shutdown() override;
		void BeginFrame() override;
		void EndFrame() override;
		void Present() override;
	};


}
