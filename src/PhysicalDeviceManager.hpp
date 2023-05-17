#ifndef __PROGRADE_PHYSICAL_DEVICE_MANAGER_HPP__
#define __PROGRADE_PHYSICAL_DEVICE_MANAGER_HPP__

#include "common.hpp"

namespace Prograde{
	class PhysicalDeviceSearchFilter{
		friend class PhysicalDeviceManager;
		public:
			PhysicalDeviceSearchFilter() = default;
			~PhysicalDeviceSearchFilter() = default;

			PhysicalDeviceSearchFilter& requireFeatures(const VkPhysicalDeviceFeatures &features);
			PhysicalDeviceSearchFilter& requirePresent(VkSurfaceKHR surface);
			PhysicalDeviceSearchFilter& requireExtension(const char* extension);
			PhysicalDeviceSearchFilter& requireLayer(const char* layer);

		private:
			VkPhysicalDeviceFeatures _requiredFeatures{};
			VkSurfaceKHR _surface = VK_NULL_HANDLE;
			std::vector<const char*> _requiredExtensions;
			std::vector<const char*> _requiredLayers;
	};

	class PhysicalDeviceManager{
		public:
			PhysicalDeviceManager(std::shared_ptr<Instance> instance);
			~PhysicalDeviceManager();

			std::list<std::shared_ptr<PhysicalDevice>> find(const PhysicalDeviceSearchFilter &filter) const;

		private:
			std::shared_ptr<Instance> _instance;
			std::list<std::shared_ptr<PhysicalDevice>> _physicalDevices;

			static bool supportExtensions(const std::shared_ptr<PhysicalDevice>& device, const std::vector<const char*>& extensions);
			static bool supportLayers(const std::shared_ptr<PhysicalDevice>& device, const std::vector<const char*>& layers);
			bool supportPresent(const std::shared_ptr<PhysicalDevice>& device, VkSurfaceKHR surface) const;
	};
}

#endif