#include "engine.h"
//#include "DebugUI.h"


namespace m3d
{

    Engine* g_engine = NULL;

    Engine::~Engine()
    {

    }
	
    static void GLAPIENTRY MessageCallback(gl::GLenum source, gl::GLenum type, gl::GLuint id, gl::GLenum severity, gl::GLsizei length, const gl::GLchar* message, const void* userParam)
    {
        if (type == gl::GL_DEBUG_TYPE_ERROR)
        {
            LOG_F(ERROR, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
                (type == gl::GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
                type, severity, message);
        }
        else
        {
            LOG_F(INFO, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
                (type == gl::GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
                type, severity, message);
        }
        printf("smg %d ", source);
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
        windowsCount = 0;
    }


    bool Engine::init(const EngineConfig& config)
    {
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

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, config.openglVersionMajor);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, config.openglVersionMinor);

        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


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

        LOG_F(INFO, "Created application window ", config.name);

        //glfwSetKeyCallback(window, __internal_key_callback);

        /* Make the window's context current */
        glfwMakeContextCurrent(window);

        // Initialize globjects (internally initializes glbinding, and registers the current context)
        globjects::init([](const char* name) {
            return glfwGetProcAddress(name);
            });

        glfwGetFramebufferSize(window, &mFramebufferWidth, &mFramebufferHeight);

        //gladLoadGL(glfwGetProcAddress);

        //glfwSwapInterval(1);
         //During init, enable debug output
        globjects::enable(gl::GL_DEBUG_OUTPUT);
        glDebugMessageCallback(MessageCallback, 0);

        ++windowsCount;
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


        shutdown();
        return true;
    }
		
        
    void Engine::render(float alpha)
    {
        glfwGetFramebufferSize(mWindow, &mWindowWidth, &mWindowHeight);
        
        //DebugUI::begin_frame();
        gl::glViewport(0, 0, mWindowWidth, mWindowHeight);
        gl::glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
        gl::glClear(gl::GL_COLOR_BUFFER_BIT | gl::GL_DEPTH_BUFFER_BIT);

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
        glfwDestroyWindow(mWindow);
        glfwTerminate();
    }

}