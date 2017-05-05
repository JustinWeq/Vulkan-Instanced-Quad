#include <vulkan.h>
#include "Instance.h"
#include "Device.h"
#include "PhysicalDevice.h"
#include "CommandBuffer.h"
#include <Windows.h>
int CALLBACK WinMain(HINSTANCE hinstance,HINSTANCE prevInstance,LPSTR args,int show)
{
	int returnCode = 0;
	Instance instance = Instance();
	PhysicalDevice physicalDevice = PhysicalDevice();
	Device device = Device();
	CommandBuffer cmdBuffer = CommandBuffer();

	//init the instance
	returnCode = !instance.Init("Test Vulkan app");

	//init the physical device adapter
	returnCode = !physicalDevice.Init(instance);

	//init the device
	returnCode = !device.Init(physicalDevice);

	//init the comand buffer
	returnCode = !cmdBuffer.Init(device);

	//destroy the instance
	instance.destroy();

	//return the return code
	return returnCode;

}