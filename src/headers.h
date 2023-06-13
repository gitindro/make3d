
#ifndef _Headers_h_
#define _Headers_h_


#include <stdio.h>
#include <stdlib.h>


//-----------------------------------------------------------------------------
// opengl and glfw headers
//-----------------------------------------------------------------------------
#define GLFW_INCLUDE_NONE
#include <glbinding/gl/gl.h>
#include <glbinding/glbinding.h>
#include <GLFW/glfw3.h>

//-----------------------------------------------------------------------------
// Common math headers
//-----------------------------------------------------------------------------
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "loguru.hpp"
#include "platform.h"
#include "Aabb.h"

//-----------------------------------------------------------------------------
// Macros
//-----------------------------------------------------------------------------
#define SAFE_DELETE( p )       { if( p ) { delete ( p );     ( p ) = NULL; } }
#define SAFE_DELETE_ARRAY( p ) { if( p ) { delete[] ( p );   ( p ) = NULL; } }
#define SAFE_RELEASE( p )      { if( p ) { ( p )->Release(); ( p ) = NULL; } }
#define ZERO_MEMORY(Destination, Length) memset((Destination),0,(Length))



#endif