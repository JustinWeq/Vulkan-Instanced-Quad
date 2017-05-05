#include "CommandBuffer.h"
#include "Device.h"
//defualt constructer--creates a new instance of CommandBuffer with default parameters
CommandBuffer::CommandBuffer()
{
	//set the data to null
	m_data = NULL;
}

//initalizes this instance of command buffer with the passed in vk device
//device- the vulkan device to use for initalization
bool CommandBuffer::Init(VkDevice device)
{
	VkCommandPool pool;
	VkResult result;
	//load the command pool
	VkCommandPoolCreateInfo cmdPoolInfo = {};
	cmdPoolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
	cmdPoolInfo.pNext = NULL;
	//set the queue family index
	cmdPoolInfo.queueFamilyIndex = Device::GetQueueFamilyIndex();
	cmdPoolInfo.flags = 0;
	//create the command pool
	result = vkCreateCommandPool(device, &cmdPoolInfo, NULL, &pool);
	if (result != VK_SUCCESS)
		return false;

	//start filling out the info for the command buffer
	VkCommandBufferAllocateInfo cmd = {};
	cmd.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
	cmd.pNext = NULL;
	cmd.commandPool = pool;
	cmd.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
	cmd.commandBufferCount = 1;

	result = vkAllocateCommandBuffers(device, &cmd, &m_data);
	if (result != VK_SUCCESS)
		return false;

	return true;
}

// implicitly used for casting this class to a VkCommandBuffer class
CommandBuffer::operator VkCommandBuffer() {
	//return the command buffer data
	return m_data;
}