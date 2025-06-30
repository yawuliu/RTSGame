#pragma once

#include <string>
#include "AbstractPass.h"
#include "IScene.h"
#include "IModel.h"
#include "Filter.h"
#include "IUniformSampler.h"

namespace MyGL {
    class BloomPass : public AbstractPass {
    public:
        class Data {
        public:
            Data(IScene &s, IModel *quad);

            virtual ~Data() = default;

        protected:
            Filter gausV;
            Filter gausH;
            Filter grab;
            IUniformSampler *textureIn;
            int w;
            int h;
        };

    public:
        BloomPass(IScene &s, const gadapter &adapter, ITextureRectangle *in);

        virtual ~BloomPass();

        virtual void exec() override;

        virtual IRenderPass::Pass::Type type() override;

        bool validate();

        int downSamplesCount();

        void setDownSamplesCount(int c);

        void setShader(IShader *s);

        void buildQuad(int w, int h);

        void setPoint(float *p, float x, float y);

        void resizeFrame();

        void incompleteEvent(const std::string &msg);

        void initShaders(const gadapter &adapter);

        void downSample(FBO *frameBuffer, ITexture *input, ITextureRectangle *output, IModel *quad);

        void postProcess(FBO *frameBuffer);

        ITextureRectangle *output();

    protected:
        ITextureRectangle *input;
        ITextureRectangle *scale[2];
        ITextureRectangle *frame;
        ITextureRectangle *subFrame;
        FBO *frameBuffer[3];
        IModel *quad[3];
        BloomPass::Data *data;
        int m_downSamplesCount;
        bool m_isValid;
    };

}