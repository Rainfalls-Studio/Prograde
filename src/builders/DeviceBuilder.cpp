#include "DeviceBuilder.hpp"
#include "../Device.hpp"
#include "../PhysicalDevice.hpp"

namespace Prograde::Builders{
	DeviceBuilder::DeviceBuilder(){

	}

	DeviceBuilder::~DeviceBuilder(){
		VkDeviceCreateInfo info;
		info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	}

	DeviceBuilder& DeviceBuilder::setPhysicalDevice(std::shared_ptr<PhysicalDevice> physicalDevice){
		_physicalDevice = physicalDevice;
		return *this;
	}
	
	DeviceBuilder& DeviceBuilder::requireExtension(const char* extension){
		_requiredExtensions.push_back(extension);
		return *this;
	}

	DeviceBuilder& DeviceBuilder::requireLayer(const char* layer){
		_requiredLayers.push_back(layer);
		return *this;
	}

	std::shared_ptr<Device> DeviceBuilder::build(VkAllocationCallbacks* callbacks){
		if (!isExtensionsSupported()){
			throw std::runtime_error("unsupported extensions");
		}

		if (!isLayersSupported()){
			throw std::runtime_error("unsupported layers");
		}

		VkDeviceCreateInfo info{};
		info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
		
		VkPhysicalDeviceFeatures features = _physicalDevice->features();
		info.pEnabledFeatures = &features;

		info.ppEnabledExtensionNames = _requiredExtensions.data();
		info.ppEnabledLayerNames = _requiredLayers.data();

		info.enabledExtensionCount = static_cast<uint32>(_requiredExtensions.size());
		info.enabledLayerCount = static_cast<uint32>(_requiredLayers.size());

		info.queueCreateInfoCount = 0;

		return std::make_shared<Device>(info, _physicalDevice->get(), callbacks);
	}
	
	bool DeviceBuilder::isExtensionsSupported() const{
		for (const auto &e : _requiredExtensions){
			if (!_physicalDevice->supportExtension(e)) return false;
		}
		return true;
	}

	bool DeviceBuilder::isLayersSupported() const{
		for (const auto &l : _requiredLayers){
			if (!_physicalDevice->supportLayer(l)) return false;
		}
		return true;
	}
}