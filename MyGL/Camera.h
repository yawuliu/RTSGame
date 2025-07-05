#pragma once

#include "Data.h"
#include "CGL.h"
#include "ICamera.h"

namespace MyGL {
    class Camera : public ICamera {
    public:
        Camera();

        ~Camera() override = default;

        Float distance() override;

        bool isPrespective() override;

        CGL::GLdouble *modelProjectiveMatrix();

        void move(Float x, Float y) override;

        void normalization(CGL::GLdouble &X, CGL::GLdouble &Y, CGL::GLdouble &Z, CGL::GLdouble &D);

        Camera &operator=(const Camera &c);

        CGL::GLdouble po(CGL::GLdouble x,
                         CGL::GLdouble y,
                         CGL::GLdouble z,
                         CGL::GLdouble X,
                         CGL::GLdouble Y,
                         CGL::GLdouble Z,
                         CGL::GLdouble D);

        Float rotXY() override;

        Float rotXZ() override;

        void setAngles(Float rotXY, Float rotXZ, Float ani) override;

        void setDistance(Float d, Float ani) override;

        void setPos(Float x1, Float y1, Float z1, Float ani) override;

        void setPrespective(bool perspective) override;

        void setZoom(Float zoom) override;

        void updateCull();

        void updateGL();

        Float x() override;

        Float y() override;

        Float z() override;

        Float zoom() override;

    protected:
        Float px;
        Float py;
        Float pz;
        Float vxy;
        Float vxz;
        Float zm;
        Float dist;
        bool usePrespective;
        //00000041     // padding byte
        //	00000042     // padding byte
        //	00000043     // padding byte
        //	00000044     // padding byte
        //	00000045     // padding byte
        //	00000046     // padding byte
        //	00000047     // padding byte
        CGL::GLdouble model_proj[16];
        CGL::GLdouble cullM[6][4];
    };
}

