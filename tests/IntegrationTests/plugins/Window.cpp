#include "Window.hpp"

std::shared_ptr<Raindrop::Graphics::Window> WindowTest::window = nullptr;

TEST_F(WindowTest, initialization){
	
}

TEST_F(WindowTest, setResize){
	EXPECT_NO_THROW(window->setSize({180, 180}));
}

TEST_F(WindowTest, setPosition){
	EXPECT_NO_THROW(window->setPosition({180, 180}));
}

TEST_F(WindowTest, setTitle){
	EXPECT_NO_THROW(window->setTitle("new title"));
}

TEST_F(WindowTest, getTitle){
	EXPECT_EQ(strcmp(window->getTitle(), "new title"), 0);
}