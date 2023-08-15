
#ifndef _Headers_h_
#define _Headers_h_

// any platform specific stuff here
#include "platform.h"

#include <stdio.h>
#include <stdlib.h>


//-----------------------------------------------------------------------------
// opengl and glfw headers
//-----------------------------------------------------------------------------
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <string>
//-----------------------------------------------------------------------------
// Common math headers
//-----------------------------------------------------------------------------
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "../external/loguru/loguru.hpp"

#include "AssetManager.h"

//-----------------------------------------------------------------------------
// Macros
//-----------------------------------------------------------------------------
#define SAFE_DELETE( p )       { if( p ) { delete ( p );     ( p ) = NULL; } }
#define SAFE_DELETE_ARRAY( p ) { if( p ) { delete[] ( p );   ( p ) = NULL; } }
#define ZERO_MEMORY(Destination, Length) memset((Destination),0,(Length))



#endif