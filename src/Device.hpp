#ifndef __PROGRADE_DEVICE_HPP__
#define __PROGRADE_DEVICE_HPP__

#include "common.hpp"

namespace Prograde{
	class Device{
		public:
			Device(const VkDeviceCreateInfo& info, VkPhysicalDevice physicalDevice, VkAllocationCallbacks* callbacks = nullptr);
			~Device();

			Device(const Device&) = delete;
			Device& operator=(const Device&) = delete;

		private:
			VkAllocationCallbacks* _callbacks;
			VkDevice _device;

	};
}

#endif