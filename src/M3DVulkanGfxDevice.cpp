#include "Headers.h"
#include "M3DVulkanGfxDevice.h"
#include <stdexcept>
#include <vector>

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
			if (!CreateInstance())
				return false;
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
		DestroyInstance();
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

	bool M3DVulkanGfxDevice::CheckExtensionSupport(std::vector<cstring> requiredList)
	{
		auto ret = vkEnumerateInstanceExtensionProperties(nullptr, &m_extensionCount, nullptr);

		if (VK_SUCCESS != ret)
		{
			LOG_F(ERROR, "Could not find any instance extension..");
			return false;
		}
		LOG_F(INFO, "Instance extension count %d", m_extensionCount);


		std::vector<VkExtensionProperties> availableExtensions(m_extensionCount);

		ret = vkEnumerateInstanceExtensionProperties(nullptr, &m_extensionCount, availableExtensions.data());
		if (VK_SUCCESS != ret)
		{
			LOG_F(ERROR, "Could not find any instance extension..");
			return false;
		}

		for each (auto var in requiredList)
		{
			bool found = false;

			for each (VkExtensionProperties extvar in availableExtensions)
			{
				if (0 == strcmpi(extvar.extensionName, var))
				{
					found = true;
					break;
				}
			}

			if (!found)
			{
				LOG_F(ERROR, "Required extension  %s not found", var);
				return false;
			}
		}
		
		return true;
	}

	bool M3DVulkanGfxDevice::CreateInstance()
	{
		std::vector<cstring> requiredExtensionList = std::vector<cstring>();
		uint32_t requiredExtensionCount = 0;

		cstring* glfwExtensions = glfwGetRequiredInstanceExtensions(&requiredExtensionCount);

		for (SIZE_T i = 0; i < requiredExtensionCount; ++i)
		{
			requiredExtensionList.push_back(glfwExtensions[i]);
			LOG_F(INFO, "Required extension  %s ", glfwExtensions[i]);
		}

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
		createInfo.enabledExtensionCount = requiredExtensionCount;
		createInfo.ppEnabledExtensionNames = requiredExtensionList.data();
		createInfo.enabledLayerCount = 0;//validation layer count
		createInfo.ppEnabledLayerNames = nullptr;//


		if (!CheckExtensionSupport(requiredExtensionList))
		{
			return false;
		}

		VkResult res = vkCreateInstance(&createInfo, nullptr, &m_vkInstance);

		if (res != VK_SUCCESS)
		{
			LOG_F(ERROR, "failed to create Instance ");
			return false;
		}
		LOG_F(INFO, "Successfully created Instance.. ");
		return true;
	}

	void M3DVulkanGfxDevice::DestroyInstance()
	{
		vkDestroyInstance(m_vkInstance, nullptr);
	}
}
