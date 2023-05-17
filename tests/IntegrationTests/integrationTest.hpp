#ifndef __PROGRADE_INTEGRATION_TEST_HPP__
#define __PROGRADE_INTEGRATION_TEST_HPP__

#include "test.hpp"

#ifndef MODULE_PATH
	#define MODULE_PATH ""
#endif

using namespace Raindrop::Core::Debug::Log;

class TestLogModule : public Raindrop::Core::Debug::Log::LogModule{
	public:
		TestLogModule(){
			push();
		}

		virtual ~TestLogModule() = default;

		virtual void callback(const Log &msg) override{
			printf("[%s] :: %s\n", severityToStr(msg.severity), msg.message);
		}
};

static std::filesystem::path modulePath = MODULE_PATH;

class AppTest : public ::testing::Test{
	public:
		AppTest(){
		}

		virtual ~AppTest() override{
		}

		static void SetUpTestSuite(){
			Raindrop::Core::Debug::Log::initialize();
			logModule = std::make_unique<TestLogModule>();

			application.loadOrGetModule(modulePath);
			plugin = application.createPlugin<Raindrop::Graphics::GraphicsPlugin>("Prograde");	
		}

		static void TearDownTestSuite(){
			logModule.release();
			Raindrop::Core::Debug::Log::shutdownLog();
		}

		

		static Raindrop::Application application;
		static std::shared_ptr<Raindrop::Graphics::GraphicsPlugin> plugin;
		static std::unique_ptr<TestLogModule> logModule;
};


#endif