#include "Plugin.hpp"

namespace Prograde{
	::Raindrop::Version Plugin::version() const{
		return Raindrop::Version(CMAKE_PROJECT_VERSION_MAJOR, CMAKE_PROJECT_VERSION_MINOR, CMAKE_PROJECT_VERSION_PATCH);
	}

	const char* Plugin::name() const{
		return "Prograde";
	}

	std::shared_ptr<Raindrop::Graphics::Renderer> Plugin::createRenderer(){
		#warning TODO
	}
}