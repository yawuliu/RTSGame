#pragma once

#include <vector>
#include "IRenderPass.h"

namespace MyGL {
    class IScene;

    class IModel;

    class Adapter;

    class IFrameBuffer;

    class MainPass : public IRenderPass {
    public:
        MainPass(IScene *s, const MyGL::Adapter *adapter, IModel *quad, int);

        void makeAlgo(std::vector<IRenderPass *> &out,
                      const MyGL::Adapter *adapter) override;

        void makeAlgo(const MyGL::Adapter *adapter) override;

        IFrameBuffer *frameBuffer() override;

        const IRenderPass::Pass::Type &type() const override;

        IModel *quadModel();

    protected:
        IModel *mQuad;
    };
}
