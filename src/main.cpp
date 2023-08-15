
#define GLFW_INCLUDE_NONE
#include "engine.h"

void __onLog(void* user_data, const loguru::Message& message)
{
    printf("[%s] %s %d %s", message.preamble, message.filename, message.line, message.message);
}


int main(void)
{
    loguru::add_file("core.log", loguru::Truncate, loguru::Verbosity_MAX);

    loguru::add_callback("engine_logger", __onLog, NULL, loguru::Verbosity_MAX);

    LOG_F(INFO, "App init --- Start of app");

    LOG_F(INFO, "Create Window");

	m3d::EngineConfig defaultConfig = {};
	defaultConfig.fixedTimedelta = 0.06;
	defaultConfig.fullscreen = false;
	defaultConfig.name = "test";
	defaultConfig.openglVersionMajor = 4;
	defaultConfig.openglVersionMinor = 6;
	defaultConfig.targetFps = 60;
	defaultConfig.window_width = 1920;
	defaultConfig.window_height = 1080;

	m3d::g_engine = new m3d::Engine();

	bool ret = m3d::g_engine->init(defaultConfig);
	if (ret == false)
		return -1;

	m3d::g_engine->run();
	m3d::g_engine->shutdown();
	glfwTerminate();;
    return 0;
}