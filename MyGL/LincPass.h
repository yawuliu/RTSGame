#pragma once

#include "IScene.h"
#include "Adapter.h"
#include "ITextureRectangle.h"
#include "AbstractPass.h"

namespace MyGL {
    class IModel;

    class Filter;

    class LincPass : public AbstractPass {
    public:
        LincPass(IScene &s, const Adapter &adapter, IModel *quad, ITextureRectangle &f, ITextureRectangle &g,
                 ITextureRectangle &b, ITextureRectangle &d);

        virtual ~LincPass();

        virtual void exec() override;

        virtual IRenderPass::Pass::Type type() override;

        void setShader(IShader *shader);

        bool validate();

    protected:
        ITextureRectangle &frame;
        ITextureRectangle &glow;
        ITextureRectangle &bloom;
        ITextureRectangle &depth;
        Filter *filter;
    };

}