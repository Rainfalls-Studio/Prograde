#include "Plugin.hpp"
#include "common.hpp"
#include "Renderer.hpp"

void ____(){
	__RAINDROP_log_getContext();
	__RAINDROP_log_setContext(nullptr);
	__RAINDROP_profile_getContext();
	__RAINDROP_profile_setContext(nullptr);
}

namespace Prograde{
	Plugin::Plugin() : Gfx::GraphicsPlugin(){
		if (SDL_Init(SDL_INIT_VIDEO) != 0){
			std::stringstream err;
			err << "Failed to initialize SDL : " << SDL_GetError();
			throw std::runtime_error(err.str());
		}
	}

	Plugin::~Plugin(){
		if (SDL_WasInit(SDL_INIT_VIDEO) == SDL_TRUE){
			SDL_Quit();
		}
	}

	::Raindrop::Version Plugin::version() const{
		return Raindrop::Version(PROGRADE_VERSION_MAJOR, PROGRADE_VERSION_MINOR, PROGRADE_VERSION_PATCH);
	}

	const char* Plugin::name() const{
		return "Prograde";
	}

	std::shared_ptr<Raindrop::Graphics::Renderer> Plugin::createRenderer(){
		return std::make_shared<Renderer>();
	}
}

RAINDROP_MODULE std::shared_ptr<Raindrop::Graphics::GraphicsPlugin> create_Prograde(){
	return std::static_pointer_cast<Raindrop::Graphics::GraphicsPlugin>(std::make_shared<Prograde::Plugin>());
}