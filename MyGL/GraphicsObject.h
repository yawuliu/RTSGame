#pragma once

#include <string>
#include "MyGL/IGraphicsObject.h"
#include "IData.h"

namespace MyGL {
    class IModel;

    class IScene;

    class IShader;

    class StdMaterial;

    class ITexture2d;

    class GraphicsObject : public IGraphicsObject {
    public:
        GraphicsObject(MyGL::IScene *scene);

        GraphicsObject(MyGL::IScene *scene, const std::string &src);

        ~GraphicsObject();

        MyGL::StdMaterial *material();

        void setModel(MyGL::IModel *);

        void setMaterial(MyGL::StdMaterial *);

        void setPosition(float x, float y, float z);

        void setRotateZ(float r);

        void setVisible(bool v);

        void setSize(float x, float y, float z);

        void setAlvaysVisible(bool);

        MyGL::IModel *model();


        GameObjectClass::View *getObject();

        void setPositionF(float x, float y, float z);

        void setSize(float x, float y, float z, const double *base);

        void setRotate(float r);

        void setRotateXY(float r);

        float rotateAngle() const;

        float x() const;

        float y() const;

        float z() const;

    protected:
        MyGL::IShader *extractTextures(GameObject *obj);

        MyGL::IShader *extractTextures(const GameObjectClass::View &,
                                       GameObject *obj,
                                       MyGL::StdMaterial *material,
                                       MyGL::IModel *model);

        MyGL::ITexture2d *textureFromData(const std::string &view,
                                          const char *postFix,
                                          bool mode, GameObject *obj);

        void initFromSrc(MyGL::GraphicsObject &,
                         const GameObjectClass::View &,
                         GameObject *gameObj);

        void initFromSrc(GameObject *obj);

        void setModelEvent(GameObject *obj);

        MyGL::IShader *getShadowShader(MyGL::GraphicsObject &obj,
                                       const GameObjectClass::View &);
    };
}


