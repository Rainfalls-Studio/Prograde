#include "Renderer.hpp"
#include "builders/InstanceBuilder.hpp"
#include "Window.hpp"

namespace Prograde{
	Renderer::Renderer(){
		createInstance();
		createPhysicalDeviceManager();
	}

	Renderer::~Renderer(){

	}

	const char* Renderer::name() const{
		return "Prograde";
	}

	void Renderer::createInstance(){
		RAINDROP_log(INFO, GRAPHICS, "creating a new vulkan instance ...");
		Builders::InstanceBuilder builder;

		builder.setEngineName("Raindrop");
		builder.setApplicationName("Prograde");

		builder.setEngineVersion(0, RAINDROP_VERSION_MAJOR, RAINDROP_VERSION_MINOR, RAINDROP_VERSION_PATCH);
		builder.setApplicationVersion(0, PROGRADE_VERSION_MAJOR, PROGRADE_VERSION_MINOR, PROGRADE_VERSION_PATCH);
		builder.setVulkanAPIVersion(VK_API_VERSION_1_2);
		builder.requireGraphicsExtensions();

		_instance = builder.build();

		RAINDROP_log(INFO, GRAPHICS, "created vulkan insance with success !");
	}

	void Renderer::createPhysicalDeviceManager(){
		_physicalDeviceManager = std::make_shared<PhysicalDeviceManager>(_instance);
	}


	std::shared_ptr<Gfx::Context> Renderer::createContext(std::shared_ptr<Gfx::Window> window){

	}

	std::shared_ptr<Gfx::Window> Renderer::createWindow(){
		return std::static_pointer_cast<Gfx::Window>(std::make_shared<Window>());
	}
}