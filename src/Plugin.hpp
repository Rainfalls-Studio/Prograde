#ifndef __PROGRADE_PLUGIN_HPP__
#define __PROGRADE_PLUGIN_HPP__

#include <Raindrop/Raindrop.hpp>

namespace Prograde{
	class Plugin : public ::Raindrop::Graphics::GraphicsPlugin{
		public:
			Plugin();
			virtual ~Plugin() override;

			virtual Raindrop::Version version() const override final;
			virtual const char* name() const override final;
			virtual std::shared_ptr<Raindrop::Graphics::Renderer> createRenderer() override final;
	};
}

#endif