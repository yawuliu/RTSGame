#pragma once

#include <string>
#include "IGraphicsObject.h"
#include "IData.h"
#include "ObjectMatrix.h"
#include "Data.h"
#include "IScene.h"

namespace MyGL {
    class IMaterial;

    class ModelInfo;

    class IModelInfo;

    class IModel;

    class IShader;

    class StdMaterial;

    class ITexture2d;

    class GraphicsObject : public IGraphicsObject {
    public:
        explicit GraphicsObject(IScene &s);

        explicit GraphicsObject(IScene *s);

        ~GraphicsObject() override;

        void init(IScene *s);

        bool isAlvaysVisible() override;

        IMaterial *material() override;

        IModel *model() override;

        const IModelInfo *modelInfo() override;

        const ObjectMatrix *objectMatrix() override;

        void setAlvaysVisible(bool isAVisible) override;

        void setMaterial(IMaterial *m) override;

        void setMatrix(ObjectMatrix &m) override;

        void setModel(IModel *model) override;

        void setPosition(Float x, Float y, Float z) override;

        void setRotateY(Float angle);

        void setRotateZ(Float angle) override;

        void setSize(Float s) override;

        void setSize(Float x, Float y, Float z) override;

        void setVisible(bool isVisible) override;

        void updateModelInfo();

        void upsetMatrix();

        bool visible() override;

        Float x() override;

        Float xSize();

        Float y() override;

        Float yRotation();

        Float ySize();

        Float z() override;

        Float zRotation() override;

        Float zSize();

    protected:
        IModel *gmodel;
        ModelInfo *actualInfo;
        IMaterial *gmaterial;
        ObjectMatrix matrix;
        IScene *scene;
        Bool isVisible;
        Bool isAVisible;
        //        00000032     // padding byte
        //        00000033     // padding byte
        //        00000034     // padding byte
        //        00000035     // padding byte
        //        00000036     // padding byte
        //        00000037     // padding byte
        Float pos[3];
        Float size[3];
        Float angles[3];

    };
}


