#include "PhysicalDeviceManager.hpp"
#include "Instance.hpp"
#include "PhysicalDevice.hpp"

namespace Prograde{
	PhysicalDeviceSearchFilter& PhysicalDeviceSearchFilter::requireFeatures(const VkPhysicalDeviceFeatures &features){
		_requiredFeatures = features;
		return *this;
	}

	PhysicalDeviceSearchFilter& PhysicalDeviceSearchFilter::requirePresent(VkSurfaceKHR surface){
		_surface = surface;
		return *this;
	}

	PhysicalDeviceSearchFilter& PhysicalDeviceSearchFilter::requireExtension(const char* extension){
		_requiredExtensions.push_back(extension);
		return *this;
	}

	PhysicalDeviceSearchFilter& PhysicalDeviceSearchFilter::requireLayer(const char* layer){
		_requiredLayers.push_back(layer);
		return *this;
	}

	PhysicalDeviceManager::PhysicalDeviceManager(std::shared_ptr<Instance> instance) : _instance{instance}{
		RAINDROP_log(INFO, GRAPHICS, "creating the physical device manager");

		uint32 count;
		vkEnumeratePhysicalDevices(_instance->get(), &count, nullptr);

		std::vector<VkPhysicalDevice> devices(count);
		vkEnumeratePhysicalDevices(_instance->get(), &count, devices.data());

		uint32 successCount = 0;
		for (auto d : devices){
			try{
				std::shared_ptr<PhysicalDevice> device = std::make_shared<PhysicalDevice>(d);
				RAINDROP_log(INFO, GRAPHICS, "\t- %s", device->properties().deviceName);
				_physicalDevices.push_back(device);

			} catch (std::exception &e){
				RAINDROP_log(ERROR, GRAPHICS, "failed to create a physical device");
				continue;
			}
			successCount++;
		}

		RAINDROP_log(INFO, GRAPHICS, "created with success %d out of %d physical devices", successCount, devices.size());
	}

	PhysicalDeviceManager::~PhysicalDeviceManager(){

	}

	std::list<std::shared_ptr<PhysicalDevice>> PhysicalDeviceManager::find(const PhysicalDeviceSearchFilter &filter) const{
		std::list<std::shared_ptr<PhysicalDevice>> devices;

		for (const auto &currentDevice : _physicalDevices){
			if (!currentDevice->supportFeatures(filter._requiredFeatures)) continue;
			if (!supportExtensions(currentDevice, filter._requiredExtensions)) continue;
			if (!supportLayers(currentDevice, filter._requiredLayers)) continue;
			if (filter._surface != VK_NULL_HANDLE){
				if (!supportPresent(currentDevice, filter._surface)) continue;
			}

			devices.push_back(currentDevice);
		}

		return devices;
	}

	bool PhysicalDeviceManager::supportExtensions(const std::shared_ptr<PhysicalDevice>& device, const std::vector<const char*>& extensions){
		for (const auto& e : extensions){
			if (!device->supportExtension(e)) return false;
		}
		return true;
	}

	bool PhysicalDeviceManager::supportLayers(const std::shared_ptr<PhysicalDevice>& device, const std::vector<const char*>& layers){
		for (const auto& l : layers){
			if (!device->supportLayer(l)) return false;
		}
		return true;
	}

	bool PhysicalDeviceManager::supportPresent(const std::shared_ptr<PhysicalDevice>& device, VkSurfaceKHR surface) const{
		auto support = device->getSwapchainSupport(surface);
		return support.formats.empty() && support.presentModes.empty();
	}

}