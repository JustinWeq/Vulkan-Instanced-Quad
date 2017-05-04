#include "PhysicalDevice.h"

//defualt constructor-- creates a new instance of PhysicalDevice with defualt parameters
PhysicalDevice::PhysicalDevice()
{
	m_physicalDevice = NULL;
}

bool PhysicalDevice::Init(VkInstance instance)
{
	VkResult result;
	//get the number of phyisical instances
	uint32_t count;
	result = vkEnumeratePhysicalDevices(instance, &count, NULL);
	if (result)
		return false;

	//create the list of display adapters
	VkPhysicalDevice* listOfDevices = new VkPhysicalDevice[count];

	//now actually enumerate the device
	result =vkEnumeratePhysicalDevices(instance, &count, listOfDevices);
	if (result)
		return false;

	//now choose the first physical device
	m_physicalDevice = listOfDevices[0];

	return true;

}

//returns the physical device
VkPhysicalDevice PhysicalDevice::GetPhysicalDevice()
{
	return m_physicalDevice;
}