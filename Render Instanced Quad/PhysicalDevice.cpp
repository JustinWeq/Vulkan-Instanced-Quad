#include "PhysicalDevice.h"

//defualt constructor-- creates a new instance of PhysicalDevice with defualt parameters
PhysicalDevice::PhysicalDevice()
{
	m_physicalDevice = NULL;
}

bool PhysicalDevice::Init(VkInstance instance)
{
	//get the number of phyisical instances
	uint32_t count;
	vkEnumeratePhysicalDevices(instance, &count, NULL);

	//create the list of display adapters
	VkPhysicalDevice* listOfDevices = new VkPhysicalDevice[count];

	//now actually enumerate the device
	vkEnumeratePhysicalDevices(instance, &count, listOfDevices);

	//now choose the first physical device
	m_physicalDevice = listOfDevices[0];

}

//returns the physical device
VkPhysicalDevice PhysicalDevice::GetPhysicalDevice()
{
	return m_physicalDevice;
}