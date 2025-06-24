#pragma once

#include <string>
#include <cstdint>
#include "Data.h"
#include "Color.h"
#include "DisableCopy.h"
#include "IRenderAlgo.h"
#include "ICamera.h"
#include "IVBO.h"
#include "IGraphicsObject.h"
#include "ObjectMatrix.h"

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
        virtual ~IRender() = default; // 0
        //1
        virtual void clearColor(Color) = 0; //2
        virtual void clearColor() = 0; //3
        virtual void clear(int) = 0;//4
        virtual void clear(Color, int) = 0;//5
        virtual void initGL();//6
        virtual bool wasInit() = 0;//7
        virtual void finitGL();//8
        virtual CGL *gl() = 0; //9
        //10
        virtual void setViewport(int x, int y, int w, int h) = 0; // 11
        virtual void getViewport(int &, int &, int &, int &) = 0; // 12
        virtual void useShader(IShader *) = 0;//13
        virtual void isShaderCurrent(IShader *) = 0;//14
        virtual void bindTexture(uint32_t, ITexture *) = 0;//15
        virtual void bindTexture(IUniformSampler *, ITexture *) = 0;//16
        virtual void ubindTexture(uint32_t) = 0;//17
        virtual void ubindTexture(IUniformSampler *) = 0;//18
        virtual void bindVBO(IVBO *, IVBO::BindMode::Type) = 0;//19
        virtual void ubindVBO(IVBO *) = 0;//20
        virtual void drawVBO(IVBO::PrimitiveType::Type, int) = 0;//21
        virtual void bindModel(IModel *) = 0;//22
        virtual void ubindModel(void) = 0;//23
        virtual void drawModel(IModel *) = 0;//24
        virtual void drawModel(IModel *, ObjectMatrix const &) = 0;//25
        virtual void draw(IGraphicsObject &) = 0;//26
        virtual void bindMaterial(IMaterial *) = 0;//27
        virtual void ubindMaterial(void) = 0;//28
        virtual void setZRange(double, double) = 0;//29
        virtual void setCamera(ICamera &) = 0;//30
        virtual void bindCamera(void) = 0;//31
        virtual void camera(void) = 0;//32
        virtual void getError(void) = 0;//33
        virtual void setRenderState(IRenderState *) = 0;//34
        virtual void renderState() = 0;//35
        virtual void resetRenderState(void) = 0;//36
        virtual void begin(void) = 0;//37
        virtual void isActive(void) = 0;//38
        virtual void end(void) = 0;//39
        virtual void getModeViewlMatrix(ObjectMatrix &) = 0;//40
        virtual void getProjectionMatrix(ObjectMatrix &) = 0;//41
        virtual void getTransformMatrix(ObjectMatrix &) = 0;//42
        virtual void getModeViewlMatrix(double *) = 0;//43
        virtual void getProjectionMatrix(double *) = 0;//44
        virtual void polyCount(void) = 0;//45
        virtual void resetPolyCount(void) = 0;//46
        virtual void batchCount(void) = 0;//47
        virtual void resetBatchCount(void) = 0;//48
        virtual void dipCount(void) = 0;//49
        virtual void resetDipCount(void) = 0;//50
        virtual void resetCounters(void) = 0;//51
        virtual void setScene(IScene &) = 0;//52
    };
}

