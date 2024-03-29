#ifndef __PROGRADE_PHYSICAL_DEVICE_HPP__
#define __PROGRADE_PHYSICAL_DEVICE_HPP__

#include "common.hpp"

namespace Prograde{
	class PhysicalDevice{
		public:
			struct SwapchainSupport{
				VkSurfaceCapabilitiesKHR capabilities;
				std::vector<VkSurfaceFormatKHR> formats;
				std::vector<VkPresentModeKHR> presentModes;
			};

			PhysicalDevice(VkPhysicalDevice device);
			~PhysicalDevice();

			PhysicalDevice(const PhysicalDevice &) = delete;
			PhysicalDevice& operator=(const PhysicalDevice &) = delete;

			const VkPhysicalDeviceFeatures& features() const;
			const VkPhysicalDeviceProperties& properties() const;
			const VkPhysicalDeviceMemoryProperties& memoryProperties() const;

			const std::vector<VkPhysicalDeviceToolProperties>& toolProperties() const;
			const std::vector<VkQueueFamilyProperties>& queueFamilyProperties() const;
			const std::vector<VkExtensionProperties> getSupportedExtensionProperties() const;
			const std::vector<VkLayerProperties> getSupportedLayerProperties() const;

			bool supportFeatures(const VkPhysicalDeviceFeatures& features) const;
			bool supportExtension(const char* extension) const;
			bool supportLayer(const char* layer) const;

			SwapchainSupport getSwapchainSupport(VkSurfaceKHR surface) const;
			VkPhysicalDevice get() const;

		private:
			VkPhysicalDevice _device;

			VkPhysicalDeviceFeatures _features;
			VkPhysicalDeviceProperties _properties;
			VkPhysicalDeviceMemoryProperties _memoryProperties;

			std::vector<VkPhysicalDeviceToolProperties> _toolProperties;
			std::vector<VkQueueFamilyProperties> _queueFamilyProperties;
			std::vector<VkExtensionProperties> _supportedExtensionProperties;
			std::vector<VkLayerProperties> _supportedLayerProperties;
			
			void getToolProperties();
			void getFamilyProperties();
			void getExtensionProperties();
			void getLayerProperties();
	};
}

#endif