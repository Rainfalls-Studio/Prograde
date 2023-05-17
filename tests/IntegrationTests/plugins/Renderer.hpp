#include "../integrationTest.hpp"
#include <Raindrop/Graphics/GraphicsPlugin.hpp>

class RendererTest : public AppTest{
	public:
		RendererTest() = default;
		virtual ~RendererTest() override = default;

		static void SetUpTestSuite(){
			AppTest::SetUpTestSuite();
			renderer = plugin->createRenderer();

			if (!renderer)
				GTEST_SKIP();
		}

		static std::shared_ptr<Raindrop::Graphics::Renderer> renderer;
};