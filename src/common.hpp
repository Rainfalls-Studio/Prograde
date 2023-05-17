#ifndef __PROGRADE_COMMON_HPP__
#define __PROGRADE_COMMON_HPP__

#include <Raindrop/Raindrop.hpp>
#include <vulkan/vulkan.h>
#include <SDL2/SDL.h>
#include "exception.hpp"

#define PROGRADE_VERSION_MAJOR CMAKE_PROJECT_VERSION_MAJOR
#define PROGRADE_VERSION_MINOR CMAKE_PROJECT_VERSION_MINOR
#define PROGRADE_VERSION_PATCH CMAKE_PROJECT_VERSION_PATCH

namespace Prograde{
	namespace Maths = Raindrop::Core::Maths;
	namespace Gfx = Raindrop::Graphics;
	
	using namespace Raindrop;

	class Instance;
	class PhysicalDevice;
	class Device;
}

#endif