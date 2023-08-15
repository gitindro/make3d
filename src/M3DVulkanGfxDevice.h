#pragma once
#include "SystemTypes.h"
#include "IM3DGfxDevice.h"

namespace m3d
{
	class M3DVulkanGfxDevice :public IM3DGfxDevice
	{
	private:
		M3DVulkanGfxDevice() = default;
	public:

		M3DVulkanGfxDevice(cstring name);
		bool Init(GLFWwindow* hostWindow, MUINT windowWidth, MUINT windowHeight, bool isFullscreen) override;
		void Shutdown() override;
		void BeginFrame() override;
		void EndFrame() override;
		void Present() override;

	private:
		VkInstance m_vkInstance;


		void CreateInstnce();
	};
}


