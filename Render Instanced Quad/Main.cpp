#include <vulkan.h>
#include "Instance.h"
#include "PhysicalDevice.h"
#include <Windows.h>
int CALLBACK WinMain(HINSTANCE hinstance,HINSTANCE prevInstance,LPSTR args,int show)
{
	int returnCode = 0;
	Instance instance = Instance();
	PhysicalDevice physicalDevice = PhysicalDevice();

	//init the instance
	returnCode = !instance.Init("Test Vulkan app");

	//init the physical device adapter
	returnCode = !physicalDevice.Init(instance);

	//destroy the instance
	instance.destroy();

	//return the return code
	return returnCode;

}