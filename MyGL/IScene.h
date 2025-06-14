#pragma once

#include <QString>
#include <QList>
#include <MyGL/IGraphicsObject.h>
#include <MyGL/Light.h>

namespace MyGL {
    class IModel;

    class IShader;

    class IRender;

    class ITextureLoader;

    class IShaderLoader;

    class ISceneGraph;

    class ITexture2d;

    class IScene {
    public:
        virtual IScene *dataControl() = 0;

        virtual ITexture2d *texture(const std::string &name) = 0;

        virtual IModel *model(const std::string &name) = 0;

        virtual IShader *shader(const std::string &name) = 0;

        virtual QList<Light *> lights() = 0;

        virtual IRender *render() = 0;

        virtual ITextureLoader *textureLoader() = 0;

        virtual IShaderLoader *shaderLoader() = 0;

        virtual IShader *addShader(const QString &, const QString &, const QString &) = 0;

        virtual void draw() = 0;

        virtual IShaderLoader *loader() = 0;

        virtual QList<IGraphicsObject *> objects() = 0;

        virtual void createRenderAlgo() = 0;

        virtual ISceneGraph *graph() = 0;

        virtual MyGL::ITexture2d *addTexture(std::string, MyGL::ITexture2d *) = 0;
    };
}

