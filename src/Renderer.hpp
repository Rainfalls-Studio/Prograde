#ifndef __PROGRADE_RENDERER_HPP__
#define __PROGRADE_RENDERER_HPP__

#include "common.hpp"
#include "builders/InstanceBuilder.hpp"
#include "PhysicalDeviceManager.hpp"

namespace Prograde{
	class Renderer : public ::Raindrop::Graphics::Renderer{
		public:
			Renderer();
			virtual ~Renderer() override;

			virtual const char* name() const override;
			virtual std::shared_ptr<Gfx::Context> createContext(std::shared_ptr<Gfx::Window> window) override;
			virtual std::shared_ptr<Gfx::Window> createWindow() override;
		
		private:
			std::shared_ptr<Instance> _instance;
			std::shared_ptr<PhysicalDeviceManager> _physicalDeviceManager;

			void createInstance();
			void createPhysicalDeviceManager();
	};
}

#endif