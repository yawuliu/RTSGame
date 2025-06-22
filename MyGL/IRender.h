#pragma once

#include <string>
#include "MyGL/Data.h"
#include "MyGL/Color.h"
#include <MyGL/DisableCopy.h>
#include "MyGL/IRenderAlgo.h"
#include "MyGL/ICamera.h"


namespace MyGL {
    class CGL;

    class IShader;

    class IRenderAlgo;

    class IRenderState;

    class IModel;

    class IRender : public DisableCopy {
    public:
        const static int clearDepthBit = 0;
    public:
        virtual ~IRender() = default;

        virtual void setViewport(int x, int y, int w, int h) = 0;

        virtual void getProjectionMatrix(Float[]) = 0;

        virtual void getModeViewlMatrix(Float[]) = 0;

        virtual bool wasInit() = 0;

        virtual void clear(int) = 0;

        virtual void draw() = 0;

        virtual int dipCount() = 0;

        virtual int batchCount() = 0;

        virtual void resetCounters() = 0;

        virtual std::string getError() = 0;

        virtual CGL& gl() = 0;

        virtual void end() = 0;

        virtual void drawModel(IModel&) = 0;

        virtual void useShader(IShader&) = 0;

        virtual void begin() = 0;

        virtual IRenderState& renderState() = 0;

        virtual ICamera& camera() = 0;

        virtual void setCamera(ICamera&) = 0;

        virtual bool isActive() = 0;

        virtual void setZRange(float, int) = 0;

        virtual void clearColor(Color) = 0;

        virtual IRenderAlgo& createRenderAlgo() = 0;
    };
}

