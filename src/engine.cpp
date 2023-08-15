#include "engine.h"
//#include "DebugUI.h"


namespace m3d
{

    Engine* g_engine = NULL;

    Engine::~Engine()
    {

    }

    static void __window_error_callback(int errorCode, const char* description)
    {

    }

    void Engine::__onLog(void* user_data, const loguru::Message& message)
    {
        printf("[%s] %s %d %s", message.preamble, message.filename, message.line, message.message);
    }

    void Engine::__internal_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {

    }

    Engine::Engine()
    {
        mWindow = NULL;
        mWindowWidth = 0;
        mWindowHeight = 0;
        mFramebufferHeight = 0;
        mFramebufferWidth = 0;
        mTargetFps = 0;
        mFullScreen = 0;
        mElapsedTimeDelta = 0.0F;
        mElaspsedFixedTimeDelta = 0.0F;
        mPreviousTime = 0.0F;
        mAccumulator = 0.0F;
        mUpdatesPerSecond = 0;
        mFixedDeltaTime = 0.0F;
        //ZERO_MEMORY(__app_windows, sizeof(__app_windows));
        mAssetManager = nullptr;
    }


    bool Engine::init(const EngineConfig& config)
    {
        // Init Vfs 
        mAssetManager = new AssetManager();
        mAssetManager->Initialize();

        char* data = mAssetManager->ReadFile("SimpleShader.vert.spv");

        loguru::add_file("core.log", loguru::Append, loguru::Verbosity_MAX);

        loguru::add_callback("engine_logger", __onLog, NULL, loguru::Verbosity_MAX);

        LOG_F(INFO, "App init --- Start of app");

        glfwSetErrorCallback([](int error, const char* desc)
            {
                __window_error_callback(error, desc);
            });

        /* Initialize the library */
        if (!glfwInit())
        {
            LOG_F(ERROR, "Failed to initialize glfw app quiting");
            return false;
        }

        // say no to openGLs
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        int target_width = config.window_width;
        int target_height = config.window_height;
        
        //monitor = nullptr;
        if (config.fullscreen)
        {
            monitor = glfwGetPrimaryMonitor();

            target_width = glfwGetVideoMode(glfwGetPrimaryMonitor())->width;
            target_height = glfwGetVideoMode(glfwGetPrimaryMonitor())->height;
        }
        
        /* Create a windowed mode window and its OpenGL context */
        GLFWwindow* window = glfwCreateWindow(target_width, target_height, config.name, nullptr, nullptr);

        mWindow = window;
        if (!window)
        {
            glfwTerminate();
            LOG_F(ERROR, "glfwCreateWindow failed app quiting");
            return false;
        }

        m_renderer = new M3DRenderer();
        if (nullptr == m_renderer)
        {
            return false;
        }
        if (!m_renderer->Initialize(RenderDeviceType::Null, mWindow, target_width, target_height, config.fullscreen))
        {
            return false;
        }

        g_engine = this;
        //DebugUI::init(window);
        return true;
    }
		
        
    void Engine::update(float elapsedtime)
    {

    }

		// start the game loop
    bool Engine::run()
    {
        LOG_F(INFO, "Engine run main loop");

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(mWindow))
        {
            double now = glfwGetTime();
            float delta = (now - mPreviousTime);
            mPreviousTime = now;


            // --> Update called every frame is fps dependent 
            // elapsed time is passed for user to write frame independent code
            update(delta);  
            

            if(delta >= 0.25f) 
                delta = 0.25f;

            mAccumulator += delta;

            while (mAccumulator <= mFixedDeltaTime)
            {
                // fixed update called fixed times in as frame
                fixedUpdate(mFixedDeltaTime);

                mAccumulator -= mFixedDeltaTime;
            }

            float alpha = mAccumulator / mFixedDeltaTime;

            // called every frame with alpha value for user code to do any sort of interpolation
            render(alpha) ;
     
            
            
            /* Poll for and process events */
            glfwPollEvents();
        }
        return true;
    }
		
        
    void Engine::render(float alpha)
    {
        glfwGetFramebufferSize(mWindow, &mWindowWidth, &mWindowHeight);
        
        //DebugUI::render_frame();
        //DebugUI::end_frame();
            /* Swap front and back buffers */
        glfwSwapBuffers(mWindow);
    }
		
        
    void Engine::fixedUpdate(float fixedtimedelta)
    {

    }
	
    void Engine::shutdown()
    {
        //DebugUI::shutdown();
        SAFE_DELETE(m_renderer);
        glfwDestroyWindow(mWindow);
        glfwTerminate();
    }

}