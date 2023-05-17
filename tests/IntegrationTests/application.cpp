#include "integrationTest.hpp"

Raindrop::Application AppTest::application{"Prograde Test", RAINDROP_CreateVersion(0, 1, 0)};
std::shared_ptr<Raindrop::Graphics::GraphicsPlugin> AppTest::plugin;
std::unique_ptr<TestLogModule> AppTest::logModule;

TEST_F(AppTest, initialization){
	EXPECT_TRUE(application.isModuleLoaded(modulePath));
	EXPECT_NE(plugin.get(), nullptr);
}