#ifndef __PROGRADE_BUILDERS_DEVICE_BUILDER_HPP__
#define __PROGRADE_BUILDERS_DEVICE_BUILDER_HPP__

#include "../common.hpp"

namespace Prograde::Builders{
	class DeviceBuilder{
		public:
			DeviceBuilder();
			~DeviceBuilder();

			DeviceBuilder& setPhysicalDevice(std::shared_ptr<PhysicalDevice> physicalDevice);
			DeviceBuilder& requireExtension(const char* extension);
			DeviceBuilder& requireLayer(const char* layer);

			std::shared_ptr<Device> build(VkAllocationCallbacks* callbacks = nullptr);

		private:
			std::shared_ptr<PhysicalDevice> _physicalDevice;
			std::vector<const char*> _requiredExtensions;
			std::vector<const char*> _requiredLayers;

			bool isExtensionsSupported() const;
			bool isLayersSupported() const;
	};
}

#endif