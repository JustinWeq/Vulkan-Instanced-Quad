#include "Device.h"
// defualt constructor-- construct a new instance of Device
Device::Device()
{
	//set the data to null
	m_device = NULL;
}

//initializes the vk device
//physicalDevice- the physical device to use for this Device
bool Device::Init(VkPhysicalDevice physicalDevice)
{
	uint32_t count;
	VkResult result;
	//set up the device queue
	VkDeviceQueueCreateInfo queueInfo = {};


	//get the count for the queue familys
	vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &count, NULL);

	//set up the list of propertys
	VkQueueFamilyProperties* propertys = new VkQueueFamilyProperties[count];

	//get the actual propertys
	vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &count, propertys);

	//search for an appropriate graphics queue
	bool found = false;
	for (unsigned int i = 0; i < count; i++)
	{
		if (propertys[i].queueFlags & VK_QUEUE_GRAPHICS_BIT)
		{
			found = true;
			queueInfo.queueFamilyIndex = i;
			break;
		}
	}
	if (!found)
		return false;

	//set the queue propertys
	float queuePrioritys[1] = { 0.0 };
	queueInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
	queueInfo.pNext = NULL;
	queueInfo.queueCount = 1;
	queueInfo.pQueuePriorities = queuePrioritys;

	VkDeviceCreateInfo deviceInfo = {};
	deviceInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	deviceInfo.pNext = NULL;
	deviceInfo.queueCreateInfoCount = 1;
	deviceInfo.pQueueCreateInfos = &queueInfo;
	deviceInfo.enabledExtensionCount = 0;
	deviceInfo.ppEnabledExtensionNames = NULL;
	deviceInfo.enabledLayerCount = 0;
	deviceInfo.ppEnabledLayerNames = NULL;
	deviceInfo.pEnabledFeatures = NULL;

	//set up the device
	result = vkCreateDevice(physicalDevice, &deviceInfo, NULL, &m_device);
	if (result != VK_SUCCESS)
		return false;

	return true;

}



//operator for implicitly using Device as a vk device
Device::operator VkDevice()
{
	//return the device data
	return m_device;
}