#pragma once

#include <vector>
#include <MyGL/IScene.h>
#include <MyGL/IModel.h>
#include <MyGL/IIOModel.h>
#include <MyGL/IOModel.h>
#include <MyGL/IRender.h>
#include <MyGL/TextureRectangle.h>
#include <MyGL/AbstractPass.h>
#include <MyGL/FBO.h>

namespace MyGL {
    class Adapter;

    class MainPass : public AbstractPass {
    public:
        MainPass(IScene &s, const Adapter &adapter, IModel *q, bool autoMake);

        virtual ~MainPass();

        void buildQuad(int w, int h);

        ITextureRectangle *depthBuffer();

        void draw();

        void exec();

        FBO *frameBuffer();

        void makeAlgo(const Adapter &adapter);

        void makeAlgo(MainPass &mp, std::vector<IRenderPass *> &passes, const Adapter &adapter);

        ITextureRectangle *output();

        IModel *quadModel();

        void resizeFrame();

        void setPoint(float *p, float x, float y);

        IRenderPass::Pass::Type type();

    protected:
        IModel *quad;
        FBO *m_frameBuffer;
        ITextureRectangle *frame;
        ITextureRectangle *depth;
        std::vector<IRenderPass *> passes;
    };
}
