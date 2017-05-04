#pragma once
#include <vulkan.h>
class PhysicalDevice
{
public:
	//defualt constructor-- creates a new instance of PhysicalDevice with defualt parameters
	PhysicalDevice();

	//initializes the physical device data
	//instance- the instance to get the physical devices from
	bool Init(VkInstance instance);

	//returns the physical device
	VkPhysicalDevice GetPhysicalDevice();

private:
	//the physical vulkan device(GPU adapter)
	VkPhysicalDevice m_physicalDevice;
};