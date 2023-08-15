#include "Headers.h"
#include "M3DVulkanGfxDevice.h"
#include <stdexcept>
namespace m3d
{
	M3DVulkanGfxDevice::M3DVulkanGfxDevice(cstring name)
	{
		m_name = name;
		m_window = nullptr;
	}

	bool M3DVulkanGfxDevice::Init(GLFWwindow* hostWindow, MUINT windowWidth, MUINT windowHeight, bool isFullscreen)
	{
		LOG_F(INFO, "Init Vulkan gfx device");
		try
		{

		}
		catch (const std::runtime_error& e)
		{
			LOG_F(INFO, e.what());
			return false;
		}

		return true;// never fail cause we are doing nothing :)
	}

	void M3DVulkanGfxDevice::Shutdown()
	{
		LOG_F(INFO, "Shutdown Vulkan gfx device");
	}

	void M3DVulkanGfxDevice::BeginFrame()
	{

	}

	void M3DVulkanGfxDevice::EndFrame()
	{

	}

	void M3DVulkanGfxDevice::Present()
	{

	}

	void M3DVulkanGfxDevice::CreateInstnce()
	{
		//create vulkan instance
		VkApplicationInfo appInfo = {};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "Test";
		appInfo.applicationVersion = VK_MAKE_VERSION(0, 0, 1);
		appInfo.pEngineName = "MAKE3D";
		appInfo.engineVersion = VK_MAKE_VERSION(0, 0, 1);
		appInfo.apiVersion = VK_API_VERSION_1_3;

		VkInstanceCreateInfo createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;
	}
}
