#pragma once

#include <vector>
#include "IScene.h"
#include "IModel.h"
#include "IIOModel.h"
#include "IOModel.h"
#include "IRender.h"
#include "TextureRectangle.h"
#include "AbstractPass.h"
#include "FBO.h"

namespace MyGL {
    class gadapter;

    class MainPass : public AbstractPass {
    public:
        MainPass(IScene &s, const gadapter &adapter, IModel *q, bool autoMake);

        virtual ~MainPass();//0
        //1
        virtual void exec() override;//2

        virtual IRenderPass::Pass::Type type() override;//3
        virtual ITextureRectangle *output();//4
        virtual void makeAlgo(MainPass &mp, std::vector<IRenderPass *> &passes, const gadapter &adapter);//5

        void buildQuad(int w, int h);

        ITextureRectangle *depthBuffer();

        void draw();


        FBO *frameBuffer();

        void makeAlgo(const gadapter &adapter);


        IModel *quadModel();

        void resizeFrame();

        void setPoint(float *p, float x, float y);


    protected:
        IModel *quad;
        FBO *m_frameBuffer;
        ITextureRectangle *frame;
        ITextureRectangle *depth;
        std::vector<IRenderPass *> passes;
    };
}
