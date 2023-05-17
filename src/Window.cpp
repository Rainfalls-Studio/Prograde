#include "Window.hpp"

namespace Prograde{
	Window::Window(){
		_window = SDL_CreateWindow("Prograde window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1080, 720, SDL_WINDOW_VULKAN);

		if (!_window){
			std::stringstream err;
			err << "Failed to create SDL2 window : " << SDL_GetError();
			throw std::runtime_error(err.str());
		}
	}

	Window::~Window(){
		if (_window) SDL_DestroyWindow(_window);
	}

	void Window::setTitle(const char* title){
		SDL_SetWindowTitle(_window, title);
	}

	void Window::setSize(Raindrop::Core::Maths::vec2<Raindrop::uint32> size){
		SDL_SetWindowSize(_window, static_cast<int>(size.x), static_cast<int>(size.y));
	}

	void Window::setPosition(Raindrop::Core::Maths::vec2<Raindrop::uint32> position){
		SDL_SetWindowPosition(_window, static_cast<int>(position.x), static_cast<int>(position.y));
	}

	const char* Window::getTitle() const{
		return SDL_GetWindowTitle(_window);
	}

	Maths::vec2<Raindrop::uint32> Window::getSize() const{
		int w, h;
		SDL_GetWindowSize(_window, &w, &h);
		return Maths::vec2<uint32>(w, h);
	}

	Maths::vec2<uint32> Window::getPosition() const{
		int x, y;
		SDL_GetWindowPosition(_window, &x, &y);
		return Maths::vec2<uint32>(x, y);
	}

	const char* Window::getAPI() const{
		return "Simple Direct Media Layer 2 (SDL2)";
	}

	bool Window::loaded() const{
		return _window != nullptr;
	}

	void Window::enableVSync(bool enable){

	}

	bool Window::isVSyncEnabled() const{
		return false;
	}
}