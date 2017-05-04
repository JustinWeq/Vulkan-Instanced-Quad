#include <vulkan.h>
#include "Instance.h"
#include <Windows.h>
int CALLBACK WinMain(HINSTANCE hinstance,HINSTANCE prevInstance,LPSTR args,int show)
{
	int returnCode = 0;
	Instance instance = Instance();

	//init the instance
	returnCode = !instance.Init("Test Vulkan app");

	//destroy the instance
	instance.destroy();

	//return the return code
	return returnCode;

}