#pragma once

#include <string>
#include "IGraphicsObject.h"
#include "IMaterial.h"
#include "ModelInfo.h"
#include "IData.h"
#include "ObjectMatrix.h"
#include "Data.h"

namespace MyGL {
    class IModel;

    class IScene;

    class IShader;

    class StdMaterial;

    class ITexture2d;

    class GraphicsObject : public IGraphicsObject {
    public:
        GraphicsObject(IScene &s);

        GraphicsObject(IScene *s);

        virtual ~GraphicsObject();

        void init(IScene *s);

        bool isAlvaysVisible();

        IMaterial *material();

        IModel *model();

        const IModelInfo *modelInfo();

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
        double pos[3];
        double size[3];
        double angles[3];

    };
}


