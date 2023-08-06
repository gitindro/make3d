
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
#include <glbinding/gl/gl.h>
#include <glbinding/Version.h>
#include <glbinding-aux/ContextInfo.h>
#include <glbinding-aux/types_to_string.h>
#include <GLFW/glfw3.h>

#include <globjects/globjects.h>
#include <globjects/base/File.h>
#include <globjects/logging.h>

#include <globjects/Buffer.h>
#include <globjects/Program.h>
#include <globjects/ProgramPipeline.h>
#include <globjects/Shader.h>
#include <globjects/VertexArray.h>
#include <globjects/VertexAttributeBinding.h>
#include <globjects/base/StaticStringSource.h>

#include <SOIL2/SOIL2.h>

//-----------------------------------------------------------------------------
// Common math headers
//-----------------------------------------------------------------------------
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "../external/loguru/loguru.hpp"

//#include "Aabb.h"

//-----------------------------------------------------------------------------
// Macros
//-----------------------------------------------------------------------------
#define SAFE_DELETE( p )       { if( p ) { delete ( p );     ( p ) = NULL; } }
#define SAFE_DELETE_ARRAY( p ) { if( p ) { delete[] ( p );   ( p ) = NULL; } }
#define SAFE_RELEASE( p )      { if( p ) { ( p )->Release(); ( p ) = NULL; } }
#define ZERO_MEMORY(Destination, Length) memset((Destination),0,(Length))



#endif