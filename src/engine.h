#ifndef _Engine_h_
#define _Engine_h_

#include "Modules.h"


namespace m3d
{
	typedef struct
	{
		char* name;
		int		window_width;
		int		window_height;
		bool	fullscreen;
		int 	openglVersionMinor;
		int 	openglVersionMajor;
		int 	targetFps;
		float	fixedTimedelta;
	} EngineConfig;


	typedef struct windata_tag
	{
		std::string         title;
		int                 windowWidth;
		int                 windowHeight;
		GLFWwindow* window;

	}WindowData;

	class Engine
	{
	private:
		GLFWwindow* mWindow;
		GLFWmonitor* monitor;
		int			mWindowWidth;
		int 		mWindowHeight;
		int			mFramebufferWidth;
		int			mFramebufferHeight;
		int			mTargetFps;
		int			mFullScreen;
		float		mElapsedTimeDelta;
		float		mElaspsedFixedTimeDelta;
		float		mPreviousTime;
		float		mAccumulator;
		int			mUpdatesPerSecond;
		float		mFixedDeltaTime;
		M3DRenderer* m_renderer;

		Engine(const Engine& e) {}
		static void		__internal_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void		__onLog(void* user_data, const loguru::Message& message);

		void update(float elapsedtime);
		void render(float alpha);
		void fixedUpdate(float fixedtimedelta);
		


	private:
		AssetManager* mAssetManager;

	public:
		Engine();
		~Engine();
		bool init(const EngineConfig& config);

		// start the game loop
		bool run();
		void shutdown();
	};

	extern Engine* g_engine;
}

#endif //_Engine_h_