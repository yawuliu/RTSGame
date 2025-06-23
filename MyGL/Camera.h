#pragma once

#include "Data.h"
#include "CGL.h"
#include "ICamera.h"

namespace MyGL {
    class Camera : public ICamera {
    public:
        Camera();

        virtual ~Camera();

        Float distance();

        bool isPrespective();

        CGL::GLdouble *modelProjectiveMatrix();

        void move(Float x, Float y);

        void normalization(CGL::GLdouble *const X,
                           CGL::GLdouble *const Y,
                           CGL::GLdouble *const Z,
                           CGL::GLdouble *const D);

        Camera *operator=(const Camera &c);

        CGL::GLdouble po(CGL::GLdouble x,
                         CGL::GLdouble y,
                         CGL::GLdouble z,
                         CGL::GLdouble X,
                         CGL::GLdouble Y,
                         CGL::GLdouble Z,
                         CGL::GLdouble D);

        Float rotXY();

        Float rotXZ();

        void setAngles(Float rotXY, Float rotXZ, Float ani);

        void setDistance(Float d, Float ani);

        void setPos(Float x1, Float y1, Float z1, Float ani);

        void setPrespective(bool perspective);

        void setZoom(Float zoom);

        void updateCull();

        void updateGL();

        Float x();

        Float y();

        Float z();

        Float zoom();

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
        double model_proj[16];
        double cullM[6][4];
    };
}

