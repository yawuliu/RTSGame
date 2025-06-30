#pragma once

#include <string>
#include "Adapter.h"
#include "IRender.h"
#include "Model.h"
#include "FBO.h"
#include "Texture2d.h"
#include "ITexture2d.h"
#include "IShader.h"
#include "AbstractPass.h"
#include "IGraphicsObject.h"
#include "IOModel.h"
#include "Filter.h"
#include "ObjectMatrix.h"
#include "Camera.h"
#include "ILight.h"

namespace MyGL {
    class ShadowPass : public AbstractPass {
    public:
        ShadowPass(IScene &s, const gadapter &adapter);

        virtual ~ShadowPass();

        virtual void exec() override;

        virtual IRenderPass::Pass::Type type() override;

        void buildQuad(int w, int h);

        ITexture2d *createFrame(ITexture2d *in);

        int currentLightId();

        void draw();

        void initLight(int id);

        bool isDrawable(IGraphicsObject &obj);

        void setPoint(float *p, float x, float y);

        ITexture2d *shadowMap();

    protected:
        Filter *blur;
        IModel *quad;
        ITexture2d *frame;
        ITexture2d *tmpFrame;
        FBO *frameBuffer;
        Camera lview;
        ObjectMatrix lMat;
        bool nUpdate;
        //        000001C9     // padding byte
        //        000001CA     // padding byte
        //        000001CB     // padding byte
        int lightId;
    };
}