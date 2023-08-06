#ifndef _M3D_Window_h_
#define _M3D_Window_h_

#include "SystemTypes.h"

namespace m3d
{
    class M3DWindow
    {
    private:
        M3DWindow(/* args */){}
        M3DWindow(const M3DWindow& window){}
    public:
        bool Initialize(UINT width, UINT height, bool fullscreen);
        ~M3DWindow();
    };
}


#endif //_M3D_Window_h_