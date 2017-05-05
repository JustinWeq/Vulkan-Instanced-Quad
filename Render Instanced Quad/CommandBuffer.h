#pragma once
#include <vulkan.h>
// A class for loading and maintaing a command buffer
class CommandBuffer
{
public:
	//defualt constructer--creates a new instance of CommandBuffer with default parameters
	CommandBuffer();

	//initalizes this instance of command buffer with the passed in vk device
	//device- the vulkan device to use for initalization
	bool Init(VkDevice device);

	// implicitly used for casting this class to a VkCommandBuffer class
	operator VkCommandBuffer();

private:
	// the actual command buffer data
	VkCommandBuffer m_data;

};