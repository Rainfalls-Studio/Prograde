#ifndef __PROGRADE_INSTANCE_HPP__
#define __PROGRADE_INSTANCE_HPP__

#include "common.hpp"

namespace Prograde{
	class Instance{
		public:
			Instance(VkInstanceCreateInfo& info, VkAllocationCallbacks* callbacks);
			Instance(VkInstance instance);
			~Instance();

			Instance(const Instance&) = delete;
			Instance& operator=(const Instance&) = delete;

			VkInstance get() const;

		private:
			VkAllocationCallbacks* _allocatorCallbacks = nullptr;
			VkInstance _instance = VK_NULL_HANDLE;
	};
}

#endif