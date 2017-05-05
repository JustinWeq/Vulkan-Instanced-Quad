#pragma once
#include <vulkan.h>
// Used to manage a vk device
class Device
{
public:
	// defualt constructor-- construct a new instance of Device
	Device();

	//initializes the vk device
	//physicalDevice- the physical device to use for this Device
	bool Init(VkPhysicalDevice physicalDevice);

	//cleans up dynamically alocated memory
	void destroy();

	//operator for implicitly using Device as a vk device
	operator VkDevice();

	//returns the queue family index
	static int GetQueueFamilyIndex();

private:

	//the vk device data
	VkDevice m_device;


};