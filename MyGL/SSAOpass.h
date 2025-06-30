
#pragma once

#include <string>
#include "AbstractPass.h"
#include "Filter.h"
#include "TextureRectangle.h"
#include "ITextureRectangle.h"
#include "FBO.h"
#include "MainPass.h"
#include "Adapter.h"
#include "ITexture.h"
#include "IRender.h"

namespace MyGL {
    class IScene;

    class IAdapter;

    class SSAOpass : public AbstractPass {
    public:
        class Data {
        public:
            Data(IScene &s);

            virtual ~Data() = default;

        protected:
            Filter ssao;
        };

    public:
        SSAOpass(IScene &s, const gadapter &adapter, MainPass *mp);

        virtual ~SSAOpass();

        void exec();

        bool isActive();

        ITextureRectangle *output();

        void resizeFrame();

        void setActive(bool active);

        IRenderPass::Pass::Type type();

    protected:
        ITextureRectangle *frame;
        ITextureRectangle *depthBuf;
        FBO *frameBuffer;
        ITextureRectangle *out;
        ITextureRectangle *depth;
        MainPass *mpass;
        bool active;
        //        00000041     // padding byte
        //        00000042     // padding byte
        //        00000043     // padding byte
        //        00000044     // padding byte
        //        00000045     // padding byte
        //        00000046     // padding byte
        //        00000047     // padding byte
        SSAOpass::Data *data;
    };
}