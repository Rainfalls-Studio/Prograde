#ifndef __PROGRADE_WINDOW_HPP__
#define __PROGRADE_WINDOW_HPP__

#include "common.hpp"

namespace Prograde{
	class Window : public Raindrop::Graphics::Window{
		public:
			Window();
			virtual ~Window() override;

			virtual void setTitle(const char* title) override;
			virtual void setSize(Maths::vec2<uint32> size) override;
			virtual void setPosition(Maths::vec2<uint32> position) override;
			virtual const char* getTitle() const override;
			virtual Maths::vec2<uint32> getSize() const override;
			virtual Maths::vec2<uint32> getPosition() const override;
			virtual const char* getAPI() const override;
			virtual bool loaded() const override;

			virtual void enableVSync(bool enable) override;
			virtual bool isVSyncEnabled() const override;
		
		private:
			SDL_Window* _window;
	};
}

#endif