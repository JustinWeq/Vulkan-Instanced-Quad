#pragma once
#include <vulkan.h>
//used to manage a vk instance
class Instance
{
public:
	//defualt constructor-- creates a new instance of Instance with defualt parameters
	Instance();

	//Initializes the VKinstance data with passed in name
	//appName- the name of the app
	bool Init(const char* appName);

	//Cleans up memory for dynamicly allocated memory
	void destroy();

	//Returns this Instance as a VkInstance
	operator VkInstance();

private:
	//The vkinstance data
	VkInstance m_instanceData;

};