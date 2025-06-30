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
        GraphicsObject(IScene &s);

        GraphicsObject(IScene *s);

        virtual ~GraphicsObject();

        void init(IScene *s);

        bool isAlvaysVisible() override;

        IMaterial *material();

        virtual IModel *model() override;

        const IModelInfo *modelInfo() override;

        const ObjectMatrix *objectMatrix();

        void setAlvaysVisible(bool isAVisible);

        void setMaterial(IMaterial *m);

        void setMatrix(ObjectMatrix &m);

        void setModel(IModel *model);

        void setPosition(Float x, Float y, Float z);

        void setRotateY(Float angle);

        void setRotateZ(Float angle);

        void setSize(Float s);

        void setSize(Float x, Float y, Float z);

        void setVisible(bool isVisible);

        void updateModelInfo();

        void upsetMatrix();

        bool visible();

        Float x();

        Float xSize();

        Float y();

        Float yRotation();

        Float ySize();

        Float z();

        Float zRotation();

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


