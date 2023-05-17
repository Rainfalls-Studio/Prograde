#include "Renderer.hpp"

class WindowTest : public RendererTest{
	public:
		WindowTest() = default;
		virtual ~WindowTest() override = default;

		static void SetUpTestSuite(){
			RendererTest::SetUpTestSuite();
			window = renderer->createWindow();

			if (!window)
				GTEST_SKIP();
		}

		static std::shared_ptr<Raindrop::Graphics::Window> window;
};
