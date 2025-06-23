#pragma once

#include <map>
#include <string>
#include "IScene.h"
#include "AbstractPass.h"
#include "IRenderPass.h"
#include "RenderState.h"

namespace MyGL {
    class IModel;

    class IScene;

    class IShader;

    class ITexture;

    class IRenderState;

    class IUniformSampler;

    class Filter : public AbstractPass {
    public:
        class Data {
        public:
            typedef std::map<IUniformSampler *, ITexture *> Args;
        public:
            Data() = default;

            virtual ~Data() = default;

        public:
            RenderState renderState;
            IModel *quad;
            IShader *shader;
            Args args;
        };

    public:
        Filter(IScene &s);

        virtual ~Filter();

        IUniformSampler *addArgs(IUniformSampler *sm, ITexture *u);

        IUniformSampler *addArgs(const std::string &name, ITexture *u);

        void exec();

        IModel *quadModel();

        IRenderState *renderState();

        IUniformSampler *setInput(IUniformSampler *name, ITexture *arg);

        IUniformSampler *setInput(const std::string &name, ITexture *arg);

        void setQuadModel(IModel *m);

        void setShader(IShader *s);

        IShader *shader();

        IRenderPass::Pass::Type type();

    private:
        Data *data;
    };
}