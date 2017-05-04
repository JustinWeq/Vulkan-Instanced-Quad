#include "Instance.h"

//defualt constructor-- creates a new instance of Instance with defualt parameters
Instance::Instance()
{
	//set the instance data to null
	m_instanceData = NULL;
}

//Init-- initializes the VKinstance data with passed in name
//appName- the name of the app
bool Instance::Init(const char * appName)
{
	//set the application info
	VkApplicationInfo appInfo = {};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pNext = NULL;
	appInfo.pApplicationName = appName;
	appInfo.pEngineName = appName;
	appInfo.engineVersion = 1;
	appInfo.apiVersion = VK_API_VERSION_1_0;

	//init the create instance info structure
	VkInstanceCreateInfo instInfo = {};
	instInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	instInfo.pNext = NULL;
	instInfo.flags = 0;
	instInfo.pApplicationInfo = &appInfo;
	instInfo.enabledExtensionCount = 0;
	instInfo.ppEnabledExtensionNames = NULL;
	instInfo.enabledLayerCount = 0;
	instInfo.ppEnabledLayerNames = NULL;

	//try to create the instance
	VkResult result = vkCreateInstance(&instInfo, NULL, &m_instanceData);
	if (result == VK_ERROR_INCOMPATIBLE_DRIVER)
		//there is not a compatible vulkan driver
		return false;
	else if (result)
		//there was an unknown error return false
		return false;

	//everything worked correctly so return true
	return true;
}

//destroy-- cleans up memory for dynamicly allocated memory
void Instance::destroy()
{
	//destroy the instance data if it exists
	if (m_instanceData)
		vkDestroyInstance(m_instanceData, NULL);
}
