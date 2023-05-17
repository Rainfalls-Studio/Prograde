#include "Device.hpp"

namespace Prograde{
	Device::Device(const VkDeviceCreateInfo& info, VkPhysicalDevice physicalDevice, VkAllocationCallbacks* callbacks) : _callbacks{callbacks}{
		if (vkCreateDevice(physicalDevice, &info, callbacks, &_device) != VK_SUCCESS){
			throw std::runtime_error("Failed to create vulkan logical device");
		}
	}

	Device::~Device(){
		if (_device){
			vkDestroyDevice(_device, _callbacks);
		}
	}
}